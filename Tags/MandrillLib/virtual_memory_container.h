#pragma once
class c_virtual_memory_container
{
public:
	BCSAPI c_virtual_memory_container(size_t address_space_size);
	BCSAPI ~c_virtual_memory_container();

	BCSAPI void* insert_hole(size_t offset, size_t size);
	BCSAPI void* insert_hole(void* position, size_t size);
	BCSAPI void set_size(size_t size);
	inline char* get_data() const { return static_cast<char*>(virtual_memory); }
	inline size_t get_size() const { return current_size_aligned; }
	inline size_t get_size_aligned() const { return current_size_aligned; }

protected:
	static size_t get_page_size();

	const size_t page_size;
	const size_t address_space_size;
	size_t current_size;
	size_t current_size_aligned;
	LPVOID virtual_memory;
};

