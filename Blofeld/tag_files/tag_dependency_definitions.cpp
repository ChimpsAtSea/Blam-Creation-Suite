#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(one_dependency, k_kilo*10)
{
	FIELD( _field_tag_reference, "tag reference" ),
	FIELD( _field_terminator )
};

TAG_GROUP(dependency, DEPENDENCY_TAG)
{
	FIELD( _field_block, "dependency list", &one_dependency_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

