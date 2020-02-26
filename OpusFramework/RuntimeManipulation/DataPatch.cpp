#include "opusframework-private-pch.h"


DataPatchBase* DataPatchBase::s_pFirstDataPatch = nullptr;
DataPatchBase* DataPatchBase::s_pLastDataPatch = nullptr;

DataPatchBase::DataPatchBase(
	DataPatchSearchCallback searchFunction,
	DataPatchApply_DataPatchPacket_Callback applyFunction_Packet,
	DataPatchApply_DataPatchPackets_Callback applyFunction_Packets,
	bool applyOnInit)
	: m_pNextDataPatch(nullptr)
	, m_engine(Engine::NotSet)
	, m_build(Build::NotSet)
	, m_offset(~uintptr_t())
	, m_applyOnInit(applyOnInit)
	, m_pSearchFunction(searchFunction)
	, m_pApplyFunction_Packet(applyFunction_Packet)
	, m_pApplyFunction_Packets(applyFunction_Packets)
	, m_pPublicSymbol(nullptr)
{
	ASSERT(m_pSearchFunction);
	ASSERT(m_pApplyFunction_Packet || m_pApplyFunction_Packets);
	init();
}

DataPatchBase::DataPatchBase(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPacket_Callback applyFunction_Packet, bool applyOnInit)
	: DataPatchBase(searchFunction, applyFunction_Packet, nullptr, applyOnInit)
{
}

DataPatchBase::DataPatchBase(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPackets_Callback applyFunction_Packets, bool applyOnInit)
	: DataPatchBase(searchFunction, nullptr, applyFunction_Packets, applyOnInit)
{
}

void DataPatchBase::init()
{
	if (s_pLastDataPatch)
	{
		s_pLastDataPatch->m_pNextDataPatch = this;
		s_pLastDataPatch = this;
	}
	else
	{
		s_pFirstDataPatch = this;
		s_pLastDataPatch = this;
	}
}

void DataPatchBase::InitTree(Engine engine, Build build)
{
	DataPatchBase* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		pCurrentDataPatch = pCurrentDataPatch->initNode(engine, build);
	}
}

void DataPatchBase::DeinitTree(Engine engine, Build build)
{
	DataPatchBase* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		pCurrentDataPatch = pCurrentDataPatch->deinitNode(engine, build);
	}
}

void DataPatchBase::DestroyTree()
{
	DataPatchBase* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		DataPatchBase* pNextDataPatchBase = pCurrentDataPatch->m_pNextDataPatch;

		delete pCurrentDataPatch;

		pCurrentDataPatch = pNextDataPatchBase;
	}
}

bool DataPatchBase::ApplyPatch()
{
	if (m_offset == ~uintptr_t())
	{
		return false;
	}

	uintptr_t gameVirtualAddress = GetEngineBaseAddress(m_engine);
	uintptr_t dataVirtualAddress = static_cast<uintptr_t>(m_offset);
	uintptr_t dataRelativeVirtualAddress = dataVirtualAddress - gameVirtualAddress;
	char* pGameBaseAddress = reinterpret_cast<char*>(GetEngineMemoryAddress(m_engine));
	char* pDataAddress = pGameBaseAddress + dataRelativeVirtualAddress;

	if (m_pPublicSymbol)
	{
		WriteLineVerbose("Applying DataPatch: %s", m_pPublicSymbol->m_name.c_str());
	}
	else
	{
		WriteLineVerbose("Applying DataPatch: <unknown>");
	}

	if (m_pApplyFunction_Packet)
	{
		m_packets.resize(1);
		m_packets[0] = DataPatchPacket();
		m_pApplyFunction_Packet(m_engine, m_build, pDataAddress, m_packets[0]);

		ASSERT(m_packets[0].first != nullptr);
	}
	else if (m_pApplyFunction_Packets)
	{
		m_pApplyFunction_Packets(m_engine, m_build, pDataAddress, m_packets);

		ASSERT(!m_packets.empty());
		for (DataPatchPacket& packet : m_packets)
		{
			ASSERT(packet.first != nullptr);
			ASSERT(!packet.second.empty());
		}
	}
	else FATAL_ERROR(L"No Apply Callback");

	return true;
}

bool DataPatchBase::RevertPatch()
{
	if (!m_isPatched)
	{
		return false;
	}

	if (m_pPublicSymbol)
	{
		WriteLineVerbose("Reverting DataPatch: %s", m_pPublicSymbol->m_name.c_str());
	}
	else
	{
		WriteLineVerbose("Reverting DataPatch: <unknown>");
	}

	for (DataPatchPacket& packet : m_packets)
	{
		// revert the patch
		memcpy(packet.first, packet.second.data(), packet.second.size());
	}

	return true;
}

DataPatchBase* DataPatchBase::initNode(Engine engine, Build build)
{
	ASSERT(m_offset == ~uintptr_t(), "DataPatch is already patched! This node should be reset before patching again");

	if (m_pPublicSymbol == nullptr)
	{
		m_pPublicSymbol = MappingFileParser::GetPublicSymbolByVirtualAddress(this);
	}

	uintptr_t target_offset = m_pSearchFunction(engine, build);
	if (target_offset != ~uintptr_t())
	{
		m_offset = target_offset;
		m_engine = engine;
		m_build = build;

		if (m_applyOnInit)
		{
			ApplyPatch();
		}
	}
	return m_pNextDataPatch;
}

DataPatchBase* DataPatchBase::deinitNode(Engine engine, Build build)
{
	m_offset = ~uintptr_t();
	m_engine = Engine::NotSet;
	m_build = Build::NotSet;

	RevertPatch();

	return m_pNextDataPatch;
}
