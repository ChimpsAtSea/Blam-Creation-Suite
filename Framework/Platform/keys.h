#pragma once

#define KEYS_API extern "C"

KEYS_API long init_keys();
KEYS_API void deinit_keys();
KEYS_API long keys_user_type();
KEYS_API const char* keys_user_name();
KEYS_API unsigned long keys_user_discriminator();
