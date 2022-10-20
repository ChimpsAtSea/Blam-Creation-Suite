#include "radiance_transfer.hlsli"

typedef BuiltInTriangleIntersectionAttributes Attributes;
struct RayPayload
{
    int value;
};

StructuredBuffer<s_radiance_transfer_geometry_gpu_runtime_configuration> runtime_configuration : register(t0);
StructuredBuffer<float3> sample_directions : register(t1);
StructuredBuffer<float> sample_sh_coefficients : register(t2);
StructuredBuffer<s_radiance_transfer_geometry_gpu_geometry_configuration> geometry_configuration : register(t3);
StructuredBuffer<s_radiance_transfer_geometry_gpu_vertex> vertices : register(t4);
//RaytracingAccelerationStructure acceleration_structure : register(t5);
RaytracingAccelerationStructure acceleration_structure;

RWStructuredBuffer<float> radiance_transfer : register(u0);


#define MAX_COEFFICIENTS 128

[shader("raygeneration")]
void RaygenShader()
{
    uint3 dispatch_rays_index = DispatchRaysIndex();
    uint vertex_index = dispatch_rays_index.x;

    s_radiance_transfer_geometry_gpu_vertex vertex = vertices[vertex_index];

    float sample_scale = 4.0 / (float)runtime_configuration[0].num_samples;
    float coefficients[128];
    for (uint i = 0; i < 128; i++)
    {
        coefficients[i] = 0;
    }

    for (uint sample_index = 0; sample_index < runtime_configuration[0].num_samples; sample_index++)
    {
        float3 sample_direction = sample_directions[sample_index];
        float cosine = dot(vertex.normal, sample_direction);
    
        if (cosine > 0.0)
        {
            bool is_visible = true; // #TODO: Acceleration Structure Ray Test
            if (is_visible)
            {
                uint sample_sh_coefficients_start = sample_index * geometry_configuration[0].num_coefficient_planes;
                for (uint coefficient_index = 0; coefficient_index < geometry_configuration[0].num_coefficient_planes; coefficient_index++)
                {
                    coefficients[coefficient_index] += sample_sh_coefficients[sample_sh_coefficients_start + coefficient_index] * cosine * sample_scale;
                }
            }
        }
    }

    for (uint coefficient_index = 0; coefficient_index < geometry_configuration[0].num_coefficient_planes; coefficient_index++)
    {
        uint storage_index = geometry_configuration[0].num_vertices * coefficient_index + vertex_index;
        radiance_transfer[storage_index] = coefficients[coefficient_index];
    }

    //if (vertex_index == 0)
    //{
    //    RayDesc ray;
    //    ray.Origin = float3(0, 0, 0);
    //    ray.Direction = float3(0, 1, 0);
    //    ray.TMin = 0.001;
    //    ray.TMax = 10000.0;
    //    RayPayload payload = { 'm' };
    //    TraceRay(acceleration_structure, RAY_FLAG_CULL_BACK_FACING_TRIANGLES, ~0, 0, 1, 0, ray, payload);
    //}
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
