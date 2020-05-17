#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(instance_imposter_definition, INSTANCE_IMPOSTER_DEFINITION_TAG, instance_imposter_definition_block_block );

	TAG_BLOCK(instance_imposter_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		FIELD( _field_short_integer, "group index" ),
		FIELD( _field_char_integer, "subpart_index" ),
		FIELD( _field_byte_flags, "flags", &instance_imposter_element_flags_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(instance_imposter_checksum_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_long_integer, "import checksum" ),
		FIELD( _field_long_integer, "transform checksum" ),
		FIELD( _field_real, "scale" ),
		FIELD( _field_real_vector_3d, "forward" ),
		FIELD( _field_real_vector_3d, "left" ),
		FIELD( _field_real_vector_3d, "up" ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_short_integer, "imposter version" ),
		FIELD( _field_char_integer, "imposter policy" ),
		FIELD( _field_pad, "padefefrdapad", 1 ),
		FIELD( _field_real, "bounding radius" ),
		FIELD( _field_real, "transition distance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(instance_imposter_definition_block, 1, instance_imposter_definition_struct_definition_struct_definition );

	TAG_STRUCT(instance_imposter_definition_struct_definition)
	{
		FIELD( _field_long_flags, "flags", &instance_imposter_flags_definition ),
		FIELD( _field_string_id, "bsp name" ),
		FIELD( _field_long_integer, "checksum" ),
		FIELD( _field_string_id, "source metadata path" ),
		FIELD( _field_block, "instances", &instance_imposter_block_block ),
		FIELD( _field_block, "instance checksums", &instance_imposter_checksum_block_block ),
		FIELD( _field_custom, "atlas info" ),
		FIELD( _field_short_integer, "atlas tile resolution" ),
		FIELD( _field_char_integer, "atlas x tile count" ),
		FIELD( _field_char_integer, "atlas y tile count" ),
		FIELD( _field_tag_reference, "atlas texture" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "mesh data" ),
		FIELD( _field_struct, "render geometry", &global_render_geometry_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(instance_imposter_flags_definition, 4)
	{
		OPTION("raw geometry compressed"),
		OPTION("use raw instance imposter verts"),
		OPTION("valid and good to go"),
		OPTION("build completed"),
	};

	TAG_ENUM(instance_imposter_element_flags_definition, 4)
	{
		OPTION("card"),
		OPTION("poly"),
		OPTION("rainbow box"),
		OPTION("occlusion"),
	};

} // namespace blofeld

