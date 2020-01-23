#pragma once

struct nicename("Multilingual Unicode String List") group('unic') s_multilingual_unicode_string_list_definition
{
	struct nicename("Variables") s_variable_block_definition;

	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	// comment
	s_tag_block_definition<s_variable_block_definition> nicename("Variables") variables_block; 
	DataReference __unknown4_data_reference; 
	int32_t nicename("Strings") strings[12];

	struct nicename("variable") s_variable_block_definition
	{
		string_id nicename("Pipe Handler") pipe_handler; 
		string_id nicename("Property Handler") property_handler; 
	};
};
