#pragma once

class GameRender
{
public:
	static ID3D11Device* pDevice;
	static ID3D11DeviceContext* pImmediateContext;

	static void Init();
};

