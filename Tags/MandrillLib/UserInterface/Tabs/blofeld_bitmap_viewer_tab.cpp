#include "mandrilllib-private-pch.h"

using namespace DirectX;

enum e_bitmap_format3
{
	_bitmap_format3_a8,
	_bitmap_format3_y8,
	_bitmap_format3_ay8,
	_bitmap_format3_a8y8,
	_bitmap_format3_unused1,
	_bitmap_format3_unused2,
	_bitmap_format3_r5g6b5,
	_bitmap_format3_unused3,
	_bitmap_format3_a1r5g5b5,
	_bitmap_format3_a4r4g4b4,
	_bitmap_format3_x8r8g8b8,
	_bitmap_format3_a8r8g8b8,
	_bitmap_format3_unused4,
	_bitmap_format3_dxt5_bias_alpha,
	_bitmap_format3_dxt1,
	_bitmap_format3_dxt3,
	_bitmap_format3_dxt5,
	_bitmap_format3_a4r4g4b4_font,
	_bitmap_format3_unused7,
	_bitmap_format3_unused8,
	_bitmap_format3_software_rgbfp32,
	_bitmap_format3_unused9,
	_bitmap_format3_v8u8,
	_bitmap_format3_g8b8,
	_bitmap_format3_abgrfp32,
	_bitmap_format3_abgrfp16,
	_bitmap_format3_16f_mono,
	_bitmap_format3_16f_red,
	_bitmap_format3_q8w8v8u8,
	_bitmap_format3_a2r10g10b10,
	_bitmap_format3_a16b16g16r16,
	_bitmap_format3_v16u16,
	_bitmap_format3_l16,
	_bitmap_format3_r16g16,
	_bitmap_format3_signedr16g16b16a16,
	_bitmap_format3_dxt3a,
	_bitmap_format3_dxt5a,
	_bitmap_format3_dxt3a_1111,
	_bitmap_format3_dxn,
	_bitmap_format3_ctx1,
	_bitmap_format3_dxt3a_alpha,
	_bitmap_format3_dxt3a_mono,
	_bitmap_format3_dxt5a_alpha,
	_bitmap_format3_dxt5a_mono,
	_bitmap_format3_dxn_mono_alpha,
	_bitmap_format3_dxt5_red,
	_bitmap_format3_dxt5_green,
	_bitmap_format3_dxt5_blue,
	_bitmap_format3_depth_24
};

