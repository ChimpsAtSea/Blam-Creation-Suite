#pragma once

class c_custom_tool_render_model :
	public c_custom_tool_base
{
public:
	c_custom_tool_render_model() :
		c_custom_tool_base()
	{
		title = "Render model";
		maximum_height = 500.0f;
		init_placeholder_textures();
	}
	~c_custom_tool_render_model()
	{
		placeholder_texture->Release();
		shader_resource_view->Release();
	}
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
