#pragma once

class c_h5_tag_block_definition;
struct s_h5_tag_block_definition;
struct s_h5_tag_layout_header;

class c_blamboozle_h5_forge :
	public c_blamboozle_base
{
public:
	c_blamboozle_h5_forge(const wchar_t* output_directory, const wchar_t* binary_filepath);
	~c_blamboozle_h5_forge();
	virtual int run() override final;

	static c_h5_tag_block_definition* get_tag_block_definition(
		void* virtual_address, 
		const char* halo5_forge_data, 
		const s_h5_tag_block_definition* definition_header, 
		const s_h5_tag_layout_header* tag_layout_header = nullptr);
	static std::map<void*, c_h5_tag_block_definition*> tag_block_definitions;
};

