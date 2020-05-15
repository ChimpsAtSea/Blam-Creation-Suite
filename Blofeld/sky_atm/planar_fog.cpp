#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(planar_fog_zone_set_visibility_definition, 1)
{
	{ _field_block, "structure visiblity*", &planar_fog_structure_visibility_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(planar_fog_structure_visibility_definition, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_block, "cluster visiblity*", &planar_fog_cluster_visibility_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(planar_fog_cluster_visibility_definition, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_block, "attached fogs*", &planar_fog_reference_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(planar_fog_reference_definition, k_short_max)
{
	{ _field_short_integer, "structure design index*" },
	{ _field_short_integer, "fog index*" },
	{ _field_terminator },
};

TAG_GROUP(planar_fog_parameters, PLANAR_FOG_PARAMETERS_TAG)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "ABCDadf", 2 },
	{ _field_real, "fog thickness [0.0 to 1.0]" },
	{ _field_real, "per-vertex fog thickness modulation:(only for transparents)" },
	{ _field_real, "full fog depth:world units" },
	{ _field_real_rgb_color, "fog color" },
	{ _field_real, "fog color intensity" },
	{ _field_tag_reference, "palette texture" },
	{ _field_custom, "patchy effect" },
	{ _field_tag_reference, "patchy texture" },
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
	{ _field_terminator },
};

} // namespace blofeld

