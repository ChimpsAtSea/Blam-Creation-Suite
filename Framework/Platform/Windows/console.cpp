#include "platform-private-pch.h"

std::map<std::string, c_console_command*> c_console::Commands;
std::vector<std::vector<std::string>> c_console::PrevCommands;
std::vector<std::vector<std::string>>::iterator c_console::PrevCommand;
size_t c_console::CurArg;
std::vector<std::string> c_console::CurCommand;
std::string c_console::Suggestion;
size_t c_console::ConsoleWidth;
void* c_console::ConsoleHandle; 
bool c_console::s_consoleAllocated;

const char* Credits[] = {
	"Assault on the Control Room"
};

void c_console::Update()
{
	if (_kbhit())
	{
		HandleInput(_getch());
		PrintLine();
	}
}

#define ps1beg "\xAF["
#define ps1end "]\xAE"

void c_console::init_console()
{
	c_console::AllocateConsole("Opus");

	CurArg = 0;

	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleOutputCP(437);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	if (GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleInfo))
	{
		ConsoleWidth = ConsoleInfo.dwSize.X;
	}

	set_text_color(_console_color_info);
	CurCommand.push_back("");

	static DefaultConsoleCommand baseCommand;

	// Meta commands pushed with null deleter so console doesn't delete its self.
	register_command("help", &baseCommand);
	register_command("history", &baseCommand);
	register_command("quit", &baseCommand);
	register_command("clear", &baseCommand);
}

void c_console::deinit_console()
{
	Commands.clear();
}

void c_console::set_text_color(uint8_t color)
{
	SetConsoleTextAttribute(ConsoleHandle, color);
}

void c_console::HandleInput(uint32_t KeyCode)
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
				Suggestion = Commands[CurCommand.front()]->get_command_auto_complete(CurCommand);
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
				Suggestion = Commands[CurCommand.front()]->get_command_auto_complete(CurCommand);
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
					Suggestion = Commands[CurCommand.front()]->get_command_auto_complete(CurCommand);
				}
			}
		}
	}
	else if (KeyCode == '\r') // Enter
	{
		set_text_color(e_console_color::_console_color_info);
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
				if (!Commands[CurCommand[0]]->execute_command(CurCommand))
				{
					// Error running command;
					set_text_color(e_console_color::_console_color_error);
					std::cout << "Invalid Usage: " << CurCommand[0] << std::endl;
					set_text_color(e_console_color::_console_color_info);
					std::cout << Commands[CurCommand[0]]->get_command_info() << std::endl;
				}
			}
			else
			{
				set_text_color(e_console_color::_console_color_error);
				std::cout << "Unknown Command: " << CurCommand[0];
				set_text_color(e_console_color::_console_color_info);
			}
		}

		set_text_color(e_console_color::_console_color_info);
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
			Suggestion = Commands[CurCommand.front()]->get_command_auto_complete(CurCommand);
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

