#pragma once

class c_mandrill_tab;

class c_mandrill_tab_container
{
public:
	non_copyconstructable(c_mandrill_tab_container);

	c_mandrill_tab_container(c_mandrill_tab* parent, bool allow_close = true);
	virtual ~c_mandrill_tab_container();

	virtual void add_tab(c_mandrill_tab& tab);
	virtual void remove_tab(c_mandrill_tab& tab);
	virtual bool is_enabled() const;
	bool has_enabled_children() const;
	bool is_selected() const { return _is_selected; }
	bool allow_close() const { return _allow_close; }
	bool is_open() const { return _is_open; }
	c_callback<void(c_mandrill_tab& callee)> on_selected;
	c_callback<void(c_mandrill_tab& callee, c_mandrill_tab& target)> on_selected_tree_change;
	c_callback<void(c_mandrill_tab& callee)> on_tab_added;
	c_callback<void(c_mandrill_tab& callee)> on_tab_removed;
	c_callback<void(c_mandrill_tab& callee)> on_closed;

	inline c_mandrill_tab* get_parent() const { return parent; }
	inline c_mandrill_tab* get_child(uint32_t index) const { return children[index]; }
	inline c_mandrill_tab*const* get_children() const { return children.data(); }
	inline uint32_t get_child_count() const { return static_cast<uint32_t>(children.size()); }

protected:
	bool _is_selected;
	bool _allow_close;
	bool _is_open;
	c_mandrill_tab* parent;
	std::vector<c_mandrill_tab*> children;
};
