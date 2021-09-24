#include "graphicslib-private-pch.h"

#pragma optimize("", off)

long debug_pop_geometry(s_debug_geometry* debug_geometry, s_debug_geometry_union* const data)
{
	if (debug_geometry->debug_geometry_stack_pos <= debug_geometry->debug_geometry_stack)
	{
		return 0;
	}

	debug_geometry->debug_geometry_stack_pos -= sizeof(e_debug_geometry_type);
	e_debug_geometry_type const debug_geometry_type = *(e_debug_geometry_type*)debug_geometry->debug_geometry_stack_pos;

	data->type = debug_geometry_type;

	switch (debug_geometry_type)
	{
#define handle_geometry_type(t_debug_geometry_type, _debug_geometry_type, storage)													\
	case _debug_geometry_type:																										\
	{																																\
		debug_geometry->debug_geometry_stack_pos -= sizeof(t_debug_geometry_type);													\
		const t_debug_geometry_type* const line_storage = (const t_debug_geometry_type*)debug_geometry->debug_geometry_stack_pos;	\
		(storage) = *line_storage;																									\
	}																																\
	break;	

		handle_geometry_type(s_debug_geometry_line, _debug_geometry_type_line, data->line);
		handle_geometry_type(s_debug_geometry_box, _debug_geometry_type_box, data->box);
		handle_geometry_type(s_debug_geometry_sphere, _debug_geometry_type_sphere, data->sphere);
		handle_geometry_type(s_debug_geometry_plane, _debug_geometry_type_plane, data->plane);
		handle_geometry_type(s_debug_geometry_cone, _debug_geometry_type_cone, data->cone);
		handle_geometry_type(s_debug_geometry_cylinder, _debug_geometry_type_cylinder, data->cylinder);
		handle_geometry_type(s_debug_geometry_mesh, _debug_geometry_type_mesh, data->mesh);

#undef handle_geometry_type
	}

	// assert(debug_geometry_stack_pos >= debug_geometry_stack);

	return 1;
}

long init_debug_geometry(s_debug_geometry* debug_geometry)
{
	debug_geometry->debug_geometry_stack_end = debug_geometry->debug_geometry_stack + sizeof(debug_geometry->debug_geometry_stack);
	debug_geometry->debug_geometry_stack_pos = debug_geometry->debug_geometry_stack;

	return 0;
}
