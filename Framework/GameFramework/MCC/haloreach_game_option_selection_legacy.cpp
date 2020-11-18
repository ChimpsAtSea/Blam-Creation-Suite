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

e_mcc_game_mode g_current_game_mode = _mcc_game_mode_campaign;
//e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
extern e_campaign_difficulty_level g_campaign_difficulty_level; // #TODO #REFACTOR

c_map_info_manager* c_haloreach_game_option_selection_legacy::g_map_info_manager = nullptr;
const c_map_info* c_haloreach_game_option_selection_legacy::g_selected_map_info[underlying_cast(k_number_of_selected_game_mode_map_info_indices)] = {};

//GameTypeManager* c_haloreach_game_option_selection_legacy::g_game_type_manager = nullptr;
//const GameType* c_haloreach_game_option_selection_legacy::selected_game_type[underlying_cast(k_number_of_selected_game_mode_map_info_indices)] = {};

// #TODO: Remove these
std::string c_haloreach_game_option_selection_legacy::s_launch_game_variant = "";
std::string c_haloreach_game_option_selection_legacy::s_launch_map_variant = "";
std::string c_haloreach_game_option_selection_legacy::s_launch_saved_film_filepath = "";

void c_haloreach_game_option_selection_legacy::Init()
{
	// #TODO: Support more games than just Halo Reach
	g_map_info_manager = new c_map_info_manager("haloreach/maps/info");

	loadSettings();
}

void c_haloreach_game_option_selection_legacy::deinit()
{
	delete g_map_info_manager;
}

void c_haloreach_game_option_selection_legacy::loadSettings()
{
	for (underlying(e_selected_game_mode_map_info_index) i = 0; i < underlying_cast(k_number_of_selected_game_mode_map_info_indices); i++)
	{
		g_selected_map_info[i] = GetDefaultMapSelection(static_cast<e_selected_game_mode_map_info_index>(i));
	}

	char pLaunchgame_modeBuffer[256] = {};
	c_settings::read_string(_settings_section_launch, "GameMode", pLaunchgame_modeBuffer, sizeof(pLaunchgame_modeBuffer), "");
	g_current_game_mode = string_to_mcc_game_mode(pLaunchgame_modeBuffer);
	if (g_current_game_mode == _mcc_game_mode_none)
	{
		g_current_game_mode = _mcc_game_mode_campaign;
	}

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	c_settings::read_string(_settings_section_launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_campaign_difficulty_level = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	LPCSTR pDefaultHopperGameVariant = "";
	switch (g_current_game_mode)
	{
		break;
	case _mcc_game_mode_campaign:
		pDefaultHopperGameVariant = "campaign_default_054";
		break;
	case _mcc_game_mode_multiplayer:
		pDefaultHopperGameVariant = "slayer_054";
		break;
	case _mcc_game_mode_firefight:
		pDefaultHopperGameVariant = "ff_firefight_054";
		break;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchGameVariantBuffer[256] = {};
	uint32_t LaunchGameVariantLength = c_settings::read_string(_settings_section_launch, "GameVariant", pLaunchGameVariantBuffer, sizeof(pLaunchGameVariantBuffer), pDefaultHopperGameVariant);
	if (LaunchGameVariantLength > 0)
	{
		s_launch_game_variant = pLaunchGameVariantBuffer;
	}
	else
	{
		s_launch_game_variant = "";
	}

	// #TODO: This must persist outside of the read
	static char pLaunchMapVariantBuffer[256] = {};
	uint32_t LaunchMapVariantLength = c_settings::read_string(_settings_section_launch, "MapVariant", pLaunchMapVariantBuffer, sizeof(pLaunchMapVariantBuffer), "");
	if (LaunchMapVariantLength > 0)
	{
		s_launch_map_variant = pLaunchMapVariantBuffer;
	}
	else
	{
		s_launch_map_variant = "";
	}
}

e_mcc_game_mode c_haloreach_game_option_selection_legacy::get_selected_game_mode()
{
	return g_current_game_mode;
}

void c_haloreach_game_option_selection_legacy::select_game_mode()
{
	if (c_command_line::has_command_line_arg("-showallmodes"))
	{
		const char* selected_mcc_game_mode_string = mcc_game_mode_to_local_string(g_current_game_mode);
		if (ImGui::BeginCombo("Game Mode", selected_mcc_game_mode_string))
		{
			for (underlying(e_mcc_game_mode) i = 0; i < k_number_of_mcc_game_modes; i++)
			{
				const char* current_mcc_game_mode_string = mcc_game_mode_to_local_string(static_cast<e_mcc_game_mode>(i));
				DEBUG_ASSERT(current_mcc_game_mode_string != nullptr);

				bool selected = selected_mcc_game_mode_string == current_mcc_game_mode_string;
				if (ImGui::Selectable(current_mcc_game_mode_string, &selected))
				{
					g_current_game_mode = static_cast<e_mcc_game_mode>(i);
					c_settings::write_string(_settings_section_launch, "game_mode", mcc_game_mode_to_string(g_current_game_mode));
				}
			}

			ImGui::EndCombo();
		}
	}
	else
	{
		LPCSTR s_pCurrentgame_modeStr = mcc_game_mode_to_local_string(g_current_game_mode);
		if (ImGui::BeginCombo("Game Mode", s_pCurrentgame_modeStr))
		{
			for (uint32_t i = 0; i < k_number_of_selected_game_mode_map_info_indices; i++)
			{
				if (i == _selected_game_mode_map_info_index_unknown)
				{
					continue;
				}

				e_mcc_game_mode game_mode = selected_game_mode_map_info_index_to_game_mode(static_cast<e_selected_game_mode_map_info_index>(i));
				LPCSTR pgame_modeStr = mcc_game_mode_to_local_string(game_mode);
				if (pgame_modeStr)
				{
					bool selected = s_pCurrentgame_modeStr == pgame_modeStr;
					if (ImGui::Selectable(pgame_modeStr, &selected))
					{
						g_current_game_mode = game_mode;
						c_settings::write_string(_settings_section_launch, "game_mode", mcc_game_mode_to_string(g_current_game_mode));
					}
				}
			}

			ImGui::EndCombo();
		}
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

const c_map_info* c_haloreach_game_option_selection_legacy::GetDefaultMapSelection(e_selected_game_mode_map_info_index game_mode_map_info_index)
{
	int previous_map_id = c_settings::read_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(game_mode_map_info_index)], -1);
	for (const c_map_info& rMapInfo : g_map_info_manager->map_infos)
	{
		if (rMapInfo.get_map_id() == previous_map_id)
		{
			return &rMapInfo;
		}
	}

	return nullptr;
}

const c_map_info* c_haloreach_game_option_selection_legacy::GetDefaultHaloReachGameOptionSelection(e_selected_game_mode_map_info_index game_mode_map_info_index)
{
	int previousmap_id = c_settings::read_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(game_mode_map_info_index)], -1);
	for (const c_map_info& rMapInfo : g_map_info_manager->map_infos)
	{
		if (rMapInfo.get_map_id() == previousmap_id)
		{
			return &rMapInfo;
		}
	}

	return nullptr;
}

