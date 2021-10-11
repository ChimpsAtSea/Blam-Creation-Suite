#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		self_illumination_group,
		SELF_ILLUMINATION_TAG,
		nullptr,
		INVALID_TAG,
		self_illumination_block );

	TAG_BLOCK_FROM_STRUCT(
		self_illumination_block,
		"self_illumination_block",
		1,
		self_illumination_struct_definition);

	#define SELF_ILLUMINATION_STATE_ID { 0xA95F3671, 0x6ECA4A14, 0x8732394F, 0xC5A9F4FA }
	TAG_BLOCK(
		self_illumination_state_block,
		"self_illumination_state",
		SelfIlluminationDefinition::MAX_STATES,
		"SelfIlluminationState",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SELF_ILLUMINATION_STATE_ID)
	{
		FIELD_EXPLANATION_EX("Self-Illumination State", nullptr, FIELD_FLAG_NONE, "An animated self-illumination controller state."),
		{ _field_string_id, "Name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "Flags", &self_illumination_flags },
		{ _field_real, "Length ", "Length of illumination animation in seconds." },
		{ _field_string_id, "Next State ", "Used to automatically transition to another state when finished." },
		{ _field_struct, "Intensity ", "Animates intensity over time. 0 - Min Intensity.  1 - Max Intensity", &scalar_function_named_struct },
		{ _field_struct, "Color ", "Animates color over time.  0 - White.  1 - Full Color", &scalar_function_named_struct },
		{ _field_struct, "Activation ", "Animates On/Off state over time. 0 - Off. 1 - On", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define SELF_ILLUMINATION_STRUCT_DEFINITION_ID { 0x52AD50EF, 0xED7A4429, 0x89800F3D, 0xF2771A34 }
	TAG_STRUCT(
		self_illumination_struct_definition,
		"self_illumination_struct_definition",
		"SelfIlluminationDefinition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SELF_ILLUMINATION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "States", &self_illumination_state_block },
		{ _field_terminator }
	};

	STRINGS(self_illumination_flags)
	{
		"Looping",
		"Triggered By AI State",
		"Triggered By Anim State",
		"Triggered By Dialog"
	};
	STRING_LIST(self_illumination_flags, self_illumination_flags_strings, _countof(self_illumination_flags_strings));



} // namespace blofeld

