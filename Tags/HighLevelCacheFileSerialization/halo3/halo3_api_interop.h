#pragma once

class c_halo3_tag_reader;

enum e_halo3_interop_type
{
	_halo3_d3d_vertex_buffer_interop,
	_halo3_d3d_index_buffer_interop,
	_halo3_d3d_texture_interop,
	_halo3_d3d_texture_interleaved_interop,
	_halo3_d3d_vertex_shader_interop,
	_halo3_d3d_pixel_shader_interop,
	_halo3_polyart_vertex_buffer_interop,
	_halo3_vectorart_vertex_buffer_interop,
	_halo3_polyart_index_buffer_interop,
	k_num_halo3_interop_types
};

struct s_halo3_tag_interop_info
{
	const char* name;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	uint32_t size;
	uint32_t alignment_bits;
};
extern const s_halo3_tag_interop_info halo3_tag_interop_infos[k_num_halo3_interop_types];

class c_halo3_interop_container/* :
	public h_interop*/
{
protected:
	c_halo3_interop_container(e_halo3_interop_type type, uint32_t descriptor, const void* data);
public:
	virtual ~c_halo3_interop_container();

	e_halo3_interop_type type;
	uint32_t descriptor;
	const void* data;
};

class c_halo3_vectorart_vertex_buffer_interop :
	public c_halo3_interop_container
{
public:
	c_halo3_vectorart_vertex_buffer_interop(c_halo3_tag_reader& tag_reader, uint32_t descriptor, const void* data);
	virtual ~c_halo3_vectorart_vertex_buffer_interop();

	void* vertex_data;
	uint32_t vertex_data_size;
};

class c_halo3_polyart_vertex_buffer_interop :
	public c_halo3_interop_container
{
public:
	c_halo3_polyart_vertex_buffer_interop(c_halo3_tag_reader& tag_reader, uint32_t descriptor, const void* data);
	virtual ~c_halo3_polyart_vertex_buffer_interop();

	void* vertex_data;
	uint32_t vertex_data_size;
	int32_t vertex_type;
};

class c_halo3_polyart_index_buffer_interop :
	public c_halo3_interop_container
{
public:
	c_halo3_polyart_index_buffer_interop(c_halo3_tag_reader& tag_reader, uint32_t descriptor, const void* data);
	virtual ~c_halo3_polyart_index_buffer_interop();

	void* index_data;
	uint32_t index_data_size;
};
