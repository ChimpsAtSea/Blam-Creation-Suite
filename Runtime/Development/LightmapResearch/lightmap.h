#pragma once

class c_lightmap
{
public:
	c_lightmap();
	~c_lightmap();

	void init(c_graphics& graphics);
	void deinit(c_graphics& graphics);
	void render_graphics();
	void render_pass_callback();
	void render_user_interface();
};