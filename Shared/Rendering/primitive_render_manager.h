#pragma once

class c_box_primitive;
struct BoxPrimitiveData;

class c_primitive_render_manager
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

	static c_box_primitive immediateBoxPrimitive;


	static std::vector<c_box_primitive*> s_boxPrimitives;
	static std::vector<BoxPrimitiveData> s_immediateBoxPrimitives;

	static void render();
	static ID3D11Buffer* const& GetConstantsBuffer();

	static void RegisterBoxPrimitive(c_box_primitive* pBoxPrimitive);
	static void UnregisterBoxPrimitive(c_box_primitive* pBoxPrimitive);

	static c_box_primitive& get_immediate_box();
	static void render_immediate_box();

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

