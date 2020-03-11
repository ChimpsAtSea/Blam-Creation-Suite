#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_group_definitions.h>

/* ---------- types */

struct s_cluster_reference
{
	union
	{
		struct
		{
			char bsp_index; // can be NONE
			byte cluster_index; // can not be checked against NONE!!!
		};
		struct
		{
			short packed_value;
		};
	};
};
static_assert(sizeof(s_cluster_reference) == 0x2);

/* ---------- globals */

extern s_struct_definition g_cluster_reference_struct;
