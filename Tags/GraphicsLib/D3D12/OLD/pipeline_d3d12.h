#pragma once

class c_hlsl_shader_d3d12;

enum e_pipeline_mode
{
	_pipeline_mode_depth_only = -1,
	_pipeline_mode_wireframe,
	_pipeline_mode_wireframe_line,
	_pipeline_mode_opaque,
	_pipeline_mode_alpha_blend_backface,
	_pipeline_mode_alpha_blend_frontface,
	_pipeline_mode_additive,
	k_number_of_pipeline_modes
};
const char* pipeline_mode_to_string(e_pipeline_mode pipeline_mode);

struct s_vertex_layout_description
{
	D3D12_INPUT_ELEMENT_DESC* input_element_descriptions;
	unsigned long input_element_description_count;
};
extern D3D12_INPUT_ELEMENT_DESC p_vertex_layout_descriptions[];
extern D3D12_INPUT_ELEMENT_DESC pc_vertex_layout_descriptions[];
extern D3D12_INPUT_ELEMENT_DESC ptcn_vertex_layout_descriptions[];
extern s_vertex_layout_description vertex_layout_descriptions[k_number_of_vertex_layout_types];

struct s_pipeline_mode_description
{

};
extern s_pipeline_mode_description opaque_pipeline_mode;
extern s_pipeline_mode_description alpha_blend_backface_pipeline_mode;
extern s_pipeline_mode_description alpha_blend_frontface_pipeline_mode;
extern s_pipeline_mode_description additive_pipeline_mode;
extern s_pipeline_mode_description* pipeline_modes[k_number_of_pipeline_modes];
