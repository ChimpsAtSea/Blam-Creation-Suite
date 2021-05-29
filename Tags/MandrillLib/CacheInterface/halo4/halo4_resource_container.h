#pragma once

class c_halo4_cache_file_reader;
struct s_halo4_tag_instance_info;

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

struct s_resource_priority_data
{
	c_halo4_cache_file_reader* resource_cache_file;
	const char* page_data_pointer;
	long page_file_offset;
	long page_file_size;
	long page_size;
	long resource_page_offset;
	short page_index;
	e_halo4_compression_codec compression_codec;
};

struct s_resource_priority_datas
{
	unsigned long long id;
	s_resource_priority_data data[3];
	const char* naive_resource_control_data;
	const s_halo4_tag_instance_info* instance_info;
	unsigned long resource_index;
	c_flags<blofeld::xbox360_gen3::e_cache_file_resource_data_flags_definition, short, blofeld::xbox360_gen3::k_cache_file_resource_data_flags_definition_count> flags;

	void make_id();
};

class c_halo4_resource_container
{
public:
	c_halo4_resource_container(e_halo4_resource_type resource_type, const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
	virtual ~c_halo4_resource_container();

	virtual void digest_page(c_halo4_cache_file_reader& cache_reader, unsigned long page_index, const char* page_data);

	e_halo4_resource_type resource_type;
	const s_halo4_tag_instance_info& instance_info;
	s_resource_priority_datas resource_priority_datas;
};

class c_halo4_bitmap_texture_interop_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_bitmap_texture_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
	virtual void digest_page(c_halo4_cache_file_reader& cache_reader, unsigned long page_index, const char* page_data);

	BCS_RESULT get_sub_bitmap_index_by_resource_index(c_halo4_cache_file_reader& cache_reader, unsigned long& index) const;
};

class c_halo4_sound_resource_definition :
	public c_halo4_resource_container
{
public:
	c_halo4_sound_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_facial_animation_resource_definition :
	public c_halo4_resource_container
{
public:
	c_halo4_facial_animation_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_model_animation_tag_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_model_animation_tag_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_render_geometry_api_resource_definition :
	public c_halo4_resource_container
{
public:
	c_halo4_render_geometry_api_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_bitmap_texture_interleaved_interop_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_bitmap_texture_interleaved_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_structure_bsp_tag_resources :
	public c_halo4_resource_container
{
public:
	c_halo4_structure_bsp_tag_resources(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_structure_bsp_cache_file_tag_resources :
	public c_halo4_resource_container
{
public:
	c_halo4_structure_bsp_cache_file_tag_resources(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_bink_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_bink_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_pca_coefficients_resource_definition :
	public c_halo4_resource_container
{
public:
	c_halo4_pca_coefficients_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_stitchable_bitmap_texture_interop_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_stitchable_bitmap_texture_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};

class c_halo4_collision_model_resource :
	public c_halo4_resource_container
{
public:
	c_halo4_collision_model_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas);
};
