#include "templatelibrary-private-pch.h"

c_bitfield_allocator::c_bitfield_allocator(uint32_t count) :
	allocated_count(0),
	bitfield_count((count + k_bitfield_bits - 1) / k_bitfield_bits),
	max_count(count),
	bitfields(new t_container_bitfield[bitfield_count])
{
	memset(bitfields, 0xFF, sizeof(bitfields[0]) * bitfield_count);
	uint32_t bit_count = bitfield_count * k_bitfield_bits;

	// #TODO: probbably a more efficient way to do this step
	for (uint32_t index = max_count; index < bit_count; index++)
	{
		uint32_t array_index = index / k_bitfield_bits;
		uint32_t bitfield_offset = index % k_bitfield_bits;

		// flip these bits to 0 so we ignore them as if they were already allocated
		unsigned char bit_value = _bittestandreset64(bitfields + array_index, static_cast<int64_t>(bitfield_offset));
		ASSERT(bit_value == 1);
	}
}

c_bitfield_allocator::~c_bitfield_allocator()
{
	delete[] bitfields;
}

uint32_t c_bitfield_allocator::allocate(uint32_t count)
{
	// #TODO: is there a more efficient way to do this?

	t_container_bitfield mask = (1ull << static_cast<t_container_bitfield>(count)) - 1ull;
	ASSERT(count < k_bitfield_bits);
	if (allocated_count + count > max_count) return -1;
	for (uint32_t bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		t_container_bitfield const bitfield_read = bitfields[bitfield_index]; // read once
		t_container_bitfield free_bits = __popcnt64(bitfield_read);
		if (free_bits >= count)
		{
			uint32_t bitfield_start_offset;
			if (bit_scan_forwardu64(&bitfield_start_offset, static_cast<uint64_t>(bitfields[bitfield_index]))) // skip as many bits as possible
			{
				for (uint32_t bitfield_offset = bitfield_start_offset; bitfield_offset < (k_bitfield_bits - count); bitfield_offset++)
				{
					t_container_bitfield bitfield_mask = mask << bitfield_offset;
					t_container_bitfield bitfield_bits_masked = bitfield_read & bitfield_mask;

					if (bitfield_bits_masked == bitfield_mask)
					{
						t_container_bitfield old_bitfield = bitfield_read;
						t_container_bitfield new_bitfield = old_bitfield & ~bitfield_mask;

						t_container_bitfield compare_exchange_result = _InterlockedCompareExchange64(bitfields + bitfield_index, new_bitfield, old_bitfield);
						if (compare_exchange_result == old_bitfield)
						{
							uint32_t index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
							atomic_addu32(&allocated_count, count);
							return index;
						}
					}
				}
			}
		}
	}
	return -1;
}

void c_bitfield_allocator::deallocate(uint32_t index, uint32_t count)
{
	// #TODO: write an efficient algorithm for this
	for (uint32_t current_index = index; current_index < index; current_index++)
	{
		deallocate(current_index);
	}
}

uint32_t c_bitfield_allocator::allocate()
{
	for (uint32_t bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		uint32_t bitfield_offset;
		while (bit_scan_forwardu64(&bitfield_offset, static_cast<uint64_t>(bitfields[bitfield_index]))) // keep attempting to set a bit
		{
			unsigned char bit_value = _bittestandreset64(bitfields + bitfield_index, bitfield_offset);
			if (bit_value)
			{
				atomic_incu32(&allocated_count);
				uint32_t index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
				return index;
			}
		}
	}
	return ULONG_MAX;
}

void c_bitfield_allocator::deallocate(uint32_t index)
{
	uint32_t array_index = index / k_bitfield_bits;
	uint32_t bitfield_offset = index % k_bitfield_bits;

	unsigned char bit_value = _bittestandset64(bitfields + array_index, bitfield_offset);
	ASSERT(bit_value == 0);

	atomic_decu32(&allocated_count);
}

uint32_t c_bitfield_allocator::allocate_unsafe(uint32_t count)
{
	// #TODO: is there a more efficient way to do this?

	t_container_bitfield mask = (1ull << static_cast<t_container_bitfield>(count)) - 1ull;
	ASSERT(count < k_bitfield_bits);
	if (allocated_count + count > max_count) return -1;
	for (uint32_t bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		t_container_bitfield& bitfield_read = bitfields[bitfield_index]; // read once
		t_container_bitfield free_bits = __popcnt64(bitfield_read);
		if (free_bits >= count)
		{
			uint32_t bitfield_start_offset;
			if (bit_scan_forwardu64(&bitfield_start_offset, static_cast<uint64_t>(bitfield_read))) // skip as many bits as possible
			{
				for (uint32_t bitfield_offset = bitfield_start_offset; bitfield_offset < (k_bitfield_bits - count); bitfield_offset++)
				{
					t_container_bitfield bitfield_mask = mask << bitfield_offset;
					t_container_bitfield bitfield_bits_masked = bitfield_read & bitfield_mask;

					if (bitfield_bits_masked == bitfield_mask)
					{
						bitfield_read &= ~bitfield_mask;

						uint32_t index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
						atomic_addu32(&allocated_count, count);
						return index;
					}
				}
			}
		}
	}
	return ULONG_MAX;
}

void c_bitfield_allocator::deallocate_unsafe(uint32_t index, uint32_t count)
{
	// #TODO: write an efficient algorithm for this
	for (uint32_t current_index = index; current_index < index; current_index++)
	{
		deallocate(current_index);
	}
}

uint32_t c_bitfield_allocator::allocate_unsafe()
{
	for (uint32_t bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		uint32_t bitfield_offset;
		while (bit_scan_forwardu64(&bitfield_offset, static_cast<uint64_t>(bitfields[bitfield_index]))) // keep attempting to set a bit
		{
			unsigned char bit_value = _bittestandreset64(bitfields + bitfield_index, bitfield_offset);
			if (bit_value)
			{
				atomic_incu32(&allocated_count);
				uint32_t index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
				return index;
			}
		}
	}
	return NULL;
}

void c_bitfield_allocator::deallocate_unsafe(uint32_t index)
{
	uint32_t array_index = index / k_bitfield_bits;
	uint32_t bitfield_offset = index % k_bitfield_bits;

	unsigned char bit_value = _bittestandset64(bitfields + array_index, bitfield_offset);
	ASSERT(bit_value == 0);

	atomic_decu32(&allocated_count);
}
