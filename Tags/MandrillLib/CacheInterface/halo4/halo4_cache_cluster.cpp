#include "mandrilllib-private-pch.h"

blofeld::s_tag_persistent_identifier k_xdkcompress_codec_identifier = { 0x7EDA2AB5, 0x80CF4906, 0x7343A8BD, 0xF0C7B36C };

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

#define D3D_VERTEX_BUFFER_INTEROP_ID { 0x12721193, 0x798F4648, 0xB08E254D, 0xFB5907DF }
static constexpr s_halo4_tag_interop_info d3d_vertex_buffer_interop =
{
	"s_tag_d3d_vertex_buffer",
	D3D_VERTEX_BUFFER_INTEROP_ID,
	0x2C,
	2
};

#define D3D_INDEX_BUFFER_INTEROP_ID { 0x08380D7D, 0xF14D4112, 0x82CE3471, 0x1E43A770 }
static constexpr s_halo4_tag_interop_info d3d_index_buffer_interop =
{
	"s_tag_d3d_index_buffer",
	D3D_INDEX_BUFFER_INTEROP_ID,
	0x2C,
	2
};
#define D3D_TEXTURE_INTEROP_ID { 0x64017671, 0x437A46F0, 0x9A33C422, 0x517096E3 }
static constexpr s_halo4_tag_interop_info d3d_texture_interop =
{
	"s_tag_d3d_texture",
	D3D_TEXTURE_INTEROP_ID,
	0x38,
	2
};
#define D3D_TEXTURE_INTERLEAVED_INTEROP_ID { 0x90486D0A, 0x944A4941, 0x9FE79AF0, 0x39E2E611 }
static constexpr s_halo4_tag_interop_info d3d_texture_interleaved_interop =
{
	"s_tag_d3d_texture_interleaved",
	D3D_TEXTURE_INTERLEAVED_INTEROP_ID,
	0x70,
	2
};
#define D3D_VERTEX_SHADER_INTEROP_ID { 0xA6D79D0E, 0xB84B4E35, 0x92071EB2, 0x6FB1B059 }
static constexpr s_halo4_tag_interop_info d3d_vertex_shader_interop =
{
	"s_tag_d3d_vertex_shader",
	D3D_VERTEX_SHADER_INTEROP_ID,
	0x4,
	2
};
#define D3D_PIXEL_SHADER_INTEROP_ID { 0x1578CC0C, 0xCE0043B3, 0x979C9919, 0xD43CBE05 }
static constexpr s_halo4_tag_interop_info d3d_pixel_shader_interop =
{
	"s_tag_d3d_pixel_shader",
	D3D_PIXEL_SHADER_INTEROP_ID,
	0x4,
	2
};
#define POLYART_VERTEX_BUFFER_INTEROP_ID { 0xA06E820C, 0x7AE94C17, 0xB4CFD590, 0xAAA62E0 }
static constexpr s_halo4_tag_interop_info PolyartVertexBufferInterop =
{
	"PolyartVertexBuffer",
	POLYART_VERTEX_BUFFER_INTEROP_ID,
	0x24,
	2
};
#define VECTORART_VERTEX_BUFFER_INTEROP_ID { 0xAE24DC6D, 0x9A604E07, 0xA799441A, 0x3E47B775 }
static constexpr s_halo4_tag_interop_info VectorartVertexBufferInterop =
{
	"PolyartVertexBuffer",
	VECTORART_VERTEX_BUFFER_INTEROP_ID,
	0x24,
	2
};
#define POLYART_INDEX_BUFFER_INTEROP_ID { 0xE0852B06, 0xBBAC4DF8, 0xAA48A764, 0x18DB2F80 }
static constexpr s_halo4_tag_interop_info PolyartIndexBufferInterop =
{
	"PolyartIndexBuffer",
	POLYART_INDEX_BUFFER_INTEROP_ID,
	0x24,
	2
};

