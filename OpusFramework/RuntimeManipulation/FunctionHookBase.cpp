#include "opusframework-private-pch.h"

FunctionHookBase* FunctionHookBase::g_pFirstFunctionHook = nullptr;
FunctionHookBase* FunctionHookBase::g_pLastFunctionHook = nullptr;

void FunctionHookBase::InitTree(EngineVersion engineVersion, BuildVersion buildVersion)
{
	// this iteration avoids having to do this recursively

	FunctionHookBase* pCurrentFunctionHook = g_pFirstFunctionHook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->InitNode(engineVersion, buildVersion);
	}
}

void FunctionHookBase::DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion)
{
	// this iteration avoids having to do this recursively

	FunctionHookBase* pCurrentFunctionHook = g_pFirstFunctionHook;
	while (pCurrentFunctionHook)
	{
		pCurrentFunctionHook = pCurrentFunctionHook->DeinitNode(engineVersion, buildVersion);
	}
}

FunctionHookBase* FunctionHookBase::InitNode(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if ((m_engineVersion == engineVersion || m_engineVersion == EngineVersion::NotSet) && ((buildVersion == m_buildVersion || (m_buildVersion == BuildVersion::NotSet && m_find_offset_func)) && m_isActive && !m_isHooked))
	{
		if (m_offset == 0 && m_find_offset_func)
		{
			intptr_t foundOffset = m_find_offset_func(engineVersion, buildVersion);

			if (foundOffset == ~intptr_t())
			{
				return m_pNextFunctionHook;
			}

			m_offset = foundOffset;

			ASSERT(m_buildVersion == BuildVersion::NotSet && m_offset >= GetEngineBaseAddress(engineVersion)/*, "Offset is out of bounds"*/);
			ASSERT(m_buildVersion == BuildVersion::NotSet && m_offset < GetEngineTopAddress(engineVersion, buildVersion)/*, "Offset is out of bounds"*/);
		}
		ASSERT(m_offset != 0);

		FunctionHookVarArgs<EngineVersion::NotSet, BuildVersion::NotSet, 0, void>& rVoidThis = reinterpret_cast<FunctionHookVarArgs<EngineVersion::NotSet, BuildVersion::NotSet, 0, void>&>(*this);

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
			LONG result = create_hook(engineVersion, buildVersion, m_offset, pFunctionName, rHook, rBase);
			ASSERT(result == 0);
		}
		else
		{
			populate_function_ptr(GetEngineFilename(engineVersion), GetEngineBaseAddress(engineVersion), m_offset, rBase);
			WriteLineVerbose("Created function pointer for %s", pFunctionName);
		}

		m_isHooked = true;
	}
	return m_pNextFunctionHook;
}


FunctionHookBase* FunctionHookBase::DeinitNode(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (m_isHooked)
	{
		m_isHooked = false; // #TODO: Do this better. We are unload the DLL so this is okay...
	}
	return m_pNextFunctionHook;
}
