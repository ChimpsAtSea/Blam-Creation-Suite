#include "definitiontweaker-private-pch.h"

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	flags(),
	group_tags(),
	original_reference_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_reference_definition& tag_reference_definition) :
	runtime_tag_definitions(_runtime_tag_definitions),
	flags(tag_reference_definition.flags),
	group_tags(),
	original_reference_definition(&tag_reference_definition)
{
	if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
	{
		group_tags.push_back(tag_reference_definition.group_tag);
	}
	else if (tag_reference_definition.group_tags)
	{
		for (const uint32_t* group_tag_iterator = tag_reference_definition.group_tags; *group_tag_iterator != blofeld::INVALID_TAG; group_tag_iterator++)
		{
			group_tags.push_back(*group_tag_iterator);
		}
	}
}
