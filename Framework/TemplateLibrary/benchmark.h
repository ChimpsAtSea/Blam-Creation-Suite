#pragma once

BCS_DEBUG_API extern unsigned long __benchmark_index;

#define BENCHMARK_START(name) __benchmark_index++; c_stopwatch __benchmark_##name; __benchmark_##name.start()
#define BENCHMARK_GET_TIME(name) static_cast<float>(__benchmark_##name.get_miliseconds())
#define BENCHMARK_STOP(name) \
	__benchmark_index--; \
	console_write("BENCHMARK[" #name "]>"); \
	for (unsigned long indent_index = 0; indent_index < __benchmark_index; indent_index++) console_write(">"); \
	console_write_line(" %fms", static_cast<float>(__benchmark_##name.stop(), __benchmark_##name.get_miliseconds()))

#define BENCHMARK_ACCUMULATOR_BEGIN(name) __benchmark_index++; float __benchmark_##name_accumulator = 0.0f
#define BENCHMARK_ACCUMULATOR_START(name) c_stopwatch __benchmark_##name; __benchmark_##name.start()
#define BENCHMARK_ACCUMULATOR_STOP(name) __benchmark_##name_accumulator += static_cast<float>(__benchmark_##name.stop(), __benchmark_##name.get_miliseconds())
#define BENCHMARK_ACCUMULATOR_END(name) \
	__benchmark_index--; \
	console_write("BENCHMARK[" #name "]>"); \
	for (unsigned long indent_index = 0; indent_index < __benchmark_index; indent_index++) console_write(">"); \
	console_write_line(" %fms", __benchmark_##name_accumulator)
