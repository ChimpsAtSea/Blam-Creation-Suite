#pragma once

class c_tag_group;
class c_tag_instance;

class c_tag_reader
{
public:
	c_tag_reader();
	virtual ~c_tag_reader();

	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, uint32_t& tag_group_count) = 0;
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, uint32_t& tag_instance_count) = 0;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& tag_instance) = 0;
	virtual BCS_RESULT resolve_string_id(string_id string_identifier, const char*& string) const = 0;
};
