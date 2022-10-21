#pragma once

class c_definition_tweaker
{
public:
	c_definition_tweaker();
	c_definition_tweaker(c_definition_tweaker const&) = delete;
	~c_definition_tweaker();

	void init();
	void deinit();
	void render_user_interface();
};
