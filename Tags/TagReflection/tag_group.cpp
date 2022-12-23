#include "tagreflection-private-pch.h"

h_tag_group::h_tag_group(s_engine_platform_build engine_platform_build, blofeld::s_tag_group const& _blofeld_tag_group) :
	mutex(),
	tags(),
	engine_platform_build(engine_platform_build),
	blofeld_tag_group(_blofeld_tag_group)
{

}

h_tag_group::~h_tag_group()
{

}

BCS_RESULT h_tag_group::create_tag_instance(const char* relative_filepath_without_extension, h_tag_instance*& tag_instance)
{
	BCS_RESULT rs = BCS_S_OK;

	h_prototype* prototype;
	if (BCS_FAILED(rs = high_level_registry_create_high_level_object(engine_platform_build, blofeld_tag_group.block_definition.struct_definition, prototype)))
	{
		return rs;
	}

	// #TODO: Prevent duplicate file names

	tag_instance = new() h_tag_instance(*prototype, *this, relative_filepath_without_extension);
	
	mutex.lock();
	tags.push_back(tag_instance);
	mutex.unlock();

	return BCS_S_OK;
}
