#pragma once

class c_blofeld_tag_definition_debug_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_blofeld_tag_definition_debug_tab);

	c_blofeld_tag_definition_debug_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent);
	virtual ~c_blofeld_tag_definition_debug_tab();

	c_tag_interface& get_tag_interface() const { return tag_interface; }
	c_cache_file& get_cache_file() const { return tag_interface.get_cache_file(); }

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_interface& tag_interface;

	uint32_t render_tag_struct_definition(int level, char* data, const blofeld::s_tag_struct_definition& struct_definition);
	uint32_t render_tag_group(char* data, const blofeld::s_tag_group& group);
};
