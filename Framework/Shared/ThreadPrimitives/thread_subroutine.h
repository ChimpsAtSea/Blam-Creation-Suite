#pragma once

class thread_subroutine_task_impl;
class c_thread_subroutine
{
	friend class thread_subroutine_task_impl;
public:

	template <class _Fx, class... _Types>
	c_thread_subroutine(_Fx&& _Func, _Types&&... _Args) :
		run_count(0),
		subroutine(std::bind(_Func, _Args...))
	{
		ASSERT(this->subroutine.operator bool());
	}

	c_thread_subroutine(std::function<void()>&& subroutine) :
		run_count(0),
		subroutine(subroutine)
	{
		ASSERT(this->subroutine.operator bool());
	}
	
	void run();

	void operator()()
	{
		run();
	}

protected:
	std::atomic<uint32_t> run_count;
	std::function<void()> subroutine;
};

