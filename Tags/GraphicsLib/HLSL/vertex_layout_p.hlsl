#include "descriptor_table.hlsli"
#include "cpp_types.hlsli"

ConstantBuffer<r_camera> camera : register(_register_camera);
StructuredBuffer<r_instance> instances : register(_register_model);

r_ps_input main(r_vs_input_p input)
{
    r_ps_input output;

    //r_instance transform = instances.instances[input.instance_id];
    r_instance transform = instances[input.instance_id];

    output.position = float4(input.position, 1.0);
    output.position = mul(float4(input.position, 1.0), mul(transform.transform, camera.view_perspective));
    output.texcoord = float2(0.0, 0.0);
    output.color = transform.color;
    output.normal = float3(0.0, 1.0, 1.0);

    return output;
}
