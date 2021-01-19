#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(dependency, DEPENDENCY_TAG, dependency_block_block );

	V5_TAG_BLOCK(one_dependency_block_definition, k_kilo*10)
	{
		{ _field_tag_reference, "tag reference", &dependency_reference_definition },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(dependency_block, 1, dependency_struct_definition_struct_definition );

	V5_TAG_STRUCT(dependency_struct_definition)
	{
		{ _field_block, "dependency list", &one_dependency_block_definition_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(dependency_reference_definition);

} // namespace blofeld

