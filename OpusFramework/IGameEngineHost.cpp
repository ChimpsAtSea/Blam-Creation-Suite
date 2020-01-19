#include "opusframework-private-pch.h"
#ifdef auto
#undef auto
#endif
#include <DirectXMath.h>

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

IGameEngineHost::IGameEngineHost()
	:pGameEvents(&IGameEvents::g_gameEvents)
{

}

IGameEngineHost::~IGameEngineHost()
{

}

char __fastcall IGameEngineHost::Member00()
{
	//WriteLineVerbose("IGameEngineHost::Member00");
	return 0;
}

struct real_vector3d
{
	float I, J, K;
};

struct s_observer_camera
{
	real_vector3d position;
	real_vector3d position_shift;
	float look;
	float look_shift;
	float depth;
	float unknown0;
	real_vector3d forward;
	real_vector3d up;
	float field_of_view;
	float unknown1;
	float unknown2;
};

intptr_t player_mapping_get_local_player_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x18006FDF0;
	}
	return ~intptr_t();
}
FunctionHookEx<player_mapping_get_local_player_offset, int __stdcall ()> player_mapping_get_local_player;

intptr_t observer_try_and_get_camera_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_1270_0_0: return 0x1800E2FA0;
	}
	return ~intptr_t();
}
FunctionHookEx<observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> observer_try_and_get_camera;

class BoxRenderer
{
public:
	struct alignas(16) PerFrameConstants
	{
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_perspectiveMatrix;
	};

	struct alignas(256) PerObjectConstants
	{
		DirectX::XMMATRIX m_modelMatrix;
		DirectX::XMFLOAT4 m_color;
	};

	static constexpr uint32_t kNumConstantsBuffers = 4;
	static constexpr uint32_t kMaxBoxesPerFrame = 1024 * 1024;

	static ID3D11PixelShader* pPixelShader;
	static ID3D11VertexShader* pVertexShader;
	static ID3D11RasterizerState* pSolidRasterState;
	static ID3D11RasterizerState* pWireframeRasterState;
	static ID3D11InputLayout* pVertexLayout;
	static ID3D11Buffer* pVertexBuffer;
	static ID3D11Buffer* pIndexBuffer;
	static volatile uint32_t nextConstantBufferIndex;
	static volatile uint32_t nextBoxIndex;
	static ID3D11Buffer* pCurrentInstanceConstantsBuffer;
	static ID3D11Buffer* pCurrentFrameConstantsBuffer;
	static PerObjectConstants* pPerObjectConstantsArray;
	static PerFrameConstants* pPerFrameConstantsArray;
	static ID3D11Buffer* ppInstanceConstantsBuffers[kNumConstantsBuffers];
	static ID3D11Buffer* ppFrameConstantsBuffers[kNumConstantsBuffers];

	static void SetupGeometry()
	{
		using namespace DirectX;

		if (pVertexBuffer == nullptr)
		{
			static XMFLOAT3 vertexData[] = {
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

			HRESULT createBufferResult = GameRender::s_pDevice->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pVertexBuffer);
			assert(SUCCEEDED(createBufferResult));
			assert(pVertexBuffer != nullptr);
		}

		if (pIndexBuffer == nullptr)
		{
			static const uint32_t boxIndices[] = {
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

			HRESULT createBufferResult = GameRender::s_pDevice->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pIndexBuffer);
			assert(SUCCEEDED(createBufferResult));
			assert(pIndexBuffer != nullptr);
		}
	}

