#include "ketchup-private-pch.h"

Instruction::Instruction(int length)
	:m_length(length)
{

}

Instruction::Instruction(const char* pMask, bool shouldInit) : m_length(__max(strlen(pMask), 0)) { if (shouldInit) { init(pMask); } }
Instruction::Instruction(const char* pMask) : Instruction(pMask, true) {}

Instruction::Instruction(const char* pMask, char b0) : m_length(__max(strlen(pMask), 1)) { init(pMask, b0); }
Instruction::Instruction(const char* pMask, char b0, char b1) : m_length(__max(strlen(pMask), 2)) { init(pMask, b0, b1); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2) : m_length(__max(strlen(pMask), 3)) { init(pMask, b0, b1, b2); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3) : m_length(__max(strlen(pMask), 4)) { init(pMask, b0, b1, b2, b3); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4) : m_length(__max(strlen(pMask), 5)) { init(pMask, b0, b1, b2, b3, b4); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5) : m_length(__max(strlen(pMask), 6)) { init(pMask, b0, b1, b2, b3, b4, b5); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6) : m_length(__max(strlen(pMask), 7)) { init(pMask, b0, b1, b2, b3, b4, b5, b6); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7) : m_length(__max(strlen(pMask), 8)) { init(pMask, b0, b1, b2, b3, b4, b5, b6, b7); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8) : m_length(__max(strlen(pMask), 9)) { init(pMask, b0, b1, b2, b3, b4, b5, b6, b7, b8); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9) : m_length(__max(strlen(pMask), 10)) { init(pMask, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9, char b10) : m_length(__max(strlen(pMask), 11)) { init(pMask, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10); }
Instruction::Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9, char b10, char b11) : m_length(__max(strlen(pMask), 12)) { init(pMask, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11); }



const unsigned char* Instruction::Match(const unsigned char* pInput)
{
	for (int i = 0; i < m_length; i++)
	{
		bool test_marker = m_testInstruction[i];
		if (!test_marker) continue;

		auto valueInput = pInput[i];
		auto valueInstruction = m_instructionBytes[i];

		if (valueInput != valueInstruction)
		{
			return nullptr;
		}
	}
	return pInput + m_length;
}

const void Instruction::init(const char* pMask, ...)
{
	va_list args;
	va_start(args, pMask);
	init(pMask, args);
	va_end(args);
}

const void Instruction::init(const char* pMask, va_list& rArgs)
{
	m_instructionBytes.resize(m_length);
	m_testInstruction.resize(m_length);

	char pMaskData[16] = {};
	memset(pMaskData, '?', m_length); // populate the full length with unknowns
	if (pMask)
	{
		memcpy(pMaskData, pMask, strlen(pMask)); // populate with the known mask
	}

	for (int i = 0; i < m_length; i++)
	{
		unsigned int value = va_arg(rArgs, unsigned int);
		m_instructionBytes[i] = (unsigned char)value;

		char mask_value = pMaskData[i];
		switch (mask_value)
		{
		case 'x':
		case 'X':
			m_testInstruction[i] = true;
			break;
		case '?':
			m_testInstruction[i] = false;
			break;
		default:
			throw 1;
		}
	}
}
