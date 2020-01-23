#pragma once

struct nicename("Collision Damage") group('cddf') s_collision_damage_definition
{
	float nicename("Apply Damage Scale") apply_damage_scale; 
	float nicename("Apply Recoil Damage Scale") apply_recoil_damage_scale; 
	float __unknown; 
	DataReference nicename("Function") function_data_reference; 
	float nicename("Damage Acceleration min") damage_acceleration_min; 
	float nicename("Damage Acceleration max") damage_acceleration_max; 
	float __unknown2; 
	float __unknown3; 
	float nicename("Fall Resistance") fall_resistance; 
	DataReference nicename("Function") function2_data_reference; 
	float nicename("Recoil Damage Acceleration min") recoil_damage_acceleration_min; 
	float nicename("Recoil Damage Acceleration max") recoil_damage_acceleration_max; 
};
