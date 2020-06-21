#pragma once

#define BCS_EXTENSION_VERSION 4

class c_cache_file;
class c_tag_interface;

class c_mandrill_extension
{
public:
	virtual int get_version() = 0;
	virtual const char* get_name() = 0;
	virtual c_cache_file* create_cache_file(const std::wstring& map_filepath);
	virtual BCSAPI c_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);
	BCSAPI c_mandrill_extension();
	BCSAPI virtual ~c_mandrill_extension();

	static BCSAPI void register_extension(c_mandrill_extension* extension);
	static BCSAPI c_mandrill_extension* const* get_extensions();
	static BCSAPI uint32_t get_extension_count();
};

using t_create_mandrill_extension = c_mandrill_extension * __cdecl ();

