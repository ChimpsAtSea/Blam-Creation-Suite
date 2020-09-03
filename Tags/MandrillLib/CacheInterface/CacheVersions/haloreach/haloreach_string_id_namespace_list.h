#pragma once

class c_haloreach_string_id_namespace_list :
	public c_string_id_interface
{
public:
	c_haloreach_string_id_namespace_list();
	~c_haloreach_string_id_namespace_list();

	virtual uint32_t string_id_to_index(string_id const stringid) override final;
};

