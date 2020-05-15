#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(tag_patch, 8192)
{
	FIELD( _field_tag_reference, "new tag" ),
	FIELD( _field_tag_reference, "tag to override" ),
	FIELD( _field_terminator )
};

TAG_GROUP(tag_package_manifest, TAG_PACKAGE_MANIFEST_TAG)
{
	FIELD( _field_block, "patches", &tag_patch_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

