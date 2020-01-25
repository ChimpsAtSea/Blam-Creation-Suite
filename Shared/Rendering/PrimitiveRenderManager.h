#pragma once

class BoxPrimitive;

class PrimitiveRenderManager
{
public:
	struct alignas(256) PerFrameConstants
	{
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_perspectiveMatrix;
	};

	static constexpr uint32_t kNumConstantsBuffers = 3;

	static ID3D11Buffer* ppFrameConstantsBuffers[kNumConstantsBuffers];
	static PerFrameConstants* pPerFrameConstantsArray;
	static ID3D11Buffer* pCurrentFrameConstantsBuffer;
	static volatile uint32_t nextConstantBufferIndex;

	static DirectX::XMMATRIX viewMatrix;
	static DirectX::XMMATRIX perspectiveMatrix;
	static DirectX::XMMATRIX viewMatrixTransposed;
	static DirectX::XMMATRIX perspectiveMatrixTransposed;

	static float s_fieldOfViewHorizontal;
	static float s_fieldOfViewVertical;
	static float s_aspectRatio;

	static std::vector<BoxPrimitive*> s_boxPrimitives;
	static std::vector<BoxPrimitive> s_immediateBoxPrimitives;

	static void UpdatePerspective(float fieldOfViewHorizontal, float aspectRatio);
	static void UpdateView(
		float forwardX,
		float forwardY,
		float forwardZ,
		float upX,
		float upY,
		float upZ,
		float positionX,
		float positionY,
		float positionZ
	);
	static void Render();
	static ID3D11Buffer* const& GetConstantsBuffer();

	static void ImmediateRenderBoxPrimitive(BoxPrimitive& rBoxPrimitive);
	static void RegisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);
	static void UnregisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);
	static bool CalculateScreenCoordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY);

private:
	static void SetupConstantBuffers();
	static void GetNextConstantsBuffer();
	static void MapConstantsBuffer();
	static void UnmapConstantsBuffer();
	static void UpdateConstantsBuffer();
};

