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

	static BoxPrimitive immediateBoxPrimitive;


	static std::vector<BoxPrimitive*> s_boxPrimitives;
	static std::vector<BoxPrimitiveData> s_immediateBoxPrimitives;

	static void Render();
	static ID3D11Buffer* const& GetConstantsBuffer();

	static void RegisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);
	static void UnregisterBoxPrimitive(BoxPrimitive* pBoxPrimitive);

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

