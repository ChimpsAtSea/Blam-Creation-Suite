#pragma once

#if defined(__INTELLISENSE__) && !defined(BCS_IS_HIGH_LEVEL_BUILD_PROJECT)
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) intellisense_accessspecifier 
#else
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) normal_accessspecifier 
#endif

#include "high_level_library_registry.h"

#if BCS_BUILD_HIGH_LEVEL_VERSION2

#pragma pack(push, 1)

#include "Version2\type.h"
#include "Version2\extended_type.h"
#include "Version2\member_info.h"
#include "Version2\block.h"
#include "Version2\field.h"
#include "Version2\typed_field.h"
#include "Version2\string_field.h"
#include "Version2\prototype_field.h"
#include "Version2\prototype.h"
#include "Version2\tag_instance.h"
#include "Version2\tag_group.h"
#include "Version2\high_level_cast.h"

#pragma pack(pop)

#else

#include "Version1\watchdog.h"
#include "Version1\type.h"
#include "Version1\object.h"
#include "Version1\tag.h"
#include "Version1\group.h"
#include "Version1\tag_reference.h"
#include "Version1\string_id.h"
#include "Version1\resource.h"
#include "Version1\enumerable.h"
#include "Version1\block.h"
#include "Version1\typed_block.h"
#include "Version1\typed_array.h"
#include "Version1\data.h"
#include "Version1\field.h"
#include "Version1\resource_field.h"

#endif
