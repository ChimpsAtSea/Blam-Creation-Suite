#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(firefightWaveTemplatesBlock, FirefightWaveTemplateDefinition::k_maximumAIWaveTemplates)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "wave template" },
	{ _field_terminator },
};

TAG_GROUP(firefight_globals, FIREFIGHT_GLOBALS_TAG)
{
	{ _field_block, "wave templates", &firefightWaveTemplatesBlock_block },
	{ _field_tag_reference, "co-op spawning" },
	{ _field_explanation, "PLAYER SPAWN INFLUENCERS" },
	{ _field_tag_reference, "Influencer default spawn settings" },
	{ _field_terminator },
};

} // namespace blofeld

