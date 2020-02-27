#include "shared-private-pch.h"

std::map<std::string, ConsoleCommand*> Console::Commands;
std::vector<std::vector<std::string>> Console::PrevCommands;
std::vector<std::vector<std::string>>::iterator Console::PrevCommand;
size_t Console::CurArg;
std::vector<std::string> Console::CurCommand;
std::string Console::Suggestion;
size_t Console::ConsoleWidth;
void* Console::ConsoleHandle; 
bool Console::s_consoleAllocated;

const char* Credits[] = {
	"Squaresome",
	"Twister",
};

void Console::Update()
{
	if (_kbhit())
	{
		HandleInput(_getch());
		PrintLine();
	}
}

#define ps1beg "\xAF["
#define ps1end "]\xAE"

void Console::Init()
{
	Console::AllocateConsole("Opus");

	CurArg = 0;

	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleOutputCP(437);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	if (GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleInfo))
	{
		ConsoleWidth = ConsoleInfo.dwSize.X;
	}

	SetTextColor(Console::Color::Info);
	CurCommand.push_back("");

	static DefaultConsoleCommand baseCommand;

	// Meta commands pushed with null deleter so console doesn't delete its self.
	PushCommand("help", &baseCommand);
	PushCommand("history", &baseCommand);
	PushCommand("quit", &baseCommand);
}

void Console::Deinit()
{
	Commands.clear();
}

void Console::SetTextColor(Color color)
{
	SetTextColor(underlying_cast(color));
}

void Console::SetTextColor(uint8_t color)
{
	SetConsoleTextAttribute(ConsoleHandle, color);
}

void Console::HandleInput(uint32_t KeyCode)
{
	if (std::isgraph(KeyCode))
	{
		if (CurCommand.empty())
		{
			CurCommand.push_back("");
		}
		CurCommand.back().push_back((uint8_t)KeyCode);

		// Suggest
		Suggestion.clear();
		if (CurArg == 0)
		{
			// Find closest matching command

			std::vector<std::string> Suggestions;

			for (decltype(Commands)::value_type& Cmd : Commands)
			{
				if (!CurCommand[0].compare(0, CurCommand[0].length(), (Cmd.first), 0, CurCommand[0].length()))
				{
					Suggestions.push_back((Cmd.first));
				}
			}

			if (Suggestions.size())
			{
				// Return first match
				Suggestion = Suggestions.front();
			}

			Suggestions.clear();
		}
		else
		{
			if (Commands.count(CurCommand.front()))
			{
				Suggestion = Commands[CurCommand.front()]->Suggest(CurCommand);
			}
		}
	}
	else if (KeyCode == ' ') // Space
	{
		if (!CurCommand.empty())
		{
			if (!CurCommand.back().empty())
			{
				//Go to next argument;
				CurArg++;
				CurCommand.push_back("");
			}
			if (Commands.count(CurCommand.front()))
			{
				Suggestion = Commands[CurCommand.front()]->Suggest(CurCommand);
			}
		}
	}
	else if (KeyCode == '\b') // Backspace
	{
		if (!CurCommand.empty())
		{
			// Remove character from current command
			if (!CurCommand.back().empty())
			{
				CurCommand.back().pop_back();
			}
			// Current argument is empty.
			// Go back an argument
			if (CurCommand.back().empty())
			{
				CurCommand.pop_back();
				if (CurArg > 0)
				{
					CurArg--;
				}
			}
			// Suggest
			Suggestion.clear();
			if (CurArg == 0 && !CurCommand.empty())
			{
				// Find closest matching command

				std::vector<std::string> Suggestions;

				for (decltype(Commands)::value_type& Cmd : Commands)
				{
					if (!CurCommand[0].compare(0, CurCommand[0].length(), (Cmd.first), 0, CurCommand[0].length()))
					{
						Suggestions.push_back((Cmd.first));
					}
				}

				if (Suggestions.size())
				{
					// Return first match
					Suggestion = Suggestions.front();
				}

				Suggestions.clear();
			}
			else
			{
				if (!CurCommand.empty() && Commands.count(CurCommand.front()))
				{
					Suggestion = Commands[CurCommand.front()]->Suggest(CurCommand);
				}
			}
		}
	}
	else if (KeyCode == '\r') // Enter
	{
		SetTextColor(Color::Info);
		// Clear previous suggestion..
		if (!Suggestion.empty())
		{
			size_t i;
			for (i = 0; i < Suggestion.length(); i++)
			{
				std::cout << ' ';
			}
			for (i = 0; i < Suggestion.length() + (CurCommand.size() > 1 ? 1 : 0); i++)
			{
				std::cout << '\b';
			}
		}

		std::cout << ps1end << std::endl;
		if (!CurCommand.empty())
		{
			if (CurCommand.back().empty())
			{
				CurCommand.pop_back();
			}
			// Run command
			if (Commands.count(CurCommand[0]) && Commands[CurCommand[0]])
			{
				if (!Commands[CurCommand[0]]->Run(CurCommand))
				{
					// Error running command;
					SetTextColor(Color::Error);
					std::cout << "Invalid Usage: " << CurCommand[0] << std::endl;
					SetTextColor(Color::Info);
					std::cout << Commands[CurCommand[0]]->Info() << std::endl;
				}
			}
			else
			{
				SetTextColor(Color::Error);
				std::cout << "Unknown Command: " << CurCommand[0];
				SetTextColor(Color::Info);
			}
		}

		SetTextColor(Color::Info);
		if (!CurCommand.empty())
		{
			PrevCommands.push_back(CurCommand);
			PrevCommand = PrevCommands.end();
		}
		CurArg = 0;
		CurCommand.clear();
	}
	else if (KeyCode == '\t') // Tab
	{
		// Get suggestion
		if (!Suggestion.empty() && !CurCommand.empty())
		{
			CurCommand.back() = Suggestion;
			Suggestion.clear();
			CurArg++;
			CurCommand.push_back("");
			Suggestion = Commands[CurCommand.front()]->Suggest(CurCommand);
			// Todo: Allow suggestions with spaces.
			// Simulate keypress with HandleInput
		}
	}
	else if (KeyCode == 22) // Ctrl+v
	{
		// Paste in clipbard
		if (OpenClipboard(nullptr))
		{
			std::string Clipboard((char*)GetClipboardData(CF_TEXT));
			for (char character : Clipboard)
			{
				HandleInput(character);
			}
			CloseClipboard();
		}
	}
	else if (KeyCode == 0 || KeyCode == 0xE0) // Escape character
	{
		size_t Func = _getch();
		if (Func == 0x48) // Up
		{
			if (!PrevCommands.empty())
			{
				if (PrevCommand != PrevCommands.begin())
				{
					PrevCommand--;
				}

				CurCommand = *PrevCommand;
				CurArg = CurCommand.size() - 1;
			}
		}
		else if (Func == 0x50) // Down
		{
			if (!PrevCommands.empty())
			{
				if (PrevCommand != PrevCommands.end() && PrevCommand != PrevCommands.end() - 1)
				{
					PrevCommand++;
					CurCommand = *PrevCommand;
					CurArg = CurCommand.size() - 1;
				}
				else if (PrevCommand == PrevCommands.end() - 1)
				{
					PrevCommand++;
					CurArg = 0;
					CurCommand.clear();
				}
				else
				{
					CurArg = 0;
					CurCommand.clear();
				}
			}
		}
		else if (Func == 0x4B) // Left
		{
		}
		else if (Func == 0x4D) // Right
		{
		}
		else
		{
			// Unknown function key
		}
	}
}

