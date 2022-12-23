#pragma once

#define KEYS_API extern "C"

KEYS_API BCS_SHARED int32_t init_keys();
KEYS_API BCS_SHARED void deinit_keys();
KEYS_API BCS_SHARED int32_t keys_user_type();
KEYS_API BCS_SHARED const char* keys_user_name();
KEYS_API BCS_SHARED uint32_t keys_user_discriminator();
