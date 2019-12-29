#include "ketchup-private-pch.h"

Instruction::Instruction(int length)
	:m_length(length)
{

}

Instruction::Instruction(const char* pMask, bool shouldInit) : m_length(__max(strlen(pMask), 0)) { if (shouldInit) { init(pMask); } }
Instruction::Instruction(const char* pMask) : Instruction(pMask, true) {}

Instruction::Instruction(const char* pMask, int b0) : m_length(__max(strlen(pMask), 1)) { init(pMask, static_cast<char>(b0)); }
Instruction::Instruction(const char* pMask, int b0, int b1) : m_length(__max(strlen(pMask), 2)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2) : m_length(__max(strlen(pMask), 3)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3) : m_length(__max(strlen(pMask), 4)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4) : m_length(__max(strlen(pMask), 5)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5) : m_length(__max(strlen(pMask), 6)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6) : m_length(__max(strlen(pMask), 7)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7) : m_length(__max(strlen(pMask), 8)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6), static_cast<char>(b7)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8) : m_length(__max(strlen(pMask), 9)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6), static_cast<char>(b7), static_cast<char>(b8)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9) : m_length(__max(strlen(pMask), 10)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6), static_cast<char>(b7), static_cast<char>(b8), static_cast<char>(b9)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10) : m_length(__max(strlen(pMask), 11)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6), static_cast<char>(b7), static_cast<char>(b8), static_cast<char>(b9), static_cast<char>(b10)); }
Instruction::Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int b11) : m_length(__max(strlen(pMask), 12)) { init(pMask, static_cast<char>(b0), static_cast<char>(b1), static_cast<char>(b2), static_cast<char>(b3), static_cast<char>(b4), static_cast<char>(b5), static_cast<char>(b6), static_cast<char>(b7), static_cast<char>(b8), static_cast<char>(b9), static_cast<char>(b10), static_cast<char>(b11)); }



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
