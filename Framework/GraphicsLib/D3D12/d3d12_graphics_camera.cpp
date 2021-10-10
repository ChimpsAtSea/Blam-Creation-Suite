#include "graphicslib-private-pch.h"

c_graphics_camera_d3d12::c_graphics_camera_d3d12(
	c_graphics_d3d12& graphics,
	c_viewport& viewport,
	const wchar_t* name) :
	c_graphics_camera(),
	s_camera_state_d3d12(),
	graphics(graphics),
	viewport(viewport),
	graphics_buffer(),
	camera_hash(),
	viewport_size_changed_handle()
{
	BCS_FAIL_THROW(graphics_buffer_create(
		&graphics, 
		_graphics_buffer_type_unordered_access_view, 
		sizeof(r_camera_d3d12),
		graphics_buffer));

	aspect_ratio = viewport.aspect_ratio;
	yaw_degrees = 45.0f;
	pitch_degrees = 15.0f;
	radius = 5.0f;
	set_field_of_view_degrees(60.0f);

	viewport.on_size_changed.add_callback(viewport_size_changed, this, viewport_size_changed_handle);
}

c_graphics_camera_d3d12::~c_graphics_camera_d3d12()
{
	BCS_FAIL_THROW(graphics_buffer_destroy(graphics_buffer));
}

static float3 operator*(float3& a, float b)
{
	return { a.x * b, a.y * b, a.z * b };
}

static float3 operator+(float3 a, float3 b)
{
	return { a.x + b.x, a.y + b.x, a.z + b.x };
}

static void float3_to_dxvector(float3& a, DirectX::XMVECTOR& v)
{
	v.m128_f32[0] = a.x;
	v.m128_f32[1] = a.y;
	v.m128_f32[2] = a.z;
	v.m128_f32[3] = 0.0f;
}

static void dxvector_to_float4(DirectX::XMVECTOR& v, float4& b)
{
	b.x = v.m128_f32[0];
	b.y = v.m128_f32[1];
	b.z = v.m128_f32[2];
	b.w = v.m128_f32[3];
}

static void dxmatrix_to_float4x4(DirectX::XMMATRIX& m, float4x4& b)
{
	// #TODO: hack
	dxvector_to_float4(m.r[0], reinterpret_cast<float4*>(&b)[0]);
	dxvector_to_float4(m.r[1], reinterpret_cast<float4*>(&b)[1]);
	dxvector_to_float4(m.r[2], reinterpret_cast<float4*>(&b)[2]);
	dxvector_to_float4(m.r[3], reinterpret_cast<float4*>(&b)[3]);
}

