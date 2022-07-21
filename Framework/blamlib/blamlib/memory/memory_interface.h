#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/memory/ptr32.h>

/* ---------- inline code */

template <typename t_type>
inline qword address_from_pointer(
	t_type *pointer)
{
	return reinterpret_cast<qword>(pointer);
}

template <typename t_type>
inline t_type *pointer_from_address(
	qword address)
{
	return reinterpret_cast<t_type *>(address);
}

template <typename t_type, typename t_offset>
inline t_type *offset_pointer(
	t_type *pointer,
	t_offset offset)
{
	static_assert(__is_convertible_to(t_offset, qword));
	return pointer_from_address<t_type>(address_from_pointer(pointer) + static_cast<qword>(offset));
}

inline qword align_address(
	qword address,
	int alignment_bits)
{
	qword alignment_mask = (1ULL << (static_cast<qword>(alignment_bits) & static_cast<qword>(k_int8_max))) - 1ULL;
	return address + alignment_mask & ~alignment_mask;
}

inline bool address_is_aligned(
	qword address,
	int alignment_bits)
{
	qword alignment_mask = (1ULL << (static_cast<qword>(alignment_bits) &static_cast<qword>(k_int8_max))) - 1ULL;
	return address & alignment_mask;
}

template <typename t_type>
inline t_type *align_pointer(
	t_type *pointer,
	int alignment_bits)
{
	qword address = address_from_pointer(pointer);
	address = align_address(address, alignment_bits);
	return pointer_from_address<t_type>(address);
}

template <typename t_type>
inline bool pointer_is_aligned(
	t_type *pointer,
	int alignment_bits)
{
	qword address = address_from_pointer(pointer);
	return address_is_aligned(address, alignment_bits);
}

template <typename t_lhs_type, typename t_rhs_type>
inline intptr_t pointer_distance(
	t_lhs_type *p1,
	t_rhs_type *p2)

{
	return static_cast<intptr_t>(reinterpret_cast<qword>(p2) - reinterpret_cast<qword>(p1));
}
