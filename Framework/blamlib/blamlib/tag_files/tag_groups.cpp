#include <blamlib/tag_files/tag_groups.h>

/* ---------- code */

void *tag_block_get_element_with_size(
	s_tag_block *block,
	unsigned int element_index,
	[[maybe_unused]] unsigned int element_size)
{
	blamlib_assert(block);
	blamlib_assert(block->address);

	static c_static_string<256> temp;

	vassert(
		VALID_INDEX(element_index, block->count),
		csnzprintf(
			temp.get_buffer(),
			static_cast<unsigned int>(temp.max_length()),
			"#%d is not a valid %s index in [#0, #%d]",
			element_index,
			"s_tag_block", // TODO: definition name
			block->count));

	//
	// TODO
	//

	return nullptr;
}

void *tag_block_get_range_with_size(
	[[maybe_unused]] s_tag_block *block,
	[[maybe_unused]] int first_element_index,
	[[maybe_unused]] int element_count,
	[[maybe_unused]] int element_size)
{
	//
	// TODO
	//

	return nullptr;
}

void *tag_block_get_element_within_range_with_size(
	[[maybe_unused]] s_tag_block *block,
	[[maybe_unused]] int first_element_index,
	[[maybe_unused]] int inner_element_index,
	[[maybe_unused]] int element_count,
	[[maybe_unused]] int element_size)
{
	//
	// TODO
	//

	return nullptr;
}

void *tag_data_get_pointer(
	[[maybe_unused]] s_tag_data *data,
	[[maybe_unused]] int offset,
	[[maybe_unused]] int size)
{
	//
	// TODO
	//

	return nullptr;
}
