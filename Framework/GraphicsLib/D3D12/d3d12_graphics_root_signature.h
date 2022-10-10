#pragma once

class c_graphics;

class c_graphics_root_signature_init_data_d3d12
{
public:
	c_graphics_root_signature_init_data_d3d12();
	~c_graphics_root_signature_init_data_d3d12();

	D3D12_ROOT_PARAMETER* root_patameters;
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

	BCS_RESULT preprocess_register_layout_descriptions(
		s_graphics_register_layout_description* register_layout_descriptions,
		uint32_t num_layout_descriptions);
	BCS_RESULT init_root_signature_description(
		s_graphics_register_layout_description* register_layout_descriptions,
		uint32_t num_layout_descriptions);
	BCS_RESULT init_descriptor_table_root_descriptors(
		s_graphics_register_layout_description* register_layout_descriptions,
		uint32_t num_layout_descriptions);
	BCS_RESULT init_descriptor_root_descriptors(
		s_graphics_register_layout_description* register_layout_descriptions,
		uint32_t num_layout_descriptions);
};

class c_graphics_root_signature_d3d12 :
	public c_graphics_register_layout
	DEBUG_ONLY(, public c_graphics_root_signature_init_data_d3d12)
{
public:
	c_graphics_root_signature_d3d12() = delete;
	c_graphics_root_signature_d3d12(const c_graphics_root_signature_d3d12&) = delete;
	c_graphics_root_signature_d3d12& operator=(const c_graphics_root_signature_d3d12&) = delete;
	explicit c_graphics_root_signature_d3d12(
		c_graphics_d3d12& graphics,
		s_graphics_register_layout_description* descriptions,
		uint32_t num_descriptions,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_root_signature_d3d12();

	c_graphics_d3d12& graphics;
	ID3D12RootSignature* root_signature;

	BCS_RESULT init_root_descriptor(c_graphics_root_signature_init_data_d3d12& init_data, const wchar_t* debug_name);
};

BCS_RESULT graphics_d3d12_root_signature_create(
	c_graphics_d3d12* graphics,
	s_graphics_register_layout_description* descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_root_signature_d3d12*& root_signature,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_root_signature_destroy(c_graphics_root_signature_d3d12* root_signature);
