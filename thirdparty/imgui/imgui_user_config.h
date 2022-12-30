#pragma once

#include "Platform/PlatformSpecific/platform-specific-define-platform.h"
#include "Platform/Base/bcs_api.h"

#define IMGUI_DISABLE_INCLUDE_IMCONFIG_H

#ifdef BCS_USE_SHARED_LIBRARIES
#ifdef IMGUI_DLL_EXPORT
#define IMGUI_API BCS_SHARED_EXPORT
#else
#define IMGUI_API BCS_SHARED_IMPORT
#endif
#endif