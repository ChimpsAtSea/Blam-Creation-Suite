#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo1_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo1_tools_pc64_tag_reference_definition& value)
{
	byteswap_inplace(value.flags);
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.group_tags_address);
}

c_halo1_tools_pc64_tag_reference_definition::c_halo1_tools_pc64_tag_reference_definition(c_halo1_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_reference_definition(_tag_definition_manager),
	definition_address(_definition_address),
	reference_definition(tag_definition_manager.read_structure<s_halo1_tools_pc64_tag_reference_definition>(_definition_address)),
	name(),
	code_symbol_name()
{
	if (reference_definition.group_tag != ULONG_MAX)
	{
		group_tags.insert(group_tags.end(), reference_definition.group_tag);
	}
	else if (reference_definition.group_tags_address)
	{
		ptr32 group_tags_address = reference_definition.group_tags_address;
		tag group_tag = ULONG_MAX;
		do
		{
			group_tag = tag_definition_manager.read_structure<tag>(group_tags_address);
			if (group_tag == ULONG_MAX) break;
			group_tags.insert(group_tags.end(), group_tag);
			group_tags_address += sizeof(group_tag);
		} while (group_tag != ULONG_MAX);
	}

	// #TODO: use the symbol file to find a name?

	for (tag group_tag : group_tags)
	{
		c_blamtoozle_tag_group_definition* group_definition = tag_definition_manager.get_tag_group_definition_by_group_tag(group_tag);
		ASSERT(group_definition != nullptr);
		tag_group_definitions.insert(tag_group_definitions.end(), group_definition);

		if (!name.empty())
		{
			name += "_";
		}
		name += group_definition->get_code_symbol_name();
	}
	name += "_reference";

	code_symbol_name = name;

	tag_definition_manager.format_code_symbol_name(name);
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_not_a_dependency))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_not_a_dependency, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_dont_resolve_in_editor))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_dont_resolve_in_editor, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_resolved_manually))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_resolved_manually, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_resolved_by_game))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_resolved_by_game, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_not_a_resource_dependency))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_not_a_resource_dependency, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_dependency_for_cache_file_sharing, true);
	}
	if (reference_definition.flags.test(_halo1_tools_pc64_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		tag_reference_flags.set(blofeld::_tag_reference_flag_reference_ignored_by_bundle_builder, true);
	}
}

c_halo1_tools_pc64_tag_reference_definition::~c_halo1_tools_pc64_tag_reference_definition()
{

}

const char* c_halo1_tools_pc64_tag_reference_definition::get_name()
{
	return name.c_str();
}

const char* c_halo1_tools_pc64_tag_reference_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

c_flags<blofeld::e_tag_reference_flags> c_halo1_tools_pc64_tag_reference_definition::get_tag_reference_flags()
{
	return tag_reference_flags;
}
