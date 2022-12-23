#pragma once

namespace blofeld
{
	struct s_tag_field;
	struct s_tag_group;

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

	enum e_struct_version_mode : unsigned char
	{
		_struct_version_mode_equal = k_num_version_mode_type,
		_struct_version_mode_greater_or_equal,
	};

	using t_tag_field_custom_version_callback = long(*)(s_engine_platform_build engine_platform_build);

	struct s_tag_field_versioning
	{
		uint32_t mode;
		uint32_t struct_version;
		uint32_t version_field_skip_count;
		const s_tag_group* group;
		t_tag_field_custom_version_callback custom_version_callback;
		s_engine_platform_build engine_platform_build;
	};

	BCS_SHARED bool execute_tag_field_versioning(
		s_tag_field const& tag_field,
		s_engine_platform_build engine_platform_build,
		uint32_t struct_version,
		uint32_t& skip_count);

	BCS_SHARED bool execute_tag_field_versioning(
		s_tag_field_versioning const& versioning,
		s_engine_platform_build engine_platform_build,
		uint32_t struct_version,
		uint32_t& skip_count);

	BCS_SHARED bool execute_tag_field_versioning(
		s_tag_field const& tag_field,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		uint32_t struct_version,
		uint32_t& skip_count);

	BCS_SHARED bool execute_tag_field_versioning(
		s_tag_field_versioning const& versioning,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		uint32_t struct_version,
		uint32_t& skip_count);

	BCS_SHARED BCS_RESULT calculate_versioned_tag_field_count(
		s_tag_field const* tag_fields,
		s_engine_platform_build engine_platform_build,
		tag group_tag,
		uint32_t struct_version,
		uint32_t& field_count);

	BCS_SHARED BCS_RESULT calculate_tag_field_count(
		s_tag_field const* tag_fields,
		uint32_t& field_count);

#define tag_field_version_all ULONG_MAX
#define tag_field_version_max ( ULONG_MAX - 1 )

#define tag_field_iterator_versioning(_tag_struct_definition_ref, _tag_field_iterator, _engine_platform_build, struct_version) \
	*_tag_field_iterator; \
	if ((_tag_struct_definition_ref).runtime_flags.test(blofeld::_tag_field_set_mandrill_has_versioning)) \
	{ \
		uint32_t _field_skip_count; \
		if (execute_tag_field_versioning(*_tag_field_iterator, _engine_platform_build, struct_version, _field_skip_count)) \
		{ \
			_tag_field_iterator += _field_skip_count; \
			continue; \
		} \
	}

#define tag_field_iterator_versioning_deprecated(_tag_field_iterator, _engine_platform_build, _group_tag, struct_version) \
	*_tag_field_iterator; \
	{ \
		uint32_t _field_skip_count; \
		if (execute_tag_field_versioning(*_tag_field_iterator, _engine_platform_build, _group_tag, struct_version, _field_skip_count)) \
		{ \
			_tag_field_iterator += _field_skip_count; \
			continue; \
		} \
	}


}
