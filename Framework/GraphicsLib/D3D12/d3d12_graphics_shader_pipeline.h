#pragma once

class c_graphics_d3d12;
class c_graphics_shader_binary_d3d12;
class c_graphics_vertex_layout_d3d12;
class c_graphics_root_signature_d3d12;

class c_graphics_shader_pipeline_d3d12 :
	public c_graphics_shader_pipeline
{
public:
	c_graphics_shader_pipeline_d3d12(
		c_graphics_d3d12& graphics,
		const wchar_t* debug_name);
	c_graphics_shader_pipeline_d3d12(c_graphics_shader_pipeline_d3d12 const&) = delete;
	virtual ~c_graphics_shader_pipeline_d3d12();

	virtual BCS_RESULT dispatch(uint32_t x = 1, uint32_t y = 1, uint32_t z = 1) override;
	virtual BCS_RESULT dispatch_rays(uint32_t x = 1, uint32_t y = 1, uint32_t z = 1) override;

	c_graphics_d3d12& graphics;
	const wchar_t* debug_name;
};

class c_graphics_shader_pipeline_state_d3d12 :
	public c_graphics_shader_pipeline_d3d12
{
public:
	c_graphics_shader_pipeline_state_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_root_signature_d3d12& root_signature,
		const wchar_t* debug_name);
	c_graphics_shader_pipeline_state_d3d12(c_graphics_shader_pipeline_state_d3d12 const&) = delete;
	virtual ~c_graphics_shader_pipeline_state_d3d12();

	virtual void bind() override;
	virtual void unbind() override;

	c_graphics_root_signature_d3d12& root_signature;
	ID3D12PipelineState* pipeline_state;
};

class c_graphics_shader_pipeline_compute_d3d12 :
	public c_graphics_shader_pipeline_state_d3d12
{
public:
	c_graphics_shader_pipeline_compute_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_root_signature_d3d12& root_signature,
		c_graphics_shader_binary_d3d12& shader_binary,
		const wchar_t* debug_name);
	c_graphics_shader_pipeline_compute_d3d12(c_graphics_shader_pipeline_compute_d3d12 const&) = delete;
	virtual ~c_graphics_shader_pipeline_compute_d3d12();

	D3D12_COMPUTE_PIPELINE_STATE_DESC pipeline_state_description;
};

class c_graphics_shader_pipeline_graphics_d3d12 :
	public c_graphics_shader_pipeline_state_d3d12
{
public:
	c_graphics_shader_pipeline_graphics_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_root_signature_d3d12& root_signature,
		c_graphics_shader_binary_d3d12** shader_binaries,
		uint32_t num_shader_binaries,
		e_graphics_data_format* render_target_data_formats,
		uint32_t num_render_targets,
		e_graphics_data_format* depth_data_format,
		c_graphics_vertex_layout_d3d12& vertex_layout,
		const wchar_t* debug_name);
	c_graphics_shader_pipeline_graphics_d3d12(c_graphics_shader_pipeline_graphics_d3d12 const&) = delete;
	virtual ~c_graphics_shader_pipeline_graphics_d3d12();

	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipeline_state_description;
};

class c_graphics_shader_pipeline_raytracing_d3d12 :
	public c_graphics_shader_pipeline_d3d12
{
public:
	c_graphics_shader_pipeline_raytracing_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_root_signature_d3d12& global_root_signature,
		c_graphics_root_signature_d3d12& local_root_signature,
		c_graphics_shader_binary_d3d12& shader_binary,
		const wchar_t* raygen_shader_name,
		const wchar_t* closest_hit_shader_name,
		const wchar_t* miss_shader_name,
		const wchar_t* hit_group_name,
		const wchar_t* debug_name);
	c_graphics_shader_pipeline_raytracing_d3d12(c_graphics_shader_pipeline_raytracing_d3d12 const&) = delete;
	virtual ~c_graphics_shader_pipeline_raytracing_d3d12();

	virtual void bind() override;
	virtual void unbind() override;
	virtual BCS_RESULT dispatch_rays(uint32_t x = 1, uint32_t y = 1, uint32_t z = 1) override;

	c_graphics_root_signature_d3d12& global_root_signature;
	c_graphics_root_signature_d3d12& local_root_signature;
	ID3D12RaytracingFallbackStateObject* raytracing_fallback_state_object;
	D3D12_STATE_OBJECT_DESC state_object_description;


	void* raygen_shader_identifier;
	void* closest_hit_shader_identifier;
	void* miss_shader_identifier;
	void* hit_group_identifier;
	UINT shader_identifier_size;

	unsigned int ray_generation_shader_record_size;
	unsigned int closest_hit_group_table_record_size;
	unsigned int miss_shader_table_record_size;
	unsigned int hit_group_table_record_size;
	unsigned int callable_shader_table_record_size;

	const wchar_t* raygen_shader_name;
	const wchar_t* closest_hit_shader_name;
	const wchar_t* miss_shader_name;
	const wchar_t* hit_group_name;

	c_graphics_buffer_d3d12* ray_generation_shader_record_buffer;
	c_graphics_buffer_d3d12* closest_hit_shader_table_buffer;
	c_graphics_buffer_d3d12* miss_shader_table_buffer;
	c_graphics_buffer_d3d12* hit_group_table_buffer;
	c_graphics_buffer_d3d12* callable_shader_table_buffer;
};

BCS_RESULT graphics_d3d12_shader_pipeline_raytracing_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* global_root_signature,
	c_graphics_root_signature_d3d12* local_root_signature,
	c_graphics_shader_binary_d3d12* shader_binary,
	const wchar_t* raygen_shader_name,
	const wchar_t* closest_hit_shader_name,
	const wchar_t* miss_shader_name,
	const wchar_t* hit_group_name,
	c_graphics_shader_pipeline_raytracing_d3d12*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_pipeline_compute_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* root_signature,
	c_graphics_shader_binary_d3d12* shader_binary,
	c_graphics_shader_pipeline_compute_d3d12*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_pipeline_graphics_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* root_signature,
	c_graphics_shader_binary_d3d12** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_shader_pipeline_graphics_d3d12*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_pipeline_destroy(c_graphics_shader_pipeline_d3d12* shader_pipeline);
