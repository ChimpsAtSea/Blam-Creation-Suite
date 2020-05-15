#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(lens_flare_reflection, k_maximum_reflections_per_lens_flare)
{
	{ _field_custom },
	{ _field_string_id, "name^" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "bitmap index" },
	{ _field_tag_reference, "bitmap override" },
	{ _field_real, "rotation offset:degrees" },
	{ _field_real, "axis offset:percent#percent offset in screen space along corona axis - 0.0 is on the corona, 1.0 is primary side edge of the screen, -1.0 is opposite side" },
	{ _field_real_bounds, "offset bounds#the axis offset times corona offset is clamped between these values" },
	{ _field_struct, "radius curve#interpolated by external input" },
	{ _field_struct, "scale curve X#interpolated by external input" },
	{ _field_struct, "scale curve Y#interpolated by external input" },
	{ _field_struct, "brightness curve#interpolated by external input" },
	{ _field_explanation, "TINT COLOR" },
	{ _field_struct, "color curve#interpolated by external input" },
	{ _field_real_fraction, "modulation factor:[0,1]" },
	{ _field_real, "tint power:[0.1, 16]" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(lens_flare_scalar_animation, 1)
{
	{ _field_struct, "function" },
	{ _field_terminator },
};

TAG_BLOCK(lens_flare_color_animation, 1)
{
	{ _field_struct, "color animation" },
	{ _field_terminator },
};

TAG_GROUP(lens_flare, LENS_FLARE_TAG)
{
	{ _field_explanation, "LENS FLARE" },
	{ _field_angle, "falloff angle:degrees" },
	{ _field_angle, "cutoff angle:degrees" },
	{ _field_explanation, "OCCLUSION" },
	{ _field_long_integer, "occlusion reflection index#occlusion information will be generated against the size of this reflection" },
	{ _field_real, "occlusion offset distance:world units#distance along offset direction used to test occlusion" },
	{ _field_enum, "occlusion offset direction" },
	{ _field_pad, "PANTS", 2 },
	{ _field_real, "occlusion inner radius scale#percent of the corona to occlude against (ie 0.25, 0.125, etc)" },
	{ _field_real, "near fade begin distance:world units#distance where the lens flare starts to fade in" },
	{ _field_real, "near fade end distance:world units#distance where the lens flare is fully faded in" },
	{ _field_real, "near fade distance:world units#distance at which the lens flare brightness is maximum" },
	{ _field_real, "far fade distance:world units#distance at which the lens flare brightness is minimum; set to zero to disable distance fading" },
	{ _field_tag_reference, "bitmap" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "runtime flags!" },
	{ _field_enum, "rotation function" },
	{ _field_pad, "WWZC", 2 },
	{ _field_angle, "rotation function scale:degrees" },
	{ _field_explanation, "EFFECT PARAMETERS" },
	{ _field_enum, "falloff function" },
	{ _field_pad, "COYUTLR", 2 },
	{ _field_block, "reflections", &lens_flare_reflection_block },
	{ _field_explanation, "ANIMATION" },
	{ _field_word_flags, "animation flags" },
	{ _field_pad, "AQVC", 2 },
	{ _field_block, "time brightness", &lens_flare_scalar_animation_block },
	{ _field_block, "age brightness", &lens_flare_scalar_animation_block },
	{ _field_block, "time color", &lens_flare_color_animation_block },
	{ _field_block, "age color", &lens_flare_color_animation_block },
	{ _field_block, "time rotation", &lens_flare_scalar_animation_block },
	{ _field_block, "age rotation", &lens_flare_scalar_animation_block },
	{ _field_terminator },
};

} // namespace blofeld

