#pragma once

struct nicename("airstrike") tag_group('airs') s_airstrike_definition_legacy
{
	struct nicename("Airstrike") s_airstrike1_definition_legacy
	{
		struct nicename("Unknown 1") s_unknown_1_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
		};

		float nicename("Spread") spread;
		float __unknown0;
		float nicename("Initial Shot Delay") initial_shot_delay;
		float nicename("Time Armed") time_armed;
		float nicename("Recharge Time (seconds)") recharge_time_seconds;
		float nicename("Delay Between Shot") delay_between_shot;
		int32_t nicename("Total Shots Fired") total_shots_fired;
		int32_t nicename("Ammo Count") ammo_count;
		s_tag_reference_legacy nicename("Airstrike Firing Controller") airstrike_firing_controller_reference;
		s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
		s_tag_reference_legacy nicename("Affected Weapon") affected_weapon_reference;
	};

	s_tag_block_legacy<s_airstrike1_definition_legacy> nicename("Airstrike") airstrike_block;
};

