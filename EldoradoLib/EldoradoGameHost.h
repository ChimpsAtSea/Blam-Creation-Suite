#pragma once

class EldoradoGameHost : public IOpusGameEngineHost
{
public:
	EldoradoGameHost();
	virtual ~EldoradoGameHost();

	static void Init(Build build);
	static void Deinit();
	// static
	static Build GetBuild();
public:
	static void InitModifications(Build build);
	static void DeinitModifications(Build build);
private:
	static GameRuntime* s_eldoradoGameRuntime;
};

