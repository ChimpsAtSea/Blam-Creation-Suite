#include "geometrylib-private-pch.h"

// #TODO: Find a home for these
#define dot(a, b) ( (a).x * (b).x + (a).y * (b).y + (a).z * (b).z )
#define cross(v1, v2) float3{ (v1).y * (v2).z - (v1).z * (v2).y, (v1).z * (v2).x - (v1).x * (v2).z, (v1).x * (v2).y - (v1).y * (v2).x }
static float3 operator-(const float3& a, const float3& b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }

c_radiance_transfer_engine_cpu::c_radiance_transfer_engine_cpu(
	unsigned int _order, 
	unsigned short _resolution, 
	bool _use_shadows, 
	bool _calculate_subsurface) :
	c_radiance_transfer_engine(),
	geometry_meshes(),
	num_geometry_meshes(),
	geometries(),
	num_geometries(),
	order(_order),
	resolution(_resolution),
	num_coefficient_planes((order + 1)* (order + 1)),
	use_shadows(_use_shadows),
	calculate_subsurface(_calculate_subsurface),
	samples(nullptr),
	num_samples(resolution* resolution),
	sample_sh_coefficients(nullptr),
	num_sample_sh_coefficients(num_samples* num_coefficient_planes),
	spherical_harmonic_evaluation()
{
	init_samples();
}

c_radiance_transfer_engine_cpu::~c_radiance_transfer_engine_cpu()
{
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_cpu& geometry = geometries[geometry_index];
		trivial_free(geometry.surface_coefficient_planes);
		trivial_free(geometry.subsurface_coefficient_planes);
		trivial_free(geometry.coefficients);
	}

	trivial_free(geometry_meshes);
	trivial_free(geometries);

	deinit_samples();
}

void c_radiance_transfer_engine_cpu::init_samples()
{
	switch (order)
	{
	case 0:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order0;
		break;
	case 1:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order1;
		break;
	case 2:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order2;
		break;
	default:
		throw BCS_E_UNSUPPORTED;
	}

	sample_sh_coefficients = trivial_malloc(float, num_sample_sh_coefficients);
	samples = trivial_malloc(float3, num_samples);

	float* sample_sh_coefficients_position = sample_sh_coefficients;
	float3* samples_position = samples;

	unsigned int seed = 0;
	for (unsigned int i = 0; i < resolution; i++)
	{
		for (unsigned int j = 0; j < resolution; j++)
		{
			int k = i * resolution + j;
			float3& sample = *samples_position;
			float* _sample_sh_coefficients = sample_sh_coefficients_position;

			float r0 = float(xorshift32(seed)) / UINT_MAX;
			float r1 = float(xorshift32(seed)) / UINT_MAX;

			float a = ((float)i + r0) / (float)resolution;
			float b = ((float)j + r1) / (float)resolution;
			float z = 1.0 - 2.0 * a;
			float r = sqrt(max(0.0, 1.0 - z * z));
			float phi = 2.0 * PI * b;

			float x = r * cos(phi);
			float y = r * sin(phi);

			sample = { x, y, z };
			spherical_harmonic_evaluation(x, y, z, _sample_sh_coefficients);

			samples_position++;
			sample_sh_coefficients_position += num_coefficient_planes;
		}
	}
}

void c_radiance_transfer_engine_cpu::deinit_samples()
{
	trivial_free(samples);
	trivial_free(sample_sh_coefficients);
}

