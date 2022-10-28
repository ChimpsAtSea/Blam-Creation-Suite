#pragma once

class c_serialization_error;

class c_serialization_context
{
public:
	c_serialization_context() = delete;
	c_serialization_context(c_serialization_context const&) = delete;
	c_serialization_context(s_engine_platform_build _engine_platform_build);
	c_serialization_context(c_serialization_context& parent_serialization_context);
	~c_serialization_context();

	static constexpr size_t k_target_serialization_error_count = 32;

	virtual void read() = 0;
	virtual void traverse() = 0;
	virtual void render_tree() = 0;
	void enqueue_serialization_error(c_serialization_error* serialization_error);
	void render_hover_tooltip();

	template<typename t_serialization_error, typename ...t_args>
	void enqueue_serialization_error(t_args... args)
	{
		c_serialization_error* error = new t_serialization_error(args...);
		enqueue_serialization_error(error);
	}

	s_engine_platform_build engine_platform_build;
	e_serialization_error_type max_serialization_error_type;
protected:
	c_serialization_context* parent_serialization_context;

	unsigned int serialization_errors_count;
	unsigned int child_serialization_errors_count;
	unsigned int all_serialization_errors_count;
	unsigned int serialization_errors_storage_count;
	unsigned int child_serialization_errors_storage_count;
	unsigned int all_serialization_errors_storage_count;
	c_serialization_error** serialization_errors;
	c_serialization_error** child_serialization_errors;
	c_serialization_error** all_serialization_errors;
};
