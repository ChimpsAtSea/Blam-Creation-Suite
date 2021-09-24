#pragma once

class c_bitfield_allocator
{
protected:
	typedef long long t_container_bitfield;
	static constexpr size_t k_bitfield_bits = sizeof(t_container_bitfield) * 8;

public:
	BCS_DEBUG_API c_bitfield_allocator(unsigned long count);
	BCS_DEBUG_API ~c_bitfield_allocator();

	BCS_DEBUG_API unsigned long allocate(unsigned long count);
	BCS_DEBUG_API void deallocate(unsigned long index, unsigned long count);
	BCS_DEBUG_API unsigned long allocate();
	BCS_DEBUG_API void deallocate(unsigned long index);

	BCS_DEBUG_API unsigned long allocate_unsafe(unsigned long count);
	BCS_DEBUG_API void deallocate_unsafe(unsigned long index, unsigned long count);
	BCS_DEBUG_API unsigned long allocate_unsafe();
	BCS_DEBUG_API void deallocate_unsafe(unsigned long index);

protected:
	volatile long allocated_count;
	unsigned long const bitfield_count;
	unsigned long const max_count;
	t_container_bitfield* const bitfields;
};
