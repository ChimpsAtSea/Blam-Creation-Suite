#pragma once

enum e_validation_state
{
	_validation_state_unknown,
	_validation_state_valid,
	_validation_state_block_valid,
	_validation_state_warning,
	_validation_state_invalid,
	_validation_state_previously_invalid
};

struct s_field_validation_result
{
	e_validation_state validation_state;
	uint32_t field_size;
	const char* string_id_value;
	bool float_is_out_of_range;
	bool block_is_out_of_range;
	bool block_struct_is_valid;
	bool is_enum_empty;
	bool missing_api_interop_struct;
	uint32_t field_offset;
	uint32_t absolute_offset;
	int level;
};

