#pragma once

struct nicename("Damage Effect") group('jpt!') s_damage_effect_definition
{
	struct nicename("Special Damages") s_special_damage_block_definition;
	struct nicename("Ricochets") s_ricochet_block_definition;

	float nicename("Radius min") radius_min; 
	float nicename("Radius max") radius_max; 
	float nicename("Cutoff Scale") cutoff_scale; 
	int32_t nicename("Flags") flags; 
	int16_t nicename("Side Effect") side_effect; 
	int16_t nicename("Category") category; 
	int32_t nicename("Forced Death Dialogue") forced_death_dialogue; 
	int32_t nicename("Flags") flags2; 
	float nicename("Area Of Effect Core Radius") area_of_effect_core_radius; 
	float nicename("Damage Lower Bound") damage_lower_bound; 
	float nicename("Damage Upper Bound min") damage_upper_bound_min; 
	float nicename("Damage Upper Bound max") damage_upper_bound_max; 
	DataReference __unknown_data_reference; 
	float nicename("Damage Inner Cone Angle") damage_inner_cone_angle; 
	float nicename("Damage Outer Cone Angle") damage_outer_cone_angle; 
	float nicename("Active Camoflage Damage") active_camoflage_damage; 
	float nicename("Stun") stun; 
	float nicename("Max Stun") max_stun; 
	float nicename("Stun Time") stun_time; 
	int32_t __unknown2; 
	float nicename("Instantaneous Acceleration") instantaneous_acceleration; 
	float nicename("Rider Direct Damage Scale") rider_direct_damage_scale; 
	float nicename("Rider Max Transfer Damage") rider_max_transfer_damage; 
	float nicename("Rider Min Transfer Damage") rider_min_transfer_damage; 
	Undefined32 __unknown3; 
	string_id nicename("General Damage") general_damage; 
	string_id nicename("Specific Damage") specific_damage; 
	s_tag_block_definition<s_special_damage_block_definition> nicename("Special Damages") special_damages_block; 
	float nicename("AI Stun Radius") ai_stun_radius; 
	float nicename("AI Stun Bounds min") ai_stun_bounds_min; 
	float nicename("AI Stun Bounds max") ai_stun_bounds_max; 
	float nicename("Shake Radius") shake_radius; 
	float nicename("EMP Radius") emp_radius; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	float __unknown6; 
	TagReference nicename("Damage Response") damage_response_reference; 
	// comment
	TagReference nicename("Sound") sound_reference; 
	s_tag_block_definition<s_ricochet_block_definition> nicename("Ricochets") ricochets_block; 
	// comment
	float nicename("Forward Velocity") forward_velocity; 
	float nicename("Forward Radius") forward_radius; 
	float nicename("Forward Exponent") forward_exponent; 
	float nicename("Outward Velocity") outward_velocity; 
	float nicename("Outward Radius") outward_radius; 
	float nicename("Outward Exponent") outward_exponent; 

	struct nicename("special_damage") s_special_damage_block_definition
	{
		string_id nicename("Special Damage") special_damage; 
	};

	struct nicename("ricochet") s_ricochet_block_definition
	{
		TagReference nicename("Sound") sound_reference; 
		int16_t __unknown; 
		int16_t __unknown2; 
	};
};