void c_graphics_camera_d3d12::update_buffers()
{
	s_camera_state_d3d12& camera_data = static_cast<s_camera_state_d3d12&>(*this);
	XXH64_hash_t current_camera_hash = XXH64(&camera_data, sizeof(s_camera_state_d3d12), 0);
	if (camera_hash == current_camera_hash)
	{
		return;
	}

	using namespace DirectX;

	far_distance = __max(10000.0f, radius * 2.0f);
	near_distance = far_distance / 1000000.0f;
	pitch_degrees = __clamp(pitch_degrees, -89.9f, 89.9f);
	yaw_degrees += 180.0f;
	while (yaw_degrees < 0.0f) yaw_degrees += 360.0f;
	yaw_degrees = fmodf(yaw_degrees, 360.0f) - 180.0f;

	float rotation_xy_length = cosf(pitch_degrees * DEG2RAD);
	float3 view_rotation = {
		rotation_xy_length * cosf(yaw_degrees * DEG2RAD),
		rotation_xy_length * sinf(-yaw_degrees * DEG2RAD),
		sinf(pitch_degrees * DEG2RAD),
	};

	float3 eye_position = view_rotation * radius + position.xyz;
	float3 focus_position = {};
	float3 up_direction = { 0, 0, 1.0f };

	XMVECTOR dx_eye_position;
	XMVECTOR dx_focus_position;
	XMVECTOR dx_up_direction;

	float3_to_dxvector(eye_position, dx_eye_position);
	float3_to_dxvector(focus_position, dx_focus_position);
	float3_to_dxvector(up_direction, dx_up_direction);

	XMMATRIX dx_perspective_transposed = XMMatrixPerspectiveFovRH(
		field_of_view_vertical,
		aspect_ratio,
		far_distance,
		near_distance);

	XMMATRIX dx_perspective = XMMatrixTranspose(dx_perspective_transposed);

	XMMATRIX dx_view_transposed = XMMatrixLookAtRH(
		dx_eye_position,
		dx_focus_position,
		dx_up_direction);

	XMMATRIX dx_view = XMMatrixTranspose(dx_view_transposed);

	XMMATRIX dx_view_perspective = XMMatrixMultiply(dx_perspective, dx_view);

	dxmatrix_to_float4x4(dx_perspective_transposed, perspective_transposed);
	dxmatrix_to_float4x4(dx_perspective, perspective);
	dxmatrix_to_float4x4(dx_view_transposed, view_transposed);
	dxmatrix_to_float4x4(dx_view, view);
	dxmatrix_to_float4x4(dx_view_perspective, view_perspective);

	r_camera_d3d12& camera_gpu_data = static_cast<r_camera_d3d12&>(*this);
	graphics_buffer->write_data(&camera_gpu_data, sizeof(r_camera_d3d12));

	current_camera_hash = XXH64(&camera_data, sizeof(s_camera_state_d3d12), 0);
	camera_hash = current_camera_hash;

	console_write_line("%f %f %f", yaw_degrees, pitch_degrees, radius);
}

void c_graphics_camera_d3d12::set_field_of_view_degrees(float field_of_view_degrees)
{
	field_of_view_degrees = __clamp(field_of_view_degrees, 0.1f, 179.9f);
	field_of_view_degrees *= DEG2RAD;
	field_of_view_horizontal = field_of_view_degrees;
	field_of_view_vertical = atanf(tanf(field_of_view_degrees / 2.0f) / aspect_ratio) * 2.0f;
}

void c_graphics_camera_d3d12::set_position(float3 position)
{
	this->position = position;
}

void c_graphics_camera_d3d12::set_yaw(float yaw)
{
	this->yaw_degrees = yaw;
}

void c_graphics_camera_d3d12::add_yaw(float yaw)
{
	this->yaw_degrees += yaw;
}

void c_graphics_camera_d3d12::set_pitch(float pitch)
{
	this->pitch_degrees = pitch;
}

void c_graphics_camera_d3d12::add_pitch(float pitch)
{
	this->pitch_degrees += pitch;
}

void c_graphics_camera_d3d12::set_radius(float radius)
{
	this->radius = radius;
}

void c_graphics_camera_d3d12::add_radius(float radius)
{
	this->radius += radius;
}

void c_graphics_camera_d3d12::get_graphics_buffer(c_graphics_buffer*& out_graphics_buffer)
{
	out_graphics_buffer = graphics_buffer;
}

void c_graphics_camera_d3d12::handle_input(float x_pixels, float y_pixels, float z_wheel)
{
	add_yaw(x_pixels * 0.5f);
	add_pitch(y_pixels * 0.5f);
	
	float scale = abs(radius * 0.05f);
	float distance_delta = z_wheel * scale;
	radius += distance_delta;
	radius = __max(0.01f, radius);
}

void __cdecl c_graphics_camera_d3d12::viewport_size_changed(c_graphics_camera_d3d12& _this, unsigned long width, unsigned long height)
{
	_this.aspect_ratio = _this.viewport.aspect_ratio;
}

BCS_RESULT graphics_d3d12_camera_create(
	c_graphics_d3d12* graphics,
	c_viewport& viewport,
	c_graphics_camera_d3d12*& camera,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		camera = new c_graphics_camera_d3d12(
			*graphics,
			viewport,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_camera_destroy(c_graphics_camera_d3d12* camera)
{
	try
	{
		delete camera;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
