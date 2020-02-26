#include "eldoradolib-private-pch.h"

#include "EldoradoGameHost.Testing.inl"

void register_eldoradolib()
{

}

// #TODO: Setup Eldorado version detection
GameRuntime* EldoradoGameHost::s_eldoradoGameRuntime = nullptr;


EldoradoGameHost::EldoradoGameHost()
	:IOpusGameEngineHost(*s_eldoradoGameRuntime)
{

}

EldoradoGameHost::~EldoradoGameHost()
{

}

void EldoradoGameHost::Init(Build build)
{
	s_eldoradoGameRuntime = new GameRuntime(Engine::Eldorado, "eldorado", "eldorado.exe", true, build);
}

void EldoradoGameHost::Deinit()
{
	delete s_eldoradoGameRuntime;
}

Build EldoradoGameHost::GetBuild()
{
	return s_eldoradoGameRuntime->GetBuildVersion();
}

class EldoradoLoadMapCommand : public ConsoleCommand
{
public:
	static constexpr const char* kCommandName = "loadmap";
	EldoradoLoadMapCommand()
	{
		Console::PushCommand(kCommandName, this);
	}
	~EldoradoLoadMapCommand()
	{
		Console::PopCommand(kCommandName);
	}
	virtual bool Run(const std::vector<std::string>& Args) override
	{
		if (Args.empty()) return true;

		if (!Args.front().compare("loadmap"))
		{
			if (Args.size() == 2)
			{
				const std::string& map_name = Args[1];

				Console::SetTextColor(Console::Color::Info);
				WriteLineVerbose("Loading map %s", map_name.c_str());
			}
			else return false;
		}
		return true;
	}

	virtual std::string Info(const std::string& Topic = "") const override
	{
		if (!Topic.empty())
		{
			if (!Topic.compare("loadmap"))
			{
				return "Load a map\n"
					"Usage: loadmap <map name>";
			}
		}
		return "";
	}

	virtual std::string Suggest(const std::vector<std::string>& Arguments) const override
	{
		return ""; // todo;
	}
};

static EldoradoLoadMapCommand* s_loadMapCommand;

void EldoradoGameHost::InitModifications(Build build)
{
	s_loadMapCommand = new EldoradoLoadMapCommand();
	init_detours();
	DataReferenceBase::InitTree(Engine::Eldorado, build);
	FunctionHookBase::InitTree(Engine::Eldorado, build);
	GlobalReference::InitTree(Engine::Eldorado, build);
	DataPatchBase::InitTree(Engine::Eldorado, build);
	end_detours();
}

void EldoradoGameHost::DeinitModifications(Build build)
{
	delete s_loadMapCommand;
	init_detours();
	DataReferenceBase::DeinitTree(Engine::Eldorado, build);
	FunctionHookBase::DeinitTree(Engine::Eldorado, build);
	GlobalReference::DeinitTree(Engine::Eldorado, build);
	DataPatchBase::DeinitTree(Engine::Eldorado, build);
	end_detours();
}
