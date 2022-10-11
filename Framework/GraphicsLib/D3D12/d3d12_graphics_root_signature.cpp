#include "graphicslib-private-pch.h"

c_graphics_root_signature_d3d12::c_graphics_root_signature_d3d12(
	c_graphics_d3d12& graphics,
	e_graphics_register_layout_type _root_signature_type,
	s_graphics_register_layout_description const* _register_layout_descriptions,
	uint32_t _num_register_layout_descriptions,
	const wchar_t* debug_name) :
	c_graphics_register_layout(),
	graphics(graphics),
	root_signature(),
	root_signature_type(_root_signature_type),
	register_layout_descriptions(nullptr),
	num_register_layout_descriptions(_num_register_layout_descriptions),
	root_parameters(),
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
#ifdef _DEBUG
	c_graphics_root_signature_d3d12& init_data = *this;
#else
	c_graphics_root_signature_d3d12 init_data;
#endif

	if (num_register_layout_descriptions > 0)
	{
		register_layout_descriptions = new() s_graphics_register_layout_description[num_register_layout_descriptions];
		memcpy(register_layout_descriptions, _register_layout_descriptions, sizeof(*register_layout_descriptions) * num_register_layout_descriptions);

		BCS_RESULT preprocess_register_layout_descriptions_result = init_data.preprocess_register_layout_descriptions();
		if (BCS_FAILED(preprocess_register_layout_descriptions_result))
		{
			delete[] register_layout_descriptions;
		}
		BCS_FAIL_THROW(preprocess_register_layout_descriptions_result);

		BCS_RESULT init_root_signature_description_result = init_data.init_root_signature_description();
		if (BCS_FAILED(init_root_signature_description_result))
		{
			delete[] register_layout_descriptions;
		}
		BCS_FAIL_THROW(init_root_signature_description_result);
	}

	BCS_RESULT create_root_descriptor_result = init_root_descriptor(debug_name);
	if (BCS_FAILED(create_root_descriptor_result))
	{
		if (register_layout_descriptions)
		{
			delete[] register_layout_descriptions;
		}
	}
	BCS_FAIL_THROW(create_root_descriptor_result);
}

c_graphics_root_signature_d3d12::~c_graphics_root_signature_d3d12()
{
	delete[] register_layout_descriptions;
	delete[] root_parameters;
	delete[] descriptor_ranges;
	delete[] static_samplers;

	UINT root_signature_reference_count = root_signature->Release();
	ASSERT(root_signature_reference_count == 0);
}

BCS_RESULT c_graphics_root_signature_d3d12::preprocess_register_layout_descriptions()
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int num_root_parameters[num_graphics_register_layouts] = {};
	descriptor_table_bitmask = 0;

	for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_register_layout_descriptions; layout_descriptor_index++)
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
				return BCS_E_UNSUPPORTED;
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

BCS_RESULT c_graphics_root_signature_d3d12::init_root_signature_description()
{
	root_parameters = new() D3D12_ROOT_PARAMETER[total_root_parameters]{};
	descriptor_ranges = new() D3D12_DESCRIPTOR_RANGE[total_descriptor_table_ranges];
	static_samplers = new() D3D12_STATIC_SAMPLER_DESC[total_static_samplers]{};

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_descriptor_table_root_descriptors()))
	{
		goto cleanup;
	}

	if (BCS_FAILED(rs = init_descriptor_root_descriptors()))
	{
		goto cleanup;
	}

	root_signature_description = {};
	root_signature_description.NumParameters = total_root_parameters;
	root_signature_description.pParameters = root_parameters;
	root_signature_description.NumStaticSamplers = total_static_samplers;
	root_signature_description.pStaticSamplers = static_samplers;
	root_signature_description.Flags = D3D12_ROOT_SIGNATURE_FLAG_NONE;
	root_signature_description.Flags = root_signature_description.Flags | D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

	return rs;

cleanup:

	delete[] root_parameters;
	delete[] descriptor_ranges;
	delete[] static_samplers;

	return rs;
}

BCS_RESULT c_graphics_root_signature_d3d12::init_descriptor_table_root_descriptors()
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
				D3D12_ROOT_PARAMETER* descriptor_table_root_parameter = root_parameters + indirection_index;

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
		for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_register_layout_descriptions; layout_descriptor_index++)
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
					return BCS_E_UNSUPPORTED;
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

	return BCS_S_OK;
}

BCS_RESULT c_graphics_root_signature_d3d12::init_descriptor_root_descriptors()
{
	if (num_descriptor_root_parameters == 0)
	{
		return BCS_S_OK;
	}

	D3D12_ROOT_PARAMETER* root_parameters_position = root_parameters + num_descriptor_table_root_parameters;
	D3D12_STATIC_SAMPLER_DESC* static_samplers_position = static_samplers;
	debug_point;

	for (unsigned int layout_descriptor_index = 0; layout_descriptor_index < num_register_layout_descriptions; layout_descriptor_index++)
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

					if (register_layout_description.sampler_layout_description == nullptr)
					{
						console_write_line("Sampler layout description must be supplied");
						return BCS_E_INVALID_ARGUMENT;
					}

					s_graphics_sampler_layout_description& sampler_layout_description = *register_layout_description.sampler_layout_description;

					switch (sampler_layout_description.filter)
					{
					case _graphics_sampler_filter_min_mag_mip_point:
						static_sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
						break;
					case _graphics_sampler_filter_min_mag_point_mip_linear:
						static_sampler.Filter = D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR;
						break;
					case _graphics_sampler_filter_min_point_mag_linear_mip_point:
						static_sampler.Filter = D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT;
						break;
					case _graphics_sampler_filter_min_point_mag_mip_linear:
						static_sampler.Filter = D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR;
						break;
					case _graphics_sampler_filter_min_linear_mag_mip_point:
						static_sampler.Filter = D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT;
						break;
					case _graphics_sampler_filter_min_linear_mag_point_mip_linear:
						static_sampler.Filter = D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
						break;
					case _graphics_sampler_filter_min_mag_linear_mip_point:
						static_sampler.Filter = D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT;
						break;
					case _graphics_sampler_filter_min_mag_mip_linear:
						static_sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
						break;
					case _graphics_sampler_filter_anisotropic:
						static_sampler.Filter = D3D12_FILTER_ANISOTROPIC;
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}

					switch (sampler_layout_description.texture_adress_u)
					{
					case _graphics_texture_address_mode_wrap:
						static_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
						break;
					case _graphics_texture_address_mode_mirror:
						static_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
						break;
					case _graphics_texture_address_mode_clamp:
						static_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
						break;
					case _graphics_texture_address_mode_border:
						static_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
						break;
					case _graphics_texture_address_mode_mirror_once:
						static_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE;
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}

					switch (sampler_layout_description.texture_adress_v)
					{
					case _graphics_texture_address_mode_wrap:
						static_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
						break;
					case _graphics_texture_address_mode_mirror:
						static_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
						break;
					case _graphics_texture_address_mode_clamp:
						static_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
						break;
					case _graphics_texture_address_mode_border:
						static_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
						break;
					case _graphics_texture_address_mode_mirror_once:
						static_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE;
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}

					switch (sampler_layout_description.texture_adress_w)
					{
					case _graphics_texture_address_mode_wrap:
						static_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
						break;
					case _graphics_texture_address_mode_mirror:
						static_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
						break;
					case _graphics_texture_address_mode_clamp:
						static_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
						break;
					case _graphics_texture_address_mode_border:
						static_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
						break;
					case _graphics_texture_address_mode_mirror_once:
						static_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE;
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}

					static_sampler.MipLODBias = 0.0f; // #TODO: Should this be exposed?
					static_sampler.MaxAnisotropy = __clamp(sampler_layout_description.anisotropy, 0, 16);
					static_sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
					static_sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
					static_sampler.MinLOD = __clamp(sampler_layout_description.minimum_mip, 0.0f, 64.0f);
					static_sampler.MaxLOD = __clamp(sampler_layout_description.maximum_mip, 0.0f, 64.0f);
					static_sampler.ShaderRegister = shader_register;
					static_sampler.RegisterSpace = register_layout_description.register_space;
					static_sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

					static_samplers_position++;
				}
				else
				{
					D3D12_ROOT_PARAMETER& root_parameter = *root_parameters_position;

					switch (register_layout_description.semantic)
					{
					case _graphics_register_layout_shader_resource:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_SRV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
						break;
					case _graphics_register_layout_unordered_access:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_UAV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
						break;
					case _graphics_register_layout_constant_buffer:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
						root_parameter.Descriptor.ShaderRegister = shader_register;
						root_parameter.Descriptor.RegisterSpace = register_layout_description.register_space;
						root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
						break;
					case _graphics_register_layout_32bit_constant:
						root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
						root_parameter.Constants.ShaderRegister = shader_register;
						root_parameter.Constants.RegisterSpace = register_layout_description.register_space;
						root_parameter.Constants.Num32BitValues = register_layout_description.num_32_bit_values;
						root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
						break;
					case _graphics_register_layout_sampler:
					default:
						return BCS_E_UNSUPPORTED;
					}

					root_parameters_position++;
				}
			}
		}
	}
	debug_point;

	return BCS_S_OK;
}

