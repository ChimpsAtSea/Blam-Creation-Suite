#pragma once

class c_debug_reader
{
public:
	c_debug_reader();
	virtual ~c_debug_reader();

	virtual BCS_RESULT string_id_to_index(string_id stringid, unsigned long& string_index) = 0;
	virtual BCS_RESULT string_id_to_index(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, unsigned long& string_index) = 0;
	virtual BCS_RESULT string_id_to_string(string_id stringid, const char*& string) = 0;
	virtual BCS_RESULT string_id_to_string(unsigned long string_id_index, unsigned long string_id_namespace, unsigned long string_id_length, const char*& string) = 0;
	virtual BCS_RESULT get_tag_filepath(unsigned long tag_index, const char*& filepath) = 0;
	virtual BCS_RESULT get_group_name(tag group_tag, const char*& group_name) = 0;
	virtual BCS_RESULT get_group_id(tag group_tag, const char*& group_id) = 0;
};
