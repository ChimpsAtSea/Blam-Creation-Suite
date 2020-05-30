#include <haloreachlib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

void haloreach_debug_save_camera(int(__stdcall *player_mapping_get_local_player)(), s_observer_camera *(__fastcall *observer_try_and_get_camera)(signed int local_player))
{
	if (player_mapping_get_local_player != nullptr && observer_try_and_get_camera != nullptr)
	{
		int local_player = player_mapping_get_local_player();
		s_observer_camera *observer_camera = observer_try_and_get_camera(local_player);

		FILE *stream = fopen("camera.txt", "w");
		if (stream)
		{
			fprintf(stream, "%f %f %f\n", observer_camera->position.i, observer_camera->position.j, observer_camera->position.k);
			fprintf(stream, "%f %f %f\n", observer_camera->forward.i, observer_camera->forward.j, observer_camera->forward.k);
			fprintf(stream, "%f %f %f\n", observer_camera->up.i, observer_camera->up.j, observer_camera->up.k);
			fprintf(stream, "%f\n", observer_camera->field_of_view);
			fclose(stream);
		}

		return;
	}

	write_line_verbose("Unable to save camera");
}

void haloreach_debug_load_camera(int(__stdcall *player_mapping_get_local_player)(), s_observer_camera *(__fastcall *observer_try_and_get_camera)(signed int local_player))
{
	if (player_mapping_get_local_player != nullptr && observer_try_and_get_camera != nullptr)
	{
		int local_player = player_mapping_get_local_player();
		s_observer_camera *observer_camera = observer_try_and_get_camera(local_player);

		FILE *stream = fopen("camera.txt", "r");
		if (stream)
		{
			fscanf(stream, "%f %f %f\n", &observer_camera->position.i, &observer_camera->position.j, &observer_camera->position.k);
			fscanf(stream, "%f %f %f\n", &observer_camera->forward.i, &observer_camera->forward.j, &observer_camera->forward.k);
			fscanf(stream, "%f %f %f\n", &observer_camera->up.i, &observer_camera->up.j, &observer_camera->up.k);
			fscanf(stream, "%f\n", &observer_camera->field_of_view);
			fclose(stream);
		}

		return;
	}

	write_line_verbose("Unable to load camera");
}


// TODO: Add other build offsets
uintptr_t g_centered_crosshair_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1829FFEB8 + 0x7C);
	return ~uintptr_t();
}
int& g_centered_crosshair = reference_symbol<int>("g_centered_crosshair", g_centered_crosshair_offset);

// TODO: Add other build offsets
uintptr_t g_field_of_view_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1829FFEB8 + 0x80);
	return ~uintptr_t();
}
float& g_field_of_view = reference_symbol<float>("g_field_of_view", g_field_of_view_offset);

c_haloreach_camera_command::c_haloreach_camera_command() :
	g_player_mapping_get_local_player(nullptr),
	g_observer_try_and_get_camera(nullptr)
{
	c_console::register_command(k_haloreach_camera_command_name, this);
}

c_haloreach_camera_command::~c_haloreach_camera_command()
{
	c_console::unregister_command(k_haloreach_camera_command_name);
}

bool c_haloreach_camera_command::execute_command(const std::vector<std::string> &arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_haloreach_camera_command_name))
	{
		if (arguments.size() == 2)
		{
			const std::string &arg1 = arguments[1];

			c_console::set_text_color(_console_color_info);
			if (!arg1.compare("save"))
			{
				write_line_verbose("camera save is not currently implemented");
				//haloreach_debug_save_camera(g_player_mapping_get_local_player, g_observer_try_and_get_camera);
			}
			if (!arg1.compare("load"))
			{
				write_line_verbose("camera load is not currently implemented");
				//haloreach_debug_save_camera(g_player_mapping_get_local_player, g_observer_try_and_get_camera);
			}
		}
		else if (arguments.size() == 3)
		{
			const std::string &arg1 = arguments[1];
			const std::string &arg2 = arguments[2];

			if (is_valid(g_field_of_view) && (!arg1.compare("fov") || !arg1.compare("field_of_view")))
			{
				float field_of_view = std::stof(arg2);
				if (field_of_view < 55.f) field_of_view = 55.f;
				if (field_of_view > 120.f) field_of_view = 120.f;

				g_field_of_view = field_of_view;
				c_settings_legacy::write_integer(_settings_section_legacy_camera, "FieldOfView", static_cast<int>(field_of_view));
			}
			if (is_valid(g_centered_crosshair) && !arg1.compare("crosshair"))
			{
				int centered_crosshair = std::stoi(arg2);
				if (centered_crosshair < 0) centered_crosshair = 0;
				if (centered_crosshair > 1) centered_crosshair = 1;

				g_centered_crosshair = centered_crosshair;
				c_settings_legacy::write_boolean(_settings_section_legacy_camera, "CenteredCrosshair", static_cast<bool>(centered_crosshair));
			}
		}
		else return false;
	}
	return true;
}

std::string c_haloreach_camera_command::get_command_info(const std::string &topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_haloreach_camera_command_name))
		{
			return
				"Various camera stuff\n"
				"Usage: camera <command>";
		}
	}
	return "";
}

std::string c_haloreach_camera_command::get_command_auto_complete(const std::vector<std::string> &Arguments) const
{
	return ""; // todo;
}

void c_haloreach_camera_command::read_config()
{
	std::string field_of_view = std::to_string(c_settings_legacy::read_float(_settings_section_legacy_camera, "FieldOfView", 90.f));
	execute_command({ "camera", "field_of_view", field_of_view.c_str() });

	std::string crosshair = std::to_string(c_settings_legacy::read_boolean(_settings_section_legacy_camera, "CenteredCrosshair", true));
	execute_command({ "camera", "crosshair", crosshair.c_str() });
}

void c_haloreach_camera_command::set_player_mapping_get_local_player(int(__stdcall *player_mapping_get_local_player)())
{
	g_player_mapping_get_local_player = player_mapping_get_local_player;
	return;
}

void c_haloreach_camera_command::set_observer_try_and_get_camera(s_observer_camera *(__fastcall *observer_try_and_get_camera)(signed int local_player))
{
	g_observer_try_and_get_camera = observer_try_and_get_camera;
	return;
}

/* ---------- private code */

