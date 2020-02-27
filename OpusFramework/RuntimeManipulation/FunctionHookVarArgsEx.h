#pragma once


template<find_offset_func find_offset, typename base_type>
struct FunctionHookVarArgsEx : public c_function_hook_base
{
public:
	//static_assert(build == BuildVersion::NotSet || offset >= GetBuildBaseAddress(build), "Offset is out of bounds");
	//static_assert(build == BuildVersion::NotSet || offset < GetEngineTopAddress(engine, build), "Offset is out of bounds");

	template<typename ...Args>
	__forceinline decltype(auto) operator()(Args... args) const
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

	friend class c_function_hook_base;

	template<typename hook_assignment_type>
	FunctionHookVarArgsEx(hook_assignment_type func)
		:c_function_hook_base(nullptr, Engine::NotSet, Build::NotSet, 0, find_offset)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgsEx(base_type* func)
		:c_function_hook_base(nullptr, Engine::NotSet, Build::NotSet, 0, find_offset)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgsEx(const char* pName, hook_assignment_type func)
		:c_function_hook_base(pName, Engine::NotSet, Build::NotSet, 0, find_offset)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgsEx(const char* pName, base_type* func)
		:c_function_hook_base(pName, Engine::NotSet, Build::NotSet, 0, find_offset)
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

