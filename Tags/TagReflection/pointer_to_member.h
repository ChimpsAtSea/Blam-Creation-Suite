#pragma once

#if BCS_BUILD_HIGH_LEVEL_VERSION2
using h_pointer_to_member = h_type h_extended_type::*;
#else
using h_pointer_to_member = h_type h_type::*;
#endif
