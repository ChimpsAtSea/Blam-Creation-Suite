#include "graphicslib-private-pch.h"

using namespace DirectX;

c_camera::c_camera(c_graphics_d3d12& graphics) :
	r_camera(),
	stored_yaw_degrees(NAN),
	stored_pitch_degrees(NAN),
	stored_distance(NAN),
	stored_position({ NAN ,NAN ,NAN }),
	is_perspective_invalidated(true),
	field_of_view_horizontal(),
	field_of_view_vertical(),
	aspect_ratio(),
	is_dragging(false),
	yaw_degrees(41.0f),
	pitch_degrees(14.0f),
	distance(2.2f),
	previous_drag_point(),
	constant_buffer(nullptr),
	graphics(graphics)
{
	constant_buffer = new c_constant_buffer_array_d3d12(graphics, sizeof(r_camera), c_graphics_d3d12::k_frame_count, L"c_camera");
}

c_camera::~c_camera()
{
	delete constant_buffer;
}

void c_camera::update_perspective(float new_field_of_view_horizontal, float new_aspect_ratio)
{
	bool is_different = field_of_view_horizontal != new_field_of_view_horizontal || aspect_ratio != new_aspect_ratio;
	if (!is_different) // avoid updating if we don't need to
	{
		return;
	}

	field_of_view_horizontal = new_field_of_view_horizontal;
	field_of_view_vertical = atanf(tanf(new_field_of_view_horizontal / 2.0f) / new_aspect_ratio) * 2.0f;
	aspect_ratio = new_aspect_ratio;

	perspective_transposed = XMMatrixPerspectiveFovRH(field_of_view_vertical, aspect_ratio, 10000.0f, 0.01f);
	perspective = XMMatrixTranspose(perspective_transposed);

	is_perspective_invalidated = true;
}

void c_camera::update_view(DirectX::XMFLOAT3 position)
{
	using namespace DirectX;

	pitch_degrees = __clamp(pitch_degrees, -89.9f, 89.9f);
	distance = __max(0.01f, distance);

	if (
		!is_perspective_invalidated &&
		stored_pitch_degrees == pitch_degrees &&
		stored_yaw_degrees == yaw_degrees &&
		stored_distance == distance &&
		stored_position.x == position.x &&
		stored_position.y == position.y &&
		stored_position.z == position.z
		)
	{
		return; // no need to update
	}

	stored_pitch_degrees = pitch_degrees;
	stored_yaw_degrees = yaw_degrees;
	stored_distance = distance;
	stored_position = position;

	static XMVECTOR const up_direction = XMVector3Normalize({ 0, 0, 1.0f });

	float xy_length = cosf(pitch_degrees * DEG2RAD);
	float x = xy_length * cosf(yaw_degrees * DEG2RAD);
	float y = xy_length * sinf(-yaw_degrees * DEG2RAD);
	float z = sinf(pitch_degrees * DEG2RAD);

	XMVECTOR vposition = { x, y, z };
	vposition *= distance;

	//XMVECTOR position = { sinf(yaw_degrees * DEG2RAD) * distance, sinf(pitch_degrees * DEG2RAD) * distance, cosf(yaw_degrees * DEG2RAD) * distance };
	XMVECTOR focus = {};

	view_transposed = XMMatrixLookAtRH(vposition, focus, up_direction);
	view = XMMatrixTranspose(view_transposed);
	view_perspective = XMMatrixMultiply(perspective, view);

	is_perspective_invalidated = false;
}

void c_camera::render()
{
	frame_index++;

#define k_feedback_scan_offset_bits 4
#define k_feedback_scan_offset_mask ((1 << k_feedback_scan_offset_bits) - 1)

	int feedback_scane_frame_shift = frame_index * 2; // multiply the frame index by 2 so we shift by 2 pixels for the pixel quad
	feedback_scan_offset = { float(feedback_scane_frame_shift), float(feedback_scane_frame_shift >> k_feedback_scan_offset_bits) };
	feedback_scan_offset_mask = k_feedback_scan_offset_mask;
	constant_buffer->update_resource(graphics.current_frame_index, this, 0, sizeof(r_camera));
}

void c_camera::window_procedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam)
{
	ImGuiContext* context = ImGui::GetCurrentContext();
	if (context->NavId == 0)
	{
		//if (ImGui::IsMousePosValid())
		{
			ImVec2 delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Left);
			
			yaw_degrees -= delta.x * 0.05f;
			pitch_degrees += delta.y * 0.05f;

			ImGui::ResetMouseDragDelta(ImGuiMouseButton_Left);
		}
	}
	

	switch (message)
	{
	//case WM_LBUTTONDOWN:
	//{
	//	is_dragging = true;
	//	int32_t x_position = (int)(short)LOWORD(lparam);  // Macro to get the low-order word.
	//	int32_t y_position = (int)(short)HIWORD(lparam);	// Macro to get the high-order word.
	//	previous_drag_point = { x_position, y_position };
	//}
	//break;
	//case WM_LBUTTONUP:
	//	is_dragging = false;
	//	break;
	//case WM_MOUSEMOVE:
	//{
	//	if (is_dragging)
	//	{
	//		int32_t x_position = (int)(short)LOWORD(lparam);  // Macro to get the low-order word.
	//		int32_t y_position = (int)(short)HIWORD(lparam);	// Macro to get the high-order word.

	//		int32_t x_delta = x_position - previous_drag_point.x;
	//		int32_t y_delta = y_position - previous_drag_point.y;

	//		previous_drag_point = { x_position, y_position };

	//		yaw_degrees -= static_cast<float>(x_delta) * 0.05f;
	//		pitch_degrees += static_cast<float>(y_delta) * 0.05f;
	//		pitch_degrees = __clamp(pitch_degrees, -89.9f, 89.9f);
	//	}
	//}
	//break;
	case WM_MOUSEWHEEL:
	{
		int wheel_delta = GET_WHEEL_DELTA_WPARAM(wparam);
		float wheel_delta_float = static_cast<float>(wheel_delta);
		if (wheel_delta > 0)
		{
			float scale = abs(distance * 0.05f);
			float distance_delta = wheel_delta_float * 0.005f * scale;
			distance += distance_delta;
		}
		else
		{
			float scale = abs(distance * 0.05f);
			float distance_delta = wheel_delta_float * 0.005f * scale;
			distance += distance_delta;
		}

		
	}
	break;
	}
}

void c_camera::handle_input(float x_pixels, float y_pixels, float z_wheel)
{
	yaw_degrees += x_pixels * 0.5f;
	pitch_degrees += y_pixels * 0.5f;

	float scale = abs(distance * 0.05f);
	float distance_delta = z_wheel * scale;
	distance += distance_delta;
	distance = __max(0.01f, distance);

	console_write_line("%f %f %f", yaw_degrees, pitch_degrees, distance);
}
