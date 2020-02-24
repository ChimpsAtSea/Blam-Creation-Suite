#pragma once

class EldoradoGameHost : public IOpusGameEngineHost
{
public:
	EldoradoGameHost();
	virtual ~EldoradoGameHost();
private:
	static GameRuntime s_eldoradoGameRuntime;
};

