#include "mandrillui-private-pch.h"

#ifdef BCS_BUILD_ENGINE_HALO_INFINITE

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using namespace blofeld::infinite;

template<typename T, typename field_type, typename parent_type, uint32_t _field_index>
T _dynamic_cast(h_field<field_type, parent_type, _field_index> const& field)
{
	return dynamic_cast<T>(field.value);
}

template<typename T, typename V>
T _dynamic_cast(V const& value)
{
	return dynamic_cast<T>(value);
}

#define dynamic_cast _dynamic_cast

c_model_preview_test::c_model_preview_test(
	c_render_context& parent_render_context,
	blofeld::infinite::h_s_model_definition& model_tag,
	blofeld::infinite::h_objectdefinition* object_tag) :
	model_tag(model_tag),
	object_tag(object_tag),
	render_model(dynamic_cast<decltype(render_model)>(model_tag.render_model.get_tag())),
	parent_render_context(parent_render_context),
	imgui_viewport_render_context(nullptr),
	viewport(),
	camera(),
	imgui_viewport_render_background_callback_handle(),
	//graphics(),
	//pixel_shader(),
	//geometry_pipeline(),
	scale(1.0f),
	show_markers(false),
	show_default_variant(true),
	is_dragging_camera(false),
	show_bounding_radius(false),
	reset_scale_ticks(false),
	camera_drag_start_x(),
	camera_drag_start_y(),
	viewport_width_float(),
	viewport_height_float(),
	viewport_width(),
	viewport_height(),
	selected_variant_index(0)
{
	if (render_model)
	{
		viewport = new() c_viewport();

		float4 background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
		BCS_FAIL_THROW(render_context_imgui_create(
			parent_render_context,
			*viewport,
			background_color,
			imgui_viewport_render_context));

		BCS_FAIL_THROW(imgui_viewport_render_context->on_render_background.add_callback(
			imgui_viewport_render_background_callback, 
			this, 
			imgui_viewport_render_background_callback_handle));

		c_graphics* graphics;
		parent_render_context.get_graphics(graphics);

		auto camera_create_result = graphics_camera_create(graphics, *viewport, camera);
		ASSERT(BCS_SUCCEEDED(camera_create_result));

		debug_point;

		uint32_t mesh_count = render_model->render_geometry.meshes_block.size();
		for (uint32_t mesh_index = 0; mesh_index < mesh_count; mesh_index++)
		{
			c_infinite_tag_model* infinite_tag_model = new() c_infinite_tag_model(*graphics, *render_model, mesh_index);

			model_parts.push_back(infinite_tag_model);
		}

		debug_point;
	}
}

c_model_preview_test::~c_model_preview_test()
{
	delete viewport;
}

void c_model_preview_test::imgui_viewport_render_background_callback(c_model_preview_test& _this)
{
	c_graphics_buffer* camera_buffer;
	_this.camera->get_graphics_buffer(camera_buffer);
	_this.camera->update_buffers();
	camera_buffer->bind(0);

	for (c_infinite_tag_model* infinite_tag_model : _this.model_parts)
	{
		infinite_tag_model->render();
		debug_point;
	}

	debug_point;
}

void c_model_preview_test::draw_ui()
{
	if (render_model == nullptr)
	{
		ImGui::Text("No render model");
		return;
	}

	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	if (reset_scale_ticks > 0)
	{
		reset_scale_ticks--;
		scale = 1.0f;
	}

	ImGui::Columns(2, nullptr, false);
	{
		const char* slider_format = "%.2f";
		if (scale >= 10.0f) slider_format = "%.1f";
		ImGui::SliderFloat("scale", &scale, 0.01f, 100.0f, slider_format, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_AlwaysClamp);
		if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
		{
			reset_scale_ticks = 10;
		}

		draw_viewport();

		// viewport controls
		{
			ImVec2 start_pos = ImGui::GetCursorPos();
			ImGui::Checkbox("Markers", &show_markers);
			ImVec2 end_pos = ImGui::GetCursorPos();

			float button_width = ImGui::CalcTextSize("Refresh model").x + (ImGui::GetStyle().FramePadding.x + ImGui::GetStyle().ItemInnerSpacing.x) * 2.0f;
			ImVec2 button_pos = { ImGui::GetContentRegionAvailWidth() - button_width, start_pos.y };
			ImGui::SetCursorPos(button_pos);
			ImGui::Button("Refresh model");
			ImGui::SetCursorPos(end_pos);
		}
	}
	ImGui::NextColumn();
	{
		ImGui::Text("Variant:");
		ImGui::SameLine();

		if (!model_tag.variants_block.empty())
		{
			auto& selected_variant = model_tag.variants_block[selected_variant_index];
			h_string_id selected_variant_name = selected_variant.name;
			const char* selected_variant_name_cstr = selected_variant_name.c_str();

			if (ImGui::BeginCombo("##variant", selected_variant_name_cstr))
			{
				uint32_t variant_count = model_tag.variants_block.size();
				for (uint32_t variant_index = 0; variant_index < variant_count; variant_index++)
				{
					auto& variant = model_tag.variants_block[variant_index];
					h_string_id variant_name = variant.name;
					const char* variant_name_cstr = variant_name.c_str();

					if (ImGui::Selectable(variant_name_cstr))
					{
						selected_variant_index = variant_index;
					}
				}

				ImGui::EndCombo();
			}

			ImGui::Dummy({ 0.0f, 10.0f });
		}

		ImGui::Text("default:");
		ImGui::SameLine();
		ImGui::Checkbox("##default", &show_default_variant);

		ImGui::Text("Show Bounding Radius:");
		ImGui::SameLine();
		ImGui::Checkbox("##show_bounding_radius", &show_bounding_radius);

		ImGui::BeginChild("##buttons", { ImGui::GetContentRegionAvailWidth(), 120.0f });

		ImGui::Separator();

		ImGui::Dummy({ 0.0f, 10.0f });

		ImGui::Button("Drop Variant");
		ImGui::Button("Drop Permutation");
		ImGui::Button("Update");

		ImGui::EndChild();
	}
	ImGui::Columns(1);

	debug_point;
}

