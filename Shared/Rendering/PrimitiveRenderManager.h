#pragma once

class BoxPrimitive;
struct BoxPrimitiveData;

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
	static BoxPrimitive immediateBoxPrimitive;

	static float s_fieldOfViewHorizontal;
	static float s_fieldOfViewVertical;
	static float s_aspectRatio;

	static std::vector<BoxPrimitive*> s_boxPrimitives;
	static std::vector<BoxPrimitiveData> s_immediateBoxPrimitives;

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

	static void RegisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);
	static void UnregisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);
	static bool CalculateScreenCoordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY);

	static BoxPrimitive& GetImmediateBox();
	static void RenderImmediateBox();

	inline static DirectX::XMFLOAT3 __vectorcall GetCameraForward() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_vForward); return result; }
	inline static DirectX::XMFLOAT3 __vectorcall GetCameraUp() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_vUp); return result; }
	inline static DirectX::XMFLOAT3 __vectorcall GetCameraPosition() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_vPosition); return result; }

private:
	static DirectX::XMVECTOR s_vForward;
	static DirectX::XMVECTOR s_vUp;
	static DirectX::XMVECTOR s_vPosition;

	static void SetupConstantBuffers();
	static void GetNextConstantsBuffer();
	static void MapConstantsBuffer();
	static void UnmapConstantsBuffer();
	static void UpdateConstantsBuffer();
};

