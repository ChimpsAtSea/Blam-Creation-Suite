#include "mandrillui-private-pch.h"

c_tag_project_configurator_tab::c_tag_project_configurator_tab(const wchar_t* directory, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Project Configuration", "Tag Project Configuration", &parent, false),
	step(),
	directory(directory),
	is_all_selected(true),
	is_monolithic_tag_file_directory(false),
	is_single_tag_file_directory(false),
	is_haloce_directory(false),
	is_cache_file_directory(false),
	entries(),
	selected_entries(),
	cache_cluster(),
	cache_cluster_transplant(),
	runtime_task(nullptr),
	tag_project(nullptr)
{
	using namespace std::placeholders;

	c_fixed_wide_path tags_directory = directory;
	tags_directory += L"tags\\";

	c_fixed_wide_path tag_cache_directory = directory;
	tag_cache_directory += L"tag_cache\\";

	c_fixed_wide_path guerilla_filepath = directory;
	guerilla_filepath += L"guerilla.exe";

	c_fixed_wide_path haloce_filepath = directory;
	haloce_filepath += L"halo_tag_test.exe";

	c_fixed_wide_path deploy_directory = directory;
	deploy_directory += L"deploy\\";

	if (BCS_SUCCEEDED(filesystem_directory_exists(tag_cache_directory)))
	{
		is_monolithic_tag_file_directory = true;
		debug_point;

		s_cache_file_list_entry entry = {};
		entry.filepath = tag_cache_directory;
		entry.selected = true;
		entries.push_back(entry);
	}
	else if (BCS_SUCCEEDED(filesystem_directory_exists(tags_directory)) && BCS_SUCCEEDED(filesystem_filepath_exists(guerilla_filepath)))
	{
		if (BCS_SUCCEEDED(filesystem_filepath_exists(haloce_filepath)))
		{
			is_haloce_directory = true;
		}
		is_single_tag_file_directory = true;
		debug_point;
	}
	else if (BCS_SUCCEEDED(filesystem_directory_exists(deploy_directory)))
	{
		filesystem_traverse_directory_folders(
			deploy_directory,
			[](void* userdata_pointer, const wchar_t* directory, const wchar_t* relative_directory)
			{
				struct s_traverse_directory_userdata
				{
					c_tag_project_configurator_tab& configurator_tab;
					const wchar_t* directory;
					const wchar_t* relative_directory;
				};
				s_traverse_directory_userdata userdata = { *static_cast<c_tag_project_configurator_tab*>(userdata_pointer), directory, relative_directory };
				filesystem_traverse_directory_files(
					directory,
					L"*-rtx-new.module",
					[](void* userdata_pointer, const wchar_t* path, const wchar_t* relative_path)
					{
						s_traverse_directory_userdata& userdata = *static_cast<s_traverse_directory_userdata*>(userdata_pointer);

						c_fixed_wide_path relative_path_buffer;
						relative_path_buffer.format(L"%s%s", userdata.relative_directory + 1, relative_path + 1);

						return userdata.configurator_tab.process_directory(path, relative_path_buffer);
					},
					&userdata);
				return true;
			},
			this);
		is_cache_file_directory = true;
		debug_point;
	}
	else
	{
		filesystem_traverse_directory_files(
			directory,
			L"maps\\*.map",
			[](void* userdata, const wchar_t* path, const wchar_t* relative_path)
			{
				return static_cast<c_tag_project_configurator_tab*>(userdata)->process_directory(path, relative_path);
			},
			this);
		is_cache_file_directory = true;
	}

	const wchar_t* modules[128] = {};
	unsigned long num_modules = _countof(modules);
	if (BCS_SUCCEEDED(command_line_get_arguments(L"autoproject-module", modules, num_modules)) && num_modules > 0)
	{
		for (s_cache_file_list_entry& entry : entries)
		{
			entry.selected = false;
			for (unsigned long module_index = 0; module_index < num_modules; module_index++)
			{
				const wchar_t* module_name = modules[module_index];

				if (wcscmp(entry.filepath, module_name) == 0)
				{
					entry.selected = true;
					break;
				}
			}
		}
	}

	for (s_cache_file_list_entry& entry : entries)
	{
		is_all_selected &= entry.selected;
	}
}

c_tag_project_configurator_tab::~c_tag_project_configurator_tab()
{

}

bool c_tag_project_configurator_tab::process_directory(const wchar_t* file_path, const wchar_t* relative_file_path)
{
	s_cache_file_list_entry entry = {};
	entry.filepath = relative_file_path;
	entry.selected = true; // #TODO: read the build string from any existing shared.map or campaign.map file and then auto select

	if (BCS_FAILED(get_cache_file_reader_engine_and_platform(file_path, &entry.engine_platform_build)))
	{
		return true;
	}

	if (BCS_FAILED(open_cache_file_reader(file_path, entry.engine_platform_build, true, true, &entry.cache_reader)))
	{
		return true;
	}

	if (BCS_FAILED(get_cache_file_reader_build_info(entry.cache_reader, &entry.build_info)))
	{
		return true;
	}

	entries.push_back(entry);

	return true;
}

void c_tag_project_configurator_tab::render_impl()
{
	ImGui::TextUnformatted("Tag Project Configuration");
	ImGui::Text("%S", directory.c_str());

	e_tag_project_configurator_step previous_step = _tag_project_configurator_step_cache_file_selection;
	e_tag_project_configurator_step next_step = _tag_project_configurator_step_cache_file_selection;
	switch (step)
	{
	case _tag_project_configurator_step_cache_file_selection:
		previous_step = _tag_project_configurator_step_cache_file_selection;
		next_step = _tag_project_configurator_step_project_settings;
		break;
	case _tag_project_configurator_step_project_settings:
		previous_step = _tag_project_configurator_step_cache_file_selection;
		next_step = _tag_project_configurator_step_display_tags;
		break;
	case _tag_project_configurator_step_display_tags:
		previous_step = _tag_project_configurator_step_project_settings;
		next_step = _tag_project_configurator_step_display_project_setup;
		break;
	case _tag_project_configurator_step_display_project_setup:
		previous_step = _tag_project_configurator_step_display_tags;
		next_step = _tag_project_configurator_step_project_creation;
		break;
	case _tag_project_configurator_step_project_creation:
		previous_step = _tag_project_configurator_step_display_project_setup;
		next_step = _tag_project_configurator_step_project_finished;
		break;
	case _tag_project_configurator_step_project_finished:
		previous_step = _tag_project_configurator_step_display_project_setup;
		next_step = _tag_project_configurator_step_project_finished;
		break;
	}

	bool disable_previous_step = previous_step == step;
	if (disable_previous_step)
	{
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
	}
	if (ImGui::Button("Back"))
	{
		step = previous_step;
		switch (step)
		{
		case _tag_project_configurator_step_cache_file_selection:
			destroy_cache_cluster();
			break;
		case _tag_project_configurator_step_project_settings:
			break;
		}
	}
	if (disable_previous_step)
	{
		ImGui::PopItemFlag();
	}

	ImGui::SameLine();

	bool auto_proceed = false;
	if (BCS_SUCCEEDED(command_line_has_argument("autoprojectinit")))
	{
#define AUTO_PROJECT_INIT_STEP(_step) else if (step == _step) { static bool run_once = auto_proceed = true; }
		if (false) {}
		AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_cache_file_selection)
			AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_project_settings)
			AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_display_tags)
			//AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_display_project_setup)
			AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_project_creation)
			AUTO_PROJECT_INIT_STEP(_tag_project_configurator_step_project_finished)
