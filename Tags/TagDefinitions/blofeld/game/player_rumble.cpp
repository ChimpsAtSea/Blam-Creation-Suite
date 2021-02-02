#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(rumble, RUMBLE_TAG, rumble_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(rumble_block, 1, rumble_struct_definition_struct_definition );

	V5_TAG_STRUCT(rumble_struct_definition)
	{
		{ _field_legacy, _field_struct, "rumble", &rumble_definition_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(rumble_definition_struct)
	{
		{ _field_legacy, _field_explanation, "low frequency rumble", "" },
		{ _field_legacy, _field_struct, "low frequency rumble", &rumble_frequency_definition_struct_struct_definition },
		{ _field_legacy, _field_explanation, "high frequency rumble", "" },
		{ _field_legacy, _field_struct, "high frequency rumble", &rumble_frequency_definition_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(rumble_frequency_definition_struct)
	{
		{ _field_legacy, _field_real, "duration:seconds" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "dirty whore", &mapping_function_struct_definition },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(global_rumble_reference, RUMBLE_TAG);

} // namespace blofeld

