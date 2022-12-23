#include "graphicslib-private-pch.h"

c_graphics_vertex_layout_d3d12::c_graphics_vertex_layout_d3d12(
	c_graphics_d3d12& graphics,
	s_graphics_vertex_layout_description* _vertex_layout_descriptions,
	uint32_t _num_vertex_layout_descriptions,
	const wchar_t* debug_name) :
	graphics(graphics),
	vertex_layout_descriptions(),
	input_element_descriptions(),
	num_vertex_layout_descriptions(_num_vertex_layout_descriptions)
{
	BCS_VALIDATE_ARGUMENT_THROW(num_vertex_layout_descriptions > 0);

	vertex_layout_descriptions = new() s_graphics_vertex_layout_description[num_vertex_layout_descriptions];
	memcpy(vertex_layout_descriptions, _vertex_layout_descriptions, sizeof(*vertex_layout_descriptions) * num_vertex_layout_descriptions);
	input_element_descriptions = new() D3D12_INPUT_ELEMENT_DESC[num_vertex_layout_descriptions]{};

	for (uint32_t vertex_layout_index = 0; vertex_layout_index < num_vertex_layout_descriptions; vertex_layout_index++)
	{
		s_graphics_vertex_layout_description& vertex_layout_description = vertex_layout_descriptions[vertex_layout_index];
		D3D12_INPUT_ELEMENT_DESC& input_element_description = input_element_descriptions[vertex_layout_index];

		const char* vertex_layout_semantic_name = vertex_layout_semantic_to_string(vertex_layout_description.semantic);

		DXGI_FORMAT dxgi_format;
		BCS_FAIL_THROW(graphics_data_format_to_dxgi_format(vertex_layout_description.data_format, dxgi_format));

		D3D12_INPUT_CLASSIFICATION input_classificaton;
		BCS_FAIL_THROW(graphics_vertex_layout_stepping_to_d3d12_input_classification(vertex_layout_description.vertex_layout_stepping, input_classificaton));

		input_element_description.SemanticName = vertex_layout_semantic_name;
		input_element_description.SemanticIndex = vertex_layout_description.semantic_index;
		input_element_description.Format = dxgi_format;
		input_element_description.InputSlot = vertex_layout_description.buffer_index;
		input_element_description.AlignedByteOffset = vertex_layout_description.buffer_offset;
		input_element_description.InputSlotClass = input_classificaton;
		input_element_description.InstanceDataStepRate = vertex_layout_description.buffer_stepping;
	}
}
c_graphics_vertex_layout_d3d12::~c_graphics_vertex_layout_d3d12()
{

}

BCS_RESULT c_graphics_vertex_layout_d3d12::find_first_vertex_layout_description_by_semantic(e_graphics_vertex_layout_semantic semantic, s_graphics_vertex_layout_description const*& vertex_layout_description) const
{
	D3D12_INPUT_ELEMENT_DESC const* input_element_description; // discard
	return find_first_vertex_layout_description_by_semantic(semantic, vertex_layout_description, input_element_description);
}

BCS_RESULT c_graphics_vertex_layout_d3d12::find_first_vertex_layout_description_by_semantic(e_graphics_vertex_layout_semantic semantic, D3D12_INPUT_ELEMENT_DESC const*& input_element_description) const
{
	s_graphics_vertex_layout_description const* vertex_layout_description; // discard
	return find_first_vertex_layout_description_by_semantic(semantic, vertex_layout_description, input_element_description);
}

BCS_RESULT c_graphics_vertex_layout_d3d12::find_first_vertex_layout_description_by_semantic(
	e_graphics_vertex_layout_semantic semantic,
	s_graphics_vertex_layout_description const*& out_vertex_layout_description,
	D3D12_INPUT_ELEMENT_DESC const*& out_input_element_description) const
{
	for (uint32_t vertex_layout_index = 0; vertex_layout_index < num_vertex_layout_descriptions; vertex_layout_index++)
	{
		s_graphics_vertex_layout_description const& vertex_layout_description = vertex_layout_descriptions[vertex_layout_index];
		if (vertex_layout_description.semantic == semantic)
		{
			out_vertex_layout_description = &vertex_layout_description;
			out_input_element_description = &input_element_descriptions[vertex_layout_index];
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT graphics_vertex_layout_stepping_to_d3d12_input_classification(e_graphics_vertex_layout_stepping vertex_layout_stepping, D3D12_INPUT_CLASSIFICATION& input_classification)
{
#define GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_stepping, _input_classification) \
    if (vertex_layout_stepping == _stepping) { input_classification = _input_classification; return BCS_S_OK; }

	GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_graphics_vertex_layout_stepping_per_vertex, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA);
	GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_graphics_vertex_layout_stepping_per_instance, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA);

	return BCS_E_NOT_SUPPORTED;

#undef GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT
}

BCS_RESULT graphics_d3d12_vertex_layout_create(
	c_graphics_d3d12* graphics,
	s_graphics_vertex_layout_description* descriptions,
	uint32_t num_input_element_descriptions,
	c_graphics_vertex_layout_d3d12*& vertex_layout,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		vertex_layout = new() c_graphics_vertex_layout_d3d12(
			*graphics,
			descriptions,
			num_input_element_descriptions,
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

BCS_RESULT graphics_d3d12_vertex_layout_destroy(c_graphics_vertex_layout_d3d12* vertex_layout)
{
	try
	{
		delete vertex_layout;
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
