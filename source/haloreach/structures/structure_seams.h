#pragma once

#include <cseries/cseries.h>

/* ---------- types */

struct s_seam_mapping
{
	short seam_index;
	short structure_edge_index;
};
static_assert(sizeof(s_seam_mapping) == 0x4);
