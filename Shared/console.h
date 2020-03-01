#pragma once

class c_console_command
{
public:
	virtual bool execute_command(const std::vector<std::string>& arguments) = 0; // Return true on success
	virtual std::string get_command_info(const std::string& topic = "") const = 0; // Command and usage info
	virtual std::string get_command_auto_complete(const std::vector<std::string>& arguments) const; // Suggest auto-complete strings for arugments
};

enum e_console_color : uint8_t
{
	_console_color_none = 0,
	_console_color_bright = 0x8,
	_console_color_red = 0x4,
	_console_color_blue = 0x1,
	_console_color_green = 0x2,
	_console_color_yellow = _console_color_red | _console_color_green,
	_console_color_cyan = _console_color_green | _console_color_blue,
	_console_color_magenta = _console_color_red | _console_color_blue,
	_console_color_default = _console_color_red | _console_color_blue | _console_color_green,

	// bitshift colors left 4 bits to get background version
	_console_color_background_bright = _console_color_bright << 4,
	_console_color_background_red = _console_color_red << 4,
	_console_color_background_blue = _console_color_blue << 4,
	_console_color_background_green = _console_color_green << 4,
	_console_color_background_yellow = _console_color_yellow << 4,
	_console_color_background_cyan = _console_color_cyan << 4,
	_console_color_background_magenta = _console_color_magenta << 4,

	// prefabs
	_console_color_error = _console_color_red,
	_console_color_info = _console_color_bright | _console_color_yellow,
	_console_color_input = _console_color_bright | _console_color_cyan,
	_console_color_suggestion = _console_color_cyan
};

class c_console
{
public:
	friend c_console_command;

	class DefaultConsoleCommand : public c_console_command
	{
	public:
		virtual bool execute_command(const std::vector<std::string>& Arguments) override;
		virtual std::string get_command_info(const std::string& Topic = "") const override;
		virtual std::string get_command_auto_complete(const std::vector<std::string>& Arguments) const override;
	};



	static void init_console();
	static void deinit_console();
	static void Update();

	static void set_text_color(uint8_t color);

	static void HandleInput(uint32_t KeyCode);
	static void PrintLine();

	static void register_command(const std::string& CommandName, c_console_command* Command);
	static void unregister_command(const std::string& CommandName);

	static void show_startup_banner();

private:
	static bool AllocateConsole(const std::string& ConsoleTitle);

	static bool s_consoleAllocated;

	static std::map<std::string, c_console_command*> Commands;

	// History
	static std::vector<std::vector<std::string>> PrevCommands;
	static std::vector<std::vector<std::string>>::iterator PrevCommand;

	// Current Command
	static size_t CurArg;
	static std::vector<std::string> CurCommand;
	static std::string Suggestion;

	// Console Data
	static size_t ConsoleWidth;
	static void* ConsoleHandle;
	static const char* g_console_executable_name;
};