const DirectX::DDS_PIXELFORMAT* bitmap_format_to_dds_pixel_format(e_bitmap_format3 bitmap_format, bool& is_linear_format)
{
	using namespace DirectX;

	is_linear_format = false;

	switch (bitmap_format)
	{
	case _bitmap_format3_a8:														return &DDSPF_A8;
	case _bitmap_format3_y8:														return &DDSPF_L8;
	case _bitmap_format3_ay8:														return &DDSPF_A8L8;
	case _bitmap_format3_a8y8:														return &DDSPF_A8L8_ALT;
	case _bitmap_format3_unused1:													return nullptr;
	case _bitmap_format3_unused2:													return nullptr;
	case _bitmap_format3_r5g6b5:													return &DDSPF_R5G6B5;
	case _bitmap_format3_unused3:													return nullptr;
	case _bitmap_format3_a1r5g5b5:													return &DDSPF_A1R5G5B5;
	case _bitmap_format3_a4r4g4b4:													return &DDSPF_A4R4G4B4;
	case _bitmap_format3_x8r8g8b8:													return &DDSPF_X8R8G8B8;
	case _bitmap_format3_a8r8g8b8:													return &DDSPF_A8R8G8B8;
	case _bitmap_format3_unused4:													return nullptr;
	case _bitmap_format3_dxt5_bias_alpha:											return nullptr;
	case _bitmap_format3_dxt1:							is_linear_format = true;	return &DDSPF_DXT1;
	case _bitmap_format3_dxt3:							is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt5:							is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_a4r4g4b4_font:												return &DDSPF_A4R4G4B4;
	case _bitmap_format3_unused7:													return nullptr;
	case _bitmap_format3_unused8:													return nullptr;
	case _bitmap_format3_software_rgbfp32:											return nullptr; // #TODO: DX10 header
	case _bitmap_format3_unused9:													return nullptr;
	case _bitmap_format3_v8u8:														return &DDSPF_V8U8;
	case _bitmap_format3_g8b8:														return nullptr; // unknown
	case _bitmap_format3_abgrfp32:													return nullptr; // DirectX 10
	case _bitmap_format3_abgrfp16:													return nullptr; // DirectX 10
	case _bitmap_format3_16f_mono:													return &DDSPF_L16;
	case _bitmap_format3_16f_red:													return nullptr;
	case _bitmap_format3_q8w8v8u8:													return &DDSPF_Q8W8V8U8;
	case _bitmap_format3_a2r10g10b10:												return nullptr; // DirectX 10
	case _bitmap_format3_a16b16g16r16:												return nullptr; // DirectX 10
	case _bitmap_format3_v16u16:													return &DDSPF_V16U16;
	case _bitmap_format3_l16:														return &DDSPF_L16;
	case _bitmap_format3_r16g16:  // DirectX 10 ?
	{
		static const DDS_PIXELFORMAT DDSPF_R16G16 = { sizeof(DDS_PIXELFORMAT), DDS_RGB,  0, 32, 0xffff0000, 0x0000ffff, 0x00000000, 0x00000000 };
		return &DDSPF_R16G16;
	}
	case _bitmap_format3_signedr16g16b16a16:										return nullptr; // DirectX 10
	case _bitmap_format3_dxt3a:														return nullptr;
	case _bitmap_format3_dxt5a:														return nullptr;
	case _bitmap_format3_dxt3a_1111:												return nullptr;
	case _bitmap_format3_dxn:							is_linear_format = true;	return &DDSPF_BC5_SNORM;
	case _bitmap_format3_ctx1:														return nullptr; // Xbox 360
	case _bitmap_format3_dxt3a_alpha:					is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt3a_mono:					is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt5a_alpha:					is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_dxt5a_mono:					is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_dxn_mono_alpha:											return nullptr;
	case _bitmap_format3_dxt5_red:													return nullptr;
	case _bitmap_format3_dxt5_green:												return nullptr;
	case _bitmap_format3_dxt5_blue:													return nullptr;
	case _bitmap_format3_depth_24:													return nullptr;
	default: throw;
	}
}

