#include "mandrilllib-private-pch.h"

static constexpr s_halo4_tag_resource_info bitmap_texture_interop_resource =
{
	"bitmap_texture_interop_resource",
	blofeld::macaque::bitmap_texture_interop_resource_struct,
	4,
	{ 12, 12, 12 }
};
static constexpr s_halo4_tag_resource_info sound_resource_definition =
{
	"sound_resource_definition",
	blofeld::macaque::sound_resource_definition_struct,
	2,
	{ /* #TODO: unknown */ }
};
static constexpr s_halo4_tag_resource_info facial_animation_resource_definition =
{
	"facial_animation_resource_definition",
	blofeld::macaque::facial_animation_resource_definition_struct,
	0,
	{ 0, 2, 0 }
};
static constexpr s_halo4_tag_resource_info model_animation_tag_resource =
{
	"model_animation_tag_resource",
	blofeld::macaque::model_animation_tag_resource_struct,
	16,
	{ 4, 0, 0 }
};
static constexpr s_halo4_tag_resource_info render_geometry_api_resource_definition =
{
	"render_geometry_api_resource_definition",
	blofeld::macaque::render_geometry_api_resource_definition_struct,
	0,
	{ 2, 0, 0 }
};
static constexpr s_halo4_tag_resource_info bitmap_texture_interleaved_interop_resource =
{
	"bitmap_texture_interleaved_interop_resource",
	blofeld::macaque::bitmap_texture_interleaved_interop_resource_struct,
	4,
	{ 12, 12, 0 }
};
static constexpr s_halo4_tag_resource_info structure_bsp_tag_resources =
{
	"structure_bsp_tag_resources",
	blofeld::macaque::structure_bsp_tag_resources_struct,
	0,
	{ 7, 0, 0 }
};
static constexpr s_halo4_tag_resource_info structure_bsp_cache_file_tag_resources =
{
	"structure_bsp_cache_file_tag_resources",
	blofeld::macaque::structure_bsp_cache_file_tag_resources_struct,
	0,
	{ 4, 0, 0 }
};
static constexpr s_halo4_tag_resource_info bink_resource =
{
	"bink_resource",
	blofeld::macaque::bink_resource_struct,
	0,
	{ /* #TODO: unknown */ }
};
static constexpr s_halo4_tag_resource_info pca_coefficients_resource_definition =
{
	"pca_coefficients_resource_definition",
	blofeld::macaque::pca_coefficients_resource_definition_struct,
	0,
	{ /* #TODO: unknown */ }
};
static constexpr s_halo4_tag_resource_info stitchable_bitmap_texture_interop_resource =
{
	"stitchable_bitmap_texture_interop_resource",
	blofeld::macaque::stitchable_bitmap_texture_interop_resource_struct,
	12,
	{ 12, 12, 12 }
};
static constexpr s_halo4_tag_resource_info collision_model_resource =
{
	"collision_model_resource",
	blofeld::macaque::collision_model_resource_struct,
	0,
	{ 7, 0, 0 }
};

const s_halo4_tag_resource_info halo4_tag_resource_infos[k_num_halo4_resource_types] =
{
	bitmap_texture_interop_resource,
	sound_resource_definition,
	facial_animation_resource_definition,
	model_animation_tag_resource,
	render_geometry_api_resource_definition,
	bitmap_texture_interleaved_interop_resource,
	structure_bsp_tag_resources,
	structure_bsp_cache_file_tag_resources,
	bink_resource,
	pca_coefficients_resource_definition,
	stitchable_bitmap_texture_interop_resource,
	collision_model_resource,
};

c_halo4_resource_container::c_halo4_resource_container(e_halo4_resource_type resource_type, const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	resource_type(resource_type),
	instance_info(instance_info),
	resource_priority_datas(resource_priority_datas)
{

}

c_halo4_resource_container::~c_halo4_resource_container()
{

}

void c_halo4_resource_container::digest_page(c_halo4_cache_file_reader& cache_reader, unsigned long page_index, const char* page_data)
{

}

c_halo4_bitmap_texture_interop_resource::c_halo4_bitmap_texture_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bitmap_texture_interop_resource, instance_info, resource_priority_datas)
{

}

