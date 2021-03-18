#pragma once

class c_halo4_debug_reader;
class c_halo4_tag_reader;
class c_halo4_resource_reader;
class c_halo4_localization_reader;
class c_halo4_tag_group;
class c_halo4_tag_instance;

struct s_halo4_cache_cluster_entry
{
	c_halo4_cache_file_reader* cache_reader;
	c_halo4_debug_reader* debug_reader;
	c_halo4_tag_reader* tag_reader;
	c_halo4_resource_reader* resource_reader;
	c_halo4_localization_reader* localization_reader;
};

enum e_halo4_resource_type
{
	_halo4_bitmap_texture_interop_resource,
	_halo4_sound_resource_definition,
	_halo4_facial_animation_resource_definition,
	_halo4_model_animation_tag_resource,
	_halo4_render_geometry_api_resource_definition,
	_halo4_bitmap_texture_interleaved_interop_resource,
	_halo4_structure_bsp_tag_resources,
	_halo4_structure_bsp_cache_file_tag_resources,
	_halo4_bink_resource,
	_halo4_pca_coefficients_resource_definition,
	_halo4_stitchable_bitmap_texture_interop_resource,
	_halo4_collision_model_resource,
	k_num_halo4_resource_types
};

struct s_halo4_tag_resource_info
{
	const char* name;
	blofeld::s_tag_struct_definition& definition;
	long definition_flags;
	short page_alignment_bits[3];
};
extern const s_halo4_tag_resource_info halo4_tag_resource_infos[k_num_halo4_resource_types];

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
	uint32_t size;
	uint32_t alignment_bits;
};
extern const s_halo4_tag_interop_info halo4_tag_interop_infos[k_num_halo4_interop_types];

class c_halo4_cache_cluster : public c_cache_cluster
{
public:
	friend c_debug_reader;
	friend c_tag_reader;
	friend c_resource_reader;
	friend c_localization_reader;
	c_halo4_cache_cluster(c_halo4_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build);
	virtual ~c_halo4_cache_cluster();

	BCS_RESULT get_debug_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_debug_reader*& debug_reader);
	BCS_RESULT get_tag_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_tag_reader*& tag_reader);
	BCS_RESULT get_resource_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_resource_reader*& resource_reader);
	BCS_RESULT get_localization_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_localization_reader*& localization_reader);

protected:
	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader);
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader);
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader);
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader);

public:
	s_engine_platform_build engine_platform_build;

	BCS_RESULT get_cache_file_entry(c_halo4_cache_file_reader& cache_reader, const s_halo4_cache_cluster_entry*& cache_file_entry);


	std::vector<s_halo4_cache_cluster_entry> entries;

	BCS_RESULT get_cache_reader_by_relative_path(const char* relative_path, c_halo4_cache_file_reader*& cache_reader);
};
