#pragma once

#ifdef __cplusplus

//#define USE_PIX
//#include <WinPixEventRuntime/pix3.h>

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

#include "HLSL/cpp_types.hlsli"
#include "directx_helpers.h"

#include "camera.h"
#include "debug_geometry.h"
#include "graphics_d3d12.h"
#include "constant_buffer_d3d12.h"
#include "constant_buffer_array_d3d12.h"
#include "pipeline_signature_d3d12.h"
#include "pipeline_d3d12.h"
#include "geometry_pipeline_d3d12.h"
#include "geometry_d3d12.h"
#include "texture_d3d12.h"
#include "material_d3d12.h"
#include "hlsl_shader_d3d12.h"

#include "PipelineSignatures/default_pipeline_signature_d3d12.h"
#include "PipelineSignatures/debug_geometry_pipeline_signature_d3d12.h"

#endif
