#include "graphicslib-private-pch.h"

BCS_RESULT graphics_data_format_to_dxgi_format(e_graphics_data_format graphics_data_format, DXGI_FORMAT& dxgi_format)
{
#define GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format, _dxgi_format) \
    if (graphics_data_format == _graphics_data_format) { dxgi_format = _dxgi_format; return BCS_S_OK; }

    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_unspecified, DXGI_FORMAT_UNKNOWN);
    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_r8g8b8a8_unorm, DXGI_FORMAT_R8G8B8A8_UNORM);
    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_r32g32_float, DXGI_FORMAT_R32G32_FLOAT);
    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_r32g32b32_float, DXGI_FORMAT_R32G32B32_FLOAT);
    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_r32g32b32a32_float, DXGI_FORMAT_R32G32B32A32_FLOAT);
    GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT(_graphics_data_format_depth_float32, DXGI_FORMAT_D32_FLOAT);
    
    return BCS_E_NOT_SUPPORTED;

#undef GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT
}
