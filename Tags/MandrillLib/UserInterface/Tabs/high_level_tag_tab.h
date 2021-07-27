#pragma once

class c_haloreach_cache_file;

class c_high_level_tag_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_high_level_tag_tab);

	c_high_level_tag_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent);
	virtual ~c_high_level_tag_tab();

	c_tag_project& get_tag_project() const;
	h_tag& get_tag() const;

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_project& tag_project;
	h_tag& tag;
};
