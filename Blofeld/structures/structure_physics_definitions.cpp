#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(global_structure_physics_struct)
{
	FIELD( _field_block, "breakable surfaces mopp code block!*", &mopp_code_definition_block ),
	FIELD( _field_block, "breakable surfaace key table", &breakable_surface_key_table_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_structure_physics_design_struct)
{
	FIELD( _field_long_integer, "importer version*!" ),
	FIELD( _field_block, "soft ceiling mopp code block!*", &mopp_code_definition_block ),
	FIELD( _field_block, "soft ceilings block!*", &structure_soft_ceiling_block ),
	FIELD( _field_block, "water mopp code!*", &mopp_code_definition_block ),
	FIELD( _field_block, "water groups block!*", &structure_water_groups_block ),
	FIELD( _field_block, "water instances block!*", &structure_water_instances_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(breakable_surface_key_table_block, (SHORT_MAX))
{
	FIELD( _field_short_integer, "instanced geometry index!*" ),
	FIELD( _field_byte_integer, "breakable surface set index!*" ),
	FIELD( _field_byte_integer, "breakable surface index!*" ),
	FIELD( _field_long_integer, "seed surface index!*" ),
	FIELD( _field_real, "x0!*" ),
	FIELD( _field_real, "x1!*" ),
	FIELD( _field_real, "y0!*" ),
	FIELD( _field_real, "y1!*" ),
	FIELD( _field_real, "z0!*" ),
	FIELD( _field_real, "z1!*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(soft_surfaces_definition_block, 1)
{
	FIELD( _field_pad, "CLASS_NONE", 4 ),
	FIELD( _field_real, "class biped#max - .2f" ),
	FIELD( _field_real, "class dead biped#max - .09f" ),
	FIELD( _field_real, "class crates + vehicles#max - .2f" ),
	FIELD( _field_real, "class debris#max - .04f" ),
	FIELD( _field_pad, "CLASS_ALL", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_soft_ceiling_block, k_maximum_structure_soft_ceilings_count)
{
	FIELD( _field_string_id, "name*!" ),
	FIELD( _field_enum, "type!*" ),
	FIELD( _field_pad, "fresh", 2 ),
	FIELD( _field_block, "soft ceiling triangles!*", &structure_soft_ceiling_triangle_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_soft_ceiling_triangle_block, k_maximum_structure_soft_ceiling_triangles)
{
	FIELD( _field_real_plane_3d, "plane!*" ),
	FIELD( _field_real_point_3d, "bounding sphere center!*" ),
	FIELD( _field_real, "bounding sphere radius!*" ),
	FIELD( _field_real_point_3d, "vertex0!*" ),
	FIELD( _field_real_point_3d, "vertex1!*" ),
	FIELD( _field_real_point_3d, "vertex2!*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_water_groups_block, k_maximum_structure_water_groups)
{
	FIELD( _field_string_id, "name*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_water_instances_block, k_maximum_structure_water_instances)
{
	FIELD( _field_short_block_index, "group*!" ),
	FIELD( _field_pad, "PAD0", 2 ),
	FIELD( _field_real_vector_3d, "flow velocity*!" ),
	FIELD( _field_real_argb_color, "fog color*!" ),
	FIELD( _field_real, "fog murkiness*!" ),
	FIELD( _field_block, "water planes block!*", &structure_water_instance_planes_block ),
	FIELD( _field_block, "water debug triangles block!*", &structure_water_instance_debug_triangles_block ),
	FIELD( _field_real_bounds, "bounds x*" ),
	FIELD( _field_real_bounds, "bounds y*" ),
	FIELD( _field_real_bounds, "bounds z*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_water_instance_planes_block, k_maximum_structure_water_instance_planes)
{
	FIELD( _field_real_plane_3d, "plane*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_water_instance_debug_triangles_block, k_maximum_structure_water_instance_debug_triangles)
{
	FIELD( _field_real_point_3d, "point0*!" ),
	FIELD( _field_real_point_3d, "point1*!" ),
	FIELD( _field_real_point_3d, "point2*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

