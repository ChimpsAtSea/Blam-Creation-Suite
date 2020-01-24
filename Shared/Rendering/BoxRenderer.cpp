#include "shared-private-pch.h"

ID3D11InputLayout* BoxRenderer::pVertexLayout;
ID3D11PixelShader* BoxRenderer::pPixelShader = nullptr;
ID3D11VertexShader* BoxRenderer::pVertexShader = nullptr;
ID3D11RasterizerState* BoxRenderer::pSolidRasterState = nullptr;
ID3D11RasterizerState* BoxRenderer::pWireframeRasterState = nullptr;
ID3D11Buffer* BoxRenderer::pVertexBuffer = nullptr;
ID3D11Buffer* BoxRenderer::pIndexBuffer = nullptr;
volatile uint32_t BoxRenderer::nextConstantBufferIndex = 0;
volatile uint32_t BoxRenderer::nextBoxIndex = 0;
ID3D11Buffer* BoxRenderer::ppInstanceConstantsBuffers[PrimitiveRenderManager::kNumConstantsBuffers] = {};
ID3D11Buffer* BoxRenderer::pCurrentInstanceConstantsBuffer = nullptr;
BoxRenderer::PerObjectConstants* BoxRenderer::pPerObjectConstantsArray = nullptr;

void BoxRenderer::SetupGeometry()
{
	using namespace DirectX;

	if (pVertexBuffer == nullptr)
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

		HRESULT createBufferResult = Render::s_pDevice->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pVertexBuffer);
		assert(SUCCEEDED(createBufferResult));
		assert(pVertexBuffer != nullptr);
	}

	if (pIndexBuffer == nullptr)
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

		HRESULT createBufferResult = Render::s_pDevice->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pIndexBuffer);
		assert(SUCCEEDED(createBufferResult));
		assert(pIndexBuffer != nullptr);
	}
}

