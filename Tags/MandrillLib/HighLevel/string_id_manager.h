#pragma once

class c_string_id_manager
{
public:
	c_string_id_manager();
	virtual ~c_string_id_manager();

	virtual BCS_RESULT commit_string(const char* string, unsigned long& string_id) = 0;
	virtual BCS_RESULT commit_string(const char* string) = 0;
};