	static void SetupShaders()
	{
		if (pPixelShader == nullptr)
		{
			size_t shaderFileLength = 0;
			char* pShaderBinary = opus::FileSystemReadToMemory(L"BoxShaderPS.cso", &shaderFileLength);
			assert(pShaderBinary != nullptr);

			GameRender::s_pDevice->CreatePixelShader(pShaderBinary, shaderFileLength, NULL, &pPixelShader);
			assert(pPixelShader != nullptr);

			delete[] pShaderBinary;
		}

		char* pVertexShaderBinary = nullptr;
		size_t vertexShaderBinaryLength = 0;
		if (pVertexShader == nullptr)
		{
			pVertexShaderBinary = opus::FileSystemReadToMemory(L"BoxShaderVS.cso", &vertexShaderBinaryLength);
			assert(pVertexShaderBinary != nullptr);

			GameRender::s_pDevice->CreateVertexShader(pVertexShaderBinary, vertexShaderBinaryLength, NULL, &pVertexShader);
			assert(pVertexShader != nullptr);
		}

		if (pSolidRasterState == nullptr)
		{
			D3D11_RASTERIZER_DESC rasterizerDescription = {};
			rasterizerDescription.FillMode = D3D11_FILL_SOLID;
			rasterizerDescription.CullMode = D3D11_CULL_BACK;
			GameRender::s_pDevice->CreateRasterizerState(&rasterizerDescription, &pSolidRasterState);
		}

		if (pWireframeRasterState == nullptr)
		{
			D3D11_RASTERIZER_DESC rasterizerDescription = {};
			rasterizerDescription.FillMode = D3D11_FILL_WIREFRAME;
			rasterizerDescription.CullMode = D3D11_CULL_NONE;
			GameRender::s_pDevice->CreateRasterizerState(&rasterizerDescription, &pWireframeRasterState);
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

			HRESULT createInputLayoutResult = GameRender::s_pDevice->CreateInputLayout(inputDescriptions, 1, pVertexShaderBinary, vertexShaderBinaryLength, &pVertexLayout);
			assert(SUCCEEDED(createInputLayoutResult));
			assert(pVertexLayout != nullptr);
		}

		if (pVertexShaderBinary != nullptr)
		{
			delete[] pVertexShaderBinary;
		}
	}

