#include "templatelibrary-private-pch.h"

c_bitfield_allocator::c_bitfield_allocator(unsigned long count) :
	allocated_count(0),
	bitfield_count((count + k_bitfield_bits - 1) / k_bitfield_bits),
	max_count(count),
	bitfields(new t_container_bitfield[bitfield_count])
{
	memset(bitfields, 0xFF, sizeof(bitfields[0]) * bitfield_count);
	unsigned long bit_count = bitfield_count * k_bitfield_bits;

	// #TODO: probbably a more efficient way to do this step
	for (unsigned long index = max_count; index < bit_count; index++)
	{
		unsigned long array_index = index / k_bitfield_bits;
		unsigned long bitfield_offset = index % k_bitfield_bits;

		// flip these bits to 0 so we ignore them as if they were already allocated
		unsigned char bit_value = _bittestandreset64(bitfields + array_index, static_cast<long long>(bitfield_offset));
		ASSERT(bit_value == 1);
	}
}

c_bitfield_allocator::~c_bitfield_allocator()
{
	delete bitfields;
}

unsigned long c_bitfield_allocator::allocate(unsigned long count)
{
	// #TODO: is there a more efficient way to do this?

	t_container_bitfield mask = (1ull << static_cast<t_container_bitfield>(count)) - 1ull;
	ASSERT(count < k_bitfield_bits);
	if (allocated_count + count > max_count) return -1;
	for (unsigned long bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		t_container_bitfield const bitfield_read = bitfields[bitfield_index]; // read once
		t_container_bitfield free_bits = __popcnt64(bitfield_read);
		if (free_bits >= count)
		{
			unsigned long bitfield_start_offset;
			if (_BitScanForward64(&bitfield_start_offset, static_cast<unsigned long long>(bitfields[bitfield_index]))) // skip as many bits as possible
			{
				for (unsigned long bitfield_offset = bitfield_start_offset; bitfield_offset < (k_bitfield_bits - count); bitfield_offset++)
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
							unsigned long index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
							_interlockedadd(reinterpret_cast<volatile long*>(&allocated_count), static_cast<long>(count));
							return index;
						}
					}
				}
			}
		}
	}
	return -1;
}

void c_bitfield_allocator::deallocate(unsigned long index, unsigned long count)
{
	// #TODO: write an efficient algorithm for this
	for (unsigned long current_index = index; current_index < index; current_index++)
	{
		deallocate(current_index);
	}
}

unsigned long c_bitfield_allocator::allocate()
{
	for (unsigned long bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		unsigned long bitfield_offset;
		while (_BitScanForward64(&bitfield_offset, static_cast<unsigned long long>(bitfields[bitfield_index]))) // keep attempting to set a bit
		{
			unsigned char bit_value = _bittestandreset64(bitfields + bitfield_index, bitfield_offset);
			if (bit_value)
			{
				_InterlockedIncrement(&allocated_count);
				unsigned long index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
				return index;
			}
		}
	}
	return NULL;
}

void c_bitfield_allocator::deallocate(unsigned long index)
{
	unsigned long array_index = index / k_bitfield_bits;
	unsigned long bitfield_offset = index % k_bitfield_bits;

	unsigned char bit_value = _bittestandset64(bitfields + array_index, bitfield_offset);
	ASSERT(bit_value == 0);

	_InterlockedDecrement(&allocated_count);
}

unsigned long c_bitfield_allocator::allocate_unsafe(unsigned long count)
{
	// #TODO: is there a more efficient way to do this?

	t_container_bitfield mask = (1ull << static_cast<t_container_bitfield>(count)) - 1ull;
	ASSERT(count < k_bitfield_bits);
	if (allocated_count + count > max_count) return -1;
	for (unsigned long bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		t_container_bitfield& bitfield_read = bitfields[bitfield_index]; // read once
		t_container_bitfield free_bits = __popcnt64(bitfield_read);
		if (free_bits >= count)
		{
			unsigned long bitfield_start_offset;
			if (_BitScanForward64(&bitfield_start_offset, static_cast<unsigned long long>(bitfield_read))) // skip as many bits as possible
			{
				for (unsigned long bitfield_offset = bitfield_start_offset; bitfield_offset < (k_bitfield_bits - count); bitfield_offset++)
				{
					t_container_bitfield bitfield_mask = mask << bitfield_offset;
					t_container_bitfield bitfield_bits_masked = bitfield_read & bitfield_mask;

					if (bitfield_bits_masked == bitfield_mask)
					{
						bitfield_read &= ~bitfield_mask;

						unsigned long index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
						_interlockedadd(reinterpret_cast<volatile long*>(&allocated_count), static_cast<long>(count));
						return index;
					}
				}
			}
		}
	}
	return -1;
}

void c_bitfield_allocator::deallocate_unsafe(unsigned long index, unsigned long count)
{
	// #TODO: write an efficient algorithm for this
	for (unsigned long current_index = index; current_index < index; current_index++)
	{
		deallocate(current_index);
	}
}

unsigned long c_bitfield_allocator::allocate_unsafe()
{
	for (unsigned long bitfield_index = 0; bitfield_index < bitfield_count; bitfield_index++)
	{
		unsigned long bitfield_offset;
		while (_BitScanForward64(&bitfield_offset, static_cast<unsigned long long>(bitfields[bitfield_index]))) // keep attempting to set a bit
		{
			unsigned char bit_value = _bittestandreset64(bitfields + bitfield_index, bitfield_offset);
			if (bit_value)
			{
				allocated_count++;
				unsigned long index = (bitfield_index * k_bitfield_bits) + bitfield_offset;
				return index;
			}
		}
	}
	return NULL;
}

void c_bitfield_allocator::deallocate_unsafe(unsigned long index)
{
	unsigned long array_index = index / k_bitfield_bits;
	unsigned long bitfield_offset = index % k_bitfield_bits;

	unsigned char bit_value = _bittestandset64(bitfields + array_index, bitfield_offset);
	ASSERT(bit_value == 0);

	allocated_count--;
}
