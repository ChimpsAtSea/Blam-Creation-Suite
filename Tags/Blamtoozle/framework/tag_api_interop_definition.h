#pragma once

class c_blamtoozle_tag_struct_definition;

class c_blamtoozle_tag_api_interop_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_api_interop_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_api_interop_definition(const c_blamtoozle_tag_api_interop_definition&) = delete;
	c_blamtoozle_tag_api_interop_definition(c_blamtoozle_tag_api_interop_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_api_interop_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual const blofeld::s_tag_persistent_identifier& get_persistent_identifier() = 0;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};
