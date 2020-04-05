#pragma once

struct nicename("collision_damage") tag_group('cddf') s_collision_damage_definition
{
	float nicename("Apply Damage Scale") apply_damage_scale;
	float nicename("Apply Recoil Damage Scale") apply_recoil_damage_scale;
	float __unknown0;
	DataReference nicename("Function") function_data_reference;
	float nicename("Damage Acceleration min") damage_acceleration_min;
	float nicename("Damage Acceleration max") damage_acceleration_max;
	float __unknown1;
	float __unknown2;
	float nicename("Fall Resistance") fall_resistance;
	DataReference nicename("Function") function1_data_reference;
	float nicename("Recoil Damage Acceleration min") recoil_damage_acceleration_min;
	float nicename("Recoil Damage Acceleration max") recoil_damage_acceleration_max;
};

