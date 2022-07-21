#pragma once

class c_high_level_cache_cluster_transplant;
class h_tag;

class c_tag_project
{
public:
	s_engine_platform_build engine_platform_build;
	c_status_interface* status_interface;

	c_tag_project(
		s_engine_platform_build engine_platform_build,
		c_status_interface* status_interface);
	virtual ~c_tag_project();

	virtual BCS_RESULT get_group_by_group_tag(tag group_tag, h_group*& group) const = 0;
	virtual BCS_RESULT get_tag_instances(h_tag* const*& tag_instances, uint32_t& tag_instance_count) const = 0;
	virtual BCS_RESULT get_tag_groups(h_group* const*& groups, uint32_t& group_count) const = 0;

	BCS_RESULT resolve_unqualified_tags() const;
	BCS_RESULT resolve_unqualified_tag_references(h_prototype& object) const;
	bool resolve_tag_reference(tag group_tag, h_tag_reference& tag_reference, const char* target_file_path_without_extension) const;
};
