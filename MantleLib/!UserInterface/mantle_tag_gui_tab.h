#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_tag_gui_tab : public c_mantle_gui_tab
{
public:
	c_mantle_tag_gui_tab() = delete;
	c_mantle_tag_gui_tab(const c_mantle_tag_gui_tab&) = delete;
	c_mantle_tag_gui_tab& operator=(const c_mantle_tag_gui_tab&) = delete;

	c_mantle_tag_gui_tab(c_cache_file& cache_file, c_tag_interface& tag_interface, c_mantle_gui_tab* parent_tag);
	virtual ~c_mantle_tag_gui_tab();

	static void increment_recursion();
	static void decrement_recursion();

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

template<e_primitive_type primitive_type, typename T>
void render_primitive_gui(void* field_data, const c_reflection_field& reflection_field);

void render_tagref_gui(TagReference* field_data, const char* name, c_cache_file& cache_file);
void render_tagref_gui(TagReference* field_data, const c_reflection_field& reflection_field);
void render_tagblock_gui(void* field_data, const c_reflection_field& reflection_field);
void render_struct_gui(void* field_data, const c_reflection_field& reflection_field);
void render_stringid_gui(string_id* field_data, const c_reflection_field& reflection_field);
void render_enum_gui(void* field_data, const c_reflection_field& reflection_field);
void render_dataref_gui(DataReference* field_data, const c_reflection_field& reflection_field);
void render_bitfield_gui(void* field_data, const c_reflection_field& reflection_field);
