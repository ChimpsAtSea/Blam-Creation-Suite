#include "highlevelcachefileserialization-private-pch.h"

static s_halo4_tag_resource_info bitmap_texture_interop_resource =
{
	"bitmap_texture_interop_resource",
	blofeld::bitmap_texture_interop_resource_struct,
	4,
	{ 12, 12, 12 }
};
static s_halo4_tag_resource_info sound_resource_definition =
{
	"sound_resource_definition",
	blofeld::sound_resource_definition_struct,
	2,
	{ /* #TODO: unknown */ }
};
static s_halo4_tag_resource_info facial_animation_resource_definition =
{
	"facial_animation_resource_definition",
	blofeld::facial_animation_resource_definition_struct,
	0,
	{ 0, 2, 0 }
};
static s_halo4_tag_resource_info model_animation_tag_resource =
{
	"model_animation_tag_resource",
	blofeld::model_animation_tag_resource_struct,
	16,
	{ 4, 0, 0 }
};
static s_halo4_tag_resource_info render_geometry_api_resource_definition =
{
	"render_geometry_api_resource_definition",
	blofeld::render_geometry_api_resource_definition_struct,
	0,
	{ 2, 0, 0 }
};
static s_halo4_tag_resource_info bitmap_texture_interleaved_interop_resource =
{
	"bitmap_texture_interleaved_interop_resource",
	blofeld::bitmap_texture_interleaved_interop_resource_struct,
	4,
	{ 12, 12, 0 }
};
static s_halo4_tag_resource_info structure_bsp_tag_resources =
{
	"structure_bsp_tag_resources",
	blofeld::structure_bsp_tag_resources_struct,
	0,
	{ 7, 0, 0 }
};
static s_halo4_tag_resource_info structure_bsp_cache_file_tag_resources =
{
	"structure_bsp_cache_file_tag_resources",
	blofeld::structure_bsp_cache_file_tag_resources_struct,
	0,
	{ 4, 0, 0 }
};
static s_halo4_tag_resource_info bink_resource =
{
	"bink_resource",
	blofeld::bink_resource_struct,
	0,
	{ /* #TODO: unknown */ }
};
static s_halo4_tag_resource_info pca_coefficients_resource_definition =
{
	"pca_coefficients_resource_definition",
	blofeld::pca_coefficients_resource_definition_struct,
	0,
	{ /* #TODO: unknown */ }
};
static s_halo4_tag_resource_info stitchable_bitmap_texture_interop_resource =
{
	"stitchable_bitmap_texture_interop_resource",
	blofeld::stitchable_bitmap_texture_interop_resource_struct,
	12,
	{ 12, 12, 12 }
};
static s_halo4_tag_resource_info collision_model_resource =
{
	"collision_model_resource",
	blofeld::collision_model_resource_struct,
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

c_halo4_resource_container::c_halo4_resource_container(e_halo4_resource_type resource_type, c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	resource_type(resource_type),
	tag_instance(tag_instance),
	resource_priority_datas(resource_priority_datas)
{

}

c_halo4_resource_container::~c_halo4_resource_container()
{

}

void c_halo4_resource_container::digest_page(c_halo4_cache_file_reader& cache_reader, uint32_t page_index, const char* page_data)
{

}

c_halo4_bitmap_texture_interop_resource::c_halo4_bitmap_texture_interop_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bitmap_texture_interop_resource, tag_instance, resource_priority_datas)
{

}

void c_halo4_bitmap_texture_interop_resource::digest_page(c_halo4_cache_file_reader& cache_reader, uint32_t page_index, const char* page_data)
{
	using namespace blofeld::xbox360_gen3;

	if (resource_priority_datas.flags.is_clear())
	{
		return; // nothing to do. is this bad?
	}

	const char* tag_instance_name = nullptr;
	c_halo4_tag_group* tag_group = nullptr;
	const char* tag_group_name = nullptr;

	ASSERT(BCS_SUCCEEDED(tag_instance.get_instance_name(tag_instance_name)));
	ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_group(_tag_group)));
	ASSERT(BCS_SUCCEEDED(tag_group->get_group_name(tag_group_name)));

	unsigned int debug_index = 0;
	for (auto& resource_priority_data : resource_priority_datas.data)
	{
		if (resource_priority_data.page_index == page_index)
		{
			//if (this->resource_priority_datas.data[0].page_index != page_index)
			//{
			//	return;
			//}

			//const s_render_texture_interop_definition_struct* render_texture_interop_struct_data = reinterpret_cast<decltype(render_texture_interop_struct_data)>(resource_priority_datas.naive_resource_control_data);
			//s_render_texture_interop_definition_struct render_texture_interop_struct = *render_texture_interop_struct_data;
			//byteswap_inplace(render_texture_interop_struct);

			uint32_t sub_bitmap_index;
			ASSERT(BCS_SUCCEEDED(get_sub_bitmap_index_by_resource_index(cache_reader, sub_bitmap_index)));

			c_fixed_path filepath;
			filepath.format("data\\%s.%s.%u.%u.bin", tag_instance_name, tag_group_name, sub_bitmap_index, debug_index);

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
		debug_index++;
	}
}

