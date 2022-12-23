#include "stringdefinitions-private-pch.h"

c_legacy_string_id_manager::c_legacy_string_id_manager(uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits) :
	c_string_id_manager(),
	string_ids(),
	engine_namespace_counts(),
	global_namespace_counts(),
	total_engine_strings(),
	total_strings(),
	string_to_id(),
	id_to_string(),
	index_bits(index_bits),
	index_mask(),
	namespace_bits(namespace_bits),
	namespace_mask(),
	namespace_shift(),
	length_bits(length_bits),
	length_mask(),
	length_shift(index_bits + namespace_bits),
	first_custom_index()
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

BCS_RESULT c_legacy_string_id_manager::init_from_engine_platform_build(s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;

	s_constant_string_id_table* constant_string_id_table;
	if (BCS_FAILED(rs = get_constant_string_id_table_by_engine_platform_build(engine_platform_build, constant_string_id_table)))
	{
		return rs;
	}

	commit_string(0, "", false); // empty string always first

	// defined in engine
	for (unsigned int namespace_order_index = 0; namespace_order_index < constant_string_id_table->num_namespaces; namespace_order_index++)
	{
		unsigned int string_namespace_index = constant_string_id_table->serialization_namespace_order[namespace_order_index];
		s_constant_string_id_namespace& constant_string_id_namespace = *constant_string_id_table->namespaces[string_namespace_index];

		for (unsigned int namespace_string_index = 0; namespace_string_index < constant_string_id_namespace.string_count; namespace_string_index++)
		{
			const char* string = constant_string_id_namespace.constant_string_ids[namespace_string_index];

			commit_string(string_namespace_index, string, false);
		}
	}

	return rs;
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string)
{
	return commit_string(string, true);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string, bool defined_in_tags)
{
	uint32_t string_id;
	return commit_string(string, string_id, defined_in_tags);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string, uint32_t& string_id)
{
	return commit_string(string, string_id, true);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(const char* string, uint32_t& string_id, bool defined_in_tags)
{
	return commit_string(0, string, string_id, defined_in_tags);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(uint32_t set, const char* string, bool defined_in_tags)
{
	uint32_t string_id;
	return commit_string(set, string, string_id, defined_in_tags);
}

BCS_RESULT c_legacy_string_id_manager::commit_string(uint32_t _namespace, const char* source_string, uint32_t& string_id, bool defined_in_tags)
{
	const char* string = source_string;
	if (string)
	{
		t_string_to_id_map::const_iterator search = string_to_id.find(string);
		if (search != string_to_id.end())
		{
			string_id = search->second;
			return BCS_S_OK;
		}
	}
	else
	{
		string = "";
	}

	uint32_t index = static_cast<unsigned long>(engine_namespace_counts[_namespace]);
	uint32_t length = 0; // #TODO: can this be set?

	if (!defined_in_tags)
	{
		string_id = 0;
		string_id |= (index & index_mask);
		string_id |= (_namespace & namespace_mask) << index_bits;
		string_id |= (length & length_mask) << length_shift;

		engine_namespace_counts[_namespace]++;
		total_engine_strings++;
	}
	else
	{
		string_id = total_strings;
	}

	global_namespace_counts[_namespace]++;
	total_strings++;


	if (source_string)
	{
		string_to_id[source_string] = string_id;
		id_to_string[string_id] = source_string;
	}
	string_ids[_namespace].push_back(string);

	return BCS_S_OK;
}

BCS_RESULT c_legacy_string_id_manager::fetch_string_id(const char* string, uint32_t& string_id) const
{
	if (string)
	{
		if (strcmp("<invalid string id>", string) == 0)
		{
			string_id = UINT_MAX;
			return BCS_S_OK;
		}
		else
		{
			t_string_to_id_map::const_iterator search = string_to_id.find(string);
			if (search != string_to_id.end())
			{
				string_id = search->second;
				return BCS_S_OK;
			}
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_legacy_string_id_manager::fetch_string(uint32_t string_id, const char*& string) const
{
	if (string_id == UINT_MAX)
	{
		string = "<invalid string id>";
		return BCS_S_OK;
	}
	t_id_to_string_map::const_iterator search = id_to_string.find(string_id);
	if (search != id_to_string.end())
	{
		string = search->second.c_str();
		return BCS_S_OK;
	}

	//uint32_t index = string_id & index_mask;
	//uint32_t _namespace = (string_id >> index_bits) & namespace_mask;
	//uint32_t length = (string_id >> length_shift) & length_mask;

	//if (_namespace < _countof(string_ids))
	//{
	//	t_string_vector const& vector = string_ids[_namespace];
	//	if (index < vector.size())
	//	{
	//		std::string const& string_id_string = vector[index];

	//		if (string_id_string.empty() && string_id > 0)
	//		{
	//			string = nullptr;
	//		}
	//		else
	//		{
	//			string = string_id_string.c_str();
	//		}

	//		return BCS_S_OK;
	//	}
	//}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_legacy_string_id_manager::calculate_string_id(uint32_t _namespace, uint32_t index, uint32_t length, uint32_t& string_id) const
{
	if (_namespace & ~namespace_mask)
	{
		return BCS_E_OUT_OF_RANGE;
	}
	if (index & ~index_mask)
	{
		return BCS_E_OUT_OF_RANGE;
	}
	if (length & ~length_mask)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	string_id = 0;
	string_id |= (index & index_mask);
	string_id |= (_namespace & namespace_mask) << index_bits;
	string_id |= (length & length_mask) << length_shift;

	return BCS_S_OK;
}

BCS_RESULT c_legacy_string_id_manager::deconstruct_string_id(uint32_t string_id, uint32_t& _namespace, uint32_t& index, uint32_t& length) const
{
	index = string_id & index_mask;
	_namespace = (string_id >> index_bits) & namespace_mask;
	length = (string_id >> length_shift) & length_mask;

	return BCS_S_OK;
}

BCS_RESULT c_legacy_string_id_manager::clear()
{
	for (t_string_vector& namespace_string_ids : string_ids)
	{
		namespace_string_ids.clear();
	}
	for (uint32_t& engine_namespace_count : engine_namespace_counts)
	{
		engine_namespace_count = 0;
	}
	total_engine_strings = 0;
	string_to_id.clear();
	id_to_string.clear();

	return BCS_S_OK;
}

uint32_t c_legacy_string_id_manager::get_total_engine_strings() const
{
	return total_engine_strings;
}
