#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SPAWNSETTINGS_TAG = 'ssdf';
	extern s_tag_group SpawnSettings_group; // SpawnSettings_block


	extern s_tag_block_definition SpawnSettings_block;
	extern s_tag_block_definition influencerSpawnSettingsBlock_block;
	extern s_tag_struct_definition influencerSpawnSettingsBlock_block_struct_definition; // influencerSpawnSettingsBlock_block
	extern s_tag_block_definition weaponSpawnInfluenceBlock_block;
	extern s_tag_struct_definition weaponSpawnInfluenceBlock_block_struct_definition; // weaponSpawnInfluenceBlock_block
	extern s_tag_block_definition vehicleSpawnInfluenceBlock_block;
	extern s_tag_struct_definition vehicleSpawnInfluenceBlock_block_struct_definition; // vehicleSpawnInfluenceBlock_block
	extern s_tag_block_definition projectileSpawnInfluenceBlock_block;
	extern s_tag_struct_definition projectileSpawnInfluenceBlock_block_struct_definition; // projectileSpawnInfluenceBlock_block
	extern s_tag_block_definition equipmentSpawnInfluenceBlock_block;
	extern s_tag_struct_definition equipmentSpawnInfluenceBlock_block_struct_definition; // equipmentSpawnInfluenceBlock_block

	extern s_tag_struct_definition SpawnSettings_struct_definition; // tag group

	extern c_versioned_string_list InfluencerSpawnSettingsFlagsDefinition_strings;
	extern s_string_list_definition InfluencerSpawnSettingsFlagsDefinition;
	extern c_versioned_string_list SpawnSettingsFlagsDefinition_strings;
	extern s_string_list_definition SpawnSettingsFlagsDefinition;

	extern s_tag_reference_definition g_spawnSettingsReference;

} // namespace macaque

} // namespace blofeld

