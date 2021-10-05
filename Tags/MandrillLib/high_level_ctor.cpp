#include "mandrilllib-private-pch.h"


// #TODO: fixup this. bad. nasty.
namespace blofeld
{
	namespace halo1
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace stubbs
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace halo2
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace halo3
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace halo3odst
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace haloreach
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace halo4
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace groundhog
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace xbox360_gen3
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
	namespace infinite
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
		h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);
	}
}

h_tag& h_group::create_tag_instance(const char* filepath)
{
	h_tag* tag = nullptr;
	switch (engine_platform_build.engine_type)
	{
		case _engine_type_halo1:
			tag = blofeld::halo1::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_stubbs:
			tag = blofeld::stubbs::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_halo2:
			tag = blofeld::halo2::create_high_level_tag(*this, filepath);
			break;
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
		case _engine_type_gen3_xbox360:
			tag = blofeld::xbox360_gen3::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_infinite:
			tag = blofeld::infinite::create_high_level_tag(*this, filepath);
			break;
	default: FATAL_ERROR("Unsupported engine type");
	}

	ASSERT(tag != nullptr);

	tags.push_back(tag);

	return *tag;
}

h_object* h_object::create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition, s_engine_platform_build engine_platform_build)
{
	h_object* object = nullptr;
	switch (engine_platform_build.engine_type)
	{
		case _engine_type_halo1:
			object = blofeld::halo1::create_high_level_object(struct_definition);
			break;
		case _engine_type_stubbs:
			object = blofeld::stubbs::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo2:
			object = blofeld::halo2::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo3:
			object = blofeld::halo3::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo3odst:
			object = blofeld::halo3odst::create_high_level_object(struct_definition);
			break;
		case _engine_type_haloreach:
			object = blofeld::haloreach::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo4:
			object = blofeld::halo4::create_high_level_object(struct_definition);
			break;
		case _engine_type_groundhog:
			object = blofeld::groundhog::create_high_level_object(struct_definition);
			break;
		case _engine_type_gen3_xbox360:
			object = blofeld::xbox360_gen3::create_high_level_object(struct_definition);
			break;
		case _engine_type_infinite:
			object = blofeld::infinite::create_high_level_object(struct_definition);
			break;
	default: FATAL_ERROR("Unsupported engine type");
	}
	return object;
}
