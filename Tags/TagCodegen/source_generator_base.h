#pragma once

enum e_namespace_tree_write
{
	_namespace_tree_write_none = 0,
	_namespace_tree_write_namespace = 1,
	_namespace_tree_write_pragma_pack = 2,
	_namespace_tree_write_intellisense = 4,
	_namespace_tree_write_warnings = 8,
};

class c_source_generator_base
{
public:

	c_source_generator_base(s_engine_platform_build engine_platform_build);
	virtual ~c_source_generator_base();

	void increment_indent();
	void decrement_indent();

	std::string get_base_namespace(bool semicolon_suffix);
	std::string get_engine_namespace(bool semicolon_suffix);
	std::string get_platform_namespace(bool semicolon_suffix);
	std::string get_namespace(bool semicolon_suffix);

	void begin_namespace_tree(std::stringstream& stream, uint32_t tree_write_options);
	void end_namespace_tree(std::stringstream& stream, uint32_t tree_write_options);

	void write_field_description_comment(std::stringstream& stream, const blofeld::s_tag_field& tag_field);

protected:
	s_engine_platform_build engine_platform_build;
public:
	bool has_error;
protected:
	std::string indent;
private:
	const char* _engine_namespace;
	const char* _platform_namespace;
};

