#pragma once
//
//struct s_geometry_file_header
//{
//	unsigned long magic;
//	unsigned long num_instances;
//	unsigned long index_data_size;
//	unsigned long index_data_offset;
//	unsigned long index_count;
//	unsigned long position_vertex_data_size;
//	unsigned long position_vertex_data_offset;
//	unsigned long vertex_data_size;
//	unsigned long vertex_data_offset;
//	unsigned long vertex_count;
//	XXH32_hash_t xxhash_32_hash;
//};
//
//struct s_geometry_instance_header
//{
//	unsigned long vertex_count;
//	unsigned long position_vertex_data_offset; // bytes from beginning of data
//	unsigned long vertex_data_offset; // bytes from beginning of data
//	unsigned long index_count; // #TODO: if less than 65k use 16bit indices
//	unsigned long index_data_offset; // bytes from beginning of data
//	wchar_t instance_name[64];
//};
//
//struct s_geometry_vertex_position
//{
//	float3 position;
//};
//
//struct s_geometry_vertex_extra
//{
//	float2 texcoord;
//	float4 color;
//	float3 normal;
//};
//
//class c_geometry_d3d12
//{
//protected:
//	c_geometry_d3d12(c_graphics_d3d12& graphics);
//
//public:
//	virtual ~c_geometry_d3d12();
//
//	D3D12_INDEX_BUFFER_VIEW* index_buffer_view;
//	D3D12_VERTEX_BUFFER_VIEW* vertex_buffer_views;
//	unsigned long vertex_buffer_view_count;
//	D3D_PRIMITIVE_TOPOLOGY primitive_topology;
//
//	unsigned long vertex_count;
//	unsigned long index_count;
//
//	void draw_instanced(unsigned long count);
//
//protected:
//	c_graphics_d3d12& graphics;
//};
//
//class c_mesh_geometry_d3d12 :
//	public c_geometry_d3d12
//{
//public:
//	static constexpr unsigned long k_file_version = 2;
//	static constexpr unsigned long k_file_magic = 'geo' + k_file_version;
//	static constexpr char k_file_extension[] = ".geo";
//	c_mesh_geometry_d3d12(c_graphics_d3d12& graphics, const char* obj_filepath);
//	~c_mesh_geometry_d3d12();
//
//protected:
//
//	// Geometry resources.
//	ID3D12Resource* position_vertex_buffer;
//	ID3D12Resource* vertex_buffer;
//
//	union
//	{
//		D3D12_VERTEX_BUFFER_VIEW vertex_buffer_views[2];
//		struct
//		{
//			D3D12_VERTEX_BUFFER_VIEW position_vertex_buffer_view;
//			D3D12_VERTEX_BUFFER_VIEW vertex_buffer_view;
//		};
//	};
//	c_memory_mapped_file* memory_mapped_file;
//
//	const s_geometry_file_header* geometry_file_header;
//	const s_geometry_instance_header* geometry_instance_headers;
//	const char* geometry_data;
//
//private:
//	const std::string obj_filepath;
//	const std::string geometry_filepath;
//};
//
//class c_solid_box_geometry_d3d12 :
//	public c_geometry_d3d12
//{
//public:
//	c_solid_box_geometry_d3d12(c_graphics_d3d12& graphics);
//	~c_solid_box_geometry_d3d12();
//
//	D3D12_INDEX_BUFFER_VIEW index_buffer_view;
//	D3D12_VERTEX_BUFFER_VIEW vertex_buffer_view;
//	ID3D12Resource* buffer;
//};
//
//class c_wireframe_box_geometry_d3d12 :
//	public c_geometry_d3d12
//{
//public:
//	c_wireframe_box_geometry_d3d12(c_graphics_d3d12& graphics);
//	~c_wireframe_box_geometry_d3d12();
//
//	D3D12_INDEX_BUFFER_VIEW index_buffer_view;
//	D3D12_VERTEX_BUFFER_VIEW vertex_buffer_view;
//	ID3D12Resource* buffer;
//};
//
//class c_sphere_geometry_d3d12 :
//	public c_geometry_d3d12
//{
//public:
//	c_sphere_geometry_d3d12(c_graphics_d3d12& graphics);
//	~c_sphere_geometry_d3d12();
//
//	D3D12_INDEX_BUFFER_VIEW index_buffer_view;
//	D3D12_VERTEX_BUFFER_VIEW vertex_buffer_view;
//	ID3D12Resource* buffer;
//};
//
//class c_line_geometry_d3d12 :
//	public c_geometry_d3d12
//{
//public:
//	c_line_geometry_d3d12(c_graphics_d3d12& graphics);
//	~c_line_geometry_d3d12();
//
//	D3D12_INDEX_BUFFER_VIEW index_buffer_view;
//	D3D12_VERTEX_BUFFER_VIEW vertex_buffer_view;
//	ID3D12Resource* buffer;
//};
