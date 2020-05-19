#pragma once

#include <Platform/platform-public-pch.h>
#include <Shared/shared-public-pch.h>
#include <blamlib.h>
#include <TagDefinitions/tagdefinitions-public-pch.h>

#include <MantleGen/reflection_types.h>
#include <MantleGen/legacy_reflection_types.h>

#include "mantlelib-public-pch.h"
#include "VirtualMemoryContainer.h"


inline ImGuiDataType primitive_type_to_imgui_data_type(e_legacy_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case _legacy_primitive_type_int8:				return ImGuiDataType_S8;
	case _legacy_primitive_type_int16:				return ImGuiDataType_S16;
	case _legacy_primitive_type_int32:				return ImGuiDataType_S32;
	case _legacy_primitive_type_int64:				return ImGuiDataType_S64;
	case _legacy_primitive_type_uint8:				return ImGuiDataType_U8;
	case _legacy_primitive_type_uint16:				return ImGuiDataType_U16;
	case _legacy_primitive_type_uint32:				return ImGuiDataType_U32;
	case _legacy_primitive_type_uint64:				return ImGuiDataType_U64;
	case _legacy_primitive_type_float:				return ImGuiDataType_Float;
	case _legacy_primitive_type_double:				return ImGuiDataType_Double;
	case _legacy_primitive_type_boolean8:			return ImGuiDataType_S8;
	case _legacy_primitive_type_boolean16:			return ImGuiDataType_S16;
	case _legacy_primitive_type_boolean32:			return ImGuiDataType_S32;
	case _legacy_primitive_type_boolean64:			return ImGuiDataType_S64;
	case _legacy_primitive_type_enum8:				return ImGuiDataType_S8;
	case _legacy_primitive_type_enum16:				return ImGuiDataType_S16;
	case _legacy_primitive_type_enum32:				return ImGuiDataType_S32;
	case _legacy_primitive_type_enum64:				return ImGuiDataType_S64;
	case _legacy_primitive_type_undefined8:			return ImGuiDataType_S8;
	case _legacy_primitive_type_undefined16:		return ImGuiDataType_S16;
	case _legacy_primitive_type_undefined32:		return ImGuiDataType_Float;
	case _legacy_primitive_type_undefined64:		return ImGuiDataType_Double;
	}
	FATAL_ERROR(L"unsupported primitive_type");
}
