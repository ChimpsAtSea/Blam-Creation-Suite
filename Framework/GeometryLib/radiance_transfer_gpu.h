#pragma once

class c_graphics;
class c_graphics_shader_binary;
class c_graphics_register_layout;
class c_graphics_shader_pipeline;
class c_graphics_buffer;

class c_radiance_transfer_engine_gpu;

enum e_radiance_transfer_geometry_gpu_state
{
	_radiance_transfer_geometry_gpu_prebake,
	_radiance_transfer_geometry_gpu_baked,
	_radiance_transfer_geometry_gpu_finished,
};

struct c_radiance_transfer_geometry_gpu
{
	c_geometry_mesh* geometry_mesh;
	const c_radiance_transfer_engine_gpu* radiance_transfer_engine;
	e_radiance_transfer_geometry_gpu_state state;

	c_graphics_buffer* radiance_transfer_buffer;
	c_graphics_buffer* configuration_buffer;
	c_graphics_buffer* vertex_buffer;

	float** surface_coefficient_planes;
	float** subsurface_coefficient_planes;
	float* coefficients;
};

#include <GraphicsLib/HLSL/RadianceTransfer/radiance_transfer.hlsli>

enum e_radiance_transfer_register
{
	_radiance_transfer_register_runtime_configuration_buffer, //b0
	_radiance_transfer_register_samples_direction_buffer, //b1
	_radiance_transfer_register_samples_sh_coefficients_buffer, //b2
	_radiance_transfer_register_geometry_configuration_buffer, //b3
	_radiance_transfer_register_geometry_vertex_buffer, //b4
	_radiance_transfer_register_radiance_transfer_buffer, //u0
	k_num_radiance_transfer_registers
};

class c_radiance_transfer_engine_gpu :
	public c_radiance_transfer_engine
{
public:
	c_radiance_transfer_engine_gpu(
		unsigned int order,
		unsigned short resolution,
		bool use_shadows,
		bool calculate_subsurface);
	c_radiance_transfer_engine_gpu(c_radiance_transfer_engine_gpu const&) = delete;
	virtual ~c_radiance_transfer_engine_gpu();

	virtual BCS_RESULT add_mesh(
		c_geometry_mesh& geometry_mesh) override;
	virtual BCS_RESULT bake() override;
	virtual BCS_RESULT read(
		c_geometry_mesh& geometry_mesh,
		const float* const*& surface_coefficient_planes,
		const float* const*& subsurface_coefficient_planes,
		unsigned int& num_coefficient_planes) override;

protected:
	void init_samples();
	void deinit_samples();
	BCS_RESULT bind_graphics_buffer(
		c_graphics_register_layout& register_layout,
		e_radiance_transfer_register radiance_transfer_register,
		c_graphics_buffer& graphics_buffer);

	c_graphics* graphics;
	c_graphics_shader_binary* raytracing_test_shader_binary;
	c_graphics_register_layout* raytracing_global_register_layout;
	c_graphics_shader_pipeline* raytracing_test_shader_pipeline;
	c_graphics_buffer* runtime_configuration_buffer;
	c_graphics_buffer* samples_direction_buffer;
	c_graphics_buffer* samples_sh_coefficients_buffer;

	s_graphics_register_layout_description raytracing_global_register_layouts[k_num_radiance_transfer_registers];

	BCS_RESULT graphics_start_debug_capture_result;

	c_geometry_mesh** geometry_meshes;
	unsigned int num_geometry_meshes;
	c_radiance_transfer_geometry_gpu* geometries;
	unsigned int num_geometries;

	unsigned int order;
	unsigned int resolution;
	unsigned int num_coefficient_planes;
	bool use_shadows;
	bool calculate_subsurface;
	unsigned int num_samples;
	unsigned int num_sample_sh_coefficients;
	void (*spherical_harmonic_evaluation)(float x, float y, float z, float* coefficients);
};
