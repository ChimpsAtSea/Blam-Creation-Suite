#include "tagreflection-private-pch.h"

h_block::h_block(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index) :
	h_extended_type(parent, _global_vftable_index, _local_vftable_index),
	block_data(nullptr)
{

}

h_block::~h_block()
{
	clear();
}

unsigned int h_block::get_count()
{
	if (block_data)
	{
		unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
		return *block_count_ptr;
	}
	return 0;
}

h_prototype** h_block::begin()
{
	if (block_data)
	{
		unsigned int* block_count = reinterpret_cast<unsigned int*>(block_data);
		h_prototype** elements = reinterpret_cast<h_prototype**>(block_count + 1);
		return elements;
	}
	return nullptr;
}
h_prototype** h_block::end()
{
	if (block_data)
	{
		unsigned int* block_count = reinterpret_cast<unsigned int*>(block_data);
		h_prototype** elements = reinterpret_cast<h_prototype**>(block_count + 1);
		return elements + *block_count;
	}
	return nullptr;
}

h_prototype& h_block::emplace_back()
{
	unsigned int block_count = 1;
	if (block_data)
	{
		block_count += *reinterpret_cast<unsigned int*>(block_data);
	}
	block_data = tracked_realloc(block_data, sizeof(unsigned int) + sizeof(h_prototype*) * block_count);
	unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
	h_prototype** elements = reinterpret_cast<h_prototype**>(block_count_ptr + 1);
	*block_count_ptr = block_count;

	h_prototype* element;
	BCS_RESULT rs = high_level_registry_create_high_level_prototype(__global_vftable_index, __local_vftable_index, element, this);
	ASSERT(BCS_SUCCEEDED(rs));

	elements[block_count - 1] = element;
	return *element;
}

h_prototype& h_block::emplace_back(h_prototype& _prototype)
{
	unsigned int block_count = 1;
	if (block_data)
	{
		block_count += *reinterpret_cast<unsigned int*>(block_data);
	}
	block_data = tracked_realloc(block_data, sizeof(unsigned int) + sizeof(h_prototype*) * block_count);
	unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
	h_prototype** elements = reinterpret_cast<h_prototype**>(block_count_ptr + 1);
	*block_count_ptr = block_count;

	h_prototype* element;
	BCS_RESULT rs = high_level_registry_create_high_level_prototype(__global_vftable_index, __local_vftable_index, element, this);
	ASSERT(BCS_SUCCEEDED(rs));

	elements[block_count - 1] = element;
	return *element;
}

h_prototype* const* h_block::create_elements(unsigned int num_elements)
{
	if (num_elements == 0)
	{
		return nullptr;
	}

	unsigned int elements_start_index = 0;
	unsigned int block_count = num_elements;
	if (block_data)
	{
		elements_start_index = *reinterpret_cast<unsigned int*>(block_data);
		block_count += elements_start_index;
	}

	block_data = tracked_realloc(block_data, sizeof(unsigned int) + sizeof(h_prototype*) * block_count);
	unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
	h_prototype** elements = reinterpret_cast<h_prototype**>(block_count_ptr + 1) + elements_start_index;
	*block_count_ptr = block_count;

	for (unsigned int element_index = 0; element_index < num_elements; element_index++)
	{
		h_prototype* element;
		BCS_RESULT rs = high_level_registry_create_high_level_prototype(__global_vftable_index, __local_vftable_index, element, this);
		ASSERT(BCS_SUCCEEDED(rs));
		elements[element_index] = element;
	}

	return elements;
}

h_prototype* const* h_block::get_elements(unsigned int& num_elements) const
{
	if (block_data)
	{
		unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
		h_prototype** elements = reinterpret_cast<h_prototype**>(block_count_ptr + 1);

		num_elements = *block_count_ptr;
		return elements;
	}
	else
	{
		num_elements = 0;
		return nullptr;
	}
}

bool h_block::erase(h_prototype* element_to_remove)
{
	if (block_data)
	{
		unsigned int* block_count_pointer = reinterpret_cast<unsigned int*>(block_data);
		h_prototype** elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);

		unsigned int block_count = *block_count_pointer;
		for (unsigned int block_index = 0; block_index < block_count; block_index++)
		{
			h_prototype* element = elements[block_index];
			if (element == element_to_remove)
			{
				block_count--;
				if (block_count == 0)
				{
					tracked_free(block_data);
					block_data = nullptr;
				}
				else
				{
					for (unsigned int shift_index = block_index; shift_index < block_count; shift_index++)
					{
						elements[shift_index] = elements[shift_index + 1];
					}
					block_data = tracked_realloc(block_data, sizeof(unsigned int) + sizeof(h_prototype*) * block_count);
					block_count_pointer = reinterpret_cast<unsigned int*>(block_data);
					elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);

					*block_count_pointer = block_count;
				}

				delete element;

				return true;
			}
		}
	}
	return false;
}

void h_block::clear()
{
	if (block_data)
	{
		unsigned int* block_count_pointer = reinterpret_cast<unsigned int*>(block_data);
		h_prototype** elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);

		unsigned int block_count = *block_count_pointer;
		for (unsigned int block_index = 0; block_index < block_count; block_index++)
		{
			h_prototype* element = elements[block_index];
			
			delete element;
		}
		tracked_free(block_data);
		block_data = nullptr;
	}
}

unsigned int h_block::size() const
{
	if (block_data == nullptr)
	{
		return 0;
	}

	unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
	return *block_count_ptr;
}

h_prototype& h_block::get(unsigned int index) const
{
	if (block_data == nullptr)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	unsigned int* block_count_ptr = reinterpret_cast<unsigned int*>(block_data);
	if (index >= *block_count_ptr)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	h_prototype** elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);
	h_prototype* element = elements[index];
	DEBUG_ASSERT(element != nullptr);
	return *element;
}

h_prototype& h_block::operator[](unsigned int index) const
{
	return get(index);
}

void h_block::remove(unsigned int index)
{
	if (block_data == nullptr)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	unsigned int* block_count_pointer = reinterpret_cast<unsigned int*>(block_data);
	unsigned int block_count = *block_count_pointer;
	if (index >= block_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	h_prototype** elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);
	h_prototype* element = elements[index];

	block_count--;
	if (block_count == 0)
	{
		tracked_free(block_data);
		block_data = nullptr;
	}
	else
	{
		for (unsigned int shift_index = index; shift_index < block_count; shift_index++)
		{
			elements[shift_index] = elements[shift_index + 1];
		}
		block_data = tracked_realloc(block_data, sizeof(unsigned int) + sizeof(h_prototype*) * block_count);
		block_count_pointer = reinterpret_cast<unsigned int*>(block_data);
		elements = reinterpret_cast<h_prototype**>(reinterpret_cast<unsigned int*>(block_data) + 1);

		*block_count_pointer = block_count;
	}

	delete element;
}

h_prototype* h_block::insert_hole(unsigned int index, unsigned int count)
{
	throw BCS_E_NOT_IMPLEMENTED;
}
