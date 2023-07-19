#pragma once

enum e_geometry_mesh_index_format
{
	_geometry_mesh_index_format_ushort,
	_geometry_mesh_index_format_uint,
};

enum e_geometry_mesh_property
{
	_geometry_mesh_property_indices,
	_geometry_mesh_property_positions,
	_geometry_mesh_property_normals,
	_geometry_mesh_property_tangents,
	_geometry_mesh_property_bitangents,
	_geometry_mesh_property_texture_coordinates,
	_geometry_mesh_property_colors,
	_geometry_mesh_property_bone_weights,
	_geometry_mesh_property_bone_indices,
	_geometry_mesh_property_prt_coefficients,
};

enum e_geometry_mesh_feature
{
	_geometry_mesh_feature_property, // [e_geometry_mesh_property]
	_geometry_mesh_feature_indexed,
	_geometry_mesh_feature_skinned,
	_geometry_mesh_feature_resizable,
	_geometry_mesh_feature_writable,
	_geometry_mesh_feature_contigious,
};

enum e_geometry_mesh_fixup
{
	_geometry_mesh_fixup_degenerate_texcoord_hack
};

class c_geometry_mesh
{
public:
	virtual ~c_geometry_mesh();

	virtual const char* get_name() const = 0;
	virtual uint32_t get_vertex_count() const = 0;
	virtual uint32_t get_index_count() const = 0;
	virtual uint32_t get_face_count() const = 0;
	virtual BCS_RESULT resize_vertex_count(uint32_t num_vertices) = 0;
	virtual BCS_RESULT resize_face_and_index_count(uint32_t new_num_faces, uint32_t new_num_indices) = 0;
	virtual bool feature_supported(e_geometry_mesh_feature geometry_mesh_feature, unsigned int index = 0) const = 0;
	virtual BCS_RESULT apply_fixup(e_geometry_mesh_fixup fixup) const = 0;

	virtual BCS_RESULT property_unsafe(
		e_geometry_mesh_property property,
		uint32_t set_index,
		e_graphics_data_format& format,
		void*& property_data,
		uint32_t& max_index,
		uint32_t& stride) const = 0;

	virtual BCS_RESULT get_property_set_count(
		e_geometry_mesh_property property,
		uint32_t& set_count) const = 0;

	virtual BCS_RESULT get_property_format(
		e_geometry_mesh_property property,
		e_graphics_data_format& property_format) const = 0;

	virtual BCS_RESULT get_property_formats(
		e_geometry_mesh_property const* properties,
		unsigned int num_properties,
		e_graphics_data_format* property_formats) const = 0;

	virtual BCS_RESULT get_property(
		e_geometry_mesh_property property,
		uint32_t set_index,
		uint32_t start_index,
		uint32_t end_index,
		e_graphics_data_format target_format,
		void* property_data) const = 0;

	virtual BCS_RESULT set_property(
		e_geometry_mesh_property property,
		uint32_t set_index,
		uint32_t start_index,
		uint32_t end_index,
		e_graphics_data_format source_format,
		void const* property_data) const = 0;

	BCS_SHARED BCS_RESULT copy_to_render_buffer(
		e_geometry_mesh_property property,
		uint32_t set_index,
		e_graphics_data_format format,
		c_graphics_buffer& buffer) const;
};
