#pragma once

#include <stdint.h>

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
typedef	uint8_t				enum8_t;
typedef	uint16_t			enum16_t;
typedef	uint32_t			enum32_t;
typedef	uint64_t			enum64_t;
typedef	uint8_t				bitfield8_t;
typedef	uint16_t			bitfield16_t;
typedef	uint32_t			bitfield32_t;
typedef	uint64_t			bitfield64_t;
typedef	uint8_t				bitflag8_t;
typedef	uint16_t			bitflag16_t;
typedef	uint32_t			bitflag32_t;
typedef	uint64_t			bitflag64_t;
typedef	uint8_t				undefined8_t;
typedef	uint16_t			undefined16_t;
typedef	uint32_t			undefined32_t;
typedef	uint64_t			undefined64_t;
#if __cplusplus <= 201703L
typedef char				char8_t;
#endif
//typedef wchar_t			char16_t;
