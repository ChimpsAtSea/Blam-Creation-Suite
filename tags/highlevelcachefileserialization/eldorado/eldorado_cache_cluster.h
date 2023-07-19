#pragma once

class c_eldorado_debug_reader;
class c_eldorado_tag_reader;
class c_eldorado_resource_reader;
class c_eldorado_localization_reader;
class c_eldorado_tag_group;
class c_eldorado_tag_instance;

class c_eldorado_cache_cluster : public c_cache_cluster
{
public:
	friend c_debug_reader;
	friend c_tag_reader;
	friend c_resource_reader;
	friend c_localization_reader;
	friend c_eldorado_debug_reader;
	friend c_eldorado_tag_reader;
	friend c_eldorado_resource_reader;
	friend c_eldorado_localization_reader;
	friend c_eldorado_tag_group;
	friend c_eldorado_tag_instance;

	c_eldorado_cache_cluster(c_eldorado_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build);
	virtual ~c_eldorado_cache_cluster();

	BCS_RESULT get_debug_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_debug_reader*& debug_reader);
	BCS_RESULT get_tag_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_tag_reader*& tag_reader);
	BCS_RESULT get_resource_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_resource_reader*& resource_reader);
	BCS_RESULT get_localization_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_localization_reader*& localization_reader);

	virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const override;
	virtual BCS_RESULT get_engine_platform_build(s_engine_platform_build& engine_platform_build) const override;
	virtual BCS_RESULT get_cache_readers(c_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const override;
	virtual BCS_RESULT get_cache_readers(c_eldorado_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const;
	virtual BCS_RESULT get_postprocessing_fixups(c_postprocessing_fixup const* const*& fixups, uint32_t& fixup_count) const override;

protected:
	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader) override;
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader) override;
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader) override;
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader) override;

protected:
	using t_cache_readers = std::vector<c_eldorado_cache_file_reader*>;
	using t_debug_readers = std::unordered_map<c_eldorado_cache_file_reader*, c_eldorado_debug_reader*>;
	using t_tag_readers = std::unordered_map<c_eldorado_cache_file_reader*, c_eldorado_tag_reader*>;
	using t_resource_readers = std::unordered_map<c_eldorado_cache_file_reader*, c_eldorado_resource_reader*>;
	using t_localization_readers = std::unordered_map<c_eldorado_cache_file_reader*, c_eldorado_localization_reader*>;

	t_cache_readers cache_readers;
	t_debug_readers debug_readers;
	t_tag_readers tag_readers;
	t_resource_readers resource_readers;
	t_localization_readers localization_readers;

	s_engine_platform_build engine_platform_build;
	
	BCS_RESULT get_cache_reader_by_relative_path(const char* relative_path, c_eldorado_cache_file_reader*& cache_reader);
};