BCS_RESULT c_graphics_root_signature_d3d12::init_root_descriptor(const wchar_t* debug_name)
{
	BCS_RESULT rs = BCS_S_OK;

	ID3DBlob* root_signature_blob = nullptr;
	ID3DBlob* root_signature_error_blob = nullptr;
	HRESULT serialize_root_signature_result = D3D12SerializeRootSignature(&root_signature_description, D3D_ROOT_SIGNATURE_VERSION_1_0, &root_signature_blob, &root_signature_error_blob);
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

BCS_RESULT c_graphics_root_signature_d3d12::bind() const
{
	switch (root_signature_type)
	{
	case _graphics_register_layout_type_graphics:
		graphics.command_list->SetGraphicsRootSignature(root_signature);
		break;
	case _graphics_register_layout_type_compute:
		graphics.command_list->SetComputeRootSignature(root_signature);
		break;
	default:
		return BCS_E_UNSUPPORTED;
	}
	return BCS_S_OK;
}

BCS_RESULT c_graphics_root_signature_d3d12::bind_descriptor_buffer(
	D3D12_ROOT_PARAMETER_TYPE target_root_parameter_type,
	unsigned int target_register_index,
	unsigned int target_register_space,
	c_graphics_buffer_d3d12& graphics_buffer) const
{
	// try to find a root parameter first as a fastpath
	for (unsigned int root_parameter_index = 0; root_parameter_index < total_root_parameters; root_parameter_index++)
	{
		D3D12_ROOT_PARAMETER& root_parameter = root_parameters[root_parameter_index];

		if (root_parameter.ParameterType == target_root_parameter_type)
		{
			switch (root_parameter.ParameterType)
			{
			case D3D12_ROOT_PARAMETER_TYPE_CBV:
			{
				if (root_parameter.Descriptor.RegisterSpace == target_register_space && root_parameter.Descriptor.ShaderRegister == target_register_index)
				{
					D3D12_GPU_VIRTUAL_ADDRESS gpu_virtual_address = graphics_buffer.gpu_resource->GetGPUVirtualAddress();
					switch (root_signature_type)
					{
					case _graphics_register_layout_type_graphics:
						graphics.command_list->SetGraphicsRootConstantBufferView(root_parameter_index, gpu_virtual_address);
						break;
					case _graphics_register_layout_type_compute:
						graphics.command_list->SetComputeRootConstantBufferView(root_parameter_index, gpu_virtual_address);
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}
				}
			}
			return BCS_S_OK;
			case D3D12_ROOT_PARAMETER_TYPE_SRV:
			{
				if (root_parameter.Descriptor.RegisterSpace == target_register_space && root_parameter.Descriptor.ShaderRegister == target_register_index)
				{
					D3D12_GPU_VIRTUAL_ADDRESS gpu_virtual_address = graphics_buffer.gpu_resource->GetGPUVirtualAddress();
					switch (root_signature_type)
					{
					case _graphics_register_layout_type_graphics:
						graphics.command_list->SetGraphicsRootShaderResourceView(root_parameter_index, gpu_virtual_address);
						break;
					case _graphics_register_layout_type_compute:
						graphics.command_list->SetComputeRootShaderResourceView(root_parameter_index, gpu_virtual_address);
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}
				}
			}
			return BCS_S_OK;
			case D3D12_ROOT_PARAMETER_TYPE_UAV:
			{
				if (root_parameter.Descriptor.RegisterSpace == target_register_space && root_parameter.Descriptor.ShaderRegister == target_register_index)
				{
					D3D12_GPU_VIRTUAL_ADDRESS gpu_virtual_address = graphics_buffer.gpu_resource->GetGPUVirtualAddress();
					switch (root_signature_type)
					{
					case _graphics_register_layout_type_graphics:
						graphics.command_list->SetGraphicsRootUnorderedAccessView(root_parameter_index, gpu_virtual_address);
						break;
					case _graphics_register_layout_type_compute:
						graphics.command_list->SetComputeRootUnorderedAccessView(root_parameter_index, gpu_virtual_address);
						break;
					default:
						return BCS_E_UNSUPPORTED;
					}
				}
			}
			return BCS_S_OK;
			}
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_graphics_root_signature_d3d12::bind_descriptor_table_buffer(
	D3D12_DESCRIPTOR_RANGE_TYPE target_descriptor_range_type,
	unsigned int target_register_index,
	unsigned int target_register_space,
	c_graphics_buffer_d3d12& graphics_buffer) const
{
	// try to find a descriptor range slow path
	for (unsigned int root_parameter_index = 0; root_parameter_index < total_root_parameters; root_parameter_index++)
	{
		D3D12_ROOT_PARAMETER& root_parameter = root_parameters[root_parameter_index];
		if (root_parameter.ParameterType == D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE)
		{
			unsigned int const num_descripor_ranges = root_parameter.DescriptorTable.NumDescriptorRanges;
			for (unsigned int descriptor_range_index = 0; descriptor_range_index < num_descripor_ranges; descriptor_range_index++)
			{
				const D3D12_DESCRIPTOR_RANGE& descriptor_range = root_parameter.DescriptorTable.pDescriptorRanges[descriptor_range_index];

				if (descriptor_range.RangeType == target_descriptor_range_type)
				{
					if (
						descriptor_range.RegisterSpace == target_register_space &&
						descriptor_range.BaseShaderRegister >= target_register_index &&
						(descriptor_range.BaseShaderRegister + descriptor_range.NumDescriptors) > target_register_index)
					{
						switch (descriptor_range.RangeType)
						{
						case D3D12_DESCRIPTOR_RANGE_TYPE_SRV:
						case D3D12_DESCRIPTOR_RANGE_TYPE_UAV:
						case D3D12_DESCRIPTOR_RANGE_TYPE_CBV:
						{
							D3D12_GPU_DESCRIPTOR_HANDLE descriptor_handle = graphics_buffer.get_gpu_descriptor_handle();
							switch (root_signature_type)
							{
							case _graphics_register_layout_type_graphics:
								graphics.command_list->SetGraphicsRootDescriptorTable(root_parameter_index, descriptor_handle);
								break;
							case _graphics_register_layout_type_compute:
								graphics.command_list->SetComputeRootDescriptorTable(root_parameter_index, descriptor_handle);
								break;
							default:
								return BCS_E_UNSUPPORTED;
							}
						}
						return BCS_S_OK;
						}
					}
				}
			}
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_graphics_root_signature_d3d12::bind_buffer(
	unsigned int register_layout_description_index,
	unsigned int register_layout_offset,
	c_graphics_buffer& _graphics_buffer) const
{
	c_graphics_buffer_d3d12& graphics_buffer = reinterpret_cast<c_graphics_buffer_d3d12&>(_graphics_buffer);

	if (register_layout_description_index >= num_register_layout_descriptions)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	s_graphics_register_layout_description& register_layout_description = register_layout_descriptions[register_layout_description_index];

	unsigned int const target_register_index = register_layout_description.register_index + register_layout_offset;
	unsigned int const target_register_space = register_layout_description.register_space;

	if (register_layout_description.use_table)
	{
		D3D12_DESCRIPTOR_RANGE_TYPE target_descriptor_range_type;
		switch (register_layout_description.semantic)
		{
		case _graphics_register_layout_unordered_access:
			target_descriptor_range_type = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
			break;
		case _graphics_register_layout_constant_buffer:
			target_descriptor_range_type = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
			break;
		default:
			return BCS_E_UNSUPPORTED;
		}

		BCS_RESULT bind_descriptor_table_buffer_result = bind_descriptor_table_buffer(target_descriptor_range_type, target_register_index, target_register_space, graphics_buffer);
		return bind_descriptor_table_buffer_result;
	}
	else
	{
		D3D12_ROOT_PARAMETER_TYPE target_root_parameter_type;
		switch (register_layout_description.semantic)
		{
		case _graphics_register_layout_unordered_access:
			target_root_parameter_type = D3D12_ROOT_PARAMETER_TYPE_UAV;
			break;
		case _graphics_register_layout_constant_buffer:
			target_root_parameter_type = D3D12_ROOT_PARAMETER_TYPE_CBV;
			break;
		default:
			return BCS_E_UNSUPPORTED;
		}

		BCS_RESULT bind_descriptor_table_buffer_result = bind_descriptor_buffer(target_root_parameter_type, target_register_index, target_register_space, graphics_buffer);
		return bind_descriptor_table_buffer_result;
	}
}

BCS_RESULT c_graphics_root_signature_d3d12::bind_buffer(
	e_graphics_register_layout_semantic semantic,
	unsigned int target_register_index,
	unsigned int target_register_space,
	c_graphics_buffer& _graphics_buffer) const
{
	c_graphics_buffer_d3d12& graphics_buffer = reinterpret_cast<c_graphics_buffer_d3d12&>(_graphics_buffer);

	// #TODO: Accelerate using a binary search. Encode the register index, register space, and type into an index.

	BCS_RESULT rs = BCS_E_FAIL;

	if(BCS_FAILED(rs))
	{
		D3D12_ROOT_PARAMETER_TYPE target_root_parameter_type;
		switch (semantic)
		{
		case _graphics_register_layout_unordered_access:
			target_root_parameter_type = D3D12_ROOT_PARAMETER_TYPE_UAV;
			break;
		case _graphics_register_layout_constant_buffer:
			target_root_parameter_type = D3D12_ROOT_PARAMETER_TYPE_CBV;
			break;
		default:
			return BCS_E_UNSUPPORTED;
		}
		rs = bind_descriptor_buffer(target_root_parameter_type, target_register_index, target_register_space, graphics_buffer);
	}
	if (BCS_FAILED(rs))
	{
		D3D12_DESCRIPTOR_RANGE_TYPE target_descriptor_range_type;
		switch (semantic)
		{
		case _graphics_register_layout_unordered_access:
			target_descriptor_range_type = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
			break;
		case _graphics_register_layout_constant_buffer:
			target_descriptor_range_type = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
			break;
		default:
			return BCS_E_UNSUPPORTED;
		}

		rs = bind_descriptor_table_buffer(target_descriptor_range_type, target_register_index, target_register_space, graphics_buffer);
	}

	return rs;
}

BCS_RESULT graphics_d3d12_root_signature_create(
	c_graphics_d3d12* graphics,
	e_graphics_register_layout_type root_signature_type,
	s_graphics_register_layout_description const* register_layout_descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_root_signature_d3d12*& root_signature,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		root_signature = new() c_graphics_root_signature_d3d12(
			*graphics,
			root_signature_type,
			register_layout_descriptions,
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