void Console::PrintLine()
{
	SetTextColor(Color::Info);
	std::cout << '\r' << std::string(ConsoleWidth - 2, ' ') << '\r' << ps1beg;
	SetTextColor(Color::Input);

	for (size_t i = 0; i < CurCommand.size(); i++)
	{
		if (Suggestion.length() && i == CurArg)
		{
			SetTextColor(Color::Suggestion);
			std::cout << Suggestion;
			std::cout << std::string(Suggestion.length(), '\b');
			SetTextColor(Color::Input);
			//Suggestion.clear();
			std::cout << CurCommand[i];
		}
		else
		{
			std::cout << CurCommand[i];
			(i == CurCommand.size() - 1) || std::cout << ' ';
		}
	}
	std::cout.flush();
}

void Console::PushCommand(const std::string& CommandName, ConsoleCommand* Command)
{
	Commands[CommandName] = Command;
}
void Console::PopCommand(const std::string& CommandName)
{
	if (Commands.count(CommandName))
	{
		Commands.erase(CommandName);
	}
}


void Console::Startup()
{
	SetTextColor(Color::Info);

#ifdef _DEBUG
	std::string buildType = "Debug ";
#else
	std::string buildType = "";
#endif
	char executableNameBuffer[9] = "        ";
	int count = snprintf(executableNameBuffer, _countof(executableNameBuffer), "%s", s_consoleExecutableName);
	executableNameBuffer[count] = ' ';
	executableNameBuffer[_countof(executableNameBuffer) - 1] = 0;
	std::cout << executableNameBuffer << "\xC3\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xB4 " << buildType << "Build Date: " << __DATE__ << " @ " << __TIME__ << std::endl;
	SetTextColor(Color::Input);

	for (size_t i = 0; i < sizeof(Credits) / sizeof(char*); i++)
	{
		std::cout << "        ";
		SetTextColor(Color::Input);
		std::cout << "  " << "\xC3\xC0"[(i == sizeof(Credits) / sizeof(char*) - 1) ^ 0];
		std::cout << Credits[i] << std::endl;;
	}

	SetTextColor(Color::Info);
	std::cout << "Join the Assault on the Control Room Discord https://discord.gg/ksvhEQD" << std::endl;

	SetTextColor(underlying_cast(Color::Green) | underlying_cast(Color::Bright));
	std::cout << "Enter \"";
	SetTextColor(Color::Input);
	std::cout << "help";
	SetTextColor(underlying_cast(Color::Green) | underlying_cast(Color::Bright));
	std::cout << "\" or \"";
	SetTextColor(Color::Input);
	std::cout << "help (command)";
	SetTextColor(underlying_cast(Color::Green) | underlying_cast(Color::Bright));

	std::cout << "\" to get started!" << std::endl;

	std::cout << "Current directory: ";
	SetTextColor(Color::Input);
	char currentDirectoryBuffer[MAX_PATH + 1]{};
	GetCurrentDirectoryA(MAX_PATH, currentDirectoryBuffer);
	std::cout << currentDirectoryBuffer << std::endl;

	SetTextColor(Color::Magenta);
	std::cout << std::string(ConsoleWidth - 1, '\xC4') << std::endl;
	SetTextColor(Color::Info);

	PrintLine();
}

