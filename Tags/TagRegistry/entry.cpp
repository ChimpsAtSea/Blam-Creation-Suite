#include "tagdefinitions-private-pch.h"

BCS_RESULT high_level_register()
{
	BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo1, _platform_type_pc_64bit }, blofeld::halo1::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo 1 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_stubbs, _platform_type_pc_64bit }, blofeld::stubbs::pc64::tag_groups)))
	{
		console_write_line("Failed to register Stubbs High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo2, _platform_type_pc_64bit }, blofeld::halo2::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo 2Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo3, _platform_type_pc_64bit }, blofeld::halo3::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo 3 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo3odst, _platform_type_pc_64bit }, blofeld::halo3odst::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo 3 ODST High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
	if (BCS_FAILED(rs = high_level_registry_register_global_vtable(
		blofeld::eldorado::pc32::global_vftable_index,
		{ _engine_type_eldorado, _platform_type_pc_32bit },
		blofeld::eldorado::pc32::local_vftables,
		blofeld::eldorado::pc32::create_high_level_object)))
	{
		console_write_line("Failed to register Eldorado High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
	if (BCS_FAILED(rs = high_level_registry_register_global_vtable(
		blofeld::haloreach::xbox360::global_vftable_index,
		{ _engine_type_haloreach, _platform_type_xbox_360 },
		blofeld::haloreach::xbox360::local_vftables,
		blofeld::haloreach::xbox360::create_high_level_object)))
	{
		console_write_line("Failed to register Halo Reach Xbox 360 High Level Tag Definitions");
		return rs;
	}
	if (BCS_FAILED(rs = high_level_registry_register_global_vtable(
		blofeld::haloreach::pc64::global_vftable_index,
		{ _engine_type_haloreach, _platform_type_pc_64bit },
		blofeld::haloreach::pc64::local_vftables,
		blofeld::haloreach::pc64::create_high_level_object)))
	{
		console_write_line("Failed to register Halo Reach PC 64bit High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo4, _platform_type_xbox_360 }, blofeld::halo4::xbox360::tag_groups)))
	{
		console_write_line("Failed to register Halo 4 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_groundhog, _platform_type_pc_64bit }, blofeld::groundhog::pc64::tag_groups)))
	{
		console_write_line("Failed to register Groundhog High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_halo5, _platform_type_pc_64bit }, blofeld::halo5::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo 5 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
	if (BCS_FAILED(rs = blofeld::high_level_registry_register_global_vtable({ _engine_type_haloinfinite, _platform_type_pc_64bit }, blofeld::haloinfinite::pc64::tag_groups)))
	{
		console_write_line("Failed to register Halo Infinite High Level Tag Definitions");
		return rs;
	}
#endif

	return rs;
}

BCS_RESULT high_level_unregister()
{
	BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo1, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo 1 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_stubbs, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Stubbs High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo2, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo 2Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo3, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo 3 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo3odst, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo 3 ODST High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_eldorado, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Eldorado High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_haloreach, _platform_type_xbox_360 })))
	{
		console_write_line("Failed to unregister Halo Reach High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo4, _platform_type_xbox_360 })))
	{
		console_write_line("Failed to unregister Halo 4 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_groundhog, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Groundhog High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_halo5, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo 5 High Level Tag Definitions");
		return rs;
	}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_unregister_tag_group_collection({ _engine_type_haloinfinite, _platform_type_pc_64bit })))
	{
		console_write_line("Failed to unregister Halo Infinite High Level Tag Definitions");
		return rs;
	}
#endif

	return rs;
}
