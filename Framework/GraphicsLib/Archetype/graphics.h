#pragma once

enum e_graphics_architecture
{
	_graphics_architecture_null,
	_graphics_architecture_d3d11,
	_graphics_architecture_d3d12,
	_graphics_architecture_d3d12_force_cpu,
	_graphics_architecture_d3d12_raytracing
};

class c_graphics
{
protected:
	c_graphics();
public:
	virtual ~c_graphics();

	virtual BCS_RESULT begin() = 0;
	virtual BCS_RESULT end() = 0;
	virtual BCS_RESULT execute() = 0;
	virtual BCS_RESULT start_debug_capture() = 0;
	virtual BCS_RESULT end_debug_capture() = 0;
	virtual BCS_RESULT start_debug_event(const char* event_name) = 0;
	virtual BCS_RESULT start_debug_event_ex(const char* event_name_format, ...) = 0;
	virtual BCS_RESULT start_debug_event_vargs(const char* event_name_format, va_list& virtual_argument_list) = 0;
	virtual BCS_RESULT end_debug_event() = 0;

	using t_present_callback_d3d12 = BCS_RESULT();
	c_typed_callback<t_present_callback_d3d12> present_callback;

	using t_render_callback_d3d12 = BCS_RESULT();
	c_typed_callback<t_render_callback_d3d12> render_callback;
};

BCS_DEBUG_API BCS_RESULT graphics_create(
	e_graphics_architecture architecture,
	bool use_debug_layer, 
	c_graphics*& graphics);
BCS_DEBUG_API BCS_RESULT graphics_destroy(c_graphics* graphics);
