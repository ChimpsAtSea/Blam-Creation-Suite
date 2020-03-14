#pragma once


template<e_engine_type engine_type, e_build build, size_t offset, typename base_type>
struct FunctionHookVarArgs : public c_function_hook_base
{
public:
	static_assert(build == _build_not_set || offset >= GetEngineBaseAddress(engine_type), "Offset is out of bounds");
	static_assert(build == _build_not_set || offset < GetEngineTopAddress(engine_type, build), "Offset is out of bounds");

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

	friend class c_function_hook_base;

	template<typename hook_assignment_type>
	FunctionHookVarArgs(hook_assignment_type func)
		:c_function_hook_base(nullptr, engine_type, build, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(base_type* func)
		:c_function_hook_base(nullptr, engine_type, build, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgs(const char* pName, hook_assignment_type func)
		:c_function_hook_base(pName, engine_type, build, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(const char* pName, base_type* func)
		:c_function_hook_base(pName, engine_type, build, offset, nullptr)
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

