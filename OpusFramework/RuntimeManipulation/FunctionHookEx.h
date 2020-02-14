#pragma once


template<intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion), typename T>
struct FunctionHookEx;


template<intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion), typename R, typename ...Args>
struct FunctionHookEx<find_offset_func, R(Args...)> : FunctionHookBase
{
public:
	typedef R(base_type)(Args...);

	__forceinline decltype(auto) operator()(Args... arg)
	{
		size_t x = 0; // needed to fix register issue on debug

		using return_type = decltype(base(arg...));

		if constexpr (std::is_same<return_type, void>::value)
		{
			base(arg...);
			if (m_pCallback)
			{
				m_pCallback(m_pCallbackUserData);
			}
		}
		else
		{
			auto result = base(arg...);
			if (m_pCallback)
			{
				m_pCallback(m_pCallbackUserData);
			}
			return result;
		}
	}

	friend class FunctionHookBase;

	FunctionHookEx()
		: FunctionHookBase(nullptr, EngineVersion::NotSet, BuildVersion::NotSet, 0, find_offset_func)
		, hook(nullptr)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookEx(hook_assignment_type func)
		:FunctionHookBase(nullptr, EngineVersion::NotSet, BuildVersion::NotSet, 0, find_offset_func)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookEx(R(*func)(Args...))
		:FunctionHookBase(nullptr, EngineVersion::NotSet, BuildVersion::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookEx(const char pName[], hook_assignment_type func)
		:FunctionHookBase(pName, EngineVersion::NotSet, BuildVersion::NotSet, 0, find_offset_func)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookEx(const char pName[], R(*func)(Args...))
		:FunctionHookBase(pName, EngineVersion::NotSet, BuildVersion::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& GetHook()
	{
		return *const_cast<base_type**>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type**>(&base);
	}
};

