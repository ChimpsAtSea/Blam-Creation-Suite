#pragma once

class c_assimp_geometry_mesh_data
{
protected:
	static constexpr size_t k_num_assimp_texcoord_channels = __min(2, AI_MAX_NUMBER_OF_TEXTURECOORDS);
	static constexpr size_t k_num_assimp_color_channels = __min(1, AI_MAX_NUMBER_OF_COLOR_SETS);

	// #TODO: Automatically determine these formats based on the type information
	static constexpr e_graphics_data_format k_index_graphics_data_format = _graphics_data_format_r32_uint;
	static constexpr e_graphics_data_format k_position_graphics_data_format = _graphics_data_format_r32g32b32_float;
	static constexpr e_graphics_data_format k_normal_graphics_data_format = _graphics_data_format_r32g32b32_float;
	static constexpr e_graphics_data_format k_tangent_graphics_data_format = _graphics_data_format_r32g32b32_float;
	static constexpr e_graphics_data_format k_bitangent_graphics_data_format = _graphics_data_format_r32g32b32_float;
	static constexpr e_graphics_data_format k_texture_coordinate_set_graphics_data_format = _graphics_data_format_r32g32_float;
	static constexpr e_graphics_data_format k_color_set_graphics_data_format = _graphics_data_format_r32g32b32a32_float;

public:
	unsigned int num_faces;
	unsigned int num_indices;
	unsigned int num_vertices;
	const char* name;
	unsigned int* indices;
	float3* positions;
	float3* normals;
	float3* tangents;
	float3* bitangents;
	float2* texture_coordinate_sets[k_num_assimp_texcoord_channels];
	float4* color_sets[k_num_assimp_color_channels];
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

	virtual const char* get_name() const override;
	virtual unsigned int get_vertex_count() const override;
	virtual unsigned int get_index_count() const override;
	virtual unsigned int get_face_count() const override;
	virtual BCS_RESULT resize_vertex_count(uint32_t num_vertices) override;
	virtual BCS_RESULT resize_face_and_index_count(uint32_t new_num_faces, uint32_t new_num_indices) override;
	virtual bool feature_supported(e_geometry_mesh_feature geometry_mesh_feature, unsigned int index = 0) const override;
	virtual BCS_RESULT apply_fixup(e_geometry_mesh_fixup fixup) const override;

	virtual BCS_RESULT property_unsafe(
		e_geometry_mesh_property property,
		uint32_t set_index,
		e_graphics_data_format& format,
		void*& property_data,
		uint32_t& max_index,
		uint32_t& stride) const override;

	virtual BCS_RESULT get_property_set_count(
		e_geometry_mesh_property property,
		uint32_t& set_count) const override;

	virtual BCS_RESULT get_property_format(
		e_geometry_mesh_property property,
		e_graphics_data_format& property_format) const override;

	virtual BCS_RESULT get_property_formats(
		e_geometry_mesh_property const* properties,
		unsigned int num_properties,
		e_graphics_data_format* property_formats) const override;

	virtual BCS_RESULT get_property(
		e_geometry_mesh_property property,
		uint32_t set_index,
		uint32_t start_index,
		uint32_t end_index,
		e_graphics_data_format target_format,
		void* property_data) const override;

	virtual BCS_RESULT set_property(
		e_geometry_mesh_property property,
		uint32_t set_index,
		uint32_t start_index,
		uint32_t end_index,
		e_graphics_data_format source_format,
		void const* property_data) const override;

protected:
	BCS_RESULT init_indices(aiMesh& assimp_mesh);
	BCS_RESULT init_texcoords(aiMesh& assimp_mesh);
	BCS_RESULT init_colors(aiMesh& assimp_mesh);
	BCS_RESULT init_vertices(aiMesh& assimp_mesh);
};
