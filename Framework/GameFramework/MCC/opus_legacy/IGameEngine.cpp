#include "gameframework-private-pch.h"

const char* engine_state_to_string(e_engine_state engineState)
{
	switch (engineState)
	{
	case _engine_state_pause:						return "Pause";
	case _engine_state_unpause:						return "Unpause";
	case _engine_state_immediate_exit:				return "ImmediateExit";
	case _engine_state_restart_checkpoint:			return "RestartCheckpoint";
	case _engine_state_restart_level:				return "RestartLevel";
	case _engine_state_reload_settings:				return "ReloadSettings";
	case _engine_state_game_load_start:				return "GameLoadStart";
	case _engine_state_game_load_end:					return "GameLoadEnd";
	case _engine_state_push_ui_page:					return "Unknown8";
	case _engine_state_pop_ui_page:					return "Unknown9";
	case _engine_state_game_variant_save:				return "SaveGameVariant";
	case _engine_state_map_variant_save:				return "SaveMapVariant";
	case _engine_state_round_end:					return "EndRound";
	case _engine_state_game_end:						return "EndGame";
	case _engine_state_reload_renderer:				return "ReloadRenderer";
	case _engine_state_unknown15:					return "Unknown15";
	case _engine_state_unknown16:					return "Unknown16";
	default:										return "<Unknown e_engine_state>";
	}
}