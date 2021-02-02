#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(main_menu_voiceover, MAIN_MENU_VOICEOVER_TAG, main_menu_voiceover_block_block );

	V5_TAG_BLOCK(main_menu_voiceover_lines_block, k_MaxVoiceoverLines)
	{
		{ _field_legacy, _field_tag_reference, "sound^", &sound_reference$2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(main_menu_voiceover_block, 1, main_menu_voiceover_struct_definition_struct_definition );

	V5_TAG_STRUCT(main_menu_voiceover_struct_definition)
	{
		{ _field_legacy, _field_block, "lines", &main_menu_voiceover_lines_block_block },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

