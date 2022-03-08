#pragma once

struct s_tag_persist_string_character_index;

class c_tag_file_string_debugger
{
public:
	virtual const char* get_string_by_string_character_index(const s_tag_persist_string_character_index& offset) const = 0;
};

