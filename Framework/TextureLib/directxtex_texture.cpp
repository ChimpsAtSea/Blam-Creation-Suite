#include "texturelib-private-pch.h"

c_directxtex_texture::c_directxtex_texture() :
	DEBUG_ONLY(file_path(),)
	scratch_image()
{

}

c_directxtex_texture::c_directxtex_texture(const wchar_t* _file_path) :
	DEBUG_ONLY(file_path(wcsdup(_file_path)), )
	scratch_image()
{
	HRESULT hrs = S_OK;

	DirectX::ScratchImage* wic_scratch_image = new() DirectX::ScratchImage();
	if (FAILED(hrs = DirectX::LoadFromWICFile(
		_file_path,
		DirectX::WIC_FLAGS_DEFAULT_SRGB | DirectX::WIC_FLAGS_ALL_FRAMES,
		nullptr,
		*wic_scratch_image)))
	{
		delete wic_scratch_image;
		throw BCS_E_FAIL;
	}
	scratch_image = wic_scratch_image;
}

c_directxtex_texture::~c_directxtex_texture()
{
	delete scratch_image;
	scratch_image = nullptr;
	DEBUG_ONLY(untracked_free(file_path));
	DEBUG_ONLY(file_path = nullptr);
}


unsigned int c_directxtex_texture::get_num_layers() const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	return scratch_image_metadata.arraySize;
}

unsigned int c_directxtex_texture::get_num_mips() const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	return scratch_image_metadata.mipLevels;
}

unsigned int c_directxtex_texture::get_width(unsigned int mip) const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	return __max(scratch_image_metadata.width >> mip, 1);
}

unsigned int c_directxtex_texture::get_height(unsigned int mip) const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	return __max(scratch_image_metadata.height >> mip, 1);
}

unsigned int c_directxtex_texture::get_depth(unsigned int mip) const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	return __max(scratch_image_metadata.depth >> mip, 1);
}
#include <wincodec.h>
BCS_RESULT c_directxtex_texture::get_layer_data(unsigned int layer, unsigned int mip, const char*& pixel_data, size_t& pixel_data_size)
{
	if (scratch_image == nullptr)
	{
		return BCS_E_FATAL;
	}

	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();

	BCS_VALIDATE_ARGUMENT(layer < scratch_image_metadata.arraySize);
	BCS_VALIDATE_ARGUMENT(mip < scratch_image_metadata.mipLevels);

	const DirectX::Image* image = scratch_image->GetImage(mip, layer, 0);
	if (image == nullptr)
	{
		return BCS_E_FATAL;
	}

	pixel_data = reinterpret_cast<const char*>(image->pixels);
	pixel_data_size = image->slicePitch;

	return BCS_S_OK;
}

BCS_RESULT c_directxtex_texture::resize(unsigned int width, unsigned int height, unsigned int depth)
{
	if (scratch_image == nullptr)
	{
		return BCS_E_FATAL;
	}
	
	const DirectX::Image* scratch_image_images = scratch_image->GetImages();
	size_t scratch_image_image_count = scratch_image->GetImageCount();
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();

	DirectX::TEX_FILTER_FLAGS texture_filter_flags = DirectX::TEX_FILTER_DEFAULT;
	DirectX::ScratchImage* resized_scratch_image = new() DirectX::ScratchImage();

	HRESULT convert_result = DirectX::Resize(
		scratch_image_images,
		scratch_image_image_count,
		scratch_image_metadata,
		width,
		height,
		texture_filter_flags,
		*resized_scratch_image);
	if (FAILED(convert_result))
	{
		delete resized_scratch_image;
		switch (convert_result)
		{
		case HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED):
			return BCS_E_NOT_SUPPORTED;
		default:
			return BCS_E_FAIL;
		}
	}
	else
	{
		delete scratch_image;
		scratch_image = resized_scratch_image;
		return BCS_S_OK;
	}
}

