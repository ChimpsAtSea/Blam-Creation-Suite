#include "tagreflection-private-pch.h"

h_tag::h_tag(const blofeld::s_tag_group& tag_group, h_group* group, const char* tag_name, uint32_t type_size) :
	h_type(tag_group.block_definition.struct_definition, type_size),
	tag_name(tag_name ? tag_name : ""),
	tag_group(tag_group),
	group(group)
{

}

h_tag::~h_tag()
{

}

h_type::h_type(const blofeld::s_tag_struct_definition& tag_struct_definition, uint32_t type_size) :
	tag_struct_definition(tag_struct_definition),
	type_size(type_size)
{

}

h_type::~h_type()
{

}

h_group::h_group(e_engine_type engine_type, e_platform_type platform_type, e_build build, const blofeld::s_tag_group& tag_group) :
	tags(),
	engine_type(engine_type),
	platform_type(platform_type),
	build(build),
	tag_group(tag_group)
{

}

h_group::~h_group()
{

}

namespace blofeld
{
	namespace halo3
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo3odst
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace haloreach
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo4
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace groundhog
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
}

h_tag& h_group::create_tag_instance(const char* filepath)
{
	h_tag* tag = nullptr;
	switch (engine_type)
	{
	case _engine_type_halo3:			
		tag = blofeld::halo3::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo3odst:		
		tag = blofeld::halo3odst::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_haloreach:		
		tag = blofeld::haloreach::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo4:			
		tag = blofeld::halo4::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_groundhog:		
		tag = blofeld::groundhog::create_high_level_tag(*this, filepath);
		break;
	default: FATAL_ERROR(L"Unsupported engine type");
	}

	ASSERT(tag != nullptr);

	tags.push_back(tag);

	return *tag;
}
