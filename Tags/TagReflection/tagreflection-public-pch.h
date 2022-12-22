#pragma once

#if defined(__INTELLISENSE__) && !defined(BCS_IS_HIGH_LEVEL_BUILD_PROJECT)
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) intellisense_accessspecifier 
#else
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) normal_accessspecifier 
#endif

#include "high_level_library_registry.h"

#include "tag_instance.h"
#include "tag_group.h"

#define high_level_cast dynamic_cast

#include "watchdog.h"
#include "type.h"
#include "pointer_to_member.h"
#include "member_info.h"
#include "serialization_info.h"
#include "extended_type.h"
#include "enumerable.h"
#include "block.h"
#include "field.h"
#include "string_id_field.h"
#include "resource_field.h"
#include "typed_field.h"
#include "prototype.h"
#include "array.h"
#include "resource.h"
#include "data.h"
#include "tag_reference.h"
