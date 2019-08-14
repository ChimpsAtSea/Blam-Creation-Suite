
//// allow the game to read the command line to use -width and -height
//HaloReachHook<0x1806C2C30, char()> initialize_device = []()
//{
//	qword_183461018 = 0x10;
//
//	auto result = initialize_device();
//
//	return result;
//};

HaloReachHook<0x18034A630, __int64 __fastcall (s_game_options* game_options)> game_options_new = [](s_game_options* game_options)
{
	auto result = game_options_new(game_options);

	game_options->frame_limit = g_frameLimit;

	return result;
};

HaloReachHook<0x1804DA240, float(__stdcall)()> observer_get_suggested_field_of_view = []()
{
	auto result = observer_get_suggested_field_of_view();

	return g_fieldOfView * 0.017453292f;

	return result;
};

HaloReachHook<0x1803E3510, __int64(__fastcall)(uint8_t*, int, float, char)> camera_new = [](uint8_t* director, int camera_type, float camera_speed, char force_update)
{
	//if (camera_type == 4) // on death set the camera_mode to flying
	//	camera_type = 2;

	auto result = camera_new(director, camera_type, camera_speed, force_update);
	return result;
};

