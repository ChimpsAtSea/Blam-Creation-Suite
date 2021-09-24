#pragma once

template<typename T, size_t N>
static constexpr T compile_time_accumulator(T(&A)[N], int const i = 0)
{
	return (i < N) ? A[i] + compile_time_accumulator(A, i + 1) : T(0);
}
