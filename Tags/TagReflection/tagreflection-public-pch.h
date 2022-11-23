#pragma once

#if defined(__INTELLISENSE__) && !defined(BCS_IS_HIGH_LEVEL_BUILD_PROJECT)
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) intellisense_accessspecifier 
#else
#define intelliaccess(normal_accessspecifier, intellisense_accessspecifier) normal_accessspecifier 
#endif

#include "high_level_library_registry.h"

#include "tag_instance.h"
#include "tag_group.h"



#if BCS_BUILD_HIGH_LEVEL_VERSION2

#define prototype_child_to_parent(size, name) protected: s_prototype_child_to_parent<size> name; public:

#pragma pack(push, 1)

#include "Version2\type.h"
#include "Version2\extended_type.h"

#include "pointer_to_member.h"
#include "member_info.h"
#include "serialization_info.h"

#include "block.h"
#include "Version2\field.h"
#include "Version2\typed_field.h"
#include "string_id_field.h"
#include "Version2\prototype_field.h"
#include "prototype.h"
#include "array.h"
#include "Version2\high_level_cast.h"

#pragma pack(pop)

#else

#define prototype_child_to_parent(...)
#define high_level_cast dynamic_cast

#include "Version1\watchdog.h"
#include "Version1\type.h"

#include "pointer_to_member.h"
#include "member_info.h"
#include "serialization_info.h"

#include "Version1\extended_type.h"
#include "Version1\enumerable.h"
#include "block.h"
#include "Version1\field.h"
#include "string_id_field.h"
#include "resource_field.h"
#include "Version1\typed_field.h"
#include "prototype.h"
#include "array.h"
#include "resource.h"

#include "Version1\tag_reference.h"


#include "Version1\data.h"

#endif
