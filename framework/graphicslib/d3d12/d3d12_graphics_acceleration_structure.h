#pragma once

class c_graphics_d3d12;
class c_graphics_buffer_d3d12;
class c_graphics_geometry_d3d12;

class c_graphics_top_level_acceleration_structure_d3d12 :
	public c_graphics_top_level_acceleration_structure
{
public:
	c_graphics_top_level_acceleration_structure_d3d12() = delete;
	c_graphics_top_level_acceleration_structure_d3d12(const c_graphics_top_level_acceleration_structure_d3d12&) = delete;
	c_graphics_top_level_acceleration_structure_d3d12& operator=(const c_graphics_top_level_acceleration_structure_d3d12&) = delete;
	explicit c_graphics_top_level_acceleration_structure_d3d12(
		c_graphics_d3d12& graphics,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_top_level_acceleration_structure_d3d12();

	virtual BCS_RESULT acceleration_structure_prebuild();
	virtual BCS_RESULT acceleration_structure_build(
		s_graphics_acceleration_structure_instance const* instances,
		unsigned int num_instances);
	virtual BCS_RESULT get_buffer(c_graphics_buffer*& acceleration_structure_buffer) const;

	c_graphics_d3d12& graphics;

	c_graphics_buffer_d3d12* raytracing_acceleration_structure_buffer;

	D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC build_raytracing_acceleration_structure_description;
	D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO raytracing_acceleration_structure_prebuild_info;

	//unsigned int acceleration_structure_descriptor_handle_index;
	//D3D12_CPU_DESCRIPTOR_HANDLE acceleration_structure_cpu_descriptor_handle;
};

class c_graphics_bottom_level_acceleration_structure_d3d12 :
	public c_graphics_bottom_level_acceleration_structure
{
public:
	c_graphics_bottom_level_acceleration_structure_d3d12() = delete;
	c_graphics_bottom_level_acceleration_structure_d3d12(const c_graphics_bottom_level_acceleration_structure_d3d12&) = delete;
	c_graphics_bottom_level_acceleration_structure_d3d12& operator=(const c_graphics_bottom_level_acceleration_structure_d3d12&) = delete;
	explicit c_graphics_bottom_level_acceleration_structure_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_geometry_d3d12& geometry,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_bottom_level_acceleration_structure_d3d12();

	virtual BCS_RESULT acceleration_structure_prebuild();
	virtual BCS_RESULT acceleration_structure_build();

	c_graphics_d3d12& graphics;
	c_graphics_geometry_d3d12& geometry;

	c_graphics_buffer_d3d12* raytracing_acceleration_structure_buffer;
	s_graphics_vertex_layout_description const* vertex_layout_description;
	D3D12_INPUT_ELEMENT_DESC const* input_element_description;
	c_graphics_buffer_d3d12* geometry_index_buffer;
	c_graphics_buffer_d3d12* geometry_vertex_buffer;

	D3D12_RAYTRACING_GEOMETRY_DESC raytracing_geometry_description;
	D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC build_raytracing_acceleration_structure_description;
	D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO raytracing_acceleration_structure_prebuild_info;
};

BCS_RESULT graphics_d3d12_top_level_acceleration_structure_create(
	c_graphics_d3d12* graphics,
	c_graphics_top_level_acceleration_structure_d3d12*& top_level_acceleration_structure,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_top_level_acceleration_structure_destroy(c_graphics_top_level_acceleration_structure_d3d12* top_level_acceleration_structure);

BCS_RESULT graphics_d3d12_bottom_level_acceleration_structure_create(
	c_graphics_d3d12* graphics,
	c_graphics_geometry_d3d12* geometry,
	c_graphics_bottom_level_acceleration_structure_d3d12*& bottom_level_acceleration_structure,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_bottom_level_acceleration_structure_destroy(c_graphics_bottom_level_acceleration_structure_d3d12* bottom_level_acceleration_structure);