const s_halo4_tag_interop_info halo4_tag_interop_infos[k_num_halo4_interop_types] =
{
	d3d_vertex_buffer_interop,
	d3d_index_buffer_interop,
	d3d_texture_interop,
	d3d_texture_interleaved_interop,
	d3d_vertex_shader_interop,
	d3d_pixel_shader_interop,
	PolyartVertexBufferInterop,
	VectorartVertexBufferInterop,
	PolyartIndexBufferInterop,
};

c_halo4_cache_cluster::c_halo4_cache_cluster(c_halo4_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build),
	entries()
{
	BCS_RESULT rs;
	BCS_VALIDATE_ARGUMENT_THROW(cache_readers);
	BCS_VALIDATE_ARGUMENT_THROW(cache_reader_count > 0);

	s_cache_file_buffer_info temp_info;

	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_halo4_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		s_halo4_cache_cluster_entry& entry = entries.emplace_back();

		entry.cache_reader = cache_reader;
		entry.debug_reader = nullptr;
		entry.tag_reader = nullptr;
		entry.resource_reader = nullptr;
		entry.localization_reader = nullptr;

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_debug_section_buffer, temp_info)))
		{
			entry.debug_reader = new c_halo4_debug_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_resources_section_buffer, temp_info)))
		{
			entry.resource_reader = new c_halo4_resource_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_localization_section_buffer, temp_info)))
		{
			entry.localization_reader = new c_halo4_localization_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_tag_section_buffer, temp_info)))
		{
			entry.tag_reader = new c_halo4_tag_reader(*this, *cache_reader);
		}

		debug_point;
	}

	for (s_halo4_cache_cluster_entry& entry : entries) // populate resource definitions
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		if (entry.tag_reader == nullptr)
		{
			continue;
		}

		if (BCS_FAILED(rs = entry.tag_reader->init_interop_table()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = entry.tag_reader->init_resource_table()))
		{
			throw(rs);
		}

		if (BCS_FAILED(rs = entry.tag_reader->init_interops()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = entry.tag_reader->init_resources()))
		{
			throw(rs);
		}


		debug_point;
	}

	debug_point;
}

c_halo4_cache_cluster::~c_halo4_cache_cluster()
{
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		delete entry.debug_reader;
		delete entry.localization_reader;
		delete entry.resource_reader;
		delete entry.tag_reader;
	}
}

BCS_RESULT c_halo4_cache_cluster::get_debug_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_debug_reader*& debug_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		debug_reader = cache_cluster_entry->debug_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_tag_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_tag_reader*& tag_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		tag_reader = cache_cluster_entry->tag_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_resource_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_resource_reader*& resource_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		resource_reader = cache_cluster_entry->resource_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_localization_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_localization_reader*& localization_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		localization_reader = cache_cluster_entry->localization_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_cache_file_entry(c_halo4_cache_file_reader& cache_reader, const s_halo4_cache_cluster_entry*& cache_cluster_entry)
{
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		if (entry.cache_reader == &cache_reader)
		{
			cache_cluster_entry = &entry;
			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo4_cache_cluster::get_cache_reader_by_relative_path(const char* relative_path, c_halo4_cache_file_reader*& cache_reader)
{
	BCS_RESULT rs = BCS_S_OK;
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		s_cache_file_build_info build_info;
		if (FAILED(rs = entry.cache_reader->get_build_info(build_info)))
		{
			return rs;
		}

		if (strcmp(build_info.relative_path.get_string(), relative_path) == 0)
		{
			cache_reader = entry.cache_reader;
			return rs;
		}
	}
	rs = BCS_E_NOT_FOUND; // failed to find a cache file
	
	return rs;
}

BCS_RESULT c_halo4_cache_cluster::get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader)
{
	return get_debug_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_debug_reader**>(&debug_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader)
{
	return get_tag_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_tag_reader**>(&tag_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader)
{
	return get_resource_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_resource_reader**>(&resource_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader)
{
	return get_localization_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_localization_reader**>(&localization_reader));
}
