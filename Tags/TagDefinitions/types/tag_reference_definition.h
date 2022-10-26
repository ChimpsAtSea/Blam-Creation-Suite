#pragma once

namespace blofeld
{

	struct s_tag_reference_definition
	{
		const char* pretty_name;
		const char* name;
		const char* symbol_name;
		f_tag_reference_flags const flags;
		uint32_t const group_tag;
		const uint32_t* const group_tags;

		s_tag_reference_definition(
			const char* _name,
			const char* _pretty_name,
			const char* _symbol_name,
			uint32_t _group_tag,
			const uint32_t _group_tags[],
			f_tag_reference_flags _flags = 0) :
			name(_name),
			pretty_name(_pretty_name),
			symbol_name(_symbol_name),
			flags(_flags),
			group_tag(_group_tag),
			group_tags(_group_tags)
		{
			ASSERT(flags.valid());
		}

		s_tag_reference_definition(
			const char* _name,
			const char* _pretty_name,
			const char* _symbol_name,
			uint32_t _group_tag = INVALID_TAG,
			f_tag_reference_flags _flags = 0) :
			name(_name),
			pretty_name(_pretty_name),
			symbol_name(_symbol_name),
			flags(_flags),
			group_tag(_group_tag),
			group_tags(nullptr)
		{
			ASSERT(flags.valid());
		}
	};

}