BCS_RESULT c_radiance_transfer_engine_cpu::add_mesh(c_geometry_mesh& geometry_mesh)
{
	// check if already queued
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_geometry_meshes; geometry_mesh_index++)
	{
		if (geometry_meshes[geometry_mesh_index] == &geometry_mesh)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
	}

	// check if already baked
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		if (geometries[geometry_index].geometry_mesh == &geometry_mesh)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
	}

	unsigned int geometry_mesh_index = num_geometry_meshes++;
	geometry_meshes = trivial_realloc(c_geometry_mesh*, geometry_meshes, num_geometry_meshes);
	geometry_meshes[geometry_mesh_index] = &geometry_mesh;

	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_cpu::bake()
{
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_geometry_meshes; geometry_mesh_index++)
	{
		c_geometry_mesh& geometry_mesh = *geometry_meshes[geometry_mesh_index];

		unsigned int geometry_index = num_geometries++;
		geometries = trivial_realloc(c_radiance_transfer_geometry_cpu, geometries, num_geometries);
		c_radiance_transfer_geometry_cpu& geometry = geometries[geometry_index] = {};

		geometry.geometry_mesh = &geometry_mesh;
		geometry.radiance_transfer_engine = this;
		geometry.indices = geometry_mesh.get_mesh_indices_uint();
		geometry.num_triangles = geometry_mesh.get_face_count();
		geometry.vertices = geometry_mesh.get_positions();
		geometry.normals = geometry_mesh.get_normals();
		geometry.num_vertices = geometry_mesh.get_vertex_count();
		geometry.surface_coefficient_planes = trivial_malloc(float*, num_coefficient_planes);
		geometry.subsurface_coefficient_planes = nullptr;

		unsigned int num_storage_coefficients = geometry.num_vertices * num_coefficient_planes;
		if (calculate_subsurface)
		{
			geometry.subsurface_coefficient_planes = trivial_malloc(float*, num_coefficient_planes);
			num_storage_coefficients += num_storage_coefficients;
		}

		geometry.coefficients = trivial_malloc(float, num_storage_coefficients);
		memset(geometry.coefficients, 0, sizeof(float) * num_storage_coefficients);
		
		float* coefficients_position = geometry.coefficients;
		for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
		{
			geometry.surface_coefficient_planes[coefficient_plane_index] = coefficients_position;
			coefficients_position += geometry.num_vertices;
			if (calculate_subsurface)
			{
				geometry.subsurface_coefficient_planes[coefficient_plane_index] = coefficients_position;
				coefficients_position += geometry.num_vertices;
			}
		}

		parallel_invoke(0, geometry.num_vertices, calculate_spherical_harmonic_coefficient_callback, &geometry);
	}

	trivial_free(geometry_meshes);
	geometry_meshes = 0;
	num_geometry_meshes = 0;

	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_cpu::read(
	c_geometry_mesh& geometry_mesh,
	const float* const*& out_surface_coefficient_planes,
	const float* const*& out_subsurface_coefficient_planes,
	unsigned int& out_num_coefficient_planes)
{
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_cpu& geometry = geometries[geometry_index];
		if (geometry.geometry_mesh == &geometry_mesh)
		{
			out_surface_coefficient_planes = geometry.surface_coefficient_planes;
			out_subsurface_coefficient_planes = geometry.subsurface_coefficient_planes;
			out_num_coefficient_planes = num_coefficient_planes;

			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

bool c_radiance_transfer_engine_cpu::ray_intersects_triangle(c_radiance_transfer_geometry_cpu const& geometry, int face_index, const float3& ray_origin, const float3& ray_direction)
{
	int indice_index = face_index * 3;
	const float3& vertex0 = geometry.vertices[geometry.indices[indice_index++]];
	const float3& vertex1 = geometry.vertices[geometry.indices[indice_index++]];
	const float3& vertex2 = geometry.vertices[geometry.indices[indice_index++]];

	constexpr float k_epsilon = 0.0000001f;

	const float3 edge1 = vertex1 - vertex0;
	const float3 edge2 = vertex2 - vertex0;
	const float3 h = cross(ray_direction, edge2);
	const float a = dot(edge1, h);
	if (a > -k_epsilon && a < k_epsilon)
	{
		// This ray is parallel to this triangle.
		return false;
	}

	const float f = 1.0 / a;
	const float3 s = ray_origin - vertex0;
	const float u = f * dot(s, h);
	if (u < 0.0 || u > 1.0)
	{
		return false;
	}

	float3 q = cross(s, edge1);
	float v = f * dot(ray_direction, q);
	if (v < 0.0 || u + v > 1.0)
	{
		return false;
	}

	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * dot(edge2, q);
	if (t > k_epsilon) // ray intersection
	{
		//outIntersectionPoint = rayOrigin + rayVector * t;
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
	{
		return false;
	}
}

bool c_radiance_transfer_engine_cpu::ray_intersection_test(
	c_radiance_transfer_geometry_cpu const& geometry,
	int vertex_index,
	const float3& ray_direction)
{
	bool visible = true;

	const float3& vertex_origin = geometry.vertices[vertex_index];
	for (unsigned int face_index = 0; face_index < geometry.num_triangles; face_index++)
	{
		unsigned int index_a = geometry.indices[face_index * 3];
		if (index_a == vertex_index)
		{
			continue;
		}

		unsigned int index_b = geometry.indices[face_index * 3 + 1];
		if (index_b == vertex_index)
		{
			continue;
		}

		unsigned int index_c = geometry.indices[face_index * 3 + 2];
		if (index_c == vertex_index)
		{
			continue;
		}

		const float3& vertex0 = geometry.vertices[index_a];
		const float3& vertex1 = geometry.vertices[index_b];
		const float3& vertex2 = geometry.vertices[index_c];


		visible = !ray_intersects_triangle(geometry, face_index, vertex_origin, ray_direction);
		if (!visible)
			break;
	}
	return(visible);
}

void c_radiance_transfer_engine_cpu::calculate_spherical_harmonic_coefficient_callback(void* _geometry, uint32_t vertex_index)
{
	c_radiance_transfer_geometry_cpu const& geometry = *static_cast<c_radiance_transfer_geometry_cpu*>(_geometry);
	c_radiance_transfer_engine_cpu const& radiance_transfer_engine = *geometry.radiance_transfer_engine;
	radiance_transfer_engine.calculate_spherical_harmonic_coefficient(geometry, vertex_index);
}

void c_radiance_transfer_engine_cpu::calculate_spherical_harmonic_coefficient(c_radiance_transfer_geometry_cpu const& geometry, uint32_t vertex_index) const
{
	for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
	{
		geometry.surface_coefficient_planes[coefficient_plane_index][vertex_index] = 0.0f;

		if (calculate_subsurface)
		{
			geometry.subsurface_coefficient_planes[coefficient_plane_index][vertex_index] = 0.0f;
		}
	}

	float3* sample_position = samples;
	float* sample_sh_coefficients_position = sample_sh_coefficients;
	const float3& normal = geometry.normals[vertex_index];

	for (unsigned int sample_index = 0; sample_index < num_samples; sample_index++)
	{
		float cosine_term = dot(normal, *sample_position);
		if (cosine_term > 0.0f)
		{
			if (!use_shadows || ray_intersection_test(geometry, vertex_index, *sample_position))
			{
				for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
				{
					float sample_sh_coefficient = sample_sh_coefficients_position[coefficient_plane_index];
					geometry.surface_coefficient_planes[coefficient_plane_index][vertex_index] += sample_sh_coefficient * cosine_term;
				}
			}
		}
		else if (calculate_subsurface)
		{
			if (!use_shadows || ray_intersection_test(geometry, vertex_index, *sample_position))
			{
				for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
				{
					float sample_sh_coefficient = sample_sh_coefficients_position[coefficient_plane_index];
					geometry.subsurface_coefficient_planes[coefficient_plane_index][vertex_index] += sample_sh_coefficient * -cosine_term;
				}
			}
		}

		sample_position++;
		sample_sh_coefficients_position += num_coefficient_planes;
	}

	float scale = 4.0f / num_samples;
	for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
	{
		geometry.surface_coefficient_planes[coefficient_plane_index][vertex_index] *= scale;

		if (calculate_subsurface)
		{
			geometry.subsurface_coefficient_planes[coefficient_plane_index][vertex_index] *= scale;
		}
	}
}
