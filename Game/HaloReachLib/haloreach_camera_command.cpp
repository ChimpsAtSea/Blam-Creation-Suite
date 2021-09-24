#include <haloreachlib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

extern uintptr_t haloreach_player_mapping_get_local_player_offset(s_engine_platform_build engine_platform_build);
extern c_function_hook_ex<haloreach_player_mapping_get_local_player_offset, int __stdcall ()> haloreach_player_mapping_get_local_player;

extern uintptr_t haloreach_observer_try_and_get_camera_offset(s_engine_platform_build engine_platform_build);
extern c_function_hook_ex<haloreach_observer_try_and_get_camera_offset, s_observer_camera* __fastcall (signed int a1)> haloreach_observer_try_and_get_camera;

void haloreach_debug_save_camera()
{
	if (!haloreach_player_mapping_get_local_player.is_hooked) return;
	if (!haloreach_observer_try_and_get_camera.is_hooked) return;

	int local_player = haloreach_player_mapping_get_local_player();
	s_observer_camera* observer_camera = haloreach_observer_try_and_get_camera(local_player);

	FILE* stream = fopen("camera.txt", "w");
	if (stream)
	{
		fprintf(stream, "%f %f %f\n", observer_camera->position.i, observer_camera->position.j, observer_camera->position.k);
		fprintf(stream, "%f %f %f\n", observer_camera->forward.i, observer_camera->forward.j, observer_camera->forward.k);
		fprintf(stream, "%f %f %f\n", observer_camera->up.i, observer_camera->up.j, observer_camera->up.k);
		fprintf(stream, "%f\n", observer_camera->field_of_view);
		fclose(stream);
	}

	console_write_line("Unable to save camera");
}

void haloreach_debug_load_camera()
{
	if (!haloreach_player_mapping_get_local_player.is_hooked) return;
	if (!haloreach_observer_try_and_get_camera.is_hooked) return;


	int local_player = haloreach_player_mapping_get_local_player();
	s_observer_camera* observer_camera = haloreach_observer_try_and_get_camera(local_player);

	FILE* stream = fopen("camera.txt", "r");
	if (stream)
	{
		fscanf(stream, "%f %f %f\n", &observer_camera->position.i, &observer_camera->position.j, &observer_camera->position.k);
		fscanf(stream, "%f %f %f\n", &observer_camera->forward.i, &observer_camera->forward.j, &observer_camera->forward.k);
		fscanf(stream, "%f %f %f\n", &observer_camera->up.i, &observer_camera->up.j, &observer_camera->up.k);
		fscanf(stream, "%f\n", &observer_camera->field_of_view);
		fclose(stream);
	}

	console_write_line("Unable to load camera");
}


// TODO: Add other build offsets
uintptr_t g_centered_crosshair_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1829FFEB8 + 0x7C);
	return ~uintptr_t();
}
int& g_centered_crosshair = reference_symbol<int>("g_centered_crosshair", g_centered_crosshair_offset);

// TODO: Add other build offsets
uintptr_t g_field_of_view_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1829FFEB8 + 0x80);
	return ~uintptr_t();
}
float& g_field_of_view = reference_symbol<float>("g_field_of_view", g_field_of_view_offset);

c_haloreach_camera_command::c_haloreach_camera_command()
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
				console_write_line("camera save is not currently implemented");
				//haloreach_debug_save_camera();
			}
			if (!arg1.compare("load"))
			{
				console_write_line("camera load is not currently implemented");
				//haloreach_debug_save_camera();
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
				c_settings::write_integer(_settings_section_camera, "FieldOfView", static_cast<int>(field_of_view));
			}
			if (is_valid(g_centered_crosshair) && !arg1.compare("crosshair"))
			{
				int centered_crosshair = std::stoi(arg2);
				if (centered_crosshair < 0) centered_crosshair = 0;
				if (centered_crosshair > 1) centered_crosshair = 1;

				g_centered_crosshair = centered_crosshair;
				c_settings::write_boolean(_settings_section_camera, "CenteredCrosshair", static_cast<bool>(centered_crosshair));
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
	std::string field_of_view = std::to_string(c_settings::read_float(_settings_section_camera, "FieldOfView", 90.f));
	execute_command({ "camera", "field_of_view", field_of_view.c_str() });

	std::string crosshair = std::to_string(c_settings::read_boolean(_settings_section_camera, "CenteredCrosshair", true));
	execute_command({ "camera", "crosshair", crosshair.c_str() });
}

/* ---------- private code */

