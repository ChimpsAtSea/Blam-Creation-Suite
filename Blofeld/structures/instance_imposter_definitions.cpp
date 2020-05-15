#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(instance_imposter, k_maximum_instance_geometry_instances_per_structure_bsp)
{
	{ _field_short_integer, "group index" },
	{ _field_char_integer, "subpart_index" },
	{ _field_byte_flags, "flags" },
	{ _field_terminator },
};

TAG_BLOCK(instance_imposter_checksum, k_maximum_instance_geometry_instances_per_structure_bsp)
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
	{ _field_terminator },
};

TAG_GROUP(instance_imposter_definition, INSTANCE_IMPOSTER_DEFINITION_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "bsp name" },
	{ _field_long_integer, "checksum" },
	{ _field_string_id, "source metadata path" },
	{ _field_block, "instances", &instance_imposter_block },
	{ _field_block, "instance checksums", &instance_imposter_checksum_block },
	{ _field_custom, "atlas info" },
	{ _field_short_integer, "atlas tile resolution" },
	{ _field_char_integer, "atlas x tile count" },
	{ _field_char_integer, "atlas y tile count" },
	{ _field_tag_reference, "atlas texture" },
	{ _field_custom },
	{ _field_custom, "mesh data" },
	{ _field_struct, "render geometry" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

