#include "tagdefinitions-private-pch.h"

using namespace blofeld;

bool blofeld::execute_tag_field_versioning(
	s_tag_field const& tag_field,
	s_engine_platform_build engine_platform_build,
	tag group_tag,
	unsigned long struct_version,
	unsigned long& skip_count)
{
	if (tag_field.field_type != _field_version)
	{
		skip_count = 0;
		return false;
	}

	return execute_tag_field_versioning(tag_field.versioning, engine_platform_build, group_tag, struct_version, skip_count);
}

bool blofeld::execute_tag_field_versioning(
	s_tag_field_versioning const& versioning,
	s_engine_platform_build engine_platform_build,
	tag group_tag,
	unsigned long struct_version,
	unsigned long& skip_count)
{
	bool skip_versioning_field = false;
	skip_count = versioning.version_field_skip_count;

	switch (versioning.mode)
	{
	case _version_mode_invalid:
		FATAL_ERROR("Invalid version mode");
		break;
	case _version_mode_custom:
		ASSERT(versioning.custom_version_callback);
		skip_count = versioning.custom_version_callback(engine_platform_build);
		skip_versioning_field = false;
		break;
	case _version_mode_platform_include:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case _version_mode_platform_exclude:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case _version_mode_equal:
		skip_versioning_field = engine_platform_build == versioning.engine_platform_build;
		break;
	case _version_mode_not_equal:
		skip_versioning_field = engine_platform_build != versioning.engine_platform_build;
		break;
	case _version_mode_less:
		skip_versioning_field = engine_platform_build < versioning.engine_platform_build;
		break;
	case _version_mode_greater:
		skip_versioning_field = engine_platform_build > versioning.engine_platform_build;
		break;
	case _version_mode_less_or_equal:
		skip_versioning_field = engine_platform_build <= versioning.engine_platform_build;
		break;
	case _version_mode_greater_or_equal:
		skip_versioning_field = engine_platform_build >= versioning.engine_platform_build;
		break;
	case _version_mode_tag_group_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag == group_tag;
		break;
	case _version_mode_tag_group_not_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag != group_tag;
		break;
	case _struct_version_mode_equal:
		skip_versioning_field = struct_version == versioning.struct_version;
		break;
	case _struct_version_mode_greater_or_equal:
		skip_versioning_field = struct_version >= versioning.struct_version;
		break;
	}

	if (skip_versioning_field)
	{
		skip_count = 0;
	}

	return true;
}

BCS_RESULT blofeld::calculate_versioned_tag_field_count(
	const s_tag_field* tag_fields,
	s_engine_platform_build engine_platform_build,
	tag group_tag,
	unsigned long struct_version,
	unsigned long& field_count)
{
	field_count = 0;
	for (const s_tag_field* tag_field_iterator = tag_fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, struct_version);

		field_count++;
	}
	return BCS_S_OK;
}

BCS_RESULT blofeld::calculate_tag_field_count(
	const s_tag_field* tag_fields,
	unsigned long& field_count)
{
	field_count = 0;
	for (const s_tag_field* tag_field_iterator = tag_fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		field_count++;
	}
	return BCS_S_OK;
}
