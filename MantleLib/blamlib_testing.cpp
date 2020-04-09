#include "mantlelib-private-pch.h"


struct s_reflection_structure_type;
template<typename T>
const s_reflection_structure_type& runtime_structure_reflection();


extern void register_tag(unsigned int group, const s_reflection_structure_type& tag_reflection);

void register_blamlib_types()
{

	register_tag(k_render_method_group_tag, runtime_structure_reflection<c_render_method>());
	register_tag(k_render_method_group_tag, runtime_structure_reflection<c_render_method_shader>());

}
