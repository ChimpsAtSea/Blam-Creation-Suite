#pragma once
class c_material_d3d12
{
public:
	c_material_d3d12(c_graphics_d3d12* graphics, const char* material_filepath);
	~c_material_d3d12();

private:
	c_graphics_d3d12* graphics;
};

