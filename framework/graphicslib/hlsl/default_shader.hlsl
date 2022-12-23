#include "descriptor_table.hlsli"
#include "cpp_types.hlsli"

ConstantBuffer<r_camera> camera : register(_register_camera);

float4 main(r_ps_input input) : SV_TARGET
{
    float3 nor = normalize(input.normal.xyz);

    float dif = clamp(dot(nor, float3(0.57703, 0.57703, 0.57703)), 0.0, 1.0);
    float amb = 0.5 + 0.5 * dot(nor, float3(0.0, 0.0, 1.0));
    float3 col = float3(0.2, 0.3, 0.4) * amb + float3(0.85, 0.75, 0.65) * dif;

    return float4(nor, 1.0);
}
