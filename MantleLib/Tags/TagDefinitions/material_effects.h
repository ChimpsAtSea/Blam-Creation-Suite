#pragma once

struct nicename("Material Effects") group('foot') s_material_effects_definition
{
	struct nicename("Effects") s_effect_block_definition;

	s_tag_block_definition<s_effect_block_definition> nicename("Effects") effects_block; 

	struct nicename("effect") s_effect_block_definition
	{
		struct nicename("Old Materials") s_old_material_block_definition;
		struct nicename("Sounds") s_sound_block_definition;
		struct nicename("Effects") s_effect2_block_definition;

		s_tag_block_definition<s_old_material_block_definition> nicename("Old Materials") old_materials_block; 
		s_tag_block_definition<s_sound_block_definition> nicename("Sounds") sounds_block; 
		s_tag_block_definition<s_effect2_block_definition> nicename("Effects") effects_block; 

		struct nicename("old_material") s_old_material_block_definition
		{
			TagReference nicename("Effect") effect_reference; 
			TagReference nicename("Sound") sound_reference; 
			string_id nicename("Material Name") material_name; 
			signed short nicename("Global Material Index") global_material_index; 
			signed char nicename("Sweetener Mode") sweetener_mode; 
			signed char __unknown; 
			Unknown32 __unknown2; 
		};

		struct nicename("sound") s_sound_block_definition
		{
			TagReference nicename("Tag") tag_reference; 
			TagReference nicename("Secondary Tag") secondary_tag_reference; 
			string_id nicename("Material Name") material_name; 
			signed short nicename("Global Material Index") global_material_index; 
			signed char nicename("Sweetener Mode") sweetener_mode; 
			signed char __unknown; 
			Unknown32 __unknown2; 
		};

		struct nicename("effect2") s_effect2_block_definition
		{
			TagReference nicename("Tag") tag_reference; 
			TagReference nicename("Secondary Tag") secondary_tag_reference; 
			string_id nicename("Material Name") material_name; 
			signed short nicename("Global Material Index") global_material_index; 
			signed char nicename("Sweetener Mode") sweetener_mode; 
			signed char __unknown; 
			Unknown32 __unknown2; 
		};
	};
};
