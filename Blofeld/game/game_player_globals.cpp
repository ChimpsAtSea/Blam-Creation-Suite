#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(player_information, k_player_character_type_count)
{
	FIELD( _field_real, "walking speed:world units per second" ),
	FIELD( _field_real, "run forward:world units per second" ),
	FIELD( _field_real, "run backward:world units per second" ),
	FIELD( _field_real, "run sideways:world units per second" ),
	FIELD( _field_real, "run acceleration:world units per second squared" ),
	FIELD( _field_real, "sneak forward:world units per second" ),
	FIELD( _field_real, "sneak backward:world units per second" ),
	FIELD( _field_real, "sneak sideways:world units per second" ),
	FIELD( _field_real, "sneak acceleration:world units per second squared" ),
	FIELD( _field_real, "airborne acceleration:world units per second squared" ),
	FIELD( _field_real, "weapon ready anim scaler" ),
	FIELD( _field_real_point_3d, "grenade origin" ),
	FIELD( _field_struct, "grenade aiming#determines the distance along the aiming vector to orient the grenade based on the camera pitch" ),
	FIELD( _field_real_bounds, "first person idle time:seconds" ),
	FIELD( _field_real_fraction, "first person skip fraction:[0,1]" ),
	FIELD( _field_tag_reference, "coop countdown sound" ),
	FIELD( _field_tag_reference, "coop respawn sound" ),
	FIELD( _field_tag_reference, "coop respawn effect" ),
	FIELD( _field_tag_reference, "hologram death effect" ),
	FIELD( _field_long_integer, "binoculars zoom count" ),
	FIELD( _field_real_bounds, "binoculars zoom range" ),
	FIELD( _field_tag_reference, "night vision on{flashlight on}" ),
	FIELD( _field_tag_reference, "night vision off{flashlight off}" ),
	FIELD( _field_real, "fire team objective range" ),
	FIELD( _field_real, "fire team sandbox range" ),
	FIELD( _field_real, "fire team cone angle: in degrees" ),
	FIELD( _field_explanation, "sprinting/momentum" ),
	FIELD( _field_block, "momentum and sprinting", &player_momentum_data_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_momentum_data, k_player_momentum_count)
{
	FIELD( _field_byte_flags, "flag" ),
	FIELD( _field_pad, "PAD", 3 ),
	FIELD( _field_real, "seconds to start#how long you must be pegged before you gain momentum" ),
	FIELD( _field_real, "seconds to full speed#how long you must have momentum before you reach top speed" ),
	FIELD( _field_real, "decay rate#how fast being unpegged decays the timer (seconds per second)" ),
	FIELD( _field_real, "full speed multiplier#how much faster we actually go when at full momentum" ),
	FIELD( _field_real, "sprint turn multiplier#how much faster to turn when sprinting" ),
	FIELD( _field_real, "pegged magnitude#how far the stick needs to be pressed before being considered pegged" ),
	FIELD( _field_real, "pegged angular threshold#how far off straight up (in degrees) we consider pegged" ),
	FIELD( _field_angle, "max look yaw velocity:degrees per second" ),
	FIELD( _field_angle, "max look pitch velocity:degrees per second" ),
	FIELD( _field_real, "minimum player velocity to be considered in a momentum state:world units per second" ),
	FIELD( _field_real, "look window length:seconds#period of time over which we record the biped\'s look angle for deciding if we should drop him out of momentum" ),
	FIELD( _field_string_id, "momentum animation stance" ),
	FIELD( _field_real, "min weapon error#[0, 1] while using this type of momentum, the player\'s weapon error cannot drop below this value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_representation, k_player_character_type_count)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_tag_reference, "first person hands model" ),
	FIELD( _field_string_id, "first person multiplayer hands variant" ),
	FIELD( _field_tag_reference, "first person body model" ),
	FIELD( _field_string_id, "first person multiplayer body variant" ),
	FIELD( _field_block, "hidden fpBody regions", &firstPersonpHiddenBodyRegionsBlock_block ),
	FIELD( _field_tag_reference, "third person unit" ),
	FIELD( _field_string_id, "third person variant" ),
	FIELD( _field_tag_reference, "binoculars zoom in sound" ),
	FIELD( _field_tag_reference, "binoculars zoom out sounds" ),
	FIELD( _field_long_block_index, "player information" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(firstPersonpHiddenBodyRegionsBlock, 32)
{
	FIELD( _field_string_id, "hidden region^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

