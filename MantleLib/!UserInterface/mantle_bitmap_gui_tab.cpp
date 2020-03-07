#include "mantlelib-private-pch.h"
#include "compressapi.h"
#pragma comment(lib, "Cabinet.lib")

#include <zlib/zlib/zlib.h>
//#include <zlib/zlib/inflate.h>
//#include <zlib/zopfli/zopfli.h>
//#include <zlib/zopfli/deflate.h>


c_mantle_bitmap_gui_tab::c_mantle_bitmap_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tag, v_tag_interface<s_bitmap_definition>& bitmap_tag_interface) :
	c_mantle_gui_tab("Bitmap Editor", "Bitmap Editor"),
	cache_file(cache_file),
	parent_tag(parent_tag),
	bitmap_tag_interface(bitmap_tag_interface)
{
	allow_close = false;
}

c_mantle_bitmap_gui_tab::~c_mantle_bitmap_gui_tab()
{

}

void c_mantle_bitmap_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Bitmap Editor");


	c_tag_group_interface* play_interface = cache_file.get_group_interface_by_group_id(_tag_group_play);
	v_tag_interface<s_play_definition>* play_tag = dynamic_cast<decltype(play_tag)>(play_interface->get_tag_interfaces().front());
	ImGui::Text("Found Play Tag: %s", play_tag ? "true" : "false");

	c_tag_group_interface* zone_interface = cache_file.get_group_interface_by_group_id(_tag_group_zone);
	v_tag_interface<s_zone_definition>* zone_tag = dynamic_cast<decltype(zone_tag)>(zone_interface->get_tag_interfaces().front());
	ImGui::Text("Found Zone Tag: %s", zone_tag ? "true" : "false");

	uint16_t read_index = bitmap_tag_interface.raw_information_normal_block[0].easy_read_index;

	s_zone_definition::s_tag_resource_block_definition& tag_resource = zone_tag->tag_resources_block[read_index];

	if (tag_resource.play_segment_index != -1)
	{

		s_play_definition::s_segment_block_definition& segment_block = play_tag->segments_block[tag_resource.play_segment_index];

		if (segment_block.secondary_page_index != -1)
		{
			s_play_definition::s_raw_page_block_definition& low_res_raw_page = play_tag->raw_pages_block[segment_block.primary_page_index];
			s_play_definition::s_raw_page_block_definition& high_res_raw_page = play_tag->raw_pages_block[segment_block.secondary_page_index];

			ASSERT(high_res_raw_page.compression_codec_index == 0);



			//cache_file->GetTagBlockData()

			SectionCache& resources_section = cache_file.get_resources_section();
			char* data = resources_section.first + high_res_raw_page.block_offset;

			struct DDS_PIXELFORMAT {
				DWORD dwSize;
				DWORD dwFlags;
				DWORD dwFourCC;
				DWORD dwRGBBitCount;
				DWORD dwRBitMask;
				DWORD dwGBitMask;
				DWORD dwBBitMask;
				DWORD dwABitMask;
			};

			typedef struct {
				DWORD           dwSize;
				DWORD           dwFlags;
				DWORD           dwHeight;
				DWORD           dwWidth;
				DWORD           dwPitchOrLinearSize;
				DWORD           dwDepth;
				DWORD           dwMipMapCount;
				DWORD           dwReserved1[11];
				DDS_PIXELFORMAT ddspf;
				DWORD           dwCaps;
				DWORD           dwCaps2;
				DWORD           dwCaps3;
				DWORD           dwCaps4;
				DWORD           dwReserved2;
			} DDS_HEADER;

			struct DDS_FILE_HEADER
			{
				DWORD file_magic;
				DDS_HEADER dds_header;
			};




			static char* dds_texture_buffer = nullptr;
			static char* decompressed_buffer = nullptr;
			if (dds_texture_buffer == nullptr)
			{
				dds_texture_buffer = new char[high_res_raw_page.uncompressed_block_size + sizeof(DDS_FILE_HEADER)]{};
				ASSERT(dds_texture_buffer != nullptr);

				decompressed_buffer = dds_texture_buffer + sizeof(DDS_FILE_HEADER);
				{
					z_stream stream{};
					stream.avail_out = high_res_raw_page.uncompressed_block_size;
					stream.next_out = (Bytef*)decompressed_buffer;
					stream.avail_in = high_res_raw_page.compressed_block_size;
					stream.next_in = (Bytef*)data;
					int inflateInitResult = inflateInit2(&stream, -15);
					ASSERT(inflateInitResult >= Z_OK);
					int inflateResult = inflate(&stream, Z_SYNC_FLUSH);
					ASSERT(inflateResult >= Z_OK);
					int inflateEndResult = inflateEnd(&stream);
					ASSERT(inflateEndResult >= Z_OK);
				}
			}

#define DDSD_CAPS			0x1			// Required in every.dds file.	
#define DDSD_HEIGHT			0x2			// Required in every.dds file.	
#define DDSD_WIDTH			0x4			// Required in every.dds file.	
#define DDSD_PITCH			0x8			// Required when pitch is provided for an uncompressed texture.	
#define DDSD_PIXELFORMAT	0x1000		// Required in every.dds file.	
#define DDSD_MIPMAPCOUNT	0x20000		// Required in a mipmapped texture.	
#define DDSD_LINEARSIZE		0x80000		// Required when pitch is provided for a compressed texture.	
#define DDSD_DEPTH			0x800000	// Required in a depth texture.	

#define DDPF_ALPHAPIXELS	0x1			// Texture contains alpha data; dwRGBAlphaBitMask contains valid data.
#define DDPF_ALPHA			0x2			// Used in some older DDS files for alpha channel only uncompressed data(dwRGBBitCount contains the alpha channel bitcount; dwABitMask contains valid data)
#define DDPF_FOURCC			0x4			// Texture contains compressed RGB data; dwFourCC contains valid data.
#define DDPF_RGB			0x40		// Texture contains uncompressed RGB data; dwRGBBitCountand the RGB masks(dwRBitMask, dwGBitMask, dwBBitMask) contain valid data.
#define DDPF_YUV			0x200		// Used in some older DDS files for YUV uncompressed data(dwRGBBitCount contains the YUV bit count; dwRBitMask contains the Y mask, dwGBitMask contains the U mask, dwBBitMask contains the V mask)
#define DDPF_LUMINANCE		0x20000		// Used in some older DDS files for single channel color uncompressed data(dwRGBBitCount contains the luminance channel bit count; dwRBitMask contains the channel mask).Can be combined with DDPF_ALPHAPIXELS for a two channel DDS file.	

#define DDSCAPS_COMPLEX	0x8			// Optional; must be used on any file that contains more than one surface(a mipmap, a cubic environment map, or mipmapped volume texture).	
#define DDSCAPS_TEXTURE	0x1000		// Required	
#define DDSCAPS_MIPMAP	0x400000	// Optional; should be used for a mipmap.	



			static ID3D11Texture2D* pTexture = NULL;
			if (pTexture == nullptr)
			{

				{
					DDS_FILE_HEADER* file_header = reinterpret_cast<DDS_FILE_HEADER*>(dds_texture_buffer);
					file_header->file_magic = _byteswap_ulong('DDS ');
					file_header->dds_header.dwSize = sizeof(DDS_HEADER);											//DWORD           dwSize;
					file_header->dds_header.dwFlags =																//DWORD           dwFlags;
						DDSD_CAPS |
						DDSD_HEIGHT |
						DDSD_WIDTH |
						DDSD_PIXELFORMAT |
						DDSD_MIPMAPCOUNT |
						DDSD_LINEARSIZE;
					file_header->dds_header.dwHeight = bitmap_tag_interface.bitmap_data_block[0].height;			//DWORD           dwHeight;
					file_header->dds_header.dwWidth = bitmap_tag_interface.bitmap_data_block[0].width;				//DWORD           dwWidth;
					file_header->dds_header.dwPitchOrLinearSize = high_res_raw_page.uncompressed_block_size;		//DWORD           dwPitchOrLinearSize;
					file_header->dds_header.dwDepth = 0;																//DWORD           dwDepth;
					file_header->dds_header.dwMipMapCount = 1;															//DWORD           dwMipMapCount;
					file_header->dds_header.dwReserved1[11];														//DWORD           dwReserved1[11];
					file_header->dds_header.ddspf;																	//DDS_PIXELFORMAT ddspf;
					{
						file_header->dds_header.ddspf.dwSize = sizeof(DDS_PIXELFORMAT);					// DWORD dwSize;
						file_header->dds_header.ddspf.dwFlags = DDPF_FOURCC;							// DWORD dwFlags;
						file_header->dds_header.ddspf.dwFourCC = _byteswap_ulong('DXT5');				// DWORD dwFourCC;
						file_header->dds_header.ddspf.dwRGBBitCount;									// DWORD dwRGBBitCount;
						file_header->dds_header.ddspf.dwRBitMask;										// DWORD dwRBitMask;
						file_header->dds_header.ddspf.dwGBitMask;										// DWORD dwGBitMask;
						file_header->dds_header.ddspf.dwBBitMask;										// DWORD dwBBitMask;
						file_header->dds_header.ddspf.dwABitMask;										// DWORD dwABitMask;
					}
					file_header->dds_header.dwCaps = DDSCAPS_COMPLEX | DDSCAPS_TEXTURE | DDSCAPS_MIPMAP;			//DWORD           dwCaps;
					file_header->dds_header.dwCaps2;																//DWORD           dwCaps2;
					file_header->dds_header.dwCaps3;																//DWORD           dwCaps3;
					file_header->dds_header.dwCaps4;																//DWORD           dwCaps4;
					file_header->dds_header.dwReserved2;															//DWORD           dwReserved2;
				}







				int width = bitmap_tag_interface.bitmap_data_block[0].width;
				int height = bitmap_tag_interface.bitmap_data_block[0].height;

				D3D11_TEXTURE2D_DESC desc{};

				desc.Width = width;
				desc.Height = height;
				desc.MipLevels = 1;
				desc.ArraySize = 1;
				desc.Format = DXGI_FORMAT_BC3_UNORM;
				desc.SampleDesc.Count = 1;
				desc.SampleDesc.Quality = 0;
				desc.Usage = D3D11_USAGE_DEFAULT;
				desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
				desc.CPUAccessFlags = 0;
				desc.MiscFlags = 0;

				D3D11_SUBRESOURCE_DATA initData;
				initData.pSysMem = decompressed_buffer;

				initData.SysMemPitch = 16 * (width / 4);
				initData.SysMemSlicePitch = initData.SysMemPitch * (height / 4);

				//initData.SysMemPitch = static_cast<UINT>(width * sizeof(int));
				//initData.SysMemSlicePitch = static_cast<UINT>(width * height * sizeof(int));

				HRESULT createTexture2DResult = c_render::s_pDevice->CreateTexture2D(&desc, &initData, &pTexture);
				ASSERT(SUCCEEDED(createTexture2DResult));
				ASSERT(pTexture);
			}

			static ID3D11ShaderResourceView* shader_resource_view = nullptr;
			if (shader_resource_view == nullptr)
			{
				HRESULT createShaderResourceViewResult = c_render::s_pDevice->CreateShaderResourceView(pTexture, NULL, &shader_resource_view);
				ASSERT(SUCCEEDED(createShaderResourceViewResult));
			}

			ImGui::Text("Bitmap Data Count: %u", bitmap_tag_interface.bitmap_data_block.count);
			for (s_bitmap_definition::s_bitmap_datum_block_definition& bitmap_datum : bitmap_tag_interface.bitmap_data_block)
			{



				ImGui::Image(shader_resource_view, ImVec2(512, 512));
			}

			cache_file.get_resources_section();
		}
	}
}
