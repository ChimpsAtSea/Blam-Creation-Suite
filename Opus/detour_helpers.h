#pragma once

#include <Windows.h>

#define roundup(n, denominator) (((n + denominator - 1) / denominator ) * denominator )

extern const char* GetDetourResultStr(LONG detourAttachResult);

//TODO: Accept an instruction type to look for
template<typename T>
T* BackpropagateFunctionPointer(T* instructionPtr, int maxSteps)
{
	static const size_t kFunctionAlignmentSize = 16;

	const char* currentPointer = reinterpret_cast<const char*>(instructionPtr);

	currentPointer = reinterpret_cast<char*>(roundup(reinterpret_cast<size_t>(currentPointer), kFunctionAlignmentSize));

	for (int i = 0; i < maxSteps; i++)
	{
		currentPointer -= kFunctionAlignmentSize;


		char currentByte = currentPointer[0];
		char peekBackByte = currentPointer[-1];
		// assuming that this function will be aligned and have a missing space! this should be improved. Use IDA database?
		if (peekBackByte == char(0xCC))
		{
			switch (currentByte)
			{
			case 0x48: // TEST
				// looking for a push instruction!??
				//TODO: Identify the correct cases
				//TODO: Ensure 0x40 is correct
			case 0x40: //PUSH 
			case 0x55: //PUSH
			case 0x56: //PUSH
			case 0x57: //PUSH
				return reinterpret_cast<T*>(reinterpret_cast<size_t>(currentPointer));
			}
		}
	}

	return nullptr;
}