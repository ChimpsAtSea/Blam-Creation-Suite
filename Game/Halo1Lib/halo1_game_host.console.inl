
#pragma region console tests
uintptr_t hs_doc_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180780830);
	return ~uintptr_t();
}
c_function_hook_ex<hs_doc_offset, int()> hs_doc;


//__int64 sub_1807015E0()

uintptr_t console_initialize_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807015E0);
	return ~uintptr_t();
}
c_function_hook_ex<console_initialize_offset, signed int()> console_initialize = { "console_initialize", []()
{
	console_write_line("console_initialize called");
	return console_initialize();
} };

uintptr_t console_open_offset(s_engine_platform_build engine_platform_build)
{
	//OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180701760);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807EC5C0);

	return ~uintptr_t();
}
c_function_hook_ex<console_open_offset, signed int()> console_open = { "console_open", []()
{
	console_write_line("console_open called");
	return console_open();
} };

uintptr_t console_close_offset(s_engine_platform_build engine_platform_build)
{
	//OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180701800);
	return ~uintptr_t();
}
c_function_hook_ex<console_close_offset, signed int()> console_close = { "console_close", []()
{
	console_write_line("console_close called");
	return console_close();
} };

uintptr_t enable_console_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1821C8831);
	return ~uintptr_t();
}
char& enable_console = reference_symbol<char>("enable_console", enable_console_offset);

volatile uint32_t request_console_open = false;
volatile uint32_t request_console_close = false;

void update_console()
{
	if (is_valid(enable_console))
	{
		enable_console = true;
	}
	if (is_valid(console_open))
	{
		if (request_console_open)
		{
			request_console_open = 0;
			console_open();
		}
	}
	if (is_valid(console_close))
	{
		if (request_console_close)
		{
			request_console_close = 0;
			console_close();
		}
	}
}
static void draw_console_debug_gui()
{
	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(600, 600), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("Halo 1 Console/Scripting Debug"))
	{
		if (is_valid(console_open))
		{
			if (ImGui::Button("Console Open"))
			{
				_InterlockedIncrement(&request_console_open);
			}
		}
		if (is_valid(console_close))
		{
			if (ImGui::Button("Console Close"))
			{
				_InterlockedIncrement(&request_console_close);
			}
		}
		if (is_valid(hs_doc))
		{
			if (ImGui::Button("Dump Halo Script Documentation"))
			{
				hs_doc();
			}
		}
	}
	ImGui::End();
}

/* This was all for naught `IGameEngine->SendEngineCommand` can send halo script commands if you give it "HS: <command>"
// Offsets for dev console for build 1.1716.0.0 taken from https://github.com/Scaless/HaloTAS
// Scaless you're work is kinda epic dude

// Search for `aRasterizerNear` in IDA to find the offset
uintptr_t halo1_allow_dev_command_execution_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x180A9997F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x18077F7DF);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x18077F85F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x18077F88F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x18077F88F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18077F88F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1520_0_0, 0x18077FD2F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x18077FD2F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1619_0_0, 0x18077FD2F);
	OFFSET(_engine_type_halo1, _build_mcc_1_1698_0_0, 0x1807811BF);
	OFFSET(_engine_type_halo1, _build_mcc_1_1716_0_0, 0x1807811BF);
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x180B73E17);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x180B73E17);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x180B73E17);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x180B74417);
	return ~uintptr_t();
}
c_data_patch<halo1_allow_dev_command_execution_patch_offset> halo1_allow_dev_command_execution_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
{
	uint8_t mov[2] { 0xB0ui8, 0x01ui8 };
	packet = MAKE_DATAPATCHPACKET(data, sizeof(mov));
	copy_to_address(data, mov, sizeof(mov));
} };

// Search for `aMapNameB30` or `aRequestedFunct` in IDA to find the offset
uintptr_t halo1_execute_dev_command_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x180B272D0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x1807ED020);
	OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x1807ECF50);
	OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x1807ECF80);
	OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x1807ECF80);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807ECF80);
	OFFSET(_engine_type_halo1, _build_mcc_1_1520_0_0, 0x1807ED5A0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1570_0_0, 0x1807ED5A0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1619_0_0, 0x1807ED5A0);
	OFFSET(_engine_type_halo1, _build_mcc_1_1698_0_0, 0x1807EEA70);
	OFFSET(_engine_type_halo1, _build_mcc_1_1716_0_0, 0x1807EEA70);
	OFFSET(_engine_type_halo1, _build_mcc_1_1829_0_0, 0x180C0F230);
	OFFSET(_engine_type_halo1, _build_mcc_1_1864_0_0, 0x180C0F230);
	OFFSET(_engine_type_halo1, _build_mcc_1_1871_0_0, 0x180C0F230);
	OFFSET(_engine_type_halo1, _build_mcc_1_1955_0_0, 0x180C0FA80);
	return ~uintptr_t();
}
c_function_hook_ex<halo1_execute_dev_command_offset, char __fastcall(const char* src, unsigned short a2)> halo1_execute_dev_command;

void halo1_execute_command(const char* command)
{
	if (is_valid(halo1_execute_dev_command))
	{
		char result = halo1_execute_dev_command(command, 0);
	}
}
*/
#pragma endregion