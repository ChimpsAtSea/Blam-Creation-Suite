#pragma once

#include "platformspecific/platform-specific-private-pch.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>
#include <chrono>

#if BCS_USE_SHARED_LIBRARIES
#define BCS_SHARED_BUILDING_PLATFORM
#endif

//#ifdef __cplusplus
#include "platform-public-pch.h"
#include <templatelibrary/string_lookup.h>
//#endif
