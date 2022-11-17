#include "tagreflection-private-pch.h"

h_tag_reference::h_tag_reference(h_type* parent) :
	h_type(parent),
	tag_qualified(false),
	group_qualified(false),
	tag(nullptr),
	group(nullptr)
{
	file_path_without_extension = {};
	userdata = {};
	group_tag = {};
	tag = {};
	group = {};

}

h_tag_reference::h_tag_reference(const h_tag_reference& source) :
	h_type(parent),
	tag_qualified(false),
	group_qualified(false),
	tag_userdata(false),
	tag(nullptr),
	group(nullptr)
{
	file_path_without_extension = {};
	userdata = {};
	group_tag = {};
	tag = {};
	group = {};

	if (!source.tag_qualified && source.file_path_without_extension != nullptr)
	{
		file_path_without_extension = strdup(source.file_path_without_extension);
		group_tag = source.group_tag;
	}
}

h_tag_reference::~h_tag_reference()
{
	if (is_unqualified())
	{
		untracked_free(file_path_without_extension);
		file_path_without_extension = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}
}

void h_tag_reference::set_tag(h_tag* target_tag)
{
	if (is_unqualified())
	{
		untracked_free(file_path_without_extension);
		file_path_without_extension = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	if (target_tag)
	{
		tag = target_tag;
		group = target_tag->group;
		tag_qualified = true;
		group_qualified = true;
		tag_userdata = false;
	}
	else
	{
		tag = nullptr;
		//group = nullptr; // #NOTE: don't null the group to keep the tag reference data intact
		tag_qualified = false;
		group_qualified = false;
		tag_userdata = false;
	}
}

void h_tag_reference::set_unqualified_file_path_without_extension(::tag target_group_tag, const char* target_file_path_without_extension)
{
	if (is_unqualified())
	{
		untracked_free(file_path_without_extension);
		file_path_without_extension = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	tag = nullptr;
	group = nullptr;
	tag_qualified = false;
	group_qualified = false;
	tag_userdata = false;

	if (target_file_path_without_extension != nullptr)
	{
		file_path_without_extension = strdup(target_file_path_without_extension);
	}
	group_tag = target_group_tag;
}

void h_tag_reference::_set_unqualified_userdata(::tag target_group_tag, void* _userdata)
{
	if (is_unqualified())
	{
		untracked_free(file_path_without_extension);
		file_path_without_extension = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	tag = nullptr;
	group = nullptr;
	tag_qualified = false;
	group_qualified = false;
	tag_userdata = true;

	userdata = _userdata;
	group_tag = target_group_tag;
}

void h_tag_reference::set_group(h_group* target_group)
{
	if (group == target_group)
	{
		return;
	}

	userdata = nullptr;
	tag = nullptr;
	group = target_group;

	tag_qualified = false;
	group_qualified = true;
	tag_userdata = false;
}

void* h_tag_reference::_get_userdata() const
{
	return tag_userdata ? userdata : nullptr;
}

h_tag* h_tag_reference::get_tag() const
{
	return tag_qualified ? tag : nullptr;
}

h_group* h_tag_reference::get_group() const
{
	return group_qualified ? group : nullptr;
}

const char* h_tag_reference::get_file_path_without_extension() const
{
	if (tag_qualified)
	{
		ASSERT(tag != nullptr);
		return tag->get_file_path_without_extension();
	}
	else if (file_path_without_extension)
	{
		return file_path_without_extension;
	}
	return "";
}

tag h_tag_reference::get_group_tag() const
{
	if (group_qualified)
	{
		return group->tag_group.group_tag;
	}
	else
	{
		return group_tag;
	}
}

bool h_tag_reference::is_tag_qualified() const
{
	return tag_qualified;
}

bool h_tag_reference::is_null() const
{
	return !(tag_qualified || file_path_without_extension != nullptr);
}

bool h_tag_reference::is_unqualified() const
{
	return !tag_qualified;
}

void h_tag_reference::clear()
{
	if (is_unqualified())
	{
		untracked_free(file_path_without_extension);
		file_path_without_extension = nullptr;
		userdata = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	tag = nullptr;
	group = nullptr;
	tag_qualified = false;
	group_qualified = false;
	tag_userdata = false;
}
