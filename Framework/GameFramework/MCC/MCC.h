#pragma once

#define OFFSET(Engine, Build, ...) if(engine_type == Engine && build == Build) return { __VA_ARGS__ };

#include "map_id.h"


/* LEGACY */ #include "opus_legacy\IVariantAccessorBase.h"
/* LEGACY */ #include "opus_legacy\IGameVariant.h"
/* LEGACY */ #include "opus_legacy\IMapVariant.h"
/* LEGACY */ #include "opus_legacy\IGameEvents.h"
#include "game_context.h"
/* LEGACY */ #include "opus_legacy\IGameEngine.h"
#include "player_configuration.h"
#include "IGameEngineHost.h"
/* LEGACY */ #include "opus_legacy\ISaveFilmMetadata.h"
/* LEGACY */ #include "opus_legacy\IDataAccess.h"
/* LEGACY */ #include "opus_legacy\IFileAccess.h"

#include "mouse_input.h"
#include "game_launcher.h"
#ifdef _WIN64
#include "haloreach_game_option_selection_legacy.h"
#endif
#include "game_runtime.h"

#include "opus_game_engine_host.h"


