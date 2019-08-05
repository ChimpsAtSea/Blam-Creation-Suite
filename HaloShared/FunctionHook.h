#pragma once

class FunctionHookBase
{
public:
	FunctionHookBase(HaloGameID gameID, size_t offset)
		: m_gameID(gameID)
		, m_offset(offset)
		, m_pNextFunctionHook(nullptr)
		, m_isActive(true)
	{
		if (g_pFirstFunctionHook == nullptr)
		{
			g_pFirstFunctionHook = this;
			g_pLastFunctionHook = this;
		}
		else
		{
			g_pLastFunctionHook->m_pNextFunctionHook = this;
			g_pLastFunctionHook = this;
		}
	}

	size_t m_offset;
	HaloGameID m_gameID;
	bool m_isActive;

	FunctionHookBase* m_pNextFunctionHook;
	static FunctionHookBase* g_pFirstFunctionHook;
	static FunctionHookBase* g_pLastFunctionHook;

	void ProcessNode(HaloGameID gameID);
	static void ProcessTree(HaloGameID gameID);
};

template<HaloGameID gameID, size_t offset, typename base_type>
class FunctionHook : FunctionHookBase
{
public:

	// #TODO: Improve this template 
	// can we extract the arguments and return type from the base_type???
	template<typename ...Args>
	decltype(auto) operator()(Args... args)
	{
		return base(args...);
	}

	friend class FunctionHookBase;

	template<typename hook_assignment_type>
	FunctionHook(hook_assignment_type func)
		:FunctionHookBase(gameID, offset)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(base_type* func)
		:FunctionHookBase(gameID, offset)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

	void SetIsActive(bool isActive)
	{
		m_isActive = isActive;
	}

private:
	void SetHook(base_type* ptr)
	{
		base_type*& rHook = GetHook();
		rHook = reinterpret_cast<base_type*>(ptr);
	}

	void SetBase(base_type* ptr)
	{
		base_type*& rBase = GetBase();
		rBase = reinterpret_cast<base_type*>(ptr);
	}

	base_type*& GetHook()
	{
		return *const_cast<base_type * *>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type * *>(&base);
	}
};


