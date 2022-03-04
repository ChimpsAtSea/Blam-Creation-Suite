
template<> BCS_DEBUG_API void byteswap_inplace<s_tag_reference>(s_tag_reference& value)
{
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.name);
	byteswap_inplace(value.name_length);
	byteswap_inplace(value.datum_index);
}

template<> BCS_DEBUG_API void byteswap_inplace<s_tag_block>(s_tag_block& value)
{
	byteswap_inplace(value.count);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition_address);
}

template<> BCS_DEBUG_API void byteswap_inplace<s_tag_data>(s_tag_data& value)
{
	byteswap_inplace(value.size);
	byteswap_inplace(value.stream_flags);
	byteswap_inplace(value.stream_offset);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition);
}

template<> BCS_DEBUG_API void byteswap_inplace<s_tag_interop>(s_tag_interop& value)
{
	byteswap_inplace(value.descriptor);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition_address);
}

template<> BCS_DEBUG_API void byteswap_inplace<c_datum_handle>(c_datum_handle& value)
{
	byteswap_inplace(*reinterpret_cast<unsigned long*>(&value));
}

template<> BCS_DEBUG_API void byteswap_inplace<s_tag_resource>(s_tag_resource& value)
{
	byteswap_inplace(value.resource_handle);
	byteswap_inplace(value.definition_address);
}

template<> BCS_DEBUG_API void byteswap_inplace<float>(float& value)
{
	byteswap_inplace(*reinterpret_cast<unsigned long*>(&value));
}

template<> BCS_DEBUG_API void byteswap_inplace<real_point2d>(real_point2d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_point3d>(real_point3d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
	byteswap_inplace(value.z);
}

template<> BCS_DEBUG_API void byteswap_inplace<s_point2d>(s_point2d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_quaternion>(real_quaternion& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
	byteswap_inplace(value.w);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_vector2d>(real_vector2d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_vector3d>(real_vector3d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_vector4d>(real_vector4d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
	byteswap_inplace(value.w);
}

template<> BCS_DEBUG_API void byteswap_inplace<short_bounds>(short_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> BCS_DEBUG_API void byteswap_inplace<angle_bounds>(angle_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> BCS_DEBUG_API void byteswap_inplace<argb_color>(argb_color& value)
{
	byteswap_inplace(value.alpha);
	byteswap_inplace(value.red);
	byteswap_inplace(value.green);
	byteswap_inplace(value.blue);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_ahsv_color>(real_ahsv_color& value)
{
	byteswap_inplace(value.alpha);
	byteswap_inplace(value.hue);
	byteswap_inplace(value.saturation);
	byteswap_inplace(value.value);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_bounds>(real_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_euler_angles2d>(real_euler_angles2d& value)
{
	byteswap_inplace(value.yaw);
	byteswap_inplace(value.pitch);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_euler_angles3d>(real_euler_angles3d& value)
{
	byteswap_inplace(value.yaw);
	byteswap_inplace(value.pitch);
	byteswap_inplace(value.roll);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_fraction_bounds>(real_fraction_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_hsv_color>(real_hsv_color& value)
{
	byteswap_inplace(value.hue);
	byteswap_inplace(value.saturation);
	byteswap_inplace(value.value);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_plane2d>(real_plane2d& value)
{
	byteswap_inplace(value.distance);
	byteswap_inplace(value.normal);
}

template<> BCS_DEBUG_API void byteswap_inplace<real_plane3d>(real_plane3d& value)
{
	byteswap_inplace(value.distance);
	byteswap_inplace(value.normal);
}

template<> BCS_DEBUG_API void byteswap_inplace<pixel32>(pixel32& value)
{
	byteswap_inplace(value.value);
}

template<> BCS_DEBUG_API void byteswap_inplace<rgb_color>(rgb_color& value)
{
	byteswap_inplace(value.red);
	byteswap_inplace(value.green);
	byteswap_inplace(value.blue);
}

template<> BCS_DEBUG_API void byteswap_inplace<s_rectangle2d>(s_rectangle2d& value)
{
	byteswap_inplace(value.top);
	byteswap_inplace(value.left);
	byteswap_inplace(value.bottom);
	byteswap_inplace(value.right);
}

template<> BCS_DEBUG_API void byteswap_inplace<c_old_string_id>(c_old_string_id& value)
{
	byteswap_inplace(value.value);
}

template<> BCS_DEBUG_API void byteswap_inplace<c_tag_resource_fixup>(c_tag_resource_fixup& value)
{
	static_assert(sizeof(c_tag_resource_fixup) == sizeof(unsigned long));
	byteswap_inplace(*reinterpret_cast<unsigned long*>(&value));
}

template<> BCS_DEBUG_API void byteswap_inplace<s_tag_d3d_vertex_buffer>(s_tag_d3d_vertex_buffer& value)
{
	byteswap_inplace(value.data);
}
