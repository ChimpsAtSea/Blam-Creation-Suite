#pragma once

namespace blofeld
{
	
	using t_tag_reference_flags = unsigned long;
	enum e_tag_reference_flags : t_tag_reference_flags
	{
		_tag_reference_flag_not_a_dependency,
		_tag_reference_flag_dont_resolve_in_editor,
		_tag_reference_flag_resolved_manually,
		_tag_reference_flag_resolved_by_game,
		_tag_reference_flag_not_a_resource_dependency,
		_tag_reference_flag_dependency_for_cache_file_sharing,
		_tag_reference_flag_reference_ignored_by_bundle_builder
	};
	
}
