#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_tag_gui_tab : public c_mantle_gui_tab
{
public:
	static void increment_recursion();
	static void decrement_recursion();
	c_mantle_tag_gui_tab(c_cache_file& cache_file, c_tag_interface& tag_interface, c_mantle_gui_tab* parent_tag);
	virtual ~c_mantle_tag_gui_tab();

	void copy_data_recursively(const s_reflection_structure_type& reflection_type, char* source, char* destination);
	void poke();
	c_tag_interface& get_tag_interface() const { return tag_interface; };
	c_cache_file& get_cache_file() const { return cache_file; };
	c_mantle_gui_tab* GetParentTab() const { return parent_tab; };

	void RenderButtons();
protected:
	virtual void render_tab_contents_gui();
	void render_tab_contents_gui_impl();

	c_tag_interface& tag_interface;
	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tab;

public:
	static constexpr float recursion_padding_amount = 25.0f;
	static int g_current_recursion_depth;
	static float g_current_recursion_padding;
	static thread_local c_mantle_tag_gui_tab* g_current_mantle_tag_tab;
};
