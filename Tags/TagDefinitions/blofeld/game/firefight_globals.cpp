#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(firefight_globals, FIREFIGHT_GLOBALS_TAG)
	{
		{ _field_legacy, _field_block, "wave templates", &firefightWaveTemplatesBlock_block },
		{ _field_legacy, _field_tag_reference, "co-op spawning", &global_coop_spawning_globals_reference },
		{ _field_legacy, _field_explanation, "PLAYER SPAWN INFLUENCERS", "These are the default spawn influencer settings which can be overridden by scenario tags" },
		{ _field_legacy, _field_tag_reference, "Influencer default spawn settings", &g_spawnSettingsReference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(firefightWaveTemplatesBlock, FirefightWaveTemplateDefinition::k_maximumAIWaveTemplates, firefightWaveTemplatesBlock_struct_struct_definition );

	V5_TAG_STRUCT(firefightWaveTemplatesBlock_struct)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_tag_reference, "wave template", &wave_template_reference },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

