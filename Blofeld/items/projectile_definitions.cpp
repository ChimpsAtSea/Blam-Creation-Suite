#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(old_projectile_material_response, k_maximum_material_responses)
{
	{ _field_explanation, "default result" },
	{ _field_enum, "default response" },
	{ _field_pad, "KJSH", 2 },
	{ _field_string_id, "material name" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_pad, "JJHT", 2 },
	{ _field_useless_pad },
	{ _field_explanation, "potential result" },
	{ _field_enum, "potential response" },
	{ _field_word_flags, "response flags" },
	{ _field_real_fraction, "chance fraction:[0,1]" },
	{ _field_angle_bounds, "between:degrees" },
	{ _field_real_bounds, "and:world units per second" },
	{ _field_useless_pad },
	{ _field_explanation, "misc" },
	{ _field_enum, "scale effects by" },
	{ _field_pad, "BDFI", 2 },
	{ _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." },
	{ _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." },
	{ _field_useless_pad },
	{ _field_explanation, "penetration" },
	{ _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" },
	{ _field_explanation, "reflection" },
	{ _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" },
	{ _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" },
	{ _field_terminator },
};

TAG_BLOCK(projectile_material_response, k_maximum_material_responses)
{
	{ _field_explanation, "matching criteria" },
	{ _field_string_id, "material name" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_word_flags, "response flags" },
	{ _field_real_fraction, "chance fraction:[0,1]" },
	{ _field_angle_bounds, "between:degrees" },
	{ _field_real_bounds, "and:world units per second" },
	{ _field_explanation, "response" },
	{ _field_enum, "response" },
	{ _field_explanation, "misc" },
	{ _field_enum, "scale effects by" },
	{ _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." },
	{ _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." },
	{ _field_explanation, "overpenetration" },
	{ _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" },
	{ _field_explanation, "reflection" },
	{ _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" },
	{ _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" },
	{ _field_terminator },
};

TAG_BLOCK(brute_grenade, 1)
{
	{ _field_angle, "minimum angular vel#degrees/sec" },
	{ _field_angle, "maximum angular vel#degrees/sec" },
	{ _field_angle, "spin angular vel#degrees/sec" },
	{ _field_real, "angular damping#0==nothing 30==almost comlete damping" },
	{ _field_real, "drag angle k" },
	{ _field_real, "drag speed k" },
	{ _field_real, "drag exponent" },
	{ _field_real, "attach sample radius" },
	{ _field_real, "attach acc k" },
	{ _field_real, "attach acc s" },
	{ _field_real, "attach acc e" },
	{ _field_real, "attach acc damping" },
	{ _field_terminator },
};

TAG_BLOCK(fire_bomb_grenade, 1)
{
	{ _field_real, "projection offset" },
	{ _field_terminator },
};

TAG_BLOCK(conical_projection, 1)
{
	{ _field_explanation, "conical_projection: AKA shotgun" },
	{ _field_short_integer, "yaw count" },
	{ _field_short_integer, "pitch count" },
	{ _field_real, "distribution exponent#exp==.5 even distribution, exp==1  halo2 distribution, exp>1== weighted towards center" },
	{ _field_angle, "spread#degrees" },
	{ _field_terminator },
};

TAG_BLOCK(ProjectileSoundRTPCBlock, k_maxProjectileSoundRTPCBlocks)
{
	{ _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" },
	{ _field_string_id, "Function#Function to drive the RTPC" },
	{ _field_string_id, "RTPC Name#WWise RTPC string name" },
	{ _field_terminator },
};

TAG_GROUP(KillCamCameraParamter, KILLCAMCAMERAPARAMTER_TAG)
{
	{ _field_real, "distance from camera" },
	{ _field_real, "height above object" },
	{ _field_real, "minimum velocity to update" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(projectile, PROJECTILE_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ PROJECTILE $$$" },
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "secondary flags" },
	{ _field_enum, "detonation timer starts" },
	{ _field_enum, "impact noise" },
	{ _field_real, "detonation biped proximity:wu#if >0, both \'detonation timer starts\' + a biped must be within this proximity for condition to be met; see \'biped proximity enemies only\' flag" },
	{ _field_real, "max lifetime to detonate:seconds#if >0, projectile will detonate regardless of other conditions after this total time" },
	{ _field_real, "collision radius:world units" },
	{ _field_explanation, "detonation" },
	{ _field_real, "arming time:seconds#won\'t detonate before this time elapses" },
	{ _field_real, "danger radius:world units" },
	{ _field_real, "danger stimuli radius:world units#Overrides the danger radius when non-zero for stimuli related danger radius calculations." },
	{ _field_short_integer, "danger group burst count#The number of projectiles in this burst before this burst is considered dangerous" },
	{ _field_short_integer, "danger group burst max count#The maximum number of projectiles we allow in a group" },
	{ _field_real_bounds, "timer:seconds#detonation countdown (zero is untimed)" },
	{ _field_real, "minimum velocity:world units per second#detonates when slowed below this velocity" },
	{ _field_real, "maximum range:world units#detonates after travelling this distance" },
	{ _field_real, "bounce maximum range:world units#detonates after travelling this distance, but is reset after a bounce.  Combines with maximum range" },
	{ _field_real, "max latch time to detonate:seconds#projectile will detonate regardless of weapon latching after this total time" },
	{ _field_real, "max latch time to arm:seconds#projectile will arm itself regardless of detonation mode if latched for this amount of time." },
	{ _field_enum, "detonation noise" },
	{ _field_short_integer, "super det. projectile count" },
	{ _field_real, "super det. time" },
	{ _field_real_bounds, "super det. range:world units#The range within which supercombine will happen - outside this range, no supercombine" },
	{ _field_tag_reference, "super det. behavior#An equipment reference that is attached to the target upon super detonation" },
	{ _field_real, "tether release safety delay#if the weapon the projectile is tethered to loses its owner, this amount of time will pass before detonation" },
	{ _field_explanation, "tethering" },
	{ _field_tag_reference, "detonation started#effect" },
	{ _field_tag_reference, "detonation effect (airborne)" },
	{ _field_tag_reference, "detonation effect (ground)" },
	{ _field_tag_reference, "detonation damage" },
	{ _field_tag_reference, "detonation behavior#An equipment reference that is attached to the target upon detonation" },
	{ _field_tag_reference, "attached detonation damage" },
	{ _field_tag_reference, "super detonation" },
	{ _field_struct, "your momma" },
	{ _field_tag_reference, "detonation sound" },
	{ _field_char_enum, "damage reporting type" },
	{ _field_pad, "UAQLONXGN", 1 },
	{ _field_word_flags, "super detonation object types" },
	{ _field_tag_reference, "super attached detonation damage" },
	{ _field_real, "material effect radius#radius within we will generate material effects" },
	{ _field_explanation, "flyby/impact" },
	{ _field_tag_reference, "flyby sound" },
	{ _field_tag_reference, "flyby damage response" },
	{ _field_real, "flyby damage response max distance" },
	{ _field_tag_reference, "impact effect" },
	{ _field_tag_reference, "object impact effect" },
	{ _field_tag_reference, "impact damage" },
	{ _field_explanation, "boarding fields" },
	{ _field_real, "boarding detonation time" },
	{ _field_tag_reference, "boarding detonation damage" },
	{ _field_tag_reference, "boarding attached detonation damage" },
	{ _field_explanation, "physics" },
	{ _field_real, "air gravity scale#the proportion of normal gravity applied to the projectile when in air." },
	{ _field_real_bounds, "air damage range:world units#the range over which damage is scaled when the projectile is in air." },
	{ _field_real, "water gravity scale#the proportion of normal gravity applied to the projectile when in water." },
	{ _field_real_bounds, "water damage range:world units#the range over which damage is scaled when the projectile is in water." },
	{ _field_real, "initial velocity:world units per second#bullet\'s velocity when inflicting maximum damage" },
	{ _field_real, "final velocity:world units per second#bullet\'s velocity when inflicting minimum damage" },
	{ _field_real, "indirect fire velocity:world units per second#base velocity used for ballistics calculations for indirect firing." },
	{ _field_real, "ai velocity scale (normal):[0-1]#scale on the initial velocity when fired by the ai on normal difficulty (0 defaults to 1.0" },
	{ _field_real, "ai velocity scale (heroic):[0-1]#scale on the initial velocity when fired by the ai on heroic difficulty (0 defaults to 1.0)" },
	{ _field_real, "ai velocity scale (legendary):[0-1]#scale on the initial velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" },
	{ _field_real, "ai guided angular velocity scale (normal):[0-1]#scale on the guided angular velocity when fired by the ai on normal difficulty (0 defaults to 1.0" },
	{ _field_real, "ai guided angular velocity scale (legendary):[0-1]#scale on the guided angular velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" },
	{ _field_struct, "blah" },
	{ _field_angle, "guided angular velocity (upper):degrees per second" },
	{ _field_angle, "guided angular velocity at rest:degrees per second" },
	{ _field_real_bounds, "acceleration range:world units#what distance range the projectile goes from initial velocity to final velocity" },
	{ _field_real, "runtime acceleration bound inverse!" },
	{ _field_real_fraction, "targeted leading fraction" },
	{ _field_real, "guided projectile (outer range) error radius" },
	{ _field_real, "autoaim leading max lead time" },
	{ _field_block, "old material responses{material responses}!", &old_projectile_material_response_block },
	{ _field_block, "material response", &projectile_material_response_block },
	{ _field_block, "brute grenade", &brute_grenade_block },
	{ _field_block, "fire bomb grenade", &fire_bomb_grenade_block },
	{ _field_block, "conical spread", &conical_projection_block },
	{ _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used." },
	{ _field_tag_reference, "killcam parameters# if not present, first person will be used." },
	{ _field_block, "Sound RTPCs", &ProjectileSoundRTPCBlock_block },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

