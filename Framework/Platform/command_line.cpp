#include "platform-private-pch.h"

struct s_command_line_argument
{
	const wchar_t* argument_wc;
	const char* argument_mb;
	const wchar_t* value_wc;
	const char* value_mb;
	uint32_t argument_length_wc;
	uint32_t argument_length_mb;
};

static s_command_line_argument* command_line_arguments;
static LPSTR* command_line_arguments_mb;
static LPWSTR* command_line_arguments_wc;
static int command_line_arguments_count;

BCS_RESULT init_command_line(const wchar_t* command_line)
{
	if (command_line == nullptr)
	{
		command_line = GetCommandLineW();
	}
	command_line_arguments_wc = CommandLineToArgvW(command_line, &command_line_arguments_count);

	uint32_t total_buffer_size = sizeof(LPSTR) * command_line_arguments_count;
	uint32_t* mb_buffer_lengths = static_cast<uint32_t*>(_alloca(sizeof(uint32_t*) * command_line_arguments_count));
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		LPWSTR argument = command_line_arguments_wc[argument_index];
		uint32_t mb_buffer_length = static_cast<unsigned long>(wcstombs(nullptr, argument, 0));
		//uint32_t string_length = static_cast<unsigned long>(wcslen(argument) + 1);
		mb_buffer_lengths[argument_index] = mb_buffer_length;
		total_buffer_size += mb_buffer_length + 1;
	}

	HLOCAL ascii_command_line_arguments_buffer = LocalAlloc(LMEM_ZEROINIT, total_buffer_size);

	command_line_arguments_mb = static_cast<LPSTR*>(ascii_command_line_arguments_buffer);
	LPSTR command_line_arguments_string_buffer_pos = reinterpret_cast<LPSTR>(command_line_arguments_mb + command_line_arguments_count);
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		LPWSTR argument_wc = command_line_arguments_wc[argument_index];
		LPSTR argument_mb = command_line_arguments_string_buffer_pos;

		uint32_t mb_buffer_length = mb_buffer_lengths[argument_index];
		uint32_t _mb_buffer_length = static_cast<unsigned long>(wcstombs(argument_mb, argument_wc, mb_buffer_length));
		DEBUG_ASSERT(mb_buffer_length == _mb_buffer_length); // sanity check

		command_line_arguments_mb[argument_index] = command_line_arguments_string_buffer_pos;
		command_line_arguments_string_buffer_pos += mb_buffer_length + 1;
	}

	command_line_arguments = new() s_command_line_argument[command_line_arguments_count];
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		const wchar_t* argument_wc = command_line_arguments_wc[argument_index] + 1;
		const char* argument_mb = command_line_arguments_mb[argument_index] + 1;

		command_line_argument.argument_wc = argument_wc;
		command_line_argument.argument_mb = argument_mb;

		const wchar_t* value_wc = command_line_arguments_wc[argument_index];
		const char* value_mb = command_line_arguments_mb[argument_index];

		while (*value_wc && *value_wc != ':') value_wc++;
		while (*value_mb && *value_mb != ':') value_mb++;

		uint32_t argument_length_wc = static_cast<unsigned long>(value_wc - argument_wc);
		uint32_t argument_length_mb = static_cast<unsigned long>(value_mb - argument_mb);

		if (*value_wc == ':') value_wc++;
		if (*value_mb == ':') value_mb++;

		command_line_argument.value_wc = value_wc;
		command_line_argument.value_mb = value_mb;
		command_line_argument.argument_length_wc = argument_length_wc;
		command_line_argument.argument_length_mb = argument_length_mb;

		debug_point;
	}

	return BCS_S_OK;
}

BCS_RESULT deinit_command_line()
{
	LocalFree(command_line_arguments_mb);
	LocalFree(command_line_arguments_wc);
	delete[] command_line_arguments;

	return BCS_S_OK;
}

BCS_RESULT command_line_get_argument(const char* argument, const char*& value)
{
	BCS_VALIDATE_ARGUMENT(argument);

	uint32_t argument_length = static_cast<unsigned long>(strlen(argument));

	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_mb >= argument_length && strncmp(command_line_argument.argument_mb, argument, command_line_argument.argument_length_mb) == 0)
		{
			value = command_line_argument.value_mb;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_DEBUG_API BCS_RESULT command_line_get_argument_long(const char* argument, int32_t& value)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* string_value;
	if (BCS_FAILED(rs = command_line_get_argument(argument, string_value)))
	{
		return rs;
	}

	size_t string_length = strlen(string_value) + 1;

	if (string_length >= 2 && strnicmp("0x", string_value, 2) == 0)
	{
		value = strtol(string_value + 2, nullptr, 16);
	}
	else
	{
		value = strtol(string_value + 2, nullptr, 10);
	}

	return rs;
}

BCS_DEBUG_API BCS_RESULT command_line_get_argument_longlong(const char* argument, int64_t& value)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* string_value;
	if (BCS_FAILED(rs = command_line_get_argument(argument, string_value)))
	{
		return rs;
	}

	size_t string_length = strlen(string_value) + 1;

	if (string_length >= 2 && strnicmp("0x", string_value, 2) == 0)
	{
		value = strtoll(string_value + 2, nullptr, 16);
	}
	else
	{
		value = strtoll(string_value + 2, nullptr, 10);
	}

	return rs;
}

BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulong(const char* argument, uint32_t& value)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* string_value;
	if (BCS_FAILED(rs = command_line_get_argument(argument, string_value)))
	{
		return rs;
	}

	size_t string_length = strlen(string_value) + 1;

	if (string_length >= 2 && strnicmp("0x", string_value, 2) == 0)
	{
		value = strtoul(string_value + 2, nullptr, 16);
	}
	else
	{
		value = strtoul(string_value, nullptr, 10);
	}

	return rs;
}

BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulonglong(const char* argument, uint64_t& value)
{
	BCS_RESULT rs = BCS_S_OK;
	const char* string_value;
	if (BCS_FAILED(rs = command_line_get_argument(argument, string_value)))
	{
		return rs;
	}

	size_t string_length = strlen(string_value) + 1;

	if (string_length >= 2 && strnicmp("0x", string_value, 2) == 0)
	{
		value = strtoull(string_value + 2, nullptr, 16);
	}
	else
	{
		value = strtoull(string_value + 2, nullptr, 10);
	}

	return rs;
}


BCS_RESULT command_line_get_argument_count(const char* argument, uint32_t& argument_count)
{
	BCS_VALIDATE_ARGUMENT(argument);

	uint32_t argument_length = static_cast<unsigned long>(strlen(argument));

	argument_count = 0;
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_mb >= argument_length && strncmp(command_line_argument.argument_mb, argument, command_line_argument.argument_length_mb) == 0)
		{
			argument_count++;
		}
	}
	return BCS_S_OK;
}

BCS_RESULT command_line_get_arguments(const char* argument, const char** values_buffer, uint32_t& values_buffer_size)
{
	if (values_buffer == nullptr)
	{
		return command_line_get_argument_count(argument, values_buffer_size);
	}

	BCS_VALIDATE_ARGUMENT(argument);
	BCS_VALIDATE_ARGUMENT(*argument);

	uint32_t argument_length = static_cast<unsigned long>(strlen(argument));

	uint32_t argument_buffer_index = 0;
	for (int argument_index = 0; argument_index < command_line_arguments_count && argument_buffer_index < values_buffer_size; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_mb >= argument_length && strncmp(command_line_argument.argument_mb, argument, command_line_argument.argument_length_mb) == 0)
		{
			values_buffer[argument_buffer_index++] = command_line_argument.value_mb;
		}
	}
	values_buffer_size = argument_buffer_index;
	return BCS_S_OK;
}

BCS_RESULT command_line_has_argument(const char* argument)
{
	uint32_t argument_length = static_cast<unsigned long>(strlen(argument));

	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_mb >= argument_length && strncmp(command_line_argument.argument_mb, argument, command_line_argument.argument_length_mb) == 0)
		{
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT command_line_get_argument(const wchar_t* argument, const wchar_t*& value)
{
	BCS_VALIDATE_ARGUMENT(argument);

	uint32_t argument_length = static_cast<unsigned long>(wcslen(argument));

	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_wc >= argument_length && wcsncmp(command_line_argument.argument_wc, argument, command_line_argument.argument_length_wc) == 0)
		{
			value = command_line_argument.value_wc;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT command_line_get_argument_count(const wchar_t* argument, uint32_t& argument_count)
{
	BCS_VALIDATE_ARGUMENT(argument);

	uint32_t argument_length = static_cast<unsigned long>(wcslen(argument));

	argument_count = 0;
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_wc >= argument_length && wcsncmp(command_line_argument.argument_wc, argument, command_line_argument.argument_length_wc) == 0)
		{
			argument_count++;
		}
	}
	return BCS_S_OK;
}

BCS_RESULT command_line_get_arguments(const wchar_t* argument, const wchar_t** values_buffer, uint32_t& values_buffer_size)
{
	if (values_buffer == nullptr)
	{
		return command_line_get_argument_count(argument, values_buffer_size);
	}

	BCS_VALIDATE_ARGUMENT(argument);
	BCS_VALIDATE_ARGUMENT(*argument);

	uint32_t argument_length = static_cast<unsigned long>(wcslen(argument));

	uint32_t argument_buffer_index = 0;
	for (int argument_index = 0; argument_index < command_line_arguments_count && argument_buffer_index < values_buffer_size; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_wc >= argument_length && wcsncmp(command_line_argument.argument_wc, argument, command_line_argument.argument_length_wc) == 0)
		{
			values_buffer[argument_buffer_index++] = command_line_argument.value_wc;
		}
	}
	values_buffer_size = argument_buffer_index;
	return BCS_S_OK;
}

BCS_RESULT command_line_has_argument(const wchar_t* argument)
{
	uint32_t argument_length = static_cast<unsigned long>(wcslen(argument));
	for (int argument_index = 0; argument_index < command_line_arguments_count; argument_index++)
	{
		s_command_line_argument& command_line_argument = command_line_arguments[argument_index];

		if (command_line_argument.argument_length_wc >= argument_length && wcsncmp(command_line_argument.argument_wc, argument, command_line_argument.argument_length_wc) == 0)
		{
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}
