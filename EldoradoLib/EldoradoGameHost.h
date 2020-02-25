#pragma once

class EldoradoGameHost : public IOpusGameEngineHost
{
public:
	EldoradoGameHost();
	virtual ~EldoradoGameHost();

	// static
public:
	static void InitModifications(BuildVersion buildVersion);
	static void DeinitModifications(BuildVersion buildVersion);
private:
	static GameRuntime s_eldoradoGameRuntime;
};

