#pragma once

class s_cache_cluster_transplant_context;

class c_cache_file_tag_project :
	public c_tag_project
{
public:
	BCS_SHARED c_cache_file_tag_project(
		c_cache_cluster& cache_cluster,
		s_cache_cluster_transplant_context& cache_cluster_transplant_context,
		c_status_interface* status_interface);
	c_cache_file_tag_project(c_cache_file_tag_project const&) = delete;
	BCS_SHARED ~c_cache_file_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_tag_group*& group) const override;
	virtual BCS_RESULT get_tag_instances(h_tag_instance* const*& tag_instances, uint32_t& tag_instance_count) const override;
	virtual BCS_RESULT get_tag_groups(h_tag_group* const*& groups, uint32_t& group_count) const override;

protected:

	std::vector<h_tag_group*> groups;
	std::vector<h_tag_instance*> tags;
};
