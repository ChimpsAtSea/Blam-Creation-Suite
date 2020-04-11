#pragma once

struct nicename("airstrike") tag_group('airs') s_airstrike_definition
{
	struct nicename("Airstrike") s_airstrike1_definition
	{
		struct nicename("Unknown 1") s_unknown_1_definition
		{
			Undefined32 __unknown0;
			Undefined32 __unknown1;
		};

		float nicename("Spread") spread;
		float __unknown0;
		float nicename("Initial Shot Delay") initial_shot_delay;
		float nicename("Time Armed") time_armed;
		float nicename("Recharge Time (seconds)") recharge_time_seconds;
		float nicename("Delay Between Shot") delay_between_shot;
		int32_t nicename("Total Shots Fired") total_shots_fired;
		int32_t nicename("Ammo Count") ammo_count;
		TagReference nicename("Airstrike Firing Controller") airstrike_firing_controller_reference;
		s_tag_block_definition<s_unknown_1_definition> nicename("Unknown 1") unknown_1_block;
		TagReference nicename("Affected Weapon") affected_weapon_reference;
	};

	s_tag_block_definition<s_airstrike1_definition> nicename("Airstrike") airstrike_block;
};

