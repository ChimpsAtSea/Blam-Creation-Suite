#include "generic_infinite_shader.hlsli"

StructuredBuffer<r_camera_d3d12> cameras : register(t0);
StructuredBuffer<r_render_instance_d3d12> instances : register(t1);

r_ps_input main(r_vs_input_ptcn input)
{
    r_ps_input output;

    r_render_instance_d3d12 instance = instances[input.instance_id];
    r_camera_d3d12 camera = cameras[0];

    output.position = float4(input.position, 1.0);
    output.position = mul(float4(input.position, 1.0), mul(instance.transform, camera.view_perspective));
    output.texcoord = input.texcoord;
    output.color = input.color * instance.color;
    //output.normal = normalize(input.normal);
    output.normal = input.normal;

    return output;
}
