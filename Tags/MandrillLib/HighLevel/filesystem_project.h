#pragma once

class c_high_level_cache_cluster_transplant;
struct s_filesystem_tag_project_read_tags_callback_data;

class c_filesystem_tag_project :
	public c_tag_project
{
public:
	BCS_SHARED c_filesystem_tag_project(
		const wchar_t* directory, 
		s_engine_platform_build engine_platform_build,
		c_status_interface* status_interface);
	BCS_SHARED ~c_filesystem_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_tag_group*& group) const override;
	virtual BCS_RESULT get_group_by_file_extension(const char* file_extension, h_tag_group*& group) const;
	virtual BCS_RESULT get_tag_instances(h_tag_instance* const*& tag_instances, uint32_t& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_tag_group* const*& groups, uint32_t& group_count) const override;

	void try_open_tag_files();
	void try_open_single_tag_file(const wchar_t* filepath, const wchar_t* relative_filepath);

	BCS_RESULT read_tags();
protected:
	BCS_RESULT read_tag(const wchar_t* filepath, const wchar_t* relative_filepath, h_tag_instance*& out_tag, h_tag_group*& out_tag_group) const;
	BCS_RESULT read_tag_gen3(const wchar_t* filepath, h_tag_instance*& out_tag) const;
	static void read_tags_callback(s_filesystem_tag_project_read_tags_callback_data* userdata, int32_t index);

	wchar_t tags_directory[0x10000u];
	std::vector<h_tag_group*> groups;
	std::vector<h_tag_instance*> tags;

	struct s_tag_candidate
	{
		h_tag_group* group;
		const wchar_t* filepath;
		const wchar_t* relative_filepath;
	};
	std::vector<s_tag_candidate> candidates;
};
