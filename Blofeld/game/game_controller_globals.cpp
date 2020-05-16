#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(gamepad_stick_info_block, 1)
{
	FIELD( _field_char_enum, "input shape" ),
	FIELD( _field_pad, "F", 3 ),
	FIELD( _field_real_fraction, "peg threshold [0,1]#magnitude of analog input for pegged acceleration to kick in" ),
	FIELD( _field_real_point_2d, "pegged time#time for a pegged look to reach maximum effect" ),
	FIELD( _field_real_point_2d, "pegged scale#the maximum effect achieved over the duration of the pegged time." ),
	FIELD( _field_angle, "peg max angular velocity:degrees per sec#the maximum turning speed during peg" ),
	FIELD( _field_block, "input mapping function", &input_mapping_function_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(input_mapping_function_block, 1)
{
	FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(controller_input_block, 1)
{
	FIELD( _field_real, "axial dead zone" ),
	FIELD( _field_real, "radial dead zone" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(player_control_block, 1)
{
	FIELD( _field_block, "controller button mappings", &controller_mapping_reference_block_block ),
	FIELD( _field_block, "move stick info", &gamepad_stick_info_block_block ),
	FIELD( _field_block, "look stick info", &gamepad_stick_info_block_block ),
	FIELD( _field_real_fraction, "magnetism friction#how much the crosshair slows over enemies" ),
	FIELD( _field_real_fraction, "magnetism adhesion#how much the crosshair sticks to enemies" ),
	FIELD( _field_real_fraction, "inconsequential target scale#scales magnetism level for inconsequential targets like infection forms" ),
	FIELD( _field_explanation, "crosshair" ),
	FIELD( _field_real_point_2d, "crosshair location#-1..1, 0 is middle of the screen" ),
	FIELD( _field_explanation, "fireteam" ),
	FIELD( _field_real, "fireteam command mode duration:seconds#How long is command mode on after you initially attempt to issue an order" ),
	FIELD( _field_explanation, "looking" ),
	FIELD( _field_real, "look autolevelling scale#1 is fast, 0 is none, >1 will probably be really fast" ),
	FIELD( _field_real, "gravity_scale" ),
	FIELD( _field_pad, "VM", 2 ),
	FIELD( _field_short_integer, "minimum autolevelling ticks#amount of time player needs to move and not look up or down for autolevelling to kick in" ),
	FIELD( _field_angle, "minimum angle for vehicle flipping#0 means the vehicle\'s up vector is along the ground, 90 means the up vector is pointing straight up:degrees" ),
	FIELD( _field_explanation, "weapons may optionally be set to require extra button hold time (e.g. ordnance power weapon drops)" ),
	FIELD( _field_real, "minimum action hold time:seconds#time that player needs to press ACTION to register as a HOLD" ),
	FIELD( _field_real, "minimum action hold time for teammates:seconds#teammates of player who dropped/spawned weapon" ),
	FIELD( _field_real, "minimum action hold time for opponents:seconds#opponents of player who dropped/spawned weapon" ),
	FIELD( _field_real, "pegged zoom supression threshold#for spinny-shotgun goodness" ),
	FIELD( _field_explanation, "double/triple jump" ),
	FIELD( _field_real, "minimum vertical velocity:wu/s" ),
	FIELD( _field_real, "cooldown time:seconds" ),
	FIELD( _field_real_vector_2d, "double jump velocity:horizontal, vertical" ),
	FIELD( _field_real_vector_2d, "triple jump velocity:aiming, vertical" ),
	FIELD( _field_explanation, "stick throws" ),
	FIELD( _field_real, "throw channel width#how close to an axis you have to be" ),
	FIELD( _field_real, "throw peg threshold#how far from the center you have to be" ),
	FIELD( _field_real, "throw centered min time:s#how long the stick must be centered to start a throw" ),
	FIELD( _field_real, "throw drawing max time:s#how long you can take to become pegged at the start of a throw" ),
	FIELD( _field_real, "throw drawn max time:s#how long you can stay pegged at the start of a throw" ),
	FIELD( _field_real, "throw throwing max time:s#how long you can take to throw the stick to pegged on the other side" ),
	FIELD( _field_real, "flick peg jump max time:s#max time you can be pegged and then press jump to activate" ),
	FIELD( _field_real, "double tap interval time:s#to engage double-tap, user must press jump twice in this much time" ),
	FIELD( _field_explanation, "Jump Assist" ),
	FIELD( _field_real, "vault_speed_gain" ),
	FIELD( _field_real, "vaultSprint_speed_gain" ),
	FIELD( _field_real, "vault_height_high" ),
	FIELD( _field_real, "vaultSprint_height_high" ),
	FIELD( _field_real, "vault_height_medium" ),
	FIELD( _field_real, "vaultSprint_height_medium" ),
	FIELD( _field_real, "vault_height_min" ),
	FIELD( _field_real, "vaultSprint_height_min" ),
	FIELD( _field_real, "vault_height_traverse" ),
	FIELD( _field_real, "vaultSprint_height_traverse" ),
	FIELD( _field_real, "vault_max_downward_distance" ),
	FIELD( _field_real, "vaultSprint_max_downward_distance" ),
	FIELD( _field_real, "vault_max_distance" ),
	FIELD( _field_real, "vaultSprint_max_distance" ),
	FIELD( _field_real, "vault_gravity_gain" ),
	FIELD( _field_real, "vaultSprint_gravity_gain" ),
	FIELD( _field_real, "vault_stationary_probe_distance" ),
	FIELD( _field_real, "vault_stationary_probe_angle" ),
	FIELD( _field_real, "vault_stationary_probe_min_z" ),
	FIELD( _field_real, "vault_lateral_speed_gain" ),
	FIELD( _field_real, "vaultSprint_lateral_speed_gain" ),
	FIELD( _field_real, "jump_air_control_gain" ),
	FIELD( _field_real, "jump_forward_horizontal_speed_0" ),
	FIELD( _field_real, "jump_forward_horizontal_speed_1" ),
	FIELD( _field_real, "jump_forward_horizontal_speed_2" ),
	FIELD( _field_real, "jump_forward_gravity_0" ),
	FIELD( _field_real, "jump_forward_gravity_1" ),
	FIELD( _field_real, "jump_forward_gravity_2" ),
	FIELD( _field_real, "jump_forward_height" ),
	FIELD( _field_real, "jump_lateral_horizontal_speed_0" ),
	FIELD( _field_real, "jump_lateral_horizontal_speed_1" ),
	FIELD( _field_real, "jump_lateral_horizontal_speed_2" ),
	FIELD( _field_real, "jump_lateral_gravity_0" ),
	FIELD( _field_real, "jump_lateral_gravity_1" ),
	FIELD( _field_real, "jump_lateral_gravity_2" ),
	FIELD( _field_real, "jump_lateral_height" ),
	FIELD( _field_real, "jump_reverse_horizontal_speed_0" ),
	FIELD( _field_real, "jump_reverse_horizontal_speed_1" ),
	FIELD( _field_real, "jump_reverse_horizontal_speed_2" ),
	FIELD( _field_real, "jump_reverse_gravity_0" ),
	FIELD( _field_real, "jump_reverse_gravity_1" ),
	FIELD( _field_real, "jump_reverse_gravity_2" ),
	FIELD( _field_real, "jump_reverse_height" ),
	FIELD( _field_real, "jump_stationary_horizontal_speed_0" ),
	FIELD( _field_real, "jump_stationary_horizontal_speed_1" ),
	FIELD( _field_real, "jump_stationary_horizontal_speed_2" ),
	FIELD( _field_real, "jump_stationary_gravity_0" ),
	FIELD( _field_real, "jump_stationary_gravity_1" ),
	FIELD( _field_real, "jump_stationary_gravity_2" ),
	FIELD( _field_real, "jump_stationary_height" ),
	FIELD( _field_real, "Downward_Vault_Min_Laterial_Distance" ),
	FIELD( _field_real, "Vault_AutoCorrect_MaxAngle" ),
	FIELD( _field_real, "Vault ideal distance#When several via vault targets are found, vaults closer to this distance are more likely to be chosen" ),
	FIELD( _field_real, "Vault Sprint ideal distance#When several via vault targets are found, vaults closer to this distance are more likely to be chosen" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(controller_mapping_reference_block, k_button_presets_count)
{
	FIELD( _field_tag_reference, "mapping" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

