#include "gameframework-private-pch.h"

const char* engine_state_to_string(eEngineState engineState)
{
	switch (engineState)
	{
	case eEngineState::Pause:						return "Pause";
	case eEngineState::Unpause:						return "Unpause";
	case eEngineState::ImmediateExit:				return "ImmediateExit";
	case eEngineState::RestartCheckpoint:			return "RestartCheckpoint";
	case eEngineState::RestartLevel:				return "RestartLevel";
	case eEngineState::ReloadSettings:				return "ReloadSettings";
	case eEngineState::GameLoadStart:				return "GameLoadStart";
	case eEngineState::GameLoadEnd:					return "GameLoadEnd";
	case eEngineState::PushUIPage:					return "Unknown8";
	case eEngineState::PopUIPage:					return "Unknown9";
	case eEngineState::SaveGameVariant:				return "SaveGameVariant";
	case eEngineState::SaveMapVariant:				return "SaveMapVariant";
	case eEngineState::EndRound:					return "EndRound";
	case eEngineState::EndGame:						return "EndGame";
	case eEngineState::ReloadRenderer:				return "ReloadRenderer";
	case eEngineState::Unknown15:					return "Unknown15";
	case eEngineState::Unknown16:					return "Unknown16";
	default:										return "<Unknown eEngineState>";
	}
}