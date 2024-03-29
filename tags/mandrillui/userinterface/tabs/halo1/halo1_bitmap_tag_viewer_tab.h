#pragma once

class c_halo1_bitmap_tag_viewer_tab;

#ifdef HIGH_LEVEL_HALO1_PC64

class c_halo1_bitmap_tag_viewer_tab :
	public c_mandrill_tab
{
public:
	c_halo1_bitmap_tag_viewer_tab() = delete;
	c_halo1_bitmap_tag_viewer_tab(c_halo1_bitmap_tag_viewer_tab const&) = delete;
	c_halo1_bitmap_tag_viewer_tab& operator=(c_halo1_bitmap_tag_viewer_tab const&) = delete;

	c_halo1_bitmap_tag_viewer_tab(c_tag_project& tag_project, blofeld::halo1::pc64::h_bitmap_definition& halo1_bitmap_tag, c_mandrill_tab& parent);
	virtual ~c_halo1_bitmap_tag_viewer_tab();

	c_tag_project& get_tag_project() const;
	blofeld::halo1::pc64::h_bitmap_definition& get_tag() const;

protected:
	virtual void render_impl() override final;
	virtual bool render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	void render_bitmap_enumerable(h_enumerable& enumerable);
	void render_bitmap(int32_t index, blofeld::halo1::pc64::h_bitmap_data& bitmap_data);

	c_tag_project& tag_project;
	blofeld::halo1::pc64::h_bitmap_definition& halo1_bitmap_tag;
};

#endif
