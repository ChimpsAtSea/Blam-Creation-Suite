#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(collision_bsp_physics_block, (1024))
	{
		{ _field_legacy, _field_struct, "collision bsp shape", &collision_geometry_shape_struct_struct_definition },
		{ _field_legacy, _field_struct, "mopp bv tree shap", &mopp_bv_tree_shape_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(collision_geometry_shape_struct)
	{
		{ _field_legacy, _field_struct, "base", &havok_shape_collection_struct_2010_2_struct_definition },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		{ _field_legacy, _field_pad, "foobar666", 8 },

		{ _field_legacy, _field_real_vector_3d, "center*" },
		{ _field_legacy, _field_real, "havok w center*!" },
		{ _field_legacy, _field_real_vector_3d, "half extent*" },
		{ _field_legacy, _field_real, "havok w half extent*!" },
		{ _field_legacy, _field_long_integer, "runtime model definition tag index!" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_legacy, _field_pointer, "collision bsp reference pointer0!~" },
		{ _field_legacy, _field_pointer, "collision bsp reference pointer1!~" },
		{ _field_legacy, _field_char_integer, "structure_bsp_index!" },
		{ _field_legacy, _field_char_integer, "collision geometry shape type!" },
		{ _field_legacy, _field_short_integer, "instance index!" },

		{ _field_legacy, _field_real, "scale!" },
		{ _field_legacy, _field_pad, "3 long pad", 12 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(mopp_bv_tree_shape_struct) // #NOTE: same as mopps_block
	{
		{ _field_legacy, _field_struct, "mopp bv tree shape", &havok_shape_struct_2010_2_struct_definition },
		{ _field_legacy, _field_pad, "m_bvTreeType!~", 1 },
		{ _field_legacy, _field_pad, "3 other bytes", 3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		// hkMoppBvTreeShapeBase
		{ _field_legacy, _field_pointer, "mopp code pointer!~" },
		{ _field_legacy, _field_pointer, "mopp data skip!~" },
		{ _field_legacy, _field_long_integer, "mopp data size!~" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_legacy, _field_real_vector_3d, "code info copy*" },
		{ _field_legacy, _field_real, "havok w code info copy*!" },

		// hkpSingleShapeContainer
		{ _field_legacy, _field_pointer, "child shape vtable*!~" },
		{ _field_legacy, _field_pointer, "child shape pointer!~" },
		{ _field_legacy, _field_long_integer, "child size!~" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_legacy, _field_pad, "mopp alignment*!~", 4 },
		{ _field_legacy, _field_real, "mopp scale*" }, 
		
		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "final pad", 16 },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		{ _field_legacy, _field_pad, "final pad", 12 },

		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

