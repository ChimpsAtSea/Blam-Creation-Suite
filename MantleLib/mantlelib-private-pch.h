#pragma once

#include <Shared/shared-public-pch.h>
#include "mantlelib-public-pch.h"
#include "VirtualMemoryContainer.h"

inline ImGuiDataType PrimitiveTypeToImGuiDataType(PrimitiveType primitiveType)
{
	switch (primitiveType)
	{
	case PrimitiveType::Int8:			return ImGuiDataType_S8;
	case PrimitiveType::Int16:			return ImGuiDataType_S16;
	case PrimitiveType::Int32:			return ImGuiDataType_S32;
	case PrimitiveType::Int64:			return ImGuiDataType_S64;
	case PrimitiveType::UInt8:			return ImGuiDataType_U8;
	case PrimitiveType::UInt16:			return ImGuiDataType_U16;
	case PrimitiveType::UInt32:			return ImGuiDataType_U32;
	case PrimitiveType::UInt64:			return ImGuiDataType_U64;
	case PrimitiveType::Float:			return ImGuiDataType_Float;
	case PrimitiveType::Double:			return ImGuiDataType_Double;
	case PrimitiveType::Boolean8:		return ImGuiDataType_S8;
	case PrimitiveType::Boolean16:		return ImGuiDataType_S16;
	case PrimitiveType::Boolean32:		return ImGuiDataType_S32;
	case PrimitiveType::Boolean64:		return ImGuiDataType_S64;
	case PrimitiveType::Enum8:			return ImGuiDataType_S8;
	case PrimitiveType::Enum16:			return ImGuiDataType_S16;
	case PrimitiveType::Enum32:			return ImGuiDataType_S32;
	case PrimitiveType::Enum64:			return ImGuiDataType_S64;
	case PrimitiveType::Undefined8:		return ImGuiDataType_S8;
	case PrimitiveType::Undefined16:	return ImGuiDataType_S16;
	case PrimitiveType::Undefined32:	return ImGuiDataType_Float;
	case PrimitiveType::Undefined64:	return ImGuiDataType_Double;
	}
	FATAL_ERROR(L"Unsupported primitive type");
}
