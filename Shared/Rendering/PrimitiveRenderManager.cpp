#include "shared-private-pch.h"

using namespace DirectX;

PrimitiveRenderManager::PerFrameConstants* PrimitiveRenderManager::pPerFrameConstantsArray = nullptr;
ID3D11Buffer* PrimitiveRenderManager::pCurrentFrameConstantsBuffer = nullptr;
ID3D11Buffer* PrimitiveRenderManager::ppFrameConstantsBuffers[kNumConstantsBuffers] = {};
BoxPrimitive PrimitiveRenderManager::immediateBoxPrimitive;
volatile uint32_t PrimitiveRenderManager::nextConstantBufferIndex = 0;
DirectX::XMVECTOR PrimitiveRenderManager::s_vForward;
DirectX::XMVECTOR PrimitiveRenderManager::s_vUp;
DirectX::XMVECTOR PrimitiveRenderManager::s_vPosition;

std::vector<BoxPrimitive*> PrimitiveRenderManager::s_boxPrimitives;
std::vector<BoxPrimitiveData> PrimitiveRenderManager::s_immediateBoxPrimitives;

void PrimitiveRenderManager::RegisterBoxPrimitive(BoxPrimitive* pBoxPrimitive)
{
	if (pBoxPrimitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.emplace_back(pBoxPrimitive);
	}
}

void PrimitiveRenderManager::UnregisterBoxPrimitive(BoxPrimitive* pBoxPrimitive)
{
	if (pBoxPrimitive != &immediateBoxPrimitive)
	{
		// #TODO: Thread safe linked list
		s_boxPrimitives.erase(std::remove(s_boxPrimitives.begin(), s_boxPrimitives.end(), pBoxPrimitive), s_boxPrimitives.end());
	}
}

void PrimitiveRenderManager::Render()
{
	SetupConstantBuffers();
	UpdateConstantsBuffer();

	static bool enablePrimitiveDebug = c_command_line::has_command_line_arg("-primitivedebug");
	if (enablePrimitiveDebug)
	{
		static BoxPrimitive debugBox;
		debugBox.UpdateAsCenteredBox(
			0.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 1.0f
		);
		debugBox.SetColor(1.0f, 0.0f, 1.0f, 1.0f);
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

		for (const BoxPrimitive* pBoxPrimitive : s_boxPrimitives)
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

void PrimitiveRenderManager::SetupConstantBuffers()
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

			HRESULT createBufferResult = Render::s_pDevice->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			ASSERT(SUCCEEDED(createBufferResult));
			ASSERT(pConstantsBuffer != nullptr);
		}
	}
}

void PrimitiveRenderManager::GetNextConstantsBuffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % kNumConstantsBuffers;
	pCurrentFrameConstantsBuffer = ppFrameConstantsBuffers[currentConstantBufferIndex];
	ASSERT(pCurrentFrameConstantsBuffer != nullptr);
}

ID3D11Buffer* const& PrimitiveRenderManager::GetConstantsBuffer()
{
	ASSERT(pCurrentFrameConstantsBuffer != nullptr);
	return pCurrentFrameConstantsBuffer;
}

void PrimitiveRenderManager::RenderImmediateBox()
{
	if (immediateBoxPrimitive.IsVisible())
	{
		s_immediateBoxPrimitives.emplace_back(GetImmediateBox());
	}
}

void PrimitiveRenderManager::MapConstantsBuffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = Render::s_pDeviceContext->Map(pCurrentFrameConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	ASSERT(SUCCEEDED(mapResult));

	// contigious memory
	pPerFrameConstantsArray = static_cast<PerFrameConstants*>(mappedResource.pData);
}

void PrimitiveRenderManager::UnmapConstantsBuffer()
{
	Render::s_pDeviceContext->Unmap(pCurrentFrameConstantsBuffer, 0);
	pPerFrameConstantsArray = nullptr;
}

void PrimitiveRenderManager::UpdateConstantsBuffer()
{
	GetNextConstantsBuffer();
	MapConstantsBuffer();

	PerFrameConstants& rPerFrameConstants = *pPerFrameConstantsArray;
	rPerFrameConstants.m_viewMatrix = Render::viewMatrixTransposed;
	rPerFrameConstants.m_perspectiveMatrix = Render::perspectiveMatrixTransposed;

	UnmapConstantsBuffer();
}

BoxPrimitive& PrimitiveRenderManager::GetImmediateBox()
{
	return immediateBoxPrimitive;
}

