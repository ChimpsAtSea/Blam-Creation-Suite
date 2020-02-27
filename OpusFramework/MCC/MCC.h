#pragma once

#define OFFSET(Engine, Build, Offset) if(engine_type == Engine && build == Build) return (Offset);

#include "Versioning.h"

/* LEGACY */ #include "opus_legacy\IVariantAccessorBase.h"
/* LEGACY */ #include "opus_legacy\IGameVariant.h"
/* LEGACY */ #include "opus_legacy\IMapVariant.h"
/* LEGACY */ #include "opus_legacy\IGameEvents.h"
/* LEGACY */ #include "opus_legacy\IGameEngine.h"
#include "IGameEngineHost.h"
/* LEGACY */ #include "opus_legacy\ISaveFilmMetadata.h"
/* LEGACY */ #include "opus_legacy\IDataAccess.h"
/* LEGACY */ #include "opus_legacy\IFileAccess.h"

#include "MouseInput.h"
#include "GameLauncher.h"
#ifdef _WIN64
#include "HaloReachGameOptionSelection.h"
#endif
#include "game_runtime.h"

#include "opus_game_engine_host.h"


