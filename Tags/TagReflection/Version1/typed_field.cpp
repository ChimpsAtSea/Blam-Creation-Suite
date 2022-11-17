#include "tagreflection-private-pch.h"

#define typed_field_definition(t_field_type) \
template<> h_typed_field<t_field_type>::h_typed_field() : value() {} \
template<> h_typed_field<t_field_type>::h_typed_field(h_typed_field const& field) : value(field.value) {} \
template<> h_typed_field<t_field_type>::h_typed_field(t_field_type const& _value) : value(_value) {} \
template<> h_typed_field<t_field_type>::~h_typed_field() {}


typed_field_definition(::c_static_string<32>);
typed_field_definition(::c_static_string<256>);
typed_field_definition(::c_fixed_string<32>);
typed_field_definition(::c_fixed_string<256>);
typed_field_definition(string_id);
typed_field_definition(::c_old_string_id);
typed_field_definition(char);
typed_field_definition(short);
typed_field_definition(long);
typed_field_definition(byte);
typed_field_definition(word);
typed_field_definition(dword);
typed_field_definition(int64_t);
typed_field_definition(::s_point2d);
typed_field_definition(::s_rectangle2d);
typed_field_definition(::pixel32);
typed_field_definition(::real);
typed_field_definition(::real_point2d);
typed_field_definition(::real_point3d);
typed_field_definition(::real_vector2d);
typed_field_definition(::real_vector3d);
typed_field_definition(::real_quaternion);
typed_field_definition(::real_euler_angles2d);
typed_field_definition(::real_euler_angles3d);
typed_field_definition(::real_plane2d);
typed_field_definition(::real_plane3d);
typed_field_definition(::rgb_color);
typed_field_definition(::argb_color);
typed_field_definition(::real_hsv_color);
typed_field_definition(::real_ahsv_color);
typed_field_definition(::short_bounds);
typed_field_definition(::angle_bounds);
typed_field_definition(::real_bounds);
typed_field_definition(::real_fraction_bounds);
//typed_field_definition(::s_tag_reference);
//typed_field_definition(::s_tag_block);
//typed_field_definition(::s_tag_data);
//typed_field_definition(::s_tag_d3d_vertex_buffer);
//typed_field_definition(::s_tag_resource);
//typed_field_definition(::s_tag_interop);
//typed_field_definition(::s_tag_reference);
