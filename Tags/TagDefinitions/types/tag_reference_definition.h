#pragma once

namespace blofeld
{

	struct s_tag_reference_definition
	{
		e_tag_reference_flags const flags;
		uint32_t const group_tag;
		const uint32_t* const group_tags;

		s_tag_reference_definition(uint32_t group_tag, const uint32_t group_tags[], t_tag_reference_flags flags = 0) :
			flags(static_cast<e_tag_reference_flags>(flags)),
			group_tag(group_tag),
			group_tags(group_tags)
		{

		}

		s_tag_reference_definition(uint32_t group_tag = INVALID_TAG, t_tag_reference_flags flags = 0) :
			flags(static_cast<e_tag_reference_flags>(flags)),
			group_tag(group_tag),
			group_tags(nullptr)
		{

		}
	};

}