BCS_RESULT c_halo4_bitmap_texture_interop_resource::get_sub_bitmap_index_by_resource_index(c_halo4_cache_file_reader& cache_reader, uint32_t& index) const
{
	using namespace blofeld::xbox360_gen3;

	const void* tag_instance_data = nullptr;
	ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_data(tag_instance_data)));

	s_bitmap_block_struct_definition bitmap = *static_cast<const s_bitmap_block_struct_definition*>(tag_instance_data);
	byteswap_inplace(bitmap);

	BCS_RESULT rs = BCS_S_OK;

	c_halo4_tag_reader* tag_reader;
	if (BCS_FAILED(rs = cache_reader.cache_cluster->get_tag_reader(cache_reader, tag_reader)))
	{
		return rs;
	}

	if(bitmap.hardware_textures_block.count > 0)
	{
		const s_bitmap_texture_interop_block_struct_definition* hardware_textures_block_data;
		if (BCS_FAILED(rs = tag_reader->page_offset_to_pointer(bitmap.hardware_textures_block.address, *reinterpret_cast<const void**>(&hardware_textures_block_data))))
		{
			return rs;
		}

		for (uint32_t hardware_texture_index = 0; hardware_texture_index < bitmap.hardware_textures_block.count; hardware_texture_index++)
		{
			s_bitmap_texture_interop_block_struct_definition hardware_texture = hardware_textures_block_data[hardware_texture_index];
			byteswap_inplace(hardware_texture);

			uint32_t resource_index = hardware_texture.texture_resource.resource_handle.get_absolute_index();

			if (resource_index == resource_priority_datas.resource_index)
			{
				index = hardware_texture_index;
				return BCS_S_OK;
			}
		}
	}

	if (bitmap.stitchable_hardware_textures_block.count > 0)
	{
		const s_stitchable_bitmap_texture_interop_block_struct_definition* stitchable_hardware_textures_block_data;
		if (BCS_FAILED(rs = tag_reader->page_offset_to_pointer(bitmap.stitchable_hardware_textures_block.address, *reinterpret_cast<const void**>(&stitchable_hardware_textures_block_data))))
		{
			return rs;
		}

		for (uint32_t stitchable_hardware_texture_index = 0; stitchable_hardware_texture_index < bitmap.stitchable_hardware_textures_block.count; stitchable_hardware_texture_index++)
		{
			s_stitchable_bitmap_texture_interop_block_struct_definition stitchable_hardware_texture = stitchable_hardware_textures_block_data[stitchable_hardware_texture_index];
			byteswap_inplace(stitchable_hardware_texture);

			uint32_t resource_index = stitchable_hardware_texture.texture_resource.resource_handle.get_absolute_index();

			if (resource_index == resource_priority_datas.resource_index)
			{
				index = stitchable_hardware_texture_index;
				return BCS_S_OK;
			}
		}
	}

	if (bitmap.interleaved_hardware_textures_block.count > 0)
	{
		const s_bitmap_texture_interleaved_interop_block_struct_definition* interleaved_hardware_textures_block_data;
		if (BCS_FAILED(rs = tag_reader->page_offset_to_pointer(bitmap.interleaved_hardware_textures_block.address, *reinterpret_cast<const void**>(&interleaved_hardware_textures_block_data))))
		{
			return rs;
		}

		for (uint32_t interleaved_hardware_texture_index = 0; interleaved_hardware_texture_index < bitmap.interleaved_hardware_textures_block.count; interleaved_hardware_texture_index++)
		{
			s_bitmap_texture_interleaved_interop_block_struct_definition interleaved_hardware_texture = interleaved_hardware_textures_block_data[interleaved_hardware_texture_index];
			byteswap_inplace(interleaved_hardware_texture);

			uint32_t resource_index = interleaved_hardware_texture.interleaved_texture_resource.resource_handle.get_absolute_index();

			if (resource_index == resource_priority_datas.resource_index)
			{
				index = interleaved_hardware_texture_index;
				return BCS_S_OK;
			}
		}
	}

	return BCS_E_FAIL;
}

c_halo4_sound_resource_definition::c_halo4_sound_resource_definition(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_sound_resource_definition, tag_instance, resource_priority_datas)
{

}

c_halo4_facial_animation_resource_definition::c_halo4_facial_animation_resource_definition(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_facial_animation_resource_definition, tag_instance, resource_priority_datas)
{

}

c_halo4_model_animation_tag_resource::c_halo4_model_animation_tag_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_model_animation_tag_resource, tag_instance, resource_priority_datas)
{

}

c_halo4_render_geometry_api_resource_definition::c_halo4_render_geometry_api_resource_definition(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_render_geometry_api_resource_definition, tag_instance, resource_priority_datas)
{

}

c_halo4_bitmap_texture_interleaved_interop_resource::c_halo4_bitmap_texture_interleaved_interop_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bitmap_texture_interleaved_interop_resource, tag_instance, resource_priority_datas)
{

}

c_halo4_structure_bsp_tag_resources::c_halo4_structure_bsp_tag_resources(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_structure_bsp_tag_resources, tag_instance, resource_priority_datas)
{

}

c_halo4_structure_bsp_cache_file_tag_resources::c_halo4_structure_bsp_cache_file_tag_resources(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_structure_bsp_cache_file_tag_resources, tag_instance, resource_priority_datas)
{

}

c_halo4_bink_resource::c_halo4_bink_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_bink_resource, tag_instance, resource_priority_datas)
{

}

c_halo4_pca_coefficients_resource_definition::c_halo4_pca_coefficients_resource_definition(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_pca_coefficients_resource_definition, tag_instance, resource_priority_datas)
{

}

c_halo4_stitchable_bitmap_texture_interop_resource::c_halo4_stitchable_bitmap_texture_interop_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_stitchable_bitmap_texture_interop_resource, tag_instance, resource_priority_datas)
{

}

c_halo4_collision_model_resource::c_halo4_collision_model_resource(c_halo4_tag_instance& tag_instance, s_resource_priority_datas const& resource_priority_datas) :
	c_halo4_resource_container(_halo4_collision_model_resource, tag_instance, resource_priority_datas)
{

}

void s_resource_priority_datas::make_id()
{
	id = XXH64(data, sizeof(data), XXHASH_CX_XXH64_SEED);
}
