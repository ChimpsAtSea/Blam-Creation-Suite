#pragma once

class c_assimp_geometry_mesh_data
{
protected:
	static constexpr size_t k_num_assimp_texcoord_channels = __min(c_geometry_mesh::k_num_texcoord_channels, AI_MAX_NUMBER_OF_TEXTURECOORDS);
	static constexpr size_t k_num_assimp_color_channels = __min(c_geometry_mesh::k_num_color_channels, AI_MAX_NUMBER_OF_COLOR_SETS);
public:
	unsigned int num_faces;
	unsigned int num_indices;
	unsigned int num_vertices;
	float3* positions;
	float3* normals;
	float3* tangents;
	float3* bitangents;
	float2* texture_coordinate_sets[k_num_assimp_texcoord_channels];
	float4* color_sets[k_num_assimp_color_channels];
	unsigned short* mesh_indices_ushort;
	unsigned int* mesh_indices_uint;
	void deinit_geometry();
};

class c_assimp_geometry_mesh :
	public c_geometry_mesh, protected c_assimp_geometry_mesh_data
{
protected:
	DEBUG_ONLY(const aiMesh* assimp_mesh);
	c_assimp_geometry_scene& assimp_geometry_scene;

public:
	c_assimp_geometry_mesh(c_assimp_geometry_scene& assimp_geometry_scene, aiMesh* assimp_mesh);
	virtual ~c_assimp_geometry_mesh();

	virtual unsigned int get_vertex_count() const override;
	virtual unsigned int get_index_count() const override;
	virtual unsigned int get_face_count() const override;
	virtual const float3* get_positions() const override;
	virtual const float3* get_normals() const override;
	virtual const float3* get_tangents() const override;
	virtual const float3* get_bitangents() const override;
	virtual const float2* get_texture_coordinate_set(unsigned int index) const override;
	virtual const float4* get_color_set(unsigned int index) const override;
	virtual void* get_mesh_indices_raw() const override;
	virtual unsigned int* get_mesh_indices_uint() const override;
	virtual e_geometry_mesh_index_format get_mesh_index_format() const override;
	virtual bool is_read_only() const override;

	virtual BCS_RESULT resize_vertex_count(unsigned int new_num_vertices) override;
	virtual BCS_RESULT resize_face_and_index_count(unsigned int new_num_faces, unsigned int new_num_indices) override;
	virtual BCS_RESULT write_indices(const unsigned int* new_indices, unsigned int num_indices, unsigned int offset) override;
	virtual BCS_RESULT write_positions(const float3* new_positions, unsigned int num_write_vertices, unsigned int offset) override;
	virtual BCS_RESULT write_normals(const float3* new_normals, unsigned int num_write_vertices, unsigned int offset) override;
	virtual BCS_RESULT write_tangents(const float3* new_tangents, unsigned int num_write_vertices, unsigned int offset) override;
	virtual BCS_RESULT write_bitangents(const float3* new_bitangents, unsigned int num_write_vertices, unsigned int offset) override;
	virtual BCS_RESULT write_texture_coordinate_set(unsigned int index, const float2* new_texture_coordinates, unsigned int num_write_vertices, unsigned int offset) override;
	virtual BCS_RESULT write_color_set(unsigned int index, const float4* new_colors, unsigned int num_write_vertices, unsigned int offset) override;

	virtual void degenerate_texcoord_hack() override;

protected:
	BCS_RESULT init_indices(aiMesh& assimp_mesh);
	BCS_RESULT init_short_indices();
	BCS_RESULT init_texcoords(aiMesh& assimp_mesh);
	BCS_RESULT init_colors(aiMesh& assimp_mesh);
	BCS_RESULT init_vertices(aiMesh& assimp_mesh);
};
