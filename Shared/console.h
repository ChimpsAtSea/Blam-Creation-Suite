#pragma once

class ConsoleCommand
{
public:
	// Return true on success
	virtual bool Run(const std::vector<std::string>& Arguments) = 0;

	// Command and usage info
	virtual std::string Info(const std::string& Topic = "") const = 0;

	// Suggest auto-complete strings for arugments
	virtual std::string Suggest(const std::vector<std::string>& Arguments) const = 0;
};

class Console
{
public:
	friend ConsoleCommand;

	class DefaultConsoleCommand : public ConsoleCommand
	{
	public:
		virtual bool Run(const std::vector<std::string>& Arguments) override;
		virtual std::string Info(const std::string& Topic = "") const override;
		virtual std::string Suggest(const std::vector<std::string>& Arguments) const override;
	};

	enum class Color : uint8_t
	{
		None = 0,
		Bright = 0x8,
		Red = 0x4,
		Blue = 0x1,
		Green = 0x2,
		Yellow = Red | Green,
		Cyan = Green | Blue,
		Magenta = Red | Blue,
		Normal = Red | Blue | Green,
		// Bitshift colors left 4 bits to get background version
		BackBright = Bright << 4,
		BackRed = Red << 4,
		BackBlue = Blue << 4,
		BackGreen = Green << 4,
		BackYellow = Yellow << 4,
		BackCyan = Cyan << 4,
		BackMagenta = Magenta << 4,
		// Prefabs
		Error = Red,
		Info = Bright | Yellow,
		Input = Bright | Cyan,
		Suggestion = Cyan
	};

	static void Init();
	static void Deinit();
	static void Update();

	static void SetTextColor(Color color);
	static void SetTextColor(uint8_t color);

	static void HandleInput(uint32_t KeyCode);
	static void PrintLine();

	static void PushCommand(const std::string& CommandName, ConsoleCommand* Command);
	static void PopCommand(const std::string& CommandName);

	static void Startup();

private:
	static bool AllocateConsole(const std::string& ConsoleTitle);

	static bool s_consoleAllocated;

	static std::map<std::string, ConsoleCommand*> Commands;

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
	static const char* s_consoleExecutableName;
};

