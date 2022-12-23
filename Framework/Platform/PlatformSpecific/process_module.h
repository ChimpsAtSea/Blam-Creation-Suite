#pragma once

BCS_SHARED BCS_RESULT register_process_module(void* process_module);
BCS_SHARED BCS_RESULT register_process_module_by_pointer(void* pointer);
BCS_SHARED BCS_RESULT get_process_module(void*& process_module);
