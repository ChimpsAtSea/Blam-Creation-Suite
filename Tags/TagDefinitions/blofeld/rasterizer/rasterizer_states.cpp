#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	STRINGS(alpha_blend_mode_enum)
	{
		"opaque",
		"additive",
		"multiply",
		"alpha_blend",
		"double_multiply",
		"pre_multiplied_alpha",
		"maximum",
		"multiply_add",
		"add_src_times_dstalpha",
		"add_src_times_srcalpha",
		"inv_alpha_blend",
		"motion_blur_static",
		"motion_blur_inhibit",
		"apply_shadow_into_shadow_mask",
		"alpha_blend_constant",
		"overdraw_apply",
		"wet_screen_effect",
		"minimum",
		"revsubtract",
		"forge_lightmap",
		"forge_lightmap_inv",
		"replace_all_channels",
		"alpha_blend_max",
		"opaque_alpha_blend",
		"alpha_blend_additive_transparent"
	};
	STRING_LIST(alpha_blend_mode_enum, alpha_blend_mode_enum_strings, _countof(alpha_blend_mode_enum_strings));



} // namespace blofeld

