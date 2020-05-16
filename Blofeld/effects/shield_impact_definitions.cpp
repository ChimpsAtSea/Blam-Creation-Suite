#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(shield_impact, SHIELD_IMPACT_TAG, shield_impact_block_block );

TAG_BLOCK_FROM_STRUCT(shield_impact_block, 1, shield_impact_struct_definition_struct_definition );

TAG_STRUCT(shield_impact_struct_definition)
{
	FIELD( _field_explanation, "Shield Controls" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "version!" ),
	FIELD( _field_custom, "Shield Intensity" ),
	FIELD( _field_explanation, "Shield Intensity" ),
	FIELD( _field_real, "Recent Damage Intensity" ),
	FIELD( _field_real, "Current Damage Intensity" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Shield Edge" ),
	FIELD( _field_explanation, "Shield Edge" ),
	FIELD( _field_real, "Depth Fade Range:world units" ),
	FIELD( _field_real, "Outer Fade Radius:[0-1]" ),
	FIELD( _field_real, "Center Radius:[0-1]" ),
	FIELD( _field_real, "Inner Fade Radius:[0-1]" ),
	FIELD( _field_struct, "Edge Glow Color", &shield_color_function_struct_struct_definition ),
	FIELD( _field_struct, "Edge Glow Intensity", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Plasma" ),
	FIELD( _field_explanation, "Plasma" ),
	FIELD( _field_real, "Plasma Depth Fade Range:world units" ),
	FIELD( _field_tag_reference, "Plasma Noise Texture 0" ),
	FIELD( _field_tag_reference, "Plasma Noise Texture 1" ),
	FIELD( _field_real, "Tiling Scale" ),
	FIELD( _field_real, "Scroll Speed" ),
	FIELD( _field_real, "Edge Sharpness" ),
	FIELD( _field_real, "Center Sharpness" ),
	FIELD( _field_real, "Plasma Outer Fade Radius:[0-1]" ),
	FIELD( _field_real, "Plasma Center Radius:[0-1]" ),
	FIELD( _field_real, "Plasma Inner Fade Radius:[0-1]" ),
	FIELD( _field_struct, "Plasma Center Color", &shield_color_function_struct_struct_definition ),
	FIELD( _field_struct, "Plasma Center Intensity", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Plasma Edge Color", &shield_color_function_struct_struct_definition ),
	FIELD( _field_struct, "Plasma Edge Intensity", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Extrusion Oscillation" ),
	FIELD( _field_explanation, "Extrusion Oscillation" ),
	FIELD( _field_tag_reference, "Oscillation Texture 0" ),
	FIELD( _field_tag_reference, "Oscillation Texture 1" ),
	FIELD( _field_real, "Oscillation Tiling Scale" ),
	FIELD( _field_real, "Oscillation Scroll Speed" ),
	FIELD( _field_struct, "Extrusion Amount", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Oscillation Amplitude", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Hit Response" ),
	FIELD( _field_explanation, "Hit Response" ),
	FIELD( _field_real, "Hit Time:seconds" ),
	FIELD( _field_struct, "Hit Color", &shield_color_function_struct_struct_definition ),
	FIELD( _field_struct, "Hit Intensity", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Hit Radius", &shield_scalar_function_struct_struct_definition ),
	FIELD( _field_tag_reference, "hit blob texture (adds significant cost)" ),
	FIELD( _field_custom ),
	FIELD( _field_real_quaternion, "edge_scales!" ),
	FIELD( _field_real_quaternion, "edge_offsets!" ),
	FIELD( _field_real_quaternion, "plasma_scales!" ),
	FIELD( _field_real_quaternion, "depth_fade_params!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shield_color_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shield_scalar_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

