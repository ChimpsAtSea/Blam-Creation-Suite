#pragma once

#include <stdint.h>

#pragma pack(push, 1)

enum class e_reflection_type_category : unsigned __int8
{
	Primitive,
	Structure,
	TagReference,
	TagBlock,
	DataReference,
	ShaderData,
	StringID,
	Enum,
	BitField,
};

typedef unsigned __int16 s_reflection_structure_typeIndex;
enum class e_primitive_type : s_reflection_structure_typeIndex
{
	NonPrimitive,
	Int8,
	Int16,
	Int32,
	Int64,
	UInt8,
	UInt16,
	UInt32,
	UInt64,
	Float,
	Double,
	Boolean8,
	Boolean16,
	Boolean32,
	Boolean64,
	Enum8,
	Enum16,
	Enum32,
	Enum64,
	BitField8,
	BitField16,
	BitField32,
	BitField64,
	BitFlag8,
	BitFlag16,
	BitFlag32,
	BitFlag64,
	Undefined8,
	Undefined16,
	Undefined32,
	Undefined64,
	RawCharacter,
	RawWideCharacter,
	StaticString,
	StaticWideString
};

inline const char* e_primitive_typeToString(e_primitive_type primitiveType)
{
	switch (primitiveType)
	{
	case e_primitive_type::NonPrimitive:		return "NonPrimitive";
	case e_primitive_type::Int8:				return "Int8";
	case e_primitive_type::Int16:				return "Int16";
	case e_primitive_type::Int32:				return "Int32";
	case e_primitive_type::Int64:				return "Int64";
	case e_primitive_type::UInt8:				return "UInt8";
	case e_primitive_type::UInt16:				return "UInt16";
	case e_primitive_type::UInt32:				return "UInt32";
	case e_primitive_type::UInt64:				return "UInt64";
	case e_primitive_type::Float:				return "Float";
	case e_primitive_type::Double:				return "Double";
	case e_primitive_type::Boolean8:			return "Boolean8";
	case e_primitive_type::Boolean16:			return "Boolean16";
	case e_primitive_type::Boolean32:			return "Boolean32";
	case e_primitive_type::Boolean64:			return "Boolean64";
	case e_primitive_type::Enum8:				return "Enum8";
	case e_primitive_type::Enum16:				return "Enum16";
	case e_primitive_type::Enum32:				return "Enum32";
	case e_primitive_type::Enum64:				return "Enum64";
	case e_primitive_type::BitField8:			return "BitField8";
	case e_primitive_type::BitField16:			return "BitField16";
	case e_primitive_type::BitField32:			return "BitField32";
	case e_primitive_type::BitField64:			return "BitField64";
	case e_primitive_type::BitFlag8:			return "BitFlag8";
	case e_primitive_type::BitFlag16:			return "BitFlag16";
	case e_primitive_type::BitFlag32:			return "BitFlag32";
	case e_primitive_type::BitFlag64:			return "BitFlag64";
	case e_primitive_type::Undefined8:			return "Undefined8";
	case e_primitive_type::Undefined16:			return "Undefined16";
	case e_primitive_type::Undefined32:			return "Undefined32";
	case e_primitive_type::Undefined64:			return "Undefined64";
	case e_primitive_type::RawCharacter:		return "RawCharacter";
	case e_primitive_type::RawWideCharacter:	return "RawWideCharacter";
	case e_primitive_type::StaticString:		return "c_static_string";
	case e_primitive_type::StaticWideString:	return "c_static_wide_string";
	}
#ifdef FATAL_ERROR
	FATAL_ERROR(L"Invalid primitive type");
#else
	throw;
#endif
}

inline const char* e_reflection_type_categoryToString(e_reflection_type_category reflectionType)
{
	switch (reflectionType)
	{
	case e_reflection_type_category::Primitive:				return "Primitive";
	case e_reflection_type_category::Structure:				return "Structure";
	case e_reflection_type_category::TagReference:			return "TagReference";
	case e_reflection_type_category::TagBlock:				return "TagBlock";
	case e_reflection_type_category::DataReference:			return "DataReference";
	case e_reflection_type_category::ShaderData:			return "ShaderData";
	case e_reflection_type_category::StringID:				return "StringID";
	case e_reflection_type_category::Enum:					return "Enum";
	case e_reflection_type_category::BitField:				return "BitField";
	}
#ifdef FATAL_ERROR
	FATAL_ERROR(L"Invalid reflection type");
#else
	throw;
#endif
}

struct s_reflection_structure_type_info
{
	e_reflection_type_category reflection_type_category;
	union
	{
		e_primitive_type m_primitiveTypeIndex;
		s_reflection_structure_typeIndex m_reflectionTypeIndex;
	};
	const char* type_name;
	const char* type_nice_name;
	const char* type_qualified_name;
};

struct s_reflection_structure_type;
struct s_reflection_enum_type;

struct s_reflection_structure_info : s_reflection_structure_type_info
{
	const s_reflection_structure_type* reflection_type;
};

struct s_reflection_tag_block_info : s_reflection_structure_type_info
{
	const s_reflection_structure_type* reflection_type;
};

struct s_reflection_enum_info : s_reflection_structure_type_info
{
	const s_reflection_enum_type* reflection_enum_type;
};

struct c_reflection_field
{
	c_reflection_field()
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

	c_reflection_field(
		const char* name,
		const char* nice_name,
		s_reflection_structure_type_info type_info,
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

	c_reflection_field(
		const char* name,
		const char* nice_name,
		s_reflection_enum_info enum_info,
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

	c_reflection_field(
		const char* name,
		const char* nice_name,
		s_reflection_structure_info structure_info,
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

	c_reflection_field(
		const char* name,
		const char* nice_name,
		s_reflection_tag_block_info tag_block_info,
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
		s_reflection_structure_type_info type_info;
		s_reflection_structure_info structure_info;
		s_reflection_tag_block_info tag_block_info;
		s_reflection_enum_info enum_info;
	};
	unsigned __int32 offset;
	unsigned __int16 size;
	unsigned __int32 array_size;
	bool is_hidden_by_default;
};

using render_type_gui_func = void(void*);

class c_tag_interface;
class c_cache_file;

using virtual_tag_constructor_func = c_tag_interface*(c_cache_file&, uint16_t);

struct s_reflection_enum_value
{
	const char* name;
	uint64_t value;
};

#pragma warning( push )
#pragma warning( disable : 4200 ) // allow using non standard language features without warning
struct s_reflection_enum_type
{
	const char* name;
	const char* nice_name;
	unsigned __int32 size_of_data;
	unsigned __int32 values_count;
	s_reflection_enum_value values[]; // #NOTE: non standard language feature
};
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4200 ) // allow using non standard language features without warning
struct s_reflection_structure_type
{
	const char* name;
	const char* nice_name;
	unsigned __int32 size_of_data;
	unsigned __int32 members_count;
	render_type_gui_func* render_type_gui;
	c_tag_interface* (*virtual_tag_constructor)(c_cache_file&, uint16_t);
	c_reflection_field fields[]; // #NOTE: non standard language feature
};
#pragma warning( pop )

#pragma pack(pop)

// intellisense beautiful code hacks
#ifdef __INTELLISENSE__

#endif
