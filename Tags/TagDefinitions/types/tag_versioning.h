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

	BCS_DEBUG_API BCS_RESULT calculate_versioned_tag_field_count(
		const s_tag_field* tag_fields,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		unsigned long& field_count);

	BCS_DEBUG_API BCS_RESULT calculate_tag_field_count(
		const s_tag_field* tag_fields,
		unsigned long& field_count);

#define tag_field_iterator_versioning(_tag_field_iterator, _engine_platform_build, _group_tag) \
	*_tag_field_iterator; \
	{ \
		unsigned long field_skip_count; \
		if (execute_tag_field_versioning(*_tag_field_iterator, _engine_platform_build, _group_tag, field_skip_count)) \
		{ \
			_tag_field_iterator += field_skip_count; \
			continue; \
		} \
	}


}
