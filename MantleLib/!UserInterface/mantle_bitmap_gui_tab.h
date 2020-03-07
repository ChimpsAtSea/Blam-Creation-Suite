#pragma once
class c_mantle_bitmap_gui_tab : 
	public c_mantle_gui_tab
{
public:
	c_mantle_bitmap_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tag, v_tag_interface<s_bitmap_definition>& bitmap_tag_interface);
	virtual ~c_mantle_bitmap_gui_tab();

	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tag;
	v_tag_interface<s_bitmap_definition>& bitmap_tag_interface;


	ID3D11Texture2D* pTexture;
	ID3D11ShaderResourceView* shader_resource_view;
	char* dds_texture_buffer;
	char* decompressed_buffer;
protected:
	void render_tab_contents_gui() override;
};

