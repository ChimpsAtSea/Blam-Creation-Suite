#include "graphicslib-private-pch.h"

BCS_SHARED const char* register_layout_semantic_to_string(e_graphics_register_layout_semantic register_layout_semantic)
{
	switch (register_layout_semantic)
	{
		case _graphics_register_layout_shader_resource:
			return "t";
		case _graphics_register_layout_unordered_access:
			return "u";
		case _graphics_register_layout_sampler:
			return "s";
		case _graphics_register_layout_constant_buffer:
		case _graphics_register_layout_32bit_constant:
			return "b";
	}
	return nullptr;
}

c_graphics_register_layout::c_graphics_register_layout()
{

}

c_graphics_register_layout::~c_graphics_register_layout()
{

}

BCS_SHARED BCS_RESULT graphics_register_layout_create(
	c_graphics* graphics,
	e_graphics_register_layout_type root_signature_type,
	s_graphics_register_layout_description const* register_layout_descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_register_layout*& register_layout,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_root_signature_create(
			graphics_d3d12,
			root_signature_type,
			register_layout_descriptions,
			num_layout_descriptions,
			*reinterpret_cast<c_graphics_root_signature_d3d12**>(&register_layout),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_SHARED BCS_RESULT graphics_register_layout_destroy(c_graphics_register_layout* register_layout)
{
	BCS_VALIDATE_ARGUMENT(register_layout != nullptr);

	if (c_graphics_root_signature_d3d12* root_signature_d3d12 = dynamic_cast<c_graphics_root_signature_d3d12*>(register_layout))
	{
		return graphics_d3d12_root_signature_destroy(root_signature_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
