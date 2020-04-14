#pragma once

typedef uintptr_t(reference_symbol_offset_function)(e_engine_type engine_type, e_build build);

class c_global_reference
{
public:
	
	c_global_reference(const char* pReferenceName, reference_symbol_offset_function* offset_function);
	c_global_reference(const char* pReferenceName, e_engine_type engine_type, e_build build, intptr_t offset);

	static void init_global_reference_tree(e_engine_type engine_type, e_build build);
	static void deinit_global_reference_tree(e_engine_type engine_type, e_build build);
	static void destroy_tree();
private:
	void init();
	c_global_reference* init_node(e_engine_type engine_type, e_build build);
	c_global_reference* deinit_node(e_engine_type engine_type, e_build build);

	c_global_reference* next_global_reference;
	e_engine_type target_engine;
	e_build target_build;
	intptr_t offset;
	intptr_t original_reference_value;
	reference_symbol_offset_function* offset_function;
	const char* reference_name;
	void* data_address;
	PublicSymbol* public_symbol;
	void** reference_memory_pointer;

	static c_global_reference* first_global_reference;
	static c_global_reference* last_global_reference;
};

