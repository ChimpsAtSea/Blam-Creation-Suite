#pragma once

class c_mandrill_tab;

class c_mandrill_tab_container
{
public:
	c_mandrill_tab_container() = delete;
	c_mandrill_tab_container(c_mandrill_tab_container const&) = delete;
	c_mandrill_tab_container& operator=(c_mandrill_tab_container const&) = delete;

	c_mandrill_tab_container(c_mandrill_tab* parent, bool allow_close = true);
	virtual ~c_mandrill_tab_container();

	virtual void add_tab(c_mandrill_tab& tab);
	virtual void remove_tab(c_mandrill_tab& tab);
	virtual bool is_enabled() const;
	bool has_enabled_children() const;
	bool is_selected() const { return _is_selected; }
	bool allow_close() const { return _allow_close; }
	bool is_open() const { return _is_open; }

	using t_on_selected_callback = void(c_mandrill_tab& callee);
	using t_on_tab_added_callback = void(c_mandrill_tab& callee);
	using t_on_tab_removed_callback = void(c_mandrill_tab& callee);
	using t_on_closed_callback = void(c_mandrill_tab& callee);

	c_typed_callback<t_on_selected_callback> on_selected;
	c_typed_callback<t_on_tab_added_callback> on_tab_added;
	c_typed_callback<t_on_tab_removed_callback> on_tab_removed;
	c_typed_callback<t_on_closed_callback> on_closed;

	inline c_mandrill_tab* get_parent() const { return parent; }
	inline c_mandrill_tab* get_child(uint32_t index) const { return children[index]; }
	inline c_mandrill_tab*const* get_children() const { return children.data(); }
	inline uint32_t get_child_count() const { return static_cast<unsigned long>(children.size()); }

protected:
	bool _is_selected;
	bool _allow_close;
	bool _is_open;
	c_mandrill_tab* parent;
	std::vector<c_mandrill_tab*> children;
};
