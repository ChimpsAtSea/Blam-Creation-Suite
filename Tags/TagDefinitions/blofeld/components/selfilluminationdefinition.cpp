#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(self_illumination, SELF_ILLUMINATION_TAG, self_illumination_block_block );

	TAG_BLOCK(self_illumination_state, SelfIlluminationDefinition::MAX_STATES)
	{
		{ _field_explanation, "Self-Illumination State" },
		{ _field_string_id, "Name^" },
		{ _field_long_flags, "Flags", &self_illumination_flags },
		{ _field_real, "Length #Length of illumination animation in seconds." },
		{ _field_string_id, "Next State #Used to automatically transition to another state when finished." },
		{ _field_struct, "Intensity #Animates intensity over time. 0 - Min Intensity.  1 - Max Intensity", &scalar_function_named_struct_struct_definition },
		{ _field_struct, "Color #Animates color over time.  0 - White.  1 - Full Color", &scalar_function_named_struct_struct_definition },
		{ _field_struct, "Activation #Animates On/Off state over time. 0 - Off. 1 - On", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(self_illumination_block, 1, self_illumination_struct_definition_struct_definition );

	TAG_STRUCT(self_illumination_struct_definition)
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

