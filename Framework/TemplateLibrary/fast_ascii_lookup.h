#pragma once


template<typename t_value, size_t lookup_table_count, size_t value_table_count, t_value default_value = t_value()>
class c_fast_ascii_lookup
{
public:
	struct s_keyvalue
	{
		const char* key;
		t_value value;
	};

	union s_lookup_entry
	{
		unsigned short entry_indices[96];
		struct
		{
			unsigned short padding[_countof(entry_indices) - 1];
			unsigned short value_index;
		};
	};

	s_lookup_entry lookup_entries[lookup_table_count];
	t_value values[value_table_count];
	unsigned short next_value_index = 0;
	unsigned short next_entry_index = 1;

	c_fast_ascii_lookup() :
		lookup_entries(),
		values(),
		next_value_index(),
		next_entry_index()
	{
		for (s_lookup_entry& lookup_entry : values)
		{
			lookup_entry.value_index = USHRT_MAX;
		}
		for (t_value& value : values)
		{
			value = default_value;
		}
	}

	c_fast_ascii_lookup(std::initializer_list<std::pair<const char*, const t_value>> initializer_list)
	{
		for (auto& kv : initializer_list)
		{
			enqueue_string(kv.first, kv.second);
		}
	}

	void enqueue_string(const char* string, const t_value& value)
	{
		s_lookup_entry* current_entry = lookup_entries;
		for (const unsigned char* s = reinterpret_cast<const unsigned char*>(string); *s; s++)
		{
			unsigned char index = (*s & 0x7Fui8) - 32ui8;
			ASSERT(index < (_countof(s_lookup_entry::entry_indices) - 1));
			unsigned short& entry_index = current_entry->entry_indices[index];
			if (entry_index == 0)
			{
				entry_index = next_entry_index++;
				ASSERT(entry_index < lookup_table_count);
			}
			current_entry = lookup_entries + entry_index;
		}

		if (current_entry->value_index == USHRT_MAX)
		{
			unsigned short value_index = next_value_index++;
			ASSERT(value_index < value_table_count);
			current_entry->value_index = value_index;
			values[value_index] = value;
		}
	}

	bool get_value(const char* string, t_value& value)
	{
		unsigned short current_entry_index = 0;
		for (const unsigned char* s = reinterpret_cast<const unsigned char*>(string); *s; s++)
		{
			current_entry_index = lookup_entries[current_entry_index].entry_indices[(*s & 0x7Fui8) - 32ui8];
			if (current_entry_index == 0)
			{
				return false;
			}
		}
		unsigned short value_index = lookup_entries[current_entry_index].value_index;
		if (value_index != USHRT_MAX)
		{
			value = values[value_index];
			return true;
		};
		return false;
	}
};
