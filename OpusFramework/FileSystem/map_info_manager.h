#pragma once

class c_map_info_manager
{
public:
	c_map_info_manager(const char* directory_path);

	void parse_map_info(const std::filesystem::path& filesystem_path);
	std::vector<MapInfo> map_infos;
};