	static void SetupConstantBuffers()
	{
		if (ppInstanceConstantsBuffers[kNumConstantsBuffers - 1] == nullptr)
		{
			D3D11_BUFFER_DESC bufferDesc = {};
			bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
			bufferDesc.ByteWidth = sizeof(PerObjectConstants) * kMaxBoxesPerFrame;
			bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			bufferDesc.MiscFlags = 0;
			bufferDesc.StructureByteStride = 0;

			for (uint32_t i = 0; i < kNumConstantsBuffers; i++)
			{
				ID3D11Buffer*& pConstantsBuffer = ppInstanceConstantsBuffers[i];

				HRESULT createBufferResult = GameRender::s_pDevice->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
				assert(SUCCEEDED(createBufferResult));
				assert(pConstantsBuffer != nullptr);
			}
		}

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

				HRESULT createBufferResult = GameRender::s_pDevice->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
				assert(SUCCEEDED(createBufferResult));
				assert(pConstantsBuffer != nullptr);
			}
		}
	}

	static void GetNextConstantsBuffer()
	{
		uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % kNumConstantsBuffers;

		pCurrentInstanceConstantsBuffer = ppInstanceConstantsBuffers[currentConstantBufferIndex];
		pCurrentFrameConstantsBuffer = ppFrameConstantsBuffers[currentConstantBufferIndex];

		assert(pCurrentInstanceConstantsBuffer != nullptr);
		assert(pCurrentFrameConstantsBuffer != nullptr);
	}

	static void MapConstantsBuffer()
	{
		{
			D3D11_MAPPED_SUBRESOURCE mappedResource = {};
			HRESULT mapResult = GameRender::s_pDeviceContext->Map(pCurrentInstanceConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
			assert(SUCCEEDED(mapResult));

			// contigious memory
			pPerObjectConstantsArray = static_cast<PerObjectConstants*>(mappedResource.pData);
		}

		{
			D3D11_MAPPED_SUBRESOURCE mappedResource = {};
			HRESULT mapResult = GameRender::s_pDeviceContext->Map(pCurrentFrameConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
			assert(SUCCEEDED(mapResult));

			// contigious memory
			pPerFrameConstantsArray = static_cast<PerFrameConstants*>(mappedResource.pData);
		}
	}

	static void UnmapConstantsBuffer()
	{
		GameRender::s_pDeviceContext->Unmap(pCurrentInstanceConstantsBuffer, 0);
		GameRender::s_pDeviceContext->Unmap(pCurrentFrameConstantsBuffer, 0);

		pPerObjectConstantsArray = nullptr;
		pPerFrameConstantsArray = nullptr;
	}

	static void BeginRenderBox(
		DirectX::XMMATRIX const& viewMatrix,
		DirectX::XMMATRIX const& perspectiveMatrix
	)
	{
		SetupShaders();
		SetupGeometry();
		SetupConstantBuffers();

		GetNextConstantsBuffer();
		MapConstantsBuffer();

		PerFrameConstants& rPerFrameConstants = *pPerFrameConstantsArray;
		rPerFrameConstants.m_viewMatrix = viewMatrix;
		rPerFrameConstants.m_perspectiveMatrix = perspectiveMatrix;
	}

	static void RenderBox(
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

	static void EndRenderBox()
	{
		using namespace DirectX;

		UnmapConstantsBuffer();

		if (nextBoxIndex > 0)
		{
			static const UINT vertexStride = sizeof(XMFLOAT3);
			static const UINT vertexOffset = 0;

			GameRender::s_pDeviceContext->RSSetState(pWireframeRasterState);
			GameRender::s_pDeviceContext->VSSetShader(pVertexShader, NULL, 0);
			GameRender::s_pDeviceContext->PSSetShader(pPixelShader, NULL, 0);
			GameRender::s_pDeviceContext->IASetInputLayout(pVertexLayout);
			GameRender::s_pDeviceContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &vertexStride, &vertexOffset);
			GameRender::s_pDeviceContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
			GameRender::s_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

			static const uint32_t maxInstances = 4096 / sizeof(PerObjectConstants);
			//static const uint32_t maxInstancesPow2 = 1u << ilogb(maxInstances);
			static const uint32_t maxInstancesPow2 = 16;

			GameRender::s_pDeviceContext->VSSetConstantBuffers(0, 1, &pCurrentFrameConstantsBuffer);
			GameRender::s_pDeviceContext->PSSetConstantBuffers(0, 1, &pCurrentFrameConstantsBuffer);

			const uint32_t numBoxes = min(kMaxBoxesPerFrame, nextBoxIndex);
			for (uint32_t i = 0; i < numBoxes;)
			{
				uint32_t remainingBoxes = numBoxes - i;
				uint32_t boxesToDrawThisCall = min(remainingBoxes, maxInstancesPow2);

				boxesToDrawThisCall = 1; // #TODO: Rendering more than 1 box at a time causes issues. Not sure why.

				UINT firstConstant = (sizeof(PerObjectConstants) * i) / 16;
				UINT numConstants = sizeof(PerObjectConstants);

				GameRender::s_pDeviceContext->VSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);
				GameRender::s_pDeviceContext->PSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);
				GameRender::s_pDeviceContext->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);

				i += boxesToDrawThisCall;
			}
		}

		pCurrentFrameConstantsBuffer = nullptr;
		pCurrentInstanceConstantsBuffer = nullptr;
		nextBoxIndex = 0;
	}


};
ID3D11InputLayout* BoxRenderer::pVertexLayout;
ID3D11PixelShader* BoxRenderer::pPixelShader = nullptr;
ID3D11VertexShader* BoxRenderer::pVertexShader = nullptr;
ID3D11RasterizerState* BoxRenderer::pSolidRasterState = nullptr;
ID3D11RasterizerState* BoxRenderer::pWireframeRasterState = nullptr;
ID3D11Buffer* BoxRenderer::pVertexBuffer = nullptr;
ID3D11Buffer* BoxRenderer::pIndexBuffer = nullptr;
volatile uint32_t BoxRenderer::nextConstantBufferIndex = 0;
volatile uint32_t BoxRenderer::nextBoxIndex = 0;
ID3D11Buffer* BoxRenderer::ppInstanceConstantsBuffers[kNumConstantsBuffers] = {};
ID3D11Buffer* BoxRenderer::ppFrameConstantsBuffers[kNumConstantsBuffers] = {};
ID3D11Buffer* BoxRenderer::pCurrentInstanceConstantsBuffer = nullptr;
ID3D11Buffer* BoxRenderer::pCurrentFrameConstantsBuffer = nullptr;
BoxRenderer::PerObjectConstants* BoxRenderer::pPerObjectConstantsArray = nullptr;
BoxRenderer::PerFrameConstants* BoxRenderer::pPerFrameConstantsArray = nullptr;

