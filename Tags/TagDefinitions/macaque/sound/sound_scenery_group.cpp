#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		sound_scenery_group,
		SOUND_SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		sound_scenery_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_scenery_block,
		"sound_scenery_block",
		1,
		sound_scenery_struct_definition);

	#define SOUND_SCENERY_STRUCT_DEFINITION_ID { 0xD4C4A75B, 0x96954D6A, 0xBB77085F, 0xD4396EF5 }
	TAG_STRUCT(
		sound_scenery_struct_definition,
		"sound_scenery_struct_definition",
		"_sound_scenery_definition",
		SOUND_SCENERY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		{ _field_long_integer, "YJNXHAWAO1!" },
		{ _field_long_integer, "YJNXHAWAO2!" },
		{ _field_long_integer, "YJNXHAWAO3!" },
		{ _field_long_integer, "YJNXHAWAO4!" },
		{ _field_useless_pad },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

