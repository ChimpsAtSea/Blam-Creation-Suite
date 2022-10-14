#pragma once

#include "PlatformSpecific/platform-specific-private-pch.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

#if BCS_USE_SHARED_LIBRARIES
#define BCS_SHARED_BUILDING_PLATFORM
#endif

//#ifdef __cplusplus
#include "platform-public-pch.h"
#include <TemplateLibrary/string_lookup.h>
//#endif
