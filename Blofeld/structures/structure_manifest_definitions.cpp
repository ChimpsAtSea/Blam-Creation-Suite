#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(structure_manifest_bsp_block, k_maximum_structure_manifest_items_count)
	{
		FIELD( _field_struct, "build identifer*", &structure_manifest_build_identifier_struct_struct_definition ),
		FIELD( _field_struct, "parent build identifer*", &structure_manifest_build_identifier_struct_struct_definition ),
		FIELD( _field_long_string, "bsp name^*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(structure_manifest_build_identifier_struct)
	{
		FIELD( _field_long_integer, "manifest_id0*!" ),
		FIELD( _field_long_integer, "manifest_id1*!" ),
		FIELD( _field_long_integer, "manifest_id2*!" ),
		FIELD( _field_long_integer, "manifest_id3*!" ),
		FIELD( _field_long_integer, "build_index*" ),
		FIELD( _field_long_integer, "structure importer version*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(structure_manifest_struct)
	{
		FIELD( _field_explanation, "build identifer" ),
		FIELD( _field_struct, "build identifer*", &structure_manifest_build_identifier_struct_struct_definition ),
		FIELD( _field_explanation, "parent build identifier" ),
		FIELD( _field_struct, "parent build identifer*#for local builds, this is the content build identifier you are based on", &structure_manifest_build_identifier_struct_struct_definition ),
		FIELD( _field_block, "bsp manifest*", &structure_manifest_bsp_block_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

