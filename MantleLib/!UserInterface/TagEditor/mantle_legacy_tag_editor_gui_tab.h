#pragma once

class c_mantle_legacy_tag_editor_gui_tab :
	public c_mantle_gui_tab
{
public:
	c_mantle_legacy_tag_editor_gui_tab() = delete;
	c_mantle_legacy_tag_editor_gui_tab(const c_mantle_legacy_tag_editor_gui_tab&) = delete;
	c_mantle_legacy_tag_editor_gui_tab& operator=(const c_mantle_legacy_tag_editor_gui_tab&) = delete;

	c_mantle_legacy_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface);
	virtual ~c_mantle_legacy_tag_editor_gui_tab();

	static void increment_recursion();
	static void decrement_recursion();

	c_mantle_gui_tab* GetParentTab() const { return parent_tab; }

	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tab;
	c_tag_interface& tag_interface;
protected:
	void render_tab_contents_gui() override;

public:
	static constexpr float recursion_padding_amount = 25.0f;
	static int g_current_recursion_depth;
	static float g_current_recursion_padding;
	static thread_local c_mantle_legacy_tag_editor_gui_tab* g_current_mantle_tag_tab;
};

template<e_legacy_primitive_type primitive_type, typename T>
void render_primitive_gui_legacy(void* field_data, const c_reflection_field& reflection_field);

void render_tagref_gui_legacy(s_tag_reference_legacy* field_data, const char* name, c_cache_file& cache_file);
void render_tagref_gui_legacy(s_tag_reference_legacy* field_data, const c_reflection_field& reflection_field);
void render_tagblock_gui_legacy(void* field_data, const c_reflection_field& reflection_field);
void render_struct_gui_legacy(void* field_data, const c_reflection_field& reflection_field);
void render_stringid_gui_legacy(string_id_legacy* field_data, const c_reflection_field& reflection_field);
void render_enum_gui_legacy(void* field_data, const c_reflection_field& reflection_field);
void render_dataref_gui_legacy(s_data_reference_legacy* field_data, const c_reflection_field& reflection_field);
void render_bitfield_gui_legacy(void* field_data, const c_reflection_field& reflection_field);

