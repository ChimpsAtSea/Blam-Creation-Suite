#pragma once

class c_blamlib_string_parser
{
public:
	c_blamlib_string_parser(const char* name, bool is_block = 0, std::map<std::string, int>* field_name_unique_counter = nullptr);
	void cleanup_code_name();

	c_fixed_string_2048 string;
	c_fixed_string_512 display_name;
	c_fixed_string_512 alt_name;
	c_fixed_string_128 units;
	c_fixed_string_2048 description;
	c_fixed_string_128 minimum;
	c_fixed_string_128 maximum;
	bool read_only;
	bool is_index;
	bool is_pointer;

	c_fixed_string_512 code_name;

	static std::pair<const char*, const char*> bespoke_fixups[];
};


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
		k_num_buffers
	};

	static constexpr char flag_unknown0_id = '!';
	static constexpr char flag_unknown1_id = '*';
	static constexpr char flag_unknown2_id = '^';
	static constexpr char flag_unknown3_id = '~';
	static constexpr char flag_unknown4_id = '?';
	static constexpr char flag_unknown5_id = '\x1';

public:

	c_blamlib_string_parser_v2(const char* string);
	~c_blamlib_string_parser_v2();
	void fixup_flags(char* string);

private:
	uint32_t buffer_length;
	char* buffer_aggregate;

public:
	char(&name)[];
	char(&old_name)[];
	char(&flags)[];
	char(&units)[];
	char(&limits)[];
	char(&limits_legacy)[];
	char(&meta)[];
	char(&description)[];

	bool flag_unknown0;
	bool flag_unknown1;
	bool flag_unknown2;
	bool flag_unknown3;
	bool flag_unknown4;
	bool flag_unknown5;
};
