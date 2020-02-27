#pragma once

typedef void(FunctionHookCallback)(void* pUserData);

class c_function_hook_base
{
public:
	c_function_hook_base(const char* pName, e_engine_type engine_type, e_build build, size_t offset, find_offset_func find_offset)
		: m_engine(engine_type)
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
			bool hookOffsetExists = g_pLastFunctionHook->DoesOffsetExist(engine_type, build, offset);
			ASSERT(hookOffsetExists == false);

			g_pLastFunctionHook->m_pNextFunctionHook = this;
			g_pLastFunctionHook = this;
		}
	}

	[[nodiscard]] inline bool is_hooked() const { return m_isHooked; };
	[[nodiscard]] inline bool is_active() const { return m_isActive; };
	[[nodiscard]] inline e_engine_type get_engine_type() const { return m_engine; };
	[[nodiscard]] inline e_build get_build() const { return m_build; };
	[[nodiscard]] inline FunctionHookCallback* get_callback() const { return m_pCallback; };
	[[nodiscard]] inline void* get_callback_userdata() const { return m_pCallbackUserData; };
	[[nodiscard]] inline const char* get_name() const { return m_name; };

	static void init_function_hook_tree(e_engine_type engine_type, e_build build);
	static void deinit_function_hook_tree(e_engine_type engine_type, e_build build);

protected:

	find_offset_func* m_find_offset_func;
	uintptr_t m_offset;
	e_engine_type m_engine;
	e_build m_build;
	bool m_isActive;
	bool m_isHooked;
	FunctionHookCallback* m_pCallback;
	void* m_pCallbackUserData;
	const char* m_name;

	c_function_hook_base* m_pNextFunctionHook;
	static c_function_hook_base* g_pFirstFunctionHook;
	static c_function_hook_base* g_pLastFunctionHook;

	[[nodiscard]] c_function_hook_base* InitNode(e_engine_type engine_type, e_build build);
	[[nodiscard]] c_function_hook_base* DeinitNode(e_engine_type engine_type, e_build build);

	void SetIsActive(bool isActive)
	{
		m_isActive = isActive;
	}

	void SetCallback(FunctionHookCallback* pCallback, void* pCallbackUserData)
	{
		m_pCallback = pCallback;
		m_pCallbackUserData = pCallbackUserData;
	}

	bool DoesOffsetExist(e_engine_type engine_type, e_build build, size_t offset)
	{
		if (m_engine == engine_type)
		{
			if (build == e_build::_build_not_set)
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
			return m_pNextFunctionHook->DoesOffsetExist(engine_type, build, offset);
		}
		return false;
	}
};

