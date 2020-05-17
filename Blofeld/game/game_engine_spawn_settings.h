#pragma once

namespace blofeld
{

	extern const char* InfluencerSpawnSettingsFlagsDefinition_strings[];
	extern s_string_list_definition InfluencerSpawnSettingsFlagsDefinition;
	extern const char* SpawnSettingsFlagsDefinition_strings[];
	extern s_string_list_definition SpawnSettingsFlagsDefinition;

	constexpr unsigned long SPAWNSETTINGS_TAG = 'ssdf';

	extern s_tag_group SpawnSettings_group;

	extern s_tag_block_definition SpawnSettings_block_block;
	extern s_tag_struct influencerSpawnSettingsBlock_block_struct;
	extern s_tag_block_definition influencerSpawnSettingsBlock_block;
	extern s_tag_struct weaponSpawnInfluenceBlock_block_struct;
	extern s_tag_block_definition weaponSpawnInfluenceBlock_block;
	extern s_tag_struct vehicleSpawnInfluenceBlock_block_struct;
	extern s_tag_block_definition vehicleSpawnInfluenceBlock_block;
	extern s_tag_struct projectileSpawnInfluenceBlock_block_struct;
	extern s_tag_block_definition projectileSpawnInfluenceBlock_block;
	extern s_tag_struct equipmentSpawnInfluenceBlock_block_struct;
	extern s_tag_block_definition equipmentSpawnInfluenceBlock_block;

	extern s_tag_struct SpawnSettings_struct_definition_struct_definition; // tag group

} // namespace blofeld

