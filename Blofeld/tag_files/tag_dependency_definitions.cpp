#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(dependency, DEPENDENCY_TAG, dependency_block_block );

	TAG_BLOCK_FROM_STRUCT(dependency_block, 1, dependency_struct_definition_struct_definition );

	TAG_BLOCK(one_dependency_block_definition, k_kilo*10)
	{
		FIELD( _field_tag_reference, "tag reference" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(dependency_struct_definition)
{
		FIELD( _field_block, "dependency list", &one_dependency_block_definition_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

