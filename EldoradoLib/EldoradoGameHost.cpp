#include "eldoradolib-private-pch.h"

#include "EldoradoGameHost.Testing.inl"

void register_eldoradolib()
{

}

GameRuntime EldoradoGameHost::s_eldoradoGameRuntime(EngineVersion::Eldorado, "eldorado", "eldorado.exe");

EldoradoGameHost::EldoradoGameHost()
	:IOpusGameEngineHost(s_eldoradoGameRuntime)
{
	
}

EldoradoGameHost::~EldoradoGameHost()
{
	
}

void EldoradoGameHost::InitModifications(BuildVersion buildVersion)
{
	init_detours();
	DataReferenceBase::InitTree(EngineVersion::Eldorado, buildVersion);
	FunctionHookBase::InitTree(EngineVersion::Eldorado, buildVersion);
	GlobalReference::InitTree(EngineVersion::Eldorado, buildVersion);
	end_detours();
}

void EldoradoGameHost::DeinitModifications(BuildVersion buildVersion)
{
	init_detours();
	DataReferenceBase::DeinitTree(EngineVersion::Eldorado, buildVersion);
	FunctionHookBase::DeinitTree(EngineVersion::Eldorado, buildVersion);
	GlobalReference::DeinitTree(EngineVersion::Eldorado, buildVersion);
	end_detours();
}
