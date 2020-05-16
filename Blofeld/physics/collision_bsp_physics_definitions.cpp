#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(collision_geometry_shape_struct)
{
	FIELD( _field_struct, "base", &havok_shape_collection_struct_2010_2_struct_definition ),
	FIELD( _field_pad, "foobar666", 8 ),
	FIELD( _field_real_vector_3d, "center*" ),
	FIELD( _field_real, "havok w center*!" ),
	FIELD( _field_real_vector_3d, "half extent*" ),
	FIELD( _field_real, "havok w half extent*!" ),
	FIELD( _field_long_integer, "runtime model definition tag index!" ),
	FIELD( _field_long_integer, "collision bsp reference pointer0!~" ),
	FIELD( _field_long_integer, "collision bsp reference pointer1!~" ),
	FIELD( _field_char_integer, "structure_bsp_index!" ),
	FIELD( _field_char_integer, "collision geometry shape type!" ),
	FIELD( _field_short_integer, "instance index!" ),
	FIELD( _field_real, "scale!" ),
	FIELD( _field_pad, "3 long pad", 12 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(mopp_bv_tree_shape_struct)
{
	FIELD( _field_struct, "mopp bv tree shape", &havok_shape_struct_2010_2_struct_definition ),
	FIELD( _field_pad, "m_bvTreeType!~", 1 ),
	FIELD( _field_pad, "3 other bytes", 3 ),
	FIELD( _field_long_integer, "mopp code pointer!~" ),
	FIELD( _field_long_integer, "mopp data skip!~" ),
	FIELD( _field_long_integer, "mopp data size!~" ),
	FIELD( _field_real_vector_3d, "code info copy*" ),
	FIELD( _field_real, "havok w code info copy*!" ),
	FIELD( _field_long_integer, "child shape vtable*!~" ),
	FIELD( _field_long_integer, "child shape pointer!~" ),
	FIELD( _field_long_integer, "child size!~" ),
	FIELD( _field_pad, "mopp alignment*!~", 4 ),
	FIELD( _field_real, "mopp scale*" ),
	FIELD( _field_pad, "final pad", 12 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_bsp_physics_block, (1024))
{
	FIELD( _field_struct, "collision bsp shape", &collision_geometry_shape_struct_struct_definition ),
	FIELD( _field_struct, "mopp bv tree shap", &mopp_bv_tree_shape_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

