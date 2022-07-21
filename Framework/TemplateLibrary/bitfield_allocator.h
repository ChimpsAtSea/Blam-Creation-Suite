#pragma once

class c_bitfield_allocator
{
protected:
	typedef int64_t t_container_bitfield;
	static constexpr size_t k_bitfield_bits = sizeof(t_container_bitfield) * 8;

public:
	BCS_DEBUG_API c_bitfield_allocator(uint32_t count);
	BCS_DEBUG_API ~c_bitfield_allocator();

	BCS_DEBUG_API uint32_t allocate(uint32_t count);
	BCS_DEBUG_API void deallocate(uint32_t index, uint32_t count);
	BCS_DEBUG_API uint32_t allocate();
	BCS_DEBUG_API void deallocate(uint32_t index);

	BCS_DEBUG_API uint32_t allocate_unsafe(uint32_t count);
	BCS_DEBUG_API void deallocate_unsafe(uint32_t index, uint32_t count);
	BCS_DEBUG_API uint32_t allocate_unsafe();
	BCS_DEBUG_API void deallocate_unsafe(uint32_t index);

protected:
	volatile int32_t allocated_count;
	uint32_t const bitfield_count;
	uint32_t const max_count;
	t_container_bitfield* const bitfields;
};
