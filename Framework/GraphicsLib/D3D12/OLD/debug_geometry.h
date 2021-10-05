#pragma once

#define DG_DEFAULT_SCALE { 1.0f, 1.0f, 1.0f }
#define DG_DEFAULT_COLOR { 1.0f, 1.0f, 1.0f, 1.0f }

typedef enum
{
	_debug_geometry_type_line,
	_debug_geometry_type_box,
	_debug_geometry_type_sphere,
	_debug_geometry_type_plane,
	_debug_geometry_type_cone,
	_debug_geometry_type_cylinder,
	_debug_geometry_type_mesh

} e_debug_geometry_type;

typedef struct
{
	char debug_geometry_stack[256 * 1024 * 1024];
	char* debug_geometry_stack_end;
	char* debug_geometry_stack_pos;
} s_debug_geometry;

typedef struct
{
	float4x4 transform;
	float4 color;
	float thickness;
} s_debug_geometry_line;

typedef struct
{
	float4x4 transform;
	float4 color;
} s_debug_geometry_box;

typedef struct
{
	float4x4 transform;
	float4 color;
} s_debug_geometry_sphere;

typedef struct
{
	float x, y, z;
	float i, j, k;
} s_debug_geometry_plane;

typedef struct
{
	float x, y, z;
} s_debug_geometry_cone;

typedef struct
{
	float x, y, z;
} s_debug_geometry_cylinder;

typedef struct
{
	void* geometry;
	float4x4 transform;
	float4 color;
} s_debug_geometry_mesh;

typedef struct
{
	e_debug_geometry_type type;
	union
	{
		s_debug_geometry_line line;
		s_debug_geometry_box box;
		s_debug_geometry_sphere sphere;
		s_debug_geometry_plane plane;
		s_debug_geometry_cone cone;
		s_debug_geometry_cylinder cylinder;
		s_debug_geometry_mesh mesh;
	};
} s_debug_geometry_union;

#define debug_push_geometry(t_debug_geometry_type, _debug_geometry_type, debug_geometry, pointer)																	\
{																																									\
	if ((debug_geometry)->debug_geometry_stack_pos + (sizeof(t_debug_geometry_type) + sizeof(e_debug_geometry_type)) < (debug_geometry)->debug_geometry_stack_end)	\
	{																																								\
		t_debug_geometry_type* geometry_type_storage = (t_debug_geometry_type*)(debug_geometry)->debug_geometry_stack_pos;											\
		*geometry_type_storage = *(const t_debug_geometry_type*)(pointer);																							\
		(debug_geometry)->debug_geometry_stack_pos += sizeof(t_debug_geometry_type);																				\
																																									\
		e_debug_geometry_type* debug_geometry_type_storage = (e_debug_geometry_type*)(debug_geometry)->debug_geometry_stack_pos;									\
		*debug_geometry_type_storage = _debug_geometry_type;																										\
		(debug_geometry)->debug_geometry_stack_pos += sizeof(e_debug_geometry_type);																				\
	}																																								\
																																									\
}

#ifdef __INTELLISENSE__
void debug_push_line(s_debug_geometry* debug_geometry, const s_debug_geometry_line* line);
void debug_push_box(s_debug_geometry* debug_geometry, const s_debug_geometry_box* box);
void debug_push_sphere(s_debug_geometry* debug_geometry, const s_debug_geometry_sphere* sphere);
void debug_push_plane(s_debug_geometry* debug_geometry, const s_debug_geometry_plane* plane);
void debug_push_mesh(s_debug_geometry* debug_geometry, const s_debug_geometry_plane* plane);
#else
#define debug_push_line(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_line, _debug_geometry_type_line, debug_geometry, pointer);
#define debug_push_box(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_box, _debug_geometry_type_box, debug_geometry, pointer);
#define debug_push_sphere(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_sphere, _debug_geometry_type_sphere, debug_geometry, pointer);
#define debug_push_plane(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_plane, _debug_geometry_type_plane, debug_geometry, pointer);
#define debug_push_cone(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_cone, _debug_geometry_type_cone, debug_geometry, pointer);
#define debug_push_cylinder(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_cylinder, _debug_geometry_type_cylinder, debug_geometry, pointer);
#define debug_push_mesh(debug_geometry, pointer) debug_push_geometry(s_debug_geometry_mesh, _debug_geometry_type_mesh, debug_geometry, pointer);
#endif

#ifdef __cplusplus
#define DEBUG_GEOMETRY_CALL extern "C"
#else
#define DEBUG_GEOMETRY_CALL
#endif

DEBUG_GEOMETRY_CALL long debug_pop_geometry(s_debug_geometry* debug_geometry, s_debug_geometry_union* const data);
DEBUG_GEOMETRY_CALL long init_debug_geometry(s_debug_geometry* debug_geometry);
