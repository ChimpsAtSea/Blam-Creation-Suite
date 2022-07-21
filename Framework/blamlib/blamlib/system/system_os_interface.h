#pragma once

/* ---------- types */

enum class e_application_exit_code
{
	exit
};

struct s_operating_system_version
{
	// TODO
};

typedef void (*t_system_exit_function)();
typedef void (*t_system_halt_function)();

/* ---------- prototypes */

void system_register_exit_function(
	t_system_exit_function exit_function);

void system_exit_application(
	e_application_exit_code exit_code);

bool system_get_operating_system_version(
	s_operating_system_version *out_version);

int system_execute_command(
	char const *command);

void system_register_halt_function(
	t_system_halt_function halt_function);

t_system_halt_function system_get_halt_function();
