#include "gameframework-private-pch.h"

c_function_hook_base* c_function_hook_base::g_first_function_hook = nullptr;
c_function_hook_base* c_function_hook_base::g_last_function_hook = nullptr;

void c_function_hook_base::init_function_hook_tree(e_engine_type engine_type, e_build build)
{
	// this iteration avoids having to do this recursively

	c_function_hook_base* pCurrentFunctionHook = g_first_function_hook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->init_node(engine_type, build);
	}
}

void c_function_hook_base::deinit_function_hook_tree(e_engine_type engine_type, e_build build)
{
	// this iteration avoids having to do this recursively

	c_function_hook_base* pCurrentFunctionHook = g_first_function_hook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->deinit_node(engine_type, build);
	}
}

c_function_hook_base* c_function_hook_base::init_node(e_engine_type _engine_type, e_build _build)
{
	if ((engine_type == _engine_type || engine_type == _engine_type_not_set) && ((_build == build || (build == _build_not_set && find_offset_func)) && is_active && !is_hooked))
	{
		if (offset == 0 && find_offset_func)
		{
			uintptr_t found_offset = find_offset_func(_engine_type, _build);

			if (found_offset == ~uintptr_t())
			{
				return next_function_hook;
			}

			offset = found_offset;

			DEBUG_ASSERT(build == _build_not_set && offset >= get_engine_base_address(_engine_type)/*, "Offset is out of bounds"*/);
			DEBUG_ASSERT(build == _build_not_set && offset < get_engine_top_address(_engine_type, _build)/*, "Offset is out of bounds"*/);
		}
		DEBUG_ASSERT(offset != 0);

		FunctionHookVarArgs<_engine_type_not_set, _build_not_set, 0, void>& void_this = reinterpret_cast<FunctionHookVarArgs<_engine_type_not_set, _build_not_set, 0, void>&>(*this);

		void*& base = void_this.get_base();
		void*& hook = void_this.get_hook();

		const char* function_name = name;
		char unknown_function_name_buffer[256] = {};
		if (function_name == nullptr)
		{
			int count = snprintf(unknown_function_name_buffer, _countof(unknown_function_name_buffer), "unnamed<0x%zX>", offset);
			unknown_function_name_buffer[_countof(unknown_function_name_buffer) - 1] = 0;
			function_name = unknown_function_name_buffer;
		}

		if (hook)
		{
			LONG result = create_hook(_engine_type, _build, offset, function_name, hook, base);
			ASSERT(result == 0);
		}
		else
		{
			populate_function_ptr(get_engine_module_filename(_engine_type), get_engine_base_address(_engine_type), offset, base);
			c_console::write_line_verbose("Created function pointer for %s", function_name);
		}

		is_hooked = true;
	}
	return next_function_hook;
}


c_function_hook_base* c_function_hook_base::deinit_node(e_engine_type engine_type, e_build build)
{
	if (is_hooked)
	{
		is_hooked = false; // #TODO: Do this better. We are unload the DLL so this is okay...
	}
	return next_function_hook;
}
