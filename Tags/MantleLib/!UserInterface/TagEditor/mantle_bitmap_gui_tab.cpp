#include "mantlelib-private-pch.h"
#include "compressapi.h"
#pragma comment(lib, "Cabinet.lib")

#include <zlib/zlib/zlib.h>
//#include <zlib/zlib/inflate.h>
//#include <zlib/zopfli/zopfli.h>
//#include <zlib/zopfli/deflate.h>

c_mantle_bitmap_gui_tab::c_mantle_bitmap_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, v_tag_interface<blofeld::haloreach::s_bitmap_block_struct>& bitmap_tag_interface) :
	c_mantle_gui_tab("Bitmap Editor", "Bitmap Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	bitmap_tag_interface(bitmap_tag_interface),
	pTexture(nullptr),
	shader_resource_view(nullptr),
	dds_texture_buffer(nullptr),
	decompressed_buffer(nullptr)
{
	allow_close = false;
}

c_mantle_bitmap_gui_tab::~c_mantle_bitmap_gui_tab()
{

}

enum e_bitmap_format2
{
	_format_A8,
	_format_Y8,
	_format_AY8,
	_format_A8Y8,
	_format_Unused1,
	_format_Unused2,
	_format_R5G6B5,
	_format_Unused3,
	_format_A1R5G5B5,
	_format_A4R4G4B4,
	_format_X8R8G8B8,
	_format_A8R8G8B8,
	_format_Unused4,
	_format_Unused5,
	_format_DXT1,
	_format_DXT3,
	_format_DXT5,
	_format_P8_Bump,
	_format_P8,
	_format_ARGBFP32,
	_format_RGBFP32,
	_format_RGBFP16,
	_format_V8U8,
	_format_Unknown23,
	_format_Unknown24,
	_format_Unknown25,
	_format_Unknown26,
	_format_Unknown27,
	_format_Unknown28,
	_format_Unknown29,
	_format_Unknown30,
	_format_Unknown31,
	_format_Unknown32,
	_format_Unknown33,
	_format_Unknown34,
	_format_Unknown35,
	_format_DXT5a,
	_format_Unknown37,
	_format_DXN,
	_format_CTX1,
	_format_DXT3a_alpha,
	_format_DXT3a_mono,
	_format_DXT5a_alpha,
	_format_DXT5a_mono,
	_format_DXN_mono_alpha,
};

void c_mantle_bitmap_gui_tab::render_tab_contents_gui()
{
	using namespace DirectX;

	ImGui::Text("Bitmap Editor");
	
	c_legacy_tag_group_interface* play_interface = cache_file.get_group_interface_by_group_id(_legacy_tag_group_cache_file_resource_layout_table);
	v_tag_interface<blofeld::haloreach::s_cache_file_resource_layout_table_block_struct>* play_tag = dynamic_cast<decltype(play_tag)>(play_interface->get_tag_interfaces().front());
	ImGui::Text("Found Play Tag: %s", play_tag ? "true" : "false");

	c_legacy_tag_group_interface* zone_interface = cache_file.get_group_interface_by_group_id(_legacy_tag_group_cache_file_resource_gestalt);
	v_tag_interface<blofeld::haloreach::s_cache_file_resource_gestalt_block_struct>* zone_tag = dynamic_cast<decltype(zone_tag)>(zone_interface->get_tag_interfaces().front());
	ImGui::Text("Found Zone Tag: %s", zone_tag ? "true" : "false");

	unsigned short bitmap_resource_index = bitmap_tag_interface.stitchable_hardware_textures_block[0].texture_resource.resource_handle.get_absolute_index();
	ImGui::Text("bitmap_resource_index: %u", (unsigned int)bitmap_resource_index);

	auto& tag_resource = zone_tag->resources_block[bitmap_resource_index];

	//s_cache_file_resource_gestalt_definition::s_tag_resources_definition& tag_resource = zone_tag->tag_resources_block[bitmap_resource_index];
	
	if (tag_resource.page != -1)
	{
		auto& segment_block = play_tag->sections_block[tag_resource.page];

		debug_point;

		if (segment_block.file_page_indexes[1].page_index != -1)
		{

			debug_point;
		//	s_cache_file_resource_layout_table_definition::s_raw_pages_definition& low_res_raw_page = play_tag->raw_pages_block[segment_block.primary_page_index];
		//	s_cache_file_resource_layout_table_definition::s_raw_pages_definition& high_res_raw_page = play_tag->raw_pages_block[segment_block.secondary_page_index];

		//	if (high_res_raw_page.compression_codec_index != 0)
		//	{
		//		ImGui::Text("Unsupported resource compression codec");
		//		return;
		//	}

		//	ASSERT(high_res_raw_page.compression_codec_index == 0);



		//	//cache_file->GetTagBlockData()

		//	SectionCache& resources_section = cache_file.get_resources_section();
		//	char* data = resources_section.first + high_res_raw_page.block_offset;

		//	struct DDS_FILE_HEADER
		//	{
		//		DWORD file_magic;
		//		DDS_HEADER dds_header;
		//	};

		//	if (dds_texture_buffer == nullptr)
		//	{
		//		dds_texture_buffer = new char[high_res_raw_page.uncompressed_block_size + sizeof(DDS_FILE_HEADER)]{};
		//		ASSERT(dds_texture_buffer != nullptr);

		//		decompressed_buffer = dds_texture_buffer + sizeof(DDS_FILE_HEADER);
		//		{
		//			z_stream stream{};
		//			stream.avail_out = high_res_raw_page.uncompressed_block_size;
		//			stream.next_out = (Bytef*)decompressed_buffer;
		//			stream.avail_in = high_res_raw_page.compressed_block_size;
		//			stream.next_in = (Bytef*)data;
		//			int inflateInitResult = inflateInit2(&stream, -15);
		//			ASSERT(inflateInitResult >= Z_OK);
		//			int inflateResult = inflate(&stream, Z_SYNC_FLUSH);
		//			ASSERT(inflateResult >= Z_OK);
		//			int inflateEndResult = inflateEnd(&stream);
		//			ASSERT(inflateEndResult >= Z_OK);
		//		}
		//	}

		//	if (pTexture == nullptr)
		//	{
		//		{
		//			DDS_FILE_HEADER* file_header = reinterpret_cast<DDS_FILE_HEADER*>(dds_texture_buffer);
		//			file_header->file_magic = DDS_MAGIC;
		//			file_header->dds_header.size = sizeof(DDS_HEADER);											
		//			file_header->dds_header.flags =	 DDS_HEADER_FLAGS_TEXTURE | DDS_HEADER_FLAGS_MIPMAP | DDS_HEADER_FLAGS_LINEARSIZE;
		//			file_header->dds_header.height = bitmap_tag_interface.bitmap_data_block[0].height;			
		//			file_header->dds_header.width = bitmap_tag_interface.bitmap_data_block[0].width;			
		//			file_header->dds_header.pitchOrLinearSize = high_res_raw_page.uncompressed_block_size;		
		//			file_header->dds_header.depth = 0;															
		//			file_header->dds_header.mipMapCount = 1;		

		//			switch ((e_bitmap_format)bitmap_tag_interface.bitmap_data_block[0].format)
		//			{
		//			case _format_DXN:
		//				file_header->dds_header.ddspf = DDSPF_BC5_SNORM;
		//				break;
		//			case _format_DXT1:
		//				file_header->dds_header.ddspf = DDSPF_DXT1;
		//				break;
		//			case _format_DXT3:
		//				file_header->dds_header.ddspf = DDSPF_DXT3;
		//				break;
		//			case _format_DXT5:
		//			default:
		//				file_header->dds_header.ddspf = DDSPF_DXT5;
		//				break;
		//			}
		//			file_header->dds_header.caps = DDS_SURFACE_FLAGS_TEXTURE | DDS_SURFACE_FLAGS_MIPMAP;

		//		}

		//		int width = bitmap_tag_interface.bitmap_data_block[0].width;
		//		int height = bitmap_tag_interface.bitmap_data_block[0].height;

		//		size_t bytesCount = high_res_raw_page.uncompressed_block_size;
		//		size_t pixelsCount = static_cast<size_t>(width)* static_cast<size_t>(height);
		//		size_t bitsPerPixel = (bytesCount * 8) / pixelsCount;
		//		ASSERT(bitsPerPixel > 0);

		//		D3D11_TEXTURE2D_DESC desc{};

		//		desc.Width = width;
		//		desc.Height = height;
		//		desc.MipLevels = 1;
		//		desc.ArraySize = 1;

		//		switch ((e_bitmap_format)bitmap_tag_interface.bitmap_data_block[0].format)
		//		{
		//		case _format_DXN:
		//			desc.Format = DXGI_FORMAT_BC5_SNORM;
		//			break;
		//		case _format_DXT1:
		//			desc.Format = DXGI_FORMAT_BC1_UNORM;
		//			break;
		//		case _format_DXT3:
		//			desc.Format = DXGI_FORMAT_BC2_UNORM;
		//			break;
		//		case _format_DXT5:
		//		default:
		//			desc.Format = DXGI_FORMAT_BC3_UNORM;
		//			break;
		//		}


		//		desc.SampleDesc.Count = 1;
		//		desc.SampleDesc.Quality = 0;
		//		desc.Usage = D3D11_USAGE_DEFAULT;
		//		desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		//		desc.CPUAccessFlags = 0;
		//		desc.MiscFlags = 0;

		//		D3D11_SUBRESOURCE_DATA initData{};
		//		initData.pSysMem = decompressed_buffer;

		//		size_t num_bytes;
		//		size_t row_bytes;
		//		HRESULT getSurfaceInfoResult = GetSurfaceInfo(width, height, desc.Format, &num_bytes, &row_bytes, nullptr);
		//		ASSERT(SUCCEEDED(getSurfaceInfoResult));

		//		initData.SysMemPitch = static_cast<UINT>(row_bytes);
		//		initData.SysMemSlicePitch = static_cast<UINT>(num_bytes);

		//		HRESULT createTexture2DResult = c_render::s_pDevice->CreateTexture2D(&desc, &initData, &pTexture);
		//		ASSERT(SUCCEEDED(createTexture2DResult));
		//		ASSERT(pTexture);
		//	}

		//	if (shader_resource_view == nullptr)
		//	{
		//		HRESULT createShaderResourceViewResult = c_render::s_pDevice->CreateShaderResourceView(pTexture, NULL, &shader_resource_view);
		//		ASSERT(SUCCEEDED(createShaderResourceViewResult));
		//	}

		//	ImGui::Text("Bitmap Data Count: %u", bitmap_tag_interface.bitmap_data_block.count);
		//	for (s_bitmap_definition::s_bitmap_data_definition& bitmap_datum : bitmap_tag_interface.bitmap_data_block)
		//	{
		//		ImGui::Image(shader_resource_view, ImVec2(512, 512));
		//	}

		//	cache_file.get_resources_section();
		}
	}
}
