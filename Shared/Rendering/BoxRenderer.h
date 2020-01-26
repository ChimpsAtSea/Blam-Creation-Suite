#pragma once

class BoxRenderer
{
public:
	struct alignas(256) PerObjectConstants
	{
		DirectX::XMMATRIX m_modelMatrix;
		DirectX::XMFLOAT4 m_color;
	};

	static constexpr uint32_t kMaxBoxesPerFrame = 128 * 1024;

	static ID3D11PixelShader* pPixelShader;
	static ID3D11VertexShader* pVertexShader;
	static ID3D11RasterizerState* pSolidRasterState;
	static ID3D11RasterizerState* pWireframeRasterState;
	static ID3D11InputLayout* pVertexLayout;
	static ID3D11Buffer* pVertexBuffer;
	static ID3D11Buffer* pSolidIndexBuffer;
	static ID3D11Buffer* pWireframeIndexBuffer;
	static volatile uint32_t nextConstantBufferIndex;
	static volatile uint32_t nextBoxIndex;
	static ID3D11Buffer* pCurrentInstanceConstantsBuffer;
	static PerObjectConstants* pPerObjectConstantsArray;
	static ID3D11Buffer* ppInstanceConstantsBuffers[PrimitiveRenderManager::kNumConstantsBuffers];

	static void BeginRenderBox();
	static void RenderBox(
		DirectX::XMFLOAT3 const& position,
		DirectX::XMFLOAT3 const& dimensions,
		DirectX::XMFLOAT4 const& color
	);
	static void EndRenderBox();
private:
	static void SetupSolidGeometry();
	static void SetupWireframeGeometry();
	static void SetupShaders();
	static void SetupConstantBuffers();
	static void GetNextConstantsBuffer();
	static void MapConstantsBuffer();
	static void UnmapConstantsBuffer();
	static void RenderBoxGeometry();
};

