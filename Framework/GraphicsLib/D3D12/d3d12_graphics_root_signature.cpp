#include "graphicslib-private-pch.h"

c_graphics_root_signature_init_data_d3d12::c_graphics_root_signature_init_data_d3d12() :
	root_patameters(),
	descriptor_ranges(),
	static_samplers(),
	root_signature_description(),
	num_descriptor_table_ranges(),
	descriptor_table_bitmask(),
	num_descriptor_table_root_parameters(),
	num_descriptor_root_parameters(),
	total_static_samplers(),
	total_root_parameters(),
	total_descriptor_table_ranges()
{

}

c_graphics_root_signature_init_data_d3d12::~c_graphics_root_signature_init_data_d3d12()
{
	delete[] root_patameters;
	delete[] descriptor_ranges;
	delete[] static_samplers;
}

c_graphics_root_signature_d3d12::c_graphics_root_signature_d3d12(
	c_graphics_d3d12& graphics,
	s_graphics_register_layout_description* register_layout_descriptions,
	uint32_t num_layout_descriptions,
	const wchar_t* debug_name) :
	c_graphics_register_layout(),
	DEBUG_ONLY(c_graphics_root_signature_init_data_d3d12(),)
	graphics(graphics)
{
#ifdef _DEBUG
	c_graphics_root_signature_init_data_d3d12& init_data = *this;
#else
	c_graphics_root_signature_init_data_d3d12 init_data;
#endif

	BCS_RESULT preprocess_register_layout_descriptions_result = init_data.preprocess_register_layout_descriptions(register_layout_descriptions, num_layout_descriptions);
	BCS_FAIL_THROW(preprocess_register_layout_descriptions_result);

	BCS_RESULT init_root_signature_description_result = init_data.init_root_signature_description(register_layout_descriptions, num_layout_descriptions);
	BCS_FAIL_THROW(init_root_signature_description_result);

	BCS_RESULT create_root_descriptor_result = init_root_descriptor(init_data, debug_name);
	BCS_FAIL_THROW(create_root_descriptor_result);
}

c_graphics_root_signature_d3d12::~c_graphics_root_signature_d3d12()
{

}

BCS_RESULT c_graphics_root_signature_init_data_d3d12::preprocess_register_layout_descriptions(
	s_graphics_register_layout_description* register_layout_descriptions,
	uint32_t num_layout_descriptions)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int num_root_parameters[num_graphics_register_layouts] = {};
	descriptor_table_bitmask = 0;

	for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_layout_descriptions; layout_descriptor_index++)
	{
		s_graphics_register_layout_description& register_layout_description = register_layout_descriptions[layout_descriptor_index];

		if (register_layout_description.use_table)
		{
			switch (register_layout_description.semantic)
			{
			case _graphics_register_layout_sampler:
			case _graphics_register_layout_shader_resource:
			case _graphics_register_layout_unordered_access:
			case _graphics_register_layout_constant_buffer:
				num_descriptor_table_ranges[register_layout_description.semantic]++;
				total_descriptor_table_ranges++;
				descriptor_table_bitmask |= 1u << register_layout_description.semantic;
				break;
			case _graphics_register_layout_32bit_constant:
				console_write_line("Can't use 32bit constant inside of descriptor table");
				return BCS_E_INVALID_ARGUMENT;
			default:
				BCS_FAIL_THROW(BCS_E_UNSUPPORTED);
			}
		}
		else
		{
			switch (register_layout_description.semantic)
			{
			case _graphics_register_layout_sampler:
			{
				total_static_samplers++;
			}
			break;
			case _graphics_register_layout_32bit_constant:
			case _graphics_register_layout_shader_resource:
			case _graphics_register_layout_unordered_access:
			case _graphics_register_layout_constant_buffer:
			{
				num_root_parameters[register_layout_description.semantic]++;
				if (register_layout_description.register_count == 0)
				{
					console_write_line("Register count must be greater than zero");
					return BCS_E_INVALID_ARGUMENT;
				}
				total_root_parameters += register_layout_description.register_count;
			}
			break;
			default:
				return BCS_E_UNSUPPORTED;
			}
		}
	}

	num_descriptor_table_root_parameters = __popcnt(descriptor_table_bitmask);
	num_descriptor_root_parameters = total_root_parameters;
	total_root_parameters += num_descriptor_table_root_parameters; // root parameter required for each table

	return rs;
}

