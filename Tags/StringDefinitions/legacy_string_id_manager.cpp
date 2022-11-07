#include "stringdefinitions-private-pch.h"

c_legacy_string_id_manager::c_legacy_string_id_manager(uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits) :
	c_string_id_manager(),
	index_bits(index_bits),
	index_mask(),
	namespace_bits(namespace_bits),
	namespace_mask(),
	namespace_shift(),
	length_bits(length_bits),
	length_mask(),
	length_shift(index_bits + namespace_bits),
	first_custom_index(),
	engine_set_counts(),
	string_ids(),
	string_id_table()
{
	for (uint32_t i = 0; i < index_bits; i++)
	{
		index_mask = (index_mask << 1) | 1;
	}

	for (uint32_t i = 0; i < namespace_bits; i++)
	{
		namespace_mask = (namespace_mask << 1) | 1;
	}

	for (uint32_t i = 0; i < length_bits; i++)
	{
		length_mask = (length_mask << 1) | 1;
	}
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string)
{
	uint32_t string_id;
	return commit_string(string, string_id);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string, uint32_t& string_id)
{
	return commit_string(0, string, string_id, true);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(uint32_t set, const char* string)
{
	uint32_t string_id;
	return commit_string(set, string, string_id, true);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(uint32_t set, const char* string, uint32_t& string_id, bool is_user)
{
	auto search = string_id_table.find(string);
	if (search != string_id_table.end())
	{
		string_id = search->second;
		return BCS_S_OK;
	}

	if (!is_user)
	{
		engine_set_counts[set]++;
	}

	uint32_t index = static_cast<unsigned long>(string_ids[set].size());
	uint32_t length = 0; // #TODO: can this be set?

	string_id = 0;
	string_id |= (index & index_mask);
	string_id |= (set & namespace_mask) << index_bits;
	string_id |= (length & length_mask) << length_shift;

	string_id_table[string] = string_id;
	string_ids[set].push_back(string);

	return BCS_S_OK;
}
