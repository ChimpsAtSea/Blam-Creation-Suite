#pragma once

#include "d3d12_gpu_data_structures.h"
#include "d3d12_graphics_texture.h"
#include "d3d12_graphics_geometry.h"
#include "d3d12_graphics_render_target.h"
#include "d3d12_graphics_render_pass.h"
#include "d3d12_graphics_compute_pass.h"
#include "d3d12_graphics_shader_pipeline.h"
#include "d3d12_graphics_shader_binary.h"
#include "d3d12_graphics_buffer.h"
#include "d3d12_graphics_swap_chain.h"
#include "d3d12_graphics_camera.h"
#include "d3d12_graphics_vertex_layout.h"
#include "d3d12_graphics_root_signature.h"
#include "d3d12_graphics_render_instance.h"
#include "d3d12_graphics.h"

#include "d3d12_imgui_context.h"

#include "descriptor_heap_d3d12.h"
#include "descriptor_heap_allocator_d3d12.h"

template<typename T, typename Tx>
T interface_cast(Tx* base)
{
	T result = nullptr;
	if (base)
	{
		base->QueryInterface(IID_PPV_ARGS(&result));
	}
	return result;
}
