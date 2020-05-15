#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(planar_fog_zone_set_visibility_definition, 1)
{
	FIELD( _field_block, "structure visiblity*", &planar_fog_structure_visibility_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(planar_fog_structure_visibility_definition, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	FIELD( _field_block, "cluster visiblity*", &planar_fog_cluster_visibility_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(planar_fog_cluster_visibility_definition, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	FIELD( _field_block, "attached fogs*", &planar_fog_reference_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(planar_fog_reference_definition, k_short_max)
{
	FIELD( _field_short_integer, "structure design index*" ),
	FIELD( _field_short_integer, "fog index*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(planar_fog_parameters, PLANAR_FOG_PARAMETERS_TAG)
{
	FIELD( _field_word_flags, "flags" ),
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

} // namespace blofeld

