#pragma once

namespace blofeld
{

	struct s_tag_group_info
	{
		tag group_tag;
		const char* group_name;
		s_tag_group_info* parents[2];
	};

	namespace haloreach
	{
		extern s_tag_group_info* haloreach_global_tag_groups[];
		extern s_tag_group_info* haloreach_tag_groups[];
	}

}
