#pragma once

#include <Shared/shared-public-pch.h>
#include "mantlelib-public-pch.h"
#include "VirtualMemoryContainer.h"

inline ImGuiDataType e_primitive_typeToImGuiDataType(e_primitive_type primitiveType)
{
	switch (primitiveType)
	{
	case e_primitive_type::Int8:			return ImGuiDataType_S8;
	case e_primitive_type::Int16:			return ImGuiDataType_S16;
	case e_primitive_type::Int32:			return ImGuiDataType_S32;
	case e_primitive_type::Int64:			return ImGuiDataType_S64;
	case e_primitive_type::UInt8:			return ImGuiDataType_U8;
	case e_primitive_type::UInt16:			return ImGuiDataType_U16;
	case e_primitive_type::UInt32:			return ImGuiDataType_U32;
	case e_primitive_type::UInt64:			return ImGuiDataType_U64;
	case e_primitive_type::Float:			return ImGuiDataType_Float;
	case e_primitive_type::Double:			return ImGuiDataType_Double;
	case e_primitive_type::Boolean8:		return ImGuiDataType_S8;
	case e_primitive_type::Boolean16:		return ImGuiDataType_S16;
	case e_primitive_type::Boolean32:		return ImGuiDataType_S32;
	case e_primitive_type::Boolean64:		return ImGuiDataType_S64;
	case e_primitive_type::Enum8:			return ImGuiDataType_S8;
	case e_primitive_type::Enum16:			return ImGuiDataType_S16;
	case e_primitive_type::Enum32:			return ImGuiDataType_S32;
	case e_primitive_type::Enum64:			return ImGuiDataType_S64;
	case e_primitive_type::Undefined8:		return ImGuiDataType_S8;
	case e_primitive_type::Undefined16:	return ImGuiDataType_S16;
	case e_primitive_type::Undefined32:	return ImGuiDataType_Float;
	case e_primitive_type::Undefined64:	return ImGuiDataType_Double;
	}
	FATAL_ERROR(L"Unsupported primitive type");
}