void __fastcall IGameEngineHost::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD a2)
{
	using namespace DirectX;

	int playerIndex = player_mapping_get_local_player();
	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
	if (observer_camera)
	{
		XMMATRIX viewMatrix;
		XMMATRIX perspectiveMatrix;

		{
			XMVECTOR vForward = XMVECTOR();
			XMVECTOR vUp = XMVECTOR();
			XMVECTOR vPosition = XMVECTOR();
			{
				vForward.m128_f32[0] = observer_camera->forward.I;
				vForward.m128_f32[1] = observer_camera->forward.K;
				vForward.m128_f32[2] = observer_camera->forward.J;
				vUp.m128_f32[0] = observer_camera->up.I;
				vUp.m128_f32[1] = observer_camera->up.K;
				vUp.m128_f32[2] = observer_camera->up.J;
				vPosition.m128_f32[0] = observer_camera->position.I;
				vPosition.m128_f32[1] = observer_camera->position.K;
				vPosition.m128_f32[2] = observer_camera->position.J;
			}
			vUp = XMVector3Normalize(vUp);
			vForward = XMVector3Normalize(vForward);

			float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
			float fieldOfViewVertical = atan(tanf(observer_camera->field_of_view / 2.0f) / aspectRatio) * 2.0f;

			viewMatrix = XMMatrixLookAtLH(vPosition, vPosition + vForward, vUp);
			perspectiveMatrix = XMMatrixPerspectiveFovLH(fieldOfViewVertical, aspectRatio, 0.01f, 10000.0f);
			viewMatrix = XMMatrixTranspose(viewMatrix);
			perspectiveMatrix = XMMatrixTranspose(perspectiveMatrix);
		}

		BoxRenderer::BeginRenderBox(viewMatrix, perspectiveMatrix);

		static constexpr bool kEnableBoxRenderTest = false;
		if constexpr (kEnableBoxRenderTest)
		{
			int boxes = 100000;
			int width = sqrt(boxes);
			int length = boxes / width;

			XMFLOAT3 boxPosition2 = XMFLOAT3(0.0f, 0.0f, 0.0f);
			XMFLOAT3 boxDimensions2 = XMFLOAT3(1.0f, 1.0f, 1.0f);

			for (int i = 0; i < width; i++)
				for (int j = 0; j < length; j++)
				{
					XMFLOAT3 boxPosition2 = boxPosition2;
					boxPosition2.x += i;
					boxPosition2.z += j;

					XMFLOAT4 boxColor2 = XMFLOAT4(float(i) / float(width), float(j) / float(length), 0.0f, 1.0f);

					BoxRenderer::RenderBox(
						boxPosition2,
						boxDimensions2,
						boxColor2);
				}
		}

		XMFLOAT3 boxPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);
		XMFLOAT3 boxDimensions = XMFLOAT3(1.0f, 1.0f, 1.0f);
		XMFLOAT4 boxColor = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

		BoxRenderer::RenderBox(
			boxPosition,
			boxDimensions,
			boxColor);

		BoxRenderer::EndRenderBox();
	}

	static bool once = true;
	if (once)
	{
		once = false;
		DebugUI::RegisterCallback([]()
			{
				ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
				ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

				// Main body of the Demo window starts here.
				static bool isReachCameraDebugWindowOpen = true;
				if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
				{
					int playerIndex = player_mapping_get_local_player();
					s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);

					if (observer_camera)
					{
						ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
						ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
						ImGui::Text("look:           %f", observer_camera->look);
						ImGui::Text("look_shift:     %f", observer_camera->look_shift);
						ImGui::Text("depth:          %f", observer_camera->depth);
						ImGui::Text("unknown0:       %f", observer_camera->unknown0);
						ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
						ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
						ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
						ImGui::Text("unknown1:       %f", observer_camera->unknown1);
						ImGui::Text("unknown2:       %f", observer_camera->unknown2);
					}
					else
					{
						ImGui::Text("No camera present.");
					}
				}
				ImGui::End();

			});
	}


	DebugUI::RenderFrame();
}

