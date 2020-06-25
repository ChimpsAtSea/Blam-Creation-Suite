#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(breakable_surface_key_table_block, (SHORT_MAX))
	{
		{ _field_short_integer, "instanced geometry index!*" },
		{ _field_byte_integer, "breakable surface set index!*" },
		{ _field_byte_integer, "breakable surface index!*" },
		{ _field_long_integer, "seed surface index!*" },
		{ _field_real, "x0!*" },
		{ _field_real, "x1!*" },
		{ _field_real, "y0!*" },
		{ _field_real, "y1!*" },
		{ _field_real, "z0!*" },
		{ _field_real, "z1!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(soft_surfaces_definition_block, 1)
	{
		{ _field_pad, "CLASS_NONE", 4 },
		{ _field_real, "class biped#max - .2f" },
		{ _field_real, "class dead biped#max - .09f" },
		{ _field_real, "class crates + vehicles#max - .2f" },
		{ _field_real, "class debris#max - .04f" },
		{ _field_pad, "CLASS_ALL", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_soft_ceiling_triangle_block, k_maximum_structure_soft_ceiling_triangles)
	{
		{ _field_real_plane_3d, "plane!*" },
		{ _field_real_point_3d, "bounding sphere center!*" },
		{ _field_real, "bounding sphere radius!*" },
		{ _field_real_point_3d, "vertex0!*" },
		{ _field_real_point_3d, "vertex1!*" },
		{ _field_real_point_3d, "vertex2!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_soft_ceiling_block, k_maximum_structure_soft_ceilings_count)
	{
		{ _field_string_id, "name*!" },
		{ _field_enum, "type!*", &soft_ceiling_type_enum },
		{ _field_pad, "fresh", 2 },
		{ _field_block, "soft ceiling triangles!*", &structure_soft_ceiling_triangle_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_water_groups_block, k_maximum_structure_water_groups)
	{
		{ _field_string_id, "name*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_water_instance_planes_block, k_maximum_structure_water_instance_planes)
	{
		{ _field_real_plane_3d, "plane*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_water_instance_debug_triangles_block, k_maximum_structure_water_instance_debug_triangles)
	{
		{ _field_real_point_3d, "point0*!" },
		{ _field_real_point_3d, "point1*!" },
		{ _field_real_point_3d, "point2*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_water_instances_block, k_maximum_structure_water_instances)
	{
		{ _field_short_block_index, "group*!" },
		{ _field_pad, "PAD0", 2 },
		{ _field_real_vector_3d, "flow velocity*!" },
		{ _field_real_argb_color, "fog color*!" },
		{ _field_real, "fog murkiness*!" },
		{ _field_block, "water planes block!*", &structure_water_instance_planes_block_block },
		{ _field_block, "water debug triangles block!*", &structure_water_instance_debug_triangles_block_block },
		{ _field_real_bounds, "bounds x*" },
		{ _field_real_bounds, "bounds y*" },
		{ _field_real_bounds, "bounds z*" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_structure_physics_struct)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_block, "collision mopp code block!*", &mopp_code_definition_block_block },
		{ _field_real, "unknown@" },
		{ _field_real_point_3d, "collision world bounds min" },
		{ _field_real_point_3d, "collision world bounds max" },

		{ _field_block, "breakable surfaces mopp code block!*", &mopp_code_definition_block_block },
		{ _field_block, "breakable surfaace key table", &breakable_surface_key_table_block_block },

		{ _field_terminator }
	};

	TAG_STRUCT(global_structure_physics_design_struct)
	{
		{ _field_long_integer, "importer version*!" },
		{ _field_block, "soft ceiling mopp code block!*", &mopp_code_definition_block_block },
		{ _field_block, "soft ceilings block!*", &structure_soft_ceiling_block_block },
		{ _field_block, "water mopp code!*", &mopp_code_definition_block_block },
		{ _field_block, "water groups block!*", &structure_water_groups_block_block },
		{ _field_block, "water instances block!*", &structure_water_instances_block_block },
		{ _field_terminator }
	};

	STRINGS(soft_ceiling_type_enum)
	{
		"acceleration",
		"soft kill",
		"slip surface"
	};
	STRING_LIST(soft_ceiling_type_enum, soft_ceiling_type_enum_strings, _countof(soft_ceiling_type_enum_strings));

} // namespace blofeld

