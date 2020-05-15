#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(main_menu_voiceover_lines, k_MaxVoiceoverLines)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(main_menu_voiceover, MAIN_MENU_VOICEOVER_TAG)
{
	FIELD( _field_block, "lines", &main_menu_voiceover_lines_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

