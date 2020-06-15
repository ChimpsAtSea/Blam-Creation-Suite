#pragma once

class c_mandrill_tab :
	public c_mandrill_tab_container, public s_mandrill_dynamic_data, public c_mandrill_event_queue
{
public:
	non_copyconstructable(c_mandrill_tab);

	c_mandrill_tab(const char* title, const char* description, c_mandrill_tab* parent, bool allow_close = true);
	virtual ~c_mandrill_tab();

	void render(bool set_selected);
	void render_menu_gui();
	void render_file_dialogue_gui();
	void render_game_layer();

	const char* get_title() const { return title.c_str(); }
	const char* get_description() const { return description.c_str(); }

	template<typename t_tab>
	t_tab* search_parent_tab_type()
	{
		if (t_tab* tab = dynamic_cast<t_tab*>(parent))
		{
			return tab;
		}
		else if (parent == nullptr)
		{
			return nullptr;
		}
		else
		{
			return parent->search_parent_tab_type<t_tab>();
		}
	}

protected:
	virtual void render_impl() = 0;
	virtual void render_menu_gui_impl() = 0;
	virtual void render_file_dialogue_gui_impl() = 0;
	virtual void render_game_layer_impl() = 0;

	c_fixed_string_128 title;
	c_fixed_string_256 description;
	bool is_selected;
	bool allow_close;
	bool is_open;
	c_mandrill_tab* next_selected_tab;
};
