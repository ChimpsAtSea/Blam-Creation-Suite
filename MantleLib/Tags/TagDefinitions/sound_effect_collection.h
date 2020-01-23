#pragma once

struct nicename("Sound Effect Collection") group('sfx+') s_sound_effect_collection_definition
{
	struct nicename("Sound Effects") s_sound_effect_block_definition;

	s_tag_block_definition<s_sound_effect_block_definition> nicename("Sound Effects") sound_effects_block; 

	struct nicename("sound_effect") s_sound_effect_block_definition
	{
		struct s_unknown_1_block_definition;
		struct nicename("Components") s_component_block_definition;

		string_id nicename("Name") name; 
		int32_t __unknown; 
		TagReference nicename("Radio Settings") radio_settings_reference; 
		s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 
		s_tag_block_definition<s_component_block_definition> nicename("Components") components_block; 

		struct s_unknown_1_block_definition
		{
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
		};

		struct nicename("component") s_component_block_definition
		{
			TagReference nicename("Sound") sound_reference; 
			Undefined32 __gain; 
			int32_t nicename("Flags") flags; 
		};
	};
};
