#pragma once

#include <stdint.h>

#pragma pack(push, 1)

enum e_legacy_reflection_type_category : unsigned __int8
{
	_legacy_reflection_type_category_primitive,
	_legacy_reflection_type_category_structure,
	_legacy_reflection_type_category_tag_reference,
	_legacy_reflection_type_category_tag_block,
	_legacy_reflection_type_category_data_reference,
	_legacy_reflection_type_category_string_id,
	_legacy_reflection_type_category_enum,
	_legacy_reflection_type_category_bitfield,
	_legacy_reflection_type_category_shader_data,
};

typedef unsigned __int16 s_reflection_structure_type_legacyIndex;
enum e_legacy_primitive_type : s_reflection_structure_type_legacyIndex
{
	_legacy_primitive_type_non_primitive,
	_legacy_primitive_type_int8,
	_legacy_primitive_type_int16,
	_legacy_primitive_type_int32,
	_legacy_primitive_type_int64,
	_legacy_primitive_type_uint8,
	_legacy_primitive_type_uint16,
	_legacy_primitive_type_uint32,
	_legacy_primitive_type_uint64,
	_legacy_primitive_type_float,
	_legacy_primitive_type_double,
	_legacy_primitive_type_boolean8,
	_legacy_primitive_type_boolean16,
	_legacy_primitive_type_boolean32,
	_legacy_primitive_type_boolean64,
	_legacy_primitive_type_enum8,
	_legacy_primitive_type_enum16,
	_legacy_primitive_type_enum32,
	_legacy_primitive_type_enum64,
	_legacy_primitive_type_bitfield8,
	_legacy_primitive_type_bitfield16,
	_legacy_primitive_type_bitfield32,
	_legacy_primitive_type_bitfield64,
	_legacy_primitive_type_bitflag8,
	_legacy_primitive_type_bitflag16,
	_legacy_primitive_type_bitflag32,
	_legacy_primitive_type_bitflag64,
	_legacy_primitive_type_undefined8,
	_legacy_primitive_type_undefined16,
	_legacy_primitive_type_undefined32,
	_legacy_primitive_type_undefined64,
	_legacy_primitive_type_char8,
	_legacy_primitive_type_char16,
	_legacy_primitive_type_static_string8,
	_legacy_primitive_type_static_string16
};

