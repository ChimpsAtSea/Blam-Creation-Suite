#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(character_palette_block, 64)
	{
		{ _field_tag_reference, "reference^", &character_reference$6 },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_recording_reference_block, 128)
	{
		{ _field_string, "recording name^" },
		{ _field_pad, "INYRGOR", 8 },
		{ _field_terminator }
	};

	TAG_BLOCK(big_battle_creature_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "reference^", &big_battle_creature_reference },
		{ _field_terminator }
	};

	STRINGS(ai_sound_volume_enum)
	{
		"silent#ai will not respond to this sound",
		"quiet",
		"medium",
		"shout",
		"loud#ai can hear this sound at any range"
	};
	STRING_LIST(ai_sound_volume_enum, ai_sound_volume_enum_strings, _countof(ai_sound_volume_enum_strings));

	TAG_REFERENCE(structureBspReferenceNonDependency, SCENARIO_STRUCTURE_BSP_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(structure_bsp_reference_non_resolving, SCENARIO_STRUCTURE_BSP_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_resolved_manually);

} // namespace blofeld

