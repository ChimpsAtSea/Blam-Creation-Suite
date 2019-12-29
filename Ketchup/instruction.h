#pragma once

namespace ketchup
{
	class Instruction
	{
	public:
		Instruction(int length);
		Instruction(const char* pMask);
		Instruction(const char* pMask, char b0);
		Instruction(const char* pMask, char b0, char b1);
		Instruction(const char* pMask, char b0, char b1, char b2);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9, char b10);
		Instruction(const char* pMask, char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9, char b10, char b11);
		virtual const unsigned char* Match(const unsigned char* pInput);

		const size_t m_length;
	protected:
		Instruction(const char* pMask, bool shouldInit);

		std::vector<bool> m_testInstruction;
		std::vector<unsigned char> m_instructionBytes;

		const void init(const char* pMask, ...);
		const void init(const char* pMask, va_list& rArgs);
	};
}