e_selected_game_mode_map_info_index c_haloreach_game_option_selection_legacy::game_mode_to_selected_game_mode_map_info_index(e_mcc_game_mode game_mode)
{
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		return _selected_game_mode_map_info_index_campaign;
	case _mcc_game_mode_multiplayer:
		return _selected_game_mode_map_info_index_multiplayer;
	case _mcc_game_mode_firefight:
		return _selected_game_mode_map_info_index_firefight;
	default:
		return _selected_game_mode_map_info_index_unknown;
	}
}

e_mcc_game_mode c_haloreach_game_option_selection_legacy::selected_game_mode_map_info_index_to_game_mode(e_selected_game_mode_map_info_index selected_game_mode_map_info_index)
{
	switch (selected_game_mode_map_info_index)
	{
	case _selected_game_mode_map_info_index_campaign:
		return _mcc_game_mode_campaign;
	case _selected_game_mode_map_info_index_multiplayer:
		return _mcc_game_mode_multiplayer;
	case _selected_game_mode_map_info_index_firefight:
		return _mcc_game_mode_firefight;
	default:
		return _mcc_game_mode_none;
	}
}

const c_map_info*& c_haloreach_game_option_selection_legacy::get_selected_map_info_by_selected_game_mode_map_info_index(e_selected_game_mode_map_info_index selected_game_mode_map_info_index)
{
	const c_map_info*& selected_map_info = g_selected_map_info[selected_game_mode_map_info_index];
	return selected_map_info;
}

const c_map_info*& c_haloreach_game_option_selection_legacy::get_selected_map_info_by_game_mode(e_mcc_game_mode game_mode)
{
	return get_selected_map_info_by_selected_game_mode_map_info_index(game_mode_to_selected_game_mode_map_info_index(g_current_game_mode));
}

