//#pragma once
//
//class c_eldorado_tag_reader;
//
//enum e_eldorado_interop_type
//{
//	_eldorado_d3d_vertex_buffer_interop,
//	_eldorado_d3d_index_buffer_interop,
//	_eldorado_d3d_texture_interop,
//	_eldorado_d3d_texture_interleaved_interop,
//	_eldorado_d3d_vertex_shader_interop,
//	_eldorado_d3d_pixel_shader_interop,
//	_eldorado_polyart_vertex_buffer_interop,
//	_eldorado_vectorart_vertex_buffer_interop,
//	_eldorado_polyart_index_buffer_interop,
//	k_num_eldorado_interop_types
//};
//
//struct s_eldorado_tag_interop_info
//{
//	const char* name;
//	blofeld::s_tag_persistent_identifier persistent_identifier;
//	uint32_t size;
//	uint32_t alignment_bits;
//};
//extern const s_eldorado_tag_interop_info eldorado_tag_interop_infos[k_num_eldorado_interop_types];
//
//class c_eldorado_interop_container :
//	public h_interop
//{
//protected:
//	c_eldorado_interop_container(e_eldorado_interop_type type, uint32_t descriptor, const void* data);
//public:
//	virtual ~c_eldorado_interop_container();
//
//	e_eldorado_interop_type type;
//	uint32_t descriptor;
//	const void* data;
//};
//
//class c_eldorado_vectorart_vertex_buffer_interop :
//	public c_eldorado_interop_container
//{
//public:
//	c_eldorado_vectorart_vertex_buffer_interop(c_eldorado_tag_reader& tag_reader, uint32_t descriptor, const void* data);
//	virtual ~c_eldorado_vectorart_vertex_buffer_interop();
//
//	void* vertex_data;
//	uint32_t vertex_data_size;
//};
//
//class c_eldorado_polyart_vertex_buffer_interop :
//	public c_eldorado_interop_container
//{
//public:
//	c_eldorado_polyart_vertex_buffer_interop(c_eldorado_tag_reader& tag_reader, uint32_t descriptor, const void* data);
//	virtual ~c_eldorado_polyart_vertex_buffer_interop();
//
//	void* vertex_data;
//	uint32_t vertex_data_size;
//	int32_t vertex_type;
//};
//
//class c_eldorado_polyart_index_buffer_interop :
//	public c_eldorado_interop_container
//{
//public:
//	c_eldorado_polyart_index_buffer_interop(c_eldorado_tag_reader& tag_reader, uint32_t descriptor, const void* data);
//	virtual ~c_eldorado_polyart_index_buffer_interop();
//
//	void* index_data;
//	uint32_t index_data_size;
//};
