#include "shared-private-pch.h"

ID3D11InputLayout* c_box_renderer::vertex_layout;
ID3D11PixelShader* c_box_renderer::pixel_shader = nullptr;
ID3D11VertexShader* c_box_renderer::vertex_shader = nullptr;
ID3D11RasterizerState* c_box_renderer::solid_raster_state = nullptr;
ID3D11RasterizerState* c_box_renderer::wireframe_raster_state = nullptr;
ID3D11Buffer* c_box_renderer::vertex_buffer = nullptr;
ID3D11Buffer* c_box_renderer::solid_index_buffer = nullptr;
ID3D11Buffer* c_box_renderer::wireframe_index_buffer = nullptr;
volatile uint32_t c_box_renderer::next_constant_buffer_index = 0;
volatile uint32_t c_box_renderer::next_box_index = 0;
ID3D11Buffer* c_box_renderer::instance_constants_buffers[c_primitive_render_manager::k_num_constants_buffers] = {};
ID3D11Buffer* c_box_renderer::current_instance_constants_buffer = nullptr;
c_box_renderer::s_box_per_object_constants* c_box_renderer::box_per_object_constants_array = nullptr;

void c_box_renderer::setup_wireframe_geometry()
{
	using namespace DirectX;

	if (wireframe_index_buffer == nullptr)
	{
		const uint32_t boxIndices[] = {


			///*0*/ {-0.5f, -0.5f, -0.5f},
			///*1*/ {-0.5f, 0.5f, -0.5f},
			///*2*/ {0.5f, 0.5f, -0.5f},
			///*3*/ {0.5f, -0.5f, -0.5f},
			///*4*/ {-0.5f, -0.5f, 0.5f},
			///*5*/ {-0.5f, 0.5f, 0.5f},
			///*6*/ {0.5f, 0.5f, 0.5f},
			///*7*/ {0.5f, -0.5f, 0.5f},


			0, 1,
			1, 2,
			2, 3,
			3, 0,

			4, 5,
			5, 6,
			6, 7,
			7, 4,

			0, 4,
			1, 5,
			2, 6,
			3, 7
		};

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(boxIndices);
		bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = boxIndices;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferesult = c_render::s_device->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &wireframe_index_buffer);
		ASSERT(SUCCEEDED(createBufferesult));
		ASSERT(wireframe_index_buffer != nullptr);
	}
}

void c_box_renderer::setup_solid_geometry()
{
	using namespace DirectX;

	if (vertex_buffer == nullptr)
	{
		XMFLOAT3 vertexData[] = {
			{-0.5f, -0.5f, -0.5f},
			{-0.5f, 0.5f, -0.5f},
			{0.5f, 0.5f, -0.5f},
			{0.5f, -0.5f, -0.5f},
			{-0.5f, -0.5f, 0.5f},
			{-0.5f, 0.5f, 0.5f},
			{0.5f, 0.5f, 0.5f},
			{0.5f, -0.5f, 0.5f},
		};

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(vertexData);
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = vertexData;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferesult = c_render::s_device->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &vertex_buffer);
		ASSERT(SUCCEEDED(createBufferesult));
		ASSERT(vertex_buffer != nullptr);
	}

	if (solid_index_buffer == nullptr)
	{
		const uint32_t boxIndices[] = {
			// front
			0,1,2,
			0,2,3,
			// back
			4,6,5,
			4,7,6,
			// left
			4,5,1,
			4,1,0,
			// right
			3,2,6,
			3,6,7,
			//top
			1,5,6,
			1,6,2,
			// bottom
			4,0,3,
			4,3,7
		};

		D3D11_BUFFER_DESC shader_binary = {};
		shader_binary.Usage = D3D11_USAGE_DEFAULT;
		shader_binary.ByteWidth = sizeof(boxIndices);
		shader_binary.BindFlags = D3D11_BIND_INDEX_BUFFER;
		shader_binary.CPUAccessFlags = 0;
		shader_binary.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = boxIndices;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferesult = c_render::s_device->CreateBuffer(&shader_binary, &vertexBufferSubResourceData, &solid_index_buffer);
		ASSERT(SUCCEEDED(createBufferesult));
		ASSERT(solid_index_buffer != nullptr);
	}
}

