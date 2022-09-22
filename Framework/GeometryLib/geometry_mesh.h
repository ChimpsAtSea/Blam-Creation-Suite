#pragma once

enum e_geometry_mesh_index_format
{
	_geometry_mesh_index_format_ushort,
	_geometry_mesh_index_format_uint,
};

class c_geometry_mesh
{
public:
	static constexpr size_t k_num_texcoord_channels = 2;
	static constexpr size_t k_num_color_channels = 1;

	virtual ~c_geometry_mesh();

	virtual unsigned int get_vertex_count() const = 0;
	virtual unsigned int get_index_count() const = 0;
	virtual unsigned int get_face_count() const = 0;
	virtual const float3* get_positions() const = 0;
	virtual const float3* get_normals() const = 0;
	virtual const float3* get_tangents() const = 0;
	virtual const float3* get_bitangents() const = 0;
	virtual const float2* get_texture_coordinate_set(unsigned int index) const = 0;
	virtual const float4* get_color_set(unsigned int index) const = 0;
	virtual void* get_mesh_indices_raw() const = 0;
	virtual unsigned int* get_mesh_indices_uint() const = 0;
	virtual e_geometry_mesh_index_format get_mesh_index_format() const = 0;
	virtual bool is_read_only() const = 0;

	virtual BCS_RESULT resize_vertex_count(unsigned int num_vertices) = 0;
	virtual BCS_RESULT resize_face_and_index_count(unsigned int new_num_faces, unsigned int new_num_indices) = 0;
	virtual BCS_RESULT write_indices(const unsigned int* indices, unsigned int num_indices, unsigned int offset) = 0;
	virtual BCS_RESULT write_positions(const float3* positions, unsigned int num_vertices, unsigned int offset) = 0;
	virtual BCS_RESULT write_normals(const float3* normals, unsigned int num_vertices, unsigned int offset) = 0;
	virtual BCS_RESULT write_tangents(const float3* tangents, unsigned int num_vertices, unsigned int offset) = 0;
	virtual BCS_RESULT write_bitangents(const float3* bitangents, unsigned int num_vertices, unsigned int offset) = 0;
	virtual BCS_RESULT write_texture_coordinate_set(unsigned int index, const float2* texture_coordinates, unsigned int num_vertices, unsigned int offset) = 0;
	virtual BCS_RESULT write_color_set(unsigned int index, const float4* colors, unsigned int num_vertices, unsigned int offset) = 0;
	virtual void degenerate_texcoord_hack() = 0;
};
