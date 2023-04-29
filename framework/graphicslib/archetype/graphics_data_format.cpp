#include "graphicslib-private-pch.h"

struct s_graphics_data_format_lookup
{
	const char* graphics_data_format_string;
	DXGI_FORMAT dxgi_format;
};

static constexpr s_type_lookup<e_graphics_data_format, s_graphics_data_format_lookup> graphics_data_format_lookup[] =
{
#define graphics_data_format(graphics_data_format, dxgi_format) { graphics_data_format, { #graphics_data_format, dxgi_format } }
	graphics_data_format(_graphics_data_format_unspecified, DXGI_FORMAT_UNKNOWN),
	graphics_data_format(_graphics_data_format_r32g32b32a32_typeless, DXGI_FORMAT_R32G32B32A32_TYPELESS),
	graphics_data_format(_graphics_data_format_r32g32b32a32_float, DXGI_FORMAT_R32G32B32A32_FLOAT),
	graphics_data_format(_graphics_data_format_r32g32b32a32_uint, DXGI_FORMAT_R32G32B32A32_UINT),
	graphics_data_format(_graphics_data_format_r32g32b32a32_sint, DXGI_FORMAT_R32G32B32A32_SINT),
	graphics_data_format(_graphics_data_format_r32g32b32_typeless, DXGI_FORMAT_R32G32B32_TYPELESS),
	graphics_data_format(_graphics_data_format_r32g32b32_float, DXGI_FORMAT_R32G32B32_FLOAT),
	graphics_data_format(_graphics_data_format_r32g32b32_uint, DXGI_FORMAT_R32G32B32_UINT),
	graphics_data_format(_graphics_data_format_r32g32b32_sint, DXGI_FORMAT_R32G32B32_SINT),
	graphics_data_format(_graphics_data_format_r16g16b16a16_typeless, DXGI_FORMAT_R16G16B16A16_TYPELESS),
	graphics_data_format(_graphics_data_format_r16g16b16a16_float, DXGI_FORMAT_R16G16B16A16_FLOAT),
	graphics_data_format(_graphics_data_format_r16g16b16a16_unorm, DXGI_FORMAT_R16G16B16A16_UNORM),
	graphics_data_format(_graphics_data_format_r16g16b16a16_uint, DXGI_FORMAT_R16G16B16A16_UINT),
	graphics_data_format(_graphics_data_format_r16g16b16a16_snorm, DXGI_FORMAT_R16G16B16A16_SNORM),
	graphics_data_format(_graphics_data_format_r16g16b16a16_sint, DXGI_FORMAT_R16G16B16A16_SINT),
	graphics_data_format(_graphics_data_format_r32g32_typeless, DXGI_FORMAT_R32G32_TYPELESS),
	graphics_data_format(_graphics_data_format_r32g32_float, DXGI_FORMAT_R32G32_FLOAT),
	graphics_data_format(_graphics_data_format_r32g32_uint, DXGI_FORMAT_R32G32_UINT),
	graphics_data_format(_graphics_data_format_r32g32_sint, DXGI_FORMAT_R32G32_SINT),
	graphics_data_format(_graphics_data_format_r32g8x24_typeless, DXGI_FORMAT_R32G8X24_TYPELESS),
	graphics_data_format(_graphics_data_format_d32_float_s8x24_uint, DXGI_FORMAT_D32_FLOAT_S8X24_UINT),
	graphics_data_format(_graphics_data_format_r32_float_x8x24_typeless, DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS),
	graphics_data_format(_graphics_data_format_x32_typeless_g8x24_uint, DXGI_FORMAT_X32_TYPELESS_G8X24_UINT),
	graphics_data_format(_graphics_data_format_r10g10b10a2_typeless, DXGI_FORMAT_R10G10B10A2_TYPELESS),
	graphics_data_format(_graphics_data_format_r10g10b10a2_unorm, DXGI_FORMAT_R10G10B10A2_UNORM),
	graphics_data_format(_graphics_data_format_r10g10b10a2_uint, DXGI_FORMAT_R10G10B10A2_UINT),
	graphics_data_format(_graphics_data_format_r11g11b10_float, DXGI_FORMAT_R11G11B10_FLOAT),
	graphics_data_format(_graphics_data_format_r8g8b8a8_typeless, DXGI_FORMAT_R8G8B8A8_TYPELESS),
	graphics_data_format(_graphics_data_format_r8g8b8a8_unorm, DXGI_FORMAT_R8G8B8A8_UNORM),
	graphics_data_format(_graphics_data_format_r8g8b8a8_unorm_srgb, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_r8g8b8a8_uint, DXGI_FORMAT_R8G8B8A8_UINT),
	graphics_data_format(_graphics_data_format_r8g8b8a8_snorm, DXGI_FORMAT_R8G8B8A8_SNORM),
	graphics_data_format(_graphics_data_format_r8g8b8a8_sint, DXGI_FORMAT_R8G8B8A8_SINT),
	graphics_data_format(_graphics_data_format_r16g16_typeless, DXGI_FORMAT_R16G16_TYPELESS),
	graphics_data_format(_graphics_data_format_r16g16_float, DXGI_FORMAT_R16G16_FLOAT),
	graphics_data_format(_graphics_data_format_r16g16_unorm, DXGI_FORMAT_R16G16_UNORM),
	graphics_data_format(_graphics_data_format_r16g16_uint, DXGI_FORMAT_R16G16_UINT),
	graphics_data_format(_graphics_data_format_r16g16_snorm, DXGI_FORMAT_R16G16_SNORM),
	graphics_data_format(_graphics_data_format_r16g16_sint, DXGI_FORMAT_R16G16_SINT),
	graphics_data_format(_graphics_data_format_r32_typeless, DXGI_FORMAT_R32_TYPELESS),
	graphics_data_format(_graphics_data_format_d32_float, DXGI_FORMAT_D32_FLOAT),
	graphics_data_format(_graphics_data_format_r32_float, DXGI_FORMAT_R32_FLOAT),
	graphics_data_format(_graphics_data_format_r32_uint, DXGI_FORMAT_R32_UINT),
	graphics_data_format(_graphics_data_format_r32_sint, DXGI_FORMAT_R32_SINT),
	graphics_data_format(_graphics_data_format_r24g8_typeless, DXGI_FORMAT_R24G8_TYPELESS),
	graphics_data_format(_graphics_data_format_d24_unorm_s8_uint, DXGI_FORMAT_D24_UNORM_S8_UINT),
	graphics_data_format(_graphics_data_format_r24_unorm_x8_typeless, DXGI_FORMAT_R24_UNORM_X8_TYPELESS),
	graphics_data_format(_graphics_data_format_x24_typeless_g8_uint, DXGI_FORMAT_X24_TYPELESS_G8_UINT),
	graphics_data_format(_graphics_data_format_r8g8_typeless, DXGI_FORMAT_R8G8_TYPELESS),
	graphics_data_format(_graphics_data_format_r8g8_unorm, DXGI_FORMAT_R8G8_UNORM),
	graphics_data_format(_graphics_data_format_r8g8_uint, DXGI_FORMAT_R8G8_UINT),
	graphics_data_format(_graphics_data_format_r8g8_snorm, DXGI_FORMAT_R8G8_SNORM),
	graphics_data_format(_graphics_data_format_r8g8_sint, DXGI_FORMAT_R8G8_SINT),
	graphics_data_format(_graphics_data_format_r16_typeless, DXGI_FORMAT_R16_TYPELESS),
	graphics_data_format(_graphics_data_format_r16_float, DXGI_FORMAT_R16_FLOAT),
	graphics_data_format(_graphics_data_format_d16_unorm, DXGI_FORMAT_D16_UNORM),
	graphics_data_format(_graphics_data_format_r16_unorm, DXGI_FORMAT_R16_UNORM),
	graphics_data_format(_graphics_data_format_r16_uint, DXGI_FORMAT_R16_UINT),
	graphics_data_format(_graphics_data_format_r16_snorm, DXGI_FORMAT_R16_SNORM),
	graphics_data_format(_graphics_data_format_r16_sint, DXGI_FORMAT_R16_SINT),
	graphics_data_format(_graphics_data_format_r8_typeless, DXGI_FORMAT_R8_TYPELESS),
	graphics_data_format(_graphics_data_format_r8_unorm, DXGI_FORMAT_R8_UNORM),
	graphics_data_format(_graphics_data_format_r8_uint, DXGI_FORMAT_R8_UINT),
	graphics_data_format(_graphics_data_format_r8_snorm, DXGI_FORMAT_R8_SNORM),
	graphics_data_format(_graphics_data_format_r8_sint, DXGI_FORMAT_R8_SINT),
	graphics_data_format(_graphics_data_format_a8_unorm, DXGI_FORMAT_A8_UNORM),
	graphics_data_format(_graphics_data_format_r1_unorm, DXGI_FORMAT_R1_UNORM),
	graphics_data_format(_graphics_data_format_r9g9b9e5_sharedexp, DXGI_FORMAT_R9G9B9E5_SHAREDEXP),
	graphics_data_format(_graphics_data_format_r8g8_b8g8_unorm, DXGI_FORMAT_R8G8_B8G8_UNORM),
	graphics_data_format(_graphics_data_format_g8r8_g8b8_unorm, DXGI_FORMAT_G8R8_G8B8_UNORM),
	graphics_data_format(_graphics_data_format_bc1_typeless, DXGI_FORMAT_BC1_TYPELESS),
	graphics_data_format(_graphics_data_format_bc1_unorm, DXGI_FORMAT_BC1_UNORM),
	graphics_data_format(_graphics_data_format_bc1_unorm_srgb, DXGI_FORMAT_BC1_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_bc2_typeless, DXGI_FORMAT_BC2_TYPELESS),
	graphics_data_format(_graphics_data_format_bc2_unorm, DXGI_FORMAT_BC2_UNORM),
	graphics_data_format(_graphics_data_format_bc2_unorm_srgb, DXGI_FORMAT_BC2_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_bc3_typeless, DXGI_FORMAT_BC3_TYPELESS),
	graphics_data_format(_graphics_data_format_bc3_unorm, DXGI_FORMAT_BC3_UNORM),
	graphics_data_format(_graphics_data_format_bc3_unorm_srgb, DXGI_FORMAT_BC3_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_bc4_typeless, DXGI_FORMAT_BC4_TYPELESS),
	graphics_data_format(_graphics_data_format_bc4_unorm, DXGI_FORMAT_BC4_UNORM),
	graphics_data_format(_graphics_data_format_bc4_snorm, DXGI_FORMAT_BC4_SNORM),
	graphics_data_format(_graphics_data_format_bc5_typeless, DXGI_FORMAT_BC5_TYPELESS),
	graphics_data_format(_graphics_data_format_bc5_unorm, DXGI_FORMAT_BC5_UNORM),
	graphics_data_format(_graphics_data_format_bc5_snorm, DXGI_FORMAT_BC5_SNORM),
	graphics_data_format(_graphics_data_format_b5g6r5_unorm, DXGI_FORMAT_B5G6R5_UNORM),
	graphics_data_format(_graphics_data_format_b5g5r5a1_unorm, DXGI_FORMAT_B5G5R5A1_UNORM),
	graphics_data_format(_graphics_data_format_b8g8r8a8_unorm, DXGI_FORMAT_B8G8R8A8_UNORM),
	graphics_data_format(_graphics_data_format_b8g8r8x8_unorm, DXGI_FORMAT_B8G8R8X8_UNORM),
	graphics_data_format(_graphics_data_format_r10g10b10_xr_bias_a2_unorm, DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM),
	graphics_data_format(_graphics_data_format_b8g8r8a8_typeless, DXGI_FORMAT_B8G8R8A8_TYPELESS),
	graphics_data_format(_graphics_data_format_b8g8r8a8_unorm_srgb, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_b8g8r8x8_typeless, DXGI_FORMAT_B8G8R8X8_TYPELESS),
	graphics_data_format(_graphics_data_format_b8g8r8x8_unorm_srgb, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_bc6h_typeless, DXGI_FORMAT_BC6H_TYPELESS),
	graphics_data_format(_graphics_data_format_bc6h_uf16, DXGI_FORMAT_BC6H_UF16),
	graphics_data_format(_graphics_data_format_bc6h_sf16, DXGI_FORMAT_BC6H_SF16),
	graphics_data_format(_graphics_data_format_bc7_typeless, DXGI_FORMAT_BC7_TYPELESS),
	graphics_data_format(_graphics_data_format_bc7_unorm, DXGI_FORMAT_BC7_UNORM),
	graphics_data_format(_graphics_data_format_bc7_unorm_srgb, DXGI_FORMAT_BC7_UNORM_SRGB),
	graphics_data_format(_graphics_data_format_ayuv, DXGI_FORMAT_AYUV),
	graphics_data_format(_graphics_data_format_y410, DXGI_FORMAT_Y410),
	graphics_data_format(_graphics_data_format_y416, DXGI_FORMAT_Y416),
	graphics_data_format(_graphics_data_format_nv12, DXGI_FORMAT_NV12),
	graphics_data_format(_graphics_data_format_p010, DXGI_FORMAT_P010),
	graphics_data_format(_graphics_data_format_p016, DXGI_FORMAT_P016),
	graphics_data_format(_graphics_data_format_420_opaque, DXGI_FORMAT_420_OPAQUE),
	graphics_data_format(_graphics_data_format_yuy2, DXGI_FORMAT_YUY2),
	graphics_data_format(_graphics_data_format_y210, DXGI_FORMAT_Y210),
	graphics_data_format(_graphics_data_format_y216, DXGI_FORMAT_Y216),
	graphics_data_format(_graphics_data_format_nv11, DXGI_FORMAT_NV11),
	graphics_data_format(_graphics_data_format_ai44, DXGI_FORMAT_AI44),
	graphics_data_format(_graphics_data_format_ia44, DXGI_FORMAT_IA44),
	graphics_data_format(_graphics_data_format_p8, DXGI_FORMAT_P8),
	graphics_data_format(_graphics_data_format_a8p8, DXGI_FORMAT_A8P8),
	graphics_data_format(_graphics_data_format_b4g4r4a4_unorm, DXGI_FORMAT_B4G4R4A4_UNORM),
	graphics_data_format(_graphics_data_format_p208, DXGI_FORMAT_P208),
	graphics_data_format(_graphics_data_format_v208, DXGI_FORMAT_V208),
	graphics_data_format(_graphics_data_format_v408, DXGI_FORMAT_V408),

	graphics_data_format(_graphics_data_format_bcs_prt_coefficient_order_0, DXGI_FORMAT_UNKNOWN),
	graphics_data_format(_graphics_data_format_bcs_prt_coefficient_order_1, DXGI_FORMAT_UNKNOWN),
	graphics_data_format(_graphics_data_format_bcs_prt_coefficient_order_2, DXGI_FORMAT_UNKNOWN),
	graphics_data_format(_graphics_data_format_bcs_prt_coefficient_order_3, DXGI_FORMAT_UNKNOWN),
#undef graphics_data_format
};
static_assert(_countof(graphics_data_format_lookup) == k_num_graphics_data_formats);
static_assert(is_enum_lookup_valid(graphics_data_format_lookup));

