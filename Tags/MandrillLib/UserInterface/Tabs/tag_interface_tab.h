#pragma once

class c_tag_interface_tab : 
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_tag_interface_tab);

	c_tag_interface_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent_tab);
	virtual ~c_tag_interface_tab();

	void game_quick_preview();

	inline c_tag_interface& get_tag_interface() const { return tag_interface; }
	inline c_cache_file& get_cache_file() const { return tag_interface.get_cache_file(); }

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl() override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_interface& tag_interface;

//	//void copy_data_recursively(const s_reflection_structure_type_legacy& reflection_type, char* source, char* destination);
//	void send_to_game();
//	c_tag_interface& get_tag_interface() const { return tag_interface; };
//	c_cache_file& get_cache_file() const { return cache_file; };
//	c_old_mandrill_gui_tab* GetParentTab() const { return parent_tab; };
//
//	void RenderButtons();
//protected:
//	virtual void render_tab_contents_gui();
//
//	c_cache_file& cache_file;
//	c_old_mandrill_gui_tab* parent_tab;
};
