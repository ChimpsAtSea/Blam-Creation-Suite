#include "mandrilllib-private-pch.h"

#define D3D_VERTEX_BUFFER_INTEROP_ID { 0x12721193, 0x798F4648, 0xB08E254D, 0xFB5907DF }
static constexpr s_halo4_tag_interop_info d3d_vertex_buffer_interop =
{
	"s_tag_d3d_vertex_buffer",
	D3D_VERTEX_BUFFER_INTEROP_ID,
	0x2C,
	2
};

#define D3D_INDEX_BUFFER_INTEROP_ID { 0x08380D7D, 0xF14D4112, 0x82CE3471, 0x1E43A770 }
static constexpr s_halo4_tag_interop_info d3d_index_buffer_interop =
{
	"s_tag_d3d_index_buffer",
	D3D_INDEX_BUFFER_INTEROP_ID,
	0x2C,
	2
};
#define D3D_TEXTURE_INTEROP_ID { 0x64017671, 0x437A46F0, 0x9A33C422, 0x517096E3 }
static constexpr s_halo4_tag_interop_info d3d_texture_interop =
{
	"s_tag_d3d_texture",
	D3D_TEXTURE_INTEROP_ID,
	0x38,
	2
};
#define D3D_TEXTURE_INTERLEAVED_INTEROP_ID { 0x90486D0A, 0x944A4941, 0x9FE79AF0, 0x39E2E611 }
static constexpr s_halo4_tag_interop_info d3d_texture_interleaved_interop =
{
	"s_tag_d3d_texture_interleaved",
	D3D_TEXTURE_INTERLEAVED_INTEROP_ID,
	0x70,
	2
};
#define D3D_VERTEX_SHADER_INTEROP_ID { 0xA6D79D0E, 0xB84B4E35, 0x92071EB2, 0x6FB1B059 }
static constexpr s_halo4_tag_interop_info d3d_vertex_shader_interop =
{
	"s_tag_d3d_vertex_shader",
	D3D_VERTEX_SHADER_INTEROP_ID,
	0x4,
	2
};
#define D3D_PIXEL_SHADER_INTEROP_ID { 0x1578CC0C, 0xCE0043B3, 0x979C9919, 0xD43CBE05 }
static constexpr s_halo4_tag_interop_info d3d_pixel_shader_interop =
{
	"s_tag_d3d_pixel_shader",
	D3D_PIXEL_SHADER_INTEROP_ID,
	0x4,
	2
};
#define POLYART_VERTEX_BUFFER_INTEROP_ID { 0xA06E820C, 0x7AE94C17, 0xB4CFD590, 0xAAA62E0 }
static constexpr s_halo4_tag_interop_info PolyartVertexBufferInterop =
{
	"PolyartVertexBuffer",
	POLYART_VERTEX_BUFFER_INTEROP_ID,
	0x24,
	2
};
#define VECTORART_VERTEX_BUFFER_INTEROP_ID { 0xAE24DC6D, 0x9A604E07, 0xA799441A, 0x3E47B775 }
static constexpr s_halo4_tag_interop_info VectorartVertexBufferInterop =
{
	"PolyartVertexBuffer",
	VECTORART_VERTEX_BUFFER_INTEROP_ID,
	0x24,
	2
};
#define POLYART_INDEX_BUFFER_INTEROP_ID { 0xE0852B06, 0xBBAC4DF8, 0xAA48A764, 0x18DB2F80 }
static constexpr s_halo4_tag_interop_info PolyartIndexBufferInterop =
{
	"PolyartIndexBuffer",
	POLYART_INDEX_BUFFER_INTEROP_ID,
	0x24,
	2
};

const s_halo4_tag_interop_info halo4_tag_interop_infos[k_num_halo4_interop_types] =
{
	d3d_vertex_buffer_interop,
	d3d_index_buffer_interop,
	d3d_texture_interop,
	d3d_texture_interleaved_interop,
	d3d_vertex_shader_interop,
	d3d_pixel_shader_interop,
	PolyartVertexBufferInterop,
	VectorartVertexBufferInterop,
	PolyartIndexBufferInterop,
};

c_halo4_interop_container::c_halo4_interop_container(e_halo4_interop_type type, unsigned long descriptor, const void* data) :
	h_interop(),
	type(type),
	descriptor(descriptor),
	data(data)
{

}

c_halo4_interop_container::~c_halo4_interop_container()
{

}

c_halo4_vectorart_vertex_buffer_interop::c_halo4_vectorart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_vectorart_vertex_buffer_interop, descriptor, data),
	vertex_data(),
	vertex_data_size()
{
	using namespace blofeld::xbox360_gen3;
	s_vectorartVertexBufferDescriptorStruct interop_data = *static_cast<const s_vectorartVertexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_vertex_data;
	tag_reader.page_offset_to_pointer(interop_data.vertices.address, source_vertex_data);

	vertex_data_size = interop_data.vertices.size;
	vertex_data = new char[vertex_data_size];
	memcpy(vertex_data, source_vertex_data, vertex_data_size);

	debug_point;
}

c_halo4_vectorart_vertex_buffer_interop::~c_halo4_vectorart_vertex_buffer_interop()
{

}

c_halo4_polyart_vertex_buffer_interop::c_halo4_polyart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_polyart_vertex_buffer_interop, descriptor, data),
	vertex_data(),
	vertex_data_size(),
	vertex_type()
{
	using namespace blofeld::xbox360_gen3;
	s_polyartVertexBufferDescriptorStruct interop_data = *static_cast<const s_polyartVertexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_vertex_data;
	tag_reader.page_offset_to_pointer(interop_data.vertices.address, source_vertex_data);

	vertex_data_size = interop_data.vertices.size;
	vertex_data = new char[vertex_data_size];
	memcpy(vertex_data, source_vertex_data, vertex_data_size);
	vertex_type = interop_data.vertex_type;

	debug_point;
}

c_halo4_polyart_vertex_buffer_interop::~c_halo4_polyart_vertex_buffer_interop()
{
	delete vertex_data;
}

c_halo4_polyart_index_buffer_interop::c_halo4_polyart_index_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_polyart_index_buffer_interop, descriptor, data),
	index_data(),
	index_data_size()
{
	using namespace blofeld::xbox360_gen3;
	s_polyartIndexBufferDescriptorStruct interop_data = *static_cast<const s_polyartIndexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_index_data;
	tag_reader.page_offset_to_pointer(interop_data.index_data.address, source_index_data);

	index_data_size = interop_data.index_data.size;
	index_data = new char[index_data_size];
	memcpy(index_data, source_index_data, index_data_size);

	debug_point;
}

c_halo4_polyart_index_buffer_interop::~c_halo4_polyart_index_buffer_interop()
{
	delete index_data;
}
