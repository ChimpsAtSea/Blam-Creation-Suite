#pragma once

struct s_reflection_type;
struct s_reflection_member;
struct s_reflection_enum_name;
struct s_reflection_structure;
struct s_reflection_enum;

enum e_reflection_type_class : uint8_t
{
	_reflection_type_class_undefined,
	_reflection_type_class_padding,
	_reflection_type_class_structure,
	_reflection_type_class_union,
	_reflection_type_class_tag_block,
	_reflection_type_class_tag_reference,
	_reflection_type_class_data_reference,
	_reflection_type_class_uint,
	_reflection_type_class_int,
	_reflection_type_class_enum,
	_reflection_type_class_bitflag,
	_reflection_type_class_bitfield,
	_reflection_type_class_float,
	_reflection_type_class_boolean,
	_reflection_type_class_text,
	reflection_type_class_count
};
static_assert(reflection_type_class_count <= 16, "Reflection type count limited to 4 bits of address space. See s_reflection_member for more information.");

inline constexpr const char* reflection_type_class_to_string(e_reflection_type_class reflection_type_class)
{
	switch(reflection_type_class)
	{
		case _reflection_type_class_undefined:			return "_reflection_type_class_undefined";
		case _reflection_type_class_padding:			return "_reflection_type_class_padding";
		case _reflection_type_class_structure:			return "_reflection_type_class_structure";
		case _reflection_type_class_union:				return "_reflection_type_class_union";
		case _reflection_type_class_tag_block:			return "_reflection_type_class_tag_block";
		case _reflection_type_class_tag_reference:		return "_reflection_type_class_tag_reference";
		case _reflection_type_class_data_reference:		return "_reflection_type_class_data_reference";
		case _reflection_type_class_uint:				return "_reflection_type_class_uint";
		case _reflection_type_class_int:				return "_reflection_type_class_int";
		case _reflection_type_class_enum:				return "_reflection_type_class_enum";
		case _reflection_type_class_bitflag:			return "_reflection_type_class_bitflag";
		case _reflection_type_class_bitfield:			return "_reflection_type_class_bitfield";
		case _reflection_type_class_float:				return "_reflection_type_class_float";
		case _reflection_type_class_boolean:			return "_reflection_type_class_boolean";
		case _reflection_type_class_text:				return "_reflection_type_class_text";
	}
	return "<unknown e_reflection_type_class>";
}

struct s_reflection_type
{
	s_reflection_type(e_reflection_type_class type_class, uint32_t unsafe_raw_size, const char* raw_name, const char* nice_name, const char* description) :
		type_class(type_class),
		unsafe_raw_size(unsafe_raw_size),
		raw_name(raw_name),
		nice_name(nice_name),
		description(description)
	{

	}

	const e_reflection_type_class type_class;
	const uint32_t unsafe_raw_size; // #WARN: Check the specific size of a field to get actual size of used data!
	const char* raw_name;
	const char* nice_name;
	const char* description;
};

struct s_reflection_member
{
	s_reflection_member(const s_reflection_structure& parent, uint32_t underlying_type_size, uint32_t field_offset, const s_reflection_type& type, const char* raw_name, const char* nice_name, const char* description, uint8_t bitfield_offset = 0, uint8_t bitfield_range = 0) :
		type_class(type.type_class),
		type(&type),
		raw_name(raw_name),
		nice_name(nice_name),
		description(description),
		parent(parent)
	{
		ASSERT(underlying_type_size < (1u << 23u));
		ASSERT(field_offset < (1u << 25u));

		this->size = underlying_type_size;
		this->offset = field_offset;
		this->bitfield_offset = bitfield_offset;
		this->bitfield_range = bitfield_range;
	}

	union
	{
		e_reflection_type_class type_class : 4; // duplicate data
		struct
		{
			uint64_t : 4; // padding for type_class
			uint64_t size : 23; // 8MiB max #WARN: Check against this size to determine specific size of underlying represented types for enums/bitfields
			uint64_t offset : 25; // 32MiB max
			uint64_t bitfield_offset : 6; // 64bit max
			uint64_t bitfield_range : 6; // 64 bits max
		};
	};
	union
	{
		const s_reflection_type* type;
		const s_reflection_structure* structure;
		const s_reflection_enum* enumeration;
	};
	const char* raw_name;
	const char* nice_name;
	const char* description;
	const s_reflection_structure& parent;
};

struct s_reflection_enum_name
{
	s_reflection_enum_name(const s_reflection_enum& parent, uint64_t value, const char* raw_name, const char* nice_name, const char* description) :
		value(value),
		raw_name(raw_name),
		nice_name(nice_name),
		description(description),
		parent(parent)
	{

	}

	const uint64_t value;
	const char* raw_name;
	const char* nice_name;
	const char* description;
	const s_reflection_enum& parent;
};

struct s_reflection_structure : public s_reflection_type
{
	s_reflection_structure(e_reflection_type_class type, uint32_t size, const char* raw_name, const char* nice_name, const char* description, const s_reflection_structure* inheritance, const s_reflection_member* members, uint16_t num_menbers) :
		s_reflection_type(type, size, raw_name, nice_name, description),
		num_members(num_menbers),
		members(members),
		inheritance(inheritance)
	{

	}

	const s_reflection_structure* inheritance;
	const uint16_t num_members;
	const s_reflection_member* members;

	const s_reflection_member* begin() const { return members; }
	const s_reflection_member* end() const { return members + num_members; }
};

struct s_reflection_enum : public s_reflection_type
{
	s_reflection_enum(e_reflection_type_class type, uint32_t size, const char* raw_name, const char* nice_name, const char* description, const s_reflection_enum_name* names, uint16_t num_names) :
		s_reflection_type(type, size, raw_name, nice_name, description),
		num_names(num_names),
		names(names)
	{

	}

	const uint16_t num_names;
	const s_reflection_enum_name* names;
};

extern const s_reflection_member g_members[];
extern const s_reflection_enum_name g_enum_names[];

template<typename T>
const s_reflection_enum& enum_reflection();

template<typename T>
const s_reflection_structure& structure_reflection();

const s_reflection_structure* reflection(uint32_t tag_group);

template<typename T>
decltype(auto) reflection()
{
	constexpr bool is_enum = __is_enum(T);
	if constexpr (is_enum)
	{
		return enum_reflection<T>();
	}
	else
	{
		return structure_reflection<T>();
	}
}
