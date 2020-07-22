#pragma once

class c_h4_blamboozle;
class c_h4_tag_resource
{
public:
	friend c_h4_blamboozle;
	const char* name;
protected:
	const s_h4_tag_resource_definition* const tag_resource_definition;
	const s_h4_tag_struct_definition* const struct_definition;
public:
	c_h4_tag_struct& tag_struct;

	c_h4_tag_resource(const char* h4_data, const s_h4_tag_resource_definition* tag_resource_definition);
};

