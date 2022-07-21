#pragma once

struct s_basic_buffer32
{
	intptr32_t elements;
	int32_t size;
};

struct s_basic_buffer64
{
	intptr64_t elements;
	int64_t size;
};

template<typename T>
using c_basic_buffer32 = s_basic_buffer32;

template<typename T>
using c_basic_buffer64 = s_basic_buffer64;
