#pragma once

class c_halo4_tag_reader;

enum e_halo4_interop_type
{
	_halo4_d3d_vertex_buffer_interop,
	_halo4_d3d_index_buffer_interop,
	_halo4_d3d_texture_interop,
	_halo4_d3d_texture_interleaved_interop,
	_halo4_d3d_vertex_shader_interop,
	_halo4_d3d_pixel_shader_interop,
	_halo4_polyart_vertex_buffer_interop,
	_halo4_vectorart_vertex_buffer_interop,
	_halo4_polyart_index_buffer_interop,
	k_num_halo4_interop_types
};

struct s_halo4_tag_interop_info
{
	const char* name;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	unsigned long size;
	unsigned long alignment_bits;
};
extern const s_halo4_tag_interop_info halo4_tag_interop_infos[k_num_halo4_interop_types];

class c_halo4_interop_container :
	public h_interop
{
protected:
	c_halo4_interop_container(e_halo4_interop_type type, unsigned long descriptor, const void* data);
public:
	virtual ~c_halo4_interop_container();

	e_halo4_interop_type type;
	unsigned long descriptor;
	const void* data;
};

class c_halo4_vectorart_vertex_buffer_interop :
	public c_halo4_interop_container
{
public:
	c_halo4_vectorart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data);
	virtual ~c_halo4_vectorart_vertex_buffer_interop();

	void* vertex_data;
	unsigned long vertex_data_size;
};

class c_halo4_polyart_vertex_buffer_interop :
	public c_halo4_interop_container
{
public:
	c_halo4_polyart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data);
	virtual ~c_halo4_polyart_vertex_buffer_interop();

	void* vertex_data;
	unsigned long vertex_data_size;
	long vertex_type;
};

class c_halo4_polyart_index_buffer_interop :
	public c_halo4_interop_container
{
public:
	c_halo4_polyart_index_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data);
	virtual ~c_halo4_polyart_index_buffer_interop();

	void* index_data;
	unsigned long index_data_size;
};
