#pragma once

class c_tag_group
{
public:

	virtual BCS_RESULT get_group_tag(tag& group_tag) const = 0;
	virtual BCS_RESULT get_group_name(const char*& group_name) const = 0;
	virtual BCS_RESULT get_group_short_name(const char*& group_short_name) const = 0;
	virtual BCS_RESULT get_blofeld_tag_group(blofeld::s_tag_group const*& blofeld_tag_group) const = 0;
};

