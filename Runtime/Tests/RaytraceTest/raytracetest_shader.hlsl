
typedef BuiltInTriangleIntersectionAttributes Attributes;
struct RayPayload
{
    int value;
};

RWStructuredBuffer<uint4> structured_buffer : register(u0);
//RaytracingAccelerationStructure AccelerationStructure;

[shader("raygeneration")]
void RaygenShader()
{
    uint3 dispatch_rays_index = DispatchRaysIndex();

    uint width = 32;
    uint height = 32;

    uint buffer_index = dispatch_rays_index.y * width + dispatch_rays_index.x;

    float3 ray_direction = float3(0, 0, 1);
    float3 ray_origin = (float3)dispatch_rays_index;

    RayDesc ray;
    ray.Origin = ray_origin;
    ray.Direction = ray_direction;
    ray.TMin = 0.001;
    ray.TMax = 10000.0;
    RayPayload payload = { 'm' };
    //TraceRay(AccelerationStructure, RAY_FLAG_CULL_BACK_FACING_TRIANGLES, ~0, 0, 1, 0, ray, payload);

    uint4 result = uint4(dispatch_rays_index.x, dispatch_rays_index.y, buffer_index, payload.value);
    structured_buffer[buffer_index] = result;
}

[shader("closesthit")]
void ClosestHitShader(inout RayPayload payload, in Attributes attr)
{
    payload.value = 'h';
}

[shader("miss")]
void MissShader(inout RayPayload payload)
{
    payload.value = 'm';
}
