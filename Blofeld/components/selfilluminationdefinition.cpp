#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(self_illumination_state, SelfIlluminationDefinition::MAX_STATES)
{
	{ _field_explanation, "Self-Illumination State" },
	{ _field_string_id, "Name^" },
	{ _field_long_flags, "Flags" },
	{ _field_real, "Length #Length of illumination animation in seconds." },
	{ _field_string_id, "Next State #Used to automatically transition to another state when finished." },
	{ _field_struct, "Intensity #Animates intensity over time. 0 - Min Intensity.  1 - Max Intensity" },
	{ _field_struct, "Color #Animates color over time.  0 - White.  1 - Full Color" },
	{ _field_struct, "Activation #Animates On/Off state over time. 0 - Off. 1 - On" },
	{ _field_terminator },
};

TAG_GROUP(self_illumination, SELF_ILLUMINATION_TAG)
{
	{ _field_block, "States", &self_illumination_state_block },
	{ _field_terminator },
};

} // namespace blofeld

