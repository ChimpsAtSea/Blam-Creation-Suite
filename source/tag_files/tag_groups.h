#pragma once

#include <cseries/cseries.h>
#include <memory/memory_interface.h>
#include <memory/static_arrays.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_group_definitions.h>

/* ---------- types */

struct s_tag_reference
{
	tag group_tag;
	c_pointer32<char> name;
	long name_length;
	long index;
};
static_assert(sizeof(s_tag_reference) == 0x10);

struct s_tag_block
{
	long count;
	c_pointer32<void> address;
	c_pointer32<s_tag_block_definition> definition;
};
static_assert(sizeof(s_tag_block) == 0xC);

struct s_tag_data
{
	long size;
	long stream_flags;
	long stream_offset;
	c_pointer32<void> address;
	c_pointer32<s_tag_data_definition> definition_address;
};
static_assert(sizeof(s_tag_data) == 0x14);

struct s_tag_function
{
	s_tag_data data;
};
static_assert(sizeof(s_tag_function) == 0x14);

/* ---------- globals */

extern s_tag_block_definition g_bit_vector_block;
extern s_tag_block_definition g_tag_reference_block;
extern s_struct_definition g_tag_function_struct;

/* ---------- prototypes/TAG_GROUPS.CPP */

void *tag_block_get_element_with_size(
	s_tag_block *block,
	long element_index,
	long element_size);

void *tag_block_get_range_with_size(
	s_tag_block *block,
	long first_element_index,
	long element_count,
	long element_size);

void *tag_block_get_element_within_range_with_size(
	s_tag_block *block,
	long first_element_index,
	long inner_element_index,
	long element_count,
	long element_size);

void *tag_data_get_pointer(
	s_tag_data *data,
	long offset,
	long size);

/* ---------- classes */

template <typename t_element>
class c_typed_tag_block : public s_tag_block
{
public:
	inline bool valid_index(long index) const
	{
		return index >= 0 && index < count;
	}

	bool try_get_element(long index, t_element **out_element)
	{
		if (!valid_index(index) || !out_element)
			return false;

		//
		// TODO
		//

		*out_element = nullptr;

		return true;
	}

	t_element *get_element(long index)
	{
		t_element *result = nullptr;

		if (try_get_element(index, &result))
			return result;

		return nullptr;
	}

	bool try_get_element(long index, t_element **out_element) const
	{
		if (!valid_index(index) || !out_element)
			return false;

		//
		// TODO
		//

		*out_element = nullptr;

		return true;
	}

	t_element *get_element(long index) const
	{
		t_element *result = nullptr;

		if (try_get_element(index, &result))
			return result;

		return nullptr;
	}
};
static_assert(sizeof(c_typed_tag_block<long>) == sizeof(s_tag_block));

template <typename t_element, typename t_flags>
class c_tag_block_flags
{
private:
	t_flags m_flags;

public:
	c_tag_block_flags(t_flags flags) : m_flags(flags) {}
	c_tag_block_flags() : c_tag_block_flags(t_flags()) {}
	c_tag_block_flags(const c_tag_block_flags<t_element, t_flags> &other) : c_tag_block_flags(other.m_flags) {}

	bool operator==(t_flags other) const { return m_flags == other; }
	bool operator!=(t_flags other) const { return !(*this == other); }

	bool operator==(const c_tag_block_flags<t_element, t_flags> &other) const { return m_flags == other.m_flags; }
	bool operator!=(const c_tag_block_flags<t_element, t_flags> &other) const { return !(*this == other); }

	operator t_flags() const { return m_flags; }
};
static_assert(sizeof(c_tag_block_flags<void, long>) == sizeof(long));

template <typename t_element, typename t_index>
class c_tag_block_index
{
private:
	t_index m_index;

public:
	inline c_tag_block_index(t_index index) : m_index(index) {}
	inline c_tag_block_index() : c_tag_block_index(t_index()) {}
	inline c_tag_block_index(const c_tag_block_index<t_element, t_index> &other) : c_tag_block_index(other.m_index) {}

	inline bool operator==(t_index other) const { return m_index == other; }
	inline bool operator!=(t_index other) const { return !(*this == other); }

	inline bool operator==(const c_tag_block_index<t_element, t_index> &other) const { return m_index == other.m_index; }
	inline bool operator!=(const c_tag_block_index<t_element, t_index> &other) const { return !(*this == other); }

	inline bool try_resolve(c_typed_tag_block<t_element> *block, t_element **out_element)
	{
		if (!block || !out_element)
			return false;
		return block->try_get_element(m_index, out_element);
	}

	inline t_element *resolve(c_typed_tag_block<t_element> *block)
	{
		if (!block)
			return nullptr;
		return block->get_element(m_index);
	}

	inline operator t_index() const { return m_index; }
	inline operator bool() const { return m_index != (t_index)NONE; }
};
static_assert(sizeof(c_tag_block_index<void, long>) == sizeof(long));

class c_tag_block_bit_vector : public c_typed_tag_block<dword> {};
static_assert(sizeof(c_tag_block_bit_vector) == sizeof(s_tag_block));

template <typename t_index>
class c_tag_block_index_list : public c_typed_tag_block<t_index> {};
static_assert(sizeof(c_tag_block_index_list<long>) == sizeof(s_tag_block));
