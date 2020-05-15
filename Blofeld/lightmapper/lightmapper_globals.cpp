#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(lightmap_model_reference, SHORT_MAX)
{
	{ _field_tag_reference, "Model Reference" },
	{ _field_terminator },
};

TAG_GROUP(lightmap_model_globals, LIGHTMAP_MODEL_GLOBALS_TAG)
{
	{ _field_block, "Lightmapped Models", &lightmap_model_reference_block },
	{ _field_terminator },
};

TAG_GROUP(lightmapper_globals, LIGHTMAPPER_GLOBALS_TAG)
{
	{ _field_long_integer, "Version!" },
	{ _field_custom, "GLOBAL QUALITY SETTINGS" },
	{ _field_struct, "Global lightmapper settings" },
	{ _field_custom },
	{ _field_custom, "LOCAL SETTINGS" },
	{ _field_struct, "Local lightmapper settings" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

