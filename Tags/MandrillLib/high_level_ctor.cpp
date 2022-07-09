#include "mandrilllib-private-pch.h"

#include <Generated/high_level_halo1_pc64/highlevel-halo1-pc64-public-pch.h>
#include <Generated/high_level_halo2_pc64/highlevel-halo2-pc64-public-pch.h>
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#include <Generated/high_level_halo3odst_pc64/highlevel-halo3odst-pc64-public-pch.h>
#include <Generated/high_level_haloreach_xbox360/highlevel-haloreach-xbox360-public-pch.h>
#include <Generated/high_level_halo4_xbox360/highlevel-halo4-xbox360-public-pch.h>

h_tag& h_group::create_tag_instance(const char* filepath)
{
	h_tag* tag = nullptr;
	switch (engine_platform_build.engine_type)
	{
		case _engine_type_halo1:
			tag = blofeld::halo1::pc64::create_high_level_tag(*this, filepath);
			break;
		//case _engine_type_stubbs:
		//	tag = blofeld::stubbs::create_high_level_tag(*this, filepath);
		//	break;
		case _engine_type_halo2:
			tag = blofeld::halo2::pc64::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_halo3:			
			tag = blofeld::halo3::pc64::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_halo3odst:		
			tag = blofeld::halo3odst::pc64::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_haloreach:		
			tag = blofeld::haloreach::xbox360::create_high_level_tag(*this, filepath);
			break;
		case _engine_type_halo4:			
			tag = blofeld::halo4::xbox360::create_high_level_tag(*this, filepath);
			break;
		//case _engine_type_groundhog:		
		//	tag = blofeld::groundhog::create_high_level_tag(*this, filepath);
		//	break;
		//case _engine_type_infinite:
		//	tag = blofeld::infinite::create_high_level_tag(*this, filepath);
		//	break;
	default: FATAL_ERROR("Unsupported engine type");
	}

	ASSERT(tag != nullptr);

	tags.push_back(tag);

	return *tag;
}

void h_group::associate_tag_instance(h_tag& tag_instance)
{
	// #TODO: check that tag has no group already
	// #TODO: check that tag hasn't already been added

	tag_instance.group = this;
	tags.push_back(&tag_instance);
}

h_prototype* h_prototype::create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition, s_engine_platform_build engine_platform_build)
{
	h_prototype* object = nullptr;
	switch (engine_platform_build.engine_type)
	{
		case _engine_type_halo1:
			object = blofeld::halo1::pc64::create_high_level_object(struct_definition);
			break;
		//case _engine_type_stubbs:
		//	object = blofeld::stubbs::create_high_level_object(struct_definition);
		//	break;
		case _engine_type_halo2:
			object = blofeld::halo2::pc64::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo3:
			object = blofeld::halo3::pc64::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo3odst:
			object = blofeld::halo3odst::pc64::create_high_level_object(struct_definition);
			break;
		case _engine_type_haloreach:
			object = blofeld::haloreach::xbox360::create_high_level_object(struct_definition);
			break;
		case _engine_type_halo4:
			object = blofeld::halo4::xbox360::create_high_level_object(struct_definition);
			break;
		//case _engine_type_groundhog:
		//	object = blofeld::groundhog::create_high_level_object(struct_definition);
		//	break;
		//case _engine_type_infinite:
		//	object = blofeld::infinite::create_high_level_object(struct_definition);
		//	break;
	default: FATAL_ERROR("Unsupported engine type");
	}
	return object;
}
