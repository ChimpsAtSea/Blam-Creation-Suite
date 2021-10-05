#include "mandrillui-private-pch.h"

inline bool is_whitespace(char character)
{
	switch (character)
	{
	case ' ':
	case '\t':
		return true;
	}
	return false;
}

bool is_end_of_line(const char* character, bool* skip_extra_character)
{
	char current_character = character[0];
	bool is_eol = current_character == '\n' || current_character == '\r';
	if (is_eol)
	{
		char next_character = character[1];
		bool is_extended_eol = current_character != next_character && (next_character == '\n' || next_character == '\r');
		*skip_extra_character = is_extended_eol;
		return true;
	}
	else
	{
		*skip_extra_character = false;
		return false;
	}
}


e_lisp_error_type c_lisp_node::parse(const char* file_data, size_t file_size, std::vector<c_lisp_node*>& arguments, std::vector<c_lisp_error>& errors)
{
	c_lisp_node* current_node = nullptr;

	const char* const start_position = file_data;
	const char* const end_position = start_position + file_size;
	const char* current_position = start_position;

	do
	{
		std::string current_child_search_range_debug = { current_position, end_position };
		current_position = traverse(start_position, current_position, end_position, current_node, arguments, errors LISP_AST_DEBUG(, current_child_search_range_debug));
	} while (current_position < end_position);

	return errors.empty() ? _lisp_error_type_success : errors[0].type;
}

c_lisp_node::c_lisp_node(c_lisp_node* parent) :
	type(_lisp_node_type_uninitialized),
	data(),
	arguments(),
	parent(parent),
	line_number(0),
	text_position(0),
	text_length(0)
{
	if (parent) parent->arguments.push_back(this);
}

unsigned long c_lisp_node::get_line_count(const char* const root_start_position, const char* const traversal_position)
{
	unsigned long line_count = 1;

	const char* const start_position = root_start_position;
	const char* const end_position = traversal_position;
	const char* current_position = start_position;
	while (current_position < end_position)
	{
		bool skip_extra_character = false;
		bool new_line = is_end_of_line(current_position, &skip_extra_character);


		if (new_line) line_count++;
		if (skip_extra_character) current_position++;
		current_position++;
	}

	return line_count;
}

c_lisp_node::~c_lisp_node()
{
	for (c_lisp_node* argument : arguments)
	{
		delete argument;
	}
}