void BoxRenderer::SetupShaders()
{
	if (pPixelShader == nullptr)
	{
		char* pShaderBinary = nullptr;
		size_t shaderFileLength = 0;
		if (!ResourcesManager::GetResource(ResourceType::BoxPixelShader, &pShaderBinary, &shaderFileLength))
		{
			WriteLineVerbose("Warning: Failed to find Box Pixel Vertex resource! Attempting to read BoxShaderPS.cso");
			pShaderBinary = FileSystemReadToMemory(L"BoxShaderPS.cso", &shaderFileLength);
		}
		assert(pShaderBinary != nullptr);

		Render::s_pDevice->CreatePixelShader(pShaderBinary, shaderFileLength, NULL, &pPixelShader);
		assert(pPixelShader != nullptr);

		delete[] pShaderBinary;
	}

	char* pVertexShaderBinary = nullptr;
	size_t vertexShaderBinaryLength = 0;
	if (pVertexShader == nullptr)
	{
		if (!ResourcesManager::GetResource(ResourceType::BoxVertexShader, &pVertexShaderBinary, &vertexShaderBinaryLength))
		{
			WriteLineVerbose("Warning: Failed to find Box Pixel Vertex resource! Attempting to read BoxShaderVS.cso");
			pVertexShaderBinary = FileSystemReadToMemory(L"BoxShaderVS.cso", &vertexShaderBinaryLength);
		}
		assert(pVertexShaderBinary != nullptr);

		Render::s_pDevice->CreateVertexShader(pVertexShaderBinary, vertexShaderBinaryLength, NULL, &pVertexShader);
		assert(pVertexShader != nullptr);
	}

	if (pSolidRasterState == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_SOLID;
		rasterizerDescription.CullMode = D3D11_CULL_BACK;
		Render::s_pDevice->CreateRasterizerState(&rasterizerDescription, &pSolidRasterState);
	}

	if (pWireframeRasterState == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_WIREFRAME;
		rasterizerDescription.CullMode = D3D11_CULL_NONE;
		Render::s_pDevice->CreateRasterizerState(&rasterizerDescription, &pWireframeRasterState);
	}

	if (pVertexLayout == nullptr)
	{
		D3D11_INPUT_ELEMENT_DESC inputDescriptions[1] = {};

		inputDescriptions[0].SemanticName = "POSITION";
		inputDescriptions[0].SemanticIndex = 0;
		inputDescriptions[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputDescriptions[0].InputSlot = 0;
		inputDescriptions[0].AlignedByteOffset = 0;
		inputDescriptions[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputDescriptions[0].InstanceDataStepRate = 0;

		HRESULT createInputLayoutResult = Render::s_pDevice->CreateInputLayout(inputDescriptions, 1, pVertexShaderBinary, vertexShaderBinaryLength, &pVertexLayout);
		assert(SUCCEEDED(createInputLayoutResult));
		assert(pVertexLayout != nullptr);
	}

	if (pVertexShaderBinary != nullptr)
	{
		delete[] pVertexShaderBinary;
	}
}

void BoxRenderer::SetupConstantBuffers()
{
	if (ppInstanceConstantsBuffers[PrimitiveRenderManager::kNumConstantsBuffers - 1] == nullptr)
	{
		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufferDesc.ByteWidth = sizeof(PerObjectConstants) * kMaxBoxesPerFrame;
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		for (uint32_t i = 0; i < PrimitiveRenderManager::kNumConstantsBuffers; i++)
		{
			ID3D11Buffer*& pConstantsBuffer = ppInstanceConstantsBuffers[i];

			HRESULT createBufferResult = Render::s_pDevice->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			assert(SUCCEEDED(createBufferResult));
			assert(pConstantsBuffer != nullptr);
		}
	}
}

void BoxRenderer::GetNextConstantsBuffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % PrimitiveRenderManager::kNumConstantsBuffers;
	pCurrentInstanceConstantsBuffer = ppInstanceConstantsBuffers[currentConstantBufferIndex];
	assert(pCurrentInstanceConstantsBuffer != nullptr);
}

void BoxRenderer::MapConstantsBuffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = Render::s_pDeviceContext->Map(pCurrentInstanceConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	assert(SUCCEEDED(mapResult));

	// contigious memory
	pPerObjectConstantsArray = static_cast<PerObjectConstants*>(mappedResource.pData);
}

void BoxRenderer::UnmapConstantsBuffer()
{
	Render::s_pDeviceContext->Unmap(pCurrentInstanceConstantsBuffer, 0);
	pPerObjectConstantsArray = nullptr;
}

void BoxRenderer::BeginRenderBox()
{
	SetupShaders();
	SetupGeometry();
	SetupConstantBuffers();
	GetNextConstantsBuffer();
	MapConstantsBuffer();
}

void BoxRenderer::RenderBox(
	DirectX::XMFLOAT3 const& position,
	DirectX::XMFLOAT3 const& dimensions,
	DirectX::XMFLOAT4 const& color
)
{
	using namespace DirectX;

	uint32_t currentBoxIndex = InterlockedIncrement(&nextBoxIndex) - 1;

	if (currentBoxIndex >= kMaxBoxesPerFrame)
	{
		return; // we've hit the maximum number of boxes that we can render per frame
	}

	PerObjectConstants& rPerObjectConstants = pPerObjectConstantsArray[currentBoxIndex];
	rPerObjectConstants.m_modelMatrix = XMMatrixScaling(dimensions.x, dimensions.y, dimensions.z);
	rPerObjectConstants.m_modelMatrix *= XMMatrixTranslation(position.x, position.y, position.z);
	rPerObjectConstants.m_modelMatrix = XMMatrixTranspose(rPerObjectConstants.m_modelMatrix);
	rPerObjectConstants.m_color = color;

}

void BoxRenderer::RenderBoxGeometry()
{
	using namespace DirectX;

	if (nextBoxIndex > 0)
	{
		const UINT vertexStride = sizeof(XMFLOAT3);
		const UINT vertexOffset = 0;

		Render::s_pDeviceContext->RSSetState(pWireframeRasterState);
		Render::s_pDeviceContext->VSSetShader(pVertexShader, NULL, 0);
		Render::s_pDeviceContext->PSSetShader(pPixelShader, NULL, 0);
		Render::s_pDeviceContext->IASetInputLayout(pVertexLayout);
		Render::s_pDeviceContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &vertexStride, &vertexOffset);
		Render::s_pDeviceContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		Render::s_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		const uint32_t maxInstances = 4096 / sizeof(PerObjectConstants);
		//const uint32_t maxInstancesPow2 = 1u << ilogb(maxInstances);
		const uint32_t maxInstancesPow2 = 16;

		Render::s_pDeviceContext->VSSetConstantBuffers(0, 1, &PrimitiveRenderManager::GetConstantsBuffer());
		Render::s_pDeviceContext->PSSetConstantBuffers(0, 1, &PrimitiveRenderManager::GetConstantsBuffer());

		const uint32_t numBoxes = min(kMaxBoxesPerFrame, nextBoxIndex);
		for (uint32_t i = 0; i < numBoxes;)
		{
			uint32_t remainingBoxes = numBoxes - i;
			uint32_t boxesToDrawThisCall = min(remainingBoxes, maxInstancesPow2);

			boxesToDrawThisCall = 1; // #TODO: Rendering more than 1 box at a time causes issues. Not sure why.

			UINT firstConstant = (sizeof(PerObjectConstants) * i) / 16;
			UINT numConstants = sizeof(PerObjectConstants);

			Render::s_pDeviceContext->VSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);
			Render::s_pDeviceContext->PSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);
			Render::s_pDeviceContext->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);

			i += boxesToDrawThisCall;
		}
	}
}

void BoxRenderer::EndRenderBox()
{
	using namespace DirectX;

	UnmapConstantsBuffer();

	RenderBoxGeometry();

	pCurrentInstanceConstantsBuffer = nullptr;
	nextBoxIndex = 0;
}

