#pragma once

enum e_assembly_data_type
{
	_data_type_unknown,
	_data_type_reflexive,
	_data_type_tagref,
	_data_type_dataref,
	_data_type_shader,
	_data_type_uniclist,
	_data_type_comment,
	_data_type_raw,
	_data_type_ascii,
	_data_type_utf16,
	_data_type_stringid,
	_data_type_int8,
	_data_type_int16,
	_data_type_int32,
	_data_type_int64,
	_data_type_uint8,
	_data_type_uint16,
	_data_type_uint32,
	_data_type_uint64,
	_data_type_bitfield8,
	_data_type_bitfield16,
	_data_type_bitfield32,
	_data_type_bitfield64,
	_data_type_enum8,
	_data_type_enum16,
	_data_type_enum32,
	_data_type_enum64,
	_data_type_undefined8,
	_data_type_undefined16,
	_data_type_undefined32,
	_data_type_undefined64,
	_data_type_half,
	_data_type_float,
	_data_type_double,
	_data_type_degree,
	_data_type_color24,
	_data_type_color32,
	_data_type_colorf,

};

inline const char* data_type_to_underlying_type_string(e_assembly_data_type data_type)
{
	switch (data_type)
	{
	case _data_type_reflexive:			return "s_tag_block_legacy";
	case _data_type_comment:			return "// ";
	case _data_type_raw:				return "signed char";
	case _data_type_ascii:				return "char";
	case _data_type_utf16:				return "wchar_t";
	case _data_type_tagref:				return "s_tag_reference_legacy";
	case _data_type_dataref:			return "s_data_reference_legacy";
	case _data_type_stringid:			return "string_id";
	case _data_type_int8:				return "int8_t";
	case _data_type_int16:				return "int16_t";
	case _data_type_int32:				return "int32_t";
	case _data_type_int64:				return "int64_t";
	case _data_type_uint8:				return "uint8_t";
	case _data_type_uint16:				return "uint16_t";
	case _data_type_uint32:				return "uint32_t";
	case _data_type_uint64:				return "uint64_t";
	case _data_type_bitfield8:			return "uint8_t";
	case _data_type_bitfield16:			return "uint16_t";
	case _data_type_bitfield32:			return "uint32_t";
	case _data_type_bitfield64:			return "uint64_t";
	case _data_type_enum8:				return "uint8_t";
	case _data_type_enum16:				return "uint16_t";
	case _data_type_enum32:				return "uint32_t";
	case _data_type_enum64:				return "uint64_t";
	case _data_type_undefined8:			return "s_undefined8_legacy";
	case _data_type_undefined16:		return "s_undefined16_legacy";
	case _data_type_undefined32:		return "s_undefined32_legacy";
	case _data_type_undefined64:		return "s_undefined64_legacy";
	case _data_type_half:				return "half";
	case _data_type_float:				return "float";
	case _data_type_double:				return "double";
	case _data_type_degree:				return "float";
	case _data_type_color24:			return "color24";
	case _data_type_color32:			return "color32";
	case _data_type_colorf:				return "colorf";
	case _data_type_shader:				return "s_data_reference_legacy";
	case _data_type_uniclist:			return "uniclist";
	}
	return "<unknown e_assembly_data_type>";
}

inline const char* data_type_to_string(e_assembly_data_type data_type)
{
	switch (data_type)
	{
	case _data_type_reflexive:			return "reflexive";
	case _data_type_comment:			return "comment";
	case _data_type_raw:				return "raw";
	case _data_type_ascii:				return "ascii";
	case _data_type_utf16:				return "utf16";
	case _data_type_tagref:				return "tagref";
	case _data_type_dataref:			return "dataref";
	case _data_type_stringid:			return "stringid";
	case _data_type_int8:				return "int8";
	case _data_type_int16:				return "int16";
	case _data_type_int32:				return "int32";
	case _data_type_int64:				return "int64";
	case _data_type_uint8:				return "uint8";
	case _data_type_uint16:				return "uint16";
	case _data_type_uint32:				return "uint32";
	case _data_type_uint64:				return "uint64";
	case _data_type_bitfield8:			return "bitfield8";
	case _data_type_bitfield16:			return "bitfield16";
	case _data_type_bitfield32:			return "bitfield32";
	case _data_type_bitfield64:			return "bitfield64";
	case _data_type_enum8:				return "enum8";
	case _data_type_enum16:				return "enum16";
	case _data_type_enum32:				return "enum32";
	case _data_type_enum64:				return "enum64";
	case _data_type_undefined8:			return "undefined8";
	case _data_type_undefined16:		return "undefined16";
	case _data_type_undefined32:		return "undefined32";
	case _data_type_undefined64:		return "undefined64";
	case _data_type_half:				return "half";
	case _data_type_float:				return "float";
	case _data_type_double:				return "double";
	case _data_type_degree:				return "degree";
	case _data_type_color24:			return "color24";
	case _data_type_color32:			return "color32";
	case _data_type_colorf:				return "colorf";
	case _data_type_shader:				return "shader";
	case _data_type_uniclist:			return "uniclist";
	}
	return "<unknown e_assembly_data_type>";
}
