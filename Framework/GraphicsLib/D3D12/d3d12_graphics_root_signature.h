#pragma once

class c_graphics;

class c_graphics_root_signature_d3d12 :
	public c_graphics_register_layout
{
public:
	c_graphics_root_signature_d3d12() = delete;
	c_graphics_root_signature_d3d12(const c_graphics_root_signature_d3d12&) = delete;
	c_graphics_root_signature_d3d12& operator=(const c_graphics_root_signature_d3d12&) = delete;
	explicit c_graphics_root_signature_d3d12(
		c_graphics_d3d12& graphics,
		s_graphics_register_layout_description const* register_layout_descriptions,
		uint32_t num_register_layout_descriptions,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_root_signature_d3d12();

	c_graphics_d3d12& graphics;
	ID3D12RootSignature* root_signature;

	s_graphics_register_layout_description* register_layout_descriptions;
	uint32_t num_register_layout_descriptions;
	D3D12_ROOT_PARAMETER* root_parameters;
	D3D12_DESCRIPTOR_RANGE* descriptor_ranges;
	D3D12_STATIC_SAMPLER_DESC* static_samplers;
	D3D12_ROOT_SIGNATURE_DESC root_signature_description;
	unsigned int num_descriptor_table_ranges[num_graphics_register_layouts];
	unsigned int descriptor_table_bitmask;
	unsigned int num_descriptor_table_root_parameters;
	unsigned int num_descriptor_root_parameters;
	unsigned int total_static_samplers;
	unsigned int total_root_parameters;
	unsigned int total_descriptor_table_ranges;

	BCS_RESULT preprocess_register_layout_descriptions();
	BCS_RESULT init_root_signature_description();
	BCS_RESULT init_descriptor_table_root_descriptors();
	BCS_RESULT init_descriptor_root_descriptors();
	BCS_RESULT init_root_descriptor(const wchar_t* debug_name);
	virtual void bind_graphics() const override;
	virtual void bind_compute() const override;

	BCS_RESULT bind_descriptor_buffer(
		D3D12_ROOT_PARAMETER_TYPE target_root_parameter_type,
		unsigned int target_register_index,
		unsigned int target_register_space,
		c_graphics_buffer_d3d12& graphics_buffer) const;

	BCS_RESULT bind_descriptor_table_buffer(
		D3D12_DESCRIPTOR_RANGE_TYPE target_descriptor_range_type,
		unsigned int target_register_index,
		unsigned int target_register_space,
		c_graphics_buffer_d3d12& graphics_buffer) const;

	virtual BCS_RESULT bind_buffer(
		unsigned int register_layout_description_index,
		unsigned int register_layout_offset,
		c_graphics_buffer & graphics_buffer) const override;
	virtual BCS_RESULT bind_buffer(
		e_graphics_register_layout_semantic semantic, 
		unsigned int register_index, 
		unsigned int register_space, 
		c_graphics_buffer & graphics_buffer) const override;
};

BCS_RESULT graphics_d3d12_root_signature_create(
	c_graphics_d3d12* graphics,
	s_graphics_register_layout_description const* register_layout_descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_root_signature_d3d12*& root_signature,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_root_signature_destroy(c_graphics_root_signature_d3d12* root_signature);
