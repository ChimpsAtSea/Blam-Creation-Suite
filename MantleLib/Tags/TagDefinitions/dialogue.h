#pragma once

struct nicename("Dialogue") group('udlg') s_dialogue_definition
{
	struct nicename("Vocalizations") s_vocalization_block_definition;

	TagReference nicename("Global Dialogue Info") global_dialogue_info_reference; 
	signed int nicename("Flags") flags; 
	s_tag_block_definition<s_vocalization_block_definition> nicename("Vocalizations") vocalizations_block; 
	string_id nicename("Mission Dialogue Designator") mission_dialogue_designator; 

	struct nicename("vocalization") s_vocalization_block_definition
	{
		struct nicename("Sound") s_sound_block_definition;

		string_id nicename("Vocalization") vocalization; 
		s_tag_block_definition<s_sound_block_definition> nicename("Sound") sound_block; 

		struct nicename("sound") s_sound_block_definition
		{
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			TagReference nicename("Sound") sound_reference; 
		};
	};
};
