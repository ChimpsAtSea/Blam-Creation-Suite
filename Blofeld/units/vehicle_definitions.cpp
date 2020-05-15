#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(SoundRTPCBlock, k_maxSoundRTPCBlocks)
{
	{ _field_long_block_index, "Attachment Index#Sound attachment to affect" },
	{ _field_string_id, "Function#Function to drive the RTPC" },
	{ _field_string_id, "RTPC Name#WWise RTPC string name" },
	{ _field_long_integer, "RTPC name hash value*!" },
	{ _field_terminator },
};

TAG_BLOCK(SoundSweetenerBlock, k_maxSoundSweetenerBlocks)
{
	{ _field_string_id, "Function#Function to trigger the sweetener" },
	{ _field_tag_reference, "sound" },
	{ _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" },
	{ _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" },
	{ _field_terminator },
};

TAG_BLOCK(physics_transitions, k_max_vehicle_physics_transitions)
{
	{ _field_real, "transition velocity:wu/s#speed at which flight model transition occurs" },
	{ _field_real, "velocity threshold side: 0 or 1#0 if velocity should be smaller than transition value, else 1" },
	{ _field_real, "transition throttle:-1 to 1#throttle input at which physics model transition occurs" },
	{ _field_real, "throttle threshold side: 0 or 1#0 if throttle should be smaller than transition value, else 1" },
	{ _field_char_enum, "transition target vehicle type#upon reaching transition velocity, act like this vehicle type" },
	{ _field_pad, "pad after transition target vehicle type", 3 },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(vehicle, VEHICLE_TAG, unit, UNIT_TAG)
{
	{ _field_struct, "unit" },
	{ _field_custom, "$$$ VEHICLE $$$" },
	{ _field_long_flags, "flags" },
	{ _field_explanation, "physics type" },
	{ _field_struct, "physics types" },
	{ _field_explanation, "friction and antigravity points" },
	{ _field_struct, "havok vehicle physics" },
	{ _field_block, "tricks", &unit_trick_definition_block },
	{ _field_char_enum, "player training vehicle type" },
	{ _field_char_enum, "vehicle size#The size determine what kind of seats in larger vehicles it may occupy (i.e. small or large cargo seats)" },
	{ _field_char_integer, "complex suspension sample count#How many additional raycasts to perform per side of a tire." },
	{ _field_pad, "VQWHV", 1 },
	{ _field_angle, "complex suspension distribution angle:degrees#0-90 degrees of the wedge portion of the wheel to test suspension" },
	{ _field_real, "complex suspension wheel diameter" },
	{ _field_real, "complex suspension wheel width" },
	{ _field_real, "minimum flipping angular velocity" },
	{ _field_real, "maximum flipping angular velocity" },
	{ _field_real, "crouch transition time:seconds" },
	{ _field_real, "HOOJYTSU!" },
	{ _field_real, "seat enterance acceleration scale#how much do we scale the force the vehicle the applies down on the seat when he enters. 0 == no acceleration" },
	{ _field_real, "seat exit accelersation scale#how much do we scale the force the vehicle the applies down on the seat when he exits. 0 == no acceleration" },
	{ _field_real, "blur speed" },
	{ _field_string_id, "flip message" },
	{ _field_explanation, "sounds and effects" },
	{ _field_tag_reference, "Player vehicle sound bank#High quality player sound bank to be prefetched. Can be empty." },
	{ _field_tag_reference, "suspension sound" },
	{ _field_real, "fake audio speed - speed increase amount#amount to increase per frame while speeding up(.002 is a good number)" },
	{ _field_real, "fake audio speed - boost speed increase amount#amount to increase per frame while boosting (.006 is a good number)" },
	{ _field_real, "fake audio speed - speed decrease amount#amount to decrease per frame while slowing down (.002 is a good number)" },
	{ _field_real, "fake audio speed - non-boost limit#max value while not boosting (maximum is 1)" },
	{ _field_real, "fake audio speed - max speed scale#scales speed value. Must be > 0 for this to work (ie for banshee, 5 is good)" },
	{ _field_block, "Sound RTPCs", &SoundRTPCBlock_block },
	{ _field_block, "Sound Sweeteners", &SoundSweetenerBlock_block },
	{ _field_tag_reference, "special effect" },
	{ _field_tag_reference, "driver boost damage effect or response" },
	{ _field_tag_reference, "rider boost damage effect or response" },
	{ _field_string_id, "vehicle name" },
	{ _field_block, "physics transitions", &physics_transitions_block },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

