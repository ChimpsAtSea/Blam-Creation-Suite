#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(planar_fog_parameters, PLANAR_FOG_PARAMETERS_TAG, planar_fog_parameters_block_block );

	TAG_BLOCK_FROM_STRUCT(planar_fog_parameters_block, 1, planar_fog_parameters_struct_definition_struct_definition );

	TAG_BLOCK(planar_fog_reference_definition_block, k_short_max)
	{
		FIELD( _field_short_integer, "structure design index*" ),
		FIELD( _field_short_integer, "fog index*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_cluster_visibility_definition_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_block, "attached fogs*", &planar_fog_reference_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_structure_visibility_definition_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_block, "cluster visiblity*", &planar_fog_cluster_visibility_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_zone_set_visibility_definition_block, 1)
	{
		FIELD( _field_block, "structure visiblity*", &planar_fog_structure_visibility_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_vertex_block, s_planar_fog_definition::k_maximum_triangle_count*k_vertices_per_triangle_count)
	{
		FIELD( _field_real_point_3d, "position*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_triangle_planes_block, s_planar_fog_definition::k_maximum_triangle_count)
	{
		FIELD( _field_real_plane_3d, "plane*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_triangle_block, k_short_max)
	{
		FIELD( _field_block, "planes*", &planar_fog_triangle_planes_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(planar_fog_definition_block, s_planer_fog_set_definition::k_maximum_planar_fog_count)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_tag_reference, "appearance settings" ),
		FIELD( _field_block, "vertices*", &planar_fog_vertex_block_block ),
		FIELD( _field_block, "triangles*", &planar_fog_triangle_block_block ),
		FIELD( _field_real, "depth*" ),
		FIELD( _field_real_vector_3d, "normal*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(planar_fog_parameters_struct_definition)
	{
		FIELD( _field_word_flags, "flags", &planar_fog_flags ),
		FIELD( _field_pad, "ABCDadf", 2 ),
		FIELD( _field_real, "fog thickness [0.0 to 1.0]" ),
		FIELD( _field_real, "per-vertex fog thickness modulation:(only for transparents)" ),
		FIELD( _field_real, "full fog depth:world units" ),
		FIELD( _field_real_rgb_color, "fog color" ),
		FIELD( _field_real, "fog color intensity" ),
		FIELD( _field_tag_reference, "palette texture" ),
		FIELD( _field_custom, "patchy effect" ),
		FIELD( _field_tag_reference, "patchy texture" ),
		FIELD( _field_real_rgb_color, "patchy color" ),
		FIELD( _field_real, "patchy color intensity" ),
		FIELD( _field_real, "patchy texture tile size:world units" ),
		FIELD( _field_real, "patchy distance between sheets:world units" ),
		FIELD( _field_real, "patchy z-buffer fade factor" ),
		FIELD( _field_real, "patchy distance falloff start:world units" ),
		FIELD( _field_real, "patchy distance falloff power:world units" ),
		FIELD( _field_real, "patchy density" ),
		FIELD( _field_real, "patchy surface depth:world units" ),
		FIELD( _field_real, "patchy fade range:world units" ),
		FIELD( _field_real_vector_3d, "patchy wind direction:world units" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "LoD settings (N/A yet)" ),
		FIELD( _field_real, "max fog draw distance:world units" ),
		FIELD( _field_real, "patchy fade start distance:world units" ),
		FIELD( _field_real, "patchy fade end distance:world units" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(planar_fog_set_definition_struct)
	{
		FIELD( _field_block, "planar fogs", &planar_fog_definition_block_block ),
		FIELD( _field_block, "mopp code*!", &mopp_code_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(planar_fog_flags, 4)
	{
		OPTION("enable patchy effect"),
		OPTION("enable color palette"),
		OPTION("enable alpha palette"),
		OPTION("render only"),
	};

} // namespace blofeld

