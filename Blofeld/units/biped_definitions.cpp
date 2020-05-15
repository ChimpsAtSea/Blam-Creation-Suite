#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(biped_camera_height, 16)
{
	FIELD( _field_string_id, "weapon class^" ),
	FIELD( _field_real, "standing height:wu" ),
	FIELD( _field_real, "crouching height:wu" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(biped_wall_proximity, k_maximum_biped_proximity_feelers)
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

TAG_BLOCK(biped_movement_gate, 16)
{
	FIELD( _field_real, "period:seconds" ),
	FIELD( _field_real, "z offset:world units" ),
	FIELD( _field_real, "constant z offset:world units#camera z is modified by this constant z value" ),
	FIELD( _field_real, "y offset:world units" ),
	FIELD( _field_real, "speed threshold:world units per second" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "default function" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(contact_point, k_contact_point_count)
{
	FIELD( _field_useless_pad ),
	FIELD( _field_custom ),
	FIELD( _field_old_string_id, "marker name^" ),
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

TAG_GROUP_INHERIT(biped, BIPED_TAG, unit, UNIT_TAG)
{
	FIELD( _field_struct, "unit" ),
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
	FIELD( _field_block, "tricks", &unit_trick_definition_block ),
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
	FIELD( _field_struct, "camera height velocity function" ),
	FIELD( _field_block, "camera heights", &biped_camera_height_block ),
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
	FIELD( _field_block, "wall proximity feelers", &biped_wall_proximity_block ),
	FIELD( _field_tag_reference, "area damage effect" ),
	FIELD( _field_tag_reference, "health station recharge effect" ),
	FIELD( _field_block, "movement gates", &biped_movement_gate_block ),
	FIELD( _field_block, "movement gates crouching", &biped_movement_gate_block ),
	FIELD( _field_real, "jump aim offset distance:world units" ),
	FIELD( _field_real, "jump aim offset duration:seconds" ),
	FIELD( _field_real, "land aim offset distance:world units" ),
	FIELD( _field_real, "land aim offset duration:seconds" ),
	FIELD( _field_real, "aim compensate minimum distance:world units" ),
	FIELD( _field_real, "aim compensate maximum distance:world units" ),
	FIELD( _field_struct, "physics" ),
	FIELD( _field_block, "contact points#these are the points where the biped touches the ground", &contact_point_block ),
	FIELD( _field_tag_reference, "reanimation character#when the flood reanimate this guy, he turns into a ..." ),
	FIELD( _field_tag_reference, "reanimation/morph muffins#the kind of muffins I create to cover my horrible transformation" ),
	FIELD( _field_tag_reference, "death spawn character#when I die, out of the ashes of my death crawls a ..." ),
	FIELD( _field_short_integer, "death spawn count" ),
	FIELD( _field_pad, "TQYQEWG", 2 ),
	FIELD( _field_struct, "leaping data" ),
	FIELD( _field_struct, "vaulting data" ),
	FIELD( _field_struct, "grab biped data" ),
	FIELD( _field_struct, "grab object data" ),
	FIELD( _field_struct, "ground fitting data" ),
	FIELD( _field_tag_reference, "death particleize#optional particleization effect definition, if you want this to particleize when it dies" ),
	FIELD( _field_real, "movement speed scale" ),
	FIELD( _field_struct, "movement hip lean" ),
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

} // namespace blofeld

