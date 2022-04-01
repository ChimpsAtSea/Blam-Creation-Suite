#pragma once

class c_runtime_task
{
public:
	BCS_DEBUG_API c_runtime_task();
	BCS_DEBUG_API virtual ~c_runtime_task();

	virtual bool is_running() const = 0;
	virtual float get_runtime_duration() const = 0;
};

