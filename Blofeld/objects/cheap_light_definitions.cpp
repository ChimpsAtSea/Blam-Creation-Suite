#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(cheap_light, CHEAP_LIGHT_TAG)
{
	FIELD( _field_explanation, "Cheap Lights" ),
	FIELD( _field_char_enum, "function input" ),
	FIELD( _field_pad, "clblah", 3 ),
	FIELD( _field_explanation, "COLOR" ),
	FIELD( _field_struct, "color" ),
	FIELD( _field_struct, "intensity" ),
	FIELD( _field_explanation, "SIZE" ),
	FIELD( _field_struct, "Falloff End{radius}" ),
	FIELD( _field_real, "Falloff Begin Ratio:[0-1]#Ratio of falloff start to falloff end" ),
	FIELD( _field_real, "near fade distance{closeup fading distance}:world units" ),
	FIELD( _field_real, "far fade begin:world units" ),
	FIELD( _field_real, "far fade cutoff:world units" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

