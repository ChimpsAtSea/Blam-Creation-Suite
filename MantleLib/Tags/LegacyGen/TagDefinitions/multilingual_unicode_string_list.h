#pragma once

struct nicename("multilingual_unicode_string_list") tag_group('unic') s_multilingual_unicode_string_list_definition
{
	struct nicename("Variables") s_variables_definition
	{
		DEPRECATED_string_id nicename("Pipe Handler") pipe_handler;
		DEPRECATED_string_id nicename("Property Handler") property_handler;
	};

	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	// Variables : Variables are referenced in strings by an 8-character hex index of the below block, prefixed by the "variable/" tag.
	s_tag_block_definition<s_variables_definition> nicename("Variables") variables1_block;
	DataReference __unknown3;
	uniclist nicename("Strings") strings;
};

