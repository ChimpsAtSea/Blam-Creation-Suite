#pragma once

class c_mandrill_blofeld_tag_editor_gui_tab :
	public c_mandrill_gui_tab
{
public:
	c_mandrill_blofeld_tag_editor_gui_tab() = delete;
	c_mandrill_blofeld_tag_editor_gui_tab(const c_mandrill_blofeld_tag_editor_gui_tab&) = delete;
	c_mandrill_blofeld_tag_editor_gui_tab& operator=(const c_mandrill_blofeld_tag_editor_gui_tab&) = delete;

	c_mandrill_blofeld_tag_editor_gui_tab(c_cache_file& cache_file, c_mandrill_gui_tab* parent_tab, c_tag_interface& tag_interface);
	virtual ~c_mandrill_blofeld_tag_editor_gui_tab();

	uint32_t render_tag_struct_definition(char* data, const blofeld::s_tag_struct_definition& struct_definition);
	uint32_t render_tag_group(char* data, const blofeld::s_tag_group& group);
	c_cache_file& cache_file;
	c_mandrill_gui_tab* parent_tab;
	c_tag_interface& tag_interface;
protected:
	void render_tab_contents_gui() override;
};
