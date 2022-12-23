#ifdef __cplusplus
#define semantic(...)

#define precise
#define _register_camera 0
#define _register_model 1
#define _register_instance 2

#else
#define semantic(_semantic) : _semantic

#define _register_camera b0
#define _register_model t0, space0
#define _register_instance b2

#endif

struct r_vs_input_p
{
	float3 position semantic(POSITION);
#ifndef __cplusplus
	uint instance_id : SV_InstanceID;
#endif
};

struct r_vs_input_pc
{
	float3 position semantic(POSITION);
	float4 color semantic(COLOR);
#ifndef __cplusplus
	uint instance_id : SV_InstanceID;
#endif
};

struct r_vs_input_ptcn
{
	float3 position semantic(POSITION);
	precise float2 texcoord semantic(TEXCOORD);
	float4 color semantic(COLOR);
	float3 normal semantic(NORMAL);
#ifndef __cplusplus
	uint instance_id : SV_InstanceID;
#endif
};

struct r_ps_input
{
	float4 position semantic(SV_POSITION);
	precise float2 texcoord semantic(TEXCOORD0);
	precise float3 ray_direction semantic(TEXCOORD1);
	precise float3 ray_origin semantic(TEXCOORD2);
	precise float3 world_position semantic(TEXCOORD3);
	float4 color semantic(COLOR);
	float3 normal semantic(NORMAL);
#ifndef __cplusplus
	uint instance_id : SV_InstanceID;
#endif
};

struct r_camera
{
	float4x4 view_perspective;
	float4x4 view_perspective_transposed;
	float4x4 inverse_view_perspective;
	float4x4 perspective_transposed;
	float4x4 view_transposed;
	float4x4 perspective;
	float4x4 view;
	float4 position;
	float4 view_position;
	float2 feedback_scan_offset;
	float near_distance;
	float far_distance;
	int feedback_scan_offset_mask;
	int frame_index;
};

struct r_model
{
	float4 vertex_scale;
	float4 vertex_translate;
};

struct r_instance
{
	float4 color;
	float4x4 transform;
};

struct r_instances
{
	r_instance instances[2];
};

#undef semantic
