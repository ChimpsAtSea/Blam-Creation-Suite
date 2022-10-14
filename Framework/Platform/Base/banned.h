#pragma once

#define malloc malloc_banned
#define free free_banned
#define _aligned_malloc _aligned_malloc_banned
#define _aligned_free _aligned_free_banned

#ifdef _malloca
#undef _malloca
#endif
#define _malloca _malloca_banned

#ifdef _freea
#undef _freea
#endif
#define _freea _freea_banned

