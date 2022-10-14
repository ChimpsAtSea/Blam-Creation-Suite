#pragma once

#ifdef BCS_WIN32
#define BCS_DEBUG_API_EXPORT __declspec(dllexport)
#define BCS_DEBUG_API_IMPORT __declspec(dllimport)
#else
#define BCS_DEBUG_API_EXPORT __attribute__ ((visibility ("default")))
#define BCS_DEBUG_API_IMPORT
#endif

#if BCS_USE_SHARED_LIBRARIES
#ifndef BCS_DEBUG_API
#ifdef BCS_DEBUG_API_BUILDING_PLATFORM
#define BCS_DEBUG_API BCS_DEBUG_API_EXPORT
#else
#define BCS_DEBUG_API BCS_DEBUG_API_IMPORT
#endif
#endif
#else
#ifndef BCS_DEBUG_API
#define BCS_DEBUG_API
#endif
#endif
