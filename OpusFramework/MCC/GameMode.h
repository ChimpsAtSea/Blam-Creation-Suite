#pragma once

enum GameMode : int
{
	None,
	Campaign,
	Unknown2,
	Multiplayer,
	Unknown4,
	Survival,
	NumGameModes,
};

inline const char* GameModeToString(GameMode game_mode)
{
	switch (game_mode)
	{
	case GameMode::None:
		return "None";
	case GameMode::Campaign:
		return "Campaign";
#ifdef _DEBUG
	case GameMode::Unknown2:
		return "Unknown2";
#endif
	case GameMode::Multiplayer:
		return "Multiplayer";
#ifdef _DEBUG
	case GameMode::Unknown4:
		return "Unknown4";
#endif
	case GameMode::Survival:
		return "Survival";
	}
	return nullptr;
}

inline GameMode StringToGameMode(const char* string)
{
	for (int i = GameMode::None; i < GameMode::NumGameModes; i++)
	{
		GameMode game_mode = static_cast<GameMode>(i);
		const char* game_mode_str = GameModeToString(game_mode);

		if (game_mode_str != nullptr && (strcmp(string, game_mode_str) == 0))
		{
			return game_mode;
		}
	}
	return GameMode::None;
}
