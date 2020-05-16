#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(equipment_struct_definition)
{
	FIELD( _field_struct, "item", &item_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ EQUIPMENT $$$" ),
	FIELD( _field_custom, "Energy" ),
	FIELD( _field_real, "initial energy" ),
	FIELD( _field_real, "energy recovery time:seconds#after deactivation, energy stays constant for this long before starting to change by \'inactive energy rate\'" ),
	FIELD( _field_real, "inactive energy rate:energy/second" ),
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "unit stow marker name#the marker on the unit to attach this equipment to when it is stowed.\nThe equipment should have a marker named \"equipment_stow_anchor\"" ),
	FIELD( _field_char_enum, "pickup behavior" ),
	FIELD( _field_pad, "IJKMOP", 3 ),
	FIELD( _field_real_argb_color, "forced primary change color#sets the primary change color on the unit to this if the flag above is checked" ),
	FIELD( _field_real_argb_color, "forced secondary change color#sets the secondary change color on the unit to this if the flag above is checked" ),
	FIELD( _field_custom, "AI" ),
	FIELD( _field_explanation, "AI" ),
	FIELD( _field_real, "danger radius#How large a danger zone we should create around this equipment (0 means no danger zone)" ),
	FIELD( _field_real, "min deployment distance:wus#How far does my target have to be for me to throw this at them\?" ),
	FIELD( _field_real, "awareness time:seconds#How long I should go unnoticed by nearby enemies" ),
	FIELD( _field_string_id, "ai dialogue equipment type#The equipment ability type name used by the ai dialog system used to filter equipment activation dialogue events." ),
	FIELD( _field_custom ),
	FIELD( _field_block, "override camera", &optionalUnitCameraBlock ),
	FIELD( _field_block, "abilities", &equipmentAbilityDatum ),
	FIELD( _field_char_enum, "damage reporting type" ),
	FIELD( _field_pad, "LKSHFDIJ", 3 ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_tag_reference, "pickup sound" ),
	FIELD( _field_tag_reference, "energy charged effect" ),
	FIELD( _field_tag_reference, "unable to activate sound" ),
	FIELD( _field_tag_reference, "Player sound bank#High quality player sound bank to be prefetched. Can be empty." ),
	FIELD( _field_block, "Sound RTPCs", &EquipmentSoundRTPCBlock ),
	FIELD( _field_block, "Sound Sweeteners", &EquipmentSoundSweetenerBlock ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(optionalUnitCameraBlock, 1)
{
	FIELD( _field_struct, "unit camera", &unit_camera_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityDatum, k_equipmentMaxAbilityCount)
{
	FIELD( _field_custom, "Timers" ),
	FIELD( _field_real, "duration:seconds#use negative numbers for infinite duration" ),
	FIELD( _field_real, "warmup time:seconds#time before the equipment truly becomes active" ),
	FIELD( _field_real, "cooldown time:seconds#for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates\nNote that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer" ),
	FIELD( _field_real, "phantom volume activation time#time in seconds for the phantom volumes on this object to start accelerating things in them" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Energy" ),
	FIELD( _field_explanation, "Energy" ),
	FIELD( _field_real, "minimum activation energy#energy must be at least this high to activate\nLike activation cost, but doesn\'t actually change energy levels" ),
	FIELD( _field_real, "low energy warning threshold#used by UI" ),
	FIELD( _field_real, "activation energy cost" ),
	FIELD( _field_real, "deactivation energy cost" ),
	FIELD( _field_real, "active energy rate:energy/second" ),
	FIELD( _field_struct, "movement speed to energy rate:1/s", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "movement speed domain:wu/s" ),
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "secondary flags" ),
	FIELD( _field_short_integer, "charges#-1 means unlimited charges" ),
	FIELD( _field_char_enum, "activation mode^" ),
	FIELD( _field_char_integer, "object noise adjustment#for AI perception.\nwhile active, adjusts noises made by the owner unit by this many \'notches\'.\nnote that this is additive, so a positive number is louder and a negative number is quieter" ),
	FIELD( _field_custom, "Type Definitions" ),
	FIELD( _field_block, "multiplayer powerup", &equipmentAbilityTypeMultiplayerPowerupBlock ),
	FIELD( _field_block, "spawner", &equipmentAbilityTypeSpawnerBlock ),
	FIELD( _field_block, "ai spawner", &equipmentAbilityTypeAiSpawnerBlock ),
	FIELD( _field_block, "proximity mine", &equipmentAbilityTypeProximityMineBlock ),
	FIELD( _field_block, "moition tracker noise", &equipmentAbilityTypeMotionTrackerNoiseBlock ),
	FIELD( _field_block, "invincibility mode", &equipmentAbilityTypeInvincibilityBlock ),
	FIELD( _field_block, "tree of life", &equipmentAbilityTypeTreeOfLifeBlock ),
	FIELD( _field_block, "shapeshifter", &equipmentAbilityTypeShapeshifterBlock ),
	FIELD( _field_block, "player trait field", &equipmentAbilityTypePlayerTraitFieldBlock ),
	FIELD( _field_block, "ai trait field", &equipmentAbilityTypeAiTraitFieldBlock ),
	FIELD( _field_block, "repulsor field", &equipmentAbilityTypeRepulsorFieldBlock ),
	FIELD( _field_block, "stasis field", &equipmentAbilityTypeStasisFieldBlock ),
	FIELD( _field_block, "ball lightning", &equipmentAbilityTypeBallLightningBlock ),
	FIELD( _field_block, "IWHBYDaddy", &equipmentAbilityTypeDaddyBlock ),
	FIELD( _field_block, "laser designation", &equipmentAbilityTypeLaserDesignationBlock ),
	FIELD( _field_block, "super jump", &equipmentAbilityTypeSuperJumpBlock ),
	FIELD( _field_block, "ammo pack", &equipmentAbilityTypeAmmoPackBlock ),
	FIELD( _field_block, "power fist", &equipmentAbilityTypePowerFistBlock ),
	FIELD( _field_block, "health pack", &equipmentAbilityTypeHealthPackBlock ),
	FIELD( _field_block, "jet pack", &equipmentAbilityTypeJetPackBlock ),
	FIELD( _field_block, "hologram", &equipmentAbilityTypeHologramBlock ),
	FIELD( _field_block, "special weapon", &equipmentAbilityTypeSpecialWeaponBlock ),
	FIELD( _field_block, "special move", &equipmentAbilityTypeSpecialMoveBlock ),
	FIELD( _field_block, "engineer shields", &equipmentAbilityTypeEngineerShieldsBlock ),
	FIELD( _field_block, "sprint", &equipmentAbilityTypeSprintBlock ),
	FIELD( _field_block, "teleporter", &equipmentAbilityTypeTeleporterBlock ),
	FIELD( _field_block, "auto turret", &equipmentAbilityTypeAutoTurretBlock ),
	FIELD( _field_block, "vision mode", &equipmentAbilityTypeVisionModeBlock ),
	FIELD( _field_block, "shield projector", &equipmentAbilityTypeShieldProjectorBlock ),
	FIELD( _field_block, "projectile collector", &equipmentAbilityTypeProjectileCollectorBlock ),
	FIELD( _field_block, "remote strike", &equipmentAbilityTypeRemoteStrikeBlock ),
	FIELD( _field_block, "equipment hacker", &equipmentAbilityTypeEquipmentHackerBlock ),
	FIELD( _field_block, "remote vehicle", &equipmentAbilityTypeRemoteVehicleBlock ),
	FIELD( _field_block, "suicide bomb", &equipmentAbilityTypeSuicideBombBlock ),
	FIELD( _field_block, "active shield", &equipmentAbilityTypeActiveShieldBlock ),
	FIELD( _field_custom ),
	FIELD( _field_tag_reference, "activation while disabled by player traits sound" ),
	FIELD( _field_tag_reference, "activate effect" ),
	FIELD( _field_tag_reference, "looping effect" ),
	FIELD( _field_tag_reference, "deactivate effect" ),
	FIELD( _field_string_id, "activation animation" ),
	FIELD( _field_string_id, "active animation" ),
	FIELD( _field_string_id, "deactivate animation" ),
	FIELD( _field_string_id, "active animation stance" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeMultiplayerPowerupBlock, 1)
{
	FIELD( _field_long_enum, "flavor" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSpawnerBlock, 1)
{
	FIELD( _field_real, "spawn radius#distance from players eyeball on the z-plane that this effect spawns" ),
	FIELD( _field_real, "spawn z offset#z-offset of effect spawn" ),
	FIELD( _field_real, "spawn area radius#need a sphere of radius r\'s free space in order to spawn, otherwise we pick a new spawn location" ),
	FIELD( _field_real, "spawn velocity#WU/sec" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_pad, "LSJ", 2 ),
	FIELD( _field_tag_reference, "spawned object" ),
	FIELD( _field_tag_reference, "spawned effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeAiSpawnerBlock, 1)
{
	FIELD( _field_real, "spawn radius#distance from players eyeball on the z-plane that this effect spawns" ),
	FIELD( _field_real, "spawn z offset#z-offset of effect spawn" ),
	FIELD( _field_real, "spawn area radius#need a sphere of radius r\'s free space in order to spawn, otherwise we pick a new spawn location" ),
	FIELD( _field_real, "spawn velocity#WU/sec" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_pad, "RFD", 2 ),
	FIELD( _field_tag_reference, "spawned character" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeProximityMineBlock, 1)
{
	FIELD( _field_tag_reference, "explosion effect" ),
	FIELD( _field_tag_reference, "explosion damage effect" ),
	FIELD( _field_real, "arm time#time before it becomes a proximity mine" ),
	FIELD( _field_real, "self destruct time#seconds after it is created that it must self destruct.  0 means never destroy" ),
	FIELD( _field_real, "trigger time#seconds object moving at trigger velocity takes to trigger explosion.  This will smooth out sensitivity to velocity noise" ),
	FIELD( _field_real, "trigger velocity#WU/sec at which we trigger explosion" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeMotionTrackerNoiseBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "arm time#time before it starts making noise" ),
	FIELD( _field_real, "noise radius#radius in WU that the noise extends to." ),
	FIELD( _field_long_integer, "noise count#number of noise points that are generated" ),
	FIELD( _field_real, "flash radius#radius in WU that the damage flash noise extends to." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeInvincibilityBlock, 1)
{
	FIELD( _field_string_id, "invincibility material" ),
	FIELD( _field_short_integer, "invincibility material type*!" ),
	FIELD( _field_pad, "invincibility material pad", 2 ),
	FIELD( _field_real, "shield recharge rate:1.0f/s#while active, shields recharge at this fraction per second" ),
	FIELD( _field_real, "shield max recharge level#highest level shield can recharge to (can be up to 4)" ),
	FIELD( _field_tag_reference, "override collision damage" ),
	FIELD( _field_tag_reference, "ai melee reflect damage" ),
	FIELD( _field_tag_reference, "player melee reflect damage" ),
	FIELD( _field_string_id, "loop-invincibility shield name#active while the equipment is in use (used for shield rendering effects)" ),
	FIELD( _field_string_id, "post-invincibility shield name#active once the equipment is no longer in use" ),
	FIELD( _field_struct, "post-invincibility time to shield level function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "maximum vertical velocity:WU/SEC#we use this to specify the domain of the active vertical velocity funtion" ),
	FIELD( _field_struct, "active vertical velocity damping", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_block, "threshold effects#the effect with the highest threshold will play on deactivation", &equipmentEffectWithThresholdBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentEffectWithThresholdBlock, 10)
{
	FIELD( _field_real, "threshold energy burned^:0-1#how much energy you have to burn to play this effect" ),
	FIELD( _field_real, "energy adjustment:-1 to 1#how much energy to add when playing this effect" ),
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeTreeOfLifeBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "origin marker" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeShapeshifterBlock, 1)
{
	FIELD( _field_string_id, "region name" ),
	FIELD( _field_string_id, "inactive permutation name" ),
	FIELD( _field_string_id, "active permutation name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypePlayerTraitFieldBlock, 1)
{
	FIELD( _field_skip, "radius", 4 ),
	FIELD( _field_block, "active player traits", &game_engine_player_traits_block ),
	FIELD( _field_block, "inactive player traits", &game_engine_player_traits_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeAiTraitFieldBlock, 1)
{
	FIELD( _field_block, "active ai equipment traits", &aiEquipmentTraitsBlock ),
	FIELD( _field_block, "inactive ai equipment traits", &aiEquipmentTraitsBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(aiEquipmentTraitsBlock, 1)
{
	FIELD( _field_block, "appearance traits", &aiEquipmentTraitAppearanceBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(aiEquipmentTraitAppearanceBlock, 1)
{
	FIELD( _field_explanation, "Appearance Traits" ),
	FIELD( _field_char_enum, "active camo setting" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeRepulsorFieldBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "radius:wu" ),
	FIELD( _field_real, "power" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeStasisFieldBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "radius:wu" ),
	FIELD( _field_custom, "Time Dilation Values" ),
	FIELD( _field_explanation, "Time Dilation" ),
	FIELD( _field_real, "time dilation player characters" ),
	FIELD( _field_real, "time dilation projectiles" ),
	FIELD( _field_real, "time dilation vehicles" ),
	FIELD( _field_real, "time dilation other#everything else" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "max biped turning rate:no idea what units... something like .2 or so" ),
	FIELD( _field_real, "gravity multiplier#negative values will invert gravity" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeBallLightningBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "start radius:wu" ),
	FIELD( _field_explanation, "Ball Lightning" ),
	FIELD( _field_real, "chain radius reduction multiplier^:[0.01, 1]#MUST BE GREATER THAN ZERO - each time lightning chains, this is the multiplier that controls how much the radius is reduced by" ),
	FIELD( _field_real, "chain delay timer:seconds" ),
	FIELD( _field_tag_reference, "lightning damage" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeDaddyBlock, 1)
{
	FIELD( _field_tag_reference, "child object" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "dada", 2 ),
	FIELD( _field_real, "shield damage to energy scale#scale factor for energy gain from shield damage to child.\nDamage is normalized, so if this value is -1.0 then the equipment will lose all its energy when its child\'s shield is depleted." ),
	FIELD( _field_real, "starting warm up object scale#if >0 (and warm up time is >0), object size will scale up from this up to 1.0 over course of warm up time and down over cooldown time" ),
	FIELD( _field_real_point_3d, "offset from parent#the root of the child is offset by this amount from the root of the parent biped" ),
	FIELD( _field_real, "vertical offset in world space#used to adjust hight per biped, regardless of aim direction" ),
	FIELD( _field_real_bounds, "min and max pitch:degrees#the min and max pitch that the child will follow as you aim up and down.  -90 to 90" ),
	FIELD( _field_real, "visual activation time:seconds" ),
	FIELD( _field_tag_reference, "spawn effect" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "spawn effect marker" ),
	FIELD( _field_tag_reference, "despawn effect" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "despawn effect marker" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeLaserDesignationBlock, 1)
{
	FIELD( _field_real, "unused!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSuperJumpBlock, 1)
{
	FIELD( _field_struct, "energy to jump", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeAmmoPackBlock, 1)
{
	FIELD( _field_real, "energy change per clip added" ),
	FIELD( _field_long_integer, "extra frags" ),
	FIELD( _field_long_integer, "extra plasma" ),
	FIELD( _field_long_integer, "extra grenade 3" ),
	FIELD( _field_long_integer, "extra grenade 4" ),
	FIELD( _field_long_integer, "extra grenade 5" ),
	FIELD( _field_long_integer, "extra grenade 6" ),
	FIELD( _field_long_integer, "extra grenade 7" ),
	FIELD( _field_long_integer, "extra grenade 8" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypePowerFistBlock, 1)
{
	FIELD( _field_tag_reference, "melee damage" ),
	FIELD( _field_tag_reference, "melee response" ),
	FIELD( _field_tag_reference, "clang damage" ),
	FIELD( _field_tag_reference, "clang response" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeHealthPackBlock, 1)
{
	FIELD( _field_struct, "health given over energy used", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeJetPackBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad after useCamAndMoveForThrustDirection", 3 ),
	FIELD( _field_struct, "thrust to acceleration function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_struct, "Infinite energy thrust to acceleration function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "thrust attack time:s" ),
	FIELD( _field_real, "thrust decay time:s" ),
	FIELD( _field_real, "negative velocity acceleration scale#when falling, scale the thrust by this (so you can \'catch\' yourself easier)" ),
	FIELD( _field_real, "airborne acceleration scale!" ),
	FIELD( _field_real, "grounded acceleration magnitude#how hard to kick you upwards if you activate while grounded" ),
	FIELD( _field_real, "landing anticipation time:s#how many seconds before landing the jetpack user enters the airborne arc" ),
	FIELD( _field_explanation, "Zero-G jet pack" ),
	FIELD( _field_real, "camera vs move input thrust control#Camera direction (0.0) VS movement input (1.0) interpolation" ),
	FIELD( _field_real, "min speed#drag will be applied above this" ),
	FIELD( _field_real, "max speed" ),
	FIELD( _field_real, "stick forward thrust" ),
	FIELD( _field_real, "stick strafe thrust" ),
	FIELD( _field_real, "drag" ),
	FIELD( _field_real, "drag cutoff time#if 0, drag is always applied" ),
	FIELD( _field_real, "cow catcher duration" ),
	FIELD( _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityPartCowCatcherBlock, 1)
{
	FIELD( _field_real, "cow catcher height#world units" ),
	FIELD( _field_real, "cow catcher front width#world units, the width of the flat front portion of the cow-catcher" ),
	FIELD( _field_real, "cow catcher side width#world units, the width of the angled side portion of the cow-catcher" ),
	FIELD( _field_real, "cow catcher side depth#world units, the depth of the angled side portion of the cow-catcher" ),
	FIELD( _field_real_vector_3d, "cow catcher offset#offset from the unit\'s origin to put the origin of the cow-catcher at" ),
	FIELD( _field_tag_reference, "collision damage override#if \"hide unit during transit\" isn\'t checked, this can override the unit\'s collision damage definition during the teleport" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeHologramBlock, 1)
{
	FIELD( _field_real, "hologram duration:s" ),
	FIELD( _field_long_enum, "havok filter group" ),
	FIELD( _field_tag_reference, "creation effect" ),
	FIELD( _field_tag_reference, "attached effect" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "attached effect marker" ),
	FIELD( _field_string_id, "attached effect primary scale" ),
	FIELD( _field_string_id, "attached effect secondary scale" ),
	FIELD( _field_tag_reference, "destruction effect" ),
	FIELD( _field_real, "shimmer decrease rate:1.0/s#how fast shimmer decreases" ),
	FIELD( _field_real, "shimmer bullet ping:0-1#how much to ping shimmer when hit by a bullet" ),
	FIELD( _field_struct, "shimmer to camo function#this is a periodic function with a period of 1 second\nthe shimmer value is used as the range input (interpolates between green and red)", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad after hologram flags", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSpecialWeaponBlock, 1)
{
	FIELD( _field_tag_reference, "weapon" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSpecialMoveBlock, 1)
{
	FIELD( _field_string_id, "forward" ),
	FIELD( _field_string_id, "left" ),
	FIELD( _field_string_id, "backward" ),
	FIELD( _field_string_id, "right" ),
	FIELD( _field_char_enum, "default direction" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_tag_reference, "directional effect" ),
	FIELD( _field_real, "Danger Radius#AI avoidance radius.  Ignored if zero." ),
	FIELD( _field_real, "Speed multiplier#Use this instead of a trait.  0 defaults to 1.  With a trait, the client will move at non-modified scale until it gets replicated." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeEngineerShieldsBlock, 1)
{
	FIELD( _field_real, "radius" ),
	FIELD( _field_string_id, "shield name" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSprintBlock, 1)
{
	FIELD( _field_pad, "haha", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeTeleporterBlock, 1)
{
	FIELD( _field_explanation, "Teleporter" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "blurgh", 3 ),
	FIELD( _field_real, "teleport distance" ),
	FIELD( _field_real, "travel speed#the speed at which you cross the teleporter distance; 0 means instant" ),
	FIELD( _field_real, "deactivation speed#the speed you return to at the end of the teleport, if \"hide unit during transit\" isn\'t checked" ),
	FIELD( _field_tag_reference, "trace effect#an effect that will follow along the travel path" ),
	FIELD( _field_real_vector_3d, "trace effect offset#offset from the unit\'s origin to put the effects at" ),
	FIELD( _field_real, "max pitch (airborne)#[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport in the air" ),
	FIELD( _field_real, "max pitch (ground)#[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport on the ground" ),
	FIELD( _field_custom, "Search Vector" ),
	FIELD( _field_explanation, "Look Vector Weight" ),
	FIELD( _field_real, "look vector weight#value from 0 to 1 for how much we can use the look vector in place of the movement vector" ),
	FIELD( _field_real, "look vector falloff inner#degrees, inside this angle, we use the look vector at full weight" ),
	FIELD( _field_real, "look vector falloff outer#degrees, outside this angle, we only use the movement vector" ),
	FIELD( _field_real, "move vector vertical offset#degrees, how much to offset the move vector vertically; positive is up, negative is down" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Probes" ),
	FIELD( _field_explanation, "Probe" ),
	FIELD( _field_real, "horizontal probe angle#degrees, the angle to each side of the horizontal probes" ),
	FIELD( _field_real, "vertical probe angle#degrees, the angle up and down covered by the fan of vertical rays" ),
	FIELD( _field_long_integer, "number of vertical probes#higher is more likely to find a good match, but more expensive" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Collision" ),
	FIELD( _field_explanation, "Collision" ),
	FIELD( _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeAutoTurretBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "atf", 3 ),
	FIELD( _field_tag_reference, "weapon" ),
	FIELD( _field_real_point_3d, "orbit offset from player#z forward, x right, y down.  Set x,z zero to get independent turret, y is altitude off ground" ),
	FIELD( _field_real, "orbit range#if above are zeros, this is max turret range" ),
	FIELD( _field_real, "orbit rate:orbits per second" ),
	FIELD( _field_real, "maximum range#if not following player, maximum distance downrange turret will travel" ),
	FIELD( _field_real, "max velocity:units per second" ),
	FIELD( _field_real, "max acceleration:units per second squared" ),
	FIELD( _field_real, "turret halt engage time:seconds#amount of time after a moving turret engages a target before it halts movement" ),
	FIELD( _field_real, "turret idle equipment drain multiplier:[0.1]#the multiplier on equipment drain when equipment is in its idle state" ),
	FIELD( _field_real, "turret inactive equipment drain multiplier:[0.1]#the multiplier on equipment drain when equipment is in its inactive state" ),
	FIELD( _field_real, "spawn radius:world units#area that must be clear in order for turret to spawn" ),
	FIELD( _field_real, "spawn in time:seconds#the turret will be inactive for this duration" ),
	FIELD( _field_real_vector_3d, "spawn offset from player:world units#relative to origin and camera direction without pitch" ),
	FIELD( _field_real, "vertical bob height:world units" ),
	FIELD( _field_real, "vertical bobs per second" ),
	FIELD( _field_tag_reference, "spawn effect#effect played on the turret when it is spawned into the world" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "spawn effect marker" ),
	FIELD( _field_string_id, "spawn dissolve type" ),
	FIELD( _field_string_id, "spawn dissolve marker" ),
	FIELD( _field_tag_reference, "collision phase effect#effect played on the turret while a biped or vehicle passes through it" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeVisionModeBlock, 1)
{
	FIELD( _field_byte_flags, "Flags" ),
	FIELD( _field_pad, "vmbf", 3 ),
	FIELD( _field_real, "maximum tell distance:wu#\'Other activation tell effect\' will be applied to players within this distance" ),
	FIELD( _field_tag_reference, "activation tell effect#applied to other players within maximum distance" ),
	FIELD( _field_long_integer, "motion sensor tell blip ticks#within \'maxiumum tell distance\' blip duration if \'Generate tell motion sensor blip\' is checked" ),
	FIELD( _field_tag_reference, "vision mode" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeShieldProjectorBlock, 1)
{
	FIELD( _field_real, "Lifetime #Number of seconds a projected shield will remain active." ),
	FIELD( _field_real, "Recharge Time #Number of seconds between shield projections." ),
	FIELD( _field_real, "Warmup Time #Number of seconds it takes to activate a projection." ),
	FIELD( _field_real_fraction, "Max Move Percentage #Percentage of distance between current and desired positions a shield can be moved per update tick." ),
	FIELD( _field_real, "Offset Amount #Distance from defender\'s position to project the shield." ),
	FIELD( _field_real, "Min Projection Distance #Minimum distance between defender and attacker required to project shield." ),
	FIELD( _field_real, "Max Projection Distance #Max distance from equipment that shield can be projected." ),
	FIELD( _field_real_fraction, "Min Required Energy Level #Min energy required to activate shield." ),
	FIELD( _field_tag_reference, "Project Effect #Beam effect that links equipment to projected shield." ),
	FIELD( _field_tag_reference, "Warmup Effect #Effect played at eventual shield projection point during warmup period." ),
	FIELD( _field_tag_reference, "Shield Crate #Crate created to represent projected shield." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeProjectileCollectorBlock, 1)
{
	FIELD( _field_real_fraction, "Chance to Collect #Percent chance (0-1) that collector has to collect each grenade.  Will only attempt to collect each grenade once." ),
	FIELD( _field_real_bounds, "Collect Cooldown #Number of seconds collector must wait between successful collections." ),
	FIELD( _field_real_bounds, "Attack Delay #Number of seconds collector must wait before throwing a collected projectile at a target." ),
	FIELD( _field_real, "Max Collect Range# Max range in world units that collector can collect and hold onto projectiles." ),
	FIELD( _field_real_bounds, "Orbit Radius# Collector will try to keep collected projectiles orbiting in this range." ),
	FIELD( _field_real, "Orbit Speed# Speed at which collected projectiles orbit." ),
	FIELD( _field_real, "Vertical Offset# Orbit vertical offset amount." ),
	FIELD( _field_real, "Strength# Controls amount of acceleration applied to projectile." ),
	FIELD( _field_real, "Attack Speed# Initial speed of projectiles when thrown as an attack." ),
	FIELD( _field_tag_reference, "Collect Effect #Beam effect that links equipment to each collected projectile." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeRemoteStrikeBlock, 1)
{
	FIELD( _field_tag_reference, "weapon" ),
	FIELD( _field_real, "max velocity" ),
	FIELD( _field_real, "acceleration#this is a percentage of max velocity per second - 0.1 reaches max velocity in 10 seconds" ),
	FIELD( _field_real, "decay rate#the rate at which a moving camera decays when you release the stick.  Lower decays faster." ),
	FIELD( _field_real, "camera interpolation time" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "rso", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeEquipmentHackerBlock, 1)
{
	FIELD( _field_byte_flags, "Flags" ),
	FIELD( _field_pad, "grue", 3 ),
	FIELD( _field_real, "Base drain per second#Will be multiplied by a value from the drain level block." ),
	FIELD( _field_real, "Energy recovery delay#The targeted equipment will not start regenerating energy until at least this much time has gone by." ),
	FIELD( _field_real, "Cone angle degrees#Degrees away from the reticle at which targets are in the cone." ),
	FIELD( _field_block, "Drain levels", &equipmentHackerDrainLevel ),
	FIELD( _field_tag_reference, "cone effect#an effect that will shoot out of your face" ),
	FIELD( _field_tag_reference, "target effect#an effect that will play on the target" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentHackerDrainLevel, EquipmentAbilityTypeEquipmentHacker::DrainLevel::k_maxLevels)
{
	FIELD( _field_real, "Cutoff distance#Targets within this distance will be affected by this multiplier." ),
	FIELD( _field_real, "Drain multiplier#Multiplied by the base drain per second." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeRemoteVehicleBlock, 1)
{
	FIELD( _field_tag_reference, "hologram spawner#reference the equipment that will spawn the hologram that will pilot the remote vehicle" ),
	FIELD( _field_tag_reference, "vehicle#reference the remote vehicle to be created" ),
	FIELD( _field_string_id, "seat label^#hologram gets loaded into this seat in the vehicle" ),
	FIELD( _field_string_id, "spawn position flag#position of scenerio flag with this name. Empty will default to flag named \'remote_vehicle_start_position\'" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeSuicideBombBlock, 1)
{
	FIELD( _field_tag_reference, "explosion damage effect" ),
	FIELD( _field_tag_reference, "explosion effect" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(equipmentAbilityTypeActiveShieldBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(EquipmentSoundRTPCBlock, k_maxEquipmentSoundRTPCBlocks)
{
	FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect" ),
	FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
	FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
	FIELD( _field_long_integer, "RTPC name hash value*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(EquipmentSoundSweetenerBlock, k_maxEquipmentSoundSweetenerBlocks)
{
	FIELD( _field_string_id, "Function#Function to trigger the sweetener" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" ),
	FIELD( _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(equipment_block, EQUIPMENT_TAG, item, ITEM_TAG)
{
	FIELD( _field_struct, "item", &item_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ EQUIPMENT $$$" ),
	FIELD( _field_custom, "Energy" ),
	FIELD( _field_real, "initial energy" ),
	FIELD( _field_real, "energy recovery time:seconds#after deactivation, energy stays constant for this long before starting to change by \'inactive energy rate\'" ),
	FIELD( _field_real, "inactive energy rate:energy/second" ),
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "unit stow marker name#the marker on the unit to attach this equipment to when it is stowed.\nThe equipment should have a marker named \"equipment_stow_anchor\"" ),
	FIELD( _field_char_enum, "pickup behavior" ),
	FIELD( _field_pad, "IJKMOP", 3 ),
	FIELD( _field_real_argb_color, "forced primary change color#sets the primary change color on the unit to this if the flag above is checked" ),
	FIELD( _field_real_argb_color, "forced secondary change color#sets the secondary change color on the unit to this if the flag above is checked" ),
	FIELD( _field_custom, "AI" ),
	FIELD( _field_explanation, "AI" ),
	FIELD( _field_real, "danger radius#How large a danger zone we should create around this equipment (0 means no danger zone)" ),
	FIELD( _field_real, "min deployment distance:wus#How far does my target have to be for me to throw this at them\?" ),
	FIELD( _field_real, "awareness time:seconds#How long I should go unnoticed by nearby enemies" ),
	FIELD( _field_string_id, "ai dialogue equipment type#The equipment ability type name used by the ai dialog system used to filter equipment activation dialogue events." ),
	FIELD( _field_custom ),
	FIELD( _field_block, "override camera", &optionalUnitCameraBlock ),
	FIELD( _field_block, "abilities", &equipmentAbilityDatum ),
	FIELD( _field_char_enum, "damage reporting type" ),
	FIELD( _field_pad, "LKSHFDIJ", 3 ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_tag_reference, "pickup sound" ),
	FIELD( _field_tag_reference, "energy charged effect" ),
	FIELD( _field_tag_reference, "unable to activate sound" ),
	FIELD( _field_tag_reference, "Player sound bank#High quality player sound bank to be prefetched. Can be empty." ),
	FIELD( _field_block, "Sound RTPCs", &EquipmentSoundRTPCBlock ),
	FIELD( _field_block, "Sound Sweeteners", &EquipmentSoundSweetenerBlock ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

