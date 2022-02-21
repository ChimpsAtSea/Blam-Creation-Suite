#include "mandrill-private-pch.h"

s_tracked_memory_stats mandrill_tracked_memory = { "mandrill" };
s_tracked_memory_stats& _library_tracked_memory = mandrill_tracked_memory;
