#include "graphicslib-private-pch.h"

const char* graphics_data_format_to_string(e_graphics_data_format graphics_data_format)
{
#define GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format) if(graphics_data_format == _graphics_data_format) return #_graphics_data_format + 1;
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_unspecified);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r8_unorm);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r8g8_unorm);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r8g8b8a8_unorm);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r32g32_float);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r32g32b32_float);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_r32g32b32a32_float);
    GRAPHICS_DATA_FORMAT_TO_STRING(_graphics_data_format_depth_float32);
#undef GRAPHICS_DATA_FORMAT_TO_STRING
    return "unknown";
}
