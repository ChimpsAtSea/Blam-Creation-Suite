#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(structure_manifest_bsp_block, k_maximum_structure_manifest_items_count)
	{
		{ _field_struct, "build identifer*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_struct, "parent build identifer*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_long_string, "bsp name^*" },
		{ _field_terminator }
	};

	TAG_STRUCT(structure_manifest_build_identifier_struct)
	{
		{ _field_long_integer, "manifest_id0*!" },
		{ _field_long_integer, "manifest_id1*!" },
		{ _field_long_integer, "manifest_id2*!" },
		{ _field_long_integer, "manifest_id3*!" },
		{ _field_long_integer, "build_index*" },
		{ _field_long_integer, "structure importer version*" },
		{ _field_terminator }
	};

	TAG_STRUCT(structure_manifest_struct)
	{
		{ _field_explanation, "build identifer", "" },
		{ _field_struct, "build identifer*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_explanation, "parent build identifier", "" },
		{ _field_struct, "parent build identifer*#for local builds, this is the content build identifier you are based on", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_block, "bsp manifest*", &structure_manifest_bsp_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

