#pragma once

namespace blofeld
{
	struct s_tag_field;

	enum e_version_mode : unsigned char
	{
		_version_mode_invalid,
		_version_mode_equal,
		_version_mode_not_equal,
		_version_mode_less,
		_version_mode_greater,
		_version_mode_less_or_equal,
		_version_mode_greater_or_equal,
		_version_mode_platform_include,
		_version_mode_platform_exclude,
		_version_mode_custom,
		_version_mode_tag_group_equal,
		_version_mode_tag_group_not_equal,
		k_num_version_mode_type
	};

	using t_tag_field_custom_version_callback = long(*)(s_engine_platform_build engine_platform_build);

	struct s_tag_field_versioning
	{
		const s_tag_group* group;
		t_tag_field_custom_version_callback custom_version_callback;
		unsigned long version_field_skip_count;
		s_engine_platform_build engine_platform_build;
		e_version_mode mode;
	};

	BCS_DEBUG_API bool execute_tag_field_versioning(
		s_tag_field const& tag_field,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		unsigned long& skip_count);

	BCS_DEBUG_API bool execute_tag_field_versioning(
		s_tag_field_versioning const& versioning,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		unsigned long& skip_count);

}
