#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(influencerSpawnSettingsBlock, k_spawn_influencer_type_count)
{
	{ _field_long_flags, "Flags" },
	{ _field_real, "Minimum Influence:Only used if \'Pin\' flag is set" },
	{ _field_real, "Maximum Influence:Only used if \'Pin\' flag is set" },
	{ _field_terminator },
};

TAG_BLOCK(weaponSpawnInfluenceBlock, 48)
{
	{ _field_tag_reference, "weapon" },
	{ _field_real, "full weight range:wu" },
	{ _field_real, "fall-off range:wu" },
	{ _field_real, "fall-off cone radius:wu" },
	{ _field_real, "weight" },
	{ _field_terminator },
};

TAG_BLOCK(vehicleSpawnInfluenceBlock, k_vehicle_spawn_influencer_maximum_count)
{
	{ _field_tag_reference, "vehicle" },
	{ _field_real, "box width:wu" },
	{ _field_real, "box min height:wu#How far influencer will extend below unit\'s origin.  Will usually be negative.  (If min and max are both 0, unit radius is used)" },
	{ _field_real, "box max height:wu#How far influencer will extend above unit\'s origin.  Will usually be positive.  (If min and max are both 0, unit radius is used)" },
	{ _field_real, "lead time:seconds" },
	{ _field_real, "minimum velocity:wu/sec" },
	{ _field_real, "weight" },
	{ _field_terminator },
};

TAG_BLOCK(projectileSpawnInfluenceBlock, k_projectile_spawn_influencer_maximum_count)
{
	{ _field_tag_reference, "projectile" },
	{ _field_real, "lead time:seconds" },
	{ _field_real, "collision cylinder radius:wu" },
	{ _field_real, "weight" },
	{ _field_terminator },
};

TAG_BLOCK(equipmentSpawnInfluenceBlock, k_equipment_spawn_influencer_maximum_count)
{
	{ _field_tag_reference, "equipment" },
	{ _field_real, "weight" },
	{ _field_terminator },
};

TAG_GROUP(SpawnSettings, SPAWNSETTINGS_TAG)
{
	{ _field_real, "minimum spawn time:seconds#Absolute floor.  Used to put a few-frame delay between death and instaspawn.  Will not override longer minimum times." },
	{ _field_real, "min acceptable spawn score#spawns with a score lower than this will never be used" },
	{ _field_explanation, "Spawn Randomization" },
	{ _field_real, "maximum random spawn bias:0 disables#Controls how large of a random value gets added to each spawn point" },
	{ _field_real_fraction, "% num spawn points to use:0 uses only best point#Example -\nOn a map with 140 respawn points, a value of 0.1 here\nwill choose randomly between up to the best 14 points.\nNumber of points considered is also limited by the following parameters and flags.\nIf next two parameters are 0, only points with the exact same weight as the highest\nscoring respawn point will be considered.  If \'Min absolute weight range\' is 25 then\nthe best \'X\' points within 25 points of the highest scoring point will be considered." },
	{ _field_real_fraction, "% best weight to use:0 disables#Example -\nValue of 0.25 will consider all points with weight within 25% of the highest scoring point.\nNote - At run-time, the larger of \'% best weight to use\' and \'Min absolute weight range\' will be used.\nFor instance if \'% best weight\' is 0.1 and \'Min absolute weight\' is 5.0\' a max weight\nof 150 will use 15, but a max weight of 10 will fall back on the min weight of 5" },
	{ _field_real, "Min absolute weight range:0 disables#Example -\nValue of 50 will consider all points within 50 of the highest scoring point.\nNote - At run-time, the larger of \'% best weight to use\' and \'Min absolute weight range\' will be used.\n" },
	{ _field_long_flags, "Flags" },
	{ _field_explanation, "Spawn Settings" },
	{ _field_block, "Spawn Settings", &influencerSpawnSettingsBlock_block },
	{ _field_explanation, "ENEMY FORBID" },
	{ _field_real, "ef full weight radius:wu" },
	{ _field_real, "ef fall-off radius:wu" },
	{ _field_block, "ef falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "ef upper height:wu" },
	{ _field_real, "ef lower height:wu" },
	{ _field_real, "ef weight" },
	{ _field_explanation, "ENEMY BIAS" },
	{ _field_real, "eb full weight radius:wu" },
	{ _field_real, "eb fall-off radius:wu" },
	{ _field_block, "eb falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "eb upper height:wu" },
	{ _field_real, "eb lower height:wu" },
	{ _field_real, "eb weight" },
	{ _field_explanation, "ALLY BIAS" },
	{ _field_real, "ab full weight radius:wu" },
	{ _field_real, "ab fall-off radius:wu" },
	{ _field_block, "ab falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "ab upper height:wu" },
	{ _field_real, "ab lower height:wu" },
	{ _field_real, "ab weight" },
	{ _field_explanation, "SELECTED ALLY BIAS" },
	{ _field_real, "sab full weight radius:wu" },
	{ _field_real, "sab fall-off radius:wu" },
	{ _field_block, "sab falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "sab upper height:wu" },
	{ _field_real, "sab lower height:wu" },
	{ _field_real, "sab weight" },
	{ _field_explanation, "DEAD TEAMMATE BIAS" },
	{ _field_real, "dt full weight radius:wu" },
	{ _field_real, "dt fall-off radius:wu" },
	{ _field_block, "dt falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "dt upper height:wu" },
	{ _field_real, "dt lower height:wu" },
	{ _field_real, "dt weight" },
	{ _field_real, "dead teammate influence duration:seconds" },
	{ _field_explanation, "DROP POD BIAS" },
	{ _field_real, "Drop Pod full weight radius:wu" },
	{ _field_real, "Drop Pod fall-off radius:wu" },
	{ _field_block, "Drop Pod falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "Drop Pod upper height:wu" },
	{ _field_real, "Drop Pod lower height:wu" },
	{ _field_real, "Drop Pod weight" },
	{ _field_explanation, "PLAYER AUTO TURRET BIAS" },
	{ _field_real, "Auto Turret full weight radius:wu" },
	{ _field_real, "Auto Turret fall-off radius:wu" },
	{ _field_block, "Auto Turret falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
	{ _field_real, "Auto Turret upper height:wu" },
	{ _field_real, "Auto Turret lower height:wu" },
	{ _field_real, "Auto Turret weight" },
	{ _field_explanation, "WEAPON INFLUENCERS" },
	{ _field_block, "weapon influencers", &weaponSpawnInfluenceBlock_block },
	{ _field_explanation, "VEHICLE INFLUENCERS" },
	{ _field_block, "vehicle influencers", &vehicleSpawnInfluenceBlock_block },
	{ _field_explanation, "PROJECTILE INFLUENCERS" },
	{ _field_block, "projectile influencers", &projectileSpawnInfluenceBlock_block },
	{ _field_explanation, "EQUIPMENT INFLUENCERS" },
	{ _field_block, "equipment influencers", &equipmentSpawnInfluenceBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

