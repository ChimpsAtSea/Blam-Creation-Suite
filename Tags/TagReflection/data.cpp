#include "tagreflection-private-pch.h"

h_data::h_data(h_prototype* parent) :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_extended_type(_high_level_extended_type_data, parent != nullptr, _global_vftable_index, _local_vftable_index),
#else
	h_extended_type(parent),
#endif
	data_data(nullptr)
{

}

h_data::~h_data()
{
	clear();
}

unsigned int h_data::get_count()
{
	if (data_data)
	{
		unsigned int* data_count_ptr = reinterpret_cast<unsigned int*>(data_data);
		return *data_count_ptr;
	}
	return 0;
}

char* h_data::begin()
{
	if (data_data)
	{
		unsigned int* data_count = reinterpret_cast<unsigned int*>(data_data);
		char* elements = reinterpret_cast<char*>(data_count + 1);
		return elements;
	}
	return nullptr;
}
char* h_data::end()
{
	if (data_data)
	{
		unsigned int* data_count = reinterpret_cast<unsigned int*>(data_data);
		char* elements = reinterpret_cast<char*>(data_count + 1);
		return elements + *data_count;
	}
	return nullptr;
}

char& h_data::emplace_back(char value)
{
	unsigned int data_count = 1;
	if (data_data)
	{
		data_count += *reinterpret_cast<unsigned int*>(data_data);
	}
	data_data = tracked_realloc(data_data, sizeof(unsigned int) + sizeof(char) * data_count);
	unsigned int* data_count_ptr = reinterpret_cast<unsigned int*>(data_data);
	char* elements = reinterpret_cast<char*>(data_count_ptr + 1);
	*data_count_ptr = data_count;

	char& element = elements[data_count - 1];
	element = value;
	return element;
}

char* h_data::create_elements(unsigned int num_elements)
{
	unsigned int elements_start_index = 0;
	unsigned int data_count = num_elements;
	if (data_data)
	{
		elements_start_index = *reinterpret_cast<unsigned int*>(data_data);
		data_count += elements_start_index;
	}
	data_data = tracked_realloc(data_data, sizeof(unsigned int) + sizeof(char) * data_count);
	unsigned int* data_count_ptr = reinterpret_cast<unsigned int*>(data_data);
	char* elements = reinterpret_cast<char*>(data_count_ptr + 1) + elements_start_index;
	*data_count_ptr = data_count;

	memset(elements, 0, sizeof(char) * num_elements);

	return elements;
}

char* h_data::append_elements(char const* copy_from, unsigned int num_elements)
{
	char* elements = create_elements(num_elements);
	memcpy(elements, copy_from, num_elements);
	return elements;
}

char* h_data::append_elements(char const* copy_start, char const* copy_end)
{
	if ((copy_start == nullptr || copy_end == nullptr) && (copy_start != copy_end))
	{
		throw BCS_E_INVALID_ARGUMENT;
	}
	if (copy_start > copy_end)
	{
		throw BCS_E_INVALID_ARGUMENT;
	}

	size_t num_elements = static_cast<unsigned int>(copy_end - copy_start);
	if (num_elements > UINT_MAX)
	{
		throw BCS_E_INVALID_ARGUMENT;
	}

	char* elements = create_elements(num_elements);
	memcpy(elements, copy_start, num_elements);
	return elements;
}

void h_data::clear()
{
	if (data_data)
	{
		unsigned int* data_count_pointer = reinterpret_cast<unsigned int*>(data_data);
		char* elements = reinterpret_cast<char*>(reinterpret_cast<unsigned int*>(data_data) + 1);

		tracked_free(data_data);
		data_data = nullptr;
	}
}

char& h_data::operator[](size_t index)
{
	if (data_data != nullptr)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	unsigned int* data_count_pointer = reinterpret_cast<unsigned int*>(data_data);

	if (index >= *data_count_pointer)
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	char* elements = reinterpret_cast<char*>(reinterpret_cast<unsigned int*>(data_data) + 1);
	char& element = elements[index];
	return element;
}

unsigned int h_data::size() const
{
	if (data_data == nullptr)
	{
		return 0;
	}

	unsigned int* data_count_pointer = reinterpret_cast<unsigned int*>(data_data);
	return *data_count_pointer;
}

bool h_data::empty() const
{
	return data_data == nullptr;
}

void const* h_data::data() const
{
	return data_data;
}

void* h_data::data()
{
	return data_data;
}
