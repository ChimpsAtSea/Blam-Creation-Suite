#pragma once

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
using namespace tbb;

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })
