#include "gameframework-private-pch.h"

#ifdef _WIN64

std::string format_string(const char* pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);
	char stringBuffer[64 * 1024] = {};
	vsnprintf(stringBuffer, _countof(stringBuffer) - 1, pFormat, args);
	va_end(args);
	return stringBuffer;
}

static constexpr const char k_last_game_mode_setting[] = "game_mode";
static constexpr const char k_last_difficulty_mode_setting[] = "difficulty";

static constexpr const char k_last_unknown_map_id_setting[] = "unknown_map_id";
static constexpr const char k_last_campaign_map_id_setting[] = "campaign_map_id";
static constexpr const char k_last_spartan_ops_map_id_setting[] = "spartan_ops_map_id";
static constexpr const char k_last_multiplayer_map_id_setting[] = "multiplayer_map_id";
static constexpr const char k_last_firefight_map_id_setting[] = "firefight_map_id";

static constexpr const char k_last_campaign_game_variant_setting[] = "campaign_game_variant"; // #TODO: are these a thing?
static constexpr const char k_last_spartan_ops_game_variant_setting[] = "spartan_ops_game_variant";
static constexpr const char k_last_multiplayer_game_variant_setting[] = "multiplayer_game_variant";
static constexpr const char k_last_firefight_game_variant_setting[] = "firefight_game_variant";

static constexpr const char k_last_campaign_map_variant_setting[] = "campaign_game_variant"; // #TODO: are these a thing?
static constexpr const char k_last_spartan_ops_map_variant_setting[] = "spartan_ops_map_variant";
static constexpr const char k_last_multiplayer_map_variant_setting[] = "multiplayer_map_variant";
static constexpr const char k_last_firefight_map_variant_setting[] = "firefight_map_variant";

e_mcc_game_mode current_game_mode = _mcc_game_mode_campaign;

c_fixed_string_128 c_haloreach_game_option_selection_legacy::hopper_game_variant[k_number_of_mcc_game_modes] = {};
c_fixed_string_128 c_haloreach_game_option_selection_legacy::hopper_map_variant[k_number_of_mcc_game_modes] = {};
const c_map_info* c_haloreach_game_option_selection_legacy::selected_map_infos[k_number_of_mcc_game_modes] = {};

extern e_campaign_difficulty_level difficulty_level; // #TODO #REFACTOR



c_map_info_manager* c_haloreach_game_option_selection_legacy::g_map_info_manager = nullptr;

//GameTypeManager* c_haloreach_game_option_selection_legacy::g_game_type_manager = nullptr;
//const GameType* c_haloreach_game_option_selection_legacy::selected_game_type[underlying_cast(k_number_of_selected_game_mode_map_info_indices)] = {};

std::string c_haloreach_game_option_selection_legacy::s_launch_saved_film_filepath = "";

void c_haloreach_game_option_selection_legacy::Init()
{
	// #TODO: Support more games than just Halo Reach
	g_map_info_manager = new c_map_info_manager("haloreach/maps/info");

	load_settings();
}

void c_haloreach_game_option_selection_legacy::deinit()
{
	delete g_map_info_manager;
}

void c_haloreach_game_option_selection_legacy::load_settings()
{
	c_fixed_string_128 last_game_mode;
	c_settings::read_string(_settings_section_launch, k_last_game_mode_setting, last_game_mode.str(), sizeof(last_game_mode), "");
	current_game_mode = string_to_mcc_game_mode(last_game_mode.c_str());
	if (current_game_mode == _mcc_game_mode_none)
	{
		current_game_mode = _mcc_game_mode_campaign;
	}

	c_fixed_string_128 difficulty_mode_str;
	c_settings::read_string(_settings_section_launch, k_last_difficulty_mode_setting, difficulty_mode_str.str(), sizeof(difficulty_mode_str), "normal");
	difficulty_level = string_to_campaign_difficulty_level(difficulty_mode_str.c_str());

	for (uint32_t game_mode_index = 0; game_mode_index < k_number_of_mcc_game_modes; game_mode_index++)
	{
		e_mcc_game_mode game_mode = static_cast<e_mcc_game_mode>(game_mode_index);

		load_map_id_setting(game_mode);
		load_map_variant_setting(game_mode);
		load_game_variant_setting(game_mode);
	}
}


void c_haloreach_game_option_selection_legacy::load_map_id_setting(e_mcc_game_mode game_mode)
{
	int map_id = -1;
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		map_id = c_settings::read_integer(_settings_section_launch, k_last_campaign_map_id_setting, -1);
		break;
	case _mcc_game_mode_multiplayer:
		map_id = c_settings::read_integer(_settings_section_launch, k_last_multiplayer_map_id_setting, -1);
		break;
	case _mcc_game_mode_firefight:
		map_id = c_settings::read_integer(_settings_section_launch, k_last_firefight_map_id_setting, -1);
		break;
	case _mcc_game_mode_spartan_ops:
		map_id = c_settings::read_integer(_settings_section_launch, k_last_spartan_ops_map_id_setting, -1);
		break;
	default:
		map_id = c_settings::read_integer(_settings_section_launch, k_last_unknown_map_id_setting, -1);
		break;
	}

	selected_map_infos[game_mode] = nullptr;
	for (const c_map_info& map_info : g_map_info_manager->map_infos)
	{
		if (map_info.get_map_id() == map_id)
		{
			selected_map_infos[game_mode] = &map_info;
		}
	}
}

void c_haloreach_game_option_selection_legacy::load_map_variant_setting(e_mcc_game_mode game_mode)
{
	switch (game_mode)
	{
	case _mcc_game_mode_multiplayer:
	{
		c_settings::read_string(_settings_section_launch, k_last_multiplayer_map_variant_setting, hopper_map_variant[game_mode].data, sizeof(hopper_game_variant), "");
		break;
	}
	}
}

void c_haloreach_game_option_selection_legacy::load_game_variant_setting(e_mcc_game_mode game_mode)
{
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
	{
		hopper_game_variant[game_mode] = "campaign_default_054";
		break;
		// #TODO: is this a thing?
		c_settings::read_string(_settings_section_launch, k_last_campaign_game_variant_setting, hopper_game_variant[game_mode].data, sizeof(hopper_game_variant), "campaign_default_054");
		break;
	}
	case _mcc_game_mode_multiplayer:
	{
		c_settings::read_string(_settings_section_launch, k_last_multiplayer_game_variant_setting, hopper_game_variant[game_mode].data, sizeof(hopper_game_variant), "slayer_054");
		break;
	}
	case _mcc_game_mode_firefight:
	{
		c_settings::read_string(_settings_section_launch, k_last_firefight_game_variant_setting, hopper_game_variant[game_mode].data, sizeof(hopper_game_variant), "ff_firefight_054");
		break;
	}
	//case _mcc_game_mode_spartan_ops:
	//{
	//	c_settings::read_string(_settings_section_launch, k_last_spartan_ops_game_variant_setting, hopper_game_variant[game_mode].data, sizeof(hopper_game_variant), TODO);
	//	break;
	//}
	}
}

void c_haloreach_game_option_selection_legacy::save_selected_map_id_setting(e_mcc_game_mode game_mode)
{
	const c_map_info*& map_info = selected_map_infos[current_game_mode];
	int map_id = map_info ? map_info->get_map_id() : -1;
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		c_settings::write_integer(_settings_section_launch, k_last_campaign_map_id_setting, map_id);
		break;
	case _mcc_game_mode_multiplayer:
		c_settings::write_integer(_settings_section_launch, k_last_multiplayer_map_id_setting, map_id);
		break;
	case _mcc_game_mode_firefight:
		c_settings::write_integer(_settings_section_launch, k_last_firefight_map_id_setting, map_id);
		break;
	case _mcc_game_mode_spartan_ops:
		c_settings::write_integer(_settings_section_launch, k_last_spartan_ops_map_id_setting, map_id);
		break;
	default:
		c_settings::write_integer(_settings_section_launch, k_last_unknown_map_id_setting, map_id);
		break;
	}
}

void c_haloreach_game_option_selection_legacy::save_selected_map_variant_setting(e_mcc_game_mode game_mode)
{
	const char* map_variant = hopper_map_variant[game_mode].c_str();
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		c_settings::write_string(_settings_section_launch, k_last_campaign_map_variant_setting, map_variant);
		break;
	case _mcc_game_mode_multiplayer:
		c_settings::write_string(_settings_section_launch, k_last_multiplayer_map_variant_setting, map_variant);
		break;
	case _mcc_game_mode_firefight:
		c_settings::write_string(_settings_section_launch, k_last_firefight_map_variant_setting, map_variant);
		break;
	case _mcc_game_mode_spartan_ops:
		c_settings::write_string(_settings_section_launch, k_last_spartan_ops_map_variant_setting, map_variant);
		break;
	}
}

void c_haloreach_game_option_selection_legacy::save_selected_game_variant_setting(e_mcc_game_mode game_mode)
{
	const char* game_variant = hopper_game_variant[game_mode].c_str();
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		c_settings::write_string(_settings_section_launch, k_last_campaign_game_variant_setting, game_variant);
		break;
	case _mcc_game_mode_multiplayer:
		c_settings::write_string(_settings_section_launch, k_last_multiplayer_game_variant_setting, game_variant);
		break;
	case _mcc_game_mode_firefight:
		c_settings::write_string(_settings_section_launch, k_last_firefight_game_variant_setting, game_variant);
		break;
	case _mcc_game_mode_spartan_ops:
		c_settings::write_string(_settings_section_launch, k_last_spartan_ops_game_variant_setting, game_variant);
		break;
	}
}

e_mcc_game_mode c_haloreach_game_option_selection_legacy::get_selected_game_mode()
{
	return current_game_mode;
}

const c_map_info* c_haloreach_game_option_selection_legacy::get_selected_map_info()
{
	return selected_map_infos[current_game_mode];
}

void c_haloreach_game_option_selection_legacy::select_game_mode()
{
	bool show_all_modes = c_command_line::has_command_line_arg("-showallmodes");

	const char* current_game_mode_str = mcc_game_mode_to_local_string(current_game_mode);
	if (ImGui::BeginCombo("Game Mode", current_game_mode_str))
	{
		for (uint32_t game_mode_index = 0; game_mode_index < k_number_of_mcc_game_modes; game_mode_index++)
		{
			e_mcc_game_mode game_mode = static_cast<e_mcc_game_mode>(game_mode_index);

			if (!show_all_modes)
			{
				switch (game_mode)
				{
				case _mcc_game_mode_none:
				case _mcc_game_mode_ui_shell:
					break;
				}
			}

			const char* game_mode_str = mcc_game_mode_to_local_string(game_mode);
			if (game_mode_str)
			{
				bool selected = current_game_mode == game_mode;
				if (ImGui::Selectable(game_mode_str, &selected))
				{
					current_game_mode = game_mode;
					c_settings::write_string(_settings_section_launch, k_last_game_mode_setting, mcc_game_mode_to_string(current_game_mode));
				}
			}
		}
		ImGui::EndCombo();
	}
}

void c_haloreach_game_option_selection_legacy::Render()
{


	select_saved_film();

	//ImGui::Separator();

	//if (g_current_game_mode != game_mode::Multiplayer)
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 0.938f);
	//}
	//else
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 1.415f);
	//}
	select_game_mode();
	//ImGui::SameLine();
	select_map();

	//if (g_current_game_mode != game_mode::Multiplayer)
	//{
	//	ImGui::SameLine();
	//}
	select_difficulty();
	//ImGui::PopItemWidth();

	//ImGui::Separator();

	select_game_variant();
	select_map_variant();
}

const c_map_info* c_haloreach_game_option_selection_legacy::get_first_suitable_game_mode_map_info(e_mcc_game_mode game_mode)
{
	for (const c_map_info& rMapInfo : g_map_info_manager->map_infos)
	{
		if (is_map_info_compatible_with_game_mode(game_mode, rMapInfo))
		{
			return &rMapInfo;
		}
	}
	return nullptr;
}

bool c_haloreach_game_option_selection_legacy::is_map_info_compatible_with_game_mode(e_mcc_game_mode game_mode, const c_map_info& rMapInfo)
{
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		if (!rMapInfo.is_campaign()) return false;
		break;
	case _mcc_game_mode_multiplayer:
		if (!rMapInfo.is_multiplayer()) return false;
		break;
	case _mcc_game_mode_firefight:
		if (!rMapInfo.is_firefight()) return false;
		break;
	}
	return true;
}

void c_haloreach_game_option_selection_legacy::render_hovered_tooltip(const char* pText)
{
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::Text(pText);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void c_haloreach_game_option_selection_legacy::select_map()
{
	const c_map_info*& selected_map_info = selected_map_infos[current_game_mode];

	if (!selected_map_info || selected_map_info && !is_map_info_compatible_with_game_mode(current_game_mode, *selected_map_info))
	{
		selected_map_info = get_first_suitable_game_mode_map_info(current_game_mode);
		save_selected_map_id_setting(current_game_mode);
	}

	const char* selected_level_name = "<no level selected>";
	if (selected_map_info)
	{
		selected_level_name = selected_map_info->get_friendly_name();
	}

	if (ImGui::BeginCombo("Map", selected_level_name))
	{
		// #TODO: Make a nice and beautiful interface to this for multi-game
		for (const c_map_info& current_map_info : g_map_info_manager->map_infos)
		{
			if (!is_map_info_compatible_with_game_mode(current_game_mode, current_map_info))
			{
				continue;
			}

			bool selected = selected_map_info == &current_map_info;
			const char* current_level_friendly_name = current_map_info.get_friendly_name();

			if (ImGui::Selectable(current_level_friendly_name, &selected))
			{
				selected_map_info = &current_map_info;
				save_selected_map_id_setting(current_game_mode);
			}
			render_hovered_tooltip(current_map_info.get_friendly_description());
		}

		ImGui::EndCombo();
	}
}

void c_haloreach_game_option_selection_legacy::select_difficulty()
{
	if (current_game_mode == _mcc_game_mode_campaign || current_game_mode == _mcc_game_mode_firefight)
	{
		const char* pCurrentDifficultyStr = campaign_difficulty_level_to_local_string(difficulty_level);
		if (ImGui::BeginCombo("Difficulty", pCurrentDifficultyStr))
		{
			for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int&>(difficulty)++)
			{
				const char* pDifficultyStr = campaign_difficulty_level_to_local_string(difficulty);
				if (pDifficultyStr)
				{
					bool selected = pDifficultyStr == pCurrentDifficultyStr;
					if (ImGui::Selectable(pDifficultyStr, &selected))
					{
						difficulty_level = static_cast<e_campaign_difficulty_level>(difficulty);
						c_settings::write_string(_settings_section_launch, k_last_difficulty_mode_setting, campaign_difficulty_level_to_string(difficulty_level));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

void c_haloreach_game_option_selection_legacy::GetVariantInfo(char* buffer, std::string* name, std::string* desc)
{
	for (size_t i = 0; i < 256; i++)
	{
		char* nameCur = &buffer[0x80 + i];
		if (nameCur[0] && !nameCur[1])
		{
			*name += nameCur;
		}
		char* descCur = &buffer[0x180 + i];
		if (descCur[0] && !descCur[1])
		{
			*desc += descCur;
		}
	}
}

int c_haloreach_game_option_selection_legacy::read_game_variant(const char* pName, std::string* name, std::string* desc, const char* filesystem_path)
{
	static s_game_variant game_variant;
	IDataAccess* data_access = c_haloreach_game_host::get_data_access();
	ASSERT(data_access != nullptr);
	load_game_variant(data_access, "haloreach", pName, game_variant);

	int result = game_variant.game_engine_index;

	GetVariantInfo(game_variant.game_engine_variant.data, name, desc);

	if (!(*name).c_str()[0])
	{
		*name = pName;
	}

	return result;
}

int c_haloreach_game_option_selection_legacy::ReadMapVariant(const char* pName, std::string* name, std::string* desc, const char* pPath)
{
	static s_map_variant map_variant;
	IDataAccess* data_access = c_haloreach_game_host::get_data_access();
	ASSERT(data_access != nullptr);
	load_map_variant(data_access, "haloreach", pName, map_variant);

	int result = *reinterpret_cast<int*>(&map_variant.data[0x2C]);
	GetVariantInfo(map_variant.data, name, desc);

	return result;
}

int c_haloreach_game_option_selection_legacy::ReadSavedFilm(const char* pName, std::string* name, std::string* desc, const char* pPath)
{
	IDataAccess* data_access = c_haloreach_game_host::get_data_access();
	if (data_access)
	{
		char* saved_fildata = nullptr;
		size_t saved_fildata_size = 0;

		if (!filesystem_read_file_to_memory(pPath, reinterpret_cast<void**>(&saved_fildata), &saved_fildata_size))
		{
			c_console::write_line_verbose("Failed to open saved film file");
			return -1;
		}
		if (saved_fildata == 0)
		{
			c_console::write_line_verbose("Saved film was zero sized");
			return -1;
		}

		ISaveFilmMetadata* save_filmetadata = data_access->save_film_metadata_create_from_file(saved_fildata, saved_fildata_size);// ->data;

		{
			std::wstring wide(save_filmetadata->GetName());
			*name = std::string(wide.begin(), wide.end());
		}
		{
			std::wstring wide(save_filmetadata->GetDescription());
			*desc = std::string(wide.begin(), wide.end());
		}

		if (is_valid(saved_fildata))
		{
			delete[] saved_fildata;
		}
	}

	return -1;
}

void c_haloreach_game_option_selection_legacy::select_game_variant()
{
	if (current_game_mode == _mcc_game_mode_campaign)
	{
		return;
	}

	const char* engine_name = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> file_paths = {
		format_string("%s/game_variants", engine_name/*"haloreach"*/),
		format_string("%s/hopper_game_variants", engine_name/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/GameType/", get_user_profile_environment_variable(), engine_name/*"haloreach"*/)
	};
	static c_file_array file_array = c_file_array(file_paths, { ".bin" }, &read_game_variant);

	c_fixed_string_128& selected_game_variant = hopper_game_variant[current_game_mode];
	if (ImGui::BeginCombo("Game Variant", file_array.get_name(selected_game_variant.c_str())))
	{
		const char* last_filename = file_array.get_filename(selected_game_variant.c_str());

		for (size_t file_index = 0; file_index < file_array.file_count; file_index++)
		{
			ImGui::PushID(static_cast<int>(file_index));

			const int type = file_array.get_type(file_index);
			

			int should_show = current_game_mode == _mcc_game_mode_multiplayer && type == _game_engine_type_sandbox;
			should_show |= current_game_mode == _mcc_game_mode_multiplayer && type == _game_engine_type_megalo;
			should_show |= current_game_mode == _mcc_game_mode_campaign && type == _game_engine_type_campaign;
			should_show |= current_game_mode == _mcc_game_mode_firefight && type == _game_engine_type_survival;

			if (should_show)
			{
				if (const char* filename = file_array.get_filename(file_index))
				{
					bool selected = filename == last_filename;

					c_fixed_string_1024 selected_game_variant_name;
					const char* name = file_array.get_name(file_index);
					selected_game_variant_name.format("%s (%s)", name, filename);
					if (ImGui::Selectable(selected_game_variant_name.c_str(), &selected))
					{
						selected_game_variant = filename;
						save_selected_game_variant_setting(current_game_mode);
					}

					render_hovered_tooltip(file_array.get_description(file_index));
				}
			}

			ImGui::PopID();
		}

		ImGui::EndCombo();
	}
}

void c_haloreach_game_option_selection_legacy::select_map_variant()
{
	if (current_game_mode != _mcc_game_mode_multiplayer)
	{
		return;
	}

	const char* engine_name = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> file_paths = {
		format_string("%s/map_variants", engine_name/*"haloreach"*/),
		format_string("%s/map_game_variants", engine_name/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Map/", get_user_profile_environment_variable(), engine_name/*"haloreach"*/)
	};
	static c_file_array file_array = c_file_array(file_paths, { ".mvar" }, &ReadMapVariant);

	c_fixed_string_128& selected_map_variant = hopper_map_variant[current_game_mode];

	const char* map_name = file_array.get_name(selected_map_variant.c_str());
	if (!map_name || selected_map_variant.empty())
	{
		selected_map_variant = "";
		map_name = "<Default Variant>";
	}

	if (ImGui::BeginCombo("Map Variant", map_name))
	{
		bool defaultSelected = false;
		if (ImGui::Selectable("<Default Variant>", &defaultSelected))
		{
			selected_map_variant = "";
		}

		const char* last_filename = file_array.get_filename(selected_map_variant.c_str());

		for (size_t i = 0; i < file_array.file_count; i++)
		{
			ImGui::PushID(static_cast<int>(i));

			if (const c_map_info* selected_map_info = selected_map_infos[current_game_mode])
			{
				if (file_array.get_type(i) == selected_map_info->get_map_id())
				{
					if (const char* filename = file_array.get_filename(i))
					{
						bool selected = filename == last_filename;

						c_fixed_string_1024 selected_map_variant_name;
						const char* name = file_array.get_name(i);
						selected_map_variant_name.format("%s (%s)", name, filename);
						if (ImGui::Selectable(selected_map_variant_name.c_str(), &selected) && !defaultSelected)
						{
							selected_map_variant = filename;
							save_selected_map_variant_setting(current_game_mode);
						}

						render_hovered_tooltip(file_array.get_description(i));
					}
				}
			}

			ImGui::PopID();
		}

		ImGui::EndCombo();
	}
}

void c_haloreach_game_option_selection_legacy::select_saved_film()
{
	return;

	//static std::vector<std::string> filepathPaths = {
	//	format_string("%s/Temporary/autosave/", "haloreach"),
	//	format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Movie/", get_user_profile_environment_variable(), "haloreach"),
	//	format_string("%s/AppData/LocalLow/MCC/Temporary/%s/autosave/", get_user_profile_environment_variable(), "haloreach")
	//};

	//static c_file_array file_array = c_file_array(filepathPaths, { ".film", ".mov" }, &ReadSavedFilm);
	//static const char* last = "";

	//if (s_launch_saved_film_filepath != file_array.get_filename(last))
	//{
	//	s_launch_saved_film_filepath = file_array.get_filename(last);
	//}
	//if (last != file_array.get_filename(last))
	//{
	//	last = file_array.get_filename(last);
	//}

	//if (ImGui::BeginCombo("###SAVED FILM", file_array.GetDesc(last)))
	//{
	//	for (size_t i = 0; i < file_array.file_count; i++)
	//	{
	//		if (file_array.get_name(i))
	//		{
	//			bool selected = file_array.get_name(i) == file_array.get_name(last);

	//			std::string pSelectedSavedFilmName = std::string(file_array.GetDesc(i)).append(" (").append(file_array.get_filename(i)).append(")###").append(std::to_string(i));
	//			if (ImGui::Selectable(file_array.GetDesc(i), &selected))
	//			{
	//				last = file_array.get_filename(i);
	//			}

	//			render_hovered_tooltip(file_array.get_name(i));
	//		}
	//	}

	//	ImGui::EndCombo();
	//}

	//s_launch_saved_film_filepath = last;
}

void c_haloreach_game_option_selection_legacy::load_map_variant(IDataAccess* data_access, const char* engine_name, const char* variant_name, s_map_variant& map_variant, bool print)
{
	memset(&map_variant, 0, sizeof(map_variant));

	if (variant_name[0])
	{
		static std::string filepath = "";
		if (!PathFileExistsA((filepath = format_string("%s/hopper_map_variants/%s.mvar", engine_name, variant_name)).c_str()))
		{
			if (!PathFileExistsA((filepath = format_string("%s/map_variants/%s.mvar", engine_name, variant_name)).c_str()))
			{
				if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/Map/%s.mvar", get_user_profile_environment_variable(), engine_name, variant_name)).c_str()))
				{
					if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Map/%s.mvar", get_user_profile_environment_variable(), engine_name, variant_name)).c_str()))
					{
						filepath = "";
					}
				}
			}
		}

		char* variant_data = nullptr;
		size_t variant_data_size = 0;

		if (!filesystem_read_file_to_memory(filepath.c_str(), reinterpret_cast<void**>(&variant_data), &variant_data_size))
		{
			c_console::write_line_verbose("Failed to open map variant file");
			return;
		}
		if (variant_data == 0)
		{
			c_console::write_line_verbose("Map variant was zero sized");
			return;
		}

		if (is_valid(variant_data))
		{
			if (print)
			{
				c_console::write_line_verbose("Loading map variant [%s]", filepath.c_str());
			}

			map_variant = data_access->map_variant_create_from_file(variant_data, variant_data_size)->map_variant;

			delete[] variant_data;
			return;
		}
	}

	// fallback to use map ID
	if(const c_map_info* selected_map_info = selected_map_infos[current_game_mode])
	{
		if (print)
		{
			c_console::write_line_verbose("Creating map variant for '%s'", selected_map_info->get_friendly_name());
		}

		map_variant = data_access->map_variant_create_from_map_id(selected_map_info->get_map_id())->map_variant;
	}
}

void c_haloreach_game_option_selection_legacy::load_game_variant(IDataAccess* data_access, const char* engine_name, const char* variant_name, s_game_variant& game_variant, bool print)
{
	ASSERT(data_access != nullptr);
	ASSERT(engine_name != nullptr);
	ASSERT(variant_name != nullptr);

	memset(&game_variant, 0, sizeof(game_variant));
	if (variant_name == nullptr)
	{
		return;
	}

	static std::string filepath = "";
	if (!PathFileExistsA((filepath = format_string("%s/hopper_game_variants/%s.bin", engine_name, variant_name)).c_str()))
	{
		if (!PathFileExistsA((filepath = format_string("%s/game_variants/%s.bin", engine_name, variant_name)).c_str()))
		{
			if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/GameType/%s.bin", get_user_profile_environment_variable(), engine_name, variant_name)).c_str()))
			{
				if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/GameType/%s.bin", get_user_profile_environment_variable(), engine_name, variant_name)).c_str()))
				{
					filepath = "";
				}
			}
		}
	}

	char* variant_data = nullptr;
	size_t variant_data_size = 0;

	if (!filesystem_read_file_to_memory(filepath.c_str(), reinterpret_cast<void**>(&variant_data), &variant_data_size))
	{
		c_console::write_line_verbose("Failed to open map variant file");
		return;
	}
	if (variant_data == 0)
	{
		c_console::write_line_verbose("Map variant was zero sized");
		return;
	}

	if (is_valid(variant_data))
	{
		if (print)
		{
			c_console::write_line_verbose("Loading game variant [%s]", filepath.c_str());
		}

		IGameVariant* game_variant_interface = data_access->game_variant_create_from_file(variant_data, variant_data_size);
		if (game_variant_interface != nullptr)
		{
			game_variant = game_variant_interface->game_variant;
		}
		else
		{
			c_console::write_line_verbose(__FUNCTION__"> warning: failed to create game variant from file '%s'", filepath.c_str());
		}

		delete[] variant_data;
		return;
	}
}

// TODO: Test, and fix if broke
void c_haloreach_game_option_selection_legacy::load_savegame(const char* game_state_name, GameOptions& options)
{
	return;

	//char filepath[MAX_PATH + 1];
	//sprintf(filepath, "%s.hdr", game_state_name);
	//filepath[MAX_PATH] = 0;

	//char* pGameStateBuffer = {};
	//size_t gameStateSize = {};

	//c_file_reference filo(filepath);
	//if (filo.open_file())
	//{
	//	pGameStateBuffer = new char[filo.buffer_size];
	//	memset(pGameStateBuffer, 0x00, filo.buffer_size);
	//	pGameStateBuffer = filo.buffer;

	//	options.game_mode = _mcc_game_mode_campaign;
	//	options.game_state_header_size = filo.buffer_size;
	//	options.game_state_header = pGameStateBuffer;

	//	filo.close_file();
	//}
}

void c_haloreach_game_option_selection_legacy::load_saved_film(const char* saved_film_name, GameOptions& options)
{
	if (!(*saved_film_name))
		return;

	static std::string filepath = "";
	if (!PathFileExistsA((filepath = format_string("%s/Temporary/autosave/%s.film", "haloreach", saved_film_name)).c_str()))
	{
		if (!PathFileExistsA((filepath = format_string("%s/Temporary/autosave/%s.mov", "haloreach", saved_film_name)).c_str()))
		{
			if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/HaloMCC/Temporary/UserContent/%s/Movie/%s.mov", get_user_profile_environment_variable(), "haloreach", saved_film_name)).c_str()))
			{
				if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Movie/%s.mov", get_user_profile_environment_variable(), "haloreach", saved_film_name)).c_str()))
				{
					if (!PathFileExistsA((filepath = format_string("%s/AppData/LocalLow/MCC/Temporary/%s/autosave/%s.film", get_user_profile_environment_variable(), "haloreach", saved_film_name)).c_str()))
					{
						filepath = "";
					}
				}
			}
		}
	}

	if (filepath.c_str())
	{
		c_console::write_line_verbose("Loading saved film [%s]", filepath.c_str());
	}

	options.saved_film_path = filepath.c_str();

}

#endif
