#pragma once

struct s_radiance_transfer_geometry_gpu_vertex
{
	float3 position;
	float3 normal;
};

struct s_radiance_transfer_geometry_gpu_runtime_configuration
{
	uint1 num_samples;
};

struct s_radiance_transfer_geometry_gpu_geometry_configuration
{
	uint1 num_vertices;
	uint1 num_coefficient_planes;
	uint1 num_storage_coefficients;
};
