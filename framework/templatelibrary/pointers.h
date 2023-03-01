#pragma once

#ifdef __cplusplus

#ifndef __INTELLISENSE
namespace next_contiguous_pointer
{
	template <typename _Ty>
	struct t_next_contiguous_pointer_remove_const
	{
		using type2 = _Ty;
	};

	template <typename _Ty>
	struct t_next_contiguous_pointer_remove_const<const _Ty>
	{
		using type2 = _Ty;
	};

	template <typename t_target, typename t_source>
	struct t_next_contiguous_pointer
	{
		using type = t_source;
	};

	template <typename t_target, typename t_source>
	struct t_next_contiguous_pointer<t_target, t_source*>
	{
		using type = typename t_next_contiguous_pointer_remove_const<t_target>::type2*;
	};

	template <typename t_target, typename t_source>
	struct t_next_contiguous_pointer<t_target, const t_source*>
	{
		using type = typename t_next_contiguous_pointer_remove_const<t_target>::type2 const*;
	};
}
#endif

#define next_contiguous_pointer(t_type, source) reinterpret_cast<next_contiguous_pointer::t_next_contiguous_pointer<t_type, decltype(source)>::type>(source + 1)

#else

#define next_contigious_pointer(t_type, source) (t_type*)(source + 1)

#endif
