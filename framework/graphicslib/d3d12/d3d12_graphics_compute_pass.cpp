#include "graphicslib-private-pch.h"

c_graphics_compute_pass_d3d12::c_graphics_compute_pass_d3d12(
	c_graphics_d3d12& graphics,
	const wchar_t* debug_name) :
	graphics(graphics)
{
}

c_graphics_compute_pass_d3d12::~c_graphics_compute_pass_d3d12()
{
}

void c_graphics_compute_pass_d3d12::execute()
{
	ID3D12GraphicsCommandList1* command_list = graphics.command_list;

	render_callback();
}

BCS_RESULT graphics_d3d12_compute_pass_create(
	c_graphics_d3d12* graphics,
	c_graphics_compute_pass_d3d12*& compute_pass,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		compute_pass = new() c_graphics_compute_pass_d3d12(
			*graphics,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_compute_pass_destroy(c_graphics_compute_pass_d3d12* compute_pass)
{
	try
	{
		delete compute_pass;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
