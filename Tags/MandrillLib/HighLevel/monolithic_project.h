#pragma once

class c_high_level_cache_cluster_transplant;
class h_tag;

class c_monolithic_tag_project :
	public c_tag_project
{
public:
	c_monolithic_tag_project(const wchar_t* directory, s_engine_platform_build engine_platform_build);
	~c_monolithic_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_group*& group) const override;
	virtual BCS_RESULT get_group_by_file_extension(const char* file_extension, h_group*& group) const;
	virtual BCS_RESULT get_tag_instances(h_tag* const*& tag_instances, unsigned long& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_group* const*& groups, unsigned long& group_count) const override;

	BCS_RESULT parse_tag_blob();
	h_tag* try_parse_tag_file(const wchar_t* filepath);

protected:
	wchar_t tag_cache_directory[0x10000];
	wchar_t blob_index_file_path[0x10000];
	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;
};
