#include "gameframework-private-pch.h"

c_map_info_manager::c_map_info_manager(const char* directory_path)
{
	using namespace std;
	if (filesystem_directory_exists(directory_path))
	{
		// #TODO: Automatic Windows filesystem watching
		for (const std::filesystem::directory_entry& rDirectoryEntry : std::filesystem::directory_iterator(directory_path)) {

			const std::filesystem::path& rFilepath = rDirectoryEntry.path();
			if (rFilepath.has_extension())
			{
				std::wstring filepathExtension = rFilepath.extension();
				if (_wcsicmp(filepathExtension.c_str(), L".mapinfo") == 0)
				{
					parse_map_info(rFilepath);
				}
			}
		}
	}
	else
	{
		write_line_verbose("MapInfoManager> Failed to find map info directory '%s'. Is Opus running in the correct working directory?", directory_path);
	}
}

void c_map_info_manager::parse_map_info(const std::filesystem::path& filesystem_path)
{
	std::filesystem::path filesystem_filepath = filesystem_path.filename();
	const wchar_t* filepath = filesystem_filepath.c_str();
	write_line_verbose("MapInfoManager> Parsing %S", filepath);

	char* raw_map_info_data = filesystem_read_to_memory_legacy(filesystem_path.c_str()); // #TODO: filesystem_read_to_memory_legacy deprecated
	if (raw_map_info_data == nullptr)
	{
		write_line_verbose("MapInfoManager> Error opening %S for read", filepath);
		return;
	}

	c_blam_file_parser file_parser(raw_map_info_data);
	const s_blamfile_level_chunk* level_info = file_parser.get_first_chunk_by_type<s_blamfile_level_chunk>();

	if (level_info == nullptr)
	{
		write_line_verbose("MapInfoManager> Error parsing mapinfo %S. Couldn't find level chunk.", filepath);
		return;
	}

	// store a copy
	level_info = &map_infos.emplace_back(filesystem_path, file_parser.is_little_endian(), *level_info).get_level_chunk();
	delete raw_map_info_data;

	write_line_verbose("MapInfoManager> Parsed level chunk '%S' %i", level_info->m_levelName[0], level_info->m_mapID);
}
