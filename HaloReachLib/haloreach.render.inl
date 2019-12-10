
HaloReach_2019_Jun_24_Data<void*, 0x1810EC5B0> g_pIDXGISwapChain;
HaloReach_2019_Jun_24_Data<IID, 0x180E0B2A8> stru_180E0B2A8;
HaloReach_2019_Jun_24_Pointer<IDXGIFactory1*, 0x18112D368> ppFactory;

intptr_t g_pDevice_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x18112D588;
	case BuildVersion::Build_1_1035_0_0: return 0x180D37AA0;
	}
	return ~intptr_t();
}
// #TODO: Remove this and create the device at the MCC layer
DataEx<ID3D11Device*, g_pDevice_offset> g_pDevice;

intptr_t g_pSwapChain_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x18112D378;
	case BuildVersion::Build_1_1035_0_0: return 0x184465D68;
	}
	return ~intptr_t();
}
// #TODO: Remove this and create the device at the MCC layer
PointerEx<IDXGISwapChain*, g_pSwapChain_offset> g_pSwapChain;

intptr_t initialize_device_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x1806C2C30;
	case BuildVersion::Build_1_1035_0_0: return 0x18040C8C0;
	}
	return ~intptr_t();
}

// allow the game to read the command line to use -width and -height
FunctionHookEx<initialize_device_offset, char()> initialize_device = { "initialize_device", []()
{
	//g_pDevice = GameRender::s_pDevice;

	auto result = initialize_device();
	//IDXGISwapChain* pSwapChain = g_pSwapChain;
	assert(result == 1);
  return result;
} };

intptr_t game_options_new_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x18034A630;
	case BuildVersion::Build_1_1035_0_0: return 0x18017C150;
	}
	return ~intptr_t();
}
FunctionHookEx<game_options_new_offset, __int64 __fastcall (s_game_options* game_options)> game_options_new = { "game_options_new", [](s_game_options* game_options) {

	auto result = game_options_new(game_options);

	game_options->frame_limit = g_frameLimit;

	return result;
} };

intptr_t observer_get_suggested_field_of_view_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x1804DA240;
	case BuildVersion::Build_1_1035_0_0: return 0x18029B8B0;
	}
	return ~intptr_t();
}
FunctionHookEx<observer_get_suggested_field_of_view_offset, float(__stdcall)()> observer_get_suggested_field_of_view = { "observer_get_suggested_field_of_view", []() {

	auto result = observer_get_suggested_field_of_view();

	return g_fieldOfView * 0.017453292f;

	return result;
} };

intptr_t camera_new_offset(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0: return 0x1803E3510;
	case BuildVersion::Build_1_1035_0_0: return 0x1801F1B20;
	}
	return ~intptr_t();
}
FunctionHookEx<camera_new_offset, __int64(__fastcall)(uint8_t*, int, float, char)> camera_new = { "camera_new", [](uint8_t* director, int camera_type, float camera_speed, char force_update) {

	//if (camera_type == 4) // on death set the camera_mode to flying
	//	camera_type = 2;

	auto result = camera_new(director, camera_type, camera_speed, force_update);
	return result;
} };

