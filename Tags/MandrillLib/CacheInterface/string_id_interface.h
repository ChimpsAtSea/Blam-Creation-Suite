#pragma once

class c_string_id_interface
{
public:
	virtual uint32_t string_id_to_index(string_id const stringid) = 0;
};
