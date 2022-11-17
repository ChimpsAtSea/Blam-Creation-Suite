#include "highlevelcachefileserialization-private-pch.h"

//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
//#include <Generated/high_level_halo1_pc64/highlevel-halo1-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
//#include <Generated/high_level_halo2_pc64/highlevel-halo2-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
//#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
//#include <Generated/high_level_halo3odst_pc64/highlevel-halo3odst-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
//#include <Generated/high_level_eldorado_pc32/highlevel-eldorado-pc32-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
//#include <Generated/high_level_haloreach_xbox360/highlevel-haloreach-xbox360-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
//#include <Generated/high_level_halo4_xbox360/highlevel-halo4-xbox360-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
//#include <Generated/high_level_groundhog_pc64/highlevel-groundhog-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
//#include <Generated/high_level_halo5_pc64/highlevel-halo5-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
//#include <Generated/high_level_infinite_pc64/highlevel-infinite-pc64-public-pch.h>
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
//#include <Generated/high_level_stubbs_pc64/highlevel-stubbs-pc64-public-pch.h>
//#endif
//
//h_tag_instance& h_group::create_tag_instance(const char* filepath)
//{
//	h_tag_instance* tag = nullptr;
//	switch (engine_platform_build.engine_type)
//	{
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
//	case _engine_type_halo1:
//		tag = blofeld::halo1::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
//	case _engine_type_halo2:
//		tag = blofeld::halo2::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
//	case _engine_type_halo3:
//		tag = blofeld::halo3::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
//	case _engine_type_halo3odst:
//		tag = blofeld::halo3odst::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
//	case _engine_type_eldorado:
//		tag = blofeld::eldorado::pc32::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
//	case _engine_type_haloreach:
//		tag = blofeld::haloreach::xbox360::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
//	case _engine_type_halo4:
//		tag = blofeld::halo4::xbox360::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
//	case _engine_type_groundhog:
//		tag = blofeld::groundhog::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
//	case _engine_type_halo5:
//		tag = blofeld::halo5::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
//	case _engine_type_haloinfinite:
//		tag = blofeld::haloinfinite::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
//	case _engine_type_stubbs:
//		tag = blofeld::stubbs::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//	default: FATAL_ERROR("Unsupported engine type");
//	}
//
//	ASSERT(tag != nullptr);
//
//	tags.push_back(tag);
//
//	return *tag;
//}
//
//void h_group::associate_tag_instance(h_tag_instance& tag_instance)
//{
//	// #TODO: check that tag has no group already
//	// #TODO: check that tag hasn't already been added
//
//	tag_instance.group = this;
//	tags.push_back(&tag_instance);
//}
//
//h_prototype* h_prototype::create_high_level_object(blofeld::s_tag_struct_definition const& struct_definition, s_engine_platform_build engine_platform_build)
//{
//	h_prototype* object = nullptr;
//	switch (engine_platform_build.engine_type)
//	{
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
//	case _engine_type_halo1:
//		object = blofeld::halo1::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
//	case _engine_type_halo2:
//		object = blofeld::halo2::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
//	case _engine_type_halo3:
//		object = blofeld::halo3::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
//	case _engine_type_halo3odst:
//		object = blofeld::halo3odst::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
//	case _engine_type_eldorado:
//		object = blofeld::eldorado::pc32::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
//	case _engine_type_haloreach:
//		object = blofeld::haloreach::xbox360::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
//	case _engine_type_halo4:
//		object = blofeld::halo4::xbox360::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
//	case _engine_type_groundhog:
//		object = blofeld::groundhog::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
//	case _engine_type_halo5:
//		tag = blofeld::halo5::pc64::create_high_level_tag(*this, filepath);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
//	case _engine_type_haloinfinite:
//		object = blofeld::haloinfinite::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
//	case _engine_type_stubbs:
//		object = blofeld::stubbs::pc64::create_high_level_object(struct_definition);
//		break;
//#endif
//	default: FATAL_ERROR("Unsupported engine type");
//	}
//	return object;
//}
