#pragma once

typedef void(FunctionHookCallback)(void* pUserData);

class c_function_hook_base
{
public:
	c_function_hook_base(const char* pName, Engine engine, Build build, size_t offset, find_offset_func find_offset)
		: m_engine(engine)
		, m_build(build)
		, m_offset(offset)
		, m_pNextFunctionHook(nullptr)
		, m_isActive(true)
		, m_isHooked(false)
		, m_name(pName)
		, m_find_offset_func(find_offset)
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
			bool hookOffsetExists = g_pLastFunctionHook->DoesOffsetExist(engine, build, offset);
			ASSERT(hookOffsetExists == false);

			g_pLastFunctionHook->m_pNextFunctionHook = this;
			g_pLastFunctionHook = this;
		}
	}

	find_offset_func* m_find_offset_func;
	uintptr_t m_offset;
	Engine m_engine;
	Build m_build;
	bool m_isActive;
	bool m_isHooked;
	FunctionHookCallback* m_pCallback;
	void* m_pCallbackUserData;
	const char* m_name;

	c_function_hook_base* m_pNextFunctionHook;
	static c_function_hook_base* g_pFirstFunctionHook;
	static c_function_hook_base* g_pLastFunctionHook;

	[[nodiscard]] c_function_hook_base* InitNode(Engine engine, Build build);
	[[nodiscard]] c_function_hook_base* DeinitNode(Engine engine, Build build);

	static void InitTree(Engine engine, Build build);
	static void DeinitTree(Engine engine, Build build);

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
	bool DoesOffsetExist(Engine engine, Build build, size_t offset)
	{
		if (m_engine == engine)
		{
			if (build == Build::NotSet)
			{
				return false;
			}
			if (m_build == build && offset == m_offset)
			{
				return true;
			}
		}
		if (m_pNextFunctionHook)
		{
			return m_pNextFunctionHook->DoesOffsetExist(engine, build, offset);
		}
		return false;
	}
};

