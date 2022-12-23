

template<> inline void byteswap_inplace(s_tag_reference& value)
{
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.name);
	byteswap_inplace(value.name_length);
	byteswap_inplace(value.datum_index);
}

template<> inline void byteswap_inplace(s_tag_block& value)
{
	byteswap_inplace(value.count);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition_address);
}

template<> inline void byteswap_inplace(s_tag_data& value)
{
	byteswap_inplace(value.size);
	byteswap_inplace(value.stream_flags);
	byteswap_inplace(value.stream_offset);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition);
}

template<> inline void byteswap_inplace(s_tag_interop& value)
{
	byteswap_inplace(value.descriptor);
	byteswap_inplace(value.address);
	byteswap_inplace(value.definition_address);
}

template<> inline void byteswap_inplace(c_datum_handle& value)
{
	byteswap_inplace(*reinterpret_cast<uint32_t*>(&value));
}

template<> inline void byteswap_inplace(s_tag_resource& value)
{
	byteswap_inplace(value.resource_handle);
	byteswap_inplace(value.definition_address);
}

template<> inline void byteswap_inplace(real& value)
{
	byteswap_inplace(*reinterpret_cast<uint32_t*>(&value));
}

template<> inline void byteswap_inplace(real_point2d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
}

template<> inline void byteswap_inplace(real_point3d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
	byteswap_inplace(value.z);
}

template<> inline void byteswap_inplace(s_point2d& value)
{
	byteswap_inplace(value.x);
	byteswap_inplace(value.y);
}

template<> inline void byteswap_inplace(real_quaternion& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
	byteswap_inplace(value.w);
}

template<> inline void byteswap_inplace(real_vector2d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
}

template<> inline void byteswap_inplace(real_vector3d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
}

template<> inline void byteswap_inplace(real_vector4d& value)
{
	byteswap_inplace(value.i);
	byteswap_inplace(value.j);
	byteswap_inplace(value.k);
	byteswap_inplace(value.w);
}

template<> inline void byteswap_inplace(short_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> inline void byteswap_inplace(angle_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> inline void byteswap_inplace(argb_color& value)
{
	byteswap_inplace(value.alpha);
	byteswap_inplace(value.red);
	byteswap_inplace(value.green);
	byteswap_inplace(value.blue);
}

template<> inline void byteswap_inplace(real_ahsv_color& value)
{
	byteswap_inplace(value.alpha);
	byteswap_inplace(value.hue);
	byteswap_inplace(value.saturation);
	byteswap_inplace(value.value);
}

template<> inline void byteswap_inplace(real_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> inline void byteswap_inplace(real_euler_angles2d& value)
{
	byteswap_inplace(value.yaw);
	byteswap_inplace(value.pitch);
}

template<> inline void byteswap_inplace(real_euler_angles3d& value)
{
	byteswap_inplace(value.yaw);
	byteswap_inplace(value.pitch);
	byteswap_inplace(value.roll);
}

template<> inline void byteswap_inplace(real_fraction_bounds& value)
{
	byteswap_inplace(value.lower);
	byteswap_inplace(value.upper);
}

template<> inline void byteswap_inplace(real_hsv_color& value)
{
	byteswap_inplace(value.hue);
	byteswap_inplace(value.saturation);
	byteswap_inplace(value.value);
}

template<> inline void byteswap_inplace(real_plane2d& value)
{
	byteswap_inplace(value.distance);
	byteswap_inplace(value.normal);
}

template<> inline void byteswap_inplace(real_plane3d& value)
{
	byteswap_inplace(value.distance);
	byteswap_inplace(value.normal);
}

template<> inline void byteswap_inplace(pixel32& value)
{
	byteswap_inplace(value.value);
}

template<> inline void byteswap_inplace(rgb_color& value)
{
	byteswap_inplace(value.red);
	byteswap_inplace(value.green);
	byteswap_inplace(value.blue);
}

template<> inline void byteswap_inplace(s_rectangle2d& value)
{
	byteswap_inplace(value.top);
	byteswap_inplace(value.left);
	byteswap_inplace(value.bottom);
	byteswap_inplace(value.right);
}

template<> inline void byteswap_inplace(c_old_string_id& value)
{
	byteswap_inplace(value.value);
}

template<> inline void byteswap_inplace(c_tag_resource_fixup& value)
{
	static_assert(sizeof(c_tag_resource_fixup) == sizeof(unsigned long));
	byteswap_inplace(*reinterpret_cast<uint32_t*>(&value));
}

template<> inline void byteswap_inplace(s_tag_d3d_vertex_buffer& value)
{
	byteswap_inplace(value.type);
	byteswap_inplace(value.stride);
	byteswap_inplace(value.count);
	byteswap_inplace(value.actual_vertex_offset_bytes);
	byteswap_inplace(value.default_vertex_offset_bytes);
	byteswap_inplace(value.unknownC);
	byteswap_inplace(value.unknown10);
	byteswap_inplace(value.hardware_format);
	byteswap_inplace(value.unknown18);
	byteswap_inplace(value.unknown1C);
}
