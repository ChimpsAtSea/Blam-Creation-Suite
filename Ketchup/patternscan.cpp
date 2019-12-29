#include "ketchup-private-pch.h"

PatternScan::PatternScan(HANDLE hProcess, HMODULE hModule)
{
	MODULEINFO moduleInfo = {};

	GetModuleInformation(
		hProcess,
		hModule,
		&moduleInfo,
		sizeof(moduleInfo)
	);

	ImageSize = moduleInfo.SizeOfImage;

	Data.resize(ImageSize);
	SIZE_T number_of_bytes = 0;
	ReadProcessMemory(
		hProcess,
		hModule,
		Data.data(),
		Data.size(),
		&number_of_bytes
	);
}

PatternScan::~PatternScan()
{
	// Cleanup
	for (size_t i = 0; i < Instructions.size(); i++)
	{
		delete Instructions[i];
	}
}

void PatternScan::AddInstruction(Instruction* instruction)
{
	Instructions.push_back(instruction);
}

DWORD PatternScan::FindPattern(DWORD startOffset)
{
	// use instructions length so we don't go off the end of the data
	size_t instructions_test_length = 0;
	auto instructions_count = Instructions.size();
	for (int i = 0; i < instructions_count; i++)
	{
		Instruction* ins = Instructions[i];
		instructions_test_length += ins->m_length;
	}

	auto data = Data.data();
	auto data_length = Data.size();
	const unsigned char* start_address = data;
	start_address += startOffset;
	const unsigned char* end_address = data + data_length - instructions_test_length;

	for (
		const unsigned char* current_address = start_address;
		current_address < end_address;
		current_address++
		)
	{
		const unsigned char* search_address = current_address;

		bool success = true;
		for (int i = 0; i < instructions_count; i++)
		{
			Instruction* ins = Instructions[i];

			auto test_address = search_address;
			search_address = ins->Match(search_address);
			if (search_address)
			{
				//printf("Success at instruction %i\n", i);
			}
			else
			{
				//printf("Failed at instruction %i\n", i);
				success = false;
				break;
			}
		}
		if (success)
		{
			DWORD offset = DWORD(current_address - start_address);
			return offset;
		}
	}

	return 0;
}

unsigned char* PatternScan::GetData()
{
	return (unsigned char*)Data.data();
}