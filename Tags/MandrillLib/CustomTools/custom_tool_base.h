#pragma once

class c_custom_tool_base
{
protected:
	bool is_open = true;
	float content_height = 0.0f;
	const char* title = "custom Tool";
	float maximum_height = 260.0f;
public:
	void render();

protected:
	virtual void render_contents() = 0;
};