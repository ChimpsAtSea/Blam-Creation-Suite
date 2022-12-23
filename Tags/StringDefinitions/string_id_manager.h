#pragma once

class c_string_id_manager
{
public:
	BCS_SHARED c_string_id_manager();
	BCS_SHARED virtual ~c_string_id_manager();

	BCS_SHARED virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) = 0;
	BCS_SHARED virtual BCS_RESULT commit_string(const char* string) = 0;
	BCS_SHARED virtual BCS_RESULT fetch_string_id(const char* string, uint32_t& string_id) const = 0;
	BCS_SHARED virtual BCS_RESULT fetch_string(uint32_t string_id, const char*& string) const = 0;
	BCS_SHARED virtual BCS_RESULT clear() = 0;
};