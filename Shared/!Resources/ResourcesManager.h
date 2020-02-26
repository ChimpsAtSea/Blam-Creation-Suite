#pragma once

enum class ResourceType
{
	Icon,
	ImGUIFont,
	BoxPixelShader,
	BoxVertexShader,
	ApplicationMap,
};

class ResourcesManager
{
public:
	static LPSTR GetResourceIntResource(ResourceType type);
	static bool GetResource(ResourceType type, char** ppData, size_t* pDataSize, bool nullTerminate = false);
private:
	static HRSRC GetResourceHandle(ResourceType type);
};