BCS_RESULT c_graphics_root_signature_init_data_d3d12::init_root_signature_description(
	s_graphics_register_layout_description* register_layout_descriptions,
	uint32_t num_layout_descriptions)
{
	root_patameters = new() D3D12_ROOT_PARAMETER[total_root_parameters]{};
	descriptor_ranges = new() D3D12_DESCRIPTOR_RANGE[total_descriptor_table_ranges];
	static_samplers = new() D3D12_STATIC_SAMPLER_DESC[total_static_samplers]{};

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_descriptor_table_root_descriptors(register_layout_descriptions, num_layout_descriptions)))
	{
		goto cleanup;
	}

	if (BCS_FAILED(rs = init_descriptor_root_descriptors(register_layout_descriptions, num_layout_descriptions)))
	{
		goto cleanup;
	}

	root_signature_description = {};
	root_signature_description.NumParameters = total_root_parameters;
	root_signature_description.pParameters = root_patameters;
	root_signature_description.NumStaticSamplers = total_static_samplers;
	root_signature_description.pStaticSamplers = static_samplers;
	root_signature_description.Flags = D3D12_ROOT_SIGNATURE_FLAG_NONE;
	root_signature_description.Flags = root_signature_description.Flags | D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

	return rs;

cleanup:

	delete[] root_patameters;
	delete[] descriptor_ranges;
	delete[] static_samplers;

	return rs;
}

BCS_RESULT c_graphics_root_signature_init_data_d3d12::init_descriptor_table_root_descriptors(
	s_graphics_register_layout_description* register_layout_descriptions,
	uint32_t num_layout_descriptions)
{
	if (descriptor_table_bitmask == 0)
	{
		return BCS_S_OK;
	}

	D3D12_ROOT_PARAMETER* descriptor_table_root_parameters_indirection[num_graphics_register_layouts]{};
	D3D12_DESCRIPTOR_RANGE* descriptor_ranges_indirection[num_graphics_register_layouts]{};

	{
		D3D12_DESCRIPTOR_RANGE* descriptor_ranges_position = descriptor_ranges;
		unsigned int indirection_index = 0;
		for (unsigned int register_layout_index = 0; register_layout_index < num_graphics_register_layouts; register_layout_index++)
		{
			if (unsigned int num_descriptor_table_range_entries = num_descriptor_table_ranges[register_layout_index])
			{
				D3D12_ROOT_PARAMETER* descriptor_table_root_parameter = root_patameters + indirection_index;

				descriptor_table_root_parameters_indirection[register_layout_index] = descriptor_table_root_parameter;
				descriptor_ranges_indirection[register_layout_index] = descriptor_ranges_position;

				descriptor_table_root_parameter->ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
				descriptor_table_root_parameter->DescriptorTable.pDescriptorRanges = descriptor_ranges_position;
				descriptor_table_root_parameter->DescriptorTable.NumDescriptorRanges = num_descriptor_table_range_entries;
				descriptor_table_root_parameter->ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

				descriptor_ranges_position += num_descriptor_table_range_entries;
				indirection_index++;
			}
		}
		ASSERT(indirection_index == num_descriptor_table_root_parameters);
		D3D12_DESCRIPTOR_RANGE* const descriptor_ranges_end = descriptor_ranges + total_descriptor_table_ranges;
		ASSERT(descriptor_ranges_position == descriptor_ranges_end);
		debug_point;
	}

	{
		unsigned int descriptor_table_layout_descriptor_index = 0;
		unsigned int descriptor_table_range_offsets[num_graphics_register_layouts] = {};
		for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_layout_descriptions; layout_descriptor_index++)
		{
			s_graphics_register_layout_description& register_layout_description = register_layout_descriptions[layout_descriptor_index];
			if (register_layout_description.use_table)
			{
				D3D12_DESCRIPTOR_RANGE& descriptor_range = *descriptor_ranges_indirection[register_layout_description.semantic];
				unsigned int descriptor_table_range_offset = descriptor_table_range_offsets[register_layout_description.semantic];

				switch (register_layout_description.semantic)
				{
				case _graphics_register_layout_sampler:
					descriptor_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
					break;
				case _graphics_register_layout_shader_resource:
					descriptor_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
					break;
				case _graphics_register_layout_unordered_access:
					descriptor_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
					break;
				case _graphics_register_layout_constant_buffer:
					descriptor_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
					break;
				case _graphics_register_layout_32bit_constant:
				default:
					BCS_FAIL_THROW(BCS_E_UNSUPPORTED);
				}

				descriptor_range.NumDescriptors = register_layout_description.register_count;
				descriptor_range.BaseShaderRegister = register_layout_description.register_index;
				descriptor_range.RegisterSpace = register_layout_description.register_space;
				descriptor_range.OffsetInDescriptorsFromTableStart = descriptor_table_range_offset;

				descriptor_table_range_offsets[register_layout_description.semantic]++;
				descriptor_ranges_indirection[register_layout_description.semantic]++;
				descriptor_table_layout_descriptor_index++;
			}
		}
		debug_point;
	}
}

