#pragma once


template<e_build build, size_t offset, typename T>
struct FunctionHook;

template<e_build build, size_t offset, typename R, typename ...Args>
struct FunctionHook<build, offset, R(Args...)> : c_function_hook_base
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
			if (callback)
			{
				callback(callback_user_data);
			}
		}
		else
		{
			auto result = base(arg...);
			if (callback)
			{
				callback(callback_user_data);
			}
			return result;
		}
	}

	friend class c_function_hook_base;

	template<typename hook_assignment_type>
	FunctionHook(hook_assignment_type func)
		:c_function_hook_base(nullptr, build, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(R(*func)(Args...))
		:c_function_hook_base(nullptr, build, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHook(const char pName[], hook_assignment_type func)
		:c_function_hook_base(pName, build, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(const char pName[], R(*func)(Args...))
		:c_function_hook_base(pName, build, offset, nullptr)
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

