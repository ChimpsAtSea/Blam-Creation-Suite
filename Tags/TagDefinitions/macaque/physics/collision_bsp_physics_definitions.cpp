#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define COLLISION_BSP_PHYSICS_BLOCK_ID { 0x5B8E7B3A, 0xC8394498, 0xB6AE249F, 0x4C00F83F }
	TAG_BLOCK(
		collision_bsp_physics_block,
		"collision_bsp_physics_block",
		(1024),
		"s_collision_bsp_physics_definition",
		COLLISION_BSP_PHYSICS_BLOCK_ID,
		4)
	{
		{ _field_struct, "collision bsp shape", &collision_geometry_shape_struct },
		{ _field_struct, "mopp bv tree shap", &mopp_bv_tree_shape_struct },
		{ _field_terminator }
	};

	#define COLLISION_GEOMETRY_SHAPE_STRUCT_ID { 0x97B622E0, 0xF8AF48BA, 0x85446709, 0x0386FA88 }
	TAG_STRUCT(
		collision_geometry_shape_struct,
		"collision_geometry_shape_struct",
		"c_collision_geometry_shape",
		COLLISION_GEOMETRY_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_shape_collection_struct_2010_2 },
		{ _field_pad, "foobar666", 8 },
		{ _field_real_vector_3d, "center*" },
		{ _field_real, "havok w center*!" },
		{ _field_real_vector_3d, "half extent*" },
		{ _field_real, "havok w half extent*!" },
		{ _field_long_integer, "runtime model definition tag index!" },
		{ _field_long_integer, "collision bsp reference pointer0!~", nullptr, 'nuke' },
		{ _field_long_integer, "collision bsp reference pointer1!~", nullptr, 'nuke' },
		{ _field_char_integer, "structure_bsp_index!" },
		{ _field_char_integer, "collision geometry shape type!" },
		{ _field_short_integer, "instance index!" },
		{ _field_real, "scale!" },
		{ _field_pad, "3 long pad", 12 },
		{ _field_terminator }
	};

	#define MOPP_BV_TREE_SHAPE_STRUCT_ID { 0x662B38A4, 0xAAAC448C, 0x81C491AB, 0xA4E2A6EE }
	TAG_STRUCT(
		mopp_bv_tree_shape_struct,
		"mopp_bv_tree_shape_struct",
		"c_mopp_bv_tree_shape",
		MOPP_BV_TREE_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "mopp bv tree shape", &havok_shape_struct_2010_2 },
		{ _field_pad, "m_bvTreeType!~", 1 },
		{ _field_pad, "3 other bytes", 3 },
		{ _field_long_integer, "mopp code pointer!~", nullptr, 'nuke' },
		{ _field_long_integer, "mopp data skip!~", nullptr, 'nuke' },
		{ _field_long_integer, "mopp data size!~" },
		{ _field_real_vector_3d, "code info copy*" },
		{ _field_real, "havok w code info copy*!" },
		{ _field_long_integer, "child shape vtable*!~", nullptr, 'nuke' },
		{ _field_long_integer, "child shape pointer!~", nullptr, 'nuke' },
		{ _field_long_integer, "child size!~" },
		{ _field_pad, "mopp alignment*!~", 4 },
		{ _field_real, "mopp scale*" },
		{ _field_pad, "final pad", 12 },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

