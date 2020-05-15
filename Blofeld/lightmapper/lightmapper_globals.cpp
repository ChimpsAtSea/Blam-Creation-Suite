#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(lightmap_model_reference, SHORT_MAX)
{
	FIELD( _field_tag_reference, "Model Reference" ),
	FIELD( _field_terminator )
};

TAG_GROUP(lightmap_model_globals, LIGHTMAP_MODEL_GLOBALS_TAG)
{
	FIELD( _field_block, "Lightmapped Models", &lightmap_model_reference_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(lightmapper_globals, LIGHTMAPPER_GLOBALS_TAG)
{
	FIELD( _field_long_integer, "Version!" ),
	FIELD( _field_custom, "GLOBAL QUALITY SETTINGS" ),
	FIELD( _field_struct, "Global lightmapper settings" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "LOCAL SETTINGS" ),
	FIELD( _field_struct, "Local lightmapper settings" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