const c_map_info* c_haloreach_game_option_selection_legacy::get_selected_map_info()
{
	return get_selected_map_info_by_game_mode(g_current_game_mode);
}

const c_map_info* c_haloreach_game_option_selection_legacy::get_first_suitable_game_modeMapInfo(e_mcc_game_mode game_mode)
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

void c_haloreach_game_option_selection_legacy::save_selected_map(e_mcc_game_mode game_mode, const c_map_info* pMapInfo)
{
	switch (game_mode)
	{
	case _mcc_game_mode_campaign:
		c_settings::write_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(_selected_game_mode_map_info_index_campaign)], pMapInfo ? pMapInfo->get_map_id() : -1);
		break;
	case _mcc_game_mode_multiplayer:
		c_settings::write_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(_selected_game_mode_map_info_index_multiplayer)], pMapInfo ? pMapInfo->get_map_id() : -1);
		break;
	case _mcc_game_mode_firefight:
		c_settings::write_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(_selected_game_mode_map_info_index_firefight)], pMapInfo ? pMapInfo->get_map_id() : -1);
		break;
	default:
		c_settings::write_integer(_settings_section_launch, s_kpMapInfoSettingsName[underlying_cast(_selected_game_mode_map_info_index_unknown)], pMapInfo ? pMapInfo->get_map_id() : -1);
		break;
	}
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
	const c_map_info*& selected_map_info = get_selected_map_info_by_game_mode(g_current_game_mode);

	if (!selected_map_info || selected_map_info && !is_map_info_compatible_with_game_mode(g_current_game_mode, *selected_map_info))
	{
		selected_map_info = get_first_suitable_game_modeMapInfo(g_current_game_mode);
		save_selected_map(g_current_game_mode, selected_map_info);
	}

	const char* selected_level_name = "<no level selected>";
	if (selected_map_info)
	{
		selected_level_name = selected_map_info->get_friendly_name();
	}

	if (ImGui::BeginCombo("Map", selected_level_name))
	{
		// #TODO: Make a nice and beautiful interface to this for multi-game
		for (const c_map_info& map_info : g_map_info_manager->map_infos)
		{
			if (!is_map_info_compatible_with_game_mode(g_current_game_mode, map_info))
			{
				continue;
			}

			bool selected = selected_map_info == &map_info;
			const char* current_level_friendly_name = map_info.get_friendly_name();

			if (ImGui::Selectable(current_level_friendly_name, &selected))
			{
				selected_map_info = &map_info;
				save_selected_map(g_current_game_mode, selected_map_info);
			}
			render_hovered_tooltip(map_info.get_friendly_description());
		}

		ImGui::EndCombo();
	}
}

