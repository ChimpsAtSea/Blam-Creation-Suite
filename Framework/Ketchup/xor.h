#pragma once

namespace ketchup
{
	class _xor : public Instruction
	{
	public:
		_xor();
		_xor(const char* pMask, ...);
		virtual const unsigned char* Match(const unsigned char* pInput);
	};
}


