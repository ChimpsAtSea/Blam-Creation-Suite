#include "mandrilllib-private-pch.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using namespace blofeld::infinite;

template<typename T, typename field_type, typename parent_type, unsigned long _field_index>
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
	blofeld::infinite::h_s_model_definition& model_tag,
	blofeld::infinite::h_objectdefinition* object_tag) :
	model_tag(model_tag),
	object_tag(object_tag),
	render_model(dynamic_cast<decltype(render_model)>(model_tag.render_model)),
	//viewport(),
	//camera(),
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
	//if (render_model)
	//{
	//	viewport = new c_viewport();
	//	graphics = new c_graphics_d3d12(viewport);
	//	camera = new c_camera(*graphics);
	//	pixel_shader = new c_hlsl_shader_d3d12(_bcs_resource_type_viewport_default_pixel_shader);
	//	geometry_pipeline = new c_geometry_pipeline_d3d12(*graphics, *graphics->default_pipeline_signature, pixel_shader);

	//	unsigned long mesh_count = render_model->render_geometry.meshes_block.size();
	//	for (unsigned long mesh_index = 0; mesh_index < mesh_count; mesh_index++)
	//	{
	//		c_infinite_tag_geometry_d3d12* geometry = new c_infinite_tag_geometry_d3d12(*graphics, *render_model, mesh_index);
	//		c_constant_buffer_d3d12* geometry_instance = new c_constant_buffer_d3d12(*graphics, sizeof(r_instance), L"geometry_instance");

	//		geometry_instances.push_back({ geometry, geometry_instance });
	//	}

	//	using namespace std::placeholders;
	//	graphics->on_render_scene = std::bind(&c_model_preview_test::render_d3d12, this, _1);
	//	viewport->on_size_changed = std::bind(&c_model_preview_test::on_viewport_size_changed, this, _1, _2);

	//	debug_point;
	//}
}

c_model_preview_test::~c_model_preview_test()
{
	//delete graphics;
	//delete viewport;
}

void c_model_preview_test::update_texture_resource(unsigned long width, unsigned long height)
{
	//width = __max(1ul, width);
	//height = __max(1ul, height);
	//viewport->set_size(width, height);
}

void c_model_preview_test::on_viewport_size_changed(unsigned long width, unsigned long height)
{
	//graphics->resize_render_targets();
}

