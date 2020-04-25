#pragma once

#define COPY_TO_VECTOR(pointer, count) std::vector<decltype(*pointer)>(pointer, pointer + count)
#define MAKE_DATAPATCHPACKET(pointer, count) {reinterpret_cast<char*>(pointer), {reinterpret_cast<char*>(pointer), reinterpret_cast<char*>(pointer) + count}}

typedef std::pair<char*, std::vector<char>> DataPatchPacket;
typedef std::vector<DataPatchPacket> DataPatchPackets;

typedef uintptr_t(t_search)(e_engine_type, e_build);
typedef std::vector<uintptr_t>(t_search_multi)(e_engine_type, e_build);


typedef void (t_apply_packet_func)(e_engine_type, e_build, char*, DataPatchPacket&);
typedef void (t_apply_packets_func)(e_engine_type, e_build, char*, DataPatchPackets&);
typedef void (t_apply_packets_multi_entry_func)(e_engine_type, e_build, char*[], DataPatchPackets&);

// #TODO: Figure out warning 4927
using t_apply_packet = std::function<t_apply_packet_func>;
using t_apply_packets = std::function<t_apply_packets_func>;
using t_apply_packets_multi_entry = std::function<t_apply_packets_multi_entry_func>;

class c_data_patch_base
{
private:
	c_data_patch_base(
		t_search search_function,
		t_search_multi search_function_multi_entry,
		t_apply_packet apply_packet,
		t_apply_packets apply_packets,
		t_apply_packets_multi_entry apply_packets_multi_entry,
		bool apply_on_init);
public:
	c_data_patch_base(const c_data_patch_base&) = delete;
	c_data_patch_base& operator=(const c_data_patch_base&) = delete;

	c_data_patch_base(t_search search_function, t_apply_packet apply_packet, bool apply_on_init);
	c_data_patch_base(t_search search_function, t_apply_packets apply_packets, bool apply_on_init);
	c_data_patch_base(t_search_multi search_function_multi_entry, t_apply_packets_multi_entry apply_packets_multi_entry, bool apply_on_init);

	static void init_data_patch_tree(e_engine_type engine_type, e_build build);
	static void deinit_data_patch_tree(e_engine_type engine_type, e_build build);
	static void destroy_tree();

	void set_enabled(bool is_enabled) { this->is_enabled = is_enabled; }
	bool ApplyPatch();
	bool RevertPatch();
	bool IsPatched() const { return is_patched; };
private:
	void init();
	c_data_patch_base* init_node(e_engine_type engine_type, e_build build);
	c_data_patch_base* deinit_node(e_engine_type engine_type, e_build build);

	c_data_patch_base* next_data_patch;
	e_engine_type engine_type;
	e_build build;
	std::vector<uintptr_t> offsets;
	bool is_enabled;
	bool apply_on_init;
	bool is_patched;
	t_search* search_function;
	t_search_multi* search_function_multi_entry;
	DataPatchPackets m_packets;
	PublicSymbol* public_symbol;
	t_apply_packet apply_packet;
	t_apply_packets apply_packets;
	t_apply_packets_multi_entry apply_packets_multi_entry;
	
	static c_data_patch_base* s_first_data_patch;
	static c_data_patch_base* s_last_data_patch;
};

template<t_search _search_function>
class c_data_patch : 
	public c_data_patch_base
{
public:
	c_data_patch(t_apply_packet apply_packet)
		: c_data_patch_base(_search_function, apply_packet, true)
	{

	}

	c_data_patch(t_apply_packets apply_packets)
		: c_data_patch_base(_search_function, apply_packets, true)
	{

	}

	c_data_patch(bool apply_on_init, t_apply_packet apply_packet)
		: c_data_patch_base(_search_function, apply_packet, apply_on_init)
	{

	}

	c_data_patch(bool apply_on_init, t_apply_packets apply_packets)
		: c_data_patch_base(_search_function, apply_packets, apply_on_init)
	{

	}
};

template<t_search_multi _search_function_multi_entry>
class c_multi_data_patch : 
	public c_data_patch_base
{
public:

	c_multi_data_patch(t_apply_packets_multi_entry apply_packets_multi_entry)
		: c_data_patch_base(_search_function_multi_entry, apply_packets_multi_entry, true)
	{

	}

	c_multi_data_patch(bool apply_on_init, t_apply_packets_multi_entry apply_packets_multi_entry)
		: c_data_patch_base(_search_function_multi_entry, apply_packets_multi_entry, apply_on_init)
	{

	}
};

