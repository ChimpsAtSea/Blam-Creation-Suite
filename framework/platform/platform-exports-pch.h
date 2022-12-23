#pragma once

#if BCS_USE_SHARED_LIBRARIES
#ifdef BCS_SHARED
#undef BCS_SHARED
#endif
#define BCS_SHARED BCS_SHARED_EXPORT
#endif
