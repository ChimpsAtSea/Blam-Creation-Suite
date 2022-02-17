#pragma once

template<typename TCast, typename TSource>
TCast* next_contiguous_pointer(TSource* source)
{
	return reinterpret_cast<TCast*>(source + 1);
}

template<typename TCast, typename TSource>
const TCast* next_contiguous_pointer(const TSource* source)
{
	return reinterpret_cast<const TCast*>(source + 1);
}

template<typename TSource>
TSource* next_contiguous_pointer(TSource* source)
{
	return source + 1;
}
