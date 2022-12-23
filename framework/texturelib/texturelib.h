#pragma once

#ifdef __dxgiformat_h__
extern BCS_SHARED BCS_RESULT dxgi_format_to_bits_per_pixel(DXGI_FORMAT dxgi_format, unsigned int& bits_per_pixel);
extern BCS_SHARED BCS_RESULT dxgi_format_is_compressed(DXGI_FORMAT dxgi_format, bool& is_compressed);
extern BCS_SHARED BCS_RESULT dxgi_format_is_srgb(DXGI_FORMAT dxgi_format, bool& is_srgb);
#endif
extern BCS_SHARED BCS_RESULT graphics_data_format_to_bits_per_pixel(e_graphics_data_format graphics_data_format, unsigned int& bits_per_pixel);
extern BCS_SHARED BCS_RESULT graphics_data_format_is_compressed(e_graphics_data_format graphics_data_format, bool& is_compressed);
extern BCS_SHARED BCS_RESULT graphics_data_format_is_srgb(e_graphics_data_format graphics_data_format, bool& is_srgb);