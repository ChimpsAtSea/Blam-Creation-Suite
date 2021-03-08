#include "mandrilllib-private-pch.h"

// #TODO: better linked list implementation

enum e_traverse_directory_bit
{
	_traverse_directory_recursive
};

struct s_traverse_directory_result
{
	c_fixed_wide_path filepath;
	c_fixed_wide_path relative_filepath;
};
using t_traverse_directory_callback = bool(void* userdata, const s_traverse_directory_result* result);

// #TODO: move this into filesystem util
BCS_RESULT BCSAPI traverse_directory(const wchar_t* directory, const wchar_t* search_criteria, c_flags<e_traverse_directory_bit> flags, void* userdata, t_traverse_directory_callback callback)
{
	BCS_VALIDATE_ARGUMENT(directory);
	if (search_criteria == nullptr) search_criteria = L"";
	BCS_VALIDATE_ARGUMENT(callback);

	c_fixed_wide_path directory_buffer = directory;
	PathRemoveBackslashW(directory_buffer);

	c_fixed_wide_path search_criteria_directory_buffer = search_criteria;
	PathRemoveFileSpecW(search_criteria_directory_buffer);

	c_fixed_wide_path result_directory;
	if (search_criteria_directory_buffer.empty()) result_directory = directory_buffer;
	else result_directory.format(L"%s\\%s", directory_buffer.c_str(), search_criteria_directory_buffer.c_str());

	c_fixed_wide_path search_buffer;
	search_buffer.format(L"%s\\%s", directory_buffer.c_str(), search_criteria);

	WIN32_FIND_DATAW find_data;
	HANDLE find_file_handle = FindFirstFileExW(search_buffer, FindExInfoBasic, &find_data, FindExSearchNameMatch, NULL, 0);

	if (find_file_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			s_traverse_directory_result traverse_directory_result;
			traverse_directory_result.filepath.format(L"%s\\%s", result_directory.c_str(), find_data.cFileName);
			traverse_directory_result.relative_filepath.format(L"%s\\%s", search_criteria_directory_buffer.c_str(), find_data.cFileName);

			bool continue_search = callback(userdata, &traverse_directory_result);
			if (!continue_search)
			{
				break;
			}

		} while (FindNextFile(find_file_handle, &find_data));
	}

	FindClose(find_file_handle);

	return BCS_S_OK;
}

c_tag_project_configurator_tab::c_tag_project_configurator_tab(const wchar_t* directory, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Project Configuration", "Tag Project Configuration", &parent, false),
	step(),
	directory(directory),
	is_all_selected(true),
	entries(),
	cache_cluster(),
	cache_cluster_transplant()
{
	using namespace std::placeholders;

	traverse_directory(
		directory,
		L"maps\\*.map",
		0,
		this,
		[](void* userdata, const s_traverse_directory_result* result)
		{
			return static_cast<c_tag_project_configurator_tab*>(userdata)->process_directory(result);
		});

	for (s_cache_file_list_entry& entry : entries)
	{
		is_all_selected &= entry.selected;
	}
}

c_tag_project_configurator_tab::~c_tag_project_configurator_tab()
{

}

bool c_tag_project_configurator_tab::process_directory(const s_traverse_directory_result* result)
{
	s_cache_file_list_entry entry = {};
	entry.filepath = result->relative_filepath;
	entry.selected = true; // #TODO: read the build string from any existing shared.map or campaign.map file and then auto select

	if (BCS_FAILED(get_cache_file_reader_engine_and_platform(result->filepath, &entry.engine_platform_build)))
	{
		return true;
	}

	if (BCS_FAILED(open_cache_file_reader(result->filepath, entry.engine_platform_build, true, true, &entry.cache_reader)))
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
		render_cache_file_selection();
		break;
	case _tag_project_configurator_step_project_settings:
		previous_step = _tag_project_configurator_step_cache_file_selection;
		next_step = _tag_project_configurator_step_display_tags;
		render_project_settings();
		break;
	case _tag_project_configurator_step_display_tags:
		previous_step = _tag_project_configurator_step_project_settings;
		next_step = _tag_project_configurator_step_display_tags;
		render_display_tags();
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

#ifdef _DEBUG
	bool auto_proceed = false;
	if (c_command_line::has_command_line_arg("-autoproject"))
	{
		if (step == _tag_project_configurator_step_cache_file_selection)
		{
			static bool run_once = auto_proceed = true;
		}
		else if (step == _tag_project_configurator_step_project_settings)
		{
			static bool run_once = auto_proceed = true;
		}
	}
#endif

	bool disable_next_step = next_step == step;
	if (disable_next_step)
	{
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
	}
	if (ImGui::Button("Next") DEBUG_ONLY(|| auto_proceed))
	{
		switch (step)
		{
		case _tag_project_configurator_step_cache_file_selection:
			create_cache_cluster();
			break;
		case _tag_project_configurator_step_project_settings:
			break;
		}
		step = next_step;
	}
	if (disable_next_step)
	{
		ImGui::PopItemFlag();
	}
}

void c_tag_project_configurator_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{

}

void c_tag_project_configurator_tab::render_file_dialogue_gui_impl()
{

}

void c_tag_project_configurator_tab::render_game_layer_impl()
{

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
			get_engine_type_pretty_string(entry.engine_platform_build.engine_type, &engine_pretty_string);

			const char* platform_pretty_string = "Unknown Platform";
			get_platform_type_pretty_string(entry.engine_platform_build.platform_type, &platform_pretty_string);

			ImGui::Text("%s | %s", engine_pretty_string, platform_pretty_string);
			ImGui::NextColumn();
		}
		{
			ImGui::TextUnformatted(entry.build_info.build.get_string());
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
	for (h_tag* tag : cache_cluster_transplant->instances)
	{
		ImGui::TextUnformatted(tag->tag_filename);
	}
}

void c_tag_project_configurator_tab::create_cache_cluster()
{
	DEBUG_ASSERT(cache_cluster == nullptr);

	uint32_t cache_file_reader_count = static_cast<uint32_t>(entries.size());
	if (cache_file_reader_count > 0)
	{
		c_cache_file_reader** cache_file_readers = new(alloca(sizeof(c_cache_file_reader*) * cache_file_reader_count)) c_cache_file_reader * [cache_file_reader_count];

		for (size_t entry_index = 0; entry_index < entries.size(); entry_index++)
		{
			s_cache_file_list_entry& entry = entries[entry_index];

			cache_file_readers[entry_index] = entry.cache_reader;
		}

		s_engine_platform_build engine_platform_build = entries[0].engine_platform_build; // #TODO: seems kinda hacky

		BCS_RESULT create_cache_cluster_result = ::create_cache_cluster(cache_file_readers, cache_file_reader_count, engine_platform_build, &cache_cluster);
		ASSERT(BCS_SUCCEEDED(create_cache_cluster_result));

		cache_cluster_transplant = new c_high_level_cache_cluster_transplant(*static_cast<c_halo4_cache_cluster*>(cache_cluster));

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
