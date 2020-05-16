#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(weapon, WEAPON_TAG, item, ITEM_TAG)
{
	FIELD( _field_struct, "item", &item_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ WEAPON $$$" ),
	FIELD( _field_explanation, "" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "secondary flags" ),
	FIELD( _field_old_string_id, "unused label!" ),
	FIELD( _field_enum, "secondary trigger mode" ),
	FIELD( _field_short_integer, "maximum alternate shots loaded#if the second trigger loads alternate ammunition, this is the maximum number of shots that can be loaded at a time" ),
	FIELD( _field_real, "turn on time#how long after being readied it takes this weapon to switch its \'turned_on\' attachment to 1.0" ),
	FIELD( _field_explanation, "weapon vision mode settings" ),
	FIELD( _field_tag_reference, "vision mode#activated when this weapon is charging" ),
	FIELD( _field_real, "vision cooldown time:seconds" ),
	FIELD( _field_explanation, "old obsolete export to functions" ),
	FIELD( _field_real, "ready time:seconds" ),
	FIELD( _field_tag_reference, "ready effect" ),
	FIELD( _field_tag_reference, "ready damage effect" ),
	FIELD( _field_explanation, "heat" ),
	FIELD( _field_real_fraction, "heat recovery threshold:[0,1]#the heat value a weapon must return to before leaving the overheated state, once it has become overheated in the first place" ),
	FIELD( _field_real_fraction, "overheated threshold:[0,1]#the heat value over which a weapon first becomes overheated (should be greater than the heat recovery threshold)" ),
	FIELD( _field_real_fraction, "heat detonation threshold:[0,1]#the heat value above which the weapon has a chance of exploding each time it is fired" ),
	FIELD( _field_real_fraction, "heat detonation fraction:[0,1]#the percent chance (between 0.0 and 1.0) the weapon will explode when fired over the heat detonation threshold" ),
	FIELD( _field_real_fraction, "heat loss per second:[0,1]#the amount of heat lost each second when the weapon is not being fired" ),
	FIELD( _field_string_id, "heat loss#function values sets the current heat loss per second" ),
	FIELD( _field_string_id, "heat loss venting#function value sets the heat loss per second while weapon is being vented" ),
	FIELD( _field_real, "heat venting time:seconds" ),
	FIELD( _field_real_fraction, "heat venting exit heat#heat at which to begin the venting exit animations so that the weapon is just about fully cooled when the exit animation completes." ),
	FIELD( _field_real_fraction, "heat illumination:[0,1]#the amount of illumination given off when the weapon is overheated" ),
	FIELD( _field_real_fraction, "heat warning threshold#the amount of heat at which a warning will be displayed on the hud" ),
	FIELD( _field_real_fraction, "overheated heat loss per second:[0,1]#the amount of heat lost each second when the weapon is not being fired" ),
	FIELD( _field_string_id, "overheated heat loss#function values sets the heat loss per second when weapon is overheated" ),
	FIELD( _field_tag_reference, "overheated" ),
	FIELD( _field_tag_reference, "overheated damage effect" ),
	FIELD( _field_tag_reference, "detonation" ),
	FIELD( _field_tag_reference, "detonation damage effect" ),
	FIELD( _field_block, "melee damage parameters", &melee_damage_parameters_block_block ),
	FIELD( _field_tag_reference, "clang effect#effect that is played in the air between two players that clang with this weapon" ),
	FIELD( _field_char_enum, "melee damage reporting type" ),
	FIELD( _field_pad, "FEOROBJE", 1 ),
	FIELD( _field_explanation, "zoom" ),
	FIELD( _field_short_integer, "magnification levels#the number of magnification levels this weapon allows" ),
	FIELD( _field_real_bounds, "magnification range" ),
	FIELD( _field_char_integer, "zoom effect ticks#how often \'zoom effect\' will be triggered (while zoomed)" ),
	FIELD( _field_pad, "wzt", 3 ),
	FIELD( _field_tag_reference, "zoom effect#effect that is played while zoomed" ),
	FIELD( _field_explanation, "weapon aim assist!#DEPRECATED -- this will go away in favor of aim assist modes below" ),
	FIELD( _field_struct, "weapon aim assist", &aim_assist_struct_struct_definition ),
	FIELD( _field_struct, "iron sights modifiers", &WeaponBarrelIronSightsStruct_struct_definition ),
	FIELD( _field_block, "aim assist modes#First mode is normal, second mode is iron sights/scoped", &globalAimAssistBlock_block ),
	FIELD( _field_block, "target tracking", &global_target_tracking_parameters_block_block ),
	FIELD( _field_explanation, "aim swim indexing" ),
	FIELD( _field_block, "aim swim", &globalAimSwimBlock_block ),
	FIELD( _field_explanation, "ballistics" ),
	FIELD( _field_real_bounds, "ballistic arcing firing bounds:world units#At the min range (or closer), the minimum ballistic arcing is used, at the max (or farther away), the maximum arcing is used" ),
	FIELD( _field_real_bounds, "ballistic arcing fraction bounds:[0-1]#Controls speed and degree of arc. 0 = low, fast, 1 = high, slow" ),
	FIELD( _field_explanation, "movement" ),
	FIELD( _field_enum, "movement penalized" ),
	FIELD( _field_pad, "GTIXVRPA", 2 ),
	FIELD( _field_real_fraction, "forward movement penalty#percent slowdown to forward movement for units carrying this weapon" ),
	FIELD( _field_real_fraction, "sideways movement penalty#percent slowdown to sideways and backward movement for units carrying this weapon" ),
	FIELD( _field_real_fraction, "gunner armor mod forward movement penalty#percent slowdown to forward movement for units carrying this weapon with the gunner armor mod active" ),
	FIELD( _field_real_fraction, "gunner armor mod sideways movement penalty#percent slowdown to sideways and backward movement for units carrying this weapon with the gunner armor mod active" ),
	FIELD( _field_explanation, "Aiming" ),
	FIELD( _field_real, "Maximum pitch rate:degrees per second#This will cap the speed at which the player can aim when holding this weapon, probably want to set something sensible for turrets etc" ),
	FIELD( _field_explanation, "ArmorMod Parameters" ),
	FIELD( _field_real, "Ammopack power capacity#Ammopack armormod - 0.2 would give 20% additional capacity to an energy weapon" ),
	FIELD( _field_explanation, "AI targeting parameters" ),
	FIELD( _field_real, "AI scariness" ),
	FIELD( _field_explanation, "miscellaneous" ),
	FIELD( _field_real, "weapon power-on time:seconds" ),
	FIELD( _field_real, "weapon power-off time:seconds" ),
	FIELD( _field_tag_reference, "weapon power-on effect" ),
	FIELD( _field_tag_reference, "weapon power-off effect" ),
	FIELD( _field_real, "age heat recovery penalty#how much the weapon\'s heat recovery is penalized as it ages" ),
	FIELD( _field_real, "age rate of fire penalty#how much the weapon\'s rate of fire is penalized as it ages" ),
	FIELD( _field_real_fraction, "age misfire start:[0,1]#the age threshold when the weapon begins to misfire" ),
	FIELD( _field_real_fraction, "age misfire chance:[0,1]#at age 1.0, the misfire chance per shot" ),
	FIELD( _field_tag_reference, "pickup sound" ),
	FIELD( _field_tag_reference, "zoom-in sound" ),
	FIELD( _field_tag_reference, "zoom-out sound" ),
	FIELD( _field_real, "active camo ding#how much to decrease active camo when a round is fired" ),
	FIELD( _field_string_id, "handle node#the node that get\'s attached to the unit\'s hand" ),
	FIELD( _field_explanation, "weapon labels" ),
	FIELD( _field_string_id, "weapon class" ),
	FIELD( _field_string_id, "weapon name" ),
	FIELD( _field_explanation, "more miscellaneous" ),
	FIELD( _field_char_enum, "first time pickup type" ),
	FIELD( _field_pad, "PAD", 3 ),
	FIELD( _field_enum, "weapon type" ),
	FIELD( _field_short_integer, "low ammo threshold" ),
	FIELD( _field_struct, "player interface", &weapon_interface_struct_struct_definition ),
	FIELD( _field_block, "predicted resources", &g_null_block_block ),
	FIELD( _field_block, "magazines", &magazines_block ),
	FIELD( _field_block, "new triggers", &weapon_triggers_block ),
	FIELD( _field_block, "barrels", &weapon_barrels_block ),
	FIELD( _field_explanation, "scaleshot" ),
	FIELD( _field_block, "scaleshot parameters", &weaponScaleshotStruct_block ),
	FIELD( _field_real, "runtime weapon power on velocity!" ),
	FIELD( _field_real, "runtime weapon power off velocity!" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_explanation, "first-person movement control" ),
	FIELD( _field_real, "max movement acceleration" ),
	FIELD( _field_real, "max movement velocity" ),
	FIELD( _field_real, "max turning acceleration" ),
	FIELD( _field_real, "max turning velocity" ),
	FIELD( _field_tag_reference, "deployed vehicle" ),
	FIELD( _field_tag_reference, "tossed weapon" ),
	FIELD( _field_tag_reference, "age effect" ),
	FIELD( _field_tag_reference, "aged weapon" ),
	FIELD( _field_tag_reference, "aged material effects" ),
	FIELD( _field_real, "per kill or hit aging amount#aging applied for \'weapon ages when damage is inflicted\' or \'weapon ages with each kill\' flags" ),
	FIELD( _field_real, "external aging amount" ),
	FIELD( _field_real, "campaign external aging amount" ),
	FIELD( _field_real, "external heat amount" ),
	FIELD( _field_real_fraction, "age recovered per second:[0,1]#the amount of age the weapon recovers per second" ),
	FIELD( _field_tag_reference, "age fully recovered (sound or effect)#the sound or effect played when the weapon\'s age reaches fully recovered" ),
	FIELD( _field_real_vector_3d, "first person weapon offset" ),
	FIELD( _field_real_vector_2d, "first person scope size" ),
	FIELD( _field_real_bounds, "support third person camera range:degrees#range in degrees. 0 is straight, -90 is down, 90 is up" ),
	FIELD( _field_real, "weapon zoom time#seconds" ),
	FIELD( _field_real, "weapon ready-for-use time#seconds" ),
	FIELD( _field_real, "weapon ready 1st person animation playback scale#e.g. - 2.0 makes playspeed twice as fast" ),
	FIELD( _field_real, "tether transition to linked time:seconds#begins when tethered projectile is LNKED" ),
	FIELD( _field_real, "tether transition from linked time:seconds#begins when tethered projectile becomes non-LNKED" ),
	FIELD( _field_string_id, "unit stow anchor name" ),
	FIELD( _field_block, "screen effects", &weapon_screen_effect_block_block ),
	FIELD( _field_tag_reference, "Player sound bank#High quality player sound bank to be prefetched. Can be empty." ),
	FIELD( _field_string_id, "Player EQ preset name#Name of the EQ shareset in WWise to apply when this weapon is active" ),
	FIELD( _field_long_integer, "Player EQ preset hash!" ),
	FIELD( _field_string_id, "Reload cancel event#Note - this is a direct event string - not a .sound" ),
	FIELD( _field_long_integer, "Reload cancel event hash!" ),
	FIELD( _field_tag_reference, "single shot fire for automatics" ),
	FIELD( _field_tag_reference, "firing loop for automatics" ),
	FIELD( _field_block, "Sound RTPCs", &WeaponSoundRTPCBlock_block ),
	FIELD( _field_block, "Sound Sweeteners", &WeaponSoundSweetenerBlock_block ),
	FIELD( _field_string_id, "Locking Reticle Screen Name" ),
	FIELD( _field_string_id, "Locked On Reticle Screen Name" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(melee_damage_parameters_block, k_melee_damage_class_count)
{
	FIELD( _field_explanation, "melee damage parameters" ),
	FIELD( _field_real_euler_angles_2d, "damage pyramid angles" ),
	FIELD( _field_real, "damage pyramid depth:wu#0 defaults to 0.8f" ),
	FIELD( _field_real, "maximum lunge range:wu#0 defaults to 1.22f" ),
	FIELD( _field_real, "damage lunge explosive depth:wu#the distance out from the pyramid center to spawn explosive effects.  This value will be clamped to the damage pyramid depth. 0 defaults to the damage pyramid depth" ),
	FIELD( _field_real, "runtime damage lunge explosive fraction*!" ),
	FIELD( _field_tag_reference, "melee damage" ),
	FIELD( _field_tag_reference, "melee response" ),
	FIELD( _field_tag_reference, "lunge melee damage#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "lunge melee response#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "empty melee damage#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "empty melee response#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "clang melee damage#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "clang melee response#this is only important for the energy sword" ),
	FIELD( _field_tag_reference, "clang melee against melee weapon damage#e.g. used by AR to damage sword guy when clanging sword attack" ),
	FIELD( _field_tag_reference, "clang melee against melee weapon damage response#e.g. used by AR to damage sword guy when clanging sword attack" ),
	FIELD( _field_tag_reference, "lunge melee explosive damage" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(globalAimAssistBlock, 3)
{
	FIELD( _field_real, "autoaim stick time:seconds#the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in" ),
	FIELD( _field_angle, "autoaim stick angle:degrees#the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior." ),
	FIELD( _field_angle, "autoaim angle:degrees#the maximum angle that autoaim works at full strength" ),
	FIELD( _field_real, "autoaim range:world units#the maximum distance that autoaim works at full strength" ),
	FIELD( _field_real, "autoaim falloff range:world units#at what point the autoaim starts falling off" ),
	FIELD( _field_real, "autoaim near falloff range:world units#at what point the autoaim reaches full power" ),
	FIELD( _field_angle, "magnetism angle:degrees#the maximum angle that magnetism works at full strength" ),
	FIELD( _field_real, "magnetism range:world units#the maximum distance that magnetism works at full strength" ),
	FIELD( _field_real, "magnetism falloff range:world units#at what point magnetism starts falling off" ),
	FIELD( _field_real, "magnetism near falloff range:world units#at what point magnetism reaches full power" ),
	FIELD( _field_angle, "deviation angle:degrees#the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction" ),
	FIELD( _field_pad, "ZHV", 4 ),
	FIELD( _field_pad, "CVYGPMLMX", 16 ),
	FIELD( _field_pad, "UQXKLVAXI", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(globalAimSwimBlock, 3)
{
	FIELD( _field_explanation, "x axis curve" ),
	FIELD( _field_real, "x period:seconds" ),
	FIELD( _field_real, "x amplitude" ),
	FIELD( _field_explanation, "y axis curve" ),
	FIELD( _field_real, "y period:seconds" ),
	FIELD( _field_real, "y amplitude" ),
	FIELD( _field_explanation, "biped state scalers" ),
	FIELD( _field_real, "non-moving, crouched" ),
	FIELD( _field_real, "non-moving, standing" ),
	FIELD( _field_real, "moving" ),
	FIELD( _field_explanation, "biped state transition times" ),
	FIELD( _field_real, "to crouched:seconds" ),
	FIELD( _field_real, "to standing:seconds" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_first_person_interface_block, k_first_person_interface_count)
{
	FIELD( _field_tag_reference, "first person model" ),
	FIELD( _field_tag_reference, "first person animations" ),
	FIELD( _field_real, "first person fov scale#the multiplier by the standard first person FOV to use when this weapon is held" ),
	FIELD( _field_real, "first person dof distance#the distance to apply depth of field to the weapon" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(magazines, MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_short_integer, "rounds recharged:per second" ),
	FIELD( _field_short_integer, "rounds total initial" ),
	FIELD( _field_short_integer, "rounds total maximum" ),
	FIELD( _field_short_integer, "rounds loaded maximum" ),
	FIELD( _field_short_integer, "runtime rounds inventory maximum" ),
	FIELD( _field_short_integer, "Ammopack rounds total initial#AmmoPack armormod - alternate total_initial value due to AmmoPack" ),
	FIELD( _field_short_integer, "Ammopack rounds total maximum#AmmoPack armormod - alternate total_maximum value due to armor mod AmmoPack" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_real, "reload dialogue time:seconds#the length of time we wait before saying the reload dialogue" ),
	FIELD( _field_short_integer, "rounds reloaded" ),
	FIELD( _field_pad, "VJGZW", 2 ),
	FIELD( _field_real, "chamber time:seconds - NOT USED!#the length of time it takes to chamber the next round" ),
	FIELD( _field_pad, "HPMIV", 8 ),
	FIELD( _field_pad, "P", 16 ),
	FIELD( _field_tag_reference, "reloading effect" ),
	FIELD( _field_tag_reference, "reloading damage effect" ),
	FIELD( _field_tag_reference, "chambering effect" ),
	FIELD( _field_tag_reference, "chambering damage effect" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "magazines", &magazine_objects_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(magazine_objects, MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE)
{
	FIELD( _field_short_integer, "rounds" ),
	FIELD( _field_pad, "DTDPY", 2 ),
	FIELD( _field_tag_reference, "equipment^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_triggers, k_weapon_trigger_count)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_enum, "input" ),
	FIELD( _field_enum, "behavior" ),
	FIELD( _field_short_block_index, "primary barrel" ),
	FIELD( _field_short_block_index, "secondary barrel" ),
	FIELD( _field_enum, "prediction" ),
	FIELD( _field_pad, "GNFR", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_struct, "autofire", &weapon_trigger_autofire_struct_struct_definition ),
	FIELD( _field_struct, "charging", &weapon_trigger_charging_struct_struct_definition ),
	FIELD( _field_tag_reference, "double latch projectile releasable effect#created once player is able to release the tethered projectile" ),
	FIELD( _field_tag_reference, "double latch projectile released effect#created when player releases the tethered projectile" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_trigger_charging_fire_fraction, MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER)
{
	FIELD( _field_real_fraction, "charge fraction^:[0.1]#charging fraction at which the weapon should additionally fire a shot." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_barrels, k_weapon_barrel_count)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "firing" ),
	FIELD( _field_struct, "firing", &weapon_barrel_firing_parameters_struct_struct_definition ),
	FIELD( _field_short_block_index, "magazine#the magazine from which this trigger draws its ammunition" ),
	FIELD( _field_short_integer, "rounds per shot#the number of rounds expended to create a single firing effect" ),
	FIELD( _field_short_integer, "minimum rounds loaded#the minimum number of rounds necessary to fire the weapon" ),
	FIELD( _field_short_integer, "rounds between tracers#the number of non-tracer rounds fired between tracers" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "optional barrel marker name" ),
	FIELD( _field_enum, "firing noise#how loud this weapon appears to the AI" ),
	FIELD( _field_explanation, "prediction properties" ),
	FIELD( _field_enum, "prediction type" ),
	FIELD( _field_real, "event_synchronized_projectiles_per_second#Valid only for barrels set to prediction type \"continuous\". Controls how many projectiles per second can be individually synchronized (use debug_projectiles to diagnose)." ),
	FIELD( _field_real, "maximum_barrel_error_for_event_synchronization#Valid only for barrels set to prediction type \"continuous\". If the barrel\'s current error level is over this value (zero to one scale), we will not consider synchronizing projectiles with individual events (use debug_projectiles to diagnose)." ),
	FIELD( _field_explanation, "firing error" ),
	FIELD( _field_struct, "firing error", &weapon_barrel_firing_error_struct_struct_definition ),
	FIELD( _field_explanation, "projectile" ),
	FIELD( _field_enum, "distribution function" ),
	FIELD( _field_short_integer, "projectiles per shot" ),
	FIELD( _field_block, "custom vectors#Custom vectors must be set in distribution function above", &projectileDistributionCustomVector_block ),
	FIELD( _field_real, "distribution angle:degrees#used by distribution function \'horizontal fan\' above" ),
	FIELD( _field_angle, "minimum error:degrees#projectile direction is randomly selected between this and max_error_angle below" ),
	FIELD( _field_angle_bounds, "error angle:degrees (max_error_angle)#current barrel_error is linearly interpolated between these to generate max_error_angle" ),
	FIELD( _field_struct, "accuracy penalties", &weapon_barrel_projectile_accuracy_penalty_struct_struct_definition ),
	FIELD( _field_block, "first person offset", &weapon_barrel_first_person_offset_block_block ),
	FIELD( _field_char_enum, "damage effect reporting type" ),
	FIELD( _field_pad, "DGSXQ", 3 ),
	FIELD( _field_tag_reference, "projectile" ),
	FIELD( _field_tag_reference, "optional secondary projectile" ),
	FIELD( _field_struct, "eh", &weapon_barrel_damage_effect_struct_struct_definition ),
	FIELD( _field_tag_reference, "crate projectile" ),
	FIELD( _field_real, "crate projectile speed" ),
	FIELD( _field_explanation, "misc" ),
	FIELD( _field_real, "ejection port recovery time#the amount of time (in seconds) it takes for the ejection port to transition from 1.0 (open) to 0.0 (closed) after a shot has been fired" ),
	FIELD( _field_real, "illumination recovery time#the amount of time (in seconds) it takes the illumination function to transition from 1.0 (bright) to 0.0 (dark) after a shot has been fired" ),
	FIELD( _field_real_fraction, "heat generated per round:[0,1]#the amount of heat generated each time the barrel fires. Unlike the name suggests, this amount of heat is NOT applied per projectile created." ),
	FIELD( _field_string_id, "heat generated per round function&heat generated per round#function value sets the amount of heat to add to the weapon each tick the barrel is firing" ),
	FIELD( _field_real_fraction, "age generated per round:[0,1]#the amount the weapon ages each time the trigger is fired" ),
	FIELD( _field_real_fraction, "CAMPAIGN age generated per round:[0,1]#the amount the weapon ages each time the trigger is fired" ),
	FIELD( _field_real, "overload time:seconds#the next trigger fires this often while holding down this trigger" ),
	FIELD( _field_real, "runtime illumination recovery rate!" ),
	FIELD( _field_real, "runtime ejection port recovery rate!" ),
	FIELD( _field_real, "runtime rate of fire acceleration rate!" ),
	FIELD( _field_real, "runtime rate of fire deceleration rate!" ),
	FIELD( _field_real, "runtime error deceleration rate!" ),
	FIELD( _field_block, "firing effects#firing effects determine what happens when this trigger is fired", &barrel_firing_effect_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(projectileDistributionCustomVector, k_projectile_maximum_custom_vectors)
{
	FIELD( _field_real_point_2d, "Point offset^:[-1.1]#x-y offset - +x is right, +y is up" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_barrel_function_block, 1)
{
	FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_barrel_first_person_offset_block, k_first_person_weapon_offset_type_count)
{
	FIELD( _field_real_point_3d, "first person offset:world units#+x is forward, +z is up, +y is left" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(barrel_firing_effect_block, k_weapon_barrel_effect_count)
{
	FIELD( _field_short_integer, "shot count lower bound#the minimum number of times this firing effect will be used, once it has been chosen" ),
	FIELD( _field_short_integer, "shot count upper bound#the maximum number of times this firing effect will be used, once it has been chosen" ),
	FIELD( _field_tag_reference, "firing effect^#this effect is used when the weapon is loaded and fired normally" ),
	FIELD( _field_tag_reference, "critical effect^#this effect is used when the weapon is loaded and will do critical damage" ),
	FIELD( _field_tag_reference, "misfire effect#this effect is used when the weapon is loaded but fired while overheated" ),
	FIELD( _field_tag_reference, "empty effect#this effect is used when the weapon is not loaded" ),
	FIELD( _field_tag_reference, "optional secondary firing effect#this effect is used when the weapon is not loaded" ),
	FIELD( _field_tag_reference, "firing damage#this effect is used when the weapon is loaded and fired normally" ),
	FIELD( _field_tag_reference, "critical damage^#this effect is used when the weapon is loaded and will do critical damage" ),
	FIELD( _field_tag_reference, "misfire damage#this effect is used when the weapon is loaded but fired while overheated" ),
	FIELD( _field_tag_reference, "empty damage#this effect is used when the weapon is not loaded" ),
	FIELD( _field_tag_reference, "optional secondary firing damage#this effect is used when the weapon is loaded and fired normally" ),
	FIELD( _field_tag_reference, "firing rider damage#this effect is used when the weapon is loaded and fired normally" ),
	FIELD( _field_tag_reference, "critical rider damage^#this effect is used when the weapon is loaded and will do critical damage" ),
	FIELD( _field_tag_reference, "misfire rider damage#this effect is used when the weapon is loaded but fired while overheated" ),
	FIELD( _field_tag_reference, "empty rider damage#this effect is used when the weapon is not loaded" ),
	FIELD( _field_tag_reference, "optional secondary firing rider damage#this effect is used when the weapon is loaded and fired normally" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weaponScaleshotStruct, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "power per shot#the amount of scaleshot power you get when this weapon is fired" ),
	FIELD( _field_real, "power per hit#the amount of scaleshot power you get when a projectile from this weapon hits an enemy" ),
	FIELD( _field_real, "power change per second#the change per second in power" ),
	FIELD( _field_explanation, "power levels" ),
	FIELD( _field_block, "power levels", &weaponScaleshotLevelStruct_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weaponScaleshotLevelStruct, WeaponScaleshotLevelDefinition::k_maxLevels)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "minimum power level^#the minimum power at which this scaleshot level kicks in" ),
	FIELD( _field_real, "power change per shot#the change per shot in power when you\'re at this level" ),
	FIELD( _field_real, "power change per second#the change per second in power when you\'re at this level" ),
	FIELD( _field_tag_reference, "projectile#the projectile to fire at this level" ),
	FIELD( _field_block, "firing effects#firing effects when firing at this level", &barrel_firing_effect_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_screen_effect_block, 4)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "LKSZJFSE", 3 ),
	FIELD( _field_tag_reference, "screen effect^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(WeaponSoundRTPCBlock, k_maxWeaponSoundRTPCBlocks)
{
	FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" ),
	FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
	FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
	FIELD( _field_long_integer, "RTPC name hash value*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(WeaponSoundSweetenerBlock, k_maxWeaponSoundSweetenerBlocks)
{
	FIELD( _field_string_id, "Function#Function to trigger the sweetener" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" ),
	FIELD( _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(aim_assist_struct)
{
	FIELD( _field_real, "autoaim stick time:seconds!#the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in" ),
	FIELD( _field_angle, "autoaim stick angle:degrees!#the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior." ),
	FIELD( _field_angle, "autoaim angle:degrees#the maximum angle that autoaim works at full strength!" ),
	FIELD( _field_real, "autoaim range:world units#the maximum distance that autoaim works at full strength!" ),
	FIELD( _field_real, "autoaim falloff range:world units#at what point the autoaim starts falling off!" ),
	FIELD( _field_real, "autoaim near falloff range:world units#at what point the autoaim reaches full power!" ),
	FIELD( _field_angle, "magnetism angle:degrees#the maximum angle that magnetism works at full strength!" ),
	FIELD( _field_real, "magnetism range:world units#the maximum distance that magnetism works at full strength!" ),
	FIELD( _field_real, "magnetism falloff range:world units#at what point magnetism starts falling off!" ),
	FIELD( _field_real, "magnetism near falloff range:world units#at what point magnetism reaches full power!" ),
	FIELD( _field_angle, "deviation angle:degrees#the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction!" ),
	FIELD( _field_pad, "ZHV", 4 ),
	FIELD( _field_pad, "CVYGPMLMX", 16 ),
	FIELD( _field_pad, "UQXKLVAXI", 4 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(WeaponBarrelIronSightsStruct)
{
	FIELD( _field_real, "spread multiplier#multiplies the spread error - use < 1.0 for more accuracy" ),
	FIELD( _field_real, "movement multiplier#multipliers player maximum move speed" ),
	FIELD( _field_real, "aim speed multiplier" ),
	FIELD( _field_real, "auto zoom out time#tick delay before zooming out upon release of iron sights zoom -- use 0 for single-zoom weapons, 5-10 for multi-zooms like sniper rifle" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_interface_struct)
{
	FIELD( _field_explanation, "interface" ),
	FIELD( _field_struct, "shared interface", &weapon_shared_interface_struct_struct_definition ),
	FIELD( _field_block, "first person", &weapon_first_person_interface_block_block ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_tag_reference, "alternate hud screen reference#the parent of the weapon can indicate that this hud should be used instead of the default" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_shared_interface_struct)
{
	FIELD( _field_pad, "PWGUS", 16 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_trigger_autofire_struct)
{
	FIELD( _field_explanation, "AUTOFIRE" ),
	FIELD( _field_real, "autofire time" ),
	FIELD( _field_real, "autofire throw" ),
	FIELD( _field_enum, "secondary action" ),
	FIELD( _field_enum, "primary action" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_trigger_charging_struct)
{
	FIELD( _field_explanation, "CHARGING" ),
	FIELD( _field_real, "charging time:seconds#the amount of time it takes for this trigger to become fully charged" ),
	FIELD( _field_real, "charged time:seconds#the amount of time this trigger can be charged before becoming overcharged" ),
	FIELD( _field_char_enum, "overcharged action" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_short_integer, "cancelled trigger throw#96 was the constant in code for the pp" ),
	FIELD( _field_real, "charged illumination:[0,1]#the amount of illumination given off when the weapon is fully charged" ),
	FIELD( _field_tag_reference, "charging effect#the charging effect is created once when the trigger begins to charge" ),
	FIELD( _field_tag_reference, "charging damage effect#the charging effect is created once when the trigger begins to charge" ),
	FIELD( _field_tag_reference, "charging continuous damage response#plays every tick you\'re charging or charged, scaled to charging fraction" ),
	FIELD( _field_real, "charged drain rate#how much battery to drain per second when charged" ),
	FIELD( _field_tag_reference, "discharge effect#the discharging effect is created once when the trigger releases its charge" ),
	FIELD( _field_tag_reference, "discharge damage effect#the discharging effect is created once when the trigger releases its charge" ),
	FIELD( _field_block, "fire fractions", &weapon_trigger_charging_fire_fraction_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_barrel_firing_parameters_struct)
{
	FIELD( _field_real_bounds, "rounds per second#the number of firing effects created per second" ),
	FIELD( _field_string_id, "rate of fire acceleration#function value sets the current rate of fire when the barrel is firing" ),
	FIELD( _field_real, "acceleration time:seconds#the continuous firing time it takes for the weapon to achieve its final rounds per second" ),
	FIELD( _field_string_id, "rate of fire deceleration#function value sets the current rate of fire when the barrel is not firing" ),
	FIELD( _field_real, "deceleration time:seconds#the continuous idle time it takes for the weapon to return from its final rounds per second to its initial" ),
	FIELD( _field_real, "barrel spin scale#scale the barrel spin speed by this amount" ),
	FIELD( _field_real_fraction, "blurred rate of fire#a percentage between 0 and 1 which controls how soon in its firing animation the weapon blurs" ),
	FIELD( _field_short_bounds, "shots per fire#allows designer caps to the shots you can fire from one firing action" ),
	FIELD( _field_real, "fire recovery time:seconds#how long after a set of shots it takes before the barrel can fire again" ),
	FIELD( _field_real_fraction, "soft recovery fraction#how much of the recovery allows shots to be queued" ),
	FIELD( _field_real, "melee  fire recovery time:seconds#how long after a set of shots it takes before the weapon can melee" ),
	FIELD( _field_real_fraction, "melee soft recovery fraction#how much of the melee recovery allows melee to be queued" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_barrel_firing_error_struct)
{
	FIELD( _field_real, "deceleration time:seconds#the continuous idle time it would take for a barrel_error of 1.0 to return to its minimum value.\nMinimum value is usually 0.0 but sprinting can override this. See\n\'globals@Player information.momentum and sprinting.min weapon error\'" ),
	FIELD( _field_real_bounds, "damage error#the range of angles (in degrees) that a damaged weapon will skew fire" ),
	FIELD( _field_angle, "min error look pitch rate#yaw rate is doubled" ),
	FIELD( _field_angle, "full error look pitch rate#yaw rate is doubled" ),
	FIELD( _field_real, "look pitch error power#use to soften or sharpen the rate ding" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_barrel_projectile_accuracy_penalty_struct)
{
	FIELD( _field_custom, "accuracy penalties" ),
	FIELD( _field_real, "reload penalty#percentage accuracy lost when reloading" ),
	FIELD( _field_real, "switch penalty#percentage accuracy lost when switching weapons" ),
	FIELD( _field_real, "zoom penalty#percentage accuracy lost when zooming in/out" ),
	FIELD( _field_real, "jump penalty#percentage accuracy lost when jumping" ),
	FIELD( _field_explanation, "barrel_error penalty functions" ),
	FIELD( _field_custom, "single wield penalties" ),
	FIELD( _field_struct, "single wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "dual wield penalties" ),
	FIELD( _field_struct, "dual wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_barrel_projectile_accuracy_penalty_function_struct)
{
	FIELD( _field_block, "firing penalty function#percentage accuracy lost when the barrel has fired", &weapon_barrel_function_block_block ),
	FIELD( _field_block, "firing crouched penalty function#percentage accuracy lost when the barrel has fired from a crouched position", &weapon_barrel_function_block_block ),
	FIELD( _field_block, "moving penalty function#percentage accuracy lost when moving", &weapon_barrel_function_block_block ),
	FIELD( _field_block, "turning penalty function#percentage accuracy lost when turning the camera", &weapon_barrel_function_block_block ),
	FIELD( _field_real, "error angle max rotation#angle which represents the maximum input to the turning penalty function." ),
	FIELD( _field_terminator )
};

TAG_STRUCT(weapon_barrel_damage_effect_struct)
{
	FIELD( _field_tag_reference, "damage effect" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

