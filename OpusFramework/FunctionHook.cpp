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
	if ((buildVersion == m_buildVersion || (m_buildVersion == BuildVersion::NotSet && m_find_offset_func)) && m_isActive && !m_isHooked)
	{
		if (m_offset == 0 && m_find_offset_func)
		{
			m_offset = m_find_offset_func(engineVersion, buildVersion);

			if (m_offset == ~intptr_t())
			{
				return m_pNextFunctionHook;
			}

			assert(m_buildVersion == BuildVersion::NotSet && m_offset >= GetHaloBaseAddress(buildVersion)/*, "Offset is out of bounds"*/);
			assert(m_buildVersion == BuildVersion::NotSet && m_offset < GetHaloTopAddress(buildVersion)/*, "Offset is out of bounds"*/);
		}
		assert(m_offset);

		FunctionHookVarArgs<BuildVersion::NotSet, 0, void>& rVoidThis = reinterpret_cast<FunctionHookVarArgs<BuildVersion::NotSet, 0, void>&>(*this);

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
			auto result = create_hook(engineVersion, buildVersion, m_offset, pFunctionName, rHook, rBase);
			assert(result == 0);
		}
		else
		{
			populate_function_ptr(GetHaloExecutableString(engineVersion), GetHaloBaseAddress(buildVersion), m_offset, rBase);
			WriteLineVerbose("Created function pointer for %s", pFunctionName);
		}

		m_isHooked = true;
	}
	return m_pNextFunctionHook;
}


FunctionHookBase* FunctionHookBase::DeinitNode(EngineVersion engineVersion, BuildVersion buildVersion)
{
	return m_pNextFunctionHook;
}
