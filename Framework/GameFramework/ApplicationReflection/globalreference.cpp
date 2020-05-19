#include "gameframework-private-pch.h"

c_global_reference* c_global_reference::first_global_reference = nullptr;
c_global_reference* c_global_reference::last_global_reference = nullptr;

c_global_reference::c_global_reference(const char* pReferenceName, reference_symbol_offset_function* offset_function) :
	next_global_reference(nullptr),
	target_engine(_engine_type_not_set),
	target_build(_build_not_set),
	offset(~uintptr_t()),
	reference_name(pReferenceName),
	offset_function(offset_function),
	data_address(nullptr),
	reference_memory_pointer(nullptr)
{
	init();
}

c_global_reference::c_global_reference(const char* pReferenceName, e_engine_type engine_type, e_build build, intptr_t offset) :
	next_global_reference(nullptr),
	target_engine(engine_type),
	target_build(build),
	offset(offset),
	reference_name(pReferenceName),
	offset_function(nullptr),
	data_address(nullptr),
	reference_memory_pointer(nullptr)
{
	init();
}

void c_global_reference::init()
{
	if (last_global_reference)
	{
		last_global_reference->next_global_reference = this;
		last_global_reference = this;
	}
	else
	{
		first_global_reference = this;
		last_global_reference = this;
	}
}

void c_global_reference::init_global_reference_tree(e_engine_type engine_type, e_build build)
{
	c_global_reference* current_global_reference = first_global_reference;
	while (current_global_reference)
	{
		current_global_reference = current_global_reference->init_node(engine_type, build);
	}
}

void c_global_reference::deinit_global_reference_tree(e_engine_type engine_type, e_build build)
{
	c_global_reference* current_global_reference = first_global_reference;
	while (current_global_reference)
	{
		current_global_reference = current_global_reference->deinit_node(engine_type, build);
	}
}

void c_global_reference::destroy_tree()
{
	c_global_reference* current_global_reference = first_global_reference;
	while (current_global_reference)
	{
		c_global_reference* pNextc_global_reference = current_global_reference->next_global_reference;

		delete current_global_reference;

		current_global_reference = pNextc_global_reference;
	}
}

c_global_reference* c_global_reference::init_node(e_engine_type engine_type, e_build build)
{
	if ((target_engine == e_engine_type::_engine_type_not_set || target_engine == engine_type) && (target_build == _build_not_set || target_build == build))
	{
		if (data_address != nullptr)
		{
			FATAL_ERROR(L"c_global_reference is already initialized. deinitializ first!");
		}

		if (public_symbol == nullptr)
		{
			public_symbol = c_runtime_symbols::runtime().get_public_symbol_by_name(reference_name);
			reference_memory_pointer = nullptr;
			if (public_symbol == nullptr)
			{
				write_line_verbose("c_global_reference: WARNING: Failed to find symbol '%s'", reference_name);
				DEBUG_ONLY(FATAL_ERROR(L"c_global_reference: WARNING: Failed to find symbol '%S'", reference_name));
			}
			else
			{
				uint64_t application_virtual_address = c_runtime_symbols::runtime().get_base_virtual_address();
				uint64_t symbol_virtual_address = public_symbol->rva_plus_base;
				uint64_t symbol_relative_virtual_address = symbol_virtual_address - application_virtual_address;
				static char* current_module_base_address = reinterpret_cast<char*>(c_runtime_util::get_current_module());
				char* symbol_address = current_module_base_address + symbol_relative_virtual_address;
				reference_memory_pointer = reinterpret_cast<void**>(symbol_address);

				if (reference_memory_pointer == nullptr)
				{
					write_line_verbose("c_global_reference: WARNING: Failed to find reference address for symbol '%s'", reference_name);
					DEBUG_ONLY(FATAL_ERROR(L"c_global_reference: WARNING: Failed to find reference address for symbol '%S'", reference_name));
				}
			}
		}
		
		if(reference_memory_pointer != nullptr)
		{
			intptr_t target_offset = offset;
			if (offset_function)
			{
				target_offset = offset_function(engine_type, build);
			}
			if (target_offset == ~uintptr_t())
			{
				return next_global_reference;
			}
			else
			{
				uint64_t engine_virtual_address = GetEngineBaseAddress(engine_type);
				uint64_t data_virtual_address = static_cast<uint64_t>(target_offset);
				uint64_t data_relative_virtual_address = data_virtual_address - engine_virtual_address;
				char* engine_base_address = reinterpret_cast<char*>(GetEngineMemoryAddress(engine_type));
				data_address = engine_base_address + data_relative_virtual_address;
			}

			ASSERT(reference_memory_pointer != nullptr);
			ASSERT(data_address != nullptr);

			intptr_t& reference_value = *reinterpret_cast<intptr_t*>(reference_memory_pointer);
			//if (m_build != BuildVersion::NotSet) // specific game addresses should be verified
			//{
			//	
			//	ASSERT(dataAddressValue == targetOffset);
			//}
			// take a record of the original value for unpatching

			original_reference_value = reference_value;

			DWORD old_protect = 0;
			VirtualProtect(reference_memory_pointer, sizeof(reference_memory_pointer), PAGE_READWRITE, &old_protect);
			*reference_memory_pointer = data_address;
			VirtualProtect(reference_memory_pointer, sizeof(reference_memory_pointer), old_protect, &old_protect);

			intptr_t patched_address = reference_value;

			if (data_address)
			{
				if (patched_address == original_reference_value)
				{
					write_line_verbose("c_global_reference: Patched %s", reference_name);
				}
				else
				{
					if (original_reference_value)
					{
						write_line_verbose("c_global_reference: Patched %s from 0x%zX to 0x%zX", reference_name, original_reference_value, patched_address);
					}
					else
					{
						write_line_verbose("c_global_reference: Patched %s from <null> to 0x%zX", reference_name, patched_address);
					}
				}
			}
			else
			{
				write_line_verbose("c_global_reference: WARNING: Failed to address for symbol '%s'", reference_name);
			}
		}
		else
		{
			write_line_verbose("c_global_reference: WARNING: Failed to find symbol '%s'", reference_name);
			DEBUG_ONLY(FATAL_ERROR(L"c_global_reference: WARNING: Failed to find symbol '%S'", reference_name));
		}
	}
	return next_global_reference;
}
	
c_global_reference* c_global_reference::deinit_node(e_engine_type engine_type, e_build build)
{
	if ((target_engine == e_engine_type::_engine_type_not_set || target_engine == engine_type) && (target_build == _build_not_set || target_build == build))
	{
		if (data_address)
		{
			write_line_verbose("c_global_reference: Unpatched %s", reference_name);

			DWORD old_protect = 0;
			VirtualProtect(reference_memory_pointer, sizeof(reference_memory_pointer), PAGE_READWRITE, &old_protect);
			*reference_memory_pointer = nullptr;
			VirtualProtect(reference_memory_pointer, sizeof(reference_memory_pointer), old_protect, &old_protect);
		}
		data_address = nullptr;
	}
	return next_global_reference;
}