void __fastcall IGameEngineHost::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	//WriteLineVerbose("IGameEngineHost::Member02");
}

void __fastcall IGameEngineHost::EngineStateUpdate(eEngineState state)
{
	const char* pEngineStateString = engine_state_to_string(state);
	WriteLineVerbose("IGameEngineHost::EngineStateUpdate (%d):%s", state, pEngineStateString);

	if (state != eEngineState::Unknown16) // `Unknown16` also needs a second arg so we skip it
	{
		switch (state)
		{
		case eEngineState::PushUIPage:
			WriteLineVerbose("Push UI stack");
			GameLauncher::s_uiStackLength++;
			break;
		case eEngineState::PopUIPage:
			WriteLineVerbose("Pop UI stack");
			GameLauncher::s_uiStackLength--;
			break;
		}

		GameLauncher::s_pHaloReachEngine->UpdateEngineState(state);
	}
}

__int64 __fastcall IGameEngineHost::GameExited(unsigned int a1, char* a2, int a3)
{
	GameLauncher::s_currentState = GameLauncher::CurrentState::eFinished;
	SplashScreen::Destroy();

	WriteLineVerbose("GameExited %u [%s]", a1, a2);
	return __int64(0);
}

__int64 __fastcall IGameEngineHost::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)
{
	WriteLineVerbose("IGameEngineHost::Member05 WriteBufferToFile %p %016llx", pBuffer, bufferSize);
	return __int64(0);
}

void __fastcall IGameEngineHost::Member06(s_game_results* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member06");
}

void __fastcall IGameEngineHost::Member07(unsigned int a1)
{
	if (GameLauncher::s_uiStackLength == 0)
	{
		WriteLineVerbose("IGameEngineHost::Member07 PauseMenuOpened");
		DebugUI::RegisterCallback(GameLauncher::DrawPauseMenu);
		DebugUI::Show();
	}
	else
	{
		WriteLineVerbose("IGameEngineHost::Member07 UI Stack is %i", static_cast<int>(GameLauncher::s_uiStackLength));
	}
}

void __fastcall IGameEngineHost::Member08(const wchar_t*, const wchar_t*)
{
	WriteLineVerbose("IGameEngineHost::Member08");
}

void __fastcall IGameEngineHost::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024])
{
	WriteLineVerbose("IGameEngineHost::Member09");
}

IGameEvents* __fastcall IGameEngineHost::GetGameEvents()
{
	return pGameEvents;
}

void __fastcall IGameEngineHost::UpdateGameVariant(IGameVariant* variant)
{
	WriteLineVerbose("IGameEngineHost::UpdateGameVariant");
}

void __fastcall IGameEngineHost::UpdateMapVariant(IMapVariant* variant)
{
	WriteLineVerbose("IGameEngineHost::UpdateMapVariant");
}

void __fastcall IGameEngineHost::Member13(const wchar_t*, const wchar_t*, const void*, unsigned int)
{
	WriteLineVerbose("IGameEngineHost::Member12");
}

char __fastcall IGameEngineHost::Member14(int controllerIndex, BYTE* flags)
{
	WriteLineVerbose("IGameEngineHost::Member13");
	return 0;
}

char __fastcall IGameEngineHost::Member15(int controllerIndex, BYTE* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member15");
	return 0;
}

char __fastcall IGameEngineHost::GetNextLevelInfo(e_map_id* map_id, int* campaign_insertion_point, FILETIME* filetime, _DWORD*)
{
	WriteLineVerbose("IGameEngineHost::Member16 GetNextLevelInfo");
	return 0;
}

bool __fastcall IGameEngineHost::Member17(int a1)
{
	WriteLineVerbose("IGameEngineHost::Member17");
	return false;
}

void __fastcall IGameEngineHost::Member18(int)
{
	WriteLineVerbose("IGameEngineHost::Member18");
}

__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	/*WriteLineVerbose("GameEngineHostCallback::Member19 MapLoadPecentStatus %016llx", a1);*/
	return __int64(0);
}

void __fastcall IGameEngineHost::Member20(__int64 a1, __int8 a2)
{
	WriteLineVerbose("IGameEngineHost::Member20");
}

