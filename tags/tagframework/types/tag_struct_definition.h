#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_field;

	struct s_tag_struct_definition
	{
		BCS_SHARED s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* type_name,
			const char* symbol_name,
			const char* filename,
			int32_t const line,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		BCS_SHARED s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* type_name,
			const char* symbol_name,
			const char* filename,
			int32_t const line,
			c_flags<e_tag_field_set_bit> runtime_flags,
			c_tag_memory_attributes const memory_attributes,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		const char* const pretty_name;
		const char* const name;
		const char* const type_name;
		const char* const symbol_name;
		const char* const filename;
		int const line;
		c_flags<e_tag_field_set_bit> runtime_flags;
		c_tag_memory_attributes const memory_attributes;
		s_tag_persistent_identifier const persistent_identifier;
		s_tag_field const* const fields;
		int alignment_bits;
		//s_symbol_file_public* symbol;
	};
}

// symbol, pretty_name, struct_name, persistent_identifier, [aligmnment_bits]
#define TAG_STRUCT_V6(symbol, pretty_name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field _##symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, #symbol, struct_name, #symbol, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, _##symbol##_fields, __VA_ARGS__); \
s_tag_field _##symbol##_fields[] =

#define TAG_STRUCT(symbol, pretty_name, name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field _##symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, name, struct_name, #symbol, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, _##symbol##_fields, __VA_ARGS__); \
s_tag_field _##symbol##_fields[] =

#define VERSIONED_TAG_STRUCT(symbol, pretty_name, name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field _##symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, name, struct_name, #symbol, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, _##symbol##_fields, __VA_ARGS__); \
s_tag_field _##symbol##_fields[] =