BCS_RESULT c_graphics_root_signature_init_data_d3d12::init_descriptor_root_descriptors(
	s_graphics_register_layout_description* register_layout_descriptions,
	uint32_t num_layout_descriptions)
{
	if (num_descriptor_root_parameters == 0)
	{
		return BCS_S_OK;
	}

	D3D12_ROOT_PARAMETER* root_patameters_position = root_patameters + num_descriptor_table_root_parameters;
	D3D12_STATIC_SAMPLER_DESC* static_samplers_position = static_samplers;
	debug_point;

	for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_layout_descriptions; layout_descriptor_index++)
	{
		s_graphics_register_layout_description& register_layout_description = register_layout_descriptions[layout_descriptor_index];
		if (!register_layout_description.use_table)
		{
			for (unsigned int relative_register_offset = 0; relative_register_offset < register_layout_description.register_count; relative_register_offset++)
			{
				unsigned int shader_register = register_layout_description.register_index + relative_register_offset;
				if (register_layout_description.semantic == _graphics_register_layout_sampler)
				{
					D3D12_STATIC_SAMPLER_DESC& static_sampler = *static_samplers_position;

					static_samplers_position++;
				}
				else
				{
					D3D12_ROOT_PARAMETER& root_parameter = *root_patameters_position;

					switch (register_layout_description.semantic)
					{
					case _graphics_register_layout_shader_resource:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_SRV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						break;
					case _graphics_register_layout_unordered_access:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_UAV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						break;
					case _graphics_register_layout_constant_buffer:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						break;
					case _graphics_register_layout_32bit_constant:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
						root_parameter.Constants.ShaderRegister = shader_register;
						root_parameter.Constants.RegisterSpace = register_layout_description.register_space;
						root_parameter.Constants.Num32BitValues = register_layout_description.num_32_bit_values;
						break;
					case _graphics_register_layout_sampler:
					default:
						BCS_FAIL_THROW(BCS_E_UNSUPPORTED);
					}

					root_patameters_position++;
				}
			}
		}
	}
	debug_point;
}

BCS_RESULT c_graphics_root_signature_d3d12::init_root_descriptor(c_graphics_root_signature_init_data_d3d12& init_data, const wchar_t* debug_name)
{
	BCS_RESULT rs = BCS_S_OK;

	ID3DBlob* root_signature_blob = nullptr;
	ID3DBlob* root_signature_error_blob = nullptr;
	HRESULT serialize_root_signature_result = D3D12SerializeRootSignature(&init_data.root_signature_description, D3D_ROOT_SIGNATURE_VERSION_1_0, &root_signature_blob, &root_signature_error_blob);
	if (root_signature_error_blob)
	{
		// #TODO: Handle the error

		rs = BCS_E_GRAPHICS_HRESULT_ERROR;

		size_t error_buffer_size = root_signature_error_blob->GetBufferSize();
		LPVOID error_buffer_data = root_signature_error_blob->GetBufferPointer();

		char* error_string = static_cast<char*>(tracked_malloca(error_buffer_size + 1));

		memcpy(error_string, error_buffer_data, error_buffer_size);
		error_string[error_buffer_size] = 0;

		trim(error_string);

		console_write_line_with_debug("SerializeRootSignature: '%s'", error_string);

		tracked_freea(error_string);

		root_signature_error_blob->Release();
	}
	ASSERT(SUCCEEDED(serialize_root_signature_result));
	HRESULT create_root_signature_result = graphics.device->CreateRootSignature(0, root_signature_blob->GetBufferPointer(), root_signature_blob->GetBufferSize(), IID_PPV_ARGS(&root_signature));
	ASSERT(SUCCEEDED(create_root_signature_result));
	root_signature_blob->Release();

	graphics.set_object_debug_name(debug_name, L"c_graphics_root_signature_d3d12::root_signature", root_signature);

	return rs;
}

BCS_RESULT graphics_d3d12_root_signature_create(
	c_graphics_d3d12* graphics,
	s_graphics_register_layout_description* descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_root_signature_d3d12*& root_signature,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		root_signature = new() c_graphics_root_signature_d3d12(
			*graphics,
			descriptions,
			num_layout_descriptions,
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

BCS_RESULT graphics_d3d12_root_signature_destroy(c_graphics_root_signature_d3d12* root_signature)
{
	try
	{
		delete root_signature;
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
