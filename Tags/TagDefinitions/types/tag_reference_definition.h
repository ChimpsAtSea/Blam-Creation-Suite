#pragma once

namespace blofeld
{
	enum e_tag_reference_flags : unsigned long
	{
		_tag_reference_flag_not_a_dependency,
		_tag_reference_flag_dont_resolve_in_editor,
		_tag_reference_flag_resolved_manually,
		_tag_reference_flag_resolved_by_game,
		_tag_reference_flag_not_a_resource_dependency,
		_tag_reference_flag_dependency_for_cache_file_sharing,
		_tag_reference_flag_reference_ignored_by_bundle_builder
	};

	struct s_tag_reference_definition
	{
		e_tag_reference_flags const flags;
		unsigned long const group_tag;
		const unsigned long* const group_tags;

		s_tag_reference_definition(unsigned long group_tag, e_tag_reference_flags flags, const unsigned long group_tags[]) :
			flags(flags),
			group_tag(group_tag),
			group_tags(group_tags)
		{

		}

		s_tag_reference_definition(unsigned long group_tag, e_tag_reference_flags flags) :
			flags(flags),
			group_tag(group_tag),
			group_tags(nullptr)
		{

		}

		s_tag_reference_definition(unsigned long group_tag = INVALID_TAG, unsigned long flags = 0) :
			flags(static_cast<e_tag_reference_flags>(flags)),
			group_tag(group_tag),
			group_tags(nullptr)
		{

		}
	};
}
