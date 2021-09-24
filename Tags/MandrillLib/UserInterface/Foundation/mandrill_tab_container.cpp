#include "mandrilllib-private-pch.h"

c_mandrill_tab_container::c_mandrill_tab_container(c_mandrill_tab* parent, bool allow_close) :
	on_selected(),
	on_tab_added(),
	on_tab_removed(),
	on_closed(),
	_is_selected(false),
	_allow_close(allow_close),
	_is_open(true),
	parent(parent),
	children()
{

}

c_mandrill_tab_container::~c_mandrill_tab_container()
{

}

void c_mandrill_tab_container::add_tab(c_mandrill_tab& tab)
{
	REFERENCE_ASSERT(tab);
	if (std::find(children.begin(), children.end(), &tab) == children.end())
	{
		children.push_back(&tab);

		console_write_line("#TODO: implement c_mandrill_tab_container::add_tab callbacks!!!");
	}
	on_tab_added(&tab);
}

void c_mandrill_tab_container::remove_tab(c_mandrill_tab& tab)
{
	vector_erase_by_value_helper(children, &tab);
	on_tab_removed(&tab);
}

bool c_mandrill_tab_container::is_enabled() const
{
	return true;
}

bool c_mandrill_tab_container::has_enabled_children() const
{
	if (children.empty())
	{
		return false;
	}

	for (c_mandrill_tab* tab : children)
	{
		if (tab->is_enabled())
		{
			return true;
		}
	}
	return false;
}
