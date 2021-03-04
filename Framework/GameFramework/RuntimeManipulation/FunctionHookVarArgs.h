#pragma once


template<e_engine_type _engine_type, e_build _build, size_t _offset, typename base_type>
struct FunctionHookVarArgs : public c_function_hook_base
{
public:
	template<typename ...Args>
	__forceinline decltype(auto) operator()(Args... args)
	{
		size_t x = 0; // needed to fix register issue on debug

		using return_type = decltype(base(args...));

		if constexpr (std::is_same<return_type, void>::value)
		{
			base(args...);
			if (callback)
			{
				callback(callback_user_data);
			}
		}
		else
		{
			auto result = base(args...);
			if (callback)
			{
				callback(callback_user_data);
			}
			return result;
		}
	}

	friend class c_function_hook_base;

	template<typename hook_assignment_type>
	FunctionHookVarArgs(hook_assignment_type func)
		:c_function_hook_base(nullptr, { _engine_type, _platform_type_not_set, _build }, _offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(base_type* func)
		:c_function_hook_base(nullptr, { _engine_type, _platform_type_not_set, _build }, _offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgs(const char* pName, hook_assignment_type func)
		:c_function_hook_base(pName, { _engine_type, _platform_type_not_set, _build }, _offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(const char* pName, base_type* func)
		:c_function_hook_base(pName, { _engine_type, _platform_type_not_set, _build }, _offset, nullptr)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& get_hook()
	{
		return *const_cast<base_type**>(&hook);
	}

	base_type*& get_base()
	{
		return *const_cast<base_type**>(&base);
	}
};

