#pragma once

class c_string_id_manager
{
public:
	BCS_SHARED c_string_id_manager();
	BCS_SHARED virtual ~c_string_id_manager();

	BCS_SHARED virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) = 0;
	BCS_SHARED virtual BCS_RESULT commit_string(const char* string) = 0;
};