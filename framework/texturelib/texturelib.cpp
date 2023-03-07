#include "texturelib-private-pch.h"

BCS_RESULT dxgi_format_to_bits_per_pixel(DXGI_FORMAT dxgi_format, unsigned int& bits_per_pixel)
{
	bits_per_pixel = DirectX::BitsPerPixel(dxgi_format);
	return BCS_S_OK;
}

BCS_RESULT dxgi_format_is_compressed(DXGI_FORMAT dxgi_format, bool& is_compressed)
{
	is_compressed = DirectX::IsCompressed(dxgi_format);
	return BCS_S_OK;
}

BCS_RESULT dxgi_format_is_srgb(DXGI_FORMAT dxgi_format, bool& is_srgb)
{
	is_srgb = DirectX::IsSRGB(dxgi_format);
	return BCS_S_OK;
}

BCS_RESULT graphics_data_format_to_bits_per_pixel(e_graphics_data_format graphics_data_format, unsigned int& bits_per_pixel)
{
	BCS_RESULT rs = BCS_S_OK;

	DXGI_FORMAT dxgi_format;
	if (BCS_FAILED(rs = graphics_data_format_to_dxgi_format(graphics_data_format, dxgi_format)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = dxgi_format_to_bits_per_pixel(dxgi_format, bits_per_pixel)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT graphics_data_format_is_compressed(e_graphics_data_format graphics_data_format, bool& is_compressed)
{
	BCS_RESULT rs = BCS_S_OK;

	DXGI_FORMAT dxgi_format;
	if (BCS_FAILED(rs = graphics_data_format_to_dxgi_format(graphics_data_format, dxgi_format)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = dxgi_format_is_compressed(dxgi_format, is_compressed)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT graphics_data_format_is_srgb(e_graphics_data_format graphics_data_format, bool& is_srgb)
{
	BCS_RESULT rs = BCS_S_OK;

	DXGI_FORMAT dxgi_format;
	if (BCS_FAILED(rs = graphics_data_format_to_dxgi_format(graphics_data_format, dxgi_format)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = dxgi_format_is_srgb(dxgi_format, is_srgb)))
	{
		return rs;
	}

	return rs;
}
