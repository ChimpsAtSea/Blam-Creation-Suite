#pragma once

struct nicename("multilingual_unicode_string_list") tag_group('unic') s_multilingual_unicode_string_list_definition_legacy
{
	struct nicename("Variables") s_variables_definition_legacy
	{
		string_id_legacy nicename("Pipe Handler") pipe_handler;
		string_id_legacy nicename("Property Handler") property_handler;
	};

	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	// Variables : Variables are referenced in strings by an 8-character hex index of the below block, prefixed by the "variable/" tag.
	s_tag_block_legacy<s_variables_definition_legacy> nicename("Variables") variables1_block;
	s_data_reference_legacy __unknown3;
	s_uniclist_legacy nicename("Strings") strings;
};

