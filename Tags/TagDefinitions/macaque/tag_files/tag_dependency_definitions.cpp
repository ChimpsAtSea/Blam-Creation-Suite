#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		dependency_group,
		DEPENDENCY_TAG,
		nullptr,
		INVALID_TAG,
		dependency_block );

	TAG_BLOCK_FROM_STRUCT(
		dependency_block,
		"dependency_block",
		1,
		dependency_struct_definition);

	#define ONE_DEPENDENCY_BLOCK_DEFINITION_ID { 0xD35E5ED1, 0xE81246C5, 0xAA31F553, 0x3A8A909C }
	TAG_BLOCK(
		one_dependency_block_definition_block,
		"one_dependency_block_definition",
		k_kilo*10,
		"s_one_dependency",
		ONE_DEPENDENCY_BLOCK_DEFINITION_ID)
	{
		{ _field_tag_reference, "tag reference", &dependency_reference_definition },
		{ _field_terminator }
	};

	#define DEPENDENCY_STRUCT_DEFINITION_ID { 0xE7E865D4, 0xC1CE4274, 0xAFDC6ECC, 0xCF42D536 }
	TAG_STRUCT(
		dependency_struct_definition,
		"dependency_struct_definition",
		"s_dependency_list",
		DEPENDENCY_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "dependency list", &one_dependency_block_definition_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(dependency_reference_definition);

} // namespace macaque

} // namespace blofeld

