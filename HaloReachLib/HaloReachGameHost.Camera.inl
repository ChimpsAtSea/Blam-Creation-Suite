
intptr_t player_mapping_get_local_player_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x18006FDF0;
	}
	return ~intptr_t();
}
FunctionHookEx<player_mapping_get_local_player_offset, int __stdcall ()> player_mapping_get_local_player;

intptr_t observer_try_and_get_camera_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x1800E2FA0;
	}
	return ~intptr_t();
}
FunctionHookEx<observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> observer_try_and_get_camera;
