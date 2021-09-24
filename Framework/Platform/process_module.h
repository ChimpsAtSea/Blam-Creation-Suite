#pragma once

BCS_DEBUG_API BCS_RESULT register_process_module(void* process_module);
BCS_DEBUG_API BCS_RESULT register_process_module_by_pointer(void* pointer);
BCS_DEBUG_API BCS_RESULT get_process_module(void*& process_module);
