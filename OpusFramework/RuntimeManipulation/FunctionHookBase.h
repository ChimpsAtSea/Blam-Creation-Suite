#pragma once

typedef void(FunctionHookCallback)(void* pUserData);

class FunctionHookBase
{
public:
	FunctionHookBase(const char* pName, BuildVersion buildVersion, size_t offset, intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion))
		: m_buildVersion(buildVersion)
		, m_offset(offset)
		, m_pNextFunctionHook(nullptr)
		, m_isActive(true)
		, m_isHooked(false)
		, m_name(pName)
		, m_find_offset_func(find_offset_func)
		, m_pCallback(nullptr)
		, m_pCallbackUserData(nullptr)
	{
		if (g_pFirstFunctionHook == nullptr)
		{
			g_pFirstFunctionHook = this;
			g_pLastFunctionHook = this;
		}
		else
		{
			bool hookOffsetExists = g_pLastFunctionHook->DoesOffsetExist(buildVersion, offset);
			assert(hookOffsetExists == false);

			g_pLastFunctionHook->m_pNextFunctionHook = this;
			g_pLastFunctionHook = this;
		}
	}

	intptr_t(*m_find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion);
	intptr_t m_offset;
	BuildVersion m_buildVersion;
	bool m_isActive;
	bool m_isHooked;
	FunctionHookCallback* m_pCallback;
	void* m_pCallbackUserData;
	const char* m_name;

	FunctionHookBase* m_pNextFunctionHook;
	static FunctionHookBase* g_pFirstFunctionHook;
	static FunctionHookBase* g_pLastFunctionHook;

	[[nodiscard]] FunctionHookBase* InitNode(EngineVersion engineVersion, BuildVersion buildVersion);
	[[nodiscard]] FunctionHookBase* DeinitNode(EngineVersion engineVersion, BuildVersion buildVersion);

	static void InitTree(EngineVersion engineVersion, BuildVersion buildVersion);
	static void DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion);

	void SetIsActive(bool isActive)
	{
		m_isActive = isActive;
	}

	void SetCallback(FunctionHookCallback* pCallback, void* pCallbackUserData)
	{
		m_pCallback = pCallback;
		m_pCallbackUserData = pCallbackUserData;
	}

private:
	bool DoesOffsetExist(BuildVersion buildVersion, size_t offset)
	{
		if (buildVersion == BuildVersion::NotSet)
		{
			return false;
		}
		if (m_buildVersion == buildVersion && offset == m_offset)
		{
			return true;
		}
		if (m_pNextFunctionHook)
		{
			return m_pNextFunctionHook->DoesOffsetExist(buildVersion, offset);
		}
		return false;
	}
};

