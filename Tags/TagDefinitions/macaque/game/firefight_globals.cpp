#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define FIREFIGHT_GLOBALS_STRUCT_DEFINITION_ID { 0xEA3163B8, 0xA323445B, 0x94142215, 0x9CA868DD }
	TAG_BLOCK(
		firefight_globals_block,
		"firefight_globals_block",
		1,
		"FirefightGlobalsDefinition",
		FIREFIGHT_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "wave templates", &firefightWaveTemplatesBlock_block },
		{ _field_tag_reference, "co-op spawning", &global_coop_spawning_globals_reference },
		{ _field_explanation, "PLAYER SPAWN INFLUENCERS", "These are the default spawn influencer settings which can be overridden by scenario tags" },
		{ _field_tag_reference, "Influencer default spawn settings", &g_spawnSettingsReference },
		{ _field_terminator }
	};

	TAG_GROUP(
		firefight_globals_group,
		FIREFIGHT_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		firefight_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		firefightWaveTemplatesBlock_block,
		"firefightWaveTemplatesBlock",
		FirefightWaveTemplateDefinition::k_maximumAIWaveTemplates,
		firefightWaveTemplatesBlock_struct);

	#define FIREFIGHTWAVETEMPLATESBLOCK_STRUCT_ID { 0x0B9922FA, 0x1881452F, 0xB4D24003, 0x5C0B4463 }
	TAG_STRUCT(
		firefightWaveTemplatesBlock_struct,
		"firefightWaveTemplatesBlock_struct",
		"FirefightWaveTemplateDefinition",
		FIREFIGHTWAVETEMPLATESBLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "wave template", &wave_template_reference },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

