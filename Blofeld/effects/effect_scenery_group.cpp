#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(effect_scenery_struct_definition)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(effect_scenery_block, EFFECT_SCENERY_TAG, object, OBJECT_TAG)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

