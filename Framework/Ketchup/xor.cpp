#include "ketchup-private-pch.h"

_xor::_xor()
	:Instruction(3)
{
}

_xor::_xor(const char* pMask, ...)
	: Instruction(pMask, false)
{
	va_list args;
	va_start(args, pMask);
	init(pMask, args);
	va_end(args);
}

const unsigned char* _xor::Match(const unsigned char* pInput)
{
	auto byte0 = pInput[0];

	// make sure this has a REX specifier
	switch (byte0)
	{
	case 0x40: // REX			Access to new 8 - bit registers
	case 0x41: // REX.B		Extension of r / m field, base field, or opcode reg field
	case 0x42: // REX.X		Extension of SIB index field
	case 0x43: // REX.XB		REX.X and REX.B combination
	case 0x44: // REX.R		Extension of ModR / M reg field
	case 0x45: // REX.RB		REX.R and REX.B combination
	case 0x46: // REX.RX		REX.R and REX.X combination
	case 0x47: // REX.RXB		REX.R, REX.X and REX.B combination
	case 0x48: // REX.W	64	Bit Operand ImageSize
	case 0x49: // REX.WB		REX.W and REX.B combination
	case 0x4A: // REX.WX		REX.W and REX.X combination
	case 0x4B: // REX.WXB		REX.W, REX.X and REX.B combination
	case 0x4C: // REX.WR		REX.W and REX.R combination
	case 0x4D: // REX.WRB		REX.W, REX.R and REX.B combination
	case 0x4E: // REX.WRX		REX.W, REX.R and REX.X combination
	case 0x4F: // REX.WRXB	REX.W, REX.R, REX.X and REX.B combination
		break;
	default:
		return nullptr;
	}

	auto byte1 = pInput[1];
	switch (byte1)
	{
	case 0x30: // XOR r/m8 r8 Logical Exclusive OR
	case 0x31: // XOR r/m16/32/64 r16/32/64 Logical Exclusive OR
	case 0x32: // XOR r8 r/m8 Logical Exclusive OR
	case 0x33: // XOR r16/32/64 r/m16/32/64 Logical Exclusive OR
	case 0x34: // XOR AL imm8 Logical Exclusive OR
	case 0x35: // XOR rAX imm16/32 Logical Exclusive OR
		break;
	default:
		return nullptr;
	}

	auto byte2 = pInput[2];
	//TODO: Make sure this is correct

	return pInput + m_length;
}