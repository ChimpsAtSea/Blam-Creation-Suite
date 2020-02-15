#pragma once


template<BuildVersion buildVersion, size_t offset, typename T>
struct FunctionHook;

template<BuildVersion buildVersion, size_t offset, typename R, typename ...Args>
struct FunctionHook<buildVersion, offset, R(Args...)> : FunctionHookBase
{
public:
	typedef R(base_type)(Args...);

	static_assert(buildVersion == BuildVersion::NotSet || offset >= GetEngineBaseAddress(engineVersion), "Offset is out of bounds");
	static_assert(buildVersion == BuildVersion::NotSet || offset < GetEngineTopAddress(engineVersion, buildVersion), "Offset is out of bounds");

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

	template<typename hook_assignment_type>
	FunctionHook(hook_assignment_type func)
		:FunctionHookBase(nullptr, buildVersion, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(R(*func)(Args...))
		:FunctionHookBase(nullptr, buildVersion, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHook(const char pName[], hook_assignment_type func)
		:FunctionHookBase(pName, buildVersion, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(const char pName[], R(*func)(Args...))
		:FunctionHookBase(pName, buildVersion, offset, nullptr)
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

