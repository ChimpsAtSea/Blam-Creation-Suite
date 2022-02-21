#include "templatelibrary-private-pch.h"

s_tracked_memory_stats templatelibrary_tracked_memory = { "template library" };
s_tracked_memory_stats& _library_tracked_memory = templatelibrary_tracked_memory;