void c_haloreach_game_option_selection_legacy::select_difficulty()
{
	if (g_current_game_mode == _mcc_game_mode_campaign || g_current_game_mode == _mcc_game_mode_firefight)
	{
		LPCSTR pCurrentDifficultyStr = campaign_difficulty_level_to_local_string(g_campaign_difficulty_level);
		if (ImGui::BeginCombo("Difficulty", pCurrentDifficultyStr))
		{
			for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int&>(difficulty)++)
			{
				LPCSTR pDifficultyStr = campaign_difficulty_level_to_local_string(difficulty);
				if (pDifficultyStr)
				{
					bool selected = pDifficultyStr == pCurrentDifficultyStr;
					if (ImGui::Selectable(pDifficultyStr, &selected))
					{
						g_campaign_difficulty_level = static_cast<e_campaign_difficulty_level>(difficulty);
						c_settings::write_string(_settings_section_launch, "DifficultyLevel", campaign_difficulty_level_to_string(g_campaign_difficulty_level));
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

int c_haloreach_game_option_selection_legacy::read_game_variant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR filesystem_path)
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

int c_haloreach_game_option_selection_legacy::ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	static s_map_variant map_variant;
	IDataAccess* data_access = c_haloreach_game_host::get_data_access();
	ASSERT(data_access != nullptr);
	load_map_variant(data_access, "haloreach", pName, map_variant);

	int result = *reinterpret_cast<int*>(&map_variant.data[0x2C]);
	GetVariantInfo(map_variant.data, name, desc);

	return result;
}

int c_haloreach_game_option_selection_legacy::ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
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
	const char* engine_name = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> file_paths = {
		format_string("%s/game_variants", engine_name/*"haloreach"*/),
		format_string("%s/hopper_game_variants", engine_name/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/GameType/", get_user_profile_environment_variable(), engine_name/*"haloreach"*/)
	};
	static c_file_array file_array = c_file_array(file_paths, { ".bin" }, &read_game_variant);
	static LPCSTR last = s_launch_game_variant.c_str();

	if (g_current_game_mode == _mcc_game_mode_campaign)
	{
		return;
	}

	if (ImGui::BeginCombo("Game Variant", file_array.get_name(last)))
	{
		const char* last_filename = file_array.get_filename(last);

		for (size_t i = 0; i < file_array.file_count; i++)
		{
			ImGui::PushID(static_cast<int>(i));

			const int type = file_array.get_type(i);
			const LPCSTR filename = file_array.get_filename(i);

			int should_show = g_current_game_mode == _mcc_game_mode_multiplayer && type == _game_engine_type_sandbox;
			should_show |= g_current_game_mode == _mcc_game_mode_multiplayer && type == _game_engine_type_megalo;
			should_show |= g_current_game_mode == _mcc_game_mode_campaign && type == _game_engine_type_campaign;
			should_show |= g_current_game_mode == _mcc_game_mode_firefight && type == _game_engine_type_survival;

			if (filename && should_show)
			{
				bool selected = filename == last_filename;

				c_fixed_string_1024 selected_game_variant_name;
				const char* name = file_array.get_name(i);
				selected_game_variant_name.format("%s (%s)", name, filename);
				if (ImGui::Selectable(selected_game_variant_name.c_str(), &selected))
				{
					last = filename;
				}

				render_hovered_tooltip(file_array.get_description(i));
			}

			ImGui::PopID();
		}

		ImGui::EndCombo();
	}

	s_launch_game_variant = last;
}

void c_haloreach_game_option_selection_legacy::select_map_variant()
{
	const char* engine_name = "haloreach"; // #TODO: Set this up properly
	static std::vector<std::string> file_paths = {
		format_string("%s/map_variants", engine_name/*"haloreach"*/),
		format_string("%s/map_game_variants", engine_name/*"haloreach"*/),
		format_string("%s/AppData/LocalLow/MCC/Temporary/UserContent/%s/Map/", get_user_profile_environment_variable(), engine_name/*"haloreach"*/)
	};
	static c_file_array file_array = c_file_array(file_paths, { ".mvar" }, &ReadMapVariant);
	static LPCSTR last = s_launch_map_variant.c_str();

	if (g_current_game_mode != _mcc_game_mode_multiplayer)
	{
		return;
	}

	const c_map_info* selected_map_info = get_selected_map_info_by_game_mode(g_current_game_mode);

	LPCSTR lastMapName = file_array.get_name(last);
	if (!lastMapName || last[0] == 0)
	{
		last = "";
		lastMapName = "<Default Variant>";
	}
	if (ImGui::BeginCombo("Map Variant", lastMapName))
	{
		bool defaultSelected = false;
		if (ImGui::Selectable("<Default Variant>", &defaultSelected))
		{
			last = "";
		}

		const char* last_filename = file_array.get_filename(last);

		for (size_t i = 0; i < file_array.file_count; i++)
		{
			ImGui::PushID(static_cast<int>(i));

			int should_show = file_array.get_type(i) == selected_map_info->get_map_id();

			const char* filename = file_array.get_filename(i);

			if (filename && should_show)
			{
				bool selected = filename == last_filename;

				c_fixed_string_1024 selected_map_variant_name;
				const char* name = file_array.get_name(i);
				selected_map_variant_name.format("%s (%s)", name, filename);
				if (ImGui::Selectable(selected_map_variant_name.c_str(), &selected) && !defaultSelected)
				{
					last = filename;
				}

				render_hovered_tooltip(file_array.get_description(i));
			}

			ImGui::PopID();
		}

		ImGui::EndCombo();
	}

	s_launch_map_variant = last;
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
	//static LPCSTR last = "";

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
	{
		const c_map_info* selected_map_info = get_selected_map_info_by_game_mode(g_current_game_mode);

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
void c_haloreach_game_option_selection_legacy::load_savegame(const char* game_state_name, GameContext& game_context)
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

	//	game_context.game_mode = _mcc_game_mode_campaign;
	//	game_context.game_state_header_size = filo.buffer_size;
	//	game_context.game_state_header = pGameStateBuffer;

	//	filo.close_file();
	//}
}

void c_haloreach_game_option_selection_legacy::load_saved_film(const char* saved_film_name, GameContext& game_context)
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

	game_context.saved_film_path = filepath.c_str();

}

#endif
