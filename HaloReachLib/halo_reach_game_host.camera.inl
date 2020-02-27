
uintptr_t player_mapping_get_local_player_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo_reach)
	{
		switch (build)
		{
		case e_build::_build_mcc_1_1270_0_0: return 0x18006FDF0;
		case e_build::_build_mcc_1_1305_0_0: return 0x18006FE30;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<player_mapping_get_local_player_offset, int __stdcall ()> player_mapping_get_local_player;

uintptr_t observer_try_and_get_camera_offset(e_engine_type engine_type, e_build build)
{
	if (engine_type == _engine_type_halo_reach)
	{
		switch (build)
		{
		case e_build::_build_mcc_1_1270_0_0: return 0x1800E2FA0;
		case e_build::_build_mcc_1_1305_0_0: return 0x1800E3050;
		}
	}
	return ~uintptr_t();
}
FunctionHookEx<observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> observer_try_and_get_camera;
