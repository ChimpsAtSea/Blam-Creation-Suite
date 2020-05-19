#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(instance_imposter_definition, INSTANCE_IMPOSTER_DEFINITION_TAG, instance_imposter_definition_block_block );

	TAG_BLOCK(instance_imposter_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		{ _field_short_integer, "group index" },
		{ _field_char_integer, "subpart_index" },
		{ _field_byte_flags, "flags", &instance_imposter_element_flags_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(instance_imposter_checksum_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		{ _field_string_id, "name" },
		{ _field_long_integer, "import checksum" },
		{ _field_long_integer, "transform checksum" },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_integer, "imposter version" },
		{ _field_char_integer, "imposter policy" },
		{ _field_pad, "padefefrdapad", 1 },
		{ _field_real, "bounding radius" },
		{ _field_real, "transition distance" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(instance_imposter_definition_block, 1, instance_imposter_definition_struct_definition_struct_definition );

	TAG_STRUCT(instance_imposter_definition_struct_definition)
	{
		{ _field_long_flags, "flags", &instance_imposter_flags_definition },
		{ _field_string_id, "bsp name" },
		{ _field_long_integer, "checksum" },
		{ _field_string_id, "source metadata path" },
		{ _field_block, "instances", &instance_imposter_block_block },
		{ _field_block, "instance checksums", &instance_imposter_checksum_block_block },
		{ _field_custom, "atlas info" },
		{ _field_short_integer, "atlas tile resolution" },
		{ _field_char_integer, "atlas x tile count" },
		{ _field_char_integer, "atlas y tile count" },
		{ _field_tag_reference, "atlas texture", &global_bitmap_reference },
		{ _field_custom },
		{ _field_custom, "mesh data" },
		{ _field_struct, "render geometry", &global_render_geometry_struct_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	STRINGS(instance_imposter_flags_definition)
	{
		"raw geometry compressed",
		"use raw instance imposter verts",
		"valid and good to go",
		"build completed"
	};
	STRING_LIST(instance_imposter_flags_definition, instance_imposter_flags_definition_strings, _countof(instance_imposter_flags_definition_strings));

	STRINGS(instance_imposter_element_flags_definition)
	{
		"card",
		"poly",
		"rainbow box",
		"occlusion"
	};
	STRING_LIST(instance_imposter_element_flags_definition, instance_imposter_element_flags_definition_strings, _countof(instance_imposter_element_flags_definition_strings));

	TAG_REFERENCE(global_instance_imposter_reference, INSTANCE_IMPOSTER_DEFINITION_TAG);

} // namespace blofeld

