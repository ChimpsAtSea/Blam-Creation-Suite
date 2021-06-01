#pragma once

class c_tag_group;
class c_tag_instance;

class c_tag_reader
{
public:
	c_tag_reader();
	virtual ~c_tag_reader();

	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, unsigned long& tag_group_count) = 0;
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, unsigned long& tag_instance_count) = 0;
};
