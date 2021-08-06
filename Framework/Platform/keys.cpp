#include "platform-private-pch.h"

#define KEYS_API extern "C"

KEYS_API long init_keys()
{
	return false;
}

KEYS_API void deinit_keys()
{
	
}

KEYS_API long keys_user_type()
{
	return 0;
}

KEYS_API const char* keys_user_name()
{
	return "";
}

KEYS_API unsigned long keys_user_discriminator()
{
	return 1;
}
