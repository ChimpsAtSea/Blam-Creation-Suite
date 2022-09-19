#include "graphicslib-private-pch.h"

c_graphics_swap_chain_d3d12::c_graphics_swap_chain_d3d12(
	c_graphics_d3d12& graphics,
	c_imgui_viewport_render_context& imgui_viewport_render_context,
	c_viewport& viewport,
	uint32_t num_back_buffers,
	const char* debug_name) :
	graphics(graphics),
	viewport(viewport),
	imgui_viewport_render_context(&imgui_viewport_render_context),
	window(nullptr),
	dxgi_swap_chain(),
	swap_chain_description(),
	num_back_buffers(num_back_buffers),
	current_back_buffer_index(0),
	window_resize_callback_handle()
{
	// Describe and create the swap chain.
	swap_chain_description.BufferCount = num_back_buffers;
	swap_chain_description.BufferDesc.Width = __max(1u, viewport.width);
	swap_chain_description.BufferDesc.Height = __max(1u, viewport.height);
	swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swap_chain_description.OutputWindow = NULL;
	swap_chain_description.SampleDesc.Count = 1;
	swap_chain_description.Windowed = FALSE;

	current_back_buffer_index = 0;
	viewport.on_size_changed.add_callback(window_resize_event, this, window_resize_callback_handle);
}

c_graphics_swap_chain_d3d12::c_graphics_swap_chain_d3d12(
		c_graphics_d3d12& graphics,
		c_window_windows& window,
		uint32_t num_back_buffers,
		const char* debug_name) :
	graphics(graphics),
	viewport(window),
	imgui_viewport_render_context(nullptr),
	window(&window),
	dxgi_swap_chain(),
	swap_chain_description(),
	num_back_buffers(num_back_buffers),
	current_back_buffer_index(0),
	window_resize_callback_handle()
{
	// Describe and create the swap chain.
	swap_chain_description.BufferCount = num_back_buffers;
	swap_chain_description.BufferDesc.Width = __max(1u, window.width);
	swap_chain_description.BufferDesc.Height = __max(1u, window.height);
	swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swap_chain_description.OutputWindow = window.window_handle;
	swap_chain_description.SampleDesc.Count = 1;
	swap_chain_description.Windowed = TRUE;

	IDXGISwapChain* dxgi_swap_chain_base = nullptr;
	graphics.dxgi_factory->CreateSwapChain(
		graphics.command_queue,        // Swap chain needs the queue so that it can force a flush on it.
		&swap_chain_description,
		&dxgi_swap_chain_base
	);
	if (dxgi_swap_chain_base == nullptr)
	{
		throw BCS_E_FAIL;
	}
	dxgi_swap_chain = interface_cast<IDXGISwapChain3*>(dxgi_swap_chain_base);
	if (dxgi_swap_chain == nullptr)
	{
		throw BCS_E_FAIL;
	}
	ULONG dxgi_swap_chain_base_reference_count = dxgi_swap_chain_base->Release();
	ASSERT(dxgi_swap_chain_base_reference_count == 1); // the reference to the swapchain should now be held in dxgi_swap_chain

	// #TODO: Support fullscreen transitions
	// disable fullscreen transitions
	HRESULT make_window_association_result = graphics.dxgi_factory->MakeWindowAssociation(window.window_handle, DXGI_MWA_NO_ALT_ENTER);
	ASSERT(SUCCEEDED(make_window_association_result));

	current_back_buffer_index = dxgi_swap_chain->GetCurrentBackBufferIndex();

	viewport.on_size_changed.add_callback(window_resize_event, this, window_resize_callback_handle);
}

c_graphics_swap_chain_d3d12::~c_graphics_swap_chain_d3d12()
{
	BCS_RESULT rs = viewport.on_size_changed.remove_callback(window_resize_callback_handle);
	BCS_FAIL_THROW(rs);

	ULONG dxgi_swap_chain_reference_count = dxgi_swap_chain->Release();
	ASSERT(dxgi_swap_chain_reference_count == 0);
}

BCS_RESULT c_graphics_swap_chain_d3d12::present()
{
	BCS_RESULT rs = BCS_S_OK;

	if (dxgi_swap_chain)
	{
		HRESULT present_result = dxgi_swap_chain->Present(1, 0);
		current_back_buffer_index = dxgi_swap_chain->GetCurrentBackBufferIndex();
	}
	else if(imgui_viewport_render_context)
	{
		if (BCS_FAILED(rs = imgui_viewport_render_context->present()))
		{
			return rs;
		}
		current_back_buffer_index = (current_back_buffer_index + 1) % num_back_buffers;
	}

	return rs;
}

void c_graphics_swap_chain_d3d12::window_resize_event(c_graphics_swap_chain_d3d12& _this, uint32_t width, uint32_t height)
{
	console_write_line(__FUNCTION__);
	_this.graphics.wait_for_frame_to_complete_cpu();

	_this.swap_chain_description.BufferDesc.Width = __max(1u, width);
	_this.swap_chain_description.BufferDesc.Height = __max(1u, height);

	_this.on_resize_start(width, height);

	if (_this.dxgi_swap_chain)
	{
		HRESULT resize_buffers_result = _this.dxgi_swap_chain->ResizeBuffers(
			_this.swap_chain_description.BufferCount,
			_this.swap_chain_description.BufferDesc.Width,
			_this.swap_chain_description.BufferDesc.Height,
			DXGI_FORMAT_UNKNOWN, 0);
		ASSERT(SUCCEEDED(resize_buffers_result));
	}

	_this.on_resize_finish(width, height);


	if (_this.dxgi_swap_chain)
	{
		_this.current_back_buffer_index = _this.dxgi_swap_chain->GetCurrentBackBufferIndex();
	}

	_this.graphics.wait_for_frame_to_complete_cpu();
}

uint32_t c_graphics_swap_chain_d3d12::get_current_back_buffer_index()
{
	return current_back_buffer_index;
}

BCS_DEBUG_API BCS_RESULT graphics_d3d12_swap_chain_create(
	c_graphics_d3d12* graphics,
	c_window_windows* window,
	uint32_t num_back_buffers,
	c_graphics_swap_chain_d3d12*& swap_chain,
	const char* debug_name)
{
	try
	{
		swap_chain = new() c_graphics_swap_chain_d3d12(
			*graphics,
			*window,
			num_back_buffers,
			debug_name);
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

BCS_DEBUG_API BCS_RESULT graphics_d3d12_swap_chain_create(
	c_graphics_d3d12* graphics,
	c_imgui_viewport_render_context* imgui_viewport_render_context,
	uint32_t num_back_buffers,
	c_graphics_swap_chain_d3d12*& swap_chain,
	const char* debug_name)
{
	c_viewport* viewport;
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = imgui_viewport_render_context->get_viewport(viewport)))
	{
		return rs;
	}
	try
	{
		swap_chain = new() c_graphics_swap_chain_d3d12(
			*graphics,
			*imgui_viewport_render_context,
			*viewport,
			num_back_buffers,
			debug_name);
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

BCS_DEBUG_API BCS_RESULT graphics_d3d12_swap_chain_destroy(c_graphics_swap_chain_d3d12* swap_chain)
{
	try
	{
		delete swap_chain;
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