void c_box_renderer::setup_shaders()
{
	if (pixel_shader == nullptr)
	{
		void* shader_binary = nullptr;
		size_t shaderFileLength = 0;
		if (!c_resources_manager::copy_resource_to_buffer(_resource_type_box_pixel_shader, shader_binary, &shaderFileLength))
		{
			c_console::write_line_verbose("Warning: Failed to find Box pixel shader resource! Attempting to read BoxShaderPS.cso");
			shader_binary = filesystem_read_to_memory_legacy(L"BoxShaderPS.cso", &shaderFileLength);
		}
		ASSERT(shader_binary != nullptr);

		c_render::s_device->CreatePixelShader(shader_binary, shaderFileLength, NULL, &pixel_shader);
		ASSERT(pixel_shader != nullptr);

		delete[] shader_binary;
	}

	void* vertex_shader_binary = nullptr;
	size_t vertex_shader_binary_length = 0;
	if (vertex_shader == nullptr)
	{
		if (!c_resources_manager::copy_resource_to_buffer(_resource_type_box_vertex_shader, vertex_shader_binary, &vertex_shader_binary_length))
		{
			c_console::write_line_verbose("Warning: Failed to find Box vertex shader resource! Attempting to read BoxShaderVS.cso");
			vertex_shader_binary = filesystem_read_to_memory_legacy(L"BoxShaderVS.cso", &vertex_shader_binary_length);
		}
		ASSERT(vertex_shader_binary != nullptr);

		c_render::s_device->CreateVertexShader(vertex_shader_binary, vertex_shader_binary_length, NULL, &vertex_shader);
		ASSERT(vertex_shader != nullptr);
	}

	if (solid_raster_state == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_SOLID;
		rasterizerDescription.CullMode = D3D11_CULL_BACK;
		c_render::s_device->CreateRasterizerState(&rasterizerDescription, &solid_raster_state);
	}

	if (wireframe_raster_state == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_WIREFRAME;
		rasterizerDescription.CullMode = D3D11_CULL_NONE;
		c_render::s_device->CreateRasterizerState(&rasterizerDescription, &wireframe_raster_state);
	}

	if (vertex_layout == nullptr)
	{
		D3D11_INPUT_ELEMENT_DESC inputDescriptions[1] = {};

		inputDescriptions[0].SemanticName = "POSITION";
		inputDescriptions[0].SemanticIndex = 0;
		inputDescriptions[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputDescriptions[0].InputSlot = 0;
		inputDescriptions[0].AlignedByteOffset = 0;
		inputDescriptions[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputDescriptions[0].InstanceDataStepRate = 0;

		HRESULT createInputLayoutResult = c_render::s_device->CreateInputLayout(inputDescriptions, 1, vertex_shader_binary, vertex_shader_binary_length, &vertex_layout);
		ASSERT(SUCCEEDED(createInputLayoutResult));
		ASSERT(vertex_layout != nullptr);
	}

	if (vertex_shader_binary != nullptr)
	{
		delete[] vertex_shader_binary;
	}
}

void c_box_renderer::setup_constants_buffers()
{
	if (instance_constants_buffers[c_primitive_render_manager::k_num_constants_buffers - 1] == nullptr)
	{
		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufferDesc.ByteWidth = sizeof(s_box_per_object_constants) * k_max_boxes_per_frame;
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		for (uint32_t i = 0; i < c_primitive_render_manager::k_num_constants_buffers; i++)
		{
			ID3D11Buffer*& pConstantsBuffer = instance_constants_buffers[i];

			HRESULT createBufferesult = c_render::s_device->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			ASSERT(SUCCEEDED(createBufferesult));
			ASSERT(pConstantsBuffer != nullptr);
		}
	}
}

void c_box_renderer::get_next_constants_buffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&next_constant_buffer_index) - 1) % c_primitive_render_manager::k_num_constants_buffers;
	current_instance_constants_buffer = instance_constants_buffers[currentConstantBufferIndex];
	ASSERT(current_instance_constants_buffer != nullptr);
}

void c_box_renderer::map_constants_buffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = c_render::s_device_context->Map(current_instance_constants_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	ASSERT(SUCCEEDED(mapResult));

	// contigious memory
	box_per_object_constants_array = static_cast<s_box_per_object_constants*>(mappedResource.pData);
}

