#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- types */

typedef long string_id;
static_assert(sizeof(string_id) == 0x4);

class c_old_string_id
{
	unsigned long value;
};
static_assert(sizeof(c_old_string_id) == 0x4);


