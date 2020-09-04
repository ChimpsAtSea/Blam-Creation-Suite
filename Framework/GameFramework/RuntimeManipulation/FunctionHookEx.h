#pragma once


template<find_offset_func, typename T>
struct c_function_hook_ex;

template<find_offset_func find_offset, typename R, typename ...Args>
struct c_function_hook_ex<find_offset, R(Args...)> : c_function_hook_base
{
public:
	typedef R(base_type)(Args...);

	__forceinline decltype(auto) operator()(Args... arg)
	{
		size_t x = 0; // needed to fix register issue on debug

		using return_type = decltype(base(arg...));

		if constexpr (std::is_same<return_type, void>::value)
		{
			_InterlockedIncrement(&reference_counter);
			base(arg...);
			if (callback)
			{
				callback(callback_user_data);
			}
			_InterlockedDecrement(&reference_counter);
		}
		else
		{
			_InterlockedIncrement(&reference_counter);
			auto result = base(arg...);
			if (callback)
			{
				callback(callback_user_data);
			}
			_InterlockedDecrement(&reference_counter);
			return result;
		}
	}

	friend class c_function_hook_base;

	c_function_hook_ex()
		: c_function_hook_base(nullptr, _engine_type_not_set, _build_not_set, 0, find_offset)
		, hook(nullptr)
	{

	}

	template<typename hook_assignment_type>
	c_function_hook_ex(hook_assignment_type func)
		:c_function_hook_base(nullptr, _engine_type_not_set, _build_not_set, 0, find_offset)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	c_function_hook_ex(R(*func)(Args...))
		:c_function_hook_base(nullptr, _engine_type_not_set, _build_not_set, 0, find_offset)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	c_function_hook_ex(const char pName[], hook_assignment_type func)
		:c_function_hook_base(pName, _engine_type_not_set, _build_not_set, 0, find_offset)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	c_function_hook_ex(const char pName[], R(*func)(Args...))
		:c_function_hook_base(pName, _engine_type_not_set, _build_not_set, 0, find_offset)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;
	volatile uint32_t reference_counter;

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