BCS_RESULT c_directxtex_texture::convert_to_graphics_data_format(e_graphics_data_format graphics_data_format)
{
	if (scratch_image == nullptr)
	{
		return BCS_E_FATAL;
	}

	const DirectX::Image* scratch_image_images = scratch_image->GetImages();
	size_t scratch_image_image_count = scratch_image->GetImageCount();
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	DXGI_FORMAT dxgi_format = DXGI_FORMAT_UNKNOWN;

	BCS_RESULT rs;
	if (BCS_FAILED(rs = graphics_data_format_to_dxgi_format(graphics_data_format, dxgi_format)))
	{
		return rs;
	}

	DirectX::TEX_FILTER_FLAGS texture_filter_flags = DirectX::TEX_FILTER_DEFAULT;
	DirectX::TEX_COMPRESS_FLAGS texture_compress_flags = DirectX::TEX_COMPRESS_SRGB;

	bool is_source_compressed = DirectX::IsCompressed(scratch_image_metadata.format);
	bool is_destination_compressed = DirectX::IsCompressed(dxgi_format);

	if (is_source_compressed)
	{
		DirectX::ScratchImage* decompressed_scratch_image = new() DirectX::ScratchImage();
		HRESULT decompress_result = DirectX::Decompress(
			scratch_image_images,
			scratch_image_image_count,
			scratch_image_metadata,
			DXGI_FORMAT_R32G32B32A32_FLOAT,
			*decompressed_scratch_image);
		if (FAILED(decompress_result))
		{
			delete decompressed_scratch_image;
			switch (decompress_result)
			{
			case HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED):
				return BCS_E_NOT_SUPPORTED;
			default:
				return BCS_E_FAIL;
			}
		}
		else
		{
			delete scratch_image;
			scratch_image = decompressed_scratch_image;
			return BCS_S_OK;
		}
	}

	if (is_destination_compressed)
	{
		DirectX::ScratchImage* compressed_scratch_image = new() DirectX::ScratchImage();
		HRESULT compress_result = DirectX::Compress(
			scratch_image_images,
			scratch_image_image_count,
			scratch_image_metadata,
			dxgi_format,
			texture_compress_flags,
			0.0f,
			*compressed_scratch_image);
		if (FAILED(compress_result))
		{
			delete compressed_scratch_image;
			switch (compress_result)
			{
			case HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED):
				return BCS_E_NOT_SUPPORTED;
			default:
				return BCS_E_FAIL;
			}
		}
		else
		{
			delete scratch_image;
			scratch_image = compressed_scratch_image;
			return BCS_S_OK;
		}
	}
	else
	{
		DirectX::ScratchImage* converted_scratch_image = new() DirectX::ScratchImage();
		HRESULT convert_result = DirectX::Convert(
			scratch_image_images,
			scratch_image_image_count,
			scratch_image_metadata,
			dxgi_format,
			texture_filter_flags,
			0.0f,
			*converted_scratch_image);
		if (FAILED(convert_result))
		{
			delete converted_scratch_image;
			switch (convert_result)
			{
			case HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED):
				return BCS_E_NOT_SUPPORTED;
			default:
				return BCS_E_FAIL;
			}
		}
		else
		{
			delete scratch_image;
			scratch_image = converted_scratch_image;
			return BCS_S_OK;
		}
	}
}

BCS_RESULT c_directxtex_texture::generate_mips(unsigned int num_mip_levels_override)
{
	if (scratch_image == nullptr)
	{
		return BCS_E_FATAL;
	}

	const DirectX::Image* scratch_image_images = scratch_image->GetImages();
	size_t scratch_image_image_count = scratch_image->GetImageCount();
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();
	DirectX::TEX_FILTER_FLAGS texture_filter_flags = DirectX::TEX_FILTER_DEFAULT;
	size_t num_mip_levels = static_cast<size_t>(log2(__max(scratch_image_metadata.width, scratch_image_metadata.height))) + 1;
	if (num_mip_levels_override != UINT_MAX)
	{
		num_mip_levels = num_mip_levels_override;
	}
	DirectX::ScratchImage* mip_chain_scratch_image = new() DirectX::ScratchImage();

	HRESULT generate_mip_maps_result = DirectX::GenerateMipMaps(scratch_image_images, scratch_image_image_count, scratch_image_metadata, DirectX::TEX_FILTER_DEFAULT, num_mip_levels, *mip_chain_scratch_image);
	if (FAILED(generate_mip_maps_result))
	{
		delete mip_chain_scratch_image;
		switch (generate_mip_maps_result)
		{
		case HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED):
			return BCS_E_NOT_SUPPORTED;
		default:
			return BCS_E_FAIL;
		}
	}
	else
	{
		delete scratch_image;
		scratch_image = mip_chain_scratch_image;
		return BCS_S_OK;
	}
}

BCS_RESULT c_directxtex_texture::get_graphics_data_format(e_graphics_data_format& graphics_data_format) const
{
	const DirectX::TexMetadata& scratch_image_metadata = scratch_image->GetMetadata();

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = dxgi_format_to_graphics_data_format(scratch_image_metadata.format, graphics_data_format)))
	{
		graphics_data_format = _graphics_data_format_unspecified;
		return rs;
	}

	return rs;
}
