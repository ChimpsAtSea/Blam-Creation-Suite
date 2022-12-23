#pragma once

/* ---------- constants */

constexpr int k_maximum_assert_string_length = 0x400;

/* ---------- types */

struct s_slim_assert_info
{
	// TODO
};

/* ---------- classes */

class __declspec(novtable) c_engine_assert_interface
{
public:
	virtual bool thread_manager_handle_assertion_via_exception() = 0;

	virtual void thread_manager_post_assertion(
		char const *message,
		char const *file,
		int line) = 0;

	virtual void call_fatal_error_callbacks() = 0;

	virtual void generate_stack_walk(
		char const *file) = 0;

	virtual void raise_exception_unhandled(
		char const *message,
		char const *file,
		int line) = 0;

	virtual void raise_exception_handled(
		char const *message,
		char const *file,
		int line) = 0;
};

class c_assert_string
{
private:
	char m_string[k_maximum_assert_string_length];

public:
	c_assert_string(char const *format, ...);

	operator char const *() const;
};

class __declspec(novtable) c_assert_handler
{
public:
	virtual int register_tracked_assert(
		char const *file,
		int line) = 0;

	virtual void log_tracked_assert(
		int handler_index) = 0;

	virtual bool debugger_present() = 0;

	virtual bool handle_assert(
		char const *message,
		char const *file,
		int line) = 0;

	virtual void halt_execution() = 0;

	virtual void handle_slim_assert_constant(
		s_slim_assert_info *info) = 0;

	virtual void handle_slim_assert_dynamic(
		s_slim_assert_info *info,
		c_assert_string &string) = 0;
};

class c_assert_handler_hook final
{
private:
	static c_assert_handler *g_assert_handler;

public:
	c_assert_handler_hook() = delete;

	static void attach_handler(c_assert_handler *handler);
	static void detach_handler(c_assert_handler *handler);

	static bool active();

	static c_assert_handler *get_handler();
};

/* ---------- prototypes/ASSERT_HANDLER_INSTANCE.CPP */

void assert_handler_initialize(
	c_engine_assert_interface *assert_interface);
