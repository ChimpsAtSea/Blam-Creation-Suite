#pragma once

void get_format_tile_dimensions(_In_ DXGI_FORMAT fmt, _Out_ unsigned long* width, _Out_ unsigned long* height);

//--------------------------------------------------------------------------------------
// Return the BPP for a particular format
//--------------------------------------------------------------------------------------
UINT get_format_bits_per_pixel(_In_ DXGI_FORMAT fmt);

//--------------------------------------------------------------------------------------
// Get surface information for a particular format
//--------------------------------------------------------------------------------------
HRESULT get_surface_info(
	_In_ size_t width,
	_In_ size_t height,
	_In_ DXGI_FORMAT fmt,
	size_t* outNumBytes,
	_Out_opt_ size_t* outRowBytes,
	_Out_opt_ size_t* outNumRows);
