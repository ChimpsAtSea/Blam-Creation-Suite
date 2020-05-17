#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(cheapLightFunctionInputEnum, 3)
	{
		OPTION("time/age"),
		OPTION("scale A"),
		OPTION("scale B"),
	};

	TAG_GROUP_FROM_BLOCK(cheap_light, CHEAP_LIGHT_TAG, cheap_light_block_block );

	TAG_BLOCK_FROM_STRUCT(cheap_light_block, 1, cheap_light_struct_definition_struct_definition );

TAG_STRUCT(cheap_light_struct_definition)
{
		FIELD( _field_explanation, "Cheap Lights" ),
		FIELD( _field_char_enum, "function input", &cheapLightFunctionInputEnum ),
		FIELD( _field_pad, "clblah", 3 ),
		FIELD( _field_explanation, "COLOR" ),
		FIELD( _field_struct, "color", &light_color_function_struct_struct_definition ),
		FIELD( _field_struct, "intensity", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "SIZE" ),
		FIELD( _field_struct, "Falloff End{radius}", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_real, "Falloff Begin Ratio:[0-1]#Ratio of falloff start to falloff end" ),
		FIELD( _field_real, "near fade distance{closeup fading distance}:world units" ),
		FIELD( _field_real, "far fade begin:world units" ),
		FIELD( _field_real, "far fade cutoff:world units" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