void c_box_renderer::unmap_constants_buffer()
{
	c_render::s_device_context->Unmap(current_instance_constants_buffer, 0);
	box_per_object_constants_array = nullptr;
}

void c_box_renderer::begin_render_box()
{
	setup_shaders();
	setup_wireframe_geometry();
	setup_solid_geometry();
	setup_constants_buffers();
	get_next_constants_buffer();
	map_constants_buffer();
}

void c_box_renderer::render_box(
	DirectX::XMFLOAT3 const& position,
	DirectX::XMFLOAT3 const& dimensions,
	DirectX::XMFLOAT4 const& color
)
{
	using namespace DirectX;

	uint32_t currentBoxIndex = InterlockedIncrement(&next_box_index) - 1;

	if (currentBoxIndex >= k_max_boxes_per_frame)
	{
		return; // we've hit the maximum number of boxes that we can render per frame
	}

	s_box_per_object_constants& rs_box_per_object_constants = box_per_object_constants_array[currentBoxIndex];
	rs_box_per_object_constants.model_matrix = XMMatrixScaling(dimensions.x, dimensions.y, dimensions.z);
	rs_box_per_object_constants.model_matrix *= XMMatrixTranslation(position.x, position.y, position.z);
	rs_box_per_object_constants.model_matrix = XMMatrixTranspose(rs_box_per_object_constants.model_matrix);
	rs_box_per_object_constants.color = color;

}

void c_box_renderer::render_box_geometry()
{
	using namespace DirectX;

	if (next_box_index > 0)
	{
		const UINT vertexStride = sizeof(XMFLOAT3);
		const UINT vertexOffset = 0;

		c_render::s_device_context->RSSetState(wireframe_raster_state);
		c_render::s_device_context->VSSetShader(vertex_shader, NULL, 0);
		c_render::s_device_context->PSSetShader(pixel_shader, NULL, 0);
		c_render::s_device_context->IASetInputLayout(vertex_layout);
		c_render::s_device_context->IASetVertexBuffers(0, 1, &vertex_buffer, &vertexStride, &vertexOffset);

		bool solid = false;
		if (solid)
		{
			c_render::s_device_context->IASetIndexBuffer(solid_index_buffer, DXGI_FORMAT_R32_UINT, 0);
			c_render::s_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		}
		else
		{
			c_render::s_device_context->IASetIndexBuffer(wireframe_index_buffer, DXGI_FORMAT_R32_UINT, 0);
			c_render::s_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
		}

		const uint32_t maxInstances = 4096 / sizeof(s_box_per_object_constants);
		//const uint32_t maxInstancesPow2 = 1u << ilogb(maxInstances);
		const uint32_t maxInstancesPow2 = 16;

		c_render::s_device_context->VSSetConstantBuffers(0, 1, &c_primitive_render_manager::GetConstantsBuffer());
		c_render::s_device_context->PSSetConstantBuffers(0, 1, &c_primitive_render_manager::GetConstantsBuffer());

		const uint32_t numBoxes = __min(k_max_boxes_per_frame, next_box_index);
		for (uint32_t i = 0; i < numBoxes;)
		{
			uint32_t remainingBoxes = numBoxes - i;
			uint32_t boxesToDrawThisCall = __min(remainingBoxes, maxInstancesPow2);

			boxesToDrawThisCall = 1; // #TODO: Rendering more than 1 box at a time causes issues. Not sure why.

			UINT firstConstant = (sizeof(s_box_per_object_constants) * i) / 16;
			UINT numConstants = sizeof(s_box_per_object_constants);

			c_render::s_device_context->VSSetConstantBuffers1(1, 1, &current_instance_constants_buffer, &firstConstant, &numConstants);
			c_render::s_device_context->PSSetConstantBuffers1(1, 1, &current_instance_constants_buffer, &firstConstant, &numConstants);

			if (solid)
			{
				c_render::s_device_context->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);
			}
			else
			{
				c_render::s_device_context->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);
			}

			i += boxesToDrawThisCall;
		}
	}
}

void c_box_renderer::end_render_box()
{
	using namespace DirectX;

	unmap_constants_buffer();

	c_render::begin_frame(false, nullptr, false);
	render_box_geometry();
	//c_render::EndFrame();

	current_instance_constants_buffer = nullptr;
	next_box_index = 0;
}

