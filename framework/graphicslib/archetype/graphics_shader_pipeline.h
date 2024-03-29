#pragma once

class c_graphics;
class c_graphics_shader_binary;
class c_graphics_vertex_layout;
class c_graphics_register_layout;

class c_graphics_shader_pipeline
{
protected:
	c_graphics_shader_pipeline();
public:
	virtual ~c_graphics_shader_pipeline();

	virtual void bind() = 0;
	virtual void unbind() = 0;
	virtual BCS_RESULT dispatch(uint32_t x = 1, uint32_t y = 1, uint32_t z = 1) = 0;
#ifdef BCS_DX12_RAY_TRACING_FALLBACK
	virtual BCS_RESULT dispatch_rays(uint32_t x = 1, uint32_t y = 1, uint32_t z = 1) = 0;
#endif
};

BCS_SHARED BCS_RESULT graphics_shader_pipeline_raytracing_create(
	c_graphics* graphics,
	c_graphics_register_layout* global_register_layout,
	c_graphics_register_layout* local_register_layout,
	c_graphics_shader_binary* shader_binary,
	const wchar_t* raygen_shader_name,
	const wchar_t* closest_hit_shader_name,
	const wchar_t* miss_shader_name,
	const wchar_t* hit_group_name,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_shader_pipeline_compute_create(
	c_graphics* graphics,
	c_graphics_register_layout* register_layout,
	c_graphics_shader_binary* shader_binary,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_shader_pipeline_graphics_create(
	c_graphics* graphics,
	c_graphics_register_layout* register_layout,
	c_graphics_shader_binary** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout* vertex_layout,
	c_graphics_shader_pipeline*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_shader_pipeline_destroy(c_graphics_shader_pipeline* shader_pipeline);
