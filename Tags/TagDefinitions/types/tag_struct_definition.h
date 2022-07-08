#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_field;

	struct s_tag_struct_definition
	{
		s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* struct_name,
			const char* filename,
			long const line,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* struct_name,
			const char* filename,
			long const line,
			c_flags<e_tag_field_set_bit> runtime_flags,
			c_tag_memory_attributes const memory_attributes,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		const char* const pretty_name;
		const char* const name;
		const char* const struct_name;
		const char* const filename;
		int const line;
		c_flags<e_tag_field_set_bit> runtime_flags;
		c_tag_memory_attributes const memory_attributes;
		s_tag_persistent_identifier const persistent_identifier;
		const s_tag_field* const fields;
		int alignment_bits;
		s_symbol_file_public* symbol;
	};
}
