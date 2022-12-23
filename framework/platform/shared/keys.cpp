#include "platform-private-pch.h"

#define KEYS_API extern "C"

KEYS_API int32_t init_keys()
{
	return false;
}

KEYS_API void deinit_keys()
{
	
}

KEYS_API int32_t keys_user_type()
{
	return 1;
}

KEYS_API const char* keys_user_name()
{
	return "";
}

KEYS_API uint32_t keys_user_discriminator()
{
	return 0;
}
