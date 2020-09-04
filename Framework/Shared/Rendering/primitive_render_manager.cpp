#include "shared-private-pch.h"

using namespace DirectX;

c_primitive_render_manager::PerFrameConstants* c_primitive_render_manager::pPerFrameConstantsArray = nullptr;
ID3D11Buffer* c_primitive_render_manager::pCurrentFrameConstantsBuffer = nullptr;
ID3D11Buffer* c_primitive_render_manager::ppFrameConstantsBuffers[k_num_constants_buffers] = {};
c_box_primitive c_primitive_render_manager::immediateBoxPrimitive;
volatile uint32_t c_primitive_render_manager::next_constant_buffer_index = 0;
DirectX::XMVECTOR c_primitive_render_manager::s_forward;
DirectX::XMVECTOR c_primitive_render_manager::s_up;
DirectX::XMVECTOR c_primitive_render_manager::s_position;

std::vector<c_box_primitive*> c_primitive_render_manager::s_boxPrimitives;
std::vector<BoxPrimitiveData> c_primitive_render_manager::s_immediateBoxPrimitives;

void c_primitive_render_manager::register_box_primitive(c_box_primitive* box_primitive)
{
	if (box_primitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.emplace_back(box_primitive);
	}
}

void c_primitive_render_manager::unregister_box_primitive(c_box_primitive* box_primitive)
{
	if (box_primitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.erase(std::remove(s_boxPrimitives.begin(), s_boxPrimitives.end(), box_primitive), s_boxPrimitives.end());
	}
}

void c_primitive_render_manager::render()
{
	setup_constants_buffers();
	UpdateConstantsBuffer();

	static bool enablePrimitiveDebug = c_command_line::has_command_line_arg("-primitivedebug");
	if (enablePrimitiveDebug)
	{
		static c_box_primitive debugBox;
		debugBox.update_as_centered_box(
			0.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 1.0f
		);
		debugBox.set_color(1.0f, 0.0f, 1.0f, 1.0f);
	}

	{
		c_box_renderer::begin_render_box();

		for (const BoxPrimitiveData& box_primitive : s_immediateBoxPrimitives)
		{
			c_box_renderer::render_box(
				XMFLOAT3(
					box_primitive.position_x,
					box_primitive.position_y,
					box_primitive.position_z),
				XMFLOAT3(
					box_primitive.dimensions_x,
					box_primitive.dimensions_y,
					box_primitive.dimensions_z),
				XMFLOAT4(
					box_primitive.color_r,
					box_primitive.color_g,
					box_primitive.color_b,
					box_primitive.color_a)
			);
		}
		s_immediateBoxPrimitives.clear();

		for (const c_box_primitive* box_primitive : s_boxPrimitives)
		{
			if (box_primitive->IsVisible())
			{
				c_box_renderer::render_box(
					XMFLOAT3(
						box_primitive->position_x,
						box_primitive->position_y,
						box_primitive->position_z),
					XMFLOAT3(
						box_primitive->dimensions_x,
						box_primitive->dimensions_y,
						box_primitive->dimensions_z),
					XMFLOAT4(
						box_primitive->color_r,
						box_primitive->color_g,
						box_primitive->color_b,
						box_primitive->color_a)
				);
			}
		}

		c_box_renderer::end_render_box();
	}

	pCurrentFrameConstantsBuffer = nullptr;
}

void c_primitive_render_manager::setup_constants_buffers()
{
	if (ppFrameConstantsBuffers[k_num_constants_buffers - 1] == nullptr)
	{
		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufferDesc.ByteWidth = sizeof(PerFrameConstants);
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		for (uint32_t i = 0; i < k_num_constants_buffers; i++)
		{
			ID3D11Buffer*& pConstantsBuffer = ppFrameConstantsBuffers[i];

			HRESULT createBufferesult = c_render::s_device->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			ASSERT(SUCCEEDED(createBufferesult));
			ASSERT(pConstantsBuffer != nullptr);
		}
	}
}

void c_primitive_render_manager::get_next_constants_buffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&next_constant_buffer_index) - 1) % k_num_constants_buffers;
	pCurrentFrameConstantsBuffer = ppFrameConstantsBuffers[currentConstantBufferIndex];
	ASSERT(pCurrentFrameConstantsBuffer != nullptr);
}

ID3D11Buffer* const& c_primitive_render_manager::GetConstantsBuffer()
{
	ASSERT(pCurrentFrameConstantsBuffer != nullptr);
	return pCurrentFrameConstantsBuffer;
}

void c_primitive_render_manager::render_immediate_box()
{
	if (immediateBoxPrimitive.IsVisible())
	{
		s_immediateBoxPrimitives.emplace_back(get_immediate_box());
	}
}

void c_primitive_render_manager::map_constants_buffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = c_render::s_device_context->Map(pCurrentFrameConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	ASSERT(SUCCEEDED(mapResult));

	// contigious memory
	pPerFrameConstantsArray = static_cast<PerFrameConstants*>(mappedResource.pData);
}

void c_primitive_render_manager::unmap_constants_buffer()
{
	c_render::s_device_context->Unmap(pCurrentFrameConstantsBuffer, 0);
	pPerFrameConstantsArray = nullptr;
}

void c_primitive_render_manager::UpdateConstantsBuffer()
{
	get_next_constants_buffer();
	map_constants_buffer();

	PerFrameConstants& rPerFrameConstants = *pPerFrameConstantsArray;
	rPerFrameConstants.view_matrix = c_render::view_matrix_transposed;
	rPerFrameConstants.perspective_matrix = c_render::perspective_matrix_transposed;

	unmap_constants_buffer();
}

c_box_primitive& c_primitive_render_manager::get_immediate_box()
{
	return immediateBoxPrimitive;
}

