#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT_FROM_BLOCK(sound_scenery, SOUND_SCENERY_TAG, object, OBJECT_TAG, sound_scenery_block_block );

TAG_BLOCK_FROM_STRUCT(sound_scenery_block, 1, sound_scenery_struct_definition_struct_definition );

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

} // namespace blofeld

