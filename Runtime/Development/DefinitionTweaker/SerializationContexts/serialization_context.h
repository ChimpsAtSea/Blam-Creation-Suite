#pragma once

class c_serialization_error;

class c_serialization_context
{
public:
	c_serialization_context() = delete;
	c_serialization_context(c_serialization_context const&) = delete;
	c_serialization_context(s_engine_platform_build _engine_platform_build, const void* data_start, const char* name, bool& cache_name);
	c_serialization_context(c_serialization_context& parent_serialization_context, const void* data_start, const char* name, bool& cache_name);
	virtual ~c_serialization_context();

	static constexpr size_t k_target_serialization_error_count = 32;

	virtual BCS_RESULT read() = 0;
	virtual BCS_RESULT traverse() = 0;
	virtual BCS_RESULT calculate_memory() = 0;
	virtual void render_tree() = 0;
	void enqueue_serialization_error(c_serialization_error* serialization_error);
	void render_hover_tooltip();

	template<typename t_serialization_error, typename ...t_args>
	void enqueue_serialization_error(t_args... args)
	{
		c_serialization_error* error = new() t_serialization_error(args...);
		enqueue_serialization_error(error);
	}

	template<typename t_serialization_context>
	t_serialization_context* find_parent_by_type() const
	{
		c_serialization_context* serialization_context = parent_serialization_context;
		if (serialization_context)
		{
			do
			{
				if (t_serialization_context* target_serialization_context = dynamic_cast<t_serialization_context*>(serialization_context))
				{
					return target_serialization_context;
				}
			} while (serialization_context = serialization_context->parent_serialization_context);
		}
		return nullptr;
	}

public:
	c_serialization_context* parent_serialization_context;
	const void* data_start;
	const void* data_end;
	const char* name;
protected:
	c_serialization_error** serialization_errors;
	c_serialization_error** child_serialization_errors;
	c_serialization_error** all_serialization_errors;
	c_atomic_lock mutex;
public:
	s_engine_platform_build engine_platform_build;
	e_serialization_error_type max_serialization_error_type : 4;
	e_serialization_error_type max_local_serialization_error_type : 4;
	bool owns_name_memory;
	unsigned short color_index;
protected:
	unsigned short child_serialization_errors_count;
	unsigned short all_serialization_errors_count;
	unsigned short serialization_errors_count;
	unsigned short serialization_errors_storage_count;
	unsigned short child_serialization_errors_storage_count;
	unsigned short all_serialization_errors_storage_count;
};
static constexpr size_t x = sizeof(c_serialization_context);