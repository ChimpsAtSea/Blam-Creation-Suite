#pragma once

namespace ketchup
{
	class Instruction;

	class c_pattern_scanner
	{
	public:
#ifdef _WINDOWS_
		c_pattern_scanner(HANDLE hProcess, HMODULE hModule);
		DWORD find_pattern(DWORD startOffset);
#endif
		void add_instruction(Instruction* instruction);
		~c_pattern_scanner();
		unsigned char* get_data();

		std::vector<Instruction*> Instructions;
		size_t ImageSize;
		std::vector<unsigned char> Data;
	};
}

