#include "graphicslib-private-pch.h"

c_graphics_geometry_d3d12::c_graphics_geometry_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_buffer_d3d12* index_buffer,
	unsigned long num_primitives,
	c_graphics_buffer_d3d12** in_vertex_buffers,
	unsigned long num_vertex_buffers,
	c_graphics_vertex_layout_d3d12& vertex_layout,
	const wchar_t* debug_name) :
	graphics(graphics),
	vertex_layout(vertex_layout),
	index_buffer_view(),
	vertex_buffer_views(),
	num_primitives(num_primitives),
	num_vertex_buffers(num_vertex_buffers),
	index_buffer(index_buffer),
	vertex_buffers()
{
	BCS_VALIDATE_ARGUMENT_THROW(num_vertex_buffers >= vertex_layout.num_layout_descriptions);

	vertex_buffers = new c_graphics_buffer_d3d12 * [num_vertex_buffers];
	vertex_buffer_views = new D3D12_VERTEX_BUFFER_VIEW[num_vertex_buffers];
	for (unsigned long vertex_buffer_index = 0; vertex_buffer_index < num_vertex_buffers; vertex_buffer_index++)
	{
		c_graphics_buffer_d3d12* vertex_buffer = in_vertex_buffers[vertex_buffer_index];
		vertex_buffers[vertex_buffer_index] = vertex_buffer;

		auto& vertex_buffer_view = vertex_buffer_views[vertex_buffer_index];

		vertex_buffer_view.BufferLocation = vertex_buffer->gpu_resource->GetGPUVirtualAddress();
		vertex_buffer_view.StrideInBytes = vertex_buffer->element_size;
		vertex_buffer_view.SizeInBytes = vertex_buffer->data_size;
	}
	if (index_buffer)
	{
		index_buffer_view.BufferLocation = index_buffer->gpu_resource->GetGPUVirtualAddress();
		index_buffer_view.Format = DXGI_FORMAT_R32_UINT;
		index_buffer_view.SizeInBytes = index_buffer->data_size;
	}
}

c_graphics_geometry_d3d12::~c_graphics_geometry_d3d12()
{
	delete vertex_buffers;
	delete vertex_buffer_views;
}

void c_graphics_geometry_d3d12::render_geometry(unsigned long instance_count)
{
	graphics.command_list->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	graphics.command_list->IASetVertexBuffers(0, num_vertex_buffers, vertex_buffer_views);
	if (index_buffer)
	{
		graphics.command_list->IASetIndexBuffer(&index_buffer_view);
		graphics.command_list->DrawIndexedInstanced(num_primitives, instance_count, 0, 0, 0);
	}
	else
	{
		graphics.command_list->DrawInstanced(num_primitives, instance_count, 0, 0);
	}
}

BCS_RESULT graphics_d3d12_geometry_create(
	c_graphics_d3d12* graphics,
	c_graphics_buffer_d3d12* index_buffer,
	unsigned long num_primitives,
	c_graphics_buffer_d3d12** vertex_buffers,
	unsigned long num_vertex_buffers,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_geometry_d3d12*& geometry,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		geometry = new c_graphics_geometry_d3d12(
			*graphics,
			index_buffer,
			num_primitives,
			vertex_buffers,
			num_vertex_buffers,
			*vertex_layout,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_geometry_destroy(c_graphics_geometry_d3d12* geometry)
{
	try
	{
		delete geometry;
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
