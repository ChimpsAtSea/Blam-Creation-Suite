#include "eldoradolib-private-pch.h"

#include "EldoradoGameHost.Testing.inl"

void register_eldoradolib()
{

}

// #TODO: Setup Eldorado version detection
GameRuntime EldoradoGameHost::s_eldoradoGameRuntime(Engine::Eldorado, "eldorado", "eldorado.exe", true, Build::Eldorado_1_106708_cert_ms23);

EldoradoGameHost::EldoradoGameHost()
	:IOpusGameEngineHost(s_eldoradoGameRuntime)
{
	
}

EldoradoGameHost::~EldoradoGameHost()
{
	
}

void EldoradoGameHost::InitModifications(Build build)
{
	init_detours();
	DataReferenceBase::InitTree(Engine::Eldorado, build);
	FunctionHookBase::InitTree(Engine::Eldorado, build);
	GlobalReference::InitTree(Engine::Eldorado, build);
	DataPatchBase::InitTree(Engine::Eldorado, build);
	end_detours();
}

void EldoradoGameHost::DeinitModifications(Build build)
{
	init_detours();
	DataReferenceBase::DeinitTree(Engine::Eldorado, build);
	FunctionHookBase::DeinitTree(Engine::Eldorado, build);
	GlobalReference::DeinitTree(Engine::Eldorado, build);
	DataPatchBase::DeinitTree(Engine::Eldorado, build);
	end_detours();
}
