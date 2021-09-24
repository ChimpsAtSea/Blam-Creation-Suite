#pragma once

class c_hlsl_shader_d3d12;

class c_geometry_pipeline_d3d12
{
public:
	c_geometry_pipeline_d3d12(
		c_graphics_d3d12& graphics, 
		c_pipeline_signature_d3d12& pipeline_signature,
		c_hlsl_shader_d3d12* pixel_shader);
	~c_geometry_pipeline_d3d12();

	void init_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout);
	void init_pipeline_state();
	void deinit_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout);
	void deinit_pipeline_state();

	ID3D12PipelineState* get_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout) const;

protected:
	ID3D12PipelineState* depth_only_pipeline_state;
	ID3D12PipelineState* pipeline_states[k_number_of_vertex_layout_types][k_number_of_pipeline_modes];
	c_hlsl_shader_d3d12* pixel_shader;
	c_graphics_d3d12& graphics;
	c_pipeline_signature_d3d12& pipeline_signature;
};