#undef AUTO_PROJECT_INIT_STEP
	}

	bool disable_next_step = next_step == step;
	if (disable_next_step)
	{
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
	}
	if (ImGui::Button("Next") || auto_proceed)
	{
		switch (step)
		{
		case _tag_project_configurator_step_cache_file_selection:
			create_cache_cluster();
			break;
		case _tag_project_configurator_step_project_settings:
			break;
		case _tag_project_configurator_step_display_tags:
			init_tag_project();
			break;
		case _tag_project_configurator_step_display_project_setup:
			break;
		case _tag_project_configurator_step_project_creation:
			create_tag_project_tab();
			break;
		case _tag_project_configurator_step_project_finished:
			// #TODO: destroy this
			break;
		}
		step = next_step;
	}
	if (disable_next_step)
	{
		ImGui::PopItemFlag();
	}

	switch (step)
	{
	case _tag_project_configurator_step_cache_file_selection:
		render_cache_file_selection();
		break;
	case _tag_project_configurator_step_project_settings:
		render_project_settings();
		break;
	case _tag_project_configurator_step_display_tags:
		render_display_tags();
		break;
	case _tag_project_configurator_step_display_project_setup:
		render_tag_project_status();
		break;
	case _tag_project_configurator_step_project_creation:
		break;
	case _tag_project_configurator_step_project_finished:
		ImGui::TextUnformatted("Finished");
		break;
	}
}

