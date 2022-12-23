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

#define TAG_REFERENCE(tag_reference_symbolname, ...) \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(#tag_reference_symbolname, #tag_reference_symbolname, #tag_reference_symbolname, __VA_ARGS__)

#define TAG_REFERENCE_GROUP(tag_reference_symbolname, ...) \
extern uint32_t CONCAT(tag_reference_symbolname, _tag_groups)[]; \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(#tag_reference_symbolname, #tag_reference_symbolname, #tag_reference_symbolname, INVALID_TAG, CONCAT(tag_reference_symbolname, _tag_groups), __VA_ARGS__); \
uint32_t CONCAT(tag_reference_symbolname, _tag_groups)[] =
