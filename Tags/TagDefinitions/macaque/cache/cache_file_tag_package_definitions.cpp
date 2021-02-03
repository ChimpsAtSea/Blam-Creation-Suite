#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define TAG_PACKAGE_MANIFEST_STRUCT_DEFINITION_ID { 0x71C748DE, 0x49F7414C, 0xAAA41710, 0x99C055EA }
	TAG_BLOCK(
		tag_package_manifest_block,
		"tag_package_manifest_block",
		1,
		"CacheFiles::TagPackageManifest",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TAG_PACKAGE_MANIFEST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "patches", &tag_patch_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		tag_package_manifest_group,
		TAG_PACKAGE_MANIFEST_TAG,
		nullptr,
		INVALID_TAG,
		tag_package_manifest_block );

	#define TAG_PATCH_BLOCK_STRUCT_ID { 0x50CF42AF, 0x6F5141A4, 0x8B34C505, 0xD092F652 }
	TAG_BLOCK(
		tag_patch_block,
		"tag_patch_block",
		8192,
		"CacheFiles::TagPatch",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TAG_PATCH_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "new tag", &tag_patch_block_struct_new_tag_reference },
		{ _field_tag_reference, "tag to override", &tag_patch_block_struct_tag_to_override_reference },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

