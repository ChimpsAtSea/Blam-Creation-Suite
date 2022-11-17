#pragma once

template<typename t_type_ptr>
auto high_level_cast(h_extended_type* extended_type)
{
	using t_type = std::remove_pointer_t<t_type_ptr>;
	if constexpr (std::is_same_v<h_prototype, t_type>)
	{
		if (extended_type->__field_type == _high_level_extended_type_struct)
		{
			return static_cast<h_prototype*>(extended_type);
		}
	}
	else if constexpr (std::is_same_v<h_block, t_type> || std::is_base_of_v<h_block, t_type>)
	{
		if (extended_type->__field_type == _high_level_extended_type_block)
		{
			return static_cast<h_block*>(extended_type);
		}
	}
	return static_cast<t_type*>(nullptr);

	//if constexpr (t_type::k_field_type >= k_number_of_high_level_basic_types)
	//{
	//	if constexpr (std::is_same_v<t_type, h_prototype>)
	//	{
	//		return static_cast<h_prototype*>(extended_type);
	//	}
	//	else
	//	{
	//		if (extended_type->__local_vftable_index == t_type::k_local_vftable_index &&
	//			extended_type->__global_vftable_index == t_type::k_global_vftable_index)
	//		{
	//			return static_cast<t_type*>(extended_type);
	//		}
	//	}
	//}
	//return static_cast<t_type*>(nullptr);
}

template<typename t_type_ptr>
auto high_level_cast(h_type* type)
{
	using t_type = std::remove_pointer_t<t_type_ptr>;

	if constexpr (std::is_same_v<h_string_id_field, t_type>)
	{
		if (type->__field_type == _high_level_extended_type_string_id)
		{
			return static_cast<h_string_id_field*>(type);
		}
	}
	else if (type->__field_type >= k_number_of_high_level_basic_types)
	{
		return high_level_cast<t_type_ptr>(reinterpret_cast<h_extended_type*>(type));
	}
	else if constexpr (std::is_same_v<h_field, t_type>)
	{
		if (type->__field_type < k_number_of_high_level_basic_types)
		{
			return static_cast<h_field*>(type);
		}
	}

	//if (type->__field_type == t_type::k_field_type)
	//{
	//	if (type->__field_type >= k_number_of_high_level_basic_types && t_type::k_is_extended)
	//	{
	//		if constexpr (t_type::k_is_extended)
	//		{
	//			h_extended_type* extended_type = reinterpret_cast<h_extended_type*>(type);
	//			return high_level_cast<t_type_ptr>(extended_type);
	//		}
	//		else
	//		{
	//			return reinterpret_cast<t_type*>(type);
	//		}
	//	}
	//}
	return static_cast<t_type*>(nullptr);
}

#ifdef __INTELLISENSE__
#define _high_level_cast reinterpret_cast
#define high_level_cast _high_level_cast
#endif
