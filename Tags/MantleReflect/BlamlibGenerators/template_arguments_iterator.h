#pragma once

class c_template_arguments_iterator
{
public:
	c_template_arguments_iterator(const clang::TemplateArgumentList& arguments_list) :
		arguments_list(arguments_list)
	{

	}
	const clang::TemplateArgumentList& arguments_list;

	decltype(auto) begin() { return arguments_list.data(); }
	decltype(auto) end() { return arguments_list.data() + arguments_list.size(); }
};
