#pragma once

#include <cseries/cseries.h>

/* ---------- types */

struct s_half_rgb_lightprobe
{
	short dominant_light_direction[3];
	short : 16;
	short dominant_light_intensity[3];
	short : 16;
	short sh_red[9];
	short sh_green[9];
	short sh_blue[9];
	short : 16;
};
static_assert(sizeof(s_half_rgb_lightprobe) == 0x48);
