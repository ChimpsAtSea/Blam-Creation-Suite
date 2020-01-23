#pragma once

typedef signed __int8		int8_t;
typedef signed __int16		int16_t;
typedef signed __int32		int32_t;
typedef signed __int64		int64_t;
typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t;
typedef unsigned __int64	uint64_t;
typedef unsigned __int8		bool8_t;
typedef unsigned __int16	bool16_t;
typedef unsigned __int32	bool32_t;
typedef unsigned __int64	bool64_t;

#pragma pack(push, 1)

#ifndef __clang__ 
#define __attribute__(...)
#endif
#define noreflection __attribute__((annotate("no_reflection")))

#include "TagTypes/TagGroupName.h"
#include "TagTypes/StringID.h"
#include "TagTypes/DataReference.h"
#include "TagTypes/TagReference.h"
#include "TagTypes/TagBlock.h"

// Tag Definitions
#include "TagDefinitions/TestType.h"
//#include "TagDefinitions/plugins/scenario.h"

#ifndef BUILD_REFLECTION_DATA
#include "ReflectionData.h"
#endif

#pragma pack(pop)