#include "tagframework-private-pch.h"

#define TAG_VERSIONING_EXTENDED
#include "tag_versioning.inl"
#undef TAG_VERSIONING_EXTENDED
#include "tag_versioning.inl"



BCS_RESULT blofeld::calculate_versioned_tag_field_count(
	const s_tag_field* tag_fields,
	s_engine_platform_build engine_platform_build,
	tag group_tag,
	uint32_t struct_version,
	uint32_t& field_count)
{
	field_count = 0;
	for (const s_tag_field* tag_field_iterator = tag_fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, struct_version);

		field_count++;
	}
	return BCS_S_OK;
}

BCS_RESULT blofeld::calculate_tag_field_count(
	const s_tag_field* tag_fields,
	uint32_t& field_count)
{
	field_count = 0;
	for (const s_tag_field* tag_field_iterator = tag_fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		field_count++;
	}
	return BCS_S_OK;
}
