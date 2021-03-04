#include <eldoradolib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

void load_map(const char* scenario_path, int scenario_type, int game_engine_variant)
{
	uintptr_t g_game_options_address;
	uintptr_t main_game_change_immediate_address;
	
	s_engine_platform_build engine_platform_build = { e_engine_type::_engine_type_eldorado, _platform_type_pc_legacy, c_eldorado_game_host::get_build() };

	switch (engine_platform_build.build)
	{
	case _build_eldorado_1_106708_cert_ms23:
		g_game_options_address = 0x02391800;
		main_game_change_immediate_address = 0x00566EF0;
		break;
	case _build_eldorado_1_604673_Live:
		g_game_options_address = 0x0438E6B0;
		main_game_change_immediate_address = 0x004A9530;
		break;
	case _build_eldorado_1_700255_cert_ms30_oct19:
		g_game_options_address = 0x0312B5E0;
		main_game_change_immediate_address = 0x004AB190;
		break;
	default:
		return; // skip unknown builds
	}

	char* g_game_options;
	BCS_RESULT engine_virtual_address_to_pointer_result = engine_virtual_address_to_pointer(engine_platform_build, g_game_options_address, reinterpret_cast<void**>(&g_game_options));
	DEBUG_ASSERT(BCS_SUCCEEDED(engine_virtual_address_to_pointer_result));

	char(__thiscall * main_game_change_immediate)(char*);
	BCS_RESULT engine_virtual_address_to_pointer_result2 = engine_virtual_address_to_pointer(engine_platform_build, main_game_change_immediate_address, reinterpret_cast<void**>(&main_game_change_immediate));
	DEBUG_ASSERT(BCS_SUCCEEDED(engine_virtual_address_to_pointer_result2));

	sprintf_s(g_game_options + 0x24, 128, "%s", scenario_path);
	*reinterpret_cast<int*>(g_game_options + 0x0) = scenario_type;
	*reinterpret_cast<int*>(g_game_options + 0x32C) = game_engine_variant;

	main_game_change_immediate(g_game_options);
}

c_eldorado_load_map_command::c_eldorado_load_map_command()
{
	c_console::register_command(k_eldorado_load_map_command_name, this);
}

c_eldorado_load_map_command::~c_eldorado_load_map_command()
{
	c_console::unregister_command(k_eldorado_load_map_command_name);
}

bool c_eldorado_load_map_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_eldorado_load_map_command_name))
	{
		if (arguments.size() > 1 && arguments.size() < 4)
		{
			const std::string& map_name = arguments[1];
			int map_type = 1;
			int game_type = 0;
			if (arguments.size() > 2)
				map_type = std::stoi(arguments[2]);
			if (arguments.size() > 3)
				game_type = std::stoi(arguments[3]);

			c_console::set_text_color(_console_color_info);
			c_console::write_line_verbose("Loading map %s", map_name.c_str());
			load_map(map_name.c_str(), map_type, game_type);
		}
		else return false;
	}
	return true;
}

std::string c_eldorado_load_map_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_eldorado_load_map_command_name))
		{
			return
				"Load a map\n"
				"Usage: loadmap <map name>";
		}
	}
	return "";
}

std::string c_eldorado_load_map_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	return ""; // todo;
}

/* ---------- private code */

