#include "shared-private-pch.h"

using namespace DirectX;

c_primitive_render_manager::PerFrameConstants* c_primitive_render_manager::pPerFrameConstantsArray = nullptr;
ID3D11Buffer* c_primitive_render_manager::pCurrentFrameConstantsBuffer = nullptr;
ID3D11Buffer* c_primitive_render_manager::ppFrameConstantsBuffers[kNumConstantsBuffers] = {};
c_box_primitive c_primitive_render_manager::immediateBoxPrimitive;
volatile uint32_t c_primitive_render_manager::nextConstantBufferIndex = 0;
DirectX::XMVECTOR c_primitive_render_manager::s_vForward;
DirectX::XMVECTOR c_primitive_render_manager::s_vUp;
DirectX::XMVECTOR c_primitive_render_manager::s_vPosition;

std::vector<c_box_primitive*> c_primitive_render_manager::s_boxPrimitives;
std::vector<BoxPrimitiveData> c_primitive_render_manager::s_immediateBoxPrimitives;

void c_primitive_render_manager::RegisterBoxPrimitive(c_box_primitive* pBoxPrimitive)
{
	if (pBoxPrimitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.emplace_back(pBoxPrimitive);
	}
}

void c_primitive_render_manager::UnregisterBoxPrimitive(c_box_primitive* pBoxPrimitive)
{
	if (pBoxPrimitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.erase(std::remove(s_boxPrimitives.begin(), s_boxPrimitives.end(), pBoxPrimitive), s_boxPrimitives.end());
	}
}

void c_primitive_render_manager::Render()
{
	SetupConstantBuffers();
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
		BoxRenderer::BeginRenderBox();

		for (const BoxPrimitiveData& rBoxPrimitive : s_immediateBoxPrimitives)
		{
			BoxRenderer::RenderBox(
				XMFLOAT3(
					rBoxPrimitive.m_positionX,
					rBoxPrimitive.m_positionY,
					rBoxPrimitive.m_positionZ),
				XMFLOAT3(
					rBoxPrimitive.m_dimensionsX,
					rBoxPrimitive.m_dimensionsY,
					rBoxPrimitive.m_dimensionsZ),
				XMFLOAT4(
					rBoxPrimitive.m_colorR,
					rBoxPrimitive.m_colorG,
					rBoxPrimitive.m_colorB,
					rBoxPrimitive.m_colorA)
			);
		}
		s_immediateBoxPrimitives.clear();

		for (const c_box_primitive* pBoxPrimitive : s_boxPrimitives)
		{
			if (pBoxPrimitive->IsVisible())
			{
				BoxRenderer::RenderBox(
					XMFLOAT3(
						pBoxPrimitive->m_positionX,
						pBoxPrimitive->m_positionY,
						pBoxPrimitive->m_positionZ),
					XMFLOAT3(
						pBoxPrimitive->m_dimensionsX,
						pBoxPrimitive->m_dimensionsY,
						pBoxPrimitive->m_dimensionsZ),
					XMFLOAT4(
						pBoxPrimitive->m_colorR,
						pBoxPrimitive->m_colorG,
						pBoxPrimitive->m_colorB,
						pBoxPrimitive->m_colorA)
				);
			}
		}

		BoxRenderer::EndRenderBox();
	}

	pCurrentFrameConstantsBuffer = nullptr;
}

void c_primitive_render_manager::SetupConstantBuffers()
{
	if (ppFrameConstantsBuffers[kNumConstantsBuffers - 1] == nullptr)
	{
		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufferDesc.ByteWidth = sizeof(PerFrameConstants);
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		for (uint32_t i = 0; i < kNumConstantsBuffers; i++)
		{
			ID3D11Buffer*& pConstantsBuffer = ppFrameConstantsBuffers[i];

			HRESULT createBufferResult = c_render::s_pDevice->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			ASSERT(SUCCEEDED(createBufferResult));
			ASSERT(pConstantsBuffer != nullptr);
		}
	}
}

void c_primitive_render_manager::GetNextConstantsBuffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % kNumConstantsBuffers;
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

void c_primitive_render_manager::MapConstantsBuffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = c_render::s_pDeviceContext->Map(pCurrentFrameConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	ASSERT(SUCCEEDED(mapResult));

	// contigious memory
	pPerFrameConstantsArray = static_cast<PerFrameConstants*>(mappedResource.pData);
}

void c_primitive_render_manager::UnmapConstantsBuffer()
{
	c_render::s_pDeviceContext->Unmap(pCurrentFrameConstantsBuffer, 0);
	pPerFrameConstantsArray = nullptr;
}

void c_primitive_render_manager::UpdateConstantsBuffer()
{
	GetNextConstantsBuffer();
	MapConstantsBuffer();

	PerFrameConstants& rPerFrameConstants = *pPerFrameConstantsArray;
	rPerFrameConstants.m_viewMatrix = c_render::viewMatrixTransposed;
	rPerFrameConstants.m_perspectiveMatrix = c_render::perspectiveMatrixTransposed;

	UnmapConstantsBuffer();
}

c_box_primitive& c_primitive_render_manager::get_immediate_box()
{
	return immediateBoxPrimitive;
}

