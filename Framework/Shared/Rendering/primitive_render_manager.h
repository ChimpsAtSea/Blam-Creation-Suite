#pragma once

class c_box_primitive;
struct BoxPrimitiveData;

class c_primitive_render_manager
{
public:
	struct alignas(256) PerFrameConstants
	{
		DirectX::XMMATRIX view_matrix;
		DirectX::XMMATRIX perspective_matrix;
	};

	static constexpr uint32_t k_num_constants_buffers = 3;

	static ID3D11Buffer* ppFrameConstantsBuffers[k_num_constants_buffers];
	static PerFrameConstants* pPerFrameConstantsArray;
	static ID3D11Buffer* pCurrentFrameConstantsBuffer;
	static volatile uint32_t next_constant_buffer_index;

	static c_box_primitive immediateBoxPrimitive;


	static std::vector<c_box_primitive*> s_boxPrimitives;
	static std::vector<BoxPrimitiveData> s_immediateBoxPrimitives;

	static void render();
	static ID3D11Buffer* const& GetConstantsBuffer();

	static void register_box_primitive(c_box_primitive* box_primitive);
	static void unregister_box_primitive(c_box_primitive* box_primitive);

	static c_box_primitive& get_immediate_box();
	static void render_immediate_box();

	inline static DirectX::XMFLOAT3 __vectorcall GetCameraForward() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_forward); return result; }
	inline static DirectX::XMFLOAT3 __vectorcall GetCameraUp() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_up); return result; }
	inline static DirectX::XMFLOAT3 __vectorcall GetCameraPosition() { DirectX::XMFLOAT3 result;  DirectX::XMStoreFloat3(&result, s_position); return result; }

private:
	static DirectX::XMVECTOR s_forward;
	static DirectX::XMVECTOR s_up;
	static DirectX::XMVECTOR s_position;

	static void setup_constants_buffers();
	static void get_next_constants_buffer();
	static void map_constants_buffer();
	static void unmap_constants_buffer();
	static void UpdateConstantsBuffer();
};

