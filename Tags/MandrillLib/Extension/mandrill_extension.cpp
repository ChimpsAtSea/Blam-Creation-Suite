#include "mandrilllib-private-pch.h"

static std::vector<c_mandrill_extension*> extensions;

void c_mandrill_extension::register_extension(c_mandrill_extension* extension)
{
	extensions.push_back(extension);
}

c_mandrill_extension*const* c_mandrill_extension::get_extensions()
{
	return extensions.data();
}

uint32_t c_mandrill_extension::get_extension_count()
{
	return static_cast<uint32_t>(extensions.size());
}

c_cache_file* c_mandrill_extension::create_cache_file(const std::wstring& map_filepath)
{
	return nullptr;
}

c_virtual_tag_interface* c_mandrill_extension::create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag)
{
	return nullptr;
}

c_mandrill_extension::c_mandrill_extension()
{

}

c_mandrill_extension::~c_mandrill_extension()
{

}
