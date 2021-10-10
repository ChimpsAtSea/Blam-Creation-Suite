#include "graphicslib-private-pch.h"

c_graphics_vertex_layout_d3d12::c_graphics_vertex_layout_d3d12(
	c_graphics_d3d12& graphics,
	s_graphics_vertex_layout_description* descriptions,
	unsigned long num_descriptions,
	const wchar_t* name) :
	graphics(graphics),
	vertex_layout_descriptions(),
	num_layout_descriptions(num_descriptions)
{
	vertex_layout_descriptions = new D3D12_INPUT_ELEMENT_DESC[num_layout_descriptions]{};
	for (unsigned long vertex_layout_index = 0; vertex_layout_index < num_layout_descriptions; vertex_layout_index++)
	{
		D3D12_INPUT_ELEMENT_DESC& d3d12_vertex_layout_description = vertex_layout_descriptions[vertex_layout_index];
		s_graphics_vertex_layout_description vertex_layout_description = descriptions[vertex_layout_index];

		const char* vertex_layout_semantic_name = vertex_layout_semantic_to_string(vertex_layout_description.semantic);

		DXGI_FORMAT dxgi_format;
		BCS_FAIL_THROW(graphics_data_format_to_dxgi_format(vertex_layout_description.data_format, dxgi_format));

		D3D12_INPUT_CLASSIFICATION input_classificaton;
		BCS_FAIL_THROW(graphics_vertex_layout_stepping_to_d3d12_input_classification(vertex_layout_description.stepping, input_classificaton));

		d3d12_vertex_layout_description.SemanticName = vertex_layout_semantic_name;
		d3d12_vertex_layout_description.SemanticIndex = vertex_layout_description.semantic_index;
		d3d12_vertex_layout_description.Format = dxgi_format;
		d3d12_vertex_layout_description.InputSlot = vertex_layout_description.buffer_index;
		d3d12_vertex_layout_description.AlignedByteOffset = vertex_layout_description.buffer_offset;
		d3d12_vertex_layout_description.InputSlotClass = input_classificaton;
		d3d12_vertex_layout_description.InstanceDataStepRate = vertex_layout_description.buffer_instance_stepping;

		debug_point;
	}
}
c_graphics_vertex_layout_d3d12::~c_graphics_vertex_layout_d3d12()
{

}

BCS_RESULT graphics_vertex_layout_stepping_to_d3d12_input_classification(e_graphics_vertex_layout_stepping stepping, D3D12_INPUT_CLASSIFICATION& input_classification)
{
#define GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_stepping, _input_classification) \
    if (stepping == _stepping) { input_classification = _input_classification; return BCS_S_OK; }

	GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_graphics_vertex_layout_stepping_per_vertex, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA);
	GRAPHICS_VERTEX_LAYOUT_STEPPING_TO_D3D12_INPUT_CLASSIFICATION(_graphics_vertex_layout_stepping_per_instance, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA);

	return BCS_E_NOT_SUPPORTED;

#undef GRAPHICS_DATA_FORMAT_TO_DXGI_FORMAT
}

BCS_RESULT graphics_d3d12_vertex_layout_create(
	c_graphics_d3d12* graphics,
	s_graphics_vertex_layout_description* descriptions,
	unsigned long num_layout_descriptions,
	c_graphics_vertex_layout_d3d12*& vertex_layout,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		vertex_layout = new c_graphics_vertex_layout_d3d12(
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
