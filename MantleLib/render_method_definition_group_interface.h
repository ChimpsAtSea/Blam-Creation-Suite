#pragma once
class c_render_method_definition_group_interface :
	public c_legacy_tag_group_interface
{
public:
	friend class c_cache_file;
	friend class c_mantle_cache_file_gui_tab;
	friend class c_tag_interface;

	c_render_method_definition_group_interface(c_cache_file& cache_file, uint16_t group_index);
	virtual ~c_render_method_definition_group_interface();

	std::map<c_tag_interface*, std::vector<c_tag_interface*>> shader_definition_and_rmt2;
};

