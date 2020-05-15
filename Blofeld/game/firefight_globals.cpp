#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(firefightWaveTemplatesBlock, FirefightWaveTemplateDefinition::k_maximumAIWaveTemplates)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "wave template" ),
	FIELD( _field_terminator )
};

TAG_GROUP(firefight_globals, FIREFIGHT_GLOBALS_TAG)
{
	FIELD( _field_block, "wave templates", &firefightWaveTemplatesBlock_block ),
	FIELD( _field_tag_reference, "co-op spawning" ),
	FIELD( _field_explanation, "PLAYER SPAWN INFLUENCERS" ),
	FIELD( _field_tag_reference, "Influencer default spawn settings" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

