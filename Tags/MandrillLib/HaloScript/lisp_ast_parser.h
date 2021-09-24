#pragma once

#define LISP_AST_PARSER_DEBUG 0

#if LISP_AST_PARSER_DEBUG
#define LISP_AST_DEBUG(...) __VA_ARGS__
#else
#define LISP_AST_DEBUG(...) 
#endif

enum e_lisp_error_type
{
	_lisp_error_type_success,
	_lisp_error_type_internal_failed_statement_search = 1000,
	_lisp_error_type_unexpected_parser_error_internal_non_zero_search_depth = 1001,
	_lisp_error_type_unexpected_end_parenthesis = 2000,
	_lisp_error_type_missing_end_parenthesis = 2001,
};

enum e_lisp_node_type
{
	_lisp_node_type_uninitialized,
	_lisp_node_type_variable,
	_lisp_node_type_statement,
	_lisp_node_type_comment,
	_lisp_node_type_multi_line_comment,
	_lisp_node_type_root
};

struct c_lisp_error
{
public:
	unsigned long line_number;
	unsigned long position;
	e_lisp_error_type type;
	std::string message;
};

struct c_lisp_node
{
public:
	static e_lisp_error_type parse(const char* file_data, size_t file_size, std::vector<c_lisp_node*>& arguments, std::vector<c_lisp_error>& errors);
	~c_lisp_node();
private:
	c_lisp_node(c_lisp_node* parent);

	static unsigned long get_line_count(const char* const root_start_position, const char* const traversal_position);
	static const char* traverse(
		const char* const root_start_position,
		const char* const traversal_start_position,
		const char* const traversal_end_position,
		c_lisp_node*& current_node,
		std::vector<c_lisp_node*>& root_arguments,
		std::vector<c_lisp_error>& errors
		LISP_AST_DEBUG(, std::string& const debug));

public:
	e_lisp_node_type type;
	std::string data;
	std::vector<c_lisp_node*> arguments;
	c_lisp_node* parent;
	unsigned long line_number;
	unsigned long text_position;
	unsigned long text_length;
};