const char* c_lisp_node::traverse(
	const char* const root_start_position,
	const char* const traversal_start_position,
	const char* const traversal_end_position,
	c_lisp_node*& current_node,
	std::vector<c_lisp_node*>& root_arguments,
	std::vector<c_lisp_error>& errors
	LISP_AST_DEBUG(, std::string& const debug))
{
	const char* traversal_position = traversal_start_position;
	const char* current_node_begin = traversal_position;
	const char* last_begin_statement_position = nullptr;

	e_lisp_node_type search_type = _lisp_node_type_uninitialized;
	int32_t search_depth = 0;

	bool finished_searching = false;
	bool found_node = false;
	bool skip_extra_character = false;

	unsigned long line_count_start = get_line_count(root_start_position, traversal_position);
	unsigned long line_count = line_count_start;
	while (traversal_position < traversal_end_position && !finished_searching)
	{
		LISP_AST_DEBUG(std::string prefix_search_debug = { traversal_start_position, traversal_position });
		LISP_AST_DEBUG(std::string postfix_search_debug = { traversal_position, traversal_end_position });

		char current_character = traversal_position[0];
		char next_character = current_character ? traversal_position[1] : 0;
		bool whitespace = is_whitespace(current_character);
		bool new_line = is_end_of_line(traversal_position, &skip_extra_character);
		bool is_open_bracket = current_character == '(';
		bool is_end_bracket = current_character == ')';
		bool is_searching_comment = search_type == _lisp_node_type_comment || search_type == _lisp_node_type_multi_line_comment;
		if (new_line) line_count++;

		if (is_searching_comment)
		{
			if (search_type == _lisp_node_type_comment && new_line)
			{
				search_depth--;
				finished_searching = true;
			}
			else if (search_type == _lisp_node_type_multi_line_comment && (current_character == '*' && next_character == ';'))
			{
				skip_extra_character = true;
				search_depth--;
				finished_searching = true;
			}
		}
		else if (!is_searching_comment && search_type != _lisp_node_type_variable && is_open_bracket)
		{
			search_type = _lisp_node_type_statement;
			found_node = true;
			if (search_depth == 0)
			{
				current_node_begin = traversal_position;
				last_begin_statement_position = traversal_position;
			}
			search_depth++;
		}
		else if (!is_searching_comment && is_end_bracket)
		{
			if (search_depth == 0 || search_type == _lisp_node_type_variable)
			{
				errors.push_back({ line_count, 0, _lisp_error_type_unexpected_end_parenthesis, "syntax error : unexpected ')' expected '(' or variable statement" });
			}
			else if (search_type == _lisp_node_type_statement)
			{
				if (search_depth == 1) // finish reading this node
				{
					search_depth--;
					finished_searching = true;
				}
				else
				{
					search_depth--;
				}
			}
		}
		else if (/*search_type == _lisp_node_type_uninitialized && */current_character == ';')
		{
			if (next_character == '*')
			{
				search_type = _lisp_node_type_multi_line_comment;
			}
			else
			{
				search_type = _lisp_node_type_comment;
			}
			found_node = true;
			current_node_begin = traversal_position;
			//if (search_depth != 0)
			//{
			//	errors.push_back({ line_count, 0, _lisp_error_type_unexpected_parser_error_internal_non_zero_search_depth,  "parser error: internal error 'search_depth != 0'" });
			//	if (IsDebuggerPresent()) throw; // internal compiler error.
			//}
			search_depth = 1;
		}
		else if (search_type == _lisp_node_type_uninitialized && !whitespace && !new_line)
		{
			search_type = _lisp_node_type_variable;
			found_node = true;
			current_node_begin = traversal_position;
			if (search_depth != 0)
			{
				errors.push_back({ line_count, 0, _lisp_error_type_unexpected_parser_error_internal_non_zero_search_depth,  "parser error: internal error 'search_depth != 0'" });
				DEBUG_FATAL_ERROR("internal compiler error");
			}
			search_depth = 1;
		}
		else if (search_type == _lisp_node_type_variable && (whitespace || new_line || is_open_bracket))
		{
			search_depth--;
			finished_searching = true;
		}

		if (skip_extra_character) traversal_position++;
		traversal_position++;
	}
	if (search_type == _lisp_node_type_variable && !finished_searching) // variable ends at the end of the search range
	{
		search_depth--;
		finished_searching = true;
		traversal_position++;
	}
	if (search_depth != 0)
	{
		char error_buffer[512]{};
		snprintf(error_buffer, _countof(error_buffer) - 1, "syntax error : missing ')' [depth %i]", search_depth);
		errors.push_back({ line_count + 1, 0, _lisp_error_type_missing_end_parenthesis,  error_buffer });
	}
	else if (search_type != _lisp_node_type_uninitialized && !finished_searching) // we started searching for something but something else strange happened
	{
		errors.push_back({ line_count, 0, _lisp_error_type_internal_failed_statement_search,  "parser error: internal error 'failed to finish searching statement'" });
		DEBUG_FATAL_ERROR("internal compiler error");
	}

	if (found_node)
	{

		c_lisp_node* new_node = new c_lisp_node(current_node);
		new_node->type = search_type;
		if (current_node == nullptr) root_arguments.push_back(new_node);
		current_node = new_node;

		if (search_type == _lisp_node_type_statement)
		{
			if (*traversal_position)
			{
				const char* child_search_position = current_node_begin + 1;
				const char* const child_search_end = traversal_position - 1;

				std::string statement_data = { child_search_position, child_search_end };
				LISP_AST_DEBUG({ printf("statement>%s\n", statement_data.c_str()); });
				new_node->data = statement_data;
				new_node->line_number = get_line_count(root_start_position, child_search_position);

				do
				{
					std::string current_child_search_range_debug = { child_search_position, child_search_end };
					child_search_position = traverse(root_start_position, child_search_position, child_search_end, current_node, root_arguments, errors LISP_AST_DEBUG(, current_child_search_range_debug));
				} while (child_search_position < child_search_end);
			}
			else
			{
				unsigned long last_begin_statement_line_count = get_line_count(root_start_position, last_begin_statement_position);
				errors.push_back({ last_begin_statement_line_count, 0, _lisp_error_type_missing_end_parenthesis, "syntax error : missing ')'" });
			}
		}
		else if (search_type == _lisp_node_type_variable)
		{
			std::string argument_data = { current_node_begin, traversal_position - (skip_extra_character ? 2 : 1) };
			LISP_AST_DEBUG({ printf("argument>%s\n", argument_data.c_str()); });
			new_node->data = argument_data;
			new_node->line_number = get_line_count(root_start_position, current_node_begin);
		}
		else if (search_type == _lisp_node_type_comment)
		{
			std::string argument_data = { current_node_begin, traversal_position - (skip_extra_character ? 2 : 1) };
			LISP_AST_DEBUG({ printf("comment>'%s'\n", argument_data.c_str()); });
			new_node->data = argument_data;
			new_node->line_number = get_line_count(root_start_position, current_node_begin);
		}
		else if (search_type == _lisp_node_type_multi_line_comment)
		{
			std::string argument_data = { current_node_begin, traversal_position };
			LISP_AST_DEBUG({ printf("multi_line_comment>'%s'\n", argument_data.c_str()); });
			new_node->data = argument_data;
			new_node->line_number = get_line_count(root_start_position, current_node_begin);
		}
		current_node = new_node->parent;

		return traversal_position;
	}
	else
	{
		return traversal_end_position;
	}
}
