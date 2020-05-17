#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(self_illumination, SELF_ILLUMINATION_TAG, self_illumination_block_block );

	TAG_BLOCK(self_illumination_state, SelfIlluminationDefinition::MAX_STATES)
	{
		FIELD( _field_explanation, "Self-Illumination State" ),
		FIELD( _field_string_id, "Name^" ),
		FIELD( _field_long_flags, "Flags", &self_illumination_flags ),
		FIELD( _field_real, "Length #Length of illumination animation in seconds." ),
		FIELD( _field_string_id, "Next State #Used to automatically transition to another state when finished." ),
		FIELD( _field_struct, "Intensity #Animates intensity over time. 0 - Min Intensity.  1 - Max Intensity", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "Color #Animates color over time.  0 - White.  1 - Full Color", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "Activation #Animates On/Off state over time. 0 - Off. 1 - On", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(self_illumination_block, 1, self_illumination_struct_definition_struct_definition );

	TAG_STRUCT(self_illumination_struct_definition)
	{
		FIELD( _field_block, "States", &self_illumination_state_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(self_illumination_flags, 4)
	{
		OPTION("Looping"),
		OPTION("Triggered By AI State"),
		OPTION("Triggered By Anim State"),
		OPTION("Triggered By Dialog"),
	};

} // namespace blofeld