__int64 __fastcall IGameEngineHost::GetMachineIdentifier(_QWORD a1)
{
	return __int64(3);
}

__int64 __fastcall IGameEngineHost::Member22(Member22Struct* buffer, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member22");
	return __int64(0);
}

char __fastcall IGameEngineHost::Member23(__int64 a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member23 ScoreboardOpened");
	return 1;
}

void __fastcall IGameEngineHost::GetSessionInfo(s_session_info_part* buffer)
{
	WriteVerbose("IGameEngineHost::GetSessionInfo");
}

void __fastcall IGameEngineHost::MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount)
{
	WriteLineVerbose("s_session_membership count: %i", pSessionMembership->Count);
	for (int i = 0; i < pSessionMembership->Count; i++)
	{
		WriteLineVerbose("MachineIdentifier[%i]: 0x%llx", i, pSessionMembership->Members[i].MachineIdentifier);

		pSessionMembership->Members[i].SecureAddress = -1;
	}

	//if (g_isHost)
	//{
	//	pSessionMembership->Count = 2;
	//	static int x = 1;
	//	pSessionMembership->Members[1].MachineIdentifier = x;
	//}

	//auto x = &pSessionMembership->Members[0].SecureAddress;

	WriteLineVerbose("IGameEngineHost::Member25 MembershipUpdate");
};

bool __fastcall IGameEngineHost::Member26()
{
	WriteLineVerbose("IGameEngineHost::Member26");
	return false;
}

bool __fastcall IGameEngineHost::Member27()
{
	//WriteLineVerbose("IGameEngineHost::Member27");
	return false;
}

bool __fastcall IGameEngineHost::UpdateGraphics(Member28Struct* buffer)
{
	// set resolution to 4k
	buffer->width = 3840;
	buffer->height = 2160;

	buffer->fps_flags = 0;

	WriteLineVerbose("IGameEngineHost::UpdateGraphics");

	// returning false effectively doubles fps when unlocked
	return buffer->fps_flags;
}

__int64 __fastcall IGameEngineHost::UpdatePlayerConfiguration(wchar_t playerNames[4][32], s_player_configuration& rPlayerConfiguration)
{
	assert(&rPlayerConfiguration);
	rPlayerConfiguration = {}; // reset values

	// sub_18004E800 applies customization conversion from MCC to Reach
	// TODO: get conversion table from sub_18004E800
	rPlayerConfiguration.is_elite = false;
	rPlayerConfiguration.armor_helmet_option = 0;
	rPlayerConfiguration.armor_left_shoulder_option = 0;
	rPlayerConfiguration.armor_right_shoulder_option = 0;
	rPlayerConfiguration.armor_chest_option = 0;
	rPlayerConfiguration.armor_wrist_option = 0;
	rPlayerConfiguration.armor_leg_utility_option = 0;
	rPlayerConfiguration.armor_knees_option = 0;
	rPlayerConfiguration.armor_effect_dupe_option = 0;
	rPlayerConfiguration.elite_armor_option = 0;
	rPlayerConfiguration.armor_effect_option = 0;
	rPlayerConfiguration.firefight_voice_option = 0;
	rPlayerConfiguration.primary_color_option = 13;   // HR_Color_Cobalt
	rPlayerConfiguration.secondary_color_option = 25;   // HR_Color_Yellow

	Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", rPlayerConfiguration.service_tag, 5, L"UNSC");

	// todo: find a good home for this
	SplashScreen::Destroy();

	//WriteStackBackTrace("IGameEngineHost::UpdatePlayerConfiguration");
	return __int64(1);
}

