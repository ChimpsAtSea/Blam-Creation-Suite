#pragma once

struct c_blamlib_string_parser_v2
{
private:
	enum
	{
		_buffer_name,
		_buffer_old_name,
		_buffer_flags,
		_buffer_units,
		_buffer_limits_legacy,
		_buffer_limits,
		_buffer_meta,
		_buffer_description,
		_buffer_code_name,
		k_num_buffers
	};

	static constexpr char field_flag_id_unknown0 = '!';
	static constexpr char field_flag_id_read_only = '*';
	static constexpr char field_flag_id_index = '^';
	static constexpr char field_flag_id_unknown3 = '~';
	static constexpr char field_flag_id_pointer = '\x1';

public:

	c_blamlib_string_parser_v2(const char* string, bool is_block = false, std::unordered_map<std::string, int>* string_list_value_unique_counter = nullptr);
	~c_blamlib_string_parser_v2();
	void fixup_flags(char* string);

private:
	void cleanup_code_name();
	void setup_code_name();

public:
	c_fixed_string_2048 pretty_name;
	c_fixed_string_2048 tag_file_name;
	c_fixed_string_512 old_name;
	c_fixed_string_512 old_name2;
	c_fixed_string_512 old_name3;
	c_fixed_string_2048 flags;
	c_fixed_string_2048 units;
	c_fixed_string_2048 limits;
	c_fixed_string_2048 limits_legacy;
	c_fixed_string_2048 meta;
	c_fixed_string_2048 description;
	c_fixed_string_4096 code_name;

	bool flag_unknown0;
	bool flag_read_only;
	bool flag_index;
	bool flag_unknown3;
	bool flag_unknown4;
	bool flag_pointer;

	bool is_block;
	uint32_t code_index;
	std::unordered_map<std::string, int>* string_list_value_unique_counter;
};

