#pragma once

struct s_symbol_file_public;

BCS_SHARED BCS_RESULT symbol_manager_cleanup();
BCS_SHARED BCS_RESULT symbol_manager_get_public_symbol_by_pointer(const void* pointer, s_symbol_file_public*& public_symbol);
BCS_SHARED BCS_RESULT symbol_manager_get_public_symbol_by_rva_plus_base(const void* module_instance, uint64_t rva_plus_base, s_symbol_file_public*& public_symbol);
