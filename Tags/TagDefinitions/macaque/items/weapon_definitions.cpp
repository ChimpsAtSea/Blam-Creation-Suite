#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define WEAPON_STRUCT_DEFINITION_ID { 0xFFC6FB66, 0x88904EC8, 0xB98D9160, 0xFA0A7CDE }
	TAG_BLOCK(
		weapon_block,
		"weapon_block",
		1,
		"_weapon_definition",
		WEAPON_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "item", &item_struct_definition },
		FIELD_CUSTOM("$$$ WEAPON $$$", nullptr, _field_id_function_group_begin),
		{ _field_explanation, "", "All weapons should have \'primary trigger\' and \'secondary trigger\' markers as appropriate.\nBlurred permutations are called \'$primary-blur\' and \'$secondary-blur\'." },
		{ _field_long_flags, "flags", &weapon_definition_flags },
		{ _field_long_flags, "secondary flags", &weapon_definition_secondary_flags },
		{ _field_old_string_id, "unused label" },
		{ _field_enum, "secondary trigger mode", &secondary_trigger_modes },
		{ _field_short_integer, "maximum alternate shots loaded", "if the second trigger loads alternate ammunition, this is the maximum number of shots that can be loaded at a time" },
		{ _field_real, "turn on time", "how long after being readied it takes this weapon to switch its \'turned_on\' attachment to 1.0" },
		{ _field_explanation, "weapon vision mode settings", "" },
		{ _field_tag_reference, "vision mode", &Tag::Reference<struct VisionModeDefinition>::s_defaultDefinition },
		{ _field_real, "vision cooldown time", "seconds" },
		{ _field_explanation, "old obsolete export to functions", "" },
		{ _field_real, "ready time", "seconds" },
		{ _field_tag_reference, "ready effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "ready damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_explanation, "heat", "" },
		{ _field_real_fraction, "heat recovery threshold", "the heat value a weapon must return to before leaving the overheated state, once it has become overheated in the first place" },
		{ _field_real_fraction, "overheated threshold", "the heat value over which a weapon first becomes overheated (should be greater than the heat recovery threshold)" },
		{ _field_real_fraction, "heat detonation threshold", "the heat value above which the weapon has a chance of exploding each time it is fired" },
		{ _field_real_fraction, "heat detonation fraction", "the percent chance (between 0.0 and 1.0) the weapon will explode when fired over the heat detonation threshold" },
		{ _field_real_fraction, "heat loss per second", "the amount of heat lost each second when the weapon is not being fired" },
		{ _field_string_id, "heat loss", "function values sets the current heat loss per second" },
		{ _field_string_id, "heat loss venting", "function value sets the heat loss per second while weapon is being vented" },
		{ _field_real, "heat venting time", "seconds" },
		{ _field_real_fraction, "heat venting exit heat", "heat at which to begin the venting exit animations so that the weapon is just about fully cooled when the exit animation completes." },
		{ _field_real_fraction, "heat illumination", "the amount of illumination given off when the weapon is overheated" },
		{ _field_real_fraction, "heat warning threshold", "the amount of heat at which a warning will be displayed on the hud" },
		{ _field_real_fraction, "overheated heat loss per second", "the amount of heat lost each second when the weapon is not being fired" },
		{ _field_string_id, "overheated heat loss", "function values sets the heat loss per second when weapon is overheated" },
		{ _field_tag_reference, "overheated", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "overheated damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "detonation", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "detonation damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_block, "melee damage parameters", &melee_damage_parameters_block },
		{ _field_tag_reference, "clang effect", &weapon_block_struct_ready_effect_reference },
		{ _field_char_enum, "melee damage reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("FEOROBJE", nullptr, 1),
		{ _field_explanation, "zoom", "" },
		{ _field_short_integer, "magnification levels", "the number of magnification levels this weapon allows" },
		{ _field_real_bounds, "magnification range" },
		{ _field_char_integer, "zoom effect ticks", "how often \'zoom effect\' will be triggered (while zoomed)" },
		FIELD_PAD("wzt", nullptr, 3),
		{ _field_tag_reference, "zoom effect", &weapon_block_struct_ready_effect_reference },
		{ _field_explanation, "weapon aim assist", "DEPRECATED -- this will go away in favor of aim assist modes below" },
		{ _field_struct, "weapon aim assist", &aim_assist_struct },
		{ _field_struct, "iron sights modifiers", &WeaponBarrelIronSightsStruct },
		{ _field_block, "aim assist modes", &globalAimAssistBlock_block },
		{ _field_block, "target tracking", &global_target_tracking_parameters_block },
		{ _field_explanation, "aim swim indexing", "swim index 0 used when unzoomed, index 1 is for first zoom level, index 2 is 2nd zoom, etc." },
		{ _field_block, "aim swim", &globalAimSwimBlock_block },
		{ _field_explanation, "ballistics", "" },
		{ _field_real_bounds, "ballistic arcing firing bounds", "At the min range (or closer), the minimum ballistic arcing is used, at the max (or farther away), the maximum arcing is used", "world units" },
		{ _field_real_bounds, "ballistic arcing fraction bounds", "Controls speed and degree of arc. 0 = low, fast, 1 = high, slow" },
		{ _field_explanation, "movement", "" },
		{ _field_enum, "movement penalized", &movement_penalty_modes },
		FIELD_PAD("GTIXVRPA", nullptr, 2),
		{ _field_real_fraction, "forward movement penalty", "percent slowdown to forward movement for units carrying this weapon" },
		{ _field_real_fraction, "sideways movement penalty", "percent slowdown to sideways and backward movement for units carrying this weapon" },
		{ _field_real_fraction, "gunner armor mod forward movement penalty", "percent slowdown to forward movement for units carrying this weapon with the gunner armor mod active" },
		{ _field_real_fraction, "gunner armor mod sideways movement penalty", "percent slowdown to sideways and backward movement for units carrying this weapon with the gunner armor mod active" },
		{ _field_explanation, "Aiming", "" },
		{ _field_real, "Maximum pitch rate", "This will cap the speed at which the player can aim when holding this weapon, probably want to set something sensible for turrets etc", "degrees per second" },
		{ _field_explanation, "ArmorMod Parameters", "" },
		{ _field_real, "Ammopack power capacity", "Ammopack armormod - 0.2 would give 20% additional capacity to an energy weapon" },
		{ _field_explanation, "AI targeting parameters", "" },
		{ _field_real, "AI scariness" },
		{ _field_explanation, "miscellaneous", "" },
		{ _field_real, "weapon power-on time", "seconds" },
		{ _field_real, "weapon power-off time", "seconds" },
		{ _field_tag_reference, "weapon power-on effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "weapon power-off effect", &weapon_block_struct_ready_effect_reference },
		{ _field_real, "age heat recovery penalty", "how much the weapon\'s heat recovery is penalized as it ages" },
		{ _field_real, "age rate of fire penalty", "how much the weapon\'s rate of fire is penalized as it ages" },
		{ _field_real_fraction, "age misfire start", "the age threshold when the weapon begins to misfire" },
		{ _field_real_fraction, "age misfire chance", "at age 1.0, the misfire chance per shot" },
		{ _field_tag_reference, "pickup sound", &global_sound_reference },
		{ _field_tag_reference, "zoom-in sound", &global_sound_reference },
		{ _field_tag_reference, "zoom-out sound", &global_sound_reference },
		{ _field_real, "active camo ding", "how much to decrease active camo when a round is fired" },
		{ _field_string_id, "handle node", "the node that get\'s attached to the unit\'s hand" },
		{ _field_explanation, "weapon labels", "" },
		{ _field_string_id, "weapon class" },
		{ _field_string_id, "weapon name" },
		{ _field_explanation, "more miscellaneous", "" },
		{ _field_char_enum, "first time pickup type", &first_time_pickup_types },
		FIELD_PAD("PAD", nullptr, 3),
		{ _field_enum, "weapon type", &weapon_types },
		{ _field_short_integer, "low ammo threshold" },
		{ _field_struct, "player interface", &weapon_interface_struct },
		{ _field_block, "predicted resources", &g_null_block },
		{ _field_block, "magazines", &magazines_block },
		{ _field_block, "new triggers", &weapon_triggers_block },
		{ _field_block, "barrels", &weapon_barrels_block },
		{ _field_explanation, "scaleshot", "Allows the weapon to scale up and fire different projectiles based upon how many hits you get etc." },
		{ _field_block, "scaleshot parameters", &weaponScaleshotStruct_block },
		{ _field_real, "runtime weapon power on velocity" },
		{ _field_real, "runtime weapon power off velocity" },
		{ _field_useless_pad, "" },
		{ _field_explanation, "first-person movement control", "" },
		{ _field_real, "max movement acceleration" },
		{ _field_real, "max movement velocity" },
		{ _field_real, "max turning acceleration" },
		{ _field_real, "max turning velocity" },
		{ _field_tag_reference, "deployed vehicle", &vehicle_reference$5 },
		{ _field_tag_reference, "tossed weapon", &global_weapon_reference },
		{ _field_tag_reference, "age effect", &global_effect_reference },
		{ _field_tag_reference, "aged weapon", &global_weapon_reference },
		{ _field_tag_reference, "aged material effects", &global_material_effects_reference },
		{ _field_real, "per kill or hit aging amount", "aging applied for \'weapon ages when damage is inflicted\' or \'weapon ages with each kill\' flags" },
		{ _field_real, "external aging amount" },
		{ _field_real, "campaign external aging amount" },
		{ _field_real, "external heat amount" },
		{ _field_real_fraction, "age recovered per second", "the amount of age the weapon recovers per second" },
		{ _field_tag_reference, "age fully recovered (sound or effect)", &weapon_block_struct_ready_effect_reference },
		{ _field_real_vector_3d, "first person weapon offset" },
		{ _field_real_vector_2d, "first person scope size" },
		{ _field_real_bounds, "support third person camera range", "range in degrees. 0 is straight, -90 is down, 90 is up", "degrees" },
		{ _field_real, "weapon zoom time", "seconds" },
		{ _field_real, "weapon ready-for-use time", "seconds" },
		{ _field_real, "weapon ready 1st person animation playback scale", "e.g. - 2.0 makes playspeed twice as fast" },
		{ _field_real, "tether transition to linked time", "begins when tethered projectile is LNKED", "seconds" },
		{ _field_real, "tether transition from linked time", "begins when tethered projectile becomes non-LNKED", "seconds" },
		{ _field_string_id, "unit stow anchor name" },
		{ _field_block, "screen effects", &weapon_screen_effect_block },
		{ _field_tag_reference, "Player sound bank", &global_soundbank_reference },
		{ _field_string_id, "Player EQ preset name", "Name of the EQ shareset in WWise to apply when this weapon is active" },
		{ _field_long_integer, "Player EQ preset hash" },
		{ _field_string_id, "Reload cancel event", "Note - this is a direct event string - not a .sound" },
		{ _field_long_integer, "Reload cancel event hash" },
		{ _field_tag_reference, "single shot fire for automatics", &global_sound_reference },
		{ _field_tag_reference, "firing loop for automatics", &global_looping_sound_reference },
		{ _field_block, "Sound RTPCs", &WeaponSoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &WeaponSoundSweetenerBlock_block },
		{ _field_string_id, "Locking Reticle Screen Name" },
		{ _field_string_id, "Locked On Reticle Screen Name" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	TAG_GROUP(
		weapon_group,
		WEAPON_TAG,
		&item_group,
		ITEM_TAG,
		weapon_block );

	#define MELEE_DAMAGE_PARAMETERS_BLOCK_ID { 0xB9EBA02E, 0xE895A76C, 0xAB8BEA74, 0x409CC1A5 }
	TAG_BLOCK(
		melee_damage_parameters_block,
		"melee_damage_parameters_block",
		k_melee_damage_class_count,
		"s_melee_damage_parameters",
		MELEE_DAMAGE_PARAMETERS_BLOCK_ID)
	{
		{ _field_explanation, "melee damage parameters", "damage pyramid angles: defines the frustum from the camera that the melee-attack uses to find targets\ndamage pyramid depth: how far the melee attack searches for a target" },
		{ _field_real_euler_angles_2d, "damage pyramid angles" },
		{ _field_real, "damage pyramid depth", "0 defaults to 0.8f", "wu" },
		{ _field_real, "maximum lunge range", "0 defaults to 1.22f", "wu" },
		{ _field_real, "damage lunge explosive depth", "the distance out from the pyramid center to spawn explosive effects.  This value will be clamped to the damage pyramid depth. 0 defaults to the damage pyramid depth", "wu" },
		{ _field_real, "runtime damage lunge explosive fraction" },
		{ _field_tag_reference, "melee damage", &global_damage_reference },
		{ _field_tag_reference, "melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "lunge melee damage", &global_damage_reference },
		{ _field_tag_reference, "lunge melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty melee damage", &global_damage_reference },
		{ _field_tag_reference, "empty melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "clang melee damage", &global_damage_reference },
		{ _field_tag_reference, "clang melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "clang melee against melee weapon damage", &global_damage_reference },
		{ _field_tag_reference, "clang melee against melee weapon damage response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "lunge melee explosive damage", &global_effect_reference },
		{ _field_terminator }
	};

	#define GLOBALAIMASSISTBLOCK_ID { 0x36080F7A, 0x0F9342AF, 0x80A05AEB, 0xDE985A08 }
	TAG_BLOCK(
		globalAimAssistBlock_block,
		"globalAimAssistBlock",
		3,
		"aim_assist_parameters",
		GLOBALAIMASSISTBLOCK_ID)
	{
		{ _field_real, "autoaim stick time", "the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in", "seconds" },
		{ _field_angle, "autoaim stick angle", "the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior.", "degrees" },
		{ _field_angle, "autoaim angle", "the maximum angle that autoaim works at full strength", "degrees" },
		{ _field_real, "autoaim range", "the maximum distance that autoaim works at full strength", "world units" },
		{ _field_real, "autoaim falloff range", "at what point the autoaim starts falling off", "world units" },
		{ _field_real, "autoaim near falloff range", "at what point the autoaim reaches full power", "world units" },
		{ _field_angle, "magnetism angle", "the maximum angle that magnetism works at full strength", "degrees" },
		{ _field_real, "magnetism range", "the maximum distance that magnetism works at full strength", "world units" },
		{ _field_real, "magnetism falloff range", "at what point magnetism starts falling off", "world units" },
		{ _field_real, "magnetism near falloff range", "at what point magnetism reaches full power", "world units" },
		{ _field_angle, "deviation angle", "the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction", "degrees" },
		FIELD_PAD("ZHV", nullptr, 4),
		FIELD_PAD("CVYGPMLMX", nullptr, 16),
		FIELD_PAD("UQXKLVAXI", nullptr, 4),
		{ _field_terminator }
	};

	#define GLOBALAIMSWIMBLOCK_ID { 0x0124D117, 0x0F364B7D, 0x8CFCF7CB, 0x18FE29C7 }
	TAG_BLOCK(
		globalAimSwimBlock_block,
		"globalAimSwimBlock",
		3,
		"aimSwimParameters",
		GLOBALAIMSWIMBLOCK_ID)
	{
		{ _field_explanation, "x axis curve", "" },
		{ _field_real, "x period", "seconds" },
		{ _field_real, "x amplitude" },
		{ _field_explanation, "y axis curve", "" },
		{ _field_real, "y period", "seconds" },
		{ _field_real, "y amplitude" },
		{ _field_explanation, "biped state scalers", "" },
		{ _field_real, "non-moving, crouched" },
		{ _field_real, "non-moving, standing" },
		{ _field_real, "moving" },
		{ _field_explanation, "biped state transition times", "" },
		{ _field_real, "to crouched", "seconds" },
		{ _field_real, "to standing", "seconds" },
		{ _field_terminator }
	};

	#define WEAPON_FIRST_PERSON_INTERFACE_BLOCK_ID { 0x3B47D10E, 0xB50C4EC2, 0xA64BEB32, 0x712F5A86 }
	TAG_BLOCK(
		weapon_first_person_interface_block,
		"weapon_first_person_interface_block",
		k_first_person_interface_count,
		"weapon_first_person_interface_definition",
		WEAPON_FIRST_PERSON_INTERFACE_BLOCK_ID)
	{
		{ _field_tag_reference, "first person model", &render_model_reference$10 },
		{ _field_tag_reference, "first person animations", &model_animation_graph_reference$4 },
		{ _field_real, "first person fov scale", "the multiplier by the standard first person FOV to use when this weapon is held" },
		{ _field_real, "first person dof distance", "the distance to apply depth of field to the weapon" },
		{ _field_terminator }
	};

	#define MAGAZINES_ID { 0xB8FCF9A4, 0xA0194C8E, 0x8CFE64C5, 0xB1CFC041 }
	TAG_BLOCK(
		magazines_block,
		"magazines",
		MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON,
		"magazines",
		MAGAZINES_ID)
	{
		{ _field_long_flags, "flags", &magazine_flags },
		{ _field_short_integer, "rounds recharged", "per second" },
		{ _field_short_integer, "rounds total initial" },
		{ _field_short_integer, "rounds total maximum" },
		{ _field_short_integer, "rounds loaded maximum" },
		{ _field_short_integer, "runtime rounds inventory maximum" },
		{ _field_short_integer, "Ammopack rounds total initial", "AmmoPack armormod - alternate total_initial value due to AmmoPack" },
		{ _field_short_integer, "Ammopack rounds total maximum", "AmmoPack armormod - alternate total_maximum value due to armor mod AmmoPack" },
		FIELD_PAD("pad", nullptr, 2),
		{ _field_real, "reload dialogue time", "the length of time we wait before saying the reload dialogue", "seconds" },
		{ _field_short_integer, "rounds reloaded" },
		FIELD_PAD("VJGZW", nullptr, 2),
		{ _field_real, "chamber time", "the length of time it takes to chamber the next round", "seconds - NOT USED" },
		FIELD_PAD("HPMIV", nullptr, 8),
		FIELD_PAD("P", nullptr, 16),
		{ _field_tag_reference, "reloading effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "reloading damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "chambering effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "chambering damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_useless_pad, "" },
		{ _field_block, "magazines", &magazine_objects_block },
		{ _field_terminator }
	};

	#define MAGAZINE_OBJECTS_ID { 0x3EF33972, 0xC4AC4C51, 0x96B58412, 0x7427D4AC }
	TAG_BLOCK(
		magazine_objects_block,
		"magazine_objects",
		MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE,
		"magazine_objects",
		MAGAZINE_OBJECTS_ID)
	{
		{ _field_short_integer, "rounds" },
		FIELD_PAD("DTDPY", nullptr, 2),
		{ _field_tag_reference, "equipment", &global_equipment_reference },
		{ _field_terminator }
	};

	#define WEAPON_TRIGGERS_ID { 0x908CED94, 0x29134ADA, 0x9600E10A, 0x2C4ED066 }
	TAG_BLOCK(
		weapon_triggers_block,
		"weapon_triggers",
		k_weapon_trigger_count,
		"weapon_trigger_definition",
		WEAPON_TRIGGERS_ID)
	{
		{ _field_long_flags, "flags", &weapon_trigger_definition_flags },
		{ _field_enum, "input", &weapon_trigger_inputs },
		{ _field_enum, "behavior", &weapon_trigger_behaviors },
		{ _field_short_block_index, "primary barrel", &weapon_barrels_block },
		{ _field_short_block_index, "secondary barrel", &weapon_barrels_block },
		{ _field_enum, "prediction", &trigger_prediction_type_enum },
		FIELD_PAD("GNFR", nullptr, 2),
		{ _field_useless_pad, "" },
		{ _field_struct, "autofire", &weapon_trigger_autofire_struct },
		{ _field_struct, "charging", &weapon_trigger_charging_struct },
		{ _field_tag_reference, "double latch projectile releasable effect", &global_effect_reference },
		{ _field_tag_reference, "double latch projectile released effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define WEAPON_BARRELS_ID { 0x52D6B3B0, 0x3234423B, 0x95125B72, 0xFC44714A }
	TAG_BLOCK(
		weapon_barrels_block,
		"weapon_barrels",
		k_weapon_barrel_count,
		"weapon_barrels",
		WEAPON_BARRELS_ID)
	{
		{ _field_long_flags, "flags", &weapon_barrel_flags },
		{ _field_explanation, "firing", "" },
		{ _field_struct, "firing", &weapon_barrel_firing_parameters_struct },
		{ _field_short_block_index, "magazine", &magazines_block },
		{ _field_short_integer, "rounds per shot", "the number of rounds expended to create a single firing effect" },
		{ _field_short_integer, "minimum rounds loaded", "the minimum number of rounds necessary to fire the weapon" },
		{ _field_short_integer, "rounds between tracers", "the number of non-tracer rounds fired between tracers" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "optional barrel marker name" },
		{ _field_enum, "firing noise", &ai_sound_volume_enum },
		{ _field_explanation, "prediction properties", "what the behavior of this barrel is in a predicted network game" },
		{ _field_enum, "prediction type", &barrel_prediction_type_enum },
		{ _field_real, "event_synchronized_projectiles_per_second", "Valid only for barrels set to prediction type \"continuous\". Controls how many projectiles per second can be individually synchronized (use debug_projectiles to diagnose)." },
		{ _field_real, "maximum_barrel_error_for_event_synchronization", "Valid only for barrels set to prediction type \"continuous\". If the barrel\'s current error level is over this value (zero to one scale), we will not consider synchronizing projectiles with individual events (use debug_projectiles to diagnose)." },
		{ _field_explanation, "firing error", "full error look pitch rate controlls how fast you can turn \nwith full error, yaw is implied from pitch. 0==130.\nfor reference, profile sensitivities are set to:\n1: 40\n3: 60\n9: 130\n" },
		{ _field_struct, "firing error", &weapon_barrel_firing_error_struct },
		{ _field_explanation, "projectile", "" },
		{ _field_enum, "distribution function", &weapon_barrel_distribution_functions },
		{ _field_short_integer, "projectiles per shot" },
		{ _field_block, "custom vectors", &projectileDistributionCustomVector_block },
		{ _field_real, "distribution angle", "used by distribution function \'horizontal fan\' above", "degrees" },
		{ _field_angle, "minimum error", "projectile direction is randomly selected between this and max_error_angle below", "degrees" },
		{ _field_angle_bounds, "error angle", "current barrel_error is linearly interpolated between these to generate max_error_angle", "degrees (max_error_angle)" },
		{ _field_struct, "accuracy penalties", &weapon_barrel_projectile_accuracy_penalty_struct },
		{ _field_block, "first person offset", &weapon_barrel_first_person_offset_block },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("DGSXQ", nullptr, 3),
		{ _field_tag_reference, "projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_tag_reference, "optional secondary projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_struct, "eh", &weapon_barrel_damage_effect_struct },
		{ _field_tag_reference, "crate projectile", &crate_projectile_reference },
		{ _field_real, "crate projectile speed" },
		{ _field_explanation, "misc", "" },
		{ _field_real, "ejection port recovery time", "the amount of time (in seconds) it takes for the ejection port to transition from 1.0 (open) to 0.0 (closed) after a shot has been fired" },
		{ _field_real, "illumination recovery time", "the amount of time (in seconds) it takes the illumination function to transition from 1.0 (bright) to 0.0 (dark) after a shot has been fired" },
		{ _field_real_fraction, "heat generated per round", "the amount of heat generated each time the barrel fires. Unlike the name suggests, this amount of heat is NOT applied per projectile created." },
		{ _field_string_id, "heat generated per round function&heat generated per round", "function value sets the amount of heat to add to the weapon each tick the barrel is firing" },
		{ _field_real_fraction, "age generated per round", "the amount the weapon ages each time the trigger is fired" },
		{ _field_real_fraction, "CAMPAIGN age generated per round", "the amount the weapon ages each time the trigger is fired" },
		{ _field_real, "overload time", "the next trigger fires this often while holding down this trigger", "seconds" },
		{ _field_real, "runtime illumination recovery rate" },
		{ _field_real, "runtime ejection port recovery rate" },
		{ _field_real, "runtime rate of fire acceleration rate" },
		{ _field_real, "runtime rate of fire deceleration rate" },
		{ _field_real, "runtime error deceleration rate" },
		{ _field_block, "firing effects", &barrel_firing_effect_block },
		{ _field_terminator }
	};

	#define PROJECTILEDISTRIBUTIONCUSTOMVECTOR_ID { 0x9DB02E18, 0xCD2D4FEB, 0xA6B7BDAB, 0x84E8773C }
	TAG_BLOCK(
		projectileDistributionCustomVector_block,
		"projectileDistributionCustomVector",
		k_projectile_maximum_custom_vectors,
		"s_ProjectileDistributionCustomVector",
		PROJECTILEDISTRIBUTIONCUSTOMVECTOR_ID)
	{
		{ _field_real_point_2d, "Point offset", "x-y offset - +x is right, +y is up" },
		{ _field_terminator }
	};

	#define WEAPON_BARREL_FUNCTION_BLOCK_ID { 0x7DB0BB50, 0xDD6D4AB6, 0xB1680928, 0x130AE1C8 }
	TAG_BLOCK(
		weapon_barrel_function_block,
		"weapon_barrel_function_block",
		1,
		"c_function_definition",
		WEAPON_BARREL_FUNCTION_BLOCK_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define WEAPON_BARREL_FIRST_PERSON_OFFSET_BLOCK_ID { 0x0AEB3ED8, 0xCDED4570, 0xA10B29FD, 0xCFA4104A }
	TAG_BLOCK(
		weapon_barrel_first_person_offset_block,
		"weapon_barrel_first_person_offset_block",
		k_first_person_weapon_offset_type_count,
		"real_point3d",
		WEAPON_BARREL_FIRST_PERSON_OFFSET_BLOCK_ID)
	{
		{ _field_real_point_3d, "first person offset", "+x is forward, +z is up, +y is left", "world units" },
		{ _field_terminator }
	};

	#define BARREL_FIRING_EFFECT_BLOCK_ID { 0x28BBFA00, 0x756842B0, 0x94E75CD1, 0xB8E7F4E6 }
	TAG_BLOCK(
		barrel_firing_effect_block,
		"barrel_firing_effect_block",
		k_weapon_barrel_effect_count,
		"barrel_firing_effect_block",
		BARREL_FIRING_EFFECT_BLOCK_ID)
	{
		{ _field_short_integer, "shot count lower bound", "the minimum number of times this firing effect will be used, once it has been chosen" },
		{ _field_short_integer, "shot count upper bound", "the maximum number of times this firing effect will be used, once it has been chosen" },
		{ _field_tag_reference, "firing effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "critical effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "misfire effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "empty effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "optional secondary firing effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "firing damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "critical damage", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "misfire damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "optional secondary firing damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "firing rider damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "critical rider damage", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "misfire rider damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty rider damage", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "optional secondary firing rider damage", &global_damage_effect_or_response_definition_reference },
		{ _field_terminator }
	};

	#define WEAPON_TRIGGER_CHARGING_FIRE_FRACTION_ID { 0x59082A5C, 0x8986456E, 0xBF034B9A, 0x229B0B5E }
	TAG_BLOCK(
		weapon_trigger_charging_fire_fraction_block,
		"weapon_trigger_charging_fire_fraction",
		MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER,
		"real",
		WEAPON_TRIGGER_CHARGING_FIRE_FRACTION_ID)
	{
		{ _field_real_fraction, "charge fraction", "charging fraction at which the weapon should additionally fire a shot." },
		{ _field_terminator }
	};

	#define WEAPONSCALESHOTSTRUCT_ID { 0x176D67AE, 0xE4C5487D, 0x9D62B870, 0x5AD61B72 }
	TAG_BLOCK(
		weaponScaleshotStruct_block,
		"weaponScaleshotStruct",
		1,
		"WeaponScaleshotDefinition",
		WEAPONSCALESHOTSTRUCT_ID)
	{
		{ _field_long_flags, "flags", &weaponScaleshotFlags },
		{ _field_real, "power per shot", "the amount of scaleshot power you get when this weapon is fired" },
		{ _field_real, "power per hit", "the amount of scaleshot power you get when a projectile from this weapon hits an enemy" },
		{ _field_real, "power change per second", "the change per second in power" },
		{ _field_explanation, "power levels", "IMPORTANT: put these in increasing order, by \"minimum power level\".  I claim no responsibility for weird behavior if they\'re out of order." },
		{ _field_block, "power levels", &weaponScaleshotLevelStruct_block },
		{ _field_terminator }
	};

	#define WEAPONSCALESHOTLEVELSTRUCT_ID { 0xE74FC03E, 0x27224C96, 0xAB423829, 0x624F9BA0 }
	TAG_BLOCK(
		weaponScaleshotLevelStruct_block,
		"weaponScaleshotLevelStruct",
		WeaponScaleshotLevelDefinition::k_maxLevels,
		"WeaponScaleshotLevelDefinition",
		WEAPONSCALESHOTLEVELSTRUCT_ID)
	{
		{ _field_long_flags, "flags", &weaponScaleshotLevelFlags },
		{ _field_real, "minimum power level", "the minimum power at which this scaleshot level kicks in" },
		{ _field_real, "power change per shot", "the change per shot in power when you\'re at this level" },
		{ _field_real, "power change per second", "the change per second in power when you\'re at this level" },
		{ _field_tag_reference, "projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_block, "firing effects", &barrel_firing_effect_block },
		{ _field_terminator }
	};

	#define WEAPON_SCREEN_EFFECT_BLOCK_ID { 0x13215947, 0xD5DB4A9C, 0x9D8632E0, 0xFDAF513D }
	TAG_BLOCK(
		weapon_screen_effect_block,
		"weapon_screen_effect_block",
		4,
		"s_weapon_screen_effect_definition",
		WEAPON_SCREEN_EFFECT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &weapon_screen_effect_flags },
		FIELD_PAD("LKSZJFSE", nullptr, 3),
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		{ _field_terminator }
	};

	#define WEAPONSOUNDRTPCBLOCK_ID { 0xE1F6E77A, 0x861C42FD, 0x959C4F0C, 0x143B5506 }
	TAG_BLOCK(
		WeaponSoundRTPCBlock_block,
		"WeaponSoundRTPCBlock",
		k_maxWeaponSoundRTPCBlocks,
		"WeaponSoundRTPCBlockDefinition",
		WEAPONSOUNDRTPCBLOCK_ID)
	{
		{ _field_long_block_index, "Attachment Index", &global_object_attachment_block },
		{ _field_string_id, "Function", "Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name", "WWise RTPC string name" },
		{ _field_long_integer, "RTPC name hash value" },
		{ _field_terminator }
	};

	#define WEAPONSOUNDSWEETENERBLOCK_ID { 0x2FD5FE86, 0x34154543, 0xB2B22E12, 0xE0FE66F0 }
	TAG_BLOCK(
		WeaponSoundSweetenerBlock_block,
		"WeaponSoundSweetenerBlock",
		k_maxWeaponSoundSweetenerBlocks,
		"WeaponSoundSweetenerBlockDefinition",
		WEAPONSOUNDSWEETENERBLOCK_ID)
	{
		{ _field_string_id, "Function", "Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point", "value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode", "0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" },
		{ _field_terminator }
	};

	#define AIM_ASSIST_STRUCT_ID { 0xFD3F0BC9, 0x19DE4608, 0xA91A35B8, 0x0AC45727 }
	TAG_STRUCT(
		aim_assist_struct,
		"aim_assist_struct",
		"aim_assist_parameters",
		AIM_ASSIST_STRUCT_ID)
	{
		{ _field_real, "autoaim stick time", "the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in", "seconds" },
		{ _field_angle, "autoaim stick angle", "the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior.", "degrees" },
		{ _field_angle, "autoaim angle", "the maximum angle that autoaim works at full strength!", "degrees" },
		{ _field_real, "autoaim range", "the maximum distance that autoaim works at full strength!", "world units" },
		{ _field_real, "autoaim falloff range", "at what point the autoaim starts falling off!", "world units" },
		{ _field_real, "autoaim near falloff range", "at what point the autoaim reaches full power!", "world units" },
		{ _field_angle, "magnetism angle", "the maximum angle that magnetism works at full strength!", "degrees" },
		{ _field_real, "magnetism range", "the maximum distance that magnetism works at full strength!", "world units" },
		{ _field_real, "magnetism falloff range", "at what point magnetism starts falling off!", "world units" },
		{ _field_real, "magnetism near falloff range", "at what point magnetism reaches full power!", "world units" },
		{ _field_angle, "deviation angle", "the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction!", "degrees" },
		FIELD_PAD("ZHV", nullptr, 4),
		FIELD_PAD("CVYGPMLMX", nullptr, 16),
		FIELD_PAD("UQXKLVAXI", nullptr, 4),
		{ _field_terminator }
	};

	#define WEAPONBARRELIRONSIGHTSSTRUCT_ID { 0x94301EC6, 0x12674924, 0xA2D79AE7, 0x9E4F10DE }
	TAG_STRUCT(
		WeaponBarrelIronSightsStruct,
		"WeaponBarrelIronSightsStruct",
		"s_IronSightsParameters",
		WEAPONBARRELIRONSIGHTSSTRUCT_ID)
	{
		{ _field_real, "spread multiplier", "multiplies the spread error - use < 1.0 for more accuracy" },
		{ _field_real, "movement multiplier", "multipliers player maximum move speed" },
		{ _field_real, "aim speed multiplier" },
		{ _field_real, "auto zoom out time", "tick delay before zooming out upon release of iron sights zoom -- use 0 for single-zoom weapons, 5-10 for multi-zooms like sniper rifle" },
		{ _field_terminator }
	};

	#define WEAPON_INTERFACE_STRUCT_ID { 0xE19D1139, 0xDC6246CC, 0x9B9CDBBB, 0x5D685572 }
	TAG_STRUCT(
		weapon_interface_struct,
		"weapon_interface_struct",
		"weapon_interface_definition_new",
		WEAPON_INTERFACE_STRUCT_ID)
	{
		{ _field_explanation, "interface", "" },
		{ _field_struct, "shared interface", &weapon_shared_interface_struct },
		{ _field_block, "first person", &weapon_first_person_interface_block },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "alternate hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define WEAPON_SHARED_INTERFACE_STRUCT_ID { 0x96C3519E, 0x13604185, 0x9C8C6C87, 0xE8738BE9 }
	TAG_STRUCT(
		weapon_shared_interface_struct,
		"weapon_shared_interface_struct",
		"s_tag_reference",
		WEAPON_SHARED_INTERFACE_STRUCT_ID)
	{
		FIELD_PAD("PWGUS", nullptr, 16),
		{ _field_terminator }
	};

	#define WEAPON_BARREL_FIRING_PARAMETERS_STRUCT_ID { 0x85D673EA, 0x92E147FF, 0xB5F3E5BA, 0x101796F3 }
	TAG_STRUCT(
		weapon_barrel_firing_parameters_struct,
		"weapon_barrel_firing_parameters_struct",
		"s_weapon_barrel_firing_params_definition",
		WEAPON_BARREL_FIRING_PARAMETERS_STRUCT_ID)
	{
		{ _field_real_bounds, "rounds per second", "the number of firing effects created per second" },
		{ _field_string_id, "rate of fire acceleration", "function value sets the current rate of fire when the barrel is firing" },
		{ _field_real, "acceleration time", "the continuous firing time it takes for the weapon to achieve its final rounds per second", "seconds" },
		{ _field_string_id, "rate of fire deceleration", "function value sets the current rate of fire when the barrel is not firing" },
		{ _field_real, "deceleration time", "the continuous idle time it takes for the weapon to return from its final rounds per second to its initial", "seconds" },
		{ _field_real, "barrel spin scale", "scale the barrel spin speed by this amount" },
		{ _field_real_fraction, "blurred rate of fire", "a percentage between 0 and 1 which controls how soon in its firing animation the weapon blurs" },
		{ _field_short_bounds, "shots per fire", "allows designer caps to the shots you can fire from one firing action" },
		{ _field_real, "fire recovery time", "how long after a set of shots it takes before the barrel can fire again", "seconds" },
		{ _field_real_fraction, "soft recovery fraction", "how much of the recovery allows shots to be queued" },
		{ _field_real, "melee  fire recovery time", "how long after a set of shots it takes before the weapon can melee", "seconds" },
		{ _field_real_fraction, "melee soft recovery fraction", "how much of the melee recovery allows melee to be queued" },
		{ _field_terminator }
	};

	#define WEAPON_BARREL_FIRING_ERROR_STRUCT_ID { 0xB76772F5, 0x98BB4797, 0xBC2BC6CD, 0x43C3E14E }
	TAG_STRUCT(
		weapon_barrel_firing_error_struct,
		"weapon_barrel_firing_error_struct",
		"real",
		WEAPON_BARREL_FIRING_ERROR_STRUCT_ID)
	{
		{ _field_real, "deceleration time", "the continuous idle time it would take for a barrel_error of 1.0 to return to its minimum value.\nMinimum value is usually 0.0 but sprinting can override this. See\n\'globals@Player information.momentum and sprinting.min weapon error\'", "seconds" },
		{ _field_real_bounds, "damage error", "the range of angles (in degrees) that a damaged weapon will skew fire" },
		{ _field_angle, "min error look pitch rate", "yaw rate is doubled" },
		{ _field_angle, "full error look pitch rate", "yaw rate is doubled" },
		{ _field_real, "look pitch error power", "use to soften or sharpen the rate ding" },
		{ _field_terminator }
	};

	#define WEAPON_BARREL_PROJECTILE_ACCURACY_PENALTY_STRUCT_ID { 0x058C5820, 0x7637243A, 0x2D036E58, 0x11C1972B }
	TAG_STRUCT(
		weapon_barrel_projectile_accuracy_penalty_struct,
		"weapon_barrel_projectile_accuracy_penalty_struct",
		"s_projectile_accuracy_penalty_info",
		WEAPON_BARREL_PROJECTILE_ACCURACY_PENALTY_STRUCT_ID)
	{
		FIELD_CUSTOM("accuracy penalties", nullptr, _field_id_function_group_begin),
		{ _field_real, "reload penalty", "percentage accuracy lost when reloading" },
		{ _field_real, "switch penalty", "percentage accuracy lost when switching weapons" },
		{ _field_real, "zoom penalty", "percentage accuracy lost when zooming in/out" },
		{ _field_real, "jump penalty", "percentage accuracy lost when jumping" },
		{ _field_explanation, "barrel_error penalty functions", "barrel_error = barrel_error + penaltyfunction(barrel_error)\nWhere input value \'X\' produces output value \'Y\'\n" },
		FIELD_CUSTOM("single wield penalties", nullptr, _field_id_function_group_begin),
		{ _field_struct, "single wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("dual wield penalties", nullptr, _field_id_function_group_begin),
		{ _field_struct, "dual wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	#define WEAPON_BARREL_PROJECTILE_ACCURACY_PENALTY_FUNCTION_STRUCT_ID { 0x7D45A208, 0xAA304F19, 0x847FE6F6, 0x5B453291 }
	TAG_STRUCT(
		weapon_barrel_projectile_accuracy_penalty_function_struct,
		"weapon_barrel_projectile_accuracy_penalty_function_struct",
		"s_projectile_accuracy_penalty_functions",
		WEAPON_BARREL_PROJECTILE_ACCURACY_PENALTY_FUNCTION_STRUCT_ID)
	{
		{ _field_block, "firing penalty function", &weapon_barrel_function_block },
		{ _field_block, "firing crouched penalty function", &weapon_barrel_function_block },
		{ _field_block, "moving penalty function", &weapon_barrel_function_block },
		{ _field_block, "turning penalty function", &weapon_barrel_function_block },
		{ _field_real, "error angle max rotation", "angle which represents the maximum input to the turning penalty function." },
		{ _field_terminator }
	};

	#define WEAPON_BARREL_DAMAGE_EFFECT_STRUCT_ID { 0x0CC000C1, 0x6C214FBD, 0x8B1DF64F, 0xC75CB408 }
	TAG_STRUCT(
		weapon_barrel_damage_effect_struct,
		"weapon_barrel_damage_effect_struct",
		"weapon_barrel_damage_effect_struct",
		WEAPON_BARREL_DAMAGE_EFFECT_STRUCT_ID)
	{
		{ _field_tag_reference, "damage effect", &global_damage_reference },
		{ _field_terminator }
	};

	#define WEAPON_TRIGGER_AUTOFIRE_STRUCT_ID { 0x2E880044, 0x234145A2, 0x803AC387, 0xB24AF26C }
	TAG_STRUCT(
		weapon_trigger_autofire_struct,
		"weapon_trigger_autofire_struct",
		"weapon_trigger_definition::s_autofire",
		WEAPON_TRIGGER_AUTOFIRE_STRUCT_ID)
	{
		{ _field_explanation, "AUTOFIRE", "" },
		{ _field_real, "autofire time" },
		{ _field_real, "autofire throw" },
		{ _field_enum, "secondary action", &weapon_trigger_autofire_actions },
		{ _field_enum, "primary action", &weapon_trigger_autofire_actions },
		{ _field_terminator }
	};

	#define WEAPON_TRIGGER_CHARGING_STRUCT_ID { 0x2A90D186, 0xD9FD48DD, 0x879003FA, 0x3B897118 }
	TAG_STRUCT(
		weapon_trigger_charging_struct,
		"weapon_trigger_charging_struct",
		"weapon_trigger_definition::s_charging",
		WEAPON_TRIGGER_CHARGING_STRUCT_ID)
	{
		{ _field_explanation, "CHARGING", "" },
		{ _field_real, "charging time", "the amount of time it takes for this trigger to become fully charged", "seconds" },
		{ _field_real, "charged time", "the amount of time this trigger can be charged before becoming overcharged", "seconds" },
		{ _field_char_enum, "overcharged action", &weapon_trigger_overcharged_actions },
		{ _field_byte_flags, "flags", &weapon_trigger_charging_flags },
		{ _field_short_integer, "cancelled trigger throw", "96 was the constant in code for the pp" },
		{ _field_real, "charged illumination", "the amount of illumination given off when the weapon is fully charged" },
		{ _field_tag_reference, "charging effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "charging damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "charging continuous damage response", &global_damage_response_definition_reference },
		{ _field_real, "charged drain rate", "how much battery to drain per second when charged" },
		{ _field_tag_reference, "discharge effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "discharge damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_block, "fire fractions", &weapon_trigger_charging_fire_fraction_block },
		{ _field_terminator }
	};

	STRINGS(magazine_flags)
	{
		"wastes rounds when reloaded",
		"every round must be chambered",
		"magazine cannot change state while firing#will prevent reload until fire is complete (sticky det)",
		"allow overheated reload when empty",
		"bottomless inventory"
	};
	STRING_LIST(magazine_flags, magazine_flags_strings, _countof(magazine_flags_strings));

	STRINGS(barrel_prediction_type_enum)
	{
		"none",
		"continuous",
		"instant"
	};
	STRING_LIST(barrel_prediction_type_enum, barrel_prediction_type_enum_strings, _countof(barrel_prediction_type_enum_strings));

	STRINGS(weapon_barrel_flags)
	{
		"random firing effects#rather than being chosen sequentially, firing effects are picked randomly",
		"can fire with partial ammo#allows a weapon to be fired as long as there is a non-zero amount of ammunition loaded",
		"projectiles use weapon origin#instead of coming out of the magic first person camera origin, the projectiles for this weapon actually come out of the gun",
		"ejects during chamber#this trigger\'s ejection port is started during the key frame of its chamber animation",
		"projectile vector cannot be adjusted#projectiles fired by this weapon cannot have their direction adjusted by the AI to hit the target",
		"projectiles have identical error",
		"projectiles fire parallel#If there are multiple guns for this trigger, the projectiles emerge in parallel beams (rather than independant aiming)",
		"cant fire when others firing",
		"cant fire when others recovering",
		"don\'t clear fire bit after recovering",
		"stagger fire across multiple markers",
		"can fire at maximum age",
		"use 1 firing effect per burst",
		"prevent marker deviation#the barrel will not fire if all markers are pointed further away from the desired aiming vector than the aim assist deviation angle",
		"error ignores zoom#disables of the barrel error inversely with the zoom magnification",
		"projectile fires in marker direction#projectiles shoot out the marker direction instead of the player\'s aim vector",
		"skip test for object being outside BSP#Prevents projectile origin from changing when object is outside of BSP; Useful for units that can be placed inside physics.",
		"only reload if all barrels idle",
		"only switch weapons if barrel idle#the weapon\'s owner cannot switch weapons unless this barrel is in the idle state"
	};
	STRING_LIST(weapon_barrel_flags, weapon_barrel_flags_strings, _countof(weapon_barrel_flags_strings));

	STRINGS(weapon_barrel_distribution_functions)
	{
		"point",
		"horizontal fan",
		"custom vectors",
		"custom positions"
	};
	STRING_LIST(weapon_barrel_distribution_functions, weapon_barrel_distribution_functions_strings, _countof(weapon_barrel_distribution_functions_strings));

	STRINGS(weapon_trigger_inputs)
	{
		"right trigger",
		"left trigger",
		"melee attack",
		"ai only secondary"
	};
	STRING_LIST(weapon_trigger_inputs, weapon_trigger_inputs_strings, _countof(weapon_trigger_inputs_strings));

	STRINGS(weapon_trigger_overcharged_actions)
	{
		"none",
		"explode",
		"discharge"
	};
	STRING_LIST(weapon_trigger_overcharged_actions, weapon_trigger_overcharged_actions_strings, _countof(weapon_trigger_overcharged_actions_strings));

	STRINGS(weapon_trigger_behaviors)
	{
		"spew#fires its primary action barrel whenever the trigger is down",
		"latch#fires its primary action barrel when the trigger is down and then latches",
		"latch-autofire#fires its primary action barrel once if pulsed quickly or if not depressed all the way, otherwise does secondary behavior",
		"latch-tether#tethers projectiles if latched long enough, on release the tethered projectile detonates",
		"charge#charges the trigger",
		"latch-zoom#latched; fires its primary action barrel when unzoomed, secondary when zoomed",
		"spew-charge",
		"sword-charge",
		"paint-target",
		"double-latch-tether#projectile is tethered by 1st latch, 2nd releases and detonates it",
		"charge-with-magazine#like charge, but pays attention to any magazine and will not charge unless magazine is idle and barrel is actually able to fire"
	};
	STRING_LIST(weapon_trigger_behaviors, weapon_trigger_behaviors_strings, _countof(weapon_trigger_behaviors_strings));

	STRINGS(weapon_trigger_autofire_actions)
	{
		"fire",
		"charge",
		"fire other"
	};
	STRING_LIST(weapon_trigger_autofire_actions, weapon_trigger_autofire_actions_strings, _countof(weapon_trigger_autofire_actions_strings));

	STRINGS(trigger_prediction_type_enum)
	{
		"none",
		"spew",
		"charge"
	};
	STRING_LIST(trigger_prediction_type_enum, trigger_prediction_type_enum_strings, _countof(trigger_prediction_type_enum_strings));

	STRINGS(weapon_trigger_definition_flags)
	{
		"autofire single action only"
	};
	STRING_LIST(weapon_trigger_definition_flags, weapon_trigger_definition_flags_strings, _countof(weapon_trigger_definition_flags_strings));

	STRINGS(weapon_trigger_charging_flags)
	{
		"can fire from partial charge#discharging a partially charged weapon will spew for the charged fraction of the spew time set below",
		"limit to current rounds loaded#if magazine present, do not fire more than current rounds loaded (mantis rocket launcher)",
		"Wont charge unless tracked target is valid#spew-charge triggers only"
	};
	STRING_LIST(weapon_trigger_charging_flags, weapon_trigger_charging_flags_strings, _countof(weapon_trigger_charging_flags_strings));

	STRINGS(weapon_definition_flags)
	{
		"vertical heat display",
		"mutually exclusive triggers",
		"attacks automatically on bump",
		"must be readied",
		"doesn\'t count toward maximum",
		"aim assists only when zoomed",
		"prevents grenade throwing",
		"must be picked up",
		"holds triggers when dropped",
		"prevents melee attack",
		"detonates when dropped",
		"cannot fire at maximum age",
		"secondary trigger overrides grenades",
		"support weapon",
		"hide FP weapon when in iron sights#for scoped weapons",
		"AIs use weapon melee damage",
		"allows binoculars",
		"loop fp firing animation",
		"prevents crouching",
		"cannot fire while boosting",
		"use empty melee on empty",
		"uses 3rd person camera",
		"can be dual wielded",
		"can only be dual wielded",
		"melee only",
		"cant fire if parent dead",
		"weapon ages with each kill#see \'weapon ages when damage is inflicted\', \'per kill or hit aging amount\'",
		"allows unaimed lunge",
		"cannot be used by player",
		"hold fp firing animation",
		"strict deviation angle#deviation angle is allowed to be less than primary autoaim angle - for the rocket launcher",
		"notifies target units#aiming this weapon at another player can be important to them - for lock-on weapons"
	};
	STRING_LIST(weapon_definition_flags, weapon_definition_flags_strings, _countof(weapon_definition_flags_strings));

	STRINGS(weapon_definition_secondary_flags)
	{
		"magnetizes only when zoomed",
		"force enable equipment tossing",
		"non-lunge melee dash disabled#melee-physics dash is disabled on melees that are not lunges",
		"don\'t drop on dual wield melee",
		"is equipment special weapon#when checked, this weapon\n-is deleted when dropped\n-does not count against maximum inventory\n-gets deleted on host migrations\n-prevents swapping or switching weapons",
		"uses ghost reticle",
		"never overheats",
		"force tracers to come from weapon barrel#setting this forces effects tracers to come from weapon barrel instead of eye point",
		"cannot fire during emp",
		"weapon can headshot",
		"AI cannot fire tracking projectiles#setting this will remove tracking data from AI-fired projectiles",
		"second barrel fires if friend is targeted#bishop beam support- primary barrel fires if foe is targeted, secondary if targeting friend",
		"weapon unzooms on damage#taking damage while wielding this will ping player out of zoom/iron sights",
		"do not drop on equipment activation#will counteract default support weapon behavior to drop on equipment activation",
		"weapon can not be dropped#used for CTF magnum, weapon can not be dropped or swapped out",
		"disable function overlays during reload",
		"throw weapon instead of grenade#Throws weapon when grenade trigger is pressed",
		"do not drop \'must be readied\' on primary trigger#Allows \'must be readied\' weapons to have a primary attack",
		"delete on drop",
		"allow melee when using device#Default behavior prevents melee attacks when using device.  Setting this bit allows them.",
		"do not lower weapon when using device#Default behavior lowers weapon when using device.  Setting this leaves the weapon up.",
		"cannot fire while zooming",
		"weapon ages when damage is inflicted#see \'weapon ages with each kill\', \'per kill or hit aging amount\'",
		"apply gunner armor mod abilites#Apply weapon\'s gunner armor mod movement penalty multipliers rather than base multipliers when gunner armor mod is active in _trait_weapons_gunner_armor_modifier",
		"wielders sprint is unaffected by soft ping#see momentum globals \'disable soft ping check\'",
		"weapon drops further away#Adds velocity to weapon\'s default drop (useful for weapons with auto-pickup)",
		"use automatic firing looping sounds",
		"do not drop on assassination#Keeps the weapon in your hand while being assassinated or performing an assassination (for must_be_readied or support weapons)",
		"is part of body#Keeps the weapon from dropping or being hidden at the start of assassinations, and must instead be dropped using the drop weapon keyframe",
		"force deny equipment use#Disallows any equipment usage while holding this weapon regardless of any other traits you may have",
		"hide pickup prompt unless special pickup priority#Used for Oddball that only shows the pickup prompt when megalo script sets pickup priority to special",
		"weapon ignores player_pickup_allowed trait#Player will always pickup this weapon if requested, Used for CTF that needs to force storm_magnum_ctf onto the player"
	};
	STRING_LIST(weapon_definition_secondary_flags, weapon_definition_secondary_flags_strings, _countof(weapon_definition_secondary_flags_strings));

	STRINGS(secondary_trigger_modes)
	{
		"normal",
		"slaved to primary",
		"inhibits primary",
		"loads alterate ammunition",
		"loads multiple primary ammunition"
	};
	STRING_LIST(secondary_trigger_modes, secondary_trigger_modes_strings, _countof(secondary_trigger_modes_strings));

	STRINGS(movement_penalty_modes)
	{
		"always",
		"when zoomed",
		"when zoomed or reloading"
	};
	STRING_LIST(movement_penalty_modes, movement_penalty_modes_strings, _countof(movement_penalty_modes_strings));

	STRINGS(weapon_types)
	{
		"undefined",
		"shotgun",
		"needler",
		"plasma pistol",
		"plasma rifle",
		"rocket launcher",
		"energy blade",
		"splaser",
		"shield",
		"scarab gun",
		"wolverine quad",
		"flak cannon",
		"plasma launcher",
		"laser designator",
		"sticky detonator"
	};
	STRING_LIST(weapon_types, weapon_types_strings, _countof(weapon_types_strings));

	STRINGS(first_time_pickup_types)
	{
		"unassigned",
		"bolt pistol",
		"light rifle",
		"suppressor",
		"binary rifle",
		"scattershot",
		"incineration cannon"
	};
	STRING_LIST(first_time_pickup_types, first_time_pickup_types_strings, _countof(first_time_pickup_types_strings));

	STRINGS(global_melee_class_enum_definition)
	{
		"default class",
		"elite class"
	};
	STRING_LIST(global_melee_class_enum_definition, global_melee_class_enum_definition_strings, _countof(global_melee_class_enum_definition_strings));

	STRINGS(weapon_screen_effect_flags)
	{
		"overrides unit and camera screen effects",
		"unzoomed",
		"zoom level 1",
		"zoom level 2"
	};
	STRING_LIST(weapon_screen_effect_flags, weapon_screen_effect_flags_strings, _countof(weapon_screen_effect_flags_strings));

	STRINGS(weaponScaleshotLevelFlags)
	{
		"cannot gain power at this level#if true, as long as the weapon is at this level, you cannot gain positive power, only negative values are applied"
	};
	STRING_LIST(weaponScaleshotLevelFlags, weaponScaleshotLevelFlags_strings, _countof(weaponScaleshotLevelFlags_strings));

	STRINGS(weaponScaleshotFlags)
	{
		"level latches#if true, once you hit a power level, you stay at that level or higher until your power value hits 0; otherwise your power level is recomputed constantly"
	};
	STRING_LIST(weaponScaleshotFlags, weaponScaleshotFlags_strings, _countof(weaponScaleshotFlags_strings));

	TAG_REFERENCE(global_weapon_reference, WEAPON_TAG);

	TAG_REFERENCE(crate_projectile_reference, CRATE_TAG);

} // namespace macaque

} // namespace blofeld

