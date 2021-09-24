#pragma once

#define IMGUI_DISABLE_INCLUDE_IMCONFIG_H

#ifdef _DEBUG
#ifdef IMGUI_DLL_EXPORT
#define IMGUI_API __declspec( dllexport )
#else
#define IMGUI_API __declspec( dllimport )
#endif
#endif
