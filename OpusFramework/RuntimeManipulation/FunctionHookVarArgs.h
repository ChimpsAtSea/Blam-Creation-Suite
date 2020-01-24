#pragma once


template<BuildVersion buildVersion, size_t offset, typename base_type>
struct FunctionHookVarArgs : public FunctionHookBase
{
public:
	static_assert(buildVersion == BuildVersion::NotSet || offset >= GetBuildBaseAddress(buildVersion), "Offset is out of bounds");
	static_assert(buildVersion == BuildVersion::NotSet || offset < GetEngineTopAddress(buildVersion), "Offset is out of bounds");

	template<typename ...Args>
	__forceinline decltype(auto) operator()(Args... args)
	{
		size_t x = 0; // needed to fix register issue on debug

		using return_type = decltype(base(args...));

		if constexpr (std::is_same<return_type, void>::value)
		{
			base(args...);
			if (m_pCallback)
			{
				m_pCallback(m_pCallbackUserData);
			}
		}
		else
		{
			auto result = base(args...);
			if (m_pCallback)
			{
				m_pCallback(m_pCallbackUserData);
			}
			return result;
		}
	}

	friend class FunctionHookBase;

	template<typename hook_assignment_type>
	FunctionHookVarArgs(hook_assignment_type func)
		:FunctionHookBase(nullptr, buildVersion, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(base_type* func)
		:FunctionHookBase(nullptr, buildVersion, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgs(const char* pName, hook_assignment_type func)
		:FunctionHookBase(pName, buildVersion, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(const char* pName, base_type* func)
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