inline const char* primitive_type_to_string(e_legacy_primitive_type primitiveType)
{
	switch (primitiveType)
	{
	case _legacy_primitive_type_non_primitive:		return "_legacy_primitive_type_non_primitive";
	case _legacy_primitive_type_int8:				return "_legacy_primitive_type_int8";
	case _legacy_primitive_type_int16:				return "_legacy_primitive_type_int16";
	case _legacy_primitive_type_int32:				return "_legacy_primitive_type_int32";
	case _legacy_primitive_type_int64:				return "_legacy_primitive_type_int64";
	case _legacy_primitive_type_uint8:				return "_legacy_primitive_type_uint8";
	case _legacy_primitive_type_uint16:			return "_legacy_primitive_type_uint16";
	case _legacy_primitive_type_uint32:			return "_legacy_primitive_type_uint32";
	case _legacy_primitive_type_uint64:			return "_legacy_primitive_type_uint64";
	case _legacy_primitive_type_float:				return "_legacy_primitive_type_float";
	case _legacy_primitive_type_double:			return "_legacy_primitive_type_double";
	case _legacy_primitive_type_boolean8:			return "_legacy_primitive_type_boolean8";
	case _legacy_primitive_type_boolean16:			return "_legacy_primitive_type_boolean16";
	case _legacy_primitive_type_boolean32:			return "_legacy_primitive_type_boolean32";
	case _legacy_primitive_type_boolean64:			return "_legacy_primitive_type_boolean64";
	case _legacy_primitive_type_enum8:				return "_legacy_primitive_type_enum8";
	case _legacy_primitive_type_enum16:			return "_legacy_primitive_type_enum16";
	case _legacy_primitive_type_enum32:			return "_legacy_primitive_type_enum32";
	case _legacy_primitive_type_enum64:			return "_legacy_primitive_type_enum64";
	case _legacy_primitive_type_bitfield8:			return "_legacy_primitive_type_bitfield8";
	case _legacy_primitive_type_bitfield16:		return "_legacy_primitive_type_bitfield16";
	case _legacy_primitive_type_bitfield32:		return "_legacy_primitive_type_bitfield32";
	case _legacy_primitive_type_bitfield64:		return "_legacy_primitive_type_bitfield64";
	case _legacy_primitive_type_bitflag8:			return "_legacy_primitive_type_bitflag8";
	case _legacy_primitive_type_bitflag16:			return "_legacy_primitive_type_bitflag16";
	case _legacy_primitive_type_bitflag32:			return "_legacy_primitive_type_bitflag32";
	case _legacy_primitive_type_bitflag64:			return "_legacy_primitive_type_bitflag64";
	case _legacy_primitive_type_undefined8:		return "_legacy_primitive_type_undefined8";
	case _legacy_primitive_type_undefined16:		return "_legacy_primitive_type_undefined16";
	case _legacy_primitive_type_undefined32:		return "_legacy_primitive_type_undefined32";
	case _legacy_primitive_type_undefined64:		return "_legacy_primitive_type_undefined64";
	case _legacy_primitive_type_char8:				return "_legacy_primitive_type_char8";
	case _legacy_primitive_type_char16:			return "_legacy_primitive_type_char16";
	case _legacy_primitive_type_static_string8:	return "_legacy_primitive_type_static_string8";
	case _legacy_primitive_type_static_string16:	return "_legacy_primitive_type_static_string16";
	}
#ifdef FATAL_ERROR
	FATAL_ERROR(L"invalid primitive_type");
#else
	throw;
#endif
}

inline const char* legacy_reflection_type_category_to_string(e_legacy_reflection_type_category reflectionType)
{
	switch (reflectionType)
	{
	case _legacy_reflection_type_category_primitive:				return "_legacy_reflection_type_category_primitive";
	case _legacy_reflection_type_category_structure:				return "_legacy_reflection_type_category_structure";
	case _legacy_reflection_type_category_tag_reference:			return "_legacy_reflection_type_category_tag_reference";
	case _legacy_reflection_type_category_tag_block:				return "_legacy_reflection_type_category_tag_block";
	case _legacy_reflection_type_category_data_reference:			return "_legacy_reflection_type_category_data_reference";
	case _legacy_reflection_type_category_shader_data:				return "_legacy_reflection_type_category_shader_data";
	case _legacy_reflection_type_category_string_id:				return "_legacy_reflection_type_category_string_id";
	case _legacy_reflection_type_category_enum:					return "_legacy_reflection_type_category_enum";
	case _legacy_reflection_type_category_bitfield:				return "_legacy_reflection_type_category_bitfield";
	}
#ifdef FATAL_ERROR
	FATAL_ERROR(L"invalid legacy_reflection_type_category");
#else
	throw;
#endif
}

struct s_reflection_structure_type_info_legacy
{
	e_legacy_reflection_type_category legacy_reflection_type_category;
	union
	{
		e_legacy_primitive_type m_primitiveTypeIndex;
		s_reflection_structure_type_legacyIndex m_reflectionTypeIndex;
	};
	const char* type_name;
	const char* type_nice_name;
	const char* type_qualified_name;
};

struct s_reflection_structure_type_legacy;
struct s_reflection_enum_type_legacy;

struct s_reflection_structure_info_legacy : s_reflection_structure_type_info_legacy
{
	const s_reflection_structure_type_legacy* reflection_type;
};

struct s_reflection_tag_block_info_legacy : s_reflection_structure_type_info_legacy
{
	const s_reflection_structure_type_legacy* reflection_type;
};

struct s_reflection_enum_info_legacy : s_reflection_structure_type_info_legacy
{
	const s_reflection_enum_type_legacy* reflection_enum_type;
};