bool __fastcall IGameEngineHost::UpdateInput(_QWORD, InputBuffer* pInputBuffer)
{
	memset(pInputBuffer, 0, sizeof(*pInputBuffer));

	bool debugUIVisible = DebugUI::IsVisible();
	bool windowFocused = CustomWindow::IsWindowFocused();

	MouseMode mode = MouseMode::None;
	if (windowFocused)
	{
		mode = debugUIVisible ? MouseMode::UI : MouseMode::Exclusive;
	}
	MouseInput::SetMode(mode);

	// don't update and return an empty zero buffer
	if (debugUIVisible)
	{
		pInputBuffer->inputSource = InputSource::MouseAndKeyboard;
		return unsigned __int8(1);
	}

	static InputSource sCurrentInputSource = InputSource::MouseAndKeyboard;

	// grab controller
	// grab mouse and keyboard

	BYTE keyboardState[256] = {};
	float mouseInputX = 0;
	float mouseInputY = 0;
	bool leftButtonPressed = 0;
	bool rightButtonPressed = 0;
	bool middleButtonPressed = 0;

	bool hasControllerInput = false;
	bool hasMouseAndKeyboardInput = false;

	float fThumbLX = 0;
	float fThumbLY = 0;
	float fThumbRX = 0;
	float fThumbRY = 0;
	float fThumbL_Length = 0;
	float fThumbR_Length = 0;
	XINPUT_STATE xinputState = {};

	if (windowFocused || true)
	{
		DWORD xinputGetStateResult = XInputGetState(0, &xinputState);
		if (xinputGetStateResult == ERROR_SUCCESS)
		{
			hasControllerInput |= xinputState.Gamepad.wButtons != 0;
			hasControllerInput |= xinputState.Gamepad.bLeftTrigger != 0;
			hasControllerInput |= xinputState.Gamepad.bRightTrigger != 0;

			fThumbLX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLX));
			fThumbLY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLY));
			fThumbRX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRX));
			fThumbRY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRY));

			fThumbLX /= static_cast<float>(fThumbLX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbLY /= static_cast<float>(fThumbLY > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRX /= static_cast<float>(fThumbRX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRY /= static_cast<float>(fThumbRY > 0.0f ? INT16_MAX : -INT16_MIN);

			fThumbL_Length = sqrtf(fThumbLX * fThumbLX + fThumbLY * fThumbLY);
			fThumbR_Length = sqrtf(fThumbRX * fThumbRX + fThumbRY * fThumbRY);

			fThumbLX = sign(fThumbLX) * clamp(abs(fThumbLX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbLY = sign(fThumbLY) * clamp(abs(fThumbLY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRX = sign(fThumbRX) * clamp(abs(fThumbRX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRY = sign(fThumbRY) * clamp(abs(fThumbRY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);

			hasControllerInput |= fThumbL_Length > CONTROLLER_JOYSTICK_THRESHOLD;
			hasControllerInput |= fThumbR_Length > CONTROLLER_JOYSTICK_THRESHOLD;
		}

		{
			GetKeyState(-1); // force keys to update
			if (!GetKeyboardState(keyboardState))
				ZeroMemory(keyboardState, sizeof(keyboardState));

			mouseInputX = MouseInput::GetMouseX();
			mouseInputY = MouseInput::GetMouseY();

			leftButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Left);
			rightButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Right);
			middleButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Middle);

			{
				//for (size_t i = 0; i < sizeof(keyboardState); i++)
				//	hasMouseAndKeyboardInput |= keyboardState[i] != 0;

				hasMouseAndKeyboardInput |= mouseInputX != 0.0f;
				hasMouseAndKeyboardInput |= mouseInputY != 0.0f;
				hasMouseAndKeyboardInput |= leftButtonPressed;
				hasMouseAndKeyboardInput |= rightButtonPressed;
				hasMouseAndKeyboardInput |= middleButtonPressed;

				if (hasMouseAndKeyboardInput)
				{
					sCurrentInputSource = InputSource::MouseAndKeyboard;
				}
			}
		}
	}

	if (hasControllerInput)
	{
		sCurrentInputSource = InputSource::Gamepad;
	}
	else if (hasMouseAndKeyboardInput)
	{
		sCurrentInputSource = InputSource::MouseAndKeyboard;
	}

	if (sCurrentInputSource == InputSource::MouseAndKeyboard)
	{
		for (int i = 0; i < 256; i++)
		{
			pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
		}
		pInputBuffer->MouseX += mouseInputX;
		pInputBuffer->MouseY += mouseInputY;
		pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
		pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
		pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
	}

	if (sCurrentInputSource == InputSource::Gamepad)
	{
		pInputBuffer->wButtons = xinputState.Gamepad.wButtons;
		pInputBuffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
		pInputBuffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
		pInputBuffer->sThumbLX = fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbLY = fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbRX = fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbRY = fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN);
	}

	pInputBuffer->inputSource = sCurrentInputSource;

	return unsigned __int8(1);
}

void IGameEngineHost::Member31(_QWORD a1, float* a2)
{
	*a2 = 0.f;
	// WriteLineVerbose("IGameEngineHost::Member31"); // spams if fps is unlocked
}

void IGameEngineHost::Member32()
{
	WriteLineVerbose("IGameEngineHost::Member32");
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void IGameEngineHost::XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
{
	::XInputSetState(dwUserIndex, pVibration);
}

bool __fastcall IGameEngineHost::UpdatePlayerNames(__int64* playerIndices, wchar_t playerNames[4][32], size_t dataSize)
{
	if (playerNames && dataSize)
	{
		const wchar_t* ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };

		for (int i = 0; i < 4; i++)
		{
			static wchar_t pPlayerNameBuffer[4][16] = {};
			if (pPlayerNameBuffer[i][0] == 0)
			{
				const wchar_t* pName = ppNames[i];
				if (i == 0)
				{
					if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer[i], sizeof(pPlayerNameBuffer[i]), ppNames[i]) > 0)
					{
						pName = pPlayerNameBuffer[i];
					}
				}

				{
					if (wcsncmp(playerNames[i], pName, 16) == 0)
					{
						return true;
					}
					wcsncpy_s(playerNames[i], 32, pName, 16);
					WriteLineVerbose("player[%d].Name: set %ls", i, pName);
				}
			}
		}


		return true;
	}
	return false;
}

void IGameEngineHost::Member35(const wchar_t* a1, const wchar_t* a2)
{
	WriteLineVerbose("IGameEngineHost::Member35");
}

bool IGameEngineHost::Member36(wchar_t* a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member36");
	return 0;
}

__int64 __fastcall IGameEngineHost::NetworkSendTo(NetworkID networkID, char* buffer, uint32_t buffersize, int a5)
{
	return NetworkManager::SendTo(buffer, buffersize);
}

__int64 IGameEngineHost::NetworkReceiveFrom(char* buffer, uint32_t buffersize, __int64 a4, s_transport_address* transport_address)
{
	return NetworkManager::RecieveFrom(buffer, buffersize);
}

char* __fastcall IGameEngineHost::Member39(unsigned int a1)
{
	WriteLineVerbose("IGameEngineHost::Member39");
	return 0;
}

int __fastcall IGameEngineHost::Member40(BYTE* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member40");
	return 0;
}

bool __fastcall IGameEngineHost::Member41(signed int a1, __int64 a2, __int64 a3)
{
	WriteLineVerbose("IGameEngineHost::Member41");
	return 0;
}

// new wave/set
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2)
{
	WriteLineVerbose("IGameEngineHost::FirefightNew");
}

