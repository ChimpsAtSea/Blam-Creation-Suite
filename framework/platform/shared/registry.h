#pragma once

typedef struct s_registry_key_handle* h_registry_key_handle;

BCS_SHARED BCS_RESULT registry_current_user_open(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle);
BCS_SHARED BCS_RESULT registry_current_user_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle);
BCS_SHARED BCS_RESULT registry_current_user_open_or_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle);
BCS_SHARED BCS_RESULT registry_close(h_registry_key_handle registry_key_handle);
BCS_SHARED BCS_RESULT registry_read_u32(h_registry_key_handle registry_key_handle, uint32_t& value);
BCS_SHARED BCS_RESULT registry_read_enum_u32(h_registry_key_handle registry_key_handle, uint32_t index, wchar_t* buffer, uint32_t& buffer_length, uint32_t& value);