void c_model_preview_test::draw_viewport()
{
	viewport_width_float = ImGui::GetContentRegionAvailWidth();
	if (ImGui::GetCurrentWindow()->ScrollbarSizes.x == 0) // account for the scrollbar being added to prevent flicker
	{
		viewport_width_float -= ImGui::GetStyle().ScrollbarSize;
	}
	viewport_height_float = viewport_width_float * (9.0f / 16.0f);

	viewport_width = static_cast<unsigned long>(__max(1.0f, viewport_width_float));
	viewport_height = static_cast<unsigned long>(__max(1.0f, viewport_height_float));

	viewport_width_float = static_cast<float>(viewport_width);
	viewport_height_float = static_cast<float>(viewport_height);

	viewport->set_size(viewport_width, viewport_height);
	imgui_viewport_render_context->render();

	ImVec2 viewport_drag;
	float viewport_wheel;
	if (handle_viewport_drag_and_wheel(viewport_drag, viewport_wheel))
	{
		camera->handle_input(viewport_drag.x, viewport_drag.y, viewport_wheel);
	}
}

bool c_model_preview_test::handle_viewport_drag_and_wheel(ImVec2& mouse_drag_delta, float& mouse_wheel_delta)
{
	ImGuiContext& g = *GImGui;
	if (!(ImGui::IsItemHovered() || is_dragging_camera))
	{
		// fixup for image control
		g.HoveredIdUsingMouseWheel = false;
		g.ActiveIdUsingMouseWheel = false;
	}
	else
	{
		// fixup for image control
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		ImGuiID image_control_id = window->GetID("#IMAGE");
		g.HoveredIdUsingMouseWheel = true;
		g.ActiveIdUsingMouseWheel = true;
		g.LastItemData.ID = image_control_id;
		g.HoveredId = image_control_id;

		ImGuiIO& io = ImGui::GetIO();
		mouse_wheel_delta = -io.MouseWheel;

		if (ImGui::IsMouseDragging(ImGuiMouseButton_Left))
		{

			POINT cursor_position;
			::GetCursorPos(&cursor_position);
			if (!is_dragging_camera)
			{
				camera_drag_start_x = cursor_position.x;
				camera_drag_start_y = cursor_position.y;
				is_dragging_camera = true;
			}

			ImGui::SetMouseCursor(ImGuiMouseCursor_None);

			mouse_drag_delta = ImGui::GetMouseDragDelta();

			// async and laggy, so the cursor is hidden!
			::SetCursorPos(cursor_position.x - static_cast<long>(mouse_drag_delta.x), cursor_position.y - static_cast<long>(mouse_drag_delta.y));

			io.MousePos.x -= mouse_drag_delta.x;
			io.MousePos.y -= mouse_drag_delta.y;

			ImGui::ResetMouseDragDelta();
			return true;
		}
		else if (is_dragging_camera)
		{
			mouse_drag_delta = {};
			ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
			// restore the mouse position
			::SetCursorPos(camera_drag_start_x, camera_drag_start_y);
			is_dragging_camera = false;
		}

		return mouse_wheel_delta != 0.0f;
	}

	return false;
}

#endif // BCS_BUILD_ENGINE_HALO_INFINITE
