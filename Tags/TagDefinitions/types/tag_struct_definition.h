#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_field;

	struct s_tag_persistent_identifier
	{
		unsigned long data[4];
	};

	struct s_tag_struct_definition
	{
		s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* struct_name,
			const char* filename,
//#ifdef __INTELLISENSE__
//			const char* pretty_name,
//			const char* name,
//			const char* struct_name,
//			const char* filename,
//#else
//			const char(&pretty_name)[],
//			const char(&name)[],
//			const char(&struct_name)[],
//			const char(&filename)[],
//#endif
			int32_t const line,
			s_tag_persistent_identifier persistent_identifier,
#ifndef __INTELLISENSE2__
			s_tag_field* fields,
#else
			s_tag_field(&fields)[],
#endif
			int alignment_bits = 0
		);

		const char* const pretty_name;
		const char* const name;
		const char* const struct_name;
		const char* const filename;
//#ifdef __INTELLISENSE__
//		const char* const pretty_name;
//		const char* const name;
//		const char* const struct_name;
//		const char* const filename;
//#else
//		const char(&name)[];
//		const char(&pretty_name)[];
//		const char(&struct_name)[];
//		const char(&filename)[];
//#endif
		int const line;
#ifndef __INTELLISENSE2__
		s_tag_persistent_identifier const persistent_identifier;
		const s_tag_field* const fields;
#else
		s_tag_field(&fields)[];
#endif
		int alignment_bits;

		s_symbol_file_public* symbol;
	};
}
