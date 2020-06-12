#include "mantlelib-private-pch.h"

c_tag_interface::c_tag_interface(c_cache_file& cache_file, uint16_t tag_index) :
	tag_data(nullptr),
	tag_index(tag_index),
	is_tag_null(false),
	blofeld_reflection_type(nullptr),
	cache_file(cache_file),
	virtual_tag_interface(nullptr),
	virtual_resource_user_data(nullptr)
{
	
}

c_tag_interface::~c_tag_interface()
{
	if (virtual_tag_interface != nullptr)
	{
		delete virtual_tag_interface;
	}
}

void c_tag_interface::associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface)
{
	this->virtual_tag_interface = &virtual_tag_interface;
}

void c_tag_interface::init_virtual_tag_interface()
{
	if (is_null())
	{
		return;
	}

	if (get_group_tag() == blofeld::INVALID_TAG)
	{
		return;
	}

	blofeld_reflection_type = blofeld::get_group_tag_by_group_tag(get_group_tag());

	switch (cache_file.engine_type)
	{
	case _engine_type_halo3:
		virtual_tag_interface = blofeld::halo3::create_virtual_tag_interface(*this, get_group_tag());
		break;
	case _engine_type_haloreach:
		virtual_tag_interface = blofeld::haloreach::create_virtual_tag_interface(*this, get_group_tag());
		break;
	case _engine_type_halo4:
		virtual_tag_interface = blofeld::halo4::create_virtual_tag_interface(*this, get_group_tag());
		break;
	}

	if (virtual_tag_interface == nullptr)
	{
		if (c_tag_group_interface* tag_group_interface = get_tag_group_interface())
		{
			const char* tag_group_short_name = tag_group_interface->get_short_name();
			const char* tag_group_full_name = tag_group_interface->get_full_name();
			c_console::write_line_verbose(__FUNCTION__": warning unknown tag group '%s' '%s'", tag_group_short_name, tag_group_full_name);
		}
		else
		{
			c_console::write_line_verbose(__FUNCTION__": warning unknown tag group");
		}
	}
}

void c_tag_interface::register_with_tag_group()
{
	if (c_tag_group_interface* tag_group_interface = get_tag_group_interface())
	{
		tag_group_interface->add_tag_interface(*this);
	}
}

unsigned long c_tag_interface::get_group_tag() const
{
	return blofeld::INVALID_TAG;
}

c_tag_group_interface* c_tag_interface::get_tag_group_interface() const
{
	return nullptr;
}

c_tag_interface* c_tag_interface::create_tag_interface(c_cache_file& cache_file, uint16_t tag_index)
{
	if (c_halo1_cache_file* halo1_cache_file = dynamic_cast<c_halo1_cache_file*>(&cache_file))
	{
		return new c_halo1_tag_interface(*halo1_cache_file, tag_index);
	}
	if (c_halo2_cache_file* halo1_cache_file = dynamic_cast<c_halo2_cache_file*>(&cache_file))
	{
		//return new c_halo2_tag_interface(*halo1_cache_file, tag_index);
		FATAL_ERROR(L"c_halo2_tag_interface not implemented");
	}
	if (c_halo3_cache_file* halo1_cache_file = dynamic_cast<c_halo3_cache_file*>(&cache_file))
	{
		return new c_halo3_tag_interface(*halo1_cache_file, tag_index);
	}
	if (c_halo3odst_cache_file* halo1_cache_file = dynamic_cast<c_halo3odst_cache_file*>(&cache_file))
	{
		//return new c_halo3odst_tag_interface(*halo1_cache_file, tag_index);
		FATAL_ERROR(L"c_halo3odst_tag_interface not implemented");
	}
	if (c_haloreach_cache_file* haloreach_cache_file = dynamic_cast<c_haloreach_cache_file*>(&cache_file))
	{
		return new c_haloreach_tag_interface(*haloreach_cache_file, tag_index);
	}
	if (c_halo4_cache_file* halo1_cache_file = dynamic_cast<c_halo4_cache_file*>(&cache_file))
	{
		//return new c_halo4_tag_interface(*halo1_cache_file, tag_index);
		FATAL_ERROR(L"c_halo4_tag_interface not implemented");
	}
	FATAL_ERROR(L"Unsupported cache file type");
}
