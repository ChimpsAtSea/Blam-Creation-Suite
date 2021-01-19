#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(SpawnSettings, SPAWNSETTINGS_TAG, SpawnSettings_block_block );

	V5_TAG_BLOCK(influencerSpawnSettingsBlock, k_spawn_influencer_type_count)
	{
		{ _field_long_flags, "Flags", &InfluencerSpawnSettingsFlagsDefinition },
		{ _field_real, "Minimum Influence:Only used if \'Pin\' flag is set" },
		{ _field_real, "Maximum Influence:Only used if \'Pin\' flag is set" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(weaponSpawnInfluenceBlock, 48)
	{
		{ _field_tag_reference, "weapon", &weapon_reference$9 },
		{ _field_real, "full weight range:wu" },
		{ _field_real, "fall-off range:wu" },
		{ _field_real, "fall-off cone radius:wu" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(vehicleSpawnInfluenceBlock, k_vehicle_spawn_influencer_maximum_count)
	{
		{ _field_tag_reference, "vehicle", &vehicle_reference$4 },
		{ _field_real, "box width:wu" },
		{ _field_real, "box min height:wu#How far influencer will extend below unit\'s origin.  Will usually be negative.  (If min and max are both 0, unit radius is used)" },
		{ _field_real, "box max height:wu#How far influencer will extend above unit\'s origin.  Will usually be positive.  (If min and max are both 0, unit radius is used)" },
		{ _field_real, "lead time:seconds" },
		{ _field_real, "minimum velocity:wu/sec" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(projectileSpawnInfluenceBlock, k_projectile_spawn_influencer_maximum_count)
	{
		{ _field_tag_reference, "projectile", &projectile_reference$3 },
		{ _field_real, "lead time:seconds" },
		{ _field_real, "collision cylinder radius:wu" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(equipmentSpawnInfluenceBlock, k_equipment_spawn_influencer_maximum_count)
	{
		{ _field_tag_reference, "equipment", &equipment_reference$5 },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(SpawnSettings_block, 1, SpawnSettings_struct_definition_struct_definition );

	V5_TAG_STRUCT(SpawnSettings_struct_definition)
	{
		{ _field_real, "minimum spawn time:seconds#Absolute floor.  Used to put a few-frame delay between death and instaspawn.  Will not override longer minimum times." },
		{ _field_real, "min acceptable spawn score#spawns with a score lower than this will never be used" },
		{ _field_explanation, "Spawn Randomization", "Values that affect randomization of respawn point selection\nRuntime will use the largest of \'% best weight to use\' and \'Min absolute weight range\'" },
		{ _field_real, "maximum random spawn bias:0 disables#Controls how large of a random value gets added to each spawn point" },
		{ _field_real_fraction, "% num spawn points to use:0 uses only best point#Example -\nOn a map with 140 respawn points, a value of 0.1 here\nwill choose randomly between up to the best 14 points.\nNumber of points considered is also limited by the following parameters and flags.\nIf next two parameters are 0, only points with the exact same weight as the highest\nscoring respawn point will be considered.  If \'Min absolute weight range\' is 25 then\nthe best \'X\' points within 25 points of the highest scoring point will be considered." },
		{ _field_real_fraction, "% best weight to use:0 disables#Example -\nValue of 0.25 will consider all points with weight within 25% of the highest scoring point.\nNote - At run-time, the larger of \'% best weight to use\' and \'Min absolute weight range\' will be used.\nFor instance if \'% best weight\' is 0.1 and \'Min absolute weight\' is 5.0\' a max weight\nof 150 will use 15, but a max weight of 10 will fall back on the min weight of 5" },
		{ _field_real, "Min absolute weight range:0 disables#Example -\nValue of 50 will consider all points within 50 of the highest scoring point.\nNote - At run-time, the larger of \'% best weight to use\' and \'Min absolute weight range\' will be used.\n" },
		{ _field_long_flags, "Flags", &SpawnSettingsFlagsDefinition },
		{ _field_explanation, "Spawn Settings", "block index 0: influencer - Enemy Forbid\nblock index 1: influencer - Enemy Bias\nblock index 2: influencer - Ally Bias\nblock index 3: influencer - Selected Ally Bias\nblock index 4: influencer - Dead Teammate\nblock index 5: influencer - Respawn Zone\nblock index 6: influencer - Weapon\nblock index 7: influencer - Vehicle\nblock index 8: influencer - Projectile\nblock index 9: influencer - Equipment\nblock index 10: influencer - Fireteam 1 zone\nblock index 11: influencer - Fireteam 2 zone\nblock index 12: influencer - Fireteam 3 zone\nblock index 13: influencer - Fireteam 4 zone\nblock index 14: influencer - Drop Pod\nblock index 15: influencer - Auto Turret\n" },
		{ _field_block, "Spawn Settings", &influencerSpawnSettingsBlock_block },
		{ _field_explanation, "ENEMY FORBID", "This is a tight cylinder around the player with a strong negative weight. It serves to protect players from spawning close to an enemy, or having and enemy spawn close to them." },
		{ _field_real, "ef full weight radius:wu" },
		{ _field_real, "ef fall-off radius:wu" },
		{ _field_block, "ef falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "ef upper height:wu" },
		{ _field_real, "ef lower height:wu" },
		{ _field_real, "ef weight" },
		{ _field_explanation, "ENEMY BIAS", "This is a larger cylinder, with a size set specifically for the size of the map. It has a weak negative weight which falls to zero towards the outer radius. It serves to bias players away from spawning near enemies, or in enemy held areas." },
		{ _field_real, "eb full weight radius:wu" },
		{ _field_real, "eb fall-off radius:wu" },
		{ _field_block, "eb falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "eb upper height:wu" },
		{ _field_real, "eb lower height:wu" },
		{ _field_real, "eb weight" },
		{ _field_explanation, "ALLY BIAS", "This is a larger cylinder, with a size set specifically for the size of the map. It has a weak positive weight which falls to zero towards the outer radius. It serves to bias players towards spawning with allies, or in areas which are controlled by friendly players." },
		{ _field_real, "ab full weight radius:wu" },
		{ _field_real, "ab fall-off radius:wu" },
		{ _field_block, "ab falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "ab upper height:wu" },
		{ _field_real, "ab lower height:wu" },
		{ _field_real, "ab weight" },
		{ _field_explanation, "SELECTED ALLY BIAS", "Same as ALLY BIAS, but used when the ally is selected in the dead-camera." },
		{ _field_real, "sab full weight radius:wu" },
		{ _field_real, "sab fall-off radius:wu" },
		{ _field_block, "sab falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "sab upper height:wu" },
		{ _field_real, "sab lower height:wu" },
		{ _field_real, "sab weight" },
		{ _field_explanation, "DEAD TEAMMATE BIAS", "Dead teammate influences are cylinders centered upon the body of a dead teammate (or the player’s own dead body)." },
		{ _field_real, "dt full weight radius:wu" },
		{ _field_real, "dt fall-off radius:wu" },
		{ _field_block, "dt falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "dt upper height:wu" },
		{ _field_real, "dt lower height:wu" },
		{ _field_real, "dt weight" },
		{ _field_real, "dead teammate influence duration:seconds" },

		{ _field_version_less, _engine_type_groundhog, 7 },
		{ _field_explanation, "DROP POD BIAS", "Drop pods influences are cylinders centered on unclaimed ordnance." },
		{ _field_real, "Drop Pod full weight radius:wu" },
		{ _field_real, "Drop Pod fall-off radius:wu" },
		{ _field_block, "Drop Pod falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "Drop Pod upper height:wu" },
		{ _field_real, "Drop Pod lower height:wu" },
		{ _field_real, "Drop Pod weight" },

		{ _field_version_less, _engine_type_groundhog, 7 },
		{ _field_explanation, "PLAYER AUTO TURRET BIAS", "Auto Turret influences are cylinders centered on players\' auto turrets." },
		{ _field_real, "Auto Turret full weight radius:wu" },
		{ _field_real, "Auto Turret fall-off radius:wu" },
		{ _field_block, "Auto Turret falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "Auto Turret upper height:wu" },
		{ _field_real, "Auto Turret lower height:wu" },
		{ _field_real, "Auto Turret weight" },

		{ _field_version_equal, _engine_type_groundhog, 8 },
		{ _field_explanation, "UNKNOWN BIAS" },
		{ _field_real, "@unknown full weight radius:wu" },
		{ _field_real, "@unknown fall-off radius:wu" },
		{ _field_block, "@unknown falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_real, "@unknown upper height:wu" },
		{ _field_real, "@unknown lower height:wu" },
		{ _field_real, "@unknown weight" },
		{ _field_real, "@unknown" },

		{ _field_explanation, "WEAPON INFLUENCERS", "These influencers are induced by weapons either weilded or carried in the player\'s backpack" },
		{ _field_block, "weapon influencers", &weaponSpawnInfluenceBlock_block },
		{ _field_explanation, "VEHICLE INFLUENCERS", "These influencers are induced by vehicles." },
		{ _field_block, "vehicle influencers", &vehicleSpawnInfluenceBlock_block },
		{ _field_explanation, "PROJECTILE INFLUENCERS", "These influencers are induced by projectiles." },
		{ _field_block, "projectile influencers", &projectileSpawnInfluenceBlock_block },
		{ _field_explanation, "EQUIPMENT INFLUENCERS", "These influencers are induced by equipment." },
		{ _field_block, "equipment influencers", &equipmentSpawnInfluenceBlock_block },
		{ _field_terminator }
	};

	STRINGS(InfluencerSpawnSettingsFlagsDefinition)
	{
		"Only use largest influence",
		"Pin influence to Minimum and Maximum"
	};
	STRING_LIST(InfluencerSpawnSettingsFlagsDefinition, InfluencerSpawnSettingsFlagsDefinition_strings, _countof(InfluencerSpawnSettingsFlagsDefinition_strings));

	STRINGS(SpawnSettingsFlagsDefinition)
	{
		"Allow negative weights in randomization#If checked, negative weighted respawn points are treated the same as ones with positive weight.\nIf not checked, negative respawn points aren\'t grouped with positive weighted respawn points."
	};
	STRING_LIST(SpawnSettingsFlagsDefinition, SpawnSettingsFlagsDefinition_strings, _countof(SpawnSettingsFlagsDefinition_strings));

	TAG_REFERENCE(g_spawnSettingsReference, SPAWNSETTINGS_TAG);

} // namespace blofeld