void c_halo4_bitmap_texture_interop_resource::digest_page(c_halo4_cache_file_reader& cache_reader, unsigned long page_index, const char* page_data)
{
	using namespace blofeld::xbox360_gen3;

	if (resource_priority_datas.flags.is_clear())
	{
		return; // nothing to do. is this bad?
	}

	//if (this->resource_priority_datas.data[0].page_index != page_index)
	//{
	//	return;
	//}

	const s_render_texture_interop_definition_struct* render_texture_interop_struct_data = reinterpret_cast<decltype(render_texture_interop_struct_data)>(resource_priority_datas.naive_resource_control_data);
	s_render_texture_interop_definition_struct render_texture_interop_struct = *render_texture_interop_struct_data;
	byteswap(render_texture_interop_struct);

	c_fixed_path filepath;
	filepath.format("data\\%s.%s.bin", instance_info.instance_name, instance_info.group_info->group_name);

	filesystem_write_file_from_memory(filepath, page_data, 1);

	//FILE* file = fopen(filepath.c_str(), "wb");
	//if (file)
	//{
	//	const char* resource_data = page_data + resource_priority_datas.data[0].resource_page_offset;
	//	if (resource_priority_datas.flags.test(_cache_file_resource_data_flags_definition_has_highest_priority_data))
	//	{
	//		fwrite(resource_data, 1, resource_priority_datas.data[0].page_size, file);
	//	}
	//	if (resource_priority_datas.flags.test(_cache_file_resource_data_flags_definition_has_medium_priority_data))
	//	{
	//		fwrite(resource_data, 1, resource_priority_datas.data[0].page_size, file);
	//	}
	//	if (resource_priority_datas.flags.test(_cache_file_resource_data_flags_definition_has_low_priority_data))
	//	{
	//		fwrite(resource_data, 1, resource_priority_datas.data[0].page_size, file);
	//	}

	//	fflush(file);
	//	fclose(file);
	//}

}

c_halo4_sound_resource_definition::c_halo4_sound_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_sound_resource_definition, instance_info, resource_priority_datas)
{

}

c_halo4_facial_animation_resource_definition::c_halo4_facial_animation_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_facial_animation_resource_definition, instance_info, resource_priority_datas)
{

}

c_halo4_model_animation_tag_resource::c_halo4_model_animation_tag_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_model_animation_tag_resource, instance_info, resource_priority_datas)
{

}

c_halo4_render_geometry_api_resource_definition::c_halo4_render_geometry_api_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_render_geometry_api_resource_definition, instance_info, resource_priority_datas)
{

}

c_halo4_bitmap_texture_interleaved_interop_resource::c_halo4_bitmap_texture_interleaved_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bitmap_texture_interleaved_interop_resource, instance_info, resource_priority_datas)
{

}

c_halo4_structure_bsp_tag_resources::c_halo4_structure_bsp_tag_resources(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_structure_bsp_tag_resources, instance_info, resource_priority_datas)
{

}

c_halo4_structure_bsp_cache_file_tag_resources::c_halo4_structure_bsp_cache_file_tag_resources(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_structure_bsp_cache_file_tag_resources, instance_info, resource_priority_datas)
{

}

c_halo4_bink_resource::c_halo4_bink_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bink_resource, instance_info, resource_priority_datas)
{

}

c_halo4_pca_coefficients_resource_definition::c_halo4_pca_coefficients_resource_definition(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_pca_coefficients_resource_definition, instance_info, resource_priority_datas)
{

}

c_halo4_stitchable_bitmap_texture_interop_resource::c_halo4_stitchable_bitmap_texture_interop_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_stitchable_bitmap_texture_interop_resource, instance_info, resource_priority_datas)
{

}

c_halo4_collision_model_resource::c_halo4_collision_model_resource(const s_halo4_tag_instance_info& instance_info, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_collision_model_resource, instance_info, resource_priority_datas)
{

}

void s_resource_priority_datas::make_id()
{
	id = XXH64(data, sizeof(data), XXHASH_CX_XXH64_SEED);
}
