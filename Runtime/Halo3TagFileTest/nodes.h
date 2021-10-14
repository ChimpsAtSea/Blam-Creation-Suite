#pragma once

using s_datum_handle = unsigned long;

class c_node
{
public:
	unsigned long const literal;
	unsigned long const unknown;
	unsigned long const size;
	unsigned long const depth;
	c_node* const parent;
	std::vector<c_node*> children;
	char* const node_header_data;
	char* node_data_start;
	char* const node_data_end;
	char short_name[5];

	c_node(char* node_header_data, c_node* parent, bool parse_children = true);
	virtual ~c_node();
	void log_pad();
	void log();
	void parse_children();

	c_node* find_first_node(unsigned long type);

	template<typename t_node>
	t_node* find_first_node()
	{
		return static_cast<t_node*>(find_first_node(t_node::type));
	}

	inline unsigned long get_child_count() const { return static_cast<unsigned long>(children.size()); }

	c_node* get_node(unsigned long index);

	template<typename t_node>
	t_node* get_node(unsigned long index)
	{
		return static_cast<t_node*>(get_node(index));
	}

protected:
	virtual void log_impl();
};

template<unsigned long _type, bool _parse_children = true>
class c_typed_node : public c_node
{
public:
	static constexpr unsigned long type = _type;

	c_typed_node(char* node_header_data, c_node* parent, bool parse_children = _parse_children) :
		c_node(node_header_data, parent, parse_children)
	{

	}
};

class c_binary_data_node : public c_typed_node<'bdat'>
{
public:
	c_binary_data_node(char* node_header_data, c_node* parent);
};

class c_tag_reference_node : public c_typed_node<'tgrf'>
{
public:
	char* filepath_buffer;
	const char* filepath;
	unsigned long group_tag;

	c_tag_reference_node(char* node_header_data, c_node* parent);
	~c_tag_reference_node();

	virtual void log_impl() override;
};

class c_tag_string_id_node : public c_typed_node<'tgsi'>
{
public:
	char* filepath_buffer;
	const char* filepath;

	c_tag_string_id_node(char* node_header_data, c_node* parent);
	~c_tag_string_id_node();

	virtual void log_impl() override;
};

class c_blay_node : public c_typed_node<'blay'>
{
public:
	c_blay_node(char* node_header_data, c_node* parent);
	~c_blay_node();
};

class c_tab_block_node : public c_typed_node<'tgbl'>
{
public:
	c_tab_block_node(char* node_header_data, c_node* parent);
	~c_tab_block_node();
};

class c_string_table_node : public c_typed_node<'str*'>
{
public:
	c_string_table_node(char* node_header_data, c_node* parent);
	~c_string_table_node();

	virtual void log_impl() override;
};

class c_string1_node : public c_typed_node<'sz+x'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_string1_node(char* node_header_data, c_node* parent);
	~c_string1_node();

	virtual void log_impl() override;
};

class c_custom_search_block_names_node : public c_typed_node<'csbn'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_custom_search_block_names_node(char* node_header_data, c_node* parent);
	~c_custom_search_block_names_node();
	void log_impl();
};

class c_datum_node : public c_typed_node<'dtnm'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_datum_node(char* node_header_data, c_node* parent);
	~c_datum_node();
	void log_impl();
};

struct s_array_entry
{
	uint32_t name_offset;
	uint32_t count;
	uint32_t num_fields;
};


class c_array_node : public c_typed_node<'arr!'>
{
public:
	s_array_entry* const entries;
	unsigned long const entry_count;

	c_array_node(char* node_header_data, c_node* parent);
	~c_array_node();
	void log_impl();
};

struct s_resources_v2_entry
{
	uint32_t name_offset;
	uint32_t unknown;
	uint32_t unknown1;
};

class c_resources_v2_node : public c_typed_node<'rcv2'>
{
public:
	s_resources_v2_entry* const entries;
	unsigned long const entry_count;

	c_resources_v2_node(char* node_header_data, c_node* parent);
	~c_resources_v2_node();
	void log_impl();
};

struct s_unknown_entry
{
	uint32_t name_offset;
	uint32_t unknown;
	uint32_t unknown1;
	uint32_t unknown2;
	uint32_t unknown3;
	uint32_t unknown4;
};

class c_unknown_node : public c_typed_node<']==['>
{
public:
	s_unknown_entry* const entries;
	unsigned long const entry_count;

	c_unknown_node(char* node_header_data, c_node* parent);
	~c_unknown_node();
	void log_impl();
};

struct s_tag_field_type_entry
{
	uint32_t typename_offset;
	uint32_t size;
	uint32_t unknown1;
};

class c_tag_header_node : public c_typed_node<'tag!'>
{
public:
	c_tag_header_node(char* node_header_data, c_node* parent);
	~c_tag_header_node();
};

class c_tag_tgly_node : public c_typed_node<'tgly'>
{
public:
	c_tag_tgly_node(char* node_header_data, c_node* parent);
};

struct s_string_list_entry
{
	unsigned long unknown;
};

class c_tag_string_list_node : public c_typed_node<'sz[]'>
{
public:
	s_string_list_entry* const entries;
	unsigned long const entry_count;

	c_tag_string_list_node(char* node_header_data, c_node* parent);
	virtual void log_impl() override;
};

struct s_tag_struct_table_entry
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	unsigned long string_offset;
	unsigned long gras_index;
};

class c_tag_structure_table_node : public c_typed_node<'stv2'>
{
public:
	s_tag_struct_table_entry* const entries;
	unsigned long const entry_count;

	c_tag_structure_table_node(char* node_header_data, c_node* parent);

	virtual void log_impl() override;
};

class c_tag_field_types_node : public c_typed_node<'tgft'>
{
public:
	s_tag_field_type_entry* const entries;
	unsigned long const entry_count;

	c_tag_field_types_node(char* node_header_data, c_node* parent);
	~c_tag_field_types_node();

	virtual void log_impl() override;
};

struct s_gras_entry
{
	unsigned long name_offset;
	unsigned long tag_field_type_index;
	unsigned long unknown1;
};

class c_gras_node : public c_typed_node<'gras'>
{
public:
	s_gras_entry* const entries;
	unsigned long const entry_count;

	c_gras_node(char* node_header_data, c_node* parent);
	~c_gras_node();

	virtual void log_impl() override;
};

struct s_block_v2_entry
{
	uint32_t name_offset;
	uint32_t max_count;
	uint32_t unknown1;
};

class c_block_v2_node : public c_typed_node<'blv2'>
{
public:
	s_block_v2_entry* const entries;
	unsigned long const entry_count;

	c_block_v2_node(char* node_header_data, c_node* parent);
	~c_block_v2_node();

	virtual void log_impl() override;
};


c_node* create_data_node(char* data, c_node* parent);
