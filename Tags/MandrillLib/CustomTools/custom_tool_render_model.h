#pragma once

namespace blofeld
{
	namespace haloreach
	{
		struct s_object_struct_definition;
	}
}

class c_custom_tool_render_model :
	public c_custom_tool_base
{
public:
	c_custom_tool_render_model(c_cache_file& cache_file, blofeld::haloreach::s_object_struct_definition* object_struct_definition);
	~c_custom_tool_render_model();

protected:
	float scale = 1.0f;
	bool show_markers = false;
	bool show_default_variant = true;

	// #TODO: Replace with Viewport system
	ID3D11Texture2D* placeholder_texture = nullptr;
	ID3D11ShaderResourceView* shader_resource_view = nullptr;

	void init_placeholder_textures();
	virtual void render_contents() override final;
};
