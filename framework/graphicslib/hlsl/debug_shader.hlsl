#include "descriptor_table.hlsli"
#include "cpp_types.hlsli"

ConstantBuffer<r_camera> camera : register(_register_camera);

float4 main(r_ps_input input) : SV_TARGET
{
    return input.color;
}
