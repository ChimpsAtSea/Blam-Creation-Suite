#pragma once

template<typename t_value, size_t lookup_table_count, size_t value_table_count, bool check_collisions = true>
class c_fast_byte_lookup
{
public:
	struct s_keyvalue
	{
		const char* key;
		t_value value;
	};

	union s_lookup_entry
	{
		unsigned short entry_indices[256];
		unsigned short value_index;
	};

	s_lookup_entry lookup_entries[lookup_table_count];
	t_value values[value_table_count];
	unsigned short next_value_index;
	unsigned short next_entry_index;

	c_fast_byte_lookup()
	{
		next_value_index = 0;
		next_entry_index = 1;
		lookup_entries[0] = {};
	}

#if defined(_INITIALIZER_LIST_) && defined(_UTILITY_)
	c_fast_byte_lookup(std::initializer_list<std::pair<const char*, const t_value>> initializer_list)
	{
		for (auto& kv : initializer_list)
		{
			enqueue_string_hash(kv.first, kv.second);
		}
	}
#endif

	void enqueue(const void* data, size_t data_size, const t_value& value)
	{
		s_lookup_entry* current_entry = lookup_entries;
		//const unsigned char* data_start = = static_cast<const char*>(data);
		//const unsigned char* data_end = data_start + data_size;
		const unsigned char* data_end = static_cast<const unsigned char*>(data) + data_size;
		for (const unsigned char* data_pos = static_cast<const unsigned char*>(data); data_pos < data_end; data_pos++)
		{
			unsigned short& entry_index = current_entry->entry_indices[*data_pos];
			if (entry_index == 0)
			{
				entry_index = next_entry_index++;
				ASSERT(entry_index < lookup_table_count);
				current_entry = lookup_entries + entry_index;
				*current_entry = {};
			}
			else
			{
				current_entry = lookup_entries + entry_index;
			}
		}

		if constexpr (check_collisions)
		{
			ASSERT(current_entry->value_index == 0);
		}
		if (current_entry->value_index == 0)
		{
			unsigned short value_index = next_value_index++;
			ASSERT(value_index < value_table_count);
			current_entry->value_index = value_index + 1;
			values[value_index] = value;
		}

		debug_point;
	}

	bool fetch(const void* data, size_t data_size, t_value& value) const
	{
		unsigned short current_entry_index = 0;
		//const unsigned char* data_start = = static_cast<const char*>(data);
		//const unsigned char* data_end = data_start + data_size;
		const unsigned char* data_end = static_cast<const unsigned char*>(data) + data_size;
		for (const unsigned char* data_pos = static_cast<const unsigned char*>(data); data_pos < data_end; data_pos++)
		{
			current_entry_index = lookup_entries[current_entry_index].entry_indices[*data_pos];
			if (current_entry_index == 0)
			{
				return false;
			}
		}

		unsigned short value_index = lookup_entries[current_entry_index].value_index;
		if (value_index != 0)
		{
			value = values[value_index - 1];
			return true;
		};
		return false;
	}

	bool fetch_ref(const void* data, size_t data_size, const t_value*& value) const
	{
		unsigned short current_entry_index = 0;
		//const unsigned char* data_start = = static_cast<const char*>(data);
		//const unsigned char* data_end = data_start + data_size;
		const unsigned char* data_end = static_cast<const unsigned char*>(data) + data_size;
		for (const unsigned char* data_pos = static_cast<const unsigned char*>(data); data_pos < data_end; data_pos++)
		{
			current_entry_index = lookup_entries[current_entry_index].entry_indices[*data_pos];
			if (current_entry_index == 0)
			{
				return false;
			}
		}

		unsigned short value_index = lookup_entries[current_entry_index].value_index;
		if (value_index != 0)
		{
			value = &values[value_index - 1];
			return true;
		};
		return false;
	}
};
