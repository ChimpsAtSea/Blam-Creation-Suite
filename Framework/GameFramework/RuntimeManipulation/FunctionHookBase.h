#pragma once

typedef void(t_function_hook_callback)(void* user_data);

class c_function_hook_base
{
public:
	c_function_hook_base(const char* pName, e_engine_type engine_type, e_build build, size_t offset, find_offset_func find_offset)
		: engine_type(engine_type)
		, build(build)
		, offset(offset)
		, next_function_hook(nullptr)
		, is_active(true)
		, is_hooked(false)
		, name(pName)
		, find_offset_func(find_offset)
		, callback(nullptr)
		, callback_user_data(nullptr)
	{
		if (g_first_function_hook == nullptr)
		{
			g_first_function_hook = this;
			g_last_function_hook = this;
		}
		else
		{
			bool hook_offset_exists = g_last_function_hook->does_offset_exist(engine_type, build, offset);
			ASSERT(hook_offset_exists == false);

			g_last_function_hook->next_function_hook = this;
			g_last_function_hook = this;
		}
	}

	[[nodiscard]] inline e_engine_type get_engine_type() const { return engine_type; };
	[[nodiscard]] inline e_build get_build() const { return build; };
	[[nodiscard]] inline t_function_hook_callback* get_callback() const { return callback; };
	[[nodiscard]] inline void* get_callback_userdata() const { return callback_user_data; };
	[[nodiscard]] inline const char* get_name() const { return name; };

	static void init_function_hook_tree(e_engine_type engine_type, e_build build);
	static void deinit_function_hook_tree(e_engine_type engine_type, e_build build);

public:
	bool is_active;
	bool is_hooked;

protected:

	find_offset_func* find_offset_func;
	uintptr_t offset;
	e_engine_type engine_type;
	e_build build;
	t_function_hook_callback* callback;
	void* callback_user_data;
	const char* name;

	c_function_hook_base* next_function_hook;
	static c_function_hook_base* g_first_function_hook;
	static c_function_hook_base* g_last_function_hook;

	[[nodiscard]] c_function_hook_base* init_node(e_engine_type engine_type, e_build build);
	[[nodiscard]] c_function_hook_base* deinit_node(e_engine_type engine_type, e_build build);

	void set_callback(t_function_hook_callback* callback, void* callback_user_data)
	{
		this->callback = callback;
		this->callback_user_data = callback_user_data;
	}

	bool does_offset_exist(e_engine_type engine_type, e_build build, size_t offset)
	{
		if (engine_type == engine_type)
		{
			if (build == _build_not_set)
			{
				return false;
			}
			if (build == build && offset == offset)
			{
				return true;
			}
		}
		if (next_function_hook)
		{
			return next_function_hook->does_offset_exist(engine_type, build, offset);
		}
		return false;
	}
};