struct c_reflection_field_legacy
{
	c_reflection_field_legacy()
	{
		name = {};
		nice_name = {};
		type_info = {};
		structure_info = {};
		tag_block_info = {};
		enum_info = {};
		offset = {};
		size = {};
		array_size = {};
		is_hidden_by_default = {};
	}

	c_reflection_field_legacy(
		const char* name,
		const char* nice_name,
		s_reflection_structure_type_info_legacy type_info,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 array_size,
		bool is_hidden_by_default
	)
		: name(name)
		, nice_name(nice_name)
		, offset(offset)
		, size(size)
		, array_size(array_size)
		, is_hidden_by_default(is_hidden_by_default)
	{
		structure_info = {};
		tag_block_info = {};
		enum_info = {};
		this->type_info = type_info;
	}

	c_reflection_field_legacy(
		const char* name,
		const char* nice_name,
		s_reflection_enum_info_legacy enum_info,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 array_size,
		bool is_hidden_by_default
	)
		: name(name)
		, nice_name(nice_name)
		, offset(offset)
		, size(size)
		, array_size(array_size)
		, is_hidden_by_default(is_hidden_by_default)
	{
		type_info = {};
		structure_info = {};
		tag_block_info = {};
		this->enum_info = enum_info;
	}

	c_reflection_field_legacy(
		const char* name,
		const char* nice_name,
		s_reflection_structure_info_legacy structure_info,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 array_size,
		bool is_hidden_by_default
	)
		: name(name)
		, nice_name(nice_name)
		, offset(offset)
		, size(size)
		, array_size(array_size)
		, is_hidden_by_default(is_hidden_by_default)
	{
		type_info = {};
		tag_block_info = {};
		enum_info = {};
		this->structure_info = structure_info;
	}

	c_reflection_field_legacy(
		const char* name,
		const char* nice_name,
		s_reflection_tag_block_info_legacy tag_block_info,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 array_size,
		bool is_hidden_by_default
	)
		: name(name)
		, nice_name(nice_name)
		, offset(offset)
		, size(size)
		, array_size(array_size)
		, is_hidden_by_default(is_hidden_by_default)
	{
		type_info = {};
		structure_info = {};
		enum_info = {};
		this->tag_block_info = tag_block_info;
	}

	const char* name;
	const char* nice_name;
	union {
		s_reflection_structure_type_info_legacy type_info;
		s_reflection_structure_info_legacy structure_info;
		s_reflection_tag_block_info_legacy tag_block_info;
		s_reflection_enum_info_legacy enum_info;
	};
	unsigned __int32 offset;
	unsigned __int16 size;
	unsigned __int32 array_size;
	bool is_hidden_by_default;
};

class c_tag_interface;
class c_cache_file;

using render_type_gui_legacy_func_legacy = void(void*);
using virtual_tag_constructor_func_legacy = c_tag_interface*(c_cache_file&, uint16_t);

struct s_reflection_enum_value_legacy
{
	const char* name;
	uint64_t value;
};

#pragma warning( push )
#pragma warning( disable : 4200 ) // allow using non standard language features without warning
struct s_reflection_enum_type_legacy
{
	const char* name;
	const char* nice_name;
	unsigned __int32 size_of_data;
	unsigned __int32 values_count;
	s_reflection_enum_value_legacy values[]; // #NOTE: non standard language feature
};
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4200 ) // allow using non standard language features without warning
struct s_reflection_structure_type_legacy
{
	const char* name;
	const char* nice_name;
	unsigned __int32 size_of_data;
	unsigned __int32 members_count;
	render_type_gui_legacy_func_legacy* render_type_gui_legacy;
	c_tag_interface* (*virtual_tag_constructor)(c_cache_file&, uint16_t);
	c_reflection_field_legacy fields[]; // #NOTE: non standard language feature
};
#pragma warning( pop )

#pragma pack(pop)

// intellisense beautiful code hacks
#ifdef __INTELLISENSE__

#endif
