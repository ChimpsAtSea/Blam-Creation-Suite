#pragma once

template<typename t_type, uint32_t preallocated_size, uint32_t chunk_size, uint32_t chunk_count>
class c_hybrid_chunked_resizable_array
{
public:
	static constexpr uint32_t max_size = preallocated_size + chunk_size * chunk_count;
	static_assert(__is_trivially_destructible(t_type));

	uint32_t size;
	t_type* dynamic_entries[chunk_count];
	t_type fixed_entries[preallocated_size];

	c_hybrid_chunked_resizable_array() :
		size(0),
		dynamic_entries{}
	{

	}

	~c_hybrid_chunked_resizable_array()
	{
		for (t_type* entry_list : dynamic_entries)
		{
			if (entry_list)
			{
				trivial_free(entry_list);
			}
			else
			{
				break;
			}
		}
	}

	t_type& operator[](uint32_t index)
	{
		ASSERT(index < size);
		if (index < preallocated_size)
		{
			return fixed_entries[index];
		}
		else
		{
			index -= preallocated_size;
			uint32_t chunk = index / chunk_size;
			uint32_t chunk_index = index % chunk_size;
			return dynamic_entries[chunk][chunk_index];
		}
	}

	t_type const& operator[](uint32_t index) const
	{
		ASSERT(index < size);
		if (index < preallocated_size)
		{
			return fixed_entries[index];
		}
		else
		{
			index -= preallocated_size;
			uint32_t chunk = index / chunk_size;
			uint32_t chunk_index = index % chunk_size;
			return dynamic_entries[chunk][chunk_index];
		}
	}

	t_type& emplace_back()
	{
		uint32_t index = size++;
		ASSERT(index < max_size);

		if (index < preallocated_size)
		{
			return fixed_entries[index];
		}
		else
		{
			index -= preallocated_size;
			uint32_t dynamic_entry_index = index / chunk_size;
			uint32_t sub_entry_index = index % chunk_size;

			t_type*& entries = dynamic_entries[dynamic_entry_index];
			if (entries == nullptr)
			{
				entries = trivial_malloc(t_type, chunk_size);
			}
			return entries[sub_entry_index];
		}
	}
};

