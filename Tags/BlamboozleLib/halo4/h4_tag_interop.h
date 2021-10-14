#pragma once

class c_h4_blamboozle;
class c_h4_tag_interop
{
public:
	friend c_h4_blamboozle;
	const char* name;
protected:
	const s_h4_tag_api_interop_definition* const tag_api_interop_definition;
	const s_h4_tag_struct_definition* const struct_definition;
public:
	c_h4_tag_struct& tag_struct;

	c_h4_tag_interop(const char* h4_data, const s_h4_tag_api_interop_definition* tag_api_interop_definition);
};

