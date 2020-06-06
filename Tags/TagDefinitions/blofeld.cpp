#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	const char* empty_string_list[] = { nullptr };

	const s_tag_group* get_tag_group_by_group_tag(uint32_t group_tag)
	{
		for (const s_tag_group** group = tag_groups; *group; group++)
		{
			if ((**group).group_tag == group_tag)
			{
				return *group;
			}
		}
		return nullptr;
	}
}


