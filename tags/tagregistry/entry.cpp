#include "tagregistry-private-pch.h"

#define register_global_vtable(name, _namespace, _engine_type, _platform_type) \
do \
{ \
	if (BCS_FAILED(rs = high_level_registry_register_global_vtable( \
		_namespace::global_vftable_index, \
		{ _engine_type, _platform_type }, \
		_namespace::local_vftables, \
		_namespace::create_high_level_object))) \
	{ \
		console_write_line("Failed to register " name " High Level Tag Definitions"); \
		return rs; \
	} \
} while(false)

#define unregister_global_vtable(name, _namespace, _engine_type, _platform_type) \
do \
{ \
	if (BCS_FAILED(rs = high_level_registry_unregister_global_vtable( \
		_namespace::global_vftable_index, \
	{ _engine_type, _platform_type }))) \
	{ \
		console_write_line("Failed to unregister " name " High Level Tag Definitions"); \
		return rs; \
	} \
} while(false)

BCS_RESULT high_level_register()
{
	BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
	register_global_vtable("Halo 1 PC 64bit", blofeld::halo1::pc64, _engine_type_halo1, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
	register_global_vtable("Stubbs PC 64bit", blofeld::stubbs::pc64, _engine_type_stubbs, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
	register_global_vtable("Halo 2 PC 64bit", blofeld::halo2::pc64, _engine_type_halo2, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
	register_global_vtable("Halo 3 PC 64bit", blofeld::halo3::pc64, _engine_type_halo3, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
	register_global_vtable("Halo 3 ODST PC 64bit", blofeld::halo3odst::pc64, _engine_type_halo3odst, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
	register_global_vtable("Eldorado PC 32bit", blofeld::eldorado::pc32, _engine_type_eldorado, _platform_type_pc_32bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
	register_global_vtable("Halo Reach Xbox 360", blofeld::haloreach::xbox360, _engine_type_haloreach, _platform_type_xbox_360);
	register_global_vtable("Halo Reach PC 64bit", blofeld::haloreach::pc64, _engine_type_haloreach, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
	register_global_vtable("Halo 4 Xbox 360", blofeld::halo4::xbox360, _engine_type_halo4, _platform_type_xbox_360);
	register_global_vtable("Halo 4 PC 64bit", blofeld::halo4::pc64, _engine_type_halo4, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
	register_global_vtable("Groundhog PC 64bit", blofeld::groundhog::pc64, _engine_type_groundhog, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
	register_global_vtable("Halo 5 PC 64bit", blofeld::halo5::pc64, _engine_type_halo5, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
	register_global_vtable("Halo Infinite PC 64bit", blofeld::haloinfinite::pc64, _engine_type_haloinfinite, _platform_type_pc_64bit);
#endif

	return rs;
}

BCS_RESULT high_level_unregister()
{
	BCS_RESULT rs = BCS_S_OK;

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
	unregister_global_vtable("Halo 1 PC 64bit", blofeld::halo1::pc64, _engine_type_halo1, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
	unregister_global_vtable("Stubbs PC 64bit", blofeld::stubbs::pc64, _engine_type_stubbs, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
	unregister_global_vtable("Halo 2 PC 64bit", blofeld::halo2::pc64, _engine_type_halo2, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
	unregister_global_vtable("Halo 3 PC 64bit", blofeld::halo3::pc64, _engine_type_halo3, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
	unregister_global_vtable("Halo 3 ODST PC 64bit", blofeld::halo3odst::pc64, _engine_type_halo3odst, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
	unregister_global_vtable("Eldorado PC 32bit", blofeld::eldorado::pc32, _engine_type_eldorado, _platform_type_pc_32bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
	unregister_global_vtable("Halo Reach Xbox 360", blofeld::haloreach::xbox360, _engine_type_haloreach, _platform_type_xbox_360);
	unregister_global_vtable("Halo Reach PC 64bit", blofeld::haloreach::pc64, _engine_type_haloreach, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
	unregister_global_vtable("Halo 4 Xbox 360", blofeld::halo4::xbox360, _engine_type_halo4, _platform_type_xbox_360);
	unregister_global_vtable("Halo 4 PC 64bit", blofeld::halo4::pc64, _engine_type_halo4, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
	unregister_global_vtable("Groundhog PC 64bit", blofeld::groundhog::pc64, _engine_type_groundhog, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
	unregister_global_vtable("Halo 5 PC 64bit", blofeld::halo5::pc64, _engine_type_halo5, _platform_type_pc_64bit);
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
	unregister_global_vtable("Halo Infinite PC 64bit", blofeld::haloinfinite::pc64, _engine_type_haloinfinite, _platform_type_pc_64bit);
#endif

	return rs;
}

#undef register_global_vtable
#undef unregister_global_vtable
