#pragma once

enum e_scenario_load_type : int16_t
{
	_scenario_load_none = -1,
	_scenario_load_default,
	_scenario_load_shared,
	_scenario_load_shared_campaign,
	_scenario_load_shared_multiplayer,
	k_number_of_scenario_load_types
};
