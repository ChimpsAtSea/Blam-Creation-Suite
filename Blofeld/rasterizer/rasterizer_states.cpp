#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(alpha_blend_mode_enum, 25)
	{
		OPTION("opaque"),
		OPTION("additive"),
		OPTION("multiply"),
		OPTION("alpha_blend"),
		OPTION("double_multiply"),
		OPTION("pre_multiplied_alpha"),
		OPTION("maximum"),
		OPTION("multiply_add"),
		OPTION("add_src_times_dstalpha"),
		OPTION("add_src_times_srcalpha"),
		OPTION("inv_alpha_blend"),
		OPTION("motion_blur_static"),
		OPTION("motion_blur_inhibit"),
		OPTION("apply_shadow_into_shadow_mask"),
		OPTION("alpha_blend_constant"),
		OPTION("overdraw_apply"),
		OPTION("wet_screen_effect"),
		OPTION("minimum"),
		OPTION("revsubtract"),
		OPTION("forge_lightmap"),
		OPTION("forge_lightmap_inv"),
		OPTION("replace_all_channels"),
		OPTION("alpha_blend_max"),
		OPTION("opaque_alpha_blend"),
		OPTION("alpha_blend_additive_transparent"),
	};

} // namespace blofeld