bool Console::DefaultConsoleCommand::Run(const std::vector<std::string>& Args)
{
	if (!Args.empty())
	{
		if (!Args.front().compare("help"))
		{
			if (Args.size() >= 2)
			{
				if (Console::Commands.count(Args[1]))
				{
					if (Args.size() == 3)
					{
						std::cout << Console::Commands[Args[1]]->Info() << std::endl;
					}
					else
					{
						std::cout << Console::Commands[Args[1]]->Info(Args.back()) << std::endl;
					}
				}
				else
				{
					Console::SetTextColor(Console::Color::Error);
					std::cout << "Command: " << Args[1] << "not found." << std::endl;
				}
			}
			else
			{
				// Show all command info
				for (decltype(Console::Commands)::value_type& Command : Console::Commands)
				{
					std::string Padded(Command.first);
					Padded.resize(Console::ConsoleWidth >> 1, '\xC4');
					Console::SetTextColor(Console::Color::Info);
					std::cout << Padded << std::endl;
					Console::SetTextColor(underlying_cast(Console::Color::Info) ^ underlying_cast(Console::Color::Bright));
					std::cout << Command.second->Info(Command.first) << std::endl;
				}
			}
		}
		else if (!Args.front().compare("history"))
		{
			Console::SetTextColor(Console::Color::Info);
			for (decltype(Console::PrevCommands)::value_type& Command : Console::PrevCommands)
			{
				for (std::string& Arg : Command)
				{
					std::cout << Arg << ' ';
				}
				std::cout << std::endl;
			}
		}
		else if (!Args.front().compare("quit"))
		{
			std::exit(0);
		}
	}
	return true;
}

std::string Console::DefaultConsoleCommand::Info(const std::string& Topic) const
{
	if (!Topic.empty())
	{
		if (!Topic.compare("help"))
		{
			return "Prints help for all commands\n"
				"Type help (command name) (topic) to get help on a specific command";
		}
		else if (!Topic.compare("history"))
		{
			return "Displays all previously entered commands";
		}
		else if (!Topic.compare("quit"))
		{
			return "Quits the application";
		}
	}
	return "";
};

// Suggest auto-complete strings for arguments
std::string Console::DefaultConsoleCommand::Suggest(const std::vector<std::string>& Arguments) const
{
	return ""; // todo;
};

bool Console::AllocateConsole(const std::string& ConsoleTitle)
{
	if (s_consoleAllocated)
	{
		return false;
	}

	//Set up new co-nsole window

	AllocConsole();
	(void)freopen("CONIN$", "r", stdin);
	(void)freopen("CONOUT$", "w", stdout);
	(void)freopen("CONOUT$", "w", stderr);

	SetConsoleTitleA(ConsoleTitle.c_str());
	EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE & SC_MINIMIZE | SC_MAXIMIZE, MF_GRAYED);
	DrawMenuBar(GetConsoleWindow());

	//// Setup standard input.
	HANDLE input_handle = GetStdHandle(STD_INPUT_HANDLE); // STD in Handle
	//unsigned int hConsole = _open_osfhandle((intptr_t)hStd, _O_TEXT);
	//FILE* fIn = _fdopen(hConsole, "r");
	//*stdin = *fIn;
	//setvbuf(stdin, NULL, _IONBF, 0);

	//// Setup standard output.
	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE); // STD out Handle
	//hConsole = _open_osfhandle((intptr_t)hStd, _O_TEXT); // Console Handle
	//FILE* fOut = _fdopen(hConsole, "w");
	//*stdout = *fOut;
	//setvbuf(stdout, NULL, _IONBF, 0);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(output_handle, &ConsoleInfo);
	ConsoleInfo.dwSize.Y = 25;
	ConsoleInfo.dwSize.X = 30;
	SetConsoleScreenBufferSize(output_handle, ConsoleInfo.dwSize);

	DWORD ConsoleMode;
	GetConsoleMode(output_handle, &ConsoleMode);
	ConsoleMode &= ~ENABLE_WRAP_AT_EOL_OUTPUT;
	SetConsoleMode(output_handle, ConsoleMode);

	std::ios::sync_with_stdio();

	return true;
}