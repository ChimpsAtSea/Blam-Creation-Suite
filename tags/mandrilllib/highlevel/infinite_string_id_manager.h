#pragma once

#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE

class c_infinite_string_id_manager :
	public c_string_id_manager
{
public:
	c_infinite_string_id_manager();
	~c_infinite_string_id_manager();

	BCS_SHARED virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) override final;
	BCS_SHARED virtual BCS_RESULT commit_string(const char* string) override final;
	BCS_SHARED virtual BCS_RESULT fetch_string_id(const char* string, uint32_t& string_id) const override final;
	BCS_SHARED virtual BCS_RESULT fetch_string(uint32_t string_id, const char*& string) const override final;
	BCS_SHARED virtual BCS_RESULT clear() override final;

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

#endif
