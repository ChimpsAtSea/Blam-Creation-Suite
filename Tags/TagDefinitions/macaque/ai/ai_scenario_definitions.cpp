#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CHARACTER_PALETTE_BLOCK_ID { 0xF0B3F635, 0xE3E84977, 0xA29C814A, 0x90050BA2 }
	TAG_BLOCK(
		character_palette_block,
		"character_palette_block",
		64,
		"character_palette_entry",
		CHARACTER_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "reference^", &character_reference$6 },
		{ _field_terminator }
	};

	#define AI_RECORDING_REFERENCE_BLOCK_ID { 0x5E862427, 0xA53A4CE0, 0xB153EC6F, 0x5E93FE9C }
	TAG_BLOCK(
		ai_recording_reference_block,
		"ai_recording_reference_block",
		128,
		"ai_recording_reference_definition",
		AI_RECORDING_REFERENCE_BLOCK_ID)
	{
		{ _field_string, "recording name^" },
		{ _field_pad, "INYRGOR", 8 },
		{ _field_terminator }
	};

	#define BIG_BATTLE_CREATURE_PALETTE_BLOCK_ID { 0x9E063558, 0x110D4709, 0x8B0E106E, 0x2EBF24EE }
	TAG_BLOCK(
		big_battle_creature_palette_block,
		"big_battle_creature_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_big_battle_creature_palette_entry",
		BIG_BATTLE_CREATURE_PALETTE_BLOCK_ID)
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

} // namespace macaque

} // namespace blofeld

