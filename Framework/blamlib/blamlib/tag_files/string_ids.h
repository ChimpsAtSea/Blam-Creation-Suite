#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- types */

typedef int string_id;
static_assert(sizeof(string_id) == 0x4);

class c_old_string_id
{
public:
	unsigned int value;
};
static_assert(sizeof(c_old_string_id) == 0x4);