void c_model_preview_test::render_d3d12(ID3D12GraphicsCommandList* command_list)
{
	//using namespace DirectX;

	//camera->update_perspective(60.0f * DEG2RAD, viewport->get_aspect_ratio());
	//if (object_tag)
	//{
	//	camera->update_view(
	//		{ 
	//			object_tag->bounding_offset.value.x, 
	//			object_tag->bounding_offset.value.y, 
	//			object_tag->bounding_offset.value.z 
	//		});
	//}
	//else
	//{
	//	camera->update_view({ 0.0f, 0.0f, 0.0f });
	//}
	//
	//camera->render();

	//{
	//	command_list->SetGraphicsRootSignature(graphics->default_pipeline_signature->root_signature);
	//	command_list->SetGraphicsRootDescriptorTable(0, camera->constant_buffer->get_gpu_descriptor_handle(graphics->current_frame_index));
	//	//command_list->SetGraphicsRootDescriptorTable(2, albedo_texture->gpu_desctiptor_handle);
	//	//command_list->SetGraphicsRootDescriptorTable(3, ambient_occlusion_texture->gpu_desctiptor_handle);

	//	blofeld::infinite::h_render_model_definition* render_model = dynamic_cast<decltype(render_model)>(model_tag.render_model);

	//	if (!model_tag.variants_block.empty())
	//	{
	//		auto& selected_variant = model_tag.variants_block[selected_variant_index];

	//		for (auto& runtime_variant_region_index : selected_variant.runtime_variant_region_indices)
	//		{
	//			char runtime_region_index = runtime_variant_region_index.runtime_region_index;

	//			if (runtime_region_index >= 0)
	//			{
	//				auto& runtime_render_model_region = render_model->regions_block[runtime_region_index];
	//				auto& permutation = runtime_render_model_region.permutations_block.front();


	//				if (permutation.mesh_index.value >= 0)
	//				{
	//					short mesh_start_index = permutation.mesh_index;
	//					short mesh_end_index = mesh_start_index + permutation.mesh_count.value;
	//					for (short mesh_index = mesh_start_index; mesh_index < mesh_end_index; mesh_index++)
	//					{
	//						auto& geometry_instance = geometry_instances[mesh_index];

	//						r_instance instance;
	//						instance.color = { 1.0f, 1.0f, 1.0f, 1.0f };
	//						instance.transform = XMMatrixTranspose(XMMatrixScaling(scale, scale, scale));

	//						geometry_instance.geometry_instance->update_resource(&instance, 0, sizeof(instance));

	//						command_list->SetGraphicsRootDescriptorTable(1, geometry_instance.geometry_instance->get_gpu_descriptor_handle());

	//						command_list->SetPipelineState(geometry_pipeline->get_pipeline_state(_pipeline_mode_depth_only, _vertex_layout_type_p));
	//						geometry_instance.geometry->draw_instanced(1);

	//						command_list->SetPipelineState(geometry_pipeline->get_pipeline_state(_pipeline_mode_opaque, _vertex_layout_type_ptcn));
	//						geometry_instance.geometry->draw_instanced(1);
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else
	//	{
	//		for (auto& runtime_render_model_region : render_model->regions_block)
	//		{
	//			auto& permutation = runtime_render_model_region.permutations_block.front();

	//			if (permutation.mesh_index.value >= 0)
	//			{
	//				short mesh_start_index = permutation.mesh_index;
	//				short mesh_end_index = mesh_start_index + permutation.mesh_count.value;
	//				for (short mesh_index = mesh_start_index; mesh_index < mesh_end_index; mesh_index++)
	//				{
	//					auto& geometry_instance = geometry_instances[mesh_index];

	//					r_instance instance;
	//					instance.color = { 1.0f, 1.0f, 1.0f, 1.0f };
	//					instance.transform = XMMatrixTranspose(XMMatrixScaling(scale, scale, scale));

	//					geometry_instance.geometry_instance->update_resource(&instance, 0, sizeof(instance));

	//					command_list->SetGraphicsRootDescriptorTable(1, geometry_instance.geometry_instance->get_gpu_descriptor_handle());

	//					command_list->SetPipelineState(geometry_pipeline->get_pipeline_state(_pipeline_mode_depth_only, _vertex_layout_type_p));
	//					geometry_instance.geometry->draw_instanced(1);

	//					command_list->SetPipelineState(geometry_pipeline->get_pipeline_state(_pipeline_mode_opaque, _vertex_layout_type_ptcn));
	//					geometry_instance.geometry->draw_instanced(1);
	//				}
	//			}
	//		}
	//	}
	//}

	//if (object_tag != nullptr && show_bounding_radius)
	//{
	//	s_debug_geometry_sphere sphere;
	//	sphere.color = { 1,0,0,1 };
	//	sphere.transform = XMMatrixTranspose(
	//		XMMatrixScaling(
	//			scale * object_tag->bounding_radius.value,
	//			scale * object_tag->bounding_radius.value,
	//			scale * object_tag->bounding_radius.value) *
	//		XMMatrixTranslation(
	//			object_tag->bounding_offset.value.x,
	//			object_tag->bounding_offset.value.y,
	//			object_tag->bounding_offset.value.z));
	//	debug_push_sphere(graphics, &sphere);

	//	graphics->render_debug_geometry(camera);
	//}
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
				unsigned long variant_count = model_tag.variants_block.size();
				for (unsigned long variant_index = 0; variant_index < variant_count; variant_index++)
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

	update_texture_resource(viewport_width, viewport_height);
	//viewport->set_size(viewport_width, viewport_height);
	//graphics->update(1.0f / 60.0f);
	//graphics->render();

	ImVec2 start_pos = ImGui::GetCursorScreenPos();
	ImVec2 content_region = { viewport_width_float, viewport_height_float };
	ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };

	//ImGui::Image(graphics->d3d11_render_target_shader_resource_views[graphics->current_frame_index], content_region);

	ImVec2 viewport_drag;
	float viewport_wheel;
	if (handle_viewport_drag_and_wheel(viewport_drag, viewport_wheel))
	{
		//camera->handle_input(viewport_drag.x, viewport_drag.y, viewport_wheel);
	}
}

bool c_model_preview_test::handle_viewport_drag_and_wheel(ImVec2& mouse_drag_delta, float& mouse_wheel_delta)
{
	ImGuiContext& g = *GImGui;
	if (!ImGui::IsItemHovered())
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
