#pragma once

#pragma once

enum e_life_cycle_join_result : uint32_t
{
	_life_cycle_join_result_none = 0,
	_life_cycle_join_result_in_progress,
	_life_cycle_join_result_generic_error,
	_life_cycle_join_result_failed_to_find_session,
	_life_cycle_join_result_not_enough_space,
	_life_cycle_join_result_game_not_open,
	_life_cycle_join_result_target_is_matchmaking,
	_life_cycle_join_result_host_timed_out,
	_life_cycle_join_result_peer_version_too_low,
	_life_cycle_join_result_host_version_too_low,
	_life_cycle_join_result_unable_to_connect_open_nat,
	_life_cycle_join_result_unable_to_connect_moderate_nat,
	_life_cycle_join_result_unable_to_connect_strict_nat,
	_life_cycle_join_result_unable_to_connect_party_open_nat,
	_life_cycle_join_result_unable_to_connect_party_moderate_nat,
	_life_cycle_join_result_unable_to_connect_party_strict_nat,
	_life_cycle_join_result_player_not_online_enabled,
	_life_cycle_join_result_target_has_film_in_progress,
	_life_cycle_join_result_target_has_campaign,
	_life_cycle_join_result_user_content_not_permitted,
	_life_cycle_join_result_target_has_survival,
	k_number_of_life_cycle_join_results,
};

static constexpr const char* life_cycle_join_result_to_string(e_life_cycle_join_result life_cycle_join_result)
{
	switch (life_cycle_join_result)
	{
	case _life_cycle_join_result_none:												return "_life_cycle_join_result_none";									
	case _life_cycle_join_result_in_progress:										return "_life_cycle_join_result_in_progress";
	case _life_cycle_join_result_generic_error:										return "_life_cycle_join_result_generic_error";
	case _life_cycle_join_result_failed_to_find_session:							return "_life_cycle_join_result_failed_to_find_session";
	case _life_cycle_join_result_not_enough_space:									return "_life_cycle_join_result_not_enough_space";
	case _life_cycle_join_result_game_not_open:										return "_life_cycle_join_result_game_not_open";
	case _life_cycle_join_result_target_is_matchmaking:								return "_life_cycle_join_result_target_is_matchmaking";
	case _life_cycle_join_result_host_timed_out:									return "_life_cycle_join_result_host_timed_out";
	case _life_cycle_join_result_peer_version_too_low:								return "_life_cycle_join_result_peer_version_too_low";
	case _life_cycle_join_result_host_version_too_low:								return "_life_cycle_join_result_host_version_too_low";
	case _life_cycle_join_result_unable_to_connect_open_nat:						return "_life_cycle_join_result_unable_to_connect_open_nat";
	case _life_cycle_join_result_unable_to_connect_moderate_nat:					return "_life_cycle_join_result_unable_to_connect_moderate_nat";
	case _life_cycle_join_result_unable_to_connect_strict_nat:						return "_life_cycle_join_result_unable_to_connect_strict_nat";
	case _life_cycle_join_result_unable_to_connect_party_open_nat:					return "_life_cycle_join_result_unable_to_connect_party_open_nat";
	case _life_cycle_join_result_unable_to_connect_party_moderate_nat:				return "_life_cycle_join_result_unable_to_connect_party_moderate_nat";
	case _life_cycle_join_result_unable_to_connect_party_strict_nat:				return "_life_cycle_join_result_unable_to_connect_party_strict_nat";
	case _life_cycle_join_result_player_not_online_enabled:							return "_life_cycle_join_result_player_not_online_enabled";
	case _life_cycle_join_result_target_has_film_in_progress:						return "_life_cycle_join_result_target_has_film_in_progress";
	case _life_cycle_join_result_target_has_campaign:								return "_life_cycle_join_result_target_has_campaign";
	case _life_cycle_join_result_user_content_not_permitted:						return "_life_cycle_join_result_user_content_not_permitted";
	case _life_cycle_join_result_target_has_survival:								return "_life_cycle_join_result_target_has_survival";
	}
	return nullptr;
}

static inline e_life_cycle_join_result string_to_life_cycle_join_result(const char* life_cycle_join_result_string)
{
	for (underlying(e_life_cycle_join_result) current_life_cycle_join_result = 0; current_life_cycle_join_result < k_number_of_life_cycle_join_results; current_life_cycle_join_result++)
	{
		const char* current_life_cycle_join_result_string = life_cycle_join_result_to_string(static_cast<e_life_cycle_join_result>(current_life_cycle_join_result));

		if (strcmp(current_life_cycle_join_result_string, life_cycle_join_result_string) == 0)
		{
			return static_cast<e_life_cycle_join_result>(current_life_cycle_join_result);
		}
	}
	return _life_cycle_join_result_none;
}

