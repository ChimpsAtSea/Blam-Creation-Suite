#pragma once

class c_graphics_d3d12;
class c_graphics_vertex_layout_d3d12;
class c_graphics_buffer_d3d12;

class c_graphics_geometry_d3d12 :
	public c_graphics_geometry
{
public:
	c_graphics_geometry_d3d12() = delete;
	c_graphics_geometry_d3d12(const c_graphics_geometry_d3d12&) = delete;
	c_graphics_geometry_d3d12& operator=(const c_graphics_geometry_d3d12&) = delete;
	explicit c_graphics_geometry_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_buffer_d3d12* index_buffer,
		c_graphics_buffer_d3d12** vertex_buffers,
		uint32_t num_vertex_buffers,
		uint32_t num_indices,
		uint32_t num_vertices,
		c_graphics_vertex_layout_d3d12& vertex_layout,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_geometry_d3d12();

	virtual void render_geometry(uint32_t instance_count = 1) override;

	c_graphics_d3d12& graphics;
	c_graphics_vertex_layout_d3d12& vertex_layout;

	D3D12_VERTEX_BUFFER_VIEW* vertex_buffer_views;
	D3D12_INDEX_BUFFER_VIEW index_buffer_view;

	uint32_t num_indices;
	uint32_t num_vertices;
	uint32_t num_vertex_buffers;
	c_graphics_buffer_d3d12* index_buffer;
	c_graphics_buffer_d3d12** vertex_buffers;
};

BCS_RESULT graphics_d3d12_geometry_create(
	c_graphics_d3d12* graphics,
	c_graphics_buffer_d3d12* index_buffer,
	c_graphics_buffer_d3d12** vertex_buffers,
	uint32_t num_vertex_buffers,
	uint32_t num_indices,
	uint32_t num_vertices,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_geometry_d3d12*& geometry,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_geometry_destroy(c_graphics_geometry_d3d12* geometry);
