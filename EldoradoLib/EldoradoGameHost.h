#pragma once

class EldoradoGameHost : public IOpusGameEngineHost
{
public:
	EldoradoGameHost();
	virtual ~EldoradoGameHost();

	// static
public:
	static void InitModifications(Build build);
	static void DeinitModifications(Build build);
private:
	static GameRuntime s_eldoradoGameRuntime;
};

