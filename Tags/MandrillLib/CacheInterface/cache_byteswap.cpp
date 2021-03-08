#include "mandrilllib-private-pch.h"

template<> void byteswap<unsigned char>(unsigned char& value)
{

}

template<> void byteswap<unsigned short>(unsigned short& value)
{
	value = _byteswap_ushort(value);
}

template<> void byteswap<unsigned int>(unsigned int& value)
{
	static_assert(sizeof(value) == sizeof(unsigned long));
	value = _byteswap_ulong(value);
}

template<> void byteswap<unsigned long>(unsigned long& value)
{
	value = _byteswap_ulong(value);
}

template<> void byteswap<unsigned long long>(unsigned long long& value)
{
	value = _byteswap_uint64(value);
}

template<> void byteswap<char>(char& value)
{

}

template<> void byteswap<short>(short& value)
{
	value = static_cast<short>(_byteswap_ushort(static_cast<unsigned short>(value)));
}

template<> void byteswap<long>(long& value)
{
	value = static_cast<long>(_byteswap_ulong(static_cast<unsigned long>(value)));
}

template<> void byteswap<int>(int& value)
{
	static_assert(sizeof(value) == sizeof(long));
	value = _byteswap_ulong(value);
}

template<> void byteswap<long long>(long long& value)
{
	value = static_cast<long long>(_byteswap_uint64(static_cast<unsigned long long>(value)));
}

template<> void byteswap<bool>(bool& value)
{

}

template<> void byteswap<s_basic_buffer32>(s_basic_buffer32& value)
{
	byteswap(value.elements);
	byteswap(value.size);
}

template<> void byteswap<s_tag_reference>(s_tag_reference& value)
{
	byteswap(value.group_tag);
	byteswap(value.name);
	byteswap(value.name_length);
	byteswap(value.datum_index);
}

template<> void byteswap<s_tag_block>(s_tag_block& value)
{
	byteswap(value.count);
	byteswap(value.address);
	byteswap(value.definition_address);
}

template<> void byteswap<float>(float& value)
{
	
}

template<> void byteswap<real_point2d>(real_point2d& value)
{
	byteswap(value.x);
	byteswap(value.y);
}

template<> void byteswap<real_point3d>(real_point3d& value)
{
	byteswap(value.x);
	byteswap(value.y);
	byteswap(value.z);
}

template<> void byteswap<s_point2d>(s_point2d& value)
{
	byteswap(value.x);
	byteswap(value.y);
}

template<> void byteswap<real_quaternion>(real_quaternion& value)
{
	byteswap(value.i);
	byteswap(value.j);
	byteswap(value.k);
	byteswap(value.w);
}

template<> void byteswap<real_vector2d>(real_vector2d& value)
{
	byteswap(value.i);
	byteswap(value.j);
}

template<> void byteswap<real_vector3d>(real_vector3d& value)
{
	byteswap(value.i);
	byteswap(value.j);
	byteswap(value.k);
}

template<> void byteswap<real_vector4d>(real_vector4d& value)
{
	byteswap(value.i);
	byteswap(value.j);
	byteswap(value.k);
	byteswap(value.w);
}

template<> void byteswap<short_bounds>(short_bounds& value)
{
	byteswap(value.lower);
	byteswap(value.upper);
}

template<> void byteswap<angle_bounds>(angle_bounds& value)
{
	byteswap(value.lower);
	byteswap(value.upper);
}

template<> void byteswap<argb_color>(argb_color& value)
{
	byteswap(value.alpha);
	byteswap(value.red);
	byteswap(value.green);
	byteswap(value.blue);
}

template<> void byteswap<real_ahsv_color>(real_ahsv_color& value)
{
	byteswap(value.alpha);
	byteswap(value.hue);
	byteswap(value.saturation);
	byteswap(value.value);
}

template<> void byteswap<real_bounds>(real_bounds& value)
{
	byteswap(value.lower);
	byteswap(value.upper);
}

template<> void byteswap<real_euler_angles2d>(real_euler_angles2d& value)
{
	byteswap(value.yaw);
	byteswap(value.pitch);
}

template<> void byteswap<real_euler_angles3d>(real_euler_angles3d& value)
{
	byteswap(value.yaw);
	byteswap(value.pitch);
	byteswap(value.roll);
}

template<> void byteswap<real_fraction_bounds>(real_fraction_bounds& value)
{
	byteswap(value.lower);
	byteswap(value.upper);
}

template<> void byteswap<real_hsv_color>(real_hsv_color& value)
{
	byteswap(value.hue);
	byteswap(value.saturation);
	byteswap(value.value);
}

template<> void byteswap<real_plane2d>(real_plane2d& value)
{
	byteswap(value.distance);
	byteswap(value.normal);
}

template<> void byteswap<real_plane3d>(real_plane3d& value)
{
	byteswap(value.distance);
	byteswap(value.normal);
}

template<> void byteswap<pixel32>(pixel32& value)
{
	byteswap(value.value);
}

template<> void byteswap<rgb_color>(rgb_color& value)
{
	byteswap(value.red);
	byteswap(value.green);
	byteswap(value.blue);
}

template<> void byteswap<s_rectangle2d>(s_rectangle2d& value)
{
	byteswap(value.top);
	byteswap(value.left);
	byteswap(value.bottom);
	byteswap(value.right);
}
