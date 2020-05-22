#pragma once

namespace ketchup
{
	class Instruction
	{
	public:
		Instruction(int length);
		Instruction(const char* pMask);
		Instruction(const char* pMask, int b0);
		Instruction(const char* pMask, int b0, int b1);
		Instruction(const char* pMask, int b0, int b1, int b2);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10);
		Instruction(const char* pMask, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int b11);
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
