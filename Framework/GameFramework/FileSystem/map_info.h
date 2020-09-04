#pragma once

class c_map_info
{
private:
	s_blamfile_level_chunk level_chunk;
	bool is_level_chunk_little_endian;
	std::filesystem::path filesystem_path;
	std::string friendly_name;
	std::string friendly_description;

	inline s_blamfile_level_chunk_flags get_little_endian_level_chunk_flags() const
	{
		unsigned int blamfile_raw_flags = bswap_auto_endian(is_level_chunk_little_endian, *reinterpret_cast<const unsigned int*>(&level_chunk.flags));
		s_blamfile_level_chunk_flags& flags = *reinterpret_cast<s_blamfile_level_chunk_flags*>(&blamfile_raw_flags);
		return flags;
	}

public:
	c_map_info(const std::filesystem::path& filepath, bool is_level_chunk_little_endian, const s_blamfile_level_chunk& level_chunk);

	const char* get_friendly_name() const;
	const char* get_friendly_description() const;
	const char* get_map_filepath() const { return level_chunk.map_path; }
	int get_map_id() const;
	inline bool is_main_menu() const { return get_little_endian_level_chunk_flags().is_main_menu; }
	inline bool is_multiplayer() const { return get_little_endian_level_chunk_flags().is_multiplayer; }
	inline bool is_campaign() const { return get_little_endian_level_chunk_flags().is_campaign; }
	inline bool is_firefight() const { return get_little_endian_level_chunk_flags().is_firefight; }
	inline bool is_visible() const { return get_little_endian_level_chunk_flags().is_visible; }
	inline bool is_saved_filenabled() const { return get_little_endian_level_chunk_flags().is_saved_filenabled; }
	inline bool is_dlc() const { return get_little_endian_level_chunk_flags().is_dlc; }
	inline bool is_cinematic() const { return get_little_endian_level_chunk_flags().is_cinematic; }
	inline const s_blamfile_level_chunk& get_level_chunk() const { return level_chunk; }
};

