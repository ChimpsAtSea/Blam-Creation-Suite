#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(tracking_type_block, 16)
	{
		{ _field_string_id, "tracking type^" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_target_tracking_parameters_block, 1)
	{
		{ _field_block, "tracking types#specify the kinds of targets this tracking system can lock on", &tracking_type_block_block },
		{ _field_real, "acquire time:s" },
		{ _field_real, "grace time:s" },
		{ _field_real, "decay time:s" },
		{ _field_tag_reference, "tracking sound", &global_sound_and_looping_sound_reference },
		{ _field_tag_reference, "locked sound", &global_sound_and_looping_sound_reference },
		{ _field_terminator }
	};

} // namespace blofeld

