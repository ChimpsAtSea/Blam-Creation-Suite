#pragma once

class c_infinite_string_id_manager :
	public c_string_id_manager
{
public:
	c_infinite_string_id_manager();
	~c_infinite_string_id_manager();

	virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) override;
	virtual BCS_RESULT commit_string(const char* string) override;
	virtual BCS_RESULT find_string(uint32_t string_id, const char*& string);

	void init_haloreach_temp_strings(); // #TODO: replace this with a database system

	struct s_infinite_string_id_entry
	{
		uint32_t hash;
		char string[];
	};

	using t_string_id_entries = std::vector<s_infinite_string_id_entry*>;
	using t_hash_to_string = std::unordered_map<uint32_t, s_infinite_string_id_entry*>;

	t_string_id_entries string_id_entries;
	t_hash_to_string hash_to_string;
};