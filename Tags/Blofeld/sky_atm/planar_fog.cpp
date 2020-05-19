#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(planar_fog_parameters, PLANAR_FOG_PARAMETERS_TAG, planar_fog_parameters_block_block );

	TAG_BLOCK_FROM_STRUCT(planar_fog_parameters_block, 1, planar_fog_parameters_struct_definition_struct_definition );

	TAG_BLOCK(planar_fog_reference_definition_block, k_short_max)
	{
		{ _field_short_integer, "structure design index*" },
		{ _field_short_integer, "fog index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_cluster_visibility_definition_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		{ _field_block, "attached fogs*", &planar_fog_reference_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_structure_visibility_definition_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		{ _field_block, "cluster visiblity*", &planar_fog_cluster_visibility_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_zone_set_visibility_definition_block, 1)
	{
		{ _field_block, "structure visiblity*", &planar_fog_structure_visibility_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_vertex_block, s_planar_fog_definition::k_maximum_triangle_count*k_vertices_per_triangle_count)
	{
		{ _field_real_point_3d, "position*" },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_triangle_planes_block, s_planar_fog_definition::k_maximum_triangle_count)
	{
		{ _field_real_plane_3d, "plane*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_triangle_block, k_short_max)
	{
		{ _field_block, "planes*", &planar_fog_triangle_planes_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(planar_fog_definition_block, s_planer_fog_set_definition::k_maximum_planar_fog_count)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "appearance settings", &global_planar_fog_reference },
		{ _field_block, "vertices*", &planar_fog_vertex_block_block },
		{ _field_block, "triangles*", &planar_fog_triangle_block_block },
		{ _field_real, "depth*" },
		{ _field_real_vector_3d, "normal*" },
		{ _field_terminator }
	};

	TAG_STRUCT(planar_fog_parameters_struct_definition)
	{
		{ _field_word_flags, "flags", &planar_fog_flags },
		{ _field_pad, "ABCDadf", 2 },
		{ _field_real, "fog thickness [0.0 to 1.0]" },
		{ _field_real, "per-vertex fog thickness modulation:(only for transparents)" },
		{ _field_real, "full fog depth:world units" },
		{ _field_real_rgb_color, "fog color" },
		{ _field_real, "fog color intensity" },
		{ _field_tag_reference, "palette texture", &global_bitmap_reference },
		{ _field_custom, "patchy effect" },
		{ _field_tag_reference, "patchy texture", &global_bitmap_reference },
		{ _field_real_rgb_color, "patchy color" },
		{ _field_real, "patchy color intensity" },
		{ _field_real, "patchy texture tile size:world units" },
		{ _field_real, "patchy distance between sheets:world units" },
		{ _field_real, "patchy z-buffer fade factor" },
		{ _field_real, "patchy distance falloff start:world units" },
		{ _field_real, "patchy distance falloff power:world units" },
		{ _field_real, "patchy density" },
		{ _field_real, "patchy surface depth:world units" },
		{ _field_real, "patchy fade range:world units" },
		{ _field_real_vector_3d, "patchy wind direction:world units" },
		{ _field_custom },
		{ _field_custom, "LoD settings (N/A yet)" },
		{ _field_real, "max fog draw distance:world units" },
		{ _field_real, "patchy fade start distance:world units" },
		{ _field_real, "patchy fade end distance:world units" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(planar_fog_set_definition_struct)
	{
		{ _field_block, "planar fogs", &planar_fog_definition_block_block },
		{ _field_block, "mopp code*!", &mopp_code_definition_block_block },
		{ _field_terminator }
	};

	STRINGS(planar_fog_flags)
	{
		"enable patchy effect",
		"enable color palette",
		"enable alpha palette",
		"render only"
	};
	STRING_LIST(planar_fog_flags, planar_fog_flags_strings, _countof(planar_fog_flags_strings));

	TAG_REFERENCE(global_planar_fog_reference, PLANAR_FOG_PARAMETERS_TAG);

} // namespace blofeld

