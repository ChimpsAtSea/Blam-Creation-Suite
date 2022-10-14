#pragma once

#ifdef BCS_WIN32
#define BCS_SHARED_EXPORT __declspec(dllexport)
#define BCS_SHARED_IMPORT __declspec(dllimport)
#else
#define BCS_SHARED_EXPORT __attribute__ ((visibility ("default")))
#define BCS_SHARED_IMPORT
#endif

#if BCS_USE_SHARED_LIBRARIES
#ifndef BCS_SHARED
#ifdef BCS_SHARED_BUILDING_PLATFORM
#define BCS_SHARED BCS_SHARED_EXPORT
#else
#define BCS_SHARED BCS_SHARED_IMPORT
#endif
#endif
#else
#ifndef BCS_SHARED
#define BCS_SHARED
#endif
#endif