const char* graphics_data_format_to_string(e_graphics_data_format graphics_data_format)
{
	const char* graphics_data_format_string = graphics_data_format_lookup[graphics_data_format].value.graphics_data_format_string;
	return graphics_data_format_string;
}

uint32_t graphics_data_format_bits(e_graphics_data_format graphics_data_format)
{
	return 0;
}

BCS_RESULT graphics_data_format_to_dxgi_format(e_graphics_data_format graphics_data_format, DXGI_FORMAT& dxgi_format)
{
	dxgi_format = graphics_data_format_lookup[graphics_data_format].value.dxgi_format;
	return BCS_S_OK;
}

BCS_RESULT dxgi_format_to_graphics_data_format(DXGI_FORMAT dxgi_format, e_graphics_data_format& graphics_data_format)
{
	for (auto& _graphics_data_format : graphics_data_format_lookup)
	{
		if (_graphics_data_format.value.dxgi_format == dxgi_format)
		{
			graphics_data_format = _graphics_data_format._enum;
			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}

template<e_graphics_data_format input_format, e_graphics_data_format output_format>
BCS_RESULT __vectorcall graphics_data_format_convert_impl(const void* input_data, void* output_data, uint3 dimensions)
{
	return BCS_E_NOT_IMPLEMENTED;
}

// User Defined Conversion Overrides


template<> BCS_RESULT __vectorcall graphics_data_format_convert_impl<_graphics_data_format_r32g32b32_float, _graphics_data_format_r32g32b32_float>(const void* input_data, void* output_data, uint3 dimensions)
{
	return BCS_S_OK;
}

template<e_graphics_data_format input_format>
struct t_graphics_data_format_conversion_output_lookup : public s_graphics_data_format_conversion_output_lookup
{
	constexpr t_graphics_data_format_conversion_output_lookup() :
		s_graphics_data_format_conversion_output_lookup(*this)
	{
		unsigned int index = 0;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_unspecified>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32a32_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32a32_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32a32_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32a32_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32b32_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16b16a16_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g32_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32g8x24_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_d32_float_s8x24_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32_float_x8x24_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_x32_typeless_g8x24_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r10g10b10a2_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r10g10b10a2_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r10g10b10a2_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r11g11b10_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8b8a8_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16g16_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_d32_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r32_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r24g8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_d24_unorm_s8_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r24_unorm_x8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_x24_typeless_g8_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_float>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_d16_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r16_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8_uint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8_sint>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_a8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r1_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r9g9b9e5_sharedexp>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r8g8_b8g8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_g8r8_g8b8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc1_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc1_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc1_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc2_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc2_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc2_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc3_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc3_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc3_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc4_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc4_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc4_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc5_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc5_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc5_snorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b5g6r5_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b5g5r5a1_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8a8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8x8_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_r10g10b10_xr_bias_a2_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8a8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8a8_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8x8_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b8g8r8x8_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc6h_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc6h_uf16>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc6h_sf16>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc7_typeless>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc7_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bc7_unorm_srgb>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_ayuv>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_y410>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_y416>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_nv12>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_p010>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_p016>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_420_opaque>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_yuy2>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_y210>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_y216>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_nv11>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_ai44>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_ia44>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_p8>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_a8p8>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_b4g4r4a4_unorm>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_p208>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_v208>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_v408>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bcs_prt_coefficient_order_0>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bcs_prt_coefficient_order_1>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bcs_prt_coefficient_order_2>;
		output[index++] = graphics_data_format_convert_impl<input_format, _graphics_data_format_bcs_prt_coefficient_order_3>;
		ASSERT(index == k_num_graphics_data_formats);
	}
};

s_graphics_data_format_conversion_input_lookup::s_graphics_data_format_conversion_input_lookup() :
	input
{
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_unspecified>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32a32_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32a32_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32a32_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32a32_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32b32_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16b16a16_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g32_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32g8x24_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_d32_float_s8x24_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32_float_x8x24_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_x32_typeless_g8x24_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r10g10b10a2_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r10g10b10a2_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r10g10b10a2_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r11g11b10_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8b8a8_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16g16_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_d32_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r32_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r24g8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_d24_unorm_s8_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r24_unorm_x8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_x24_typeless_g8_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_float>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_d16_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r16_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8_uint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8_sint>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_a8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r1_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r9g9b9e5_sharedexp>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r8g8_b8g8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_g8r8_g8b8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc1_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc1_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc1_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc2_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc2_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc2_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc3_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc3_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc3_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc4_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc4_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc4_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc5_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc5_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc5_snorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b5g6r5_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b5g5r5a1_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8a8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8x8_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_r10g10b10_xr_bias_a2_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8a8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8a8_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8x8_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b8g8r8x8_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc6h_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc6h_uf16>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc6h_sf16>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc7_typeless>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc7_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bc7_unorm_srgb>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_ayuv>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_y410>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_y416>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_nv12>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_p010>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_p016>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_420_opaque>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_yuy2>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_y210>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_y216>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_nv11>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_ai44>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_ia44>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_p8>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_a8p8>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_b4g4r4a4_unorm>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_p208>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_v208>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_v408>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bcs_prt_coefficient_order_0>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bcs_prt_coefficient_order_1>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bcs_prt_coefficient_order_2>(),
	t_graphics_data_format_conversion_output_lookup<_graphics_data_format_bcs_prt_coefficient_order_3>(),
}
{
	
}

s_graphics_data_format_conversion_input_lookup graphics_data_format_conversion_input_lookup;
