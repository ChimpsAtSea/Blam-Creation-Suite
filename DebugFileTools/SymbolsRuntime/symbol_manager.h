#pragma once

struct s_symbol_file_public;

BCS_DEBUG_API BCS_RESULT symbol_manager_get_public_symbol_by_pointer(const void* pointer, s_symbol_file_public*& public_symbol);