void c_console::PrintLine()
{
	set_text_color(e_console_color::_console_color_info);
	std::cout << '\r' << std::string(ConsoleWidth - 2, ' ') << '\r' << ps1beg;
	set_text_color(e_console_color::_console_color_input);

	for (size_t i = 0; i < CurCommand.size(); i++)
	{
		if (Suggestion.length() && i == CurArg)
		{
			set_text_color(e_console_color::_console_color_suggestion);
			std::cout << Suggestion;
			std::cout << std::string(Suggestion.length(), '\b');
			set_text_color(e_console_color::_console_color_input);
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

void c_console::register_command(const std::string& CommandName, c_console_command* Command)
{
	Commands[CommandName] = Command;
}
void c_console::unregister_command(const std::string& CommandName)
{
	if (Commands.count(CommandName))
	{
		Commands.erase(CommandName);
	}
}


void c_console::show_startup_banner()
{
	set_text_color(e_console_color::_console_color_info);

#ifdef _DEBUG
	std::string buildType = "Debug ";
#else
	std::string buildType = "";
#endif
	char executableNameBuffer[9] = "        ";
	int count = snprintf(executableNameBuffer, _countof(executableNameBuffer), "%s", g_console_executable_name);
	executableNameBuffer[count] = ' ';
	executableNameBuffer[_countof(executableNameBuffer) - 1] = 0;
	std::cout << executableNameBuffer << "\xC3\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xB4 " << buildType << "Build Date: " << __DATE__ << " @ " << __TIME__ << std::endl;
	set_text_color(e_console_color::_console_color_input);

	for (size_t i = 0; i < sizeof(Credits) / sizeof(char*); i++)
	{
		std::cout << "        ";
		set_text_color(e_console_color::_console_color_input);
		std::cout << "  " << "\xC3\xC0"[(i == sizeof(Credits) / sizeof(char*) - 1) ^ 0];
		std::cout << Credits[i] << std::endl;;
	}

	set_text_color(e_console_color::_console_color_info);
	std::cout << "Join the Assault on the Control Room Discord https://discord.gg/ksvhEQD" << std::endl;

	set_text_color(_console_color_green | _console_color_bright);
	std::cout << "Enter \"";
	set_text_color(e_console_color::_console_color_input);
	std::cout << "help";
	set_text_color(_console_color_green | _console_color_bright);
	std::cout << "\" or \"";
	set_text_color(e_console_color::_console_color_input);
	std::cout << "help (command)";
	set_text_color(_console_color_green | _console_color_bright);

	std::cout << "\" to get started!" << std::endl;

	std::cout << "Current directory: ";
	set_text_color(e_console_color::_console_color_input);
	char currentDirectoryBuffer[MAX_PATH + 1]{};
	GetCurrentDirectoryA(MAX_PATH, currentDirectoryBuffer);
	std::cout << currentDirectoryBuffer << std::endl;

	set_text_color(e_console_color::_console_color_magenta);
	std::cout << std::string(ConsoleWidth - 1, '\xC4') << std::endl;
	set_text_color(e_console_color::_console_color_info);

	PrintLine();
}

void c_console::write_line_verbose(const char* format, ...)
{
	if (g_debug_log_mode >= _debug_log_mode_verbose)
	{
		va_list args;
		va_start(args, format);
		write_line_internal(format, args);
		va_end(args);
	}
}

void c_console::write_line(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	write_line_internal(format, args);
	va_end(args);
}

std::mutex console_mutex;
int (__cdecl *c_console::console_printf_impl)(const char* format, ...) = printf;
void c_console::write_line_internal(const char* format, va_list args)
{
	std::lock_guard console_mutex_lockguard(console_mutex);

	c_fixed_string_4096 fixed_string;
	fixed_string.vformat(format, args);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	console_printf_impl("%s\n", fixed_string.c_str());
}

bool c_console::DefaultConsoleCommand::execute_command(const std::vector<std::string>& Args)
{
	if (!Args.empty())
	{
		if (!Args.front().compare("help"))
		{
			if (Args.size() >= 2)
			{
				if (c_console::Commands.count(Args[1]))
				{
					if (Args.size() == 3)
					{
						std::cout << c_console::Commands[Args[1]]->get_command_info() << std::endl;
					}
					else
					{
						std::cout << c_console::Commands[Args[1]]->get_command_info(Args.back()) << std::endl;
					}
				}
				else
				{
					c_console::set_text_color(_console_color_error);
					std::cout << "Command: " << Args[1] << "not found." << std::endl;
				}
			}
			else
			{
				// Show all command info
				for (decltype(c_console::Commands)::value_type& Command : c_console::Commands)
				{
					std::string Padded(Command.first);
					Padded.resize(c_console::ConsoleWidth >> 1, '\xC4');
					c_console::set_text_color(_console_color_info);
					std::cout << Padded << std::endl;
					c_console::set_text_color(_console_color_info ^ _console_color_bright);
					std::cout << Command.second->get_command_info(Command.first) << std::endl;
				}
			}
		}
		else if (!Args.front().compare("history"))
		{
			c_console::set_text_color(_console_color_info);
			for (decltype(c_console::PrevCommands)::value_type& Command : c_console::PrevCommands)
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
			std::exit(0); // #TODO: Handle this better
		}
		else if (!Args.front().compare("clear"))
		{
			::system("CLS");
			show_startup_banner();
		}
	}
	return true;
}

std::string c_console::DefaultConsoleCommand::get_command_info(const std::string& Topic) const
{
	if (!Topic.empty())
	{
		if (!Topic.compare("clear"))
		{
			return "Clears the console window";
		}
		else if (!Topic.compare("help"))
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
std::string c_console::DefaultConsoleCommand::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	return ""; // todo;
};

bool c_console::AllocateConsole(const std::string& ConsoleTitle)
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

std::string c_console_command::get_command_auto_complete(const std::vector<std::string>& arguments) const
{
	return "";
}
