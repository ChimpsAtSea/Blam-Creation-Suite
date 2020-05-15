#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(SoundRTPCBlock, k_maxSoundRTPCBlocks)
{
	FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect" ),
	FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
	FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
	FIELD( _field_long_integer, "RTPC name hash value*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SoundSweetenerBlock, k_maxSoundSweetenerBlocks)
{
	FIELD( _field_string_id, "Function#Function to trigger the sweetener" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" ),
	FIELD( _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_transitions, k_max_vehicle_physics_transitions)
{
	FIELD( _field_real, "transition velocity:wu/s#speed at which flight model transition occurs" ),
	FIELD( _field_real, "velocity threshold side: 0 or 1#0 if velocity should be smaller than transition value, else 1" ),
	FIELD( _field_real, "transition throttle:-1 to 1#throttle input at which physics model transition occurs" ),
	FIELD( _field_real, "throttle threshold side: 0 or 1#0 if throttle should be smaller than transition value, else 1" ),
	FIELD( _field_char_enum, "transition target vehicle type#upon reaching transition velocity, act like this vehicle type" ),
	FIELD( _field_pad, "pad after transition target vehicle type", 3 ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(vehicle, VEHICLE_TAG, unit, UNIT_TAG)
{
	FIELD( _field_struct, "unit" ),
	FIELD( _field_custom, "$$$ VEHICLE $$$" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "physics type" ),
	FIELD( _field_struct, "physics types" ),
	FIELD( _field_explanation, "friction and antigravity points" ),
	FIELD( _field_struct, "havok vehicle physics" ),
	FIELD( _field_block, "tricks", &unit_trick_definition_block ),
	FIELD( _field_char_enum, "player training vehicle type" ),
	FIELD( _field_char_enum, "vehicle size#The size determine what kind of seats in larger vehicles it may occupy (i.e. small or large cargo seats)" ),
	FIELD( _field_char_integer, "complex suspension sample count#How many additional raycasts to perform per side of a tire." ),
	FIELD( _field_pad, "VQWHV", 1 ),
	FIELD( _field_angle, "complex suspension distribution angle:degrees#0-90 degrees of the wedge portion of the wheel to test suspension" ),
	FIELD( _field_real, "complex suspension wheel diameter" ),
	FIELD( _field_real, "complex suspension wheel width" ),
	FIELD( _field_real, "minimum flipping angular velocity" ),
	FIELD( _field_real, "maximum flipping angular velocity" ),
	FIELD( _field_real, "crouch transition time:seconds" ),
	FIELD( _field_real, "HOOJYTSU!" ),
	FIELD( _field_real, "seat enterance acceleration scale#how much do we scale the force the vehicle the applies down on the seat when he enters. 0 == no acceleration" ),
	FIELD( _field_real, "seat exit accelersation scale#how much do we scale the force the vehicle the applies down on the seat when he exits. 0 == no acceleration" ),
	FIELD( _field_real, "blur speed" ),
	FIELD( _field_string_id, "flip message" ),
	FIELD( _field_explanation, "sounds and effects" ),
	FIELD( _field_tag_reference, "Player vehicle sound bank#High quality player sound bank to be prefetched. Can be empty." ),
	FIELD( _field_tag_reference, "suspension sound" ),
	FIELD( _field_real, "fake audio speed - speed increase amount#amount to increase per frame while speeding up(.002 is a good number)" ),
	FIELD( _field_real, "fake audio speed - boost speed increase amount#amount to increase per frame while boosting (.006 is a good number)" ),
	FIELD( _field_real, "fake audio speed - speed decrease amount#amount to decrease per frame while slowing down (.002 is a good number)" ),
	FIELD( _field_real, "fake audio speed - non-boost limit#max value while not boosting (maximum is 1)" ),
	FIELD( _field_real, "fake audio speed - max speed scale#scales speed value. Must be > 0 for this to work (ie for banshee, 5 is good)" ),
	FIELD( _field_block, "Sound RTPCs", &SoundRTPCBlock_block ),
	FIELD( _field_block, "Sound Sweeteners", &SoundSweetenerBlock_block ),
	FIELD( _field_tag_reference, "special effect" ),
	FIELD( _field_tag_reference, "driver boost damage effect or response" ),
	FIELD( _field_tag_reference, "rider boost damage effect or response" ),
	FIELD( _field_string_id, "vehicle name" ),
	FIELD( _field_block, "physics transitions", &physics_transitions_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

