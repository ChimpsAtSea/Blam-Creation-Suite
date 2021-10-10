#pragma once

namespace blofeld
{
	namespace infinite
	{
		class h_s_model_definition;
		class h_render_model_definition;
		class h_objectdefinition;
	}
}

class c_viewport;
class c_graphics_camera;
class c_render_context;

class c_model_preview_test
{
public:
	c_model_preview_test(
		c_render_context& parent_render_context,
		blofeld::infinite::h_s_model_definition& model_tag, 
		blofeld::infinite::h_objectdefinition* object_tag = nullptr);
	~c_model_preview_test();

	void draw_ui();
	void draw_viewport();
	bool handle_viewport_drag_and_wheel(ImVec2& drag, float& wheel);
protected:
	blofeld::infinite::h_s_model_definition& model_tag;
	blofeld::infinite::h_objectdefinition* object_tag;
	blofeld::infinite::h_render_model_definition* render_model;
	c_render_context& parent_render_context;
	c_render_context* imgui_viewport_render_context;

	c_viewport* viewport;
	c_graphics_camera* camera;
	//c_geometry_pipeline_d3d12* geometry_pipeline;
	//c_hlsl_shader_d3d12* pixel_shader;
	//struct s_geometry_instance
	//{
	//	c_geometry_d3d12* geometry;
	//	c_constant_buffer_d3d12* geometry_instance;
	//};
	//std::vector<s_geometry_instance> geometry_instances;

	t_callback_handle imgui_viewport_render_background_callback_handle;
	static void imgui_viewport_render_background_callback(c_model_preview_test& _this);

	// #TODO: Replace with Viewport system
	float scale;
	bool show_markers;
	bool show_default_variant;
	bool show_bounding_radius;
	bool is_dragging_camera;
	unsigned char reset_scale_ticks;
	long camera_drag_start_x;
	long camera_drag_start_y;
	float viewport_width_float;
	float viewport_height_float;
	unsigned long viewport_width;
	unsigned long viewport_height;
	unsigned long selected_variant_index;
};

