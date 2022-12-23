#include "descriptor_table.hlsli"
#include "cpp_types.hlsli"

ConstantBuffer<r_camera> camera : register(_register_camera);
StructuredBuffer<r_instance> instances : register(_register_model);

r_ps_input main(r_vs_input_ptcn input)
{
    r_ps_input output;

    //r_instance transform = instances.instances[input.instance_id];
    r_instance transform = instances[input.instance_id];

    output.position = float4(input.position, 1.0);
    output.position = mul(float4(input.position, 1.0), mul(transform.transform, camera.view_perspective));
    output.texcoord = input.texcoord;
    output.color = input.color * transform.color;
    //output.normal = normalize(input.normal);
    output.normal = input.normal;

    return output;
}
