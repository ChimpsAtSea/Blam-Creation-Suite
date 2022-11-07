#pragma once

struct s_constant_string_id_namespace
{
	const char* name;
	unsigned int string_count;
	const char** constant_string_ids;
};

struct s_constant_string_id_table
{
	unsigned int namespace_bits;
	unsigned int index_bits;
	unsigned int length_bits;
	unsigned int num_namespaces;
	s_constant_string_id_namespace** namespaces;
	unsigned int* serialization_namespace_order;
};

BCS_SHARED extern BCS_RESULT get_constant_string_id_table_by_engine_platform_build(s_engine_platform_build engine_platform_build, s_constant_string_id_table*& constant_string_id_table);
