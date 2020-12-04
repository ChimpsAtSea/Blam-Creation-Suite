#pragma once

class c_haloreach_cache_file;

namespace blofeld
{
	namespace haloreach
	{
		struct s_bitmap_block_struct;
	}
}

class c_blofeld_bitmap_viewer_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_blofeld_bitmap_viewer_tab);

	c_blofeld_bitmap_viewer_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent);
	virtual ~c_blofeld_bitmap_viewer_tab();


protected:
	static constexpr float k_field_display_name_width = 400.0f;

	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_interface& tag_interface;
	c_haloreach_cache_file& cache_file;
	v_tag_interface<blofeld::haloreach::s_bitmap_block_struct>& bitmap_tag;
	ID3D11Texture2D* texture;
	ID3D11ShaderResourceView* shader_resource_view;
};
