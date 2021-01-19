#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(tag_package_manifest, TAG_PACKAGE_MANIFEST_TAG)
	{
		{ _field_block, "patches", &tag_patch_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(tag_patch_block, 8192)
	{
		{ _field_tag_reference, "new tag", &tag_patch_block_struct_new_tag_reference },
		{ _field_tag_reference, "tag to override", &tag_patch_block_struct_tag_to_override_reference },
		{ _field_terminator }
	};

} // namespace blofeld

