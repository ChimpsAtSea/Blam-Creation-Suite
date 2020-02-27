#include "opusframework-private-pch.h"


c_data_patch_base* c_data_patch_base::s_pFirstDataPatch = nullptr;
c_data_patch_base* c_data_patch_base::s_pLastDataPatch = nullptr;

c_data_patch_base::c_data_patch_base(
	DataPatchSearchCallback searchFunction,
	DataPatchApply_DataPatchPacket_Callback applyFunction_Packet,
	DataPatchApply_DataPatchPackets_Callback applyFunction_Packets,
	bool applyOnInit)
	: m_pNextDataPatch(nullptr)
	, m_engine(_engine_type_not_set)
	, m_build(_build_not_set)
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

c_data_patch_base::c_data_patch_base(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPacket_Callback applyFunction_Packet, bool applyOnInit)
	: c_data_patch_base(searchFunction, applyFunction_Packet, nullptr, applyOnInit)
{
}

c_data_patch_base::c_data_patch_base(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPackets_Callback applyFunction_Packets, bool applyOnInit)
	: c_data_patch_base(searchFunction, nullptr, applyFunction_Packets, applyOnInit)
{
}

void c_data_patch_base::init()
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

void c_data_patch_base::init_data_patch_tree(e_engine_type engine_type, e_build build)
{
	c_data_patch_base* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		pCurrentDataPatch = pCurrentDataPatch->initNode(engine_type, build);
	}
}

void c_data_patch_base::deinit_data_patch_tree(e_engine_type engine_type, e_build build)
{
	c_data_patch_base* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		pCurrentDataPatch = pCurrentDataPatch->deinitNode(engine_type, build);
	}
}

void c_data_patch_base::DestroyTree()
{
	c_data_patch_base* pCurrentDataPatch = s_pFirstDataPatch;
	while (pCurrentDataPatch)
	{
		c_data_patch_base* pNextc_data_patch_base = pCurrentDataPatch->m_pNextDataPatch;

		delete pCurrentDataPatch;

		pCurrentDataPatch = pNextc_data_patch_base;
	}
}

bool c_data_patch_base::ApplyPatch()
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
		write_line_verbose("Applying DataPatch: %s", m_pPublicSymbol->m_name.c_str());
	}
	else
	{
		write_line_verbose("Applying DataPatch: <unknown>");
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

bool c_data_patch_base::RevertPatch()
{
	if (!m_isPatched)
	{
		return false;
	}

	if (m_pPublicSymbol)
	{
		write_line_verbose("Reverting DataPatch: %s", m_pPublicSymbol->m_name.c_str());
	}
	else
	{
		write_line_verbose("Reverting DataPatch: <unknown>");
	}

	for (DataPatchPacket& packet : m_packets)
	{
		// revert the patch
		memcpy(packet.first, packet.second.data(), packet.second.size());
	}

	return true;
}

c_data_patch_base* c_data_patch_base::initNode(e_engine_type engine_type, e_build build)
{
	ASSERT(m_offset == ~uintptr_t(), "DataPatch is already patched! This node should be reset before patching again");

	if (m_pPublicSymbol == nullptr)
	{
		m_pPublicSymbol = MappingFileParser::GetPublicSymbolByVirtualAddress(this);
	}

	uintptr_t target_offset = m_pSearchFunction(engine_type, build);
	if (target_offset != ~uintptr_t())
	{
		m_offset = target_offset;
		m_engine = engine_type;
		m_build = build;

		if (m_applyOnInit)
		{
			ApplyPatch();
		}
	}
	return m_pNextDataPatch;
}

c_data_patch_base* c_data_patch_base::deinitNode(e_engine_type engine_type, e_build build)
{
	m_offset = ~uintptr_t();
	m_engine = _engine_type_not_set;
	m_build = e_build::_build_not_set;

	RevertPatch();

	return m_pNextDataPatch;
}
