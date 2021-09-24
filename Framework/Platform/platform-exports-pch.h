#pragma once

#if _DEBUG
#ifdef BCS_DEBUG_API
#undef BCS_DEBUG_API
#endif
#define BCS_DEBUG_API __declspec(dllexport)
#endif
