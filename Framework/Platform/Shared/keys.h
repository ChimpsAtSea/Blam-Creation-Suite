#pragma once

#define KEYS_API extern "C"

KEYS_API BCS_DEBUG_API int32_t init_keys();
KEYS_API BCS_DEBUG_API void deinit_keys();
KEYS_API BCS_DEBUG_API int32_t keys_user_type();
KEYS_API BCS_DEBUG_API const char* keys_user_name();
KEYS_API BCS_DEBUG_API uint32_t keys_user_discriminator();
