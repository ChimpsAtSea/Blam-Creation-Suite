#pragma once

#define COPY_TO_VECTOR(pointer, count) std::vector<decltype(*pointer)>(pointer, pointer + count)
#define MAKE_DATAPATCHPACKET(pointer, count) {pointer, {pointer, pointer + count}}

typedef std::pair<char*, std::vector<char>> DataPatchPacket;
typedef std::vector<DataPatchPacket> DataPatchPackets;

typedef uintptr_t(DataPatchSearchCallback)(Engine, Build);


typedef void (DataPatchApply_DataPatchPacket_CallbackX)(Engine, Build, char*, DataPatchPacket&);
typedef void (DataPatchApply_DataPatchPackets_CallbackX)(Engine, Build, char*, DataPatchPackets&);

// #TODO: Figure out warning 4927
using DataPatchApply_DataPatchPacket_Callback = std::function<DataPatchApply_DataPatchPacket_CallbackX>;
using DataPatchApply_DataPatchPackets_Callback = std::function<DataPatchApply_DataPatchPackets_CallbackX>;

class c_data_patch_base
{
private:
	c_data_patch_base(
		DataPatchSearchCallback searchFunction, 
		DataPatchApply_DataPatchPacket_Callback applyFunction_Packet, 
		DataPatchApply_DataPatchPackets_Callback applyFunction_Packets, 
		bool applyOnInit);
public:
	c_data_patch_base(const c_data_patch_base&) = delete;
	c_data_patch_base& operator=(const c_data_patch_base&) = delete;

	c_data_patch_base(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPacket_Callback applyFunction_Packet, bool applyOnInit);
	c_data_patch_base(DataPatchSearchCallback searchFunction, DataPatchApply_DataPatchPackets_Callback applyFunction_Packets, bool applyOnInit);

	static void InitTree(Engine engine, Build build);
	static void DeinitTree(Engine engine, Build build);
	static void DestroyTree();

	bool ApplyPatch();
	bool RevertPatch();
	bool IsPatched() const { return m_isPatched; };
private:
	void init();
	c_data_patch_base* initNode(Engine engine, Build build);
	c_data_patch_base* deinitNode(Engine engine, Build build);

	c_data_patch_base* m_pNextDataPatch;
	Engine m_engine;
	Build m_build;
	uintptr_t m_offset;
	bool m_applyOnInit;
	bool m_isPatched;
	DataPatchSearchCallback* m_pSearchFunction;
	DataPatchPackets m_packets;
	PublicSymbol* m_pPublicSymbol;
	DataPatchApply_DataPatchPacket_Callback m_pApplyFunction_Packet;
	DataPatchApply_DataPatchPackets_Callback m_pApplyFunction_Packets;
	
	static c_data_patch_base* s_pFirstDataPatch;
	static c_data_patch_base* s_pLastDataPatch;
};

template<DataPatchSearchCallback searchFunction>
class DataPatch : c_data_patch_base
{
public:
	DataPatch(DataPatchApply_DataPatchPacket_Callback applyFunction_Packet)
		: c_data_patch_base(searchFunction, applyFunction_Packet, true)
	{

	}

	DataPatch(DataPatchApply_DataPatchPackets_Callback applyFunction_Packets)
		: c_data_patch_base(searchFunction, applyFunction_Packets, true)
	{

	}

	DataPatch(bool applyOnInit, DataPatchApply_DataPatchPacket_Callback applyFunction_Packet)
		: c_data_patch_base(searchFunction, applyFunction_Packet, applyOnInit)
	{

	}

	DataPatch(bool applyOnInit, DataPatchApply_DataPatchPackets_Callback applyFunction_Packets)
		: c_data_patch_base(searchFunction, applyFunction_Packets, applyOnInit)
	{

	}
};

