#pragma once

struct nicename("Multiplayer Variant Settings Interface Definition") group('goof') s_multiplayer_variant_settings_interface_definition_definition
{
	struct nicename("Game Engine Settings") s_game_engine_setting_block_definition;

	signed int __unknown; 
	s_tag_block_definition<s_game_engine_setting_block_definition> nicename("Game Engine Settings") game_engine_settings_block; 

	struct nicename("game_engine_setting") s_game_engine_setting_block_definition
	{
		struct nicename("Options") s_option_block_definition;

		string_id nicename("Name") name; 
		signed int nicename("Setting Category") setting_category; 
		s_tag_block_definition<s_option_block_definition> nicename("Options") options_block; 

		struct nicename("option") s_option_block_definition
		{
			TagReference nicename("Explicit Submenu") explicit_submenu_reference; 
			TagReference nicename("Template-Based Submenu") template_based_submenu_reference; 
			signed int nicename("Submenu Setting Category") submenu_setting_category; 
			string_id nicename("Submenu Name") submenu_name; 
			string_id nicename("Submenu Description") submenu_description; 
			TagReference nicename("Value Pairs") value_pairs_reference; 
		};
	};
};
