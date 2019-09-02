#include "haloshared-private-pch.h"

ID3D11Device* GameRender::pDevice = nullptr;
ID3D11DeviceContext* GameRender::pImmediateContext = nullptr;

void GameRender::Init()
{
	if (pDevice == nullptr)
	{
		D3D_FEATURE_LEVEL pFeatureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_0,
		};


		D3D_FEATURE_LEVEL FeatureLevel = {};
		auto D3D11CreateDeviceResult = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, pFeatureLevels, _countof(pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pImmediateContext);
		assert(D3D11CreateDeviceResult == S_OK);
	}
}
