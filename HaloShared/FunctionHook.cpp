#include "haloshared-private-pch.h"

FunctionHookBase* FunctionHookBase::g_pFirstFunctionHook = nullptr;
FunctionHookBase* FunctionHookBase::g_pLastFunctionHook = nullptr;

void FunctionHookBase::ProcessTree(HaloGameID gameID)
{
	if (g_pFirstFunctionHook)
	{
		g_pFirstFunctionHook->ProcessNode(gameID);
	}
}

void FunctionHookBase::ProcessNode(HaloGameID gameID)
{
	if ((gameID == m_gameID || (m_gameID == HaloGameID::NotSet && m_find_offset_func)) && m_isActive)
	{
		if (m_offset == 0 && m_find_offset_func)
		{
			m_offset = m_find_offset_func(gameID);

			assert(m_gameID == HaloGameID::NotSet && m_offset >= GetHaloBaseAddress(gameID)/*, "Offset is out of bounds"*/);
			assert(m_gameID == HaloGameID::NotSet && m_offset < GetHaloTopAddress(gameID)/*, "Offset is out of bounds"*/);
		}
		assert(m_offset);

		FunctionHookVarArgs<HaloGameID::NotSet, 0, void>& rVoidThis = reinterpret_cast<FunctionHookVarArgs<HaloGameID::NotSet, 0, void>&>(*this);

		void*& rBase = rVoidThis.GetBase();
		void*& rHook = rVoidThis.GetHook();

		const char* pFunctionName = m_name;
		char pUnknownFunctionNameBuffer[256] = {};
		if (pFunctionName == nullptr)
		{
			int count = snprintf(pUnknownFunctionNameBuffer, _countof(pUnknownFunctionNameBuffer), "unnamed<0x%llX>", m_offset);
			pUnknownFunctionNameBuffer[_countof(pUnknownFunctionNameBuffer) - 1] = 0;
			pFunctionName = pUnknownFunctionNameBuffer;
		}

		if (rHook)
		{
			auto result = create_hook(gameID, m_offset, pFunctionName, rHook, rBase);
			assert(result == 0);
		}
		else
		{
			populate_function_ptr(GetHaloExecutableString(gameID), GetHaloBaseAddress(gameID), m_offset, rBase);
			WriteLineVerbose("Created function pointer for %s", pFunctionName);
		}
	}
	if (m_pNextFunctionHook)
	{
		m_pNextFunctionHook->ProcessNode(gameID);
	}
}