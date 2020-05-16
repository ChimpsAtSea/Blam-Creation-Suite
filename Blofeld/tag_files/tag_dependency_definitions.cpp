#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(dependency_struct_definition)
{
	FIELD( _field_block, "dependency list", &one_dependency_block_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(one_dependency_block_definition, k_kilo*10)
{
	FIELD( _field_tag_reference, "tag reference" ),
	FIELD( _field_terminator )
};

TAG_GROUP(dependency_block, DEPENDENCY_TAG)
{
	FIELD( _field_block, "dependency list", &one_dependency_block_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