bool c_tag_project_configurator_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	return true;
}

void c_tag_project_configurator_tab::render_cache_file_selection()
{

	ImGui::Columns(4, "cache file list", false);
	ImGui::SetColumnWidth(0, 50);

	{
		ImGui::PushID("header");
		ImGui::Separator();
		{
			if (ImGui::Checkbox("", &is_all_selected))
			{
				for (s_cache_file_list_entry& entry : entries)
				{
					entry.selected = is_all_selected;
				}
			}
			ImGui::NextColumn();
		}
		{
			ImGui::TextUnformatted("Path");
			ImGui::NextColumn();
		}
		{
			ImGui::TextUnformatted("Engine");
			ImGui::NextColumn();
		}
		{
			ImGui::TextUnformatted("Build");
			ImGui::NextColumn();
		}
		ImGui::PopID();
	}

	for (s_cache_file_list_entry& entry : entries)
	{
		ImGui::PushID(entry.filepath);
		ImGui::Separator();
		{
			if (ImGui::Checkbox("", &entry.selected))
			{
				is_all_selected = true;
				for (s_cache_file_list_entry& entry : entries)
				{
					is_all_selected &= entry.selected;
				}
			}
			ImGui::NextColumn();
		}
		{
			ImGui::Text("%S", entry.filepath.c_str());
			ImGui::NextColumn();
		}
		{
			const char* engine_pretty_string = "Unknown Engine";
			get_engine_type_pretty_string(entry.engine_platform_build.engine_type, engine_pretty_string);

			const char* platform_pretty_string = "Unknown Platform";
			get_platform_type_pretty_string(entry.engine_platform_build.platform_type, platform_pretty_string);

			ImGui::Text("%s | %s", engine_pretty_string, platform_pretty_string);
			ImGui::NextColumn();
		}
		{
			ImGui::TextUnformatted(entry.build_info.build_version.get_string());
			if (entry.build_info.xdk_version)
			{
				ImGui::SameLine();
				ImGui::Text("| xdk:%u", entry.build_info.xdk_version);
			}
			ImGui::NextColumn();
		}
		ImGui::PopID();
	}
	ImGui::Separator();
	ImGui::Columns(1);
}

void c_tag_project_configurator_tab::render_project_settings()
{

}

void c_tag_project_configurator_tab::render_display_tags()
{
	if (cache_cluster_transplant)
		for (s_tag_transplant_instance& transplant_instance : cache_cluster_transplant->instances)
		{
			h_tag* tag = transplant_instance.high_level;
			ImGui::Text("%s.%s", tag->get_file_path(), tag->group->tag_group.name);
		}
}

void c_tag_project_configurator_tab::create_cache_cluster()
{
	if (!is_cache_file_directory)
	{
		return;
	}

	DEBUG_ASSERT(cache_cluster == nullptr);

	selected_entries.clear();
	for (s_cache_file_list_entry& entry : entries)
	{
		if (entry.selected)
		{
			selected_entries.push_back(entry);
		}
	}

	unsigned long cache_file_reader_count = static_cast<unsigned long>(selected_entries.size());
	if (cache_file_reader_count > 0)
	{
		c_cache_file_reader** cache_file_readers = new(alloca(sizeof(c_cache_file_reader*) * cache_file_reader_count)) c_cache_file_reader * [cache_file_reader_count];

		for (size_t entry_index = 0; entry_index < selected_entries.size(); entry_index++)
		{
			s_cache_file_list_entry& entry = selected_entries[entry_index];

			cache_file_readers[entry_index] = entry.cache_reader;
		}

		s_engine_platform_build engine_platform_build = selected_entries[0].engine_platform_build; // #TODO: seems kinda hacky

		BCS_RESULT create_cache_cluster_result = ::create_cache_cluster(cache_file_readers, cache_file_reader_count, engine_platform_build, &cache_cluster);
		ASSERT(BCS_SUCCEEDED(create_cache_cluster_result));

		cache_cluster_transplant = nullptr;

		//if (c_halo4_cache_cluster* halo4_cache_cluster = dynamic_cast<c_halo4_cache_cluster*>(cache_cluster))
		{
			cache_cluster_transplant = new() c_high_level_cache_cluster_transplant(*cache_cluster);
		}

		debug_point;
	}

	debug_point;
}

