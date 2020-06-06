#pragma once

namespace ketchup
{
	class Instruction;

	class PatternScan
	{
	public:
#ifdef _WINDOWS_
		PatternScan(HANDLE hProcess, HMODULE hModule);
		DWORD FindPattern(DWORD startOffset);
#endif
		void AddInstruction(Instruction* instruction);
		~PatternScan();
		unsigned char* get_data();

		std::vector<Instruction*> Instructions;
		size_t ImageSize;
		std::vector<unsigned char> Data;
	};
}

