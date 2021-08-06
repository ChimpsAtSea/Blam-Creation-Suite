#pragma once

class c_infinite_debug_reader;
class c_infinite_tag_reader;
class c_infinite_resource_reader;
class c_infinite_localization_reader;
class c_infinite_tag_group;
class c_infinite_tag_instance;

class c_infinite_cache_cluster : public c_cache_cluster
{
public:
	friend c_debug_reader;
	friend c_tag_reader;
	friend c_resource_reader;
	friend c_localization_reader;
	friend c_infinite_debug_reader;
	friend c_infinite_tag_reader;
	friend c_infinite_resource_reader;
	friend c_infinite_localization_reader;
	friend c_infinite_tag_group;
	friend c_infinite_tag_instance;

	c_infinite_cache_cluster(c_infinite_module_file_reader** cache_readers, unsigned long cache_reader_count, s_engine_platform_build engine_platform_build);
	virtual ~c_infinite_cache_cluster();

	BCS_RESULT get_debug_reader(c_infinite_module_file_reader& cache_reader, c_infinite_debug_reader*& debug_reader);
	BCS_RESULT get_tag_reader(c_infinite_module_file_reader& cache_reader, c_infinite_tag_reader*& tag_reader);
	BCS_RESULT get_resource_reader(c_infinite_module_file_reader& cache_reader, c_infinite_resource_reader*& resource_reader);
	BCS_RESULT get_localization_reader(c_infinite_module_file_reader& cache_reader, c_infinite_localization_reader*& localization_reader);

	virtual BCS_RESULT get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const;
	virtual BCS_RESULT get_engine_platform_build(s_engine_platform_build& engine_platform_build) const;
	virtual BCS_RESULT get_cache_readers(c_cache_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const;
	virtual BCS_RESULT get_cache_readers(c_infinite_module_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const;

	BCS_RESULT get_tag_instance_by_global_tag_id(long global_tag_id, c_tag_instance*& tag_instance);
	BCS_RESULT get_tag_instance_by_global_tag_id_and_group_tag(long global_tag_id, tag group_tag, c_tag_instance*& tag_instance);

protected:
	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader);
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader);
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader);
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader);

protected:
	using t_cache_readers = std::vector<c_infinite_module_file_reader*>;
	using t_debug_readers = std::map<c_infinite_module_file_reader*, c_infinite_debug_reader*>;
	using t_tag_readers = std::map<c_infinite_module_file_reader*, c_infinite_tag_reader*>;
	using t_resource_readers = std::map<c_infinite_module_file_reader*, c_infinite_resource_reader*>;
	using t_localization_readers = std::map<c_infinite_module_file_reader*, c_infinite_localization_reader*>;

	t_cache_readers cache_readers;
	t_debug_readers debug_readers;
	t_tag_readers tag_readers;
	t_resource_readers resource_readers;
	t_localization_readers localization_readers;

	s_engine_platform_build engine_platform_build;

	BCS_RESULT get_cache_reader_by_relative_path(const char* relative_path, c_infinite_module_file_reader*& cache_reader);
};
