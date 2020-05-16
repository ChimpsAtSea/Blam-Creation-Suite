#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(atmosphere_fog, ATMOSPHERE_FOG_TAG, atmosphere_definition_block_block )

TAG_BLOCK(atmosphere_definition_block, k_max_atmosphere_settings)
{
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_byte_integer, "Version!" ),
	FIELD( _field_pad, "ABCDEFGH", 1 ),
	FIELD( _field_explanation, "Ambient Fog Parameters" ),
	FIELD( _field_real, "distance bias:world units#negative means into the screen" ),
	FIELD( _field_custom, "Sky Fog" ),
	FIELD( _field_struct, "sky fog", &solo_fog_parameters_struct_definition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ground Fog" ),
	FIELD( _field_struct, "ground fog", &solo_fog_parameters_struct_definition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ceiling Fog BEWARE!" ),
	FIELD( _field_struct, "ceiling fog", &solo_fog_parameters_struct_definition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Fog Light" ),
	FIELD( _field_struct, "fog light", &fog_light_struct_definition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Patchy Fog Per-Cluster Parameters" ),
	FIELD( _field_real, "Sheet density" ),
	FIELD( _field_real_rgb_color, "Color tint" ),
	FIELD( _field_real_rgb_color, "Color tint inner" ),
	FIELD( _field_real, "Intensity" ),
	FIELD( _field_real, "Full intensity height" ),
	FIELD( _field_real, "Half intensity height" ),
	FIELD( _field_real_vector_3d, "Wind direction" ),
	FIELD( _field_real, "Reference plane height" ),
	FIELD( _field_custom, "Volume Fog" ),
	FIELD( _field_struct, "volume fog", &VolumeFogParametersDefinition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Light Shafts" ),
	FIELD( _field_struct, "light shaft", &LightShaftParametersDefinition_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Weather effect" ),
	FIELD( _field_tag_reference, "Weather effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(soloFogFunctionBlock, 1)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(solo_fog_parameters_struct_definition)
{
	FIELD( _field_real, "base height:world units" ),
	FIELD( _field_real, "fog height:world units" ),
	FIELD( _field_real, "fog thickness [0.0 to 1.0]" ),
	FIELD( _field_real, "fog falloff end{max fog distance}" ),
	FIELD( _field_real_rgb_color, "fog color" ),
	FIELD( _field_real, "fog color intensity#scales color up or down to allow for HDR values" ),
	FIELD( _field_block, "Function", &soloFogFunctionBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(fog_light_struct_definition)
{
	FIELD( _field_real, "pitch angle [-90 to 90]:degree" ),
	FIELD( _field_real, "yaw angle [0 to 360]:degree" ),
	FIELD( _field_real, "angular radius [0 to 180]:degree" ),
	FIELD( _field_real_rgb_color, "tint color" ),
	FIELD( _field_real, "tint color intensity" ),
	FIELD( _field_real, "angular falloff steepness" ),
	FIELD( _field_real, "distance falloff steepness" ),
	FIELD( _field_real, "nearby cutoff percentage" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(VolumeFogParametersDefinition)
{
	FIELD( _field_real_rgb_color, "volume fog color" ),
	FIELD( _field_real, "volume fog color intensity" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(LightShaftParametersDefinition)
{
	FIELD( _field_real_rgb_color, "light shaft tint color" ),
	FIELD( _field_real, "light shaft intensity" ),
	FIELD( _field_real, "light shaft decay rate" ),
	FIELD( _field_real, "maximum screen distance" ),
	FIELD( _field_real, "sample density" ),
	FIELD( _field_real, "minimum caster distance" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