c_blofeld_bitmap_viewer_tab::c_blofeld_bitmap_viewer_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Bitmap Viewer", "Blofeld Bitmap Resource Viewer", &parent, false),
	tag_interface(tag_interface),
	cache_file(*dynamic_cast<decltype(&cache_file)>(&tag_interface.get_cache_file())),
	bitmap_tag(*dynamic_cast<decltype(&bitmap_tag)>(tag_interface.get_virtual_tag_interface())),
	texture(nullptr)
{
	char* dds_file_data = nullptr;

	if (bitmap_tag.bitmaps_block.count)
	{
		auto& bitmap = bitmap_tag.bitmaps_block[0];

		char* raw_resource_page_data = nullptr;
		c_bitmap_texture_interop_resource_entry* resource_entry = cache_file.get_resource_entry<c_bitmap_texture_interop_resource_entry>(bitmap_tag.hardware_textures_block[0].texture_resource.resource_handle.get_absolute_index());
		if (resource_entry)
		{
			raw_resource_page_data = cache_file.get_data_with_page_offset(resource_entry->entry.pixel_data.address);

			using namespace blofeld::haloreach;


			c_tag_group_interface* cache_file_resource_gestalt_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
			DEBUG_ASSERT(cache_file_resource_gestalt_group != nullptr);
			DEBUG_ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() == 1);
			v_tag_interface<s_cache_file_resource_gestalt_block_struct>* cache_file_resource_gestalt = dynamic_cast<decltype(cache_file_resource_gestalt)>(cache_file_resource_gestalt_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
			DEBUG_ASSERT(cache_file_resource_gestalt != nullptr);

			c_tag_group_interface* cache_file_resource_layout_table_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG);
			DEBUG_ASSERT(cache_file_resource_layout_table_group != nullptr);
			DEBUG_ASSERT(cache_file_resource_layout_table_group->get_tag_interfaces_count() == 1);
			v_tag_interface<s_cache_file_resource_layout_table_block_struct>* cache_file_resource_layout_table = dynamic_cast<decltype(cache_file_resource_layout_table)>(cache_file_resource_layout_table_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
			DEBUG_ASSERT(cache_file_resource_layout_table != nullptr);

			auto resource_data = &cache_file_resource_gestalt->resources_block[bitmap_tag.hardware_textures_block[0].texture_resource.resource_handle.get_absolute_index()];
			DEBUG_ASSERT(resource_data->resource_type_index == _haloreach_resource_type_bitmap_texture_interop_resource);

			auto& section = cache_file_resource_layout_table->sections_block[resource_data->page];
			auto file_page = &cache_file_resource_layout_table->file_pages_block[section.file_page_indexes[0].page_index];

			uint32_t cluster_cache_file_index = -1;
			if (file_page->shared_file == -1) // local file
			{
				cluster_cache_file_index = 2;
			}
			else
			{
				auto& shared_file = cache_file_resource_layout_table->shared_files_block[file_page->shared_file];
				const char* dvd_path = shared_file.dvd_relative_path.get_buffer();

				// #TODO: Clean this up, this is super bad!!!!!!!!!!!

				if (_stricmp(dvd_path, "maps\\shared.map") == 0)
				{
					cluster_cache_file_index = 0;
				}
				else if (_stricmp(dvd_path, "maps\\shared.map") == 0)
				{
					cluster_cache_file_index = 1;
				}
				else if (_stricmp(dvd_path, "maps\\english.map") == 0)
				{

				}
				else DEBUG_ONLY(FATAL_ERROR(L"Unknown resource cache file"));
			}

			const s_section_cache& resources_section = cache_file.get_resources_section();
			uint32_t file_offset = resources_section.mask + file_page->file_offset;
			uint32_t page_offset = cache_file.cluster->encode_page_address(cluster_cache_file_index, file_offset);

			char* new_data = cache_file.get_data_with_page_offset(page_offset);
			raw_resource_page_data = new_data;



			char* uncompressed_resource_page_data = nullptr;
			if (raw_resource_page_data)
			{
				uint32_t compressed_size = resource_entry->get_compressed_size();
				uint32_t uncompressed_size = resource_entry->get_uncompressed_size();

				uncompressed_resource_page_data = new char[uncompressed_size];

				z_stream stream{};
				stream.avail_out = uncompressed_size;
				stream.next_out = (Bytef*)uncompressed_resource_page_data;
				stream.avail_in = compressed_size;
				stream.next_in = (Bytef*)raw_resource_page_data;
				int inflateInitResult = inflateInit2(&stream, -15);
				ASSERT(inflateInitResult >= Z_OK);
				int inflateResult = inflate(&stream, Z_SYNC_FLUSH);
				ASSERT(inflateResult >= Z_OK);
				int inflateEndResult = inflateEnd(&stream);
				ASSERT(inflateEndResult >= Z_OK);
			}

			

			if (uncompressed_resource_page_data != nullptr)
			{
				char* uncompressed_resource_data = uncompressed_resource_page_data + section.page_offsets[0].offset;

				bool is_linear_format = false;
				const DirectX::DDS_PIXELFORMAT* dds_pixel_format = bitmap_format_to_dds_pixel_format((e_bitmap_format3)bitmap.format, is_linear_format);

				size_t dds_file_data_size = sizeof(int) + sizeof(DDS_HEADER);
				if (bitmap.high_res_pixels_size > 0)
				{
					dds_file_data_size += bitmap.high_res_pixels_size;
				}
				else
				{
					dds_file_data_size += bitmap.pixels_size_bytes;
				}

				dds_file_data = new char[dds_file_data_size] {};

				int& dds_magic = *reinterpret_cast<int*>(dds_file_data);
				dds_magic = DDS_MAGIC;

				DDS_HEADER& dds_header = *reinterpret_cast<DDS_HEADER*>(&dds_magic + 1);
				dds_header.size = sizeof(DDS_HEADER);
				dds_header.flags = DDS_HEADER_FLAGS_TEXTURE | DDS_HEADER_FLAGS_MIPMAP;
				dds_header.height = bitmap.height / 2;
				dds_header.width = bitmap.width / 2;
				dds_header.depth = 0;
				dds_header.mipMapCount = 1; // #TODO: export other mips


				switch ((e_bitmap_format)bitmap.format)
				{
				case _bitmap_format_dxn:
					dds_header.ddspf = DDSPF_BC5_SNORM;
					break;
				case _bitmap_format_dxt1:
					dds_header.ddspf = DDSPF_DXT1;
					break;
				case _bitmap_format_dxt3:
					dds_header.ddspf = DDSPF_DXT3;
					break;
				case _bitmap_format_dxt5:
				default:
					dds_header.ddspf = DDSPF_DXT5;
					break;
				}
				//dds_header.ddspf = *dds_pixel_format;

				dds_header.caps = DDS_SURFACE_FLAGS_TEXTURE | DDS_SURFACE_FLAGS_MIPMAP;

				char* dds_data = reinterpret_cast<char*>(&dds_header + 1);

				if (bitmap.high_res_pixels_size > 0)
				{
					if (is_linear_format)
					{
						dds_header.flags |= DDS_HEADER_FLAGS_LINEARSIZE;
						dds_header.pitchOrLinearSize = bitmap.high_res_pixels_size;
					}
					else
					{
						// #TODO: calculate pitch correctly
						dds_header.pitchOrLinearSize = (dds_header.ddspf.RGBBitCount * dds_header.width) / 8;
					}

					memcpy(dds_data, uncompressed_resource_data, bitmap.high_res_pixels_size);
				}
				else
				{
					if (is_linear_format)
					{
						dds_header.flags |= DDS_HEADER_FLAGS_LINEARSIZE;
						dds_header.pitchOrLinearSize = bitmap.pixels_size_bytes;
					}
					else
					{
						// #TODO: calculate pitch correctly
						dds_header.pitchOrLinearSize = (dds_header.ddspf.RGBBitCount * dds_header.width) / 8;
					}

					memcpy(dds_data, uncompressed_resource_data, bitmap.pixels_size_bytes);
				}
			}
		}

		debug_point;

	}

	if (dds_file_data != nullptr)
	{
		auto& bitmap = bitmap_tag.bitmaps_block[0];

		DDS_HEADER& dds_header = *reinterpret_cast<DDS_HEADER*>(dds_file_data + 4);

		D3D11_TEXTURE2D_DESC desc{};
		desc.Width = dds_header.width;
		desc.Height = dds_header.height;
		desc.MipLevels = 1;
		desc.ArraySize = 1;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		desc.CPUAccessFlags = 0;
		desc.MiscFlags = 0;

		switch ((e_bitmap_format)bitmap.format)
		{
		case _bitmap_format_dxn:
			desc.Format = DXGI_FORMAT_BC5_SNORM;
			break;
		case _bitmap_format_dxt1:
			desc.Format = DXGI_FORMAT_BC1_UNORM;
			break;
		case _bitmap_format_dxt3:
			desc.Format = DXGI_FORMAT_BC2_UNORM;
			break;
		case _bitmap_format_dxt5:
		default:
			desc.Format = DXGI_FORMAT_BC3_UNORM;
			break;
		}

		size_t num_bytes;
		size_t row_bytes;
		HRESULT get_surface_info_result = GetSurfaceInfo(dds_header.width, dds_header.height, desc.Format, &num_bytes, &row_bytes, nullptr);
		ASSERT(SUCCEEDED(get_surface_info_result));

		D3D11_SUBRESOURCE_DATA subresource_init_data{};
		subresource_init_data.pSysMem = dds_file_data;
		subresource_init_data.SysMemPitch = static_cast<UINT>(row_bytes);
		subresource_init_data.SysMemSlicePitch = static_cast<UINT>(num_bytes);

		
		HRESULT create_texture_2d_result = c_render::s_device->CreateTexture2D(&desc, &subresource_init_data, &texture);
		ASSERT(SUCCEEDED(create_texture_2d_result));
		ASSERT(texture != nullptr);

		HRESULT create_shader_resource_view_result = c_render::s_device->CreateShaderResourceView(texture, NULL, &shader_resource_view);
		ASSERT(SUCCEEDED(create_shader_resource_view_result));
	}
}

c_blofeld_bitmap_viewer_tab::~c_blofeld_bitmap_viewer_tab()
{

}

void c_blofeld_bitmap_viewer_tab::render_impl()
{
	ImGui::TextUnformatted("Hello world");

	if (shader_resource_view)
	{
		ImGui::Image(shader_resource_view, ImVec2(1024, 1024));
	}
}

void c_blofeld_bitmap_viewer_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{

}

void c_blofeld_bitmap_viewer_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_bitmap_viewer_tab::render_game_layer_impl()
{

}
