#pragma once

namespace blofeld
{

	struct s_tag_reference_definition
	{
		e_tag_reference_flags const flags;
		unsigned long const group_tag;
		const unsigned long* const group_tags;

		s_tag_reference_definition(unsigned long group_tag, const unsigned long group_tags[], t_tag_reference_flags flags = 0) :
			flags(static_cast<e_tag_reference_flags>(flags)),
			group_tag(group_tag),
			group_tags(group_tags)
		{

		}

		s_tag_reference_definition(unsigned long group_tag = INVALID_TAG, t_tag_reference_flags flags = 0) :
			flags(static_cast<e_tag_reference_flags>(flags)),
			group_tag(group_tag),
			group_tags(nullptr)
		{

		}
	};

}
