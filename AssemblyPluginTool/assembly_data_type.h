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
	_data_type_colour24,
	_data_type_colour32,
	_data_type_colourf,

};

inline const char* data_type_to_string(e_assembly_data_type data_type)
{
	switch (data_type)
	{
	case _data_type_reflexive:			return "_data_type_reflexive";
	case _data_type_comment:			return "_data_type_comment";
	case _data_type_raw:				return "_data_type_raw";
	case _data_type_ascii:				return "_data_type_ascii";
	case _data_type_utf16:				return "_data_type_utf16";
	case _data_type_tagref:				return "_data_type_tagref";
	case _data_type_dataref:			return "_data_type_dataref";
	case _data_type_stringid:			return "_data_type_stringid";
	case _data_type_int8:				return "_data_type_int8";
	case _data_type_int16:				return "_data_type_int16";
	case _data_type_int32:				return "_data_type_int32";
	case _data_type_int64:				return "_data_type_int64";
	case _data_type_uint8:				return "_data_type_uint8";
	case _data_type_uint16:				return "_data_type_uint16";
	case _data_type_uint32:				return "_data_type_uint32";
	case _data_type_uint64:				return "_data_type_uint64";
	case _data_type_bitfield8:			return "_data_type_bitfield8";
	case _data_type_bitfield16:			return "_data_type_bitfield16";
	case _data_type_bitfield32:			return "_data_type_bitfield32";
	case _data_type_bitfield64:			return "_data_type_bitfield64";
	case _data_type_enum8:				return "_data_type_enum8";
	case _data_type_enum16:				return "_data_type_enum16";
	case _data_type_enum32:				return "_data_type_enum32";
	case _data_type_enum64:				return "_data_type_enum64";
	case _data_type_undefined8:			return "_data_type_undefined8";
	case _data_type_undefined16:		return "_data_type_undefined16";
	case _data_type_undefined32:		return "_data_type_undefined32";
	case _data_type_undefined64:		return "_data_type_undefined64";
	case _data_type_half:				return "_data_type_half";
	case _data_type_float:				return "_data_type_float";
	case _data_type_double:				return "_data_type_double";
	case _data_type_degree:				return "_data_type_degree";
	case _data_type_colour24:			return "_data_type_colour24";
	case _data_type_colour32:			return "_data_type_colour32";
	case _data_type_colourf:			return "_data_type_colourf";
	case _data_type_shader:				return "_data_type_shader";
	case _data_type_uniclist:			return "_data_type_uniclist";
	}
	return "<unknown e_assembly_data_type>";
}
