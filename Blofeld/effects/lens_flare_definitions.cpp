#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(lens_flare_reflection_flags_definition, 12)
	{
		OPTION("rotate from center of screen"),
		OPTION("radius scaled by distance"),
		OPTION("radius scaled by occlusion factor"),
		OPTION("ignore external color"),
		OPTION("lock to flare X"),
		OPTION("lock to flare Y"),
		OPTION("proximity to center as function input#The input to the curves below should be multiplied by 1 if at the center of the screen and 0 if at the edge"),
		OPTION("mirror across flare#Also renders this reflection\'s mirror image across the flare center"),
		OPTION("disabled for debugging"),
		OPTION("flip U coordinate"),
		OPTION("flip V coordinate"),
		OPTION("draw in world space instead of screen space"),
	};

	TAG_ENUM(lens_flare_flags_definition, 9)
	{
		OPTION("rotate occlusion testing box with lens flare#otherwise remains aligned with screen. turn on render_debug_lens_flares and look at green box"),
		OPTION("no occlusion test"),
		OPTION("only render in first person"),
		OPTION("only render in third person"),
		OPTION("use simple occlusion box test#ignore fancy occlusion box scaling - useful for very big or very far away lens flares (skybox flares, etc)"),
		OPTION("no reflection opacity feedback#unchecked, each reflection evaluates its opacity from the previous reflection in the list"),
		OPTION("scale by marker"),
		OPTION("don\'t autofade#otherwise fade based on effect time, for effect attachments only"),
		OPTION("don\'t render while zoomed"),
	};

	TAG_ENUM(lens_flare_occlusion_offset_enum_definition, 3)
	{
		OPTION("toward viewer"),
		OPTION("marker forward"),
		OPTION("none"),
	};

	TAG_ENUM(lens_flare_corona_rotation_function_enum_definition, 5)
	{
		OPTION("none"),
		OPTION("rotation A"),
		OPTION("rotation B"),
		OPTION("rotation-translation"),
		OPTION("translation"),
	};

	TAG_ENUM(output_mod_enum, 3)
	{
		OPTION(" "),
		OPTION("Plus"),
		OPTION("Times"),
	};

	TAG_ENUM(lens_flare_animation_flags_definition, 1)
	{
		OPTION("synchronized"),
	};

	TAG_GROUP_FROM_BLOCK(lens_flare, LENS_FLARE_TAG, lens_flare_block_block );

	TAG_BLOCK_FROM_STRUCT(lens_flare_block, 1, lens_flare_struct_definition_struct_definition );

	TAG_BLOCK(lens_flare_reflection_block, k_maximum_reflections_per_lens_flare)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_word_flags, "flags", &lens_flare_reflection_flags_definition ),
		FIELD( _field_short_integer, "bitmap index" ),
		FIELD( _field_tag_reference, "bitmap override" ),
		FIELD( _field_real, "rotation offset:degrees" ),
		FIELD( _field_real, "axis offset:percent#percent offset in screen space along corona axis - 0.0 is on the corona, 1.0 is primary side edge of the screen, -1.0 is opposite side" ),
		FIELD( _field_real_bounds, "offset bounds#the axis offset times corona offset is clamped between these values" ),
		FIELD( _field_struct, "radius curve#interpolated by external input", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "scale curve X#interpolated by external input", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "scale curve Y#interpolated by external input", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "brightness curve#interpolated by external input", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_explanation, "TINT COLOR" ),
		FIELD( _field_struct, "color curve#interpolated by external input", &color_function_named_struct_struct_definition ),
		FIELD( _field_real_fraction, "modulation factor:[0,1]" ),
		FIELD( _field_real, "tint power:[0.1, 16]" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(lens_flare_scalar_animation_block, 1)
	{
		FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(lens_flare_color_animation_block, 1)
	{
		FIELD( _field_struct, "color animation", &lens_flare_color_function_struct_struct_definition ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(lens_flare_struct_definition)
{
		FIELD( _field_explanation, "LENS FLARE" ),
		FIELD( _field_angle, "falloff angle:degrees" ),
		FIELD( _field_angle, "cutoff angle:degrees" ),
		FIELD( _field_explanation, "OCCLUSION" ),
		FIELD( _field_long_integer, "occlusion reflection index#occlusion information will be generated against the size of this reflection" ),
		FIELD( _field_real, "occlusion offset distance:world units#distance along offset direction used to test occlusion" ),
		FIELD( _field_enum, "occlusion offset direction", &lens_flare_occlusion_offset_enum_definition ),
		FIELD( _field_pad, "PANTS", 2 ),
		FIELD( _field_real, "occlusion inner radius scale#percent of the corona to occlude against (ie 0.25, 0.125, etc)" ),
		FIELD( _field_real, "near fade begin distance:world units#distance where the lens flare starts to fade in" ),
		FIELD( _field_real, "near fade end distance:world units#distance where the lens flare is fully faded in" ),
		FIELD( _field_real, "near fade distance:world units#distance at which the lens flare brightness is maximum" ),
		FIELD( _field_real, "far fade distance:world units#distance at which the lens flare brightness is minimum; set to zero to disable distance fading" ),
		FIELD( _field_tag_reference, "bitmap" ),
		FIELD( _field_word_flags, "flags", &lens_flare_flags_definition ),
		FIELD( _field_short_integer, "runtime flags!" ),
		FIELD( _field_enum, "rotation function", &lens_flare_corona_rotation_function_enum_definition ),
		FIELD( _field_pad, "WWZC", 2 ),
		FIELD( _field_angle, "rotation function scale:degrees" ),
		FIELD( _field_explanation, "EFFECT PARAMETERS" ),
		FIELD( _field_enum, "falloff function", &global_reverse_transition_functions_enum ),
		FIELD( _field_pad, "COYUTLR", 2 ),
		FIELD( _field_block, "reflections", &lens_flare_reflection_block_block ),
		FIELD( _field_explanation, "ANIMATION" ),
		FIELD( _field_word_flags, "animation flags", &lens_flare_animation_flags_definition ),
		FIELD( _field_pad, "AQVC", 2 ),
		FIELD( _field_block, "time brightness", &lens_flare_scalar_animation_block_block ),
		FIELD( _field_block, "age brightness", &lens_flare_scalar_animation_block_block ),
		FIELD( _field_block, "time color", &lens_flare_color_animation_block_block ),
		FIELD( _field_block, "age color", &lens_flare_color_animation_block_block ),
		FIELD( _field_block, "time rotation", &lens_flare_scalar_animation_block_block ),
		FIELD( _field_block, "age rotation", &lens_flare_scalar_animation_block_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(lens_flare_color_function_struct)
{
		FIELD( _field_string_id, "Input Variable!" ),
		FIELD( _field_string_id, "Range Variable!" ),
		FIELD( _field_enum, "Output Modifier!", &output_mod_enum ),
		FIELD( _field_pad, "BVCG1", 2 ),
		FIELD( _field_string_id, "Output Modifier Input!" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "lens flare color mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

