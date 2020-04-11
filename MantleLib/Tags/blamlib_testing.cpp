#ifndef __mantle_reflect__

#include "mantlelib-private-pch.h"


struct s_reflection_structure_type_legacy;
template<typename T>
const s_reflection_structure_type_legacy& reflection_structure_legacy();


extern void register_tag(unsigned int group, const s_reflection_structure_type_legacy& tag_reflection);

void register_blamlib_types()
{

	register_tag(k_render_method_group_tag, reflection_structure_legacy<c_render_method>());
	register_tag(k_render_method_group_tag, reflection_structure_legacy<c_render_method_shader>());

}

#endif
