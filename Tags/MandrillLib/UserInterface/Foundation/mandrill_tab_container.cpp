#include "mandrilllib-private-pch.h"

c_mandrill_tab_container::c_mandrill_tab_container(c_mandrill_tab* parent, bool allow_close) :
	on_selected(),
	on_selected_tree_change(),
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
	static std::mutex mutex;
	std::lock_guard lock(mutex);

	REFERENCE_ASSERT(tab);
	if (std::find(children.begin(), children.end(), &tab) == children.end())
	{
		children.push_back(&tab);

		tab.on_selected_tree_change.register_callback(this, [this](c_mandrill_tab& callee, c_mandrill_tab& target)
			{
				on_selected_tree_change(*static_cast<c_mandrill_tab*>(this), target);
			});
		tab.on_closed.register_callback(this, [this] (c_mandrill_tab& tab) 
			{ 
				this->remove_tab(tab); 
			});
	}
	on_tab_added(tab);
}

void c_mandrill_tab_container::remove_tab(c_mandrill_tab& tab)
{
	vector_erase_by_value_helper(children, &tab);
	on_tab_removed(tab);
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

	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (tab.is_enabled())
		{
			return true;
		}
	}
	return false;
}
