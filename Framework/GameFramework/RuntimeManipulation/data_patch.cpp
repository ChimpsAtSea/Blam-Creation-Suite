#include "gameframework-private-pch.h"


c_data_patch_base* c_data_patch_base::s_first_data_patch = nullptr;
c_data_patch_base* c_data_patch_base::s_last_data_patch = nullptr;

c_data_patch_base::c_data_patch_base(
	t_search search_function,
	t_search_multi search_function_multi_entry,
	t_apply_packet apply_packet,
	t_apply_packets apply_packets,
	t_apply_packets_multi_entry apply_packets_multi_entry,
	bool apply_on_init) :
	next_data_patch(nullptr),
	engine_type(_engine_type_not_set),
	build(_build_not_set),
	offsets(),
	is_enabled(true),
	apply_on_init(apply_on_init),
	search_function(search_function),
	search_function_multi_entry(search_function_multi_entry),
	apply_packet(apply_packet),
	apply_packets(apply_packets),
	apply_packets_multi_entry(apply_packets_multi_entry),
	public_symbol(nullptr)
{
	bool has_valid_search = false;
	has_valid_search = has_valid_search || search_function;
	has_valid_search = has_valid_search || search_function_multi_entry;
	ASSERT(has_valid_search);

	bool has_valid_callback = false;
	has_valid_callback = has_valid_callback || apply_packet;
	has_valid_callback = has_valid_callback || apply_packets;
	has_valid_callback = has_valid_callback || apply_packets_multi_entry;
	ASSERT(has_valid_callback);

	init();
}

c_data_patch_base::c_data_patch_base(t_search search_function, t_apply_packet apply_packet, bool apply_on_init)
	: c_data_patch_base(search_function, nullptr, apply_packet, nullptr, nullptr, apply_on_init)
{
}

c_data_patch_base::c_data_patch_base(t_search search_function, t_apply_packets apply_packets, bool apply_on_init)
	: c_data_patch_base(search_function, nullptr, nullptr, apply_packets, nullptr, apply_on_init)
{
}

c_data_patch_base::c_data_patch_base(t_search_multi search_function_multi_entry, t_apply_packets_multi_entry apply_packets_multi_entry, bool apply_on_init)
	: c_data_patch_base(nullptr, search_function_multi_entry, nullptr, nullptr, apply_packets_multi_entry, apply_on_init)
{
}

void c_data_patch_base::init()
{
	if (s_last_data_patch)
	{
		s_last_data_patch->next_data_patch = this;
		s_last_data_patch = this;
	}
	else
	{
		s_first_data_patch = this;
		s_last_data_patch = this;
	}
}

void c_data_patch_base::init_data_patch_tree(e_engine_type engine_type, e_build build)
{
	c_data_patch_base* current_data_patch = s_first_data_patch;
	while (current_data_patch)
	{
		current_data_patch = current_data_patch->init_node(engine_type, build);
	}
}

void c_data_patch_base::deinit_data_patch_tree(e_engine_type engine_type, e_build build)
{
	c_data_patch_base* current_data_patch = s_first_data_patch;
	while (current_data_patch)
	{
		current_data_patch = current_data_patch->deinit_node(engine_type, build);
	}
}

void c_data_patch_base::destroy_tree()
{
	c_data_patch_base* current_data_patch = s_first_data_patch;
	while (current_data_patch)
	{
		c_data_patch_base* pNextc_data_patch_base = current_data_patch->next_data_patch;

		delete current_data_patch;

		current_data_patch = pNextc_data_patch_base;
	}
}

bool c_data_patch_base::ApplyPatch()
{
	if (offsets.empty() || !is_enabled)
	{
		return false;
	}

	char** data_addresses = reinterpret_cast<char**>(alloca(sizeof(char*) * offsets.size()));
	for (size_t i = 0; i < offsets.size(); i++)
	{
		uintptr_t const game_virtual_address = get_engine_base_address(engine_type);
		uintptr_t const data_virtual_address = static_cast<uintptr_t>(offsets[i]);
		uintptr_t const data_relative_address = data_virtual_address - game_virtual_address;
		char* const game_base_address = reinterpret_cast<char*>(get_engine_memory_address(engine_type));
		char* const data_address = game_base_address + data_relative_address;

		data_addresses[i] = data_address;
	}

	if (public_symbol)
	{
		c_console::write_line_verbose("Applying DataPatch: %s", public_symbol->symbol_name);
	}
	else
	{
		c_console::write_line_verbose("Applying DataPatch: <unknown>");
	}

	if (apply_packet)
	{
		packets.resize(1);
		packets[0] = DataPatchPacket();
		apply_packet(engine_type, build, data_addresses[0], packets[0]);

		ASSERT(packets[0].first != nullptr);
	}
	else if (apply_packets)
	{
		apply_packets(engine_type, build, data_addresses[0], packets);

		ASSERT(!packets.empty());
		for (DataPatchPacket& packet : packets)
		{
			ASSERT(packet.first != nullptr);
			ASSERT(!packet.second.empty());
		}
	}
	else if (apply_packets_multi_entry)
	{
		apply_packets_multi_entry(engine_type, build, data_addresses, packets);

		ASSERT(!packets.empty());
		for (DataPatchPacket& packet : packets)
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
	if (!is_patched)
	{
		return false;
	}

	if (public_symbol)
	{
		c_console::write_line_verbose("Reverting DataPatch: %s", public_symbol->symbol_name);
	}
	else
	{
		c_console::write_line_verbose("Reverting DataPatch: <unknown>");
	}

	for (DataPatchPacket& packet : packets)
	{
		// revert the patch
		memcpy(packet.first, packet.second.data(), packet.second.size());
	}

	return true;
}

c_data_patch_base* c_data_patch_base::init_node(e_engine_type engine_type, e_build build)
{
	ASSERT(offsets.empty(), "DataPatch is already patched! This node should be reset before patching again");

	if (public_symbol == nullptr)
	{
		public_symbol = c_runtime_symbols::runtime().get_public_symbol_by_virtual_address(this);
	}

	if (search_function)
	{
		uintptr_t target_offset = search_function(engine_type, build);
		if (target_offset != ~uintptr_t())
		{
			offsets.push_back(target_offset);
			this->engine_type = engine_type;
			this->build = build;

			if (apply_on_init)
			{
				ApplyPatch();
			}
		}
	}
	else if (search_function_multi_entry)
	{
		std::vector<uintptr_t> target_offsets = search_function_multi_entry(engine_type, build);
		if (!target_offsets.empty())
		{
			offsets = target_offsets;
			this->engine_type = engine_type;
			this->build = build;

			if (apply_on_init)
			{
				ApplyPatch();
			}
		}
	}
	else FATAL_ERROR(L"No search function provided");

	return next_data_patch;
}

c_data_patch_base* c_data_patch_base::deinit_node(e_engine_type engine_type, e_build build)
{
	offsets.clear();
	this->engine_type = _engine_type_not_set;
	this->build = _build_not_set;

	RevertPatch();

	return next_data_patch;
}
