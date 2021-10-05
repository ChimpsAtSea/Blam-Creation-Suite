#include "graphicslib-private-pch.h"
#include "pipeline_d3d12.pipeline_modes.inl"
#include "pipeline_d3d12.vertex_layout_descriptions.inl"

using namespace DirectX;

const char* pipeline_mode_to_string(e_pipeline_mode pipeline_mode)
{
	switch(pipeline_mode)
	{
		case _pipeline_mode_depth_only:					return "pipeline_mode_depth_only";
		case _pipeline_mode_wireframe:					return "pipeline_mode_wireframe";
		case _pipeline_mode_wireframe_line:				return "pipeline_mode_wireframe_line";
		case _pipeline_mode_opaque:						return "pipeline_mode_opaque";
		case _pipeline_mode_alpha_blend_backface:		return "pipeline_mode_alpha_blend_backface";
		case _pipeline_mode_alpha_blend_frontface:		return "pipeline_mode_alpha_blend_frontface";
		case _pipeline_mode_additive:					return "pipeline_mode_additive";
	}
	return nullptr;
}
