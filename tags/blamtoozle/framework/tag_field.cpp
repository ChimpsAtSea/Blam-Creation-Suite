#include "blamtoozle-private-pch.h"

c_blamtoozle_tag_field::c_blamtoozle_tag_field(c_blamtoozle_tag_definition_manager& _tag_definition_manager) :
	t_virtual(),
	tag_definition_manager(_tag_definition_manager)
{

}

c_blamtoozle_tag_field::~c_blamtoozle_tag_field()
{

}

static blofeld::s_tag_field_versioning empty_tag_field_versioning;
blofeld::s_tag_field_versioning const& c_blamtoozle_tag_field::get_tag_field_versioning()
{
	return empty_tag_field_versioning;
}

c_blamtoozle_tag_field_combined_fixup::c_blamtoozle_tag_field_combined_fixup(
	c_blamtoozle_tag_group_definition& _group_definition,
	uint32_t _count,
	e_blamtoozle_tag_field_combined_fixup_type _fixup_type) :
	t_virtual(),
	group_definition(_group_definition),
	count(_count),
	fixup_type(_fixup_type)
{

}

c_blamtoozle_tag_field_combined_fixup::~c_blamtoozle_tag_field_combined_fixup()
{
}

c_blamtoozle_tag_field_dummy_space::c_blamtoozle_tag_field_dummy_space()
{
}

c_blamtoozle_tag_field_dummy_space::~c_blamtoozle_tag_field_dummy_space()
{
}

void string_parser(
	const char* raw_name,
	std::string& name,
	std::string& description,
	std::string& units,
	std::string& limits,
	std::string& limits_legacy,
	std::vector<std::string>& old_names,
	blofeld::f_tag_field_flags& flags)
{
	c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(raw_name);

	name = string_parser.pretty_name;
	description = string_parser.description;
	units = string_parser.units;
	limits = string_parser.limits;
	limits_legacy = string_parser.limits_legacy;
	if (!string_parser.old_name.empty())
	{
		old_names.push_back(string_parser.old_name.c_str());
	}

	flags.clear();
	flags.set(blofeld::_tag_field_flag_unknown0, string_parser.flag_unknown0);
	flags.set(blofeld::_tag_field_flag_read_only, string_parser.flag_read_only);
	flags.set(blofeld::_tag_field_flag_index, string_parser.flag_index);
	flags.set(blofeld::_tag_field_flag_unknown3, string_parser.flag_unknown3);
	flags.set(blofeld::_tag_field_flag_unknown4, string_parser.flag_unknown4);
	flags.set(blofeld::_tag_field_flag_pointer, string_parser.flag_pointer);
}
