#include "tagreflection-private-pch.h"

h_tag_reference::h_tag_reference(h_type* parent) :
	h_type(parent),
	tag_qualified(false),
	tag(nullptr),
	group(nullptr)
{

}

h_tag_reference::h_tag_reference(const h_tag_reference& source) :
	h_type(parent),
	tag_qualified(false),
	tag(nullptr),
	group(nullptr)
{
	if (!source.tag_qualified && source.unqualified_path != nullptr)
	{
		unqualified_path = strdup(source.unqualified_path);
		group_tag = source.group_tag;
	}
}

h_tag_reference::~h_tag_reference()
{
	if (is_unqualified())
	{
		untracked_free(unqualified_path);
		unqualified_path = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}
}

void h_tag_reference::set_tag(h_tag* target_tag)
{
	if (is_unqualified())
	{
		untracked_free(unqualified_path);
		unqualified_path = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	if (target_tag)
	{
		tag = target_tag;
		group = target_tag->group;
		tag_qualified = true;
	}
	else
	{
		tag = nullptr;
		//group = nullptr; // #NOTE: don't null the group to keep the tag reference data intact
		tag_qualified = false;
	}
}

void h_tag_reference::set_unqualified_path(::tag target_group_tag, const char* target_unqualified_path)
{
	if (is_unqualified())
	{
		untracked_free(unqualified_path);
		unqualified_path = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	tag = nullptr;
	group = nullptr;
	tag_qualified = false;

	unqualified_path = strdup(target_unqualified_path);
	group_tag = target_group_tag;
}

void h_tag_reference::set_group(h_group* target_group)
{
	if (group == target_group)
	{
		return;
	}

	tag = nullptr;
	group = target_group;
}

h_tag* h_tag_reference::get_tag() const
{
	return tag_qualified ? tag : nullptr;
}

h_group* h_tag_reference::get_group() const
{
	return tag_qualified ? group : nullptr;
}

const char* h_tag_reference::get_tag_path() const
{
	if (tag_qualified)
	{
		ASSERT(tag != nullptr);
		return tag->tag_filepath;
	}
	else if (unqualified_path)
	{
		return unqualified_path;
	}
	return "";
}

tag h_tag_reference::get_group_tag() const
{
	if (tag_qualified)
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
	return !(tag_qualified || unqualified_path != nullptr);
}

bool h_tag_reference::is_unqualified() const
{
	return !tag_qualified && unqualified_path != nullptr;
}

void h_tag_reference::clear()
{
	if (is_unqualified())
	{
		untracked_free(unqualified_path);
		unqualified_path = nullptr;
		group_tag = blofeld::INVALID_TAG;
	}

	tag = nullptr;
	group = nullptr;
	tag_qualified = false;
}
