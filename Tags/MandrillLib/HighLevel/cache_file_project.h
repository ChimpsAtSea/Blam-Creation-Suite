#pragma once

class c_high_level_cache_cluster_transplant;
class h_tag;

class c_cache_file_tag_project :
	public c_tag_project
{
public:
	BCS_SHARED c_cache_file_tag_project(
		c_high_level_cache_cluster_transplant& transplant, 
		c_status_interface* status_interface);
	BCS_SHARED ~c_cache_file_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_group*& group) const override;
	virtual BCS_RESULT get_tag_instances(h_tag* const*& tag_instances, uint32_t& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_group* const*& groups, uint32_t& group_count) const override;

protected:

	std::vector<h_group*> groups;
	std::vector<h_tag*> tags;
};

