
//// allow the game to read the command line to use -width and -height
//HaloReachHook<0x1806C2C30, char()> initialize_device = []()
//{
//	qword_183461018 = 0x10;
//
//	auto result = initialize_device();
//
//	return result;
//};

intptr_t game_options_new_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x18034A630;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18017C150;
	}
	return ~intptr_t();
}
HaloReachHookEx<game_options_new_offset, __int64 __fastcall (s_game_options *game_options)> game_options_new = { "game_options_new", [](s_game_options *game_options) {

	auto result = game_options_new(game_options);

	game_options->frame_limit = g_frameLimit;

	return result;
} };

intptr_t observer_get_suggested_field_of_view_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1804DA240;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x18029B8B0;
	}
	return ~intptr_t();
}
HaloReachHookEx<observer_get_suggested_field_of_view_offset, float(__stdcall)()> observer_get_suggested_field_of_view = { "observer_get_suggested_field_of_view", []() {

	auto result = observer_get_suggested_field_of_view();

	return g_fieldOfView * 0.017453292f;

	return result;
} };

intptr_t camera_new_offset(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach_2019_Jun_24: return 0x1803E3510;
	case HaloGameID::HaloReach_2019_Aug_20: return 0x1801F1B20;
	}
	return ~intptr_t();
}
HaloReachHookEx<camera_new_offset, __int64(__fastcall)(uint8_t *, int, float, char)> camera_new = { "camera_new", [](uint8_t *director, int camera_type, float camera_speed, char force_update) {

	//if (camera_type == 4) // on death set the camera_mode to flying
	//	camera_type = 2;

	auto result = camera_new(director, camera_type, camera_speed, force_update);
	return result;
} };

