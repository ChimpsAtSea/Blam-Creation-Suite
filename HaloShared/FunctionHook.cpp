#include "haloshared-private-pch.h"

FunctionHookBase* FunctionHookBase::g_pFirstFunctionHook = nullptr;
FunctionHookBase* FunctionHookBase::g_pLastFunctionHook = nullptr;

void FunctionHookBase::ProcessTree(HaloGameID gameID)
{
	if (g_pFirstFunctionHook)
	{
		g_pFirstFunctionHook->ProcessNode(gameID);
	}
}

void FunctionHookBase::ProcessNode(HaloGameID gameID)
{
	if (gameID == m_gameID && m_isActive)
	{
		FunctionHookVarArgs<HaloGameID::NotSet, 0, void>& rVoidThis = reinterpret_cast<FunctionHookVarArgs<HaloGameID::NotSet, 0, void>&>(*this);

		void*& rBase = rVoidThis.GetBase();
		void*& rHook = rVoidThis.GetHook();

		assert(rHook);

		auto result = create_hook(m_gameID, m_offset, "FunctionHookBase", rHook, rBase);
		assert(result == 0);
	}
	if (m_pNextFunctionHook)
	{
		m_pNextFunctionHook->ProcessNode(gameID);
	}
}