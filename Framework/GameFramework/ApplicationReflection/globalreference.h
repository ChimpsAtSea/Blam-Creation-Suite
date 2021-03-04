#pragma once

typedef uintptr_t(reference_symbol_offset_function)(s_engine_platform_build engine_platform_build);

class c_global_reference
{
public:
	
	c_global_reference(const char* pReferenceName, reference_symbol_offset_function* offset_function);
	c_global_reference(const char* pReferenceName, s_engine_platform_build engine_platform_build, intptr_t offset);

	static void init_global_reference_tree(s_engine_platform_build engine_platform_build);
	static void deinit_global_reference_tree(s_engine_platform_build engine_platform_build);
	static void destroy_tree();
private:
	void init();
	c_global_reference* init_node(s_engine_platform_build engine_platform_build);
	c_global_reference* deinit_node(s_engine_platform_build engine_platform_build);

	c_global_reference* next_global_reference;
	s_engine_platform_build engine_platform_build;
	intptr_t offset;
	intptr_t original_reference_value;
	reference_symbol_offset_function* offset_function;
	const char* reference_name;
	void* data_address;
	s_symbol_file_public* public_symbol;
	void** reference_memory_pointer;

	static c_global_reference* first_global_reference;
	static c_global_reference* last_global_reference;
};