BOOL __fastcall IGameEngineHost::Member43(__int64 a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member43");
	return 0;
}

bool __fastcall IGameEngineHost::GetPathByType(int type, LPSTR buf, size_t len)
{
	const char* pEngineName = GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str();

	// this implementation is inline with MCC
	switch (type)
	{
	case 0:
		sprintf_s(buf, len, "%s\\DebugLogs\\", pEngineName);
		return true;
	case 1:
		sprintf_s(buf, len, "%s\\Config\\", pEngineName);
		return true;
	case 2:
		sprintf_s(buf, len, "%s\\Temporary\\", pEngineName);
		return true;
	case 3:
		sprintf_s(buf, len, "%s\\", pEngineName);
		return true;
	}

	return false;
}

bool __fastcall IGameEngineHost::GetWidePathByType(int type, LPWSTR wbuf, size_t len)
{
	LPSTR buf = new char[len];
	bool result = GetPathByType(type, buf, len);
	swprintf_s(wbuf, len, L"%S", buf);

	return result;
}

unsigned __int8* IGameEngineHost::Member46(_QWORD a1, unsigned __int8* a2, _QWORD a3)
{
	return 0;
}

__int64 __fastcall IGameEngineHost::Member47(_QWORD, __int64)
{
	// appears to be security related
	WriteLineVerbose("IGameEngineHost::Member47");
	return 1;
}
