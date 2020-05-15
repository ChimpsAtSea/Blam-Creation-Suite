#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(tag_patch, 8192)
{
	{ _field_tag_reference, "new tag" },
	{ _field_tag_reference, "tag to override" },
	{ _field_terminator },
};

TAG_GROUP(tag_package_manifest, TAG_PACKAGE_MANIFEST_TAG)
{
	{ _field_block, "patches", &tag_patch_block },
	{ _field_terminator },
};

} // namespace blofeld