void c_tag_project_configurator_tab::destroy_cache_cluster()
{
	if (cache_cluster != nullptr)
	{
		BCS_RESULT create_cache_cluster_result = ::destroy_cache_cluster(cache_cluster);
		ASSERT(BCS_SUCCEEDED(create_cache_cluster_result));

		cache_cluster = nullptr;
	}
	if (cache_cluster_transplant != nullptr)
	{
		delete cache_cluster_transplant;
	}
}

c_tag_project_configurator_tab::c_tag_project_configurator_tab_task::c_tag_project_configurator_tab_task(c_tag_project_configurator_tab& project_configurator_tab) :
	c_runtime_task(),
	project_configurator_tab(project_configurator_tab),
	task_group(),
	stopwatch(),
	running(true)
{
	BCS_FAIL_THROW(task_group_create(task_group));

	task_group_run(
		task_group,
		[](void* userdata)
		{
			ASSERT(userdata != nullptr);
			c_tag_project_configurator_tab_task& task = *static_cast<c_tag_project_configurator_tab_task*>(userdata);
			task.stopwatch.start();
			task.project_configurator_tab.create_tag_project();
			task.running = false;
			task.stopwatch.stop();
		},
		this);
}

c_tag_project_configurator_tab::c_tag_project_configurator_tab_task::~c_tag_project_configurator_tab_task()
{
	BCS_FAIL_THROW(task_group_wait(task_group));
	BCS_FAIL_THROW(task_group_destroy(task_group));
}

bool c_tag_project_configurator_tab::c_tag_project_configurator_tab_task::is_running() const
{
	return running;
}

float c_tag_project_configurator_tab::c_tag_project_configurator_tab_task::get_runtime_duration() const
{
	return stopwatch.get_seconds();
}

void c_tag_project_configurator_tab::init_tag_project()
{
	runtime_task = new c_tag_project_configurator_tab_task(*this);
}

void c_tag_project_configurator_tab::render_tag_project_status()
{
	if (c_mandrill_user_interface* mandrill_user_interface = search_parent_tab_type<c_mandrill_user_interface>())
	{
		if (runtime_task == nullptr)
		{
			ImGui::Text("No Task");
		}
		else if (runtime_task->is_running())
		{
			ImGui::Text("Running");
		}
		else
		{
			ImGui::Text("Finished %f", runtime_task->get_runtime_duration());
			step = _tag_project_configurator_step_project_creation;
		}
		debug_point;
	}
}

void c_tag_project_configurator_tab::create_tag_project()
{
	if (c_mandrill_user_interface* mandrill_user_interface = search_parent_tab_type<c_mandrill_user_interface>())
	{
		if (cache_cluster_transplant)
		{
			tag_project = new() c_cache_file_tag_project(*cache_cluster_transplant, mandrill_user_interface);
		}
		if (is_single_tag_file_directory)
		{
			if (is_haloce_directory) // #TODO: hack, fix
			{
				tag_project = new() c_filesystem_tag_project(directory, { _engine_type_halo1, _platform_type_pc_64bit }, mandrill_user_interface);
			}
			else
			{
				tag_project = new() c_filesystem_tag_project(directory, { _engine_type_halo3, _platform_type_pc_64bit }, mandrill_user_interface);
			}
		}
		if (is_monolithic_tag_file_directory)
		{
			tag_project = new() c_monolithic_tag_project(directory, { _engine_type_haloreach }, mandrill_user_interface);
		}
	}
}

void c_tag_project_configurator_tab::create_tag_project_tab()
{
	ASSERT(!runtime_task->is_running());
	if (c_mandrill_user_interface* mandrill_user_interface = search_parent_tab_type<c_mandrill_user_interface>())
	{
		c_tag_project_tab* tag_project_tab = new() c_tag_project_tab(L"", *tag_project, *mandrill_user_interface);
		mandrill_user_interface->add_tab(*tag_project_tab);
		mandrill_user_interface->set_next_selected_tab(*tag_project_tab);
		tag_project = nullptr; // hand off the memory to the child tab
		// #TODO: Is it worth implementing a reference counting system?
		delete runtime_task; // cleaup task
		runtime_task = nullptr;
	}
}
