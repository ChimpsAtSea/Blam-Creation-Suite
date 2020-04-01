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
			fprintf(stream, "%f %f %f\n", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
			fprintf(stream, "%f %f %f\n", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
			fprintf(stream, "%f %f %f\n", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
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
			fscanf(stream, "%f %f %f\n", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
			fscanf(stream, "%f %f %f\n", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
			fscanf(stream, "%f %f %f\n", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
			fscanf(stream, "%f\n", observer_camera->field_of_view);
			fclose(stream);
		}

		return;
	}

	write_line_verbose("Unable to load camera");
}

c_haloreach_camera_command::c_haloreach_camera_command() :
	g_player_mapping_get_local_player(nullptr)
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
		if (arguments.size() >= 2)
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

