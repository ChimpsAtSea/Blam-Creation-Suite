#pragma once

namespace ketchup
{
	enum class JumpType
	{
		jz,
		jnz,
		jbe
	};

	enum class JumpDistance
	{
		Short,
		Long
	};

	template<JumpType T>
	class _jump : public Instruction
	{
	public:
		template<typename... Args>
		_jump(const char* pMask, JumpDistance jumpSize, Args... args)
			:Instruction(pMask, args...)
			, m_jumpSize(jumpSize)
		{
			
		}

		const JumpDistance m_jumpSize;
	};

	typedef _jump<JumpType::jz> _jz;
	typedef _jump<JumpType::jnz> _jnz;
	typedef _jump<JumpType::jbe> _jbe;
}


