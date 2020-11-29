#include "platform-private-pch.h"
#include "resource.h"

c_cached_resource_info* c_cached_resource_info::cached_resource_infos[k_num_resource_types];

c_cached_resource_info::c_cached_resource_info(e_resource_type resource_type) :
	resource_handle(NULL),
	resource_memory_handle(NULL),
	resource_size(0),
	resource_pointer(NULL)
{
	HMODULE instance_handle = c_runtime_util::get_current_module();
	resource_handle = c_resources_manager::get_resource_handle(resource_type);
	if (resource_handle == NULL) goto end_init_resource;
	resource_memory_handle = LoadResource(instance_handle, resource_handle);
	if (resource_memory_handle == NULL) goto end_init_resource;
	resource_size = SizeofResource(instance_handle, resource_handle);
	if (resource_size == 0) goto end_init_resource;
	resource_pointer = LockResource(resource_memory_handle);
	if (resource_pointer == nullptr) goto end_init_resource;

end_init_resource:;

}

c_cached_resource_info::~c_cached_resource_info()
{
	if (resource_pointer != nullptr)
	{
		UnlockResource(resource_pointer);
	}
}

c_cached_resource_info& c_cached_resource_info::get_info(e_resource_type resource_type)
{
	c_cached_resource_info*& resource_info = cached_resource_infos[resource_type];
	if (resource_info == nullptr)
	{
		resource_info = new c_cached_resource_info(resource_type);
	}

	return *resource_info;
}

LPCWSTR c_resources_manager::get_resource_type(e_resource_type type)
{
	switch (type)
	{
	case _resource_type_icon_application:
	case _resource_type_icon_blam_creation_suite:
	case _resource_type_icon_mandrill:
		return RT_ICON;
	default:
		return RT_RCDATA;
	}
}

LPCWSTR c_resources_manager::get_resource_int_resource(e_resource_type type)
{
	switch (type)
	{
	case _resource_type_icon_application:			return MAKEINTRESOURCEW(IDI_ICON_APPLICATION);
	case _resource_type_icon_blam_creation_suite:	return MAKEINTRESOURCEW(IDI_ICON_BLAM_CREATION_SUITE);
	case _resource_type_icon_mandrill:				return MAKEINTRESOURCEW(IDI_ICON_MANDRILL);
	case _resource_type_font_cousine_regular:		return MAKEINTRESOURCEW(IDR_FONT_COUSING_REGULAR);
	case _resource_type_font_font_awesome:			return MAKEINTRESOURCEW(IDR_FONT_FONT_AWESOME);
	case _resource_type_symbols_blob:				return MAKEINTRESOURCEW(IDR_MAPDATABASE);
	case _resource_type_box_pixel_shader:			return MAKEINTRESOURCEW(IDR_BOXSHADERPS);
	case _resource_type_box_vertex_shader:			return MAKEINTRESOURCEW(IDR_BOXSHADERVS);
	}
	return NULL;
}

const void* c_resources_manager::get_resource(e_resource_type type, size_t* resource_size)
{
	c_cached_resource_info& resource_info = c_cached_resource_info::get_info(type);

	if (resource_size)
	{
		*resource_size = resource_info.resource_size;
	}
	return resource_info.resource_pointer;
}

HRSRC c_resources_manager::get_resource_handle(e_resource_type type)
{
	static HMODULE instance_handle = c_runtime_util::get_current_module();

	LPCWSTR int_resource = get_resource_int_resource(type);
	if (int_resource == nullptr) return NULL;

	return FindResourceW(instance_handle, int_resource, get_resource_type(type));
}

bool c_resources_manager::copy_resource_to_buffer(e_resource_type type, void*& out_data, size_t* out_data_size, bool null_terminate)
{
	out_data = nullptr;
	if (out_data_size != nullptr)
	{
		*out_data_size = 0;
	}

	size_t resource_size = 0;
	if (const char* resource_data = static_cast<const char*>(get_resource(type, &resource_size)))
	{
		size_t buffer_size = resource_size;
		if (null_terminate)
		{
			buffer_size++;
		}

		char* resource_buffer = new char[buffer_size];
		if (null_terminate)
		{
			resource_buffer[resource_size] = 0;
		}

		memcpy(resource_buffer, resource_data, resource_size);

		out_data = resource_buffer;
		if (out_data_size != nullptr)
		{
			*out_data_size = buffer_size;
		}
		
		return true;
	}

	return false;
}
