#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(effect_scale_enum, 2)
	{
		OPTION("damage"),
		OPTION("angle"),
	};

	TAG_ENUM(material_response, 8)
	{
		OPTION("impact (detonate)"),
		OPTION("fizzle"),
		OPTION("overpenetrate"),
		OPTION("attach"),
		OPTION("bounce"),
		OPTION("bounce (dud)"),
		OPTION("fizzle (ricochet)"),
		OPTION("turn physical"),
	};

	TAG_ENUM(material_possible_response_flags, 11)
	{
		OPTION("only against units (except giants){only against units}"),
		OPTION("never against units (except giants){never against units}"),
		OPTION("only against bipeds"),
		OPTION("only against vehicles"),
		OPTION("never against wuss players"),
		OPTION("only when tethered"),
		OPTION("only when not tethered"),
		OPTION("only against dead bipeds"),
		OPTION("never against dead bipeds"),
		OPTION("only AI projectiles"),
		OPTION("never AI projectiles"),
	};

	TAG_ENUM(projectile_flags, 32)
	{
		OPTION("oriented along velocity"),
		OPTION("AI must use ballistic aiming"),
		OPTION("detonation max time if attached#If attach happens timeout is set to timer.high"),
		OPTION("damage scales based on distance"),
		OPTION("steering adjusts orientation"),
		OPTION("don\'t noise up steering"),
		OPTION("can track behind itself"),
		OPTION("ROBOTRON STEERING#or robotech, maybe"),
		OPTION("affected by phantom volumes"),
		OPTION("notifies target units"),
		OPTION("use ground detonation when attached"),
		OPTION("AI minor tracking threat"),
		OPTION("dangerous when inactive"),
		OPTION("AI stimulus when attached"),
		OPTION("OverPeneDetonation"),
		OPTION("no impact effects on bounce"),
		OPTION("RC1 overpenetration fixes"),
		OPTION("Disable instantaneous first tick"),
		OPTION("Constrain gravity to velocity bounds"),
		OPTION("allow deceleration below final velocity#use for bouncing projectiles that also have initial/final velocity so that can reliably come to rest."),
		OPTION("supports tethering#projectile waits for trigger unlatch before immediately detonating"),
		OPTION("damage_not_predictable_by_clients#used on the focus rifle to disable observer shield flash prediction for a high-dps weapon that does low damage per projectile"),
		OPTION("collides with physics-only surfaces#aka sphere-only collision.  Use this for projectiles that you want to bounce smoothly up stairs, but don\'t use it for projectiles that may come to rest on stairs"),
		OPTION("detonates when attached to objects#when projectiles move slowly enough they attach to objects or come to rest.  Check this for projectiles that don\'t normally attach to things like frag grenades"),
		OPTION("cannot be detached by equipment#armor lock will not detach these projectiles - for the airstrike"),
		OPTION("always attach regardless of material"),
		OPTION("does not collide with world geometry#this gun shoots through schools"),
		OPTION("is collectible#Projectile is collectible by projectile collector equipment"),
		OPTION("continuous damage while attached and tethered"),
		OPTION("combinations of projectiles from different weapons or different bursts of the same weapon will not trigger super combine detonation"),
		OPTION("distance based damage scaling uses damage range low bounds#damage scales from 1.f --> 0.f  between \'damage range - low\' --> \'damage range - high\'"),
		OPTION("skip object first tick#similar to Disable instantaneous first tick, but there\'s actually two types of ticks"),
	};

	TAG_ENUM(secondary_projectile_flags, 7)
	{
		OPTION("Use projectile radius for thickness testing#IF THIS IS OFF, NO THICKNESS OR CHUBBY TESTS ARE PERFORMED."),
		OPTION("Expensive chubby test#Will only be active if thickness testing is ON."),
		OPTION("Use play collision#Will use simple and smooth collision mesh."),
		OPTION("Highlight projectile in vision mode#Makes the projectile show up as an enemy in vision mode"),
		OPTION("biped proximity enemies only#modifies behavior of \'detonation biped proximity\'"),
		OPTION("always use localized physics#overrides early mover localize projectiles"),
		OPTION("never use localized physics#overrides early mover localize projectiles"),
	};

	TAG_ENUM(projectile_detonation_timer_modes, 4)
	{
		OPTION("immediately"),
		OPTION("after first bounce off floor{after first bounce}"),
		OPTION("when at rest"),
		OPTION("after first bounce off any surface"),
	};

	TAG_GROUP_FROM_BLOCK(KillCamCameraParamter, KILLCAMCAMERAPARAMTER_TAG, KillCamCameraParamter_block_block );

	TAG_GROUP_INHERIT_FROM_BLOCK(projectile, PROJECTILE_TAG, object, OBJECT_TAG, projectile_block_block );

	TAG_BLOCK_FROM_STRUCT(KillCamCameraParamter_block, 1, KillCamCameraParamter_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(projectile_block, 1, projectile_group_struct_definition );

	TAG_BLOCK(old_projectile_material_response_block, k_maximum_material_responses)
	{
		FIELD( _field_explanation, "default result" ),
		FIELD( _field_enum, "default response", &material_response ),
		FIELD( _field_pad, "KJSH", 2 ),
		FIELD( _field_string_id, "material name" ),
		FIELD( _field_short_integer, "runtime material index!" ),
		FIELD( _field_pad, "JJHT", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_explanation, "potential result" ),
		FIELD( _field_enum, "potential response", &material_response ),
		FIELD( _field_word_flags, "response flags", &material_possible_response_flags ),
		FIELD( _field_real_fraction, "chance fraction:[0,1]" ),
		FIELD( _field_angle_bounds, "between:degrees" ),
		FIELD( _field_real_bounds, "and:world units per second" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_explanation, "misc" ),
		FIELD( _field_enum, "scale effects by", &effect_scale_enum ),
		FIELD( _field_pad, "BDFI", 2 ),
		FIELD( _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." ),
		FIELD( _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." ),
		FIELD( _field_useless_pad ),
		FIELD( _field_explanation, "penetration" ),
		FIELD( _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" ),
		FIELD( _field_explanation, "reflection" ),
		FIELD( _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" ),
		FIELD( _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(projectile_material_response_block, k_maximum_material_responses)
	{
		FIELD( _field_explanation, "matching criteria" ),
		FIELD( _field_string_id, "material name" ),
		FIELD( _field_short_integer, "runtime material index!" ),
		FIELD( _field_word_flags, "response flags", &material_possible_response_flags ),
		FIELD( _field_real_fraction, "chance fraction:[0,1]" ),
		FIELD( _field_angle_bounds, "between:degrees" ),
		FIELD( _field_real_bounds, "and:world units per second" ),
		FIELD( _field_explanation, "response" ),
		FIELD( _field_enum, "response", &material_response ),
		FIELD( _field_explanation, "misc" ),
		FIELD( _field_enum, "scale effects by", &effect_scale_enum ),
		FIELD( _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." ),
		FIELD( _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." ),
		FIELD( _field_explanation, "overpenetration" ),
		FIELD( _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" ),
		FIELD( _field_explanation, "reflection" ),
		FIELD( _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" ),
		FIELD( _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(brute_grenade_block, 1)
	{
		FIELD( _field_angle, "minimum angular vel#degrees/sec" ),
		FIELD( _field_angle, "maximum angular vel#degrees/sec" ),
		FIELD( _field_angle, "spin angular vel#degrees/sec" ),
		FIELD( _field_real, "angular damping#0==nothing 30==almost comlete damping" ),
		FIELD( _field_real, "drag angle k" ),
		FIELD( _field_real, "drag speed k" ),
		FIELD( _field_real, "drag exponent" ),
		FIELD( _field_real, "attach sample radius" ),
		FIELD( _field_real, "attach acc k" ),
		FIELD( _field_real, "attach acc s" ),
		FIELD( _field_real, "attach acc e" ),
		FIELD( _field_real, "attach acc damping" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(fire_bomb_grenade_block, 1)
	{
		FIELD( _field_real, "projection offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(conical_projection_block, 1)
	{
		FIELD( _field_explanation, "conical_projection: AKA shotgun" ),
		FIELD( _field_short_integer, "yaw count" ),
		FIELD( _field_short_integer, "pitch count" ),
		FIELD( _field_real, "distribution exponent#exp==.5 even distribution, exp==1  halo2 distribution, exp>1== weighted towards center" ),
		FIELD( _field_angle, "spread#degrees" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(ProjectileSoundRTPCBlock, k_maxProjectileSoundRTPCBlocks)
	{
		FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" ),
		FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
		FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(KillCamCameraParamter_struct_definition)
{
		FIELD( _field_real, "distance from camera" ),
		FIELD( _field_real, "height above object" ),
		FIELD( _field_real, "minimum velocity to update" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(projectile_group)
{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ PROJECTILE $$$" ),
		FIELD( _field_long_flags, "flags", &projectile_flags ),
		FIELD( _field_long_flags, "secondary flags", &secondary_projectile_flags ),
		FIELD( _field_enum, "detonation timer starts", &projectile_detonation_timer_modes ),
		FIELD( _field_enum, "impact noise", &ai_sound_volume_enum ),
		FIELD( _field_real, "detonation biped proximity:wu#if >0, both \'detonation timer starts\' + a biped must be within this proximity for condition to be met; see \'biped proximity enemies only\' flag" ),
		FIELD( _field_real, "max lifetime to detonate:seconds#if >0, projectile will detonate regardless of other conditions after this total time" ),
		FIELD( _field_real, "collision radius:world units" ),
		FIELD( _field_explanation, "detonation" ),
		FIELD( _field_real, "arming time:seconds#won\'t detonate before this time elapses" ),
		FIELD( _field_real, "danger radius:world units" ),
		FIELD( _field_real, "danger stimuli radius:world units#Overrides the danger radius when non-zero for stimuli related danger radius calculations." ),
		FIELD( _field_short_integer, "danger group burst count#The number of projectiles in this burst before this burst is considered dangerous" ),
		FIELD( _field_short_integer, "danger group burst max count#The maximum number of projectiles we allow in a group" ),
		FIELD( _field_real_bounds, "timer:seconds#detonation countdown (zero is untimed)" ),
		FIELD( _field_real, "minimum velocity:world units per second#detonates when slowed below this velocity" ),
		FIELD( _field_real, "maximum range:world units#detonates after travelling this distance" ),
		FIELD( _field_real, "bounce maximum range:world units#detonates after travelling this distance, but is reset after a bounce.  Combines with maximum range" ),
		FIELD( _field_real, "max latch time to detonate:seconds#projectile will detonate regardless of weapon latching after this total time" ),
		FIELD( _field_real, "max latch time to arm:seconds#projectile will arm itself regardless of detonation mode if latched for this amount of time." ),
		FIELD( _field_enum, "detonation noise", &ai_sound_volume_enum ),
		FIELD( _field_short_integer, "super det. projectile count" ),
		FIELD( _field_real, "super det. time" ),
		FIELD( _field_real_bounds, "super det. range:world units#The range within which supercombine will happen - outside this range, no supercombine" ),
		FIELD( _field_tag_reference, "super det. behavior#An equipment reference that is attached to the target upon super detonation" ),
		FIELD( _field_real, "tether release safety delay#if the weapon the projectile is tethered to loses its owner, this amount of time will pass before detonation" ),
		FIELD( _field_explanation, "tethering" ),
		FIELD( _field_tag_reference, "detonation started#effect" ),
		FIELD( _field_tag_reference, "detonation effect (airborne)" ),
		FIELD( _field_tag_reference, "detonation effect (ground)" ),
		FIELD( _field_tag_reference, "detonation damage" ),
		FIELD( _field_tag_reference, "detonation behavior#An equipment reference that is attached to the target upon detonation" ),
		FIELD( _field_tag_reference, "attached detonation damage" ),
		FIELD( _field_tag_reference, "super detonation" ),
		FIELD( _field_struct, "your momma", &super_detonation_damage_struct_struct_definition ),
		FIELD( _field_tag_reference, "detonation sound" ),
		FIELD( _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "UAQLONXGN", 1 ),
		FIELD( _field_word_flags, "super detonation object types", &object_type_enum_definition ),
		FIELD( _field_tag_reference, "super attached detonation damage" ),
		FIELD( _field_real, "material effect radius#radius within we will generate material effects" ),
		FIELD( _field_explanation, "flyby/impact" ),
		FIELD( _field_tag_reference, "flyby sound" ),
		FIELD( _field_tag_reference, "flyby damage response" ),
		FIELD( _field_real, "flyby damage response max distance" ),
		FIELD( _field_tag_reference, "impact effect" ),
		FIELD( _field_tag_reference, "object impact effect" ),
		FIELD( _field_tag_reference, "impact damage" ),
		FIELD( _field_explanation, "boarding fields" ),
		FIELD( _field_real, "boarding detonation time" ),
		FIELD( _field_tag_reference, "boarding detonation damage" ),
		FIELD( _field_tag_reference, "boarding attached detonation damage" ),
		FIELD( _field_explanation, "physics" ),
		FIELD( _field_real, "air gravity scale#the proportion of normal gravity applied to the projectile when in air." ),
		FIELD( _field_real_bounds, "air damage range:world units#the range over which damage is scaled when the projectile is in air." ),
		FIELD( _field_real, "water gravity scale#the proportion of normal gravity applied to the projectile when in water." ),
		FIELD( _field_real_bounds, "water damage range:world units#the range over which damage is scaled when the projectile is in water." ),
		FIELD( _field_real, "initial velocity:world units per second#bullet\'s velocity when inflicting maximum damage" ),
		FIELD( _field_real, "final velocity:world units per second#bullet\'s velocity when inflicting minimum damage" ),
		FIELD( _field_real, "indirect fire velocity:world units per second#base velocity used for ballistics calculations for indirect firing." ),
		FIELD( _field_real, "ai velocity scale (normal):[0-1]#scale on the initial velocity when fired by the ai on normal difficulty (0 defaults to 1.0" ),
		FIELD( _field_real, "ai velocity scale (heroic):[0-1]#scale on the initial velocity when fired by the ai on heroic difficulty (0 defaults to 1.0)" ),
		FIELD( _field_real, "ai velocity scale (legendary):[0-1]#scale on the initial velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" ),
		FIELD( _field_real, "ai guided angular velocity scale (normal):[0-1]#scale on the guided angular velocity when fired by the ai on normal difficulty (0 defaults to 1.0" ),
		FIELD( _field_real, "ai guided angular velocity scale (legendary):[0-1]#scale on the guided angular velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" ),
		FIELD( _field_struct, "blah", &angular_velocity_lower_bound_struct_struct_definition ),
		FIELD( _field_angle, "guided angular velocity (upper):degrees per second" ),
		FIELD( _field_angle, "guided angular velocity at rest:degrees per second" ),
		FIELD( _field_real_bounds, "acceleration range:world units#what distance range the projectile goes from initial velocity to final velocity" ),
		FIELD( _field_real, "runtime acceleration bound inverse!" ),
		FIELD( _field_real_fraction, "targeted leading fraction" ),
		FIELD( _field_real, "guided projectile (outer range) error radius" ),
		FIELD( _field_real, "autoaim leading max lead time" ),
		FIELD( _field_block, "old material responses{material responses}!", &old_projectile_material_response_block_block ),
		FIELD( _field_block, "material response", &projectile_material_response_block_block ),
		FIELD( _field_block, "brute grenade", &brute_grenade_block_block ),
		FIELD( _field_block, "fire bomb grenade", &fire_bomb_grenade_block_block ),
		FIELD( _field_block, "conical spread", &conical_projection_block_block ),
		FIELD( _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used." ),
		FIELD( _field_tag_reference, "killcam parameters# if not present, first person will be used." ),
		FIELD( _field_block, "Sound RTPCs", &ProjectileSoundRTPCBlock_block ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
};

TAG_STRUCT(super_detonation_damage_struct)
{
		FIELD( _field_tag_reference, "super detonation damage" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(angular_velocity_lower_bound_struct)
{
		FIELD( _field_angle, "guided angular velocity (lower):degrees per second" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

