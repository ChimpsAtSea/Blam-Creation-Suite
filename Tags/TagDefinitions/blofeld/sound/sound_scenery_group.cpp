#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(sound_scenery, SOUND_SCENERY_TAG, object, OBJECT_TAG, sound_scenery_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(sound_scenery_block, 1, sound_scenery_struct_definition_struct_definition );

	V5_TAG_STRUCT(sound_scenery_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "obstruction cutoff frequency:Hz" },
		{ _field_real, "obstruction output gain:dB" },
		{ _field_real, "occlusion cutoff frequency:Hz" },
		{ _field_real, "occlusion output gain:dB" },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_long_integer, "YJNXHAWAO1!" },
		{ _field_long_integer, "YJNXHAWAO2!" },
		{ _field_long_integer, "YJNXHAWAO3!" },
		{ _field_long_integer, "YJNXHAWAO4!" },
		{ _field_useless_pad },

		{ _field_terminator }
	};

} // namespace blofeld

