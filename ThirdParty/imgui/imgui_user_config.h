#pragma once

#include "Platform/PlatformSpecific/platform-specific-define-platform.h"
#include "Platform/Base/bcs_api.h"

#define IMGUI_DISABLE_INCLUDE_IMCONFIG_H

#ifdef BCS_USE_SHARED_LIBRARIES
#ifdef IMGUI_DLL_EXPORT
#define IMGUI_API BCS_DEBUG_API_EXPORT
#else
#define IMGUI_API BCS_DEBUG_API_IMPORT
#endif
#endif
