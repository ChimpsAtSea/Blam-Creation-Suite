#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- types */

union string_id
{
	string_id(unsigned long value) :
		value(value)
	{

	}

	unsigned long value;
	struct
	{
		unsigned long index : 17;
		unsigned long set : 8;
		unsigned long length : 7;
	};
};
//typedef long string_id;
static_assert(sizeof(string_id) == 0x4);

class c_old_string_id
{
	unsigned long value;
};
static_assert(sizeof(c_old_string_id) == 0x4);


