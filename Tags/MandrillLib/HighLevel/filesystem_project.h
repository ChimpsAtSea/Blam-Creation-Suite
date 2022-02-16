#pragma once

class c_high_level_cache_cluster_transplant;
class h_tag;

class c_filesystem_tag_project :
	public c_tag_project
{
public:
	c_filesystem_tag_project(const wchar_t* directory, s_engine_platform_build engine_platform_build);
	~c_filesystem_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_group*& group) const override;
	virtual BCS_RESULT get_group_by_file_extension(const char* file_extension, h_group*& group) const;
	virtual BCS_RESULT get_tag_instances(h_tag* const*& tag_instances, unsigned long& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_group* const*& groups, unsigned long& group_count) const override;

	void try_open_tag_files();
	void try_open_single_tag_file(const wchar_t* filepath, const wchar_t* relative_filepath);
	h_tag* try_parse_tag_file(const wchar_t* filepath);

protected:
	wchar_t tags_directory[0x10000u];
	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;

	struct s_tag_candidate
	{
		h_group* group;
		const wchar_t* filepath;
		const wchar_t* relative_filepath;
	};
	std::vector<s_tag_candidate> candidates;
};
