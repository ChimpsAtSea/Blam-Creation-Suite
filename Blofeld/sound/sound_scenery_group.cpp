#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(sound_scenery_struct_definition)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_long_integer, "YJNXHAWAO1!" ),
	FIELD( _field_long_integer, "YJNXHAWAO2!" ),
	FIELD( _field_long_integer, "YJNXHAWAO3!" ),
	FIELD( _field_long_integer, "YJNXHAWAO4!" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(sound_scenery_block, SOUND_SCENERY_TAG, object, OBJECT_TAG)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_long_integer, "YJNXHAWAO1!" ),
	FIELD( _field_long_integer, "YJNXHAWAO2!" ),
	FIELD( _field_long_integer, "YJNXHAWAO3!" ),
	FIELD( _field_long_integer, "YJNXHAWAO4!" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

} // namespace blofeld

