#include "opusframework-private-pch.h"

FunctionHookBase* FunctionHookBase::g_pFirstFunctionHook = nullptr;
FunctionHookBase* FunctionHookBase::g_pLastFunctionHook = nullptr;

void FunctionHookBase::InitTree(Engine engine, Build build)
{
	// this iteration avoids having to do this recursively

	FunctionHookBase* pCurrentFunctionHook = g_pFirstFunctionHook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->InitNode(engine, build);
	}
}

void FunctionHookBase::DeinitTree(Engine engine, Build build)
{
	// this iteration avoids having to do this recursively

	FunctionHookBase* pCurrentFunctionHook = g_pFirstFunctionHook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->DeinitNode(engine, build);
	}
}

FunctionHookBase* FunctionHookBase::InitNode(Engine engine, Build build)
{
	if ((m_engine == engine || m_engine == Engine::NotSet) && ((build == m_build || (m_build == Build::NotSet && m_find_offset_func)) && m_isActive && !m_isHooked))
	{
		if (m_offset == 0 && m_find_offset_func)
		{
			uintptr_t foundOffset = m_find_offset_func(engine, build);

			if (foundOffset == ~uintptr_t())
			{
				return m_pNextFunctionHook;
			}

			m_offset = foundOffset;

			ASSERT(m_build == Build::NotSet && m_offset >= GetEngineBaseAddress(engine)/*, "Offset is out of bounds"*/);
			ASSERT(m_build == Build::NotSet && m_offset < GetEngineTopAddress(engine, build)/*, "Offset is out of bounds"*/);
		}
		ASSERT(m_offset != 0);

		FunctionHookVarArgs<Engine::NotSet, Build::NotSet, 0, void>& rVoidThis = reinterpret_cast<FunctionHookVarArgs<Engine::NotSet, Build::NotSet, 0, void>&>(*this);

		void*& rBase = rVoidThis.GetBase();
		void*& rHook = rVoidThis.GetHook();

		const char* pFunctionName = m_name;
		char pUnknownFunctionNameBuffer[256] = {};
		if (pFunctionName == nullptr)
		{
			int count = snprintf(pUnknownFunctionNameBuffer, _countof(pUnknownFunctionNameBuffer), "unnamed<0x%zX>", m_offset);
			pUnknownFunctionNameBuffer[_countof(pUnknownFunctionNameBuffer) - 1] = 0;
			pFunctionName = pUnknownFunctionNameBuffer;
		}

		if (rHook)
		{
			LONG result = create_hook(engine, build, m_offset, pFunctionName, rHook, rBase);
			ASSERT(result == 0);
		}
		else
		{
			populate_function_ptr(GetEngineModuleFileName(engine), GetEngineBaseAddress(engine), m_offset, rBase);
			WriteLineVerbose("Created function pointer for %s", pFunctionName);
		}

		m_isHooked = true;
	}
	return m_pNextFunctionHook;
}


FunctionHookBase* FunctionHookBase::DeinitNode(Engine engine, Build build)
{
	if (m_isHooked)
	{
		m_isHooked = false; // #TODO: Do this better. We are unload the DLL so this is okay...
	}
	return m_pNextFunctionHook;
}
