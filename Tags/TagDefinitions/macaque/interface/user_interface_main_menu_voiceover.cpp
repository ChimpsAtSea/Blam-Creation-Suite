#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		main_menu_voiceover_group,
		MAIN_MENU_VOICEOVER_TAG,
		nullptr,
		INVALID_TAG,
		main_menu_voiceover_block );

	TAG_BLOCK_FROM_STRUCT(
		main_menu_voiceover_block,
		"main_menu_voiceover_block",
		1,
		main_menu_voiceover_struct_definition);

	#define MAIN_MENU_VOICEOVER_LINES_BLOCK_ID { 0xA2BD65AB, 0x8CF84DDF, 0x90B4297C, 0x4CE53C1B }
	TAG_BLOCK(
		main_menu_voiceover_lines_block,
		"main_menu_voiceover_lines_block",
		k_MaxVoiceoverLines,
		"MainMenuVoiceoverLine",
		MAIN_MENU_VOICEOVER_LINES_BLOCK_ID)
	{
		{ _field_tag_reference, "sound^", &sound_reference$2 },
		{ _field_terminator }
	};

	#define MAIN_MENU_VOICEOVER_STRUCT_DEFINITION_ID { 0xCA80030F, 0x173E410E, 0x8E0F3585, 0x39D36E05 }
	TAG_STRUCT(
		main_menu_voiceover_struct_definition,
		"main_menu_voiceover_struct_definition",
		"MainMenuVoiceover",
		MAIN_MENU_VOICEOVER_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "lines", &main_menu_voiceover_lines_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

