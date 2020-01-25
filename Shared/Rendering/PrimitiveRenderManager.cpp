#include "shared-private-pch.h"

using namespace DirectX;

PrimitiveRenderManager::PerFrameConstants* PrimitiveRenderManager::pPerFrameConstantsArray = nullptr;
ID3D11Buffer* PrimitiveRenderManager::pCurrentFrameConstantsBuffer = nullptr;
ID3D11Buffer* PrimitiveRenderManager::ppFrameConstantsBuffers[kNumConstantsBuffers] = {};
DirectX::XMMATRIX PrimitiveRenderManager::viewMatrix = {};
DirectX::XMMATRIX PrimitiveRenderManager::perspectiveMatrix = {};
DirectX::XMMATRIX PrimitiveRenderManager::viewMatrixTransposed = {};
DirectX::XMMATRIX PrimitiveRenderManager::perspectiveMatrixTransposed = {};
BoxPrimitive PrimitiveRenderManager::immediateBoxPrimitive;
float PrimitiveRenderManager::s_fieldOfViewHorizontal = 0.0f;
float PrimitiveRenderManager::s_fieldOfViewVertical = 0.0f;
float PrimitiveRenderManager::s_aspectRatio = 0.0f;
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

void PrimitiveRenderManager::UpdatePerspective(float fieldOfViewHorizontal, float aspectRatio)
{
	bool isDifferent = s_fieldOfViewHorizontal != fieldOfViewHorizontal || s_aspectRatio != aspectRatio;
	if (!isDifferent) // avoid updating if we don't need to
	{
		return;
	}

	s_fieldOfViewHorizontal = fieldOfViewHorizontal;
	s_fieldOfViewVertical = atan(tanf(fieldOfViewHorizontal / 2.0f) / aspectRatio) * 2.0f;
	s_aspectRatio = aspectRatio;

	perspectiveMatrix = XMMatrixPerspectiveFovRH(s_fieldOfViewVertical, aspectRatio, 0.01f, 10000.0f);
	perspectiveMatrixTransposed = XMMatrixTranspose(perspectiveMatrix);
}

void PrimitiveRenderManager::UpdateView(
	float forwardX,
	float forwardY,
	float forwardZ,
	float upX,
	float upY,
	float upZ,
	float positionX,
	float positionY,
	float positionZ
)
{
	XMVECTOR vForward		=	{ forwardX, forwardY, forwardZ };
	XMVECTOR vUp			=	{ upX, upY, upZ };
	XMVECTOR vPosition		=	{ positionX, positionY, positionZ };

	vUp = XMVector3Normalize(vUp);
	vForward = XMVector3Normalize(vForward);

	viewMatrix = XMMatrixLookAtRH(vPosition, vPosition + vForward, vUp);
	viewMatrixTransposed = XMMatrixTranspose(viewMatrix);
}

void PrimitiveRenderManager::Render()
{
	SetupConstantBuffers();
	UpdateConstantsBuffer();

	static bool enablePrimitiveDebug = CommandLine::HasCommandLineArg("-primitivedebug");
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
			assert(SUCCEEDED(createBufferResult));
			assert(pConstantsBuffer != nullptr);
		}
	}
}

void PrimitiveRenderManager::GetNextConstantsBuffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % kNumConstantsBuffers;
	pCurrentFrameConstantsBuffer = ppFrameConstantsBuffers[currentConstantBufferIndex];
	assert(pCurrentFrameConstantsBuffer != nullptr);
}

ID3D11Buffer* const& PrimitiveRenderManager::GetConstantsBuffer()
{
	assert(pCurrentFrameConstantsBuffer != nullptr);
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
	assert(SUCCEEDED(mapResult));

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
	rPerFrameConstants.m_viewMatrix = viewMatrixTransposed;
	rPerFrameConstants.m_perspectiveMatrix = perspectiveMatrixTransposed;

	UnmapConstantsBuffer();
}

bool PrimitiveRenderManager::CalculateScreenCoordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY)
{
	XMVECTOR pV = { positionX, positionY, positionZ, 1.0f };
	float Height = (float)Window::GetWindowHeight();
	float Width = (float)Window::GetWindowWidth();

	DirectX::XMMATRIX pWorld = DirectX::XMMatrixIdentity();
	DirectX::XMMATRIX pProjection = perspectiveMatrix;
	DirectX::XMMATRIX pView = viewMatrix;

	DirectX::XMVECTOR  pOut = XMVector3Project(pV, 0, 0, Width, Height, 0, 1, pProjection, pView, pWorld);
	DirectX::XMFLOAT3 pOut3d;
	DirectX::XMStoreFloat3(&pOut3d, pOut);

	if (pOut3d.z < 1.0f)
	{
		screenX = pOut3d.x;
		screenY = pOut3d.y;
		return true;
	}
	return false;
}

BoxPrimitive& PrimitiveRenderManager::GetImmediateBox()
{
	return immediateBoxPrimitive;
}

