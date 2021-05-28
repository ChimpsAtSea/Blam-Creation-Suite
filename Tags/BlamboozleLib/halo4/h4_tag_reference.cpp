#include <blamboozlelib-private-pch.h>

c_h4_tag_reference::c_h4_tag_reference(const char* h4_data, const s_h4_tag_reference_definition* reference_definition, unsigned long definition_address) :
	reference_definition(reference_definition),
	flags(reference_definition->flags),
	public_symbol(c_h4_blamboozle::symbols->get_public_symbol_by_base_virtual_address(definition_address))
{
	if (reference_definition->group_tag != 0xFFFFFFFF)
	{
		unsigned long value = reference_definition->group_tag;
		tag_group group = { value };
		tag_groups.push_back(group);
	}
	else if (reference_definition->group_tags_address != 0)
	{
		const unsigned long* current_group = h4_va_to_pointer<unsigned long>(h4_data, reference_definition->group_tags_address);
		while (static_cast<unsigned long>(*current_group) != 0xFFFFFFFF)
		{
			unsigned long value = *current_group;
			tag_group group = { value };
			tag_groups.push_back(group);

			current_group++;
		}
	}
}
