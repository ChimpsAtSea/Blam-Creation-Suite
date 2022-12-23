#pragma once

struct s_halo4_tag_group_hierarchy
{
	tag group_tag;
	const char* group_name;
	s_halo4_tag_group_hierarchy* parents[2];
};

extern s_halo4_tag_group_hierarchy* halo4_global_tag_group_hierarchy[]; // null terminated list
extern s_halo4_tag_group_hierarchy* halo4_tag_group_hierarchy[]; // null terminated list
