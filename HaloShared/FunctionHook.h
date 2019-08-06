#pragma once

typedef void(FunctionHookCallback)(void* pUserData);

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
			bool hookOffsetExists = g_pLastFunctionHook->DoesOffsetExist(gameID, offset);
			assert(hookOffsetExists == false);

			g_pLastFunctionHook->m_pNextFunctionHook = this;
			g_pLastFunctionHook = this;
		}
	}

	size_t m_offset;
	HaloGameID m_gameID;
	bool m_isActive;
	FunctionHookCallback* m_pCallback;
	void* m_pCallbackUserData;

	FunctionHookBase* m_pNextFunctionHook;
	static FunctionHookBase* g_pFirstFunctionHook;
	static FunctionHookBase* g_pLastFunctionHook;

	void ProcessNode(HaloGameID gameID);
	static void ProcessTree(HaloGameID gameID);

	void SetIsActive(bool isActive)
	{
		m_isActive = isActive;
	}

	void SetCallback(FunctionHookCallback* pCallback, void* pCallbackUserData)
	{
		m_pCallback = pCallback;
		m_pCallbackUserData = pCallbackUserData;
	}

private:
	bool DoesOffsetExist(HaloGameID gameID, size_t offset)
	{
		if (m_gameID == gameID && offset == m_offset)
		{
			return true;
		}
		if (m_pNextFunctionHook)
		{
			return m_pNextFunctionHook->DoesOffsetExist(gameID, offset);
		}
		return false;
	}
};

template<HaloGameID gameID, size_t offset, typename base_type>
class FunctionHook : public FunctionHookBase
{
public:
	static_assert(gameID == HaloGameID::NotSet || offset >= GetHaloBaseAddress(gameID), "Offset is out of bounds");
	static_assert(gameID == HaloGameID::NotSet || offset < GetHaloTopAddress(gameID), "Offset is out of bounds");
	
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


template<size_t offset, typename base_type>
using HaloReachHook = FunctionHook<HaloGameID::HaloReach, offset, base_type>;
