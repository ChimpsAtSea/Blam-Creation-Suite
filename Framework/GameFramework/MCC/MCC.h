#pragma once

#define OFFSET(Engine, Build, ...) if(engine_platform_build.engine_type == Engine && engine_platform_build.build == Build) return { __VA_ARGS__ };

#include "map_id.h"


/* LEGACY */ #include "aotus_legacy\IVariantAccessorBase.h"
/* LEGACY */ #include "aotus_legacy\IGameVariant.h"
/* LEGACY */ #include "aotus_legacy\IMapVariant.h"
/* LEGACY */ #include "aotus_legacy\IGameEvents.h"
#include "game_options.h"
/* LEGACY */ #include "aotus_legacy\IGameEngine.h"
#include "player_configuration.h"
#include "IGameEngineHost.h"
/* LEGACY */ #include "aotus_legacy\ISaveFilmMetadata.h"
/* LEGACY */ #include "aotus_legacy\IDataAccess.h"
/* LEGACY */ #include "aotus_legacy\IFileAccess.h"

#include "mouse_input.h"
#include "game_launcher.h"
#ifdef _WIN64
#include "haloreach_game_option_selection_legacy.h"
#endif
#include "game_runtime.h"

#include "aotus_game_engine_host.h"


