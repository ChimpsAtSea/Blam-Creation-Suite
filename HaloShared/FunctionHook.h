#pragma once

#pragma optimize("", off)


typedef void(FunctionHookCallback)(void* pUserData);

class FunctionHookBase
{
public:
	FunctionHookBase(const char* pName, HaloGameID gameID, size_t offset, intptr_t(find_offset_func)(HaloGameID gameID))
		: m_gameID(gameID)
		, m_offset(offset)
		, m_pNextFunctionHook(nullptr)
		, m_isActive(true)
		, m_isHooked(false)
		, m_name(pName)
		, m_find_offset_func(find_offset_func)
		, m_pCallback(nullptr)
		, m_pCallbackUserData(nullptr)
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

	intptr_t(*m_find_offset_func)(HaloGameID gameID);
	size_t m_offset;
	HaloGameID m_gameID;
	bool m_isActive;
	bool m_isHooked;
	FunctionHookCallback* m_pCallback;
	void* m_pCallbackUserData;
	const char* m_name;

	FunctionHookBase* m_pNextFunctionHook;
	static FunctionHookBase* g_pFirstFunctionHook;
	static FunctionHookBase* g_pLastFunctionHook;

	[[nodiscard]] FunctionHookBase* InitNode(HaloGameID gameID);
	[[nodiscard]] FunctionHookBase* DeinitNode(HaloGameID gameID);

	static void InitTree(HaloGameID gameID);
	static void DeinitTree(HaloGameID gameID);

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
		if (gameID == HaloGameID::NotSet)
		{
			return false;
		}
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

#include <functional>

template<HaloGameID gameID, size_t offset, typename T>
struct FunctionHook;

template<HaloGameID gameID, size_t offset, typename R, typename ...Args>
struct FunctionHook<gameID, offset, R(Args...)> : FunctionHookBase
{
public:
	typedef R(base_type)(Args...);

	static_assert(gameID == HaloGameID::NotSet || offset >= GetHaloBaseAddress(gameID), "Offset is out of bounds");
	static_assert(gameID == HaloGameID::NotSet || offset < GetHaloTopAddress(gameID), "Offset is out of bounds");

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
		:FunctionHookBase(nullptr, gameID, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(R(*func)(Args...))
		:FunctionHookBase(nullptr, gameID, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHook(const char pName[], hook_assignment_type func)
		:FunctionHookBase(pName, gameID, offset, nullptr)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHook(const char pName[], R(*func)(Args...))
		:FunctionHookBase(pName, gameID, offset, nullptr)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& GetHook()
	{
		return *const_cast<base_type * *>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type * *>(&base);
	}
};

template<intptr_t(find_offset_func)(HaloGameID gameID), typename T>
struct FunctionHookEx;

template<intptr_t(find_offset_func)(HaloGameID gameID), typename R, typename ...Args>
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
		: FunctionHookBase(nullptr, HaloGameID::NotSet, 0, find_offset_func)
		, hook(nullptr)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookEx(hook_assignment_type func)
		:FunctionHookBase(nullptr, HaloGameID::NotSet, 0, find_offset_func)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookEx(R(*func)(Args...))
		:FunctionHookBase(nullptr, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookEx(const char pName[], hook_assignment_type func)
		:FunctionHookBase(pName, HaloGameID::NotSet, 0, find_offset_func)
		, hook((base_type*)func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookEx(const char pName[], R(*func)(Args...))
		:FunctionHookBase(pName, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& GetHook()
	{
		return *const_cast<base_type * *>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type * *>(&base);
	}
};

template<HaloGameID gameID, size_t offset, typename base_type>
struct FunctionHookVarArgs : public FunctionHookBase
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
	FunctionHookVarArgs(hook_assignment_type func)
		:FunctionHookBase(nullptr, gameID, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(base_type* func)
		:FunctionHookBase(nullptr, gameID, offset, nullptr)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgs(const char* pName, hook_assignment_type func)
		:FunctionHookBase(pName, gameID, offset, nullptr)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgs(const char* pName, base_type* func)
		:FunctionHookBase(pName, gameID, offset, nullptr)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& GetHook()
	{
		return *const_cast<base_type * *>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type * *>(&base);
	}
};

template<intptr_t(find_offset_func)(HaloGameID gameID), typename base_type>
struct FunctionHookVarArgsEx : public FunctionHookBase
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
	FunctionHookVarArgsEx(hook_assignment_type func)
		:FunctionHookBase(nullptr, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgsEx(base_type* func)
		:FunctionHookBase(nullptr, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	template<typename hook_assignment_type>
	FunctionHookVarArgsEx(const char* pName, hook_assignment_type func)
		:FunctionHookBase(pName, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func) // assigning the hook_assignment_type to the base_type will convert lambdas to function pointers
	{

	}

	FunctionHookVarArgsEx(const char* pName, base_type* func)
		:FunctionHookBase(pName, HaloGameID::NotSet, 0, find_offset_func)
		, hook(func)
	{

	}

	base_type* const hook = nullptr;
	base_type* const base = nullptr;

private:

	base_type*& GetHook()
	{
		return *const_cast<base_type * *>(&hook);
	}

	base_type*& GetBase()
	{
		return *const_cast<base_type * *>(&base);
	}
};

#pragma optimize("", on)

template<size_t offset, typename base_type>
using HaloReach_2019_Jun_24_Hook = FunctionHook<HaloGameID::HaloReach_2019_Jun_24, offset, base_type>;
template<size_t offset, typename base_type>
using HaloReach_2019_Jun_24_HookVarArgs = FunctionHookVarArgs<HaloGameID::HaloReach_2019_Jun_24, offset, base_type>;




