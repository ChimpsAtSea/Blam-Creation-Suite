#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT_FROM_BLOCK(biped, BIPED_TAG, unit, UNIT_TAG, biped_block_block )

TAG_BLOCK_FROM_STRUCT(biped_block, 1, biped_group_struct_definition );

TAG_BLOCK(biped_camera_height_block, 16)
{
	FIELD( _field_string_id, "weapon class^" ),
	FIELD( _field_real, "standing height:wu" ),
	FIELD( _field_real, "crouching height:wu" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(biped_wall_proximity_block, k_maximum_biped_proximity_feelers)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^" ),
	FIELD( _field_real, "search distance:wu" ),
	FIELD( _field_real, "compression time:s" ),
	FIELD( _field_real, "extension time:s" ),
	FIELD( _field_long_enum, "composition mode#if multiple markers share the same name, this specifies how to compose their search values" ),
	FIELD( _field_string_id, "output function name#creates an object function with this name that you can use to drive an overlay animation" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(biped_movement_gate_block, 16)
{
	FIELD( _field_real, "period:seconds" ),
	FIELD( _field_real, "z offset:world units" ),
	FIELD( _field_real, "constant z offset:world units#camera z is modified by this constant z value" ),
	FIELD( _field_real, "y offset:world units" ),
	FIELD( _field_real, "speed threshold:world units per second" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "default function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(contact_point_block, k_contact_point_count)
{
	FIELD( _field_useless_pad ),
	FIELD( _field_custom ),
	FIELD( _field_old_string_id, "marker name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(biped_grab_object_animation_set_block, k_max_biped_grab_object_animation_sets)
{
	FIELD( _field_string_id, "animation set name^" ),
	FIELD( _field_string_id, "attach marker#The marker on the biped to which we attach the grabbed object." ),
	FIELD( _field_real, "throw speed" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(BipedSoundRTPCBlock, k_maxBipedSoundRTPCBlocks)
{
	FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" ),
	FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
	FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(BipedSoundSweetenerBlock, k_maxBipedSoundSweetenerBlocks)
{
	FIELD( _field_string_id, "Function#Function to trigger the sweetener" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" ),
	FIELD( _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(BipedAimingJointFixupBlock, k_maximum_aiming_fixup_joints)
{
	FIELD( _field_string_id, "rotation_node^:bone to rotate to align marker" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^" ),
	FIELD( _field_angle_bounds, "yaw bounds:degrees" ),
	FIELD( _field_angle_bounds, "pitch bounds:degrees" ),
	FIELD( _field_real, "max yaw velocity:degrees per second" ),
	FIELD( _field_real, "max pitch velocity:degrees per second" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_group)
{
	FIELD( _field_struct, "unit", &unit_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ BIPED $$$" ),
	FIELD( _field_angle, "moving turning speed:degrees per second" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_angle, "stationary turning threshold" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_useless_pad ),
	FIELD( _field_tag_reference, "death program selector" ),
	FIELD( _field_string_id, "ragdoll region name#when the biped transitions to ragdoll, this region will change to the destroyed state" ),
	FIELD( _field_string_id, "assassination chud text#The string id for the assassination action text in the CHUD" ),
	FIELD( _field_explanation, "jumping and landing" ),
	FIELD( _field_real, "jump velocity:world units per second" ),
	FIELD( _field_block, "tricks", &unit_trick_definition_block_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_real, "maximum soft landing time:seconds#the longest amount of time the biped can take to recover from a soft landing" ),
	FIELD( _field_real, "maximum hard landing time:seconds#the longest amount of time the biped can take to recover from a hard landing" ),
	FIELD( _field_real, "minimum soft landing velocity:world units per second#below this velocity the biped does not react when landing" ),
	FIELD( _field_real, "minimum hard landing velocity:world units per second#below this velocity the biped will not do a soft landing when returning to the ground" ),
	FIELD( _field_real, "maximum hard landing velocity:world units per second#the velocity corresponding to the maximum landing time" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_real, "stun duration#0 is the default.  Bipeds are stunned when damaged by vehicle collisions, also some are when they take emp damage" ),
	FIELD( _field_explanation, "camera, collision, and autoaim" ),
	FIELD( _field_real, "standing camera height:world units" ),
	FIELD( _field_real, "running camera height:world units" ),
	FIELD( _field_real, "crouching camera height:world units" ),
	FIELD( _field_real, "crouch walking camera height:world units" ),
	FIELD( _field_real, "crouch transition time:seconds" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "camera height velocity function", &mapping_function_struct_definition ),
	FIELD( _field_block, "camera heights", &biped_camera_height_block_block ),
	FIELD( _field_angle, "camera interpolation start:degrees#looking-downward angle that starts camera interpolation to fp position" ),
	FIELD( _field_angle, "camera interpolation end:degrees#looking-downward angle at which camera interpolation to fp position is complete" ),
	FIELD( _field_real_vector_3d, "camera offset:wu#amount of fp camera movement in (forward, right, down) when pitched down by \'camera interpolation end\' above" ),
	FIELD( _field_real, "root offset camera scale" ),
	FIELD( _field_real, "root offset camera dampening" ),
	FIELD( _field_real, "autoaim width:world units" ),
	FIELD( _field_short_integer, "runtime physics control node index!" ),
	FIELD( _field_pad, "JWSSY", 2 ),
	FIELD( _field_real, "runtime cosine stationary turning threshold!" ),
	FIELD( _field_real, "runtime crouch transition velocity!*" ),
	FIELD( _field_real, "runtime_camera_height_velocity!*" ),
	FIELD( _field_short_integer, "runtime pelvis node index!" ),
	FIELD( _field_short_integer, "runtime head node index!" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_block, "wall proximity feelers", &biped_wall_proximity_block_block ),
	FIELD( _field_tag_reference, "area damage effect" ),
	FIELD( _field_tag_reference, "health station recharge effect" ),
	FIELD( _field_block, "movement gates", &biped_movement_gate_block_block ),
	FIELD( _field_block, "movement gates crouching", &biped_movement_gate_block_block ),
	FIELD( _field_real, "jump aim offset distance:world units" ),
	FIELD( _field_real, "jump aim offset duration:seconds" ),
	FIELD( _field_real, "land aim offset distance:world units" ),
	FIELD( _field_real, "land aim offset duration:seconds" ),
	FIELD( _field_real, "aim compensate minimum distance:world units" ),
	FIELD( _field_real, "aim compensate maximum distance:world units" ),
	FIELD( _field_struct, "physics", &character_physics_struct_struct_definition ),
	FIELD( _field_block, "contact points#these are the points where the biped touches the ground", &contact_point_block_block ),
	FIELD( _field_tag_reference, "reanimation character#when the flood reanimate this guy, he turns into a ..." ),
	FIELD( _field_tag_reference, "reanimation/morph muffins#the kind of muffins I create to cover my horrible transformation" ),
	FIELD( _field_tag_reference, "death spawn character#when I die, out of the ashes of my death crawls a ..." ),
	FIELD( _field_short_integer, "death spawn count" ),
	FIELD( _field_pad, "TQYQEWG", 2 ),
	FIELD( _field_struct, "leaping data", &biped_leaping_data_struct_struct_definition ),
	FIELD( _field_struct, "vaulting data", &biped_vaulting_data_struct_struct_definition ),
	FIELD( _field_struct, "grab biped data", &biped_grab_biped_data_struct_struct_definition ),
	FIELD( _field_struct, "grab object data", &biped_grab_object_data_struct_struct_definition ),
	FIELD( _field_struct, "ground fitting data", &biped_ground_fitting_data_struct_struct_definition ),
	FIELD( _field_tag_reference, "death particleize#optional particleization effect definition, if you want this to particleize when it dies" ),
	FIELD( _field_real, "movement speed scale" ),
	FIELD( _field_struct, "movement hip lean", &BipedMovementHipLeaningStruct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_tag_reference, "Player biped sound bank#Intended for biped vehicles (ie mantis)" ),
	FIELD( _field_tag_reference, "RegenField Looping Sound#plays when player is inside a RegenField" ),
	FIELD( _field_tag_reference, "Crouch down sound#plays when player starts crouching" ),
	FIELD( _field_tag_reference, "Crouch up sound#plays when player stands up" ),
	FIELD( _field_tag_reference, "Shield impact override#overrides shield impact sound, like when in a Mantis" ),
	FIELD( _field_tag_reference, "Non shield impact override#overrides regular impact sound, like when in a Mantis" ),
	FIELD( _field_real, "Sound radius multiplier#increases radius of other sounds when piloting this biped (mech)" ),
	FIELD( _field_block, "Sound RTPCs", &BipedSoundRTPCBlock_block ),
	FIELD( _field_block, "Sound Sweeteners", &BipedSoundSweetenerBlock_block ),
	FIELD( _field_block, "Aiming Fixup", &BipedAimingJointFixupBlock_block ),
	FIELD( _field_tag_reference, "Self Illumination" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_leaping_data_struct)
{
	FIELD( _field_custom, "wall-leaping" ),
	FIELD( _field_explanation, "wall-leaping fields" ),
	FIELD( _field_long_flags, "leap flags" ),
	FIELD( _field_real_fraction, "dampening scale:[0,1] 1= very slow changes" ),
	FIELD( _field_real_fraction, "roll delay:[0,1] 1= roll fast and late" ),
	FIELD( _field_real_fraction, "cannonball off-axis scale:[0,1] weight" ),
	FIELD( _field_real_fraction, "cannonball off-track scale:[0,1] weight" ),
	FIELD( _field_angle_bounds, "cannonball roll bounds:degrees per second" ),
	FIELD( _field_real_bounds, "anticipation ratio bounds:current velocity/leap velocity" ),
	FIELD( _field_real_bounds, "reaction force bounds:units per second" ),
	FIELD( _field_real_fraction, "lobbing desire:1= heavy arc, 0= no arc" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_vaulting_data_struct)
{
	FIELD( _field_custom, "vaulting" ),
	FIELD( _field_explanation, "vaulting fields" ),
	FIELD( _field_real_bounds, "vault height bounds:wus" ),
	FIELD( _field_real, "vault max horizontal distance:wus" ),
	FIELD( _field_real_fraction, "vault arc amount:1= heavy arc, 0= no arc" ),
	FIELD( _field_real, "vault min object size:wus" ),
	FIELD( _field_real, "search width:wus, the side-to-side width of the search path" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_grab_biped_data_struct)
{
	FIELD( _field_custom, "grab biped" ),
	FIELD( _field_explanation, "grab biped fields" ),
	FIELD( _field_string_id, "grab biped animation class" ),
	FIELD( _field_char_enum, "throw biped control mode" ),
	FIELD( _field_pad, "hurgh", 3 ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_grab_object_data_struct)
{
	FIELD( _field_custom, "grab object" ),
	FIELD( _field_explanation, "grab object fields" ),
	FIELD( _field_block, "grab object animation sets", &biped_grab_object_animation_set_block_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(biped_ground_fitting_data_struct)
{
	FIELD( _field_custom, "ground fitting" ),
	FIELD( _field_explanation, "ground fitting data" ),
	FIELD( _field_long_flags, "ground fitting flags" ),
	FIELD( _field_real_fraction, "ground normal dampening:react to slope changes (0=slow, 1= fast)" ),
	FIELD( _field_real, "root offset max scale idle{root offset max scale}:vertical drop to ground allowed (0=none, 1=full)" ),
	FIELD( _field_real, "root offset max scale moving:vertical drop to ground allowed (0=none, 1=full)" ),
	FIELD( _field_real_fraction, "root offset dampening:react to root changes (0=slow, 1= fast)" ),
	FIELD( _field_real_fraction, "following cam scale:root offset effect on following cam (0=none, 1=full)" ),
	FIELD( _field_real_fraction, "root leaning scale:lean into slopes (0=none, 1=full)" ),
	FIELD( _field_real, "stance width scale:scale pill width to use as stance radius" ),
	FIELD( _field_angle, "foot roll max:orient to ground slope (degrees)" ),
	FIELD( _field_angle, "foot pitch max:orient to ground slope (degrees)" ),
	FIELD( _field_real_fraction, "foot normal dampening:(0=slow, 1= fast)" ),
	FIELD( _field_real, "foot fitting test distance" ),
	FIELD( _field_real_fraction, "foot displacement upward dampening:(0=slow, 1= fast)" ),
	FIELD( _field_real_fraction, "foot displacement downward dampening:(0=slow, 1= fast)" ),
	FIELD( _field_real, "foot pull threshold distance idle:amount past the authored plane the foot can be pulled (wu)" ),
	FIELD( _field_real, "foot pull threshold distance moving:amount past the authored plane the foot can be pulled (wu)" ),
	FIELD( _field_real, "foot turn minimum radius:minimum radius at which foot is fit to turn radius" ),
	FIELD( _field_real, "foot turn maximum radius:maximum radius at which foot is fit to turn radius" ),
	FIELD( _field_real, "foot turn threshold radius:foot is fit to turn radius fully at minimum plus threshold and above" ),
	FIELD( _field_real, "foot turn rate dampening:(0=slow, 1=fast)" ),
	FIELD( _field_real, "foot turn weight dampening:dampening of fitting value for fit to turn radius(0=none, 1=fast)" ),
	FIELD( _field_real, "foot turn blend on time:time to blend on the foot turn effect (seconds)" ),
	FIELD( _field_real, "foot turn blend off time:time to blend off the foot turn effect (seconds)" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "pivot-on-foot" ),
	FIELD( _field_explanation, "pivot-on-foot data" ),
	FIELD( _field_real_fraction, "pivot-on-foot scale: (0=none, 1= full)" ),
	FIELD( _field_real, "pivot min foot delta: vert world units to find lowest foot" ),
	FIELD( _field_real, "pivot stride length scale: leg length * this = stride length" ),
	FIELD( _field_real_fraction, "pivot throttle scale:pivoting slows throttle (0=none, 1= full)" ),
	FIELD( _field_real_fraction, "pivot offset dampening:react to pivot changes (0=slow, 1= fast)" ),
	FIELD( _field_real_fraction, "pivot force turn rate:turn no matter what the pivot state is (0=control turn, 1= always turn)" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ground fitting pelvis elevation settings" ),
	FIELD( _field_real, "ideal pelvis over high foot scale: ratio of pedestal to pelvis distance #ideal ratio of distance from the pelvis to pedestal to place pelvis over the highest foot" ),
	FIELD( _field_real, "ideal pelvis over low foot scale: ratio of pedestal to pelvis distance #ideal ratio of distance from the pelvis to pedestal to place pelvis over the lowest foot" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ledge Push" ),
	FIELD( _field_explanation, "Pushing over Ledges" ),
	FIELD( _field_real, "push over mag: magnitude of throttle to push over ledges. 0= no push" ),
	FIELD( _field_real, "push back mag: magnitude of throttle to push back from ledges. 0= no push" ),
	FIELD( _field_real, "ledgeIKSuccessRange: when unable to IK at least this close, consider the IK failed." ),
	FIELD( _field_real, "ledge warning time: secs to warn the player before pushing over a ledge" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Foot locking" ),
	FIELD( _field_real, "footlock Scale: (0-1) #how much this biped respects foot lock events" ),
	FIELD( _field_real, "footlock Min Throttle: (0-1) #throttle at which foot lock should be fully on (footlockScale)" ),
	FIELD( _field_real, "footlock Max Throttle: (0-1) #throttle at which foot lock should be fully off" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(BipedMovementHipLeaningStruct)
{
	FIELD( _field_custom, "Movement Hip Leaning" ),
	FIELD( _field_explanation, "Movement Hip Leaning" ),
	FIELD( _field_real, "prediction seconds:predict ahead to determine lean. 0= off, more time=more lean" ),
	FIELD( _field_real, "max lean angle:(degrees) maximum lean amount" ),
	FIELD( _field_real_fraction, "max vertical dip:(fraction of leg length)" ),
	FIELD( _field_real, "max lean angle sine:set on post-process, don\'t edit!*" ),
	FIELD( _field_real, "max lean angle cosine:set on post-process, don\'t edit!*" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

