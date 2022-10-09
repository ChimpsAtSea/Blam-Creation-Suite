#include "geometrylib-private-pch.h"

// #TODO: Make a home for these

#define dot(a, b) ( (a).x * (b).x + (a).y * (b).y + (a).z * (b).z )
#define cross(v1, v2) float3{ (v1).y * (v2).z - (v1).z * (v2).y, (v1).z * (v2).x - (v1).x * (v2).z, (v1).x * (v2).y - (v1).y * (v2).x }
#define PI 3.14159265359
float3 operator-(const float3& a, const float3& b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

// order 0
void SHEval0(const float fX, const float fY, const float fZ, float* pSH)
{
	pSH[0] = 0.2820947917738781f;
}

// order 1
void SHEval1(const float fX, const float fY, const float fZ, float* pSH)
{
	float fC0, fC1, fS0, fS1, fTmpA, fTmpB, fTmpC;

	pSH[0] = 0.2820947917738781f;
	pSH[2] = 0.4886025119029199f * fZ;
	fC0 = fX;
	fS0 = fY;

	fTmpB = -0.48860251190292f;
	pSH[3] = fTmpB * fC0;
	pSH[1] = fTmpB * fS0;
}

// order 2
void SHEval2(const float fX, const float fY, const float fZ, float* pSH)
{
	float fC0, fC1, fS0, fS1, fTmpA, fTmpB, fTmpC;
	float fZ2 = fZ * fZ;

	pSH[0] = 0.2820947917738781f;
	pSH[2] = 0.4886025119029199f * fZ;
	pSH[6] = 0.9461746957575601f * fZ2 + -0.31539156525252f;
	fC0 = fX;
	fS0 = fY;

	fTmpA = -0.48860251190292f;
	pSH[3] = fTmpA * fC0;
	pSH[1] = fTmpA * fS0;
	fTmpB = -1.092548430592079f * fZ;
	pSH[7] = fTmpB * fC0;
	pSH[5] = fTmpB * fS0;
	fC1 = fX * fC0 - fY * fS0;
	fS1 = fX * fS0 + fY * fC0;

	fTmpC = 0.5462742152960395f;
	pSH[8] = fTmpC * fC1;
	pSH[4] = fTmpC * fS1;
}

struct s_triangle_indices
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
};

struct s_triangle_precompute
{
	float3 v0v1;
	float3 v0v2;
};

struct s_sh_baker_sample
{
	//float2 spherical_coord;
	float3 cartesian_coord;
	float* sh_functions;
};

struct s_sh_baker
{
	unsigned int order;
	unsigned int bands;
	unsigned int bands2;

	unsigned int num_triangles;
	const s_triangle_indices* triangles;
	s_triangle_precompute* triangle_precompute;

	unsigned int num_vertices;
	const float3* vertices;
	const float3* normals;

	s_sh_baker_sample* samples;
	int num_samples;

	void (*SHEval)(const float fX, const float fY, const float fZ, float* pSH);

	float3** coefficients;
};

BCS_RESULT create_sh_baker_cpu(h_sh_baker& sh_baker_handle, unsigned int order)
{
	s_sh_baker* sh_baker = new() s_sh_baker();
	if (sh_baker == nullptr)
	{
		return BCS_E_OUT_OF_MEMORY;
	}

	sh_baker->order = order;
	switch(order)
	{
	case 0:
		sh_baker->SHEval = SHEval0;
		sh_baker->bands = 1;
		break;
	case 1:
		sh_baker->SHEval = SHEval1;
		sh_baker->bands = 2;
		break;
	case 2:
		sh_baker->SHEval = SHEval2;
		sh_baker->bands = 3;
		break;
		}
	sh_baker->bands2 = sh_baker->bands * sh_baker->bands;

	sh_baker_handle = sh_baker;

	return BCS_S_OK;
}

float sh_project_random()
{
	float random = (float)(rand() % 1000) / 1000.0f;
	return(random);
}

void sh_project_generate_samples(s_sh_baker& sh_baker, int resolution)
{
	s_sh_baker_sample* samples = new s_sh_baker_sample[resolution * resolution];
	sh_baker.samples = samples;
	sh_baker.num_samples = resolution * resolution;
	for (unsigned int i = 0; i < resolution; i++)
	{
		for (unsigned int j = 0; j < resolution; j++)
		{
			float a = ((float)i + sh_project_random()) / (float)resolution;
			float b = ((float)j + sh_project_random()) / (float)resolution;

			float z = 1.0 - 2.0 * a;
			float r = sqrt(max(0.0, 1.0 - z * z));
			float phi = 2.0 * PI * b;
			int k = i * resolution + j;

			float3 cartesian_coord = float3{ r * cos(phi), r * sin(phi), z };
			float* sh_functions = new float[sh_baker.bands2];
			sh_baker.SHEval(cartesian_coord.x, cartesian_coord.y, cartesian_coord.z, sh_functions);

			sh_baker.samples[k].cartesian_coord = cartesian_coord;
			sh_baker.samples[k].sh_functions = sh_functions;
		}
	}
};

bool ray_intersects_triangle(s_sh_baker& sh_baker, int face_index, const float3& orig, const float3& dir)
{
	const s_triangle_indices& triangle = sh_baker.triangles[face_index];
	const float3& vertex0 = sh_baker.vertices[triangle.a];
	const float3& vertex1 = sh_baker.vertices[triangle.b];
	const float3& vertex2 = sh_baker.vertices[triangle.c];

	constexpr float k_epsilon = 0.0000001f;

	const float3 edge1 = vertex1 - vertex0;
	const float3 edge2 = vertex2 - vertex0;
	const float3 h = cross(dir, edge2);
	const float a = dot(edge1, h);
	if (a > -k_epsilon && a < k_epsilon)
	{
		// This ray is parallel to this triangle.
		return false;    
	}

	const float f = 1.0 / a;
	const float3 s = orig - vertex0;
	const float u = f * dot(s, h);
	if (u < 0.0 || u > 1.0)
	{
		return false;
	}

	float3 q = cross(s, edge1);
	float v = f * dot(dir, q);
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

bool ray_intersection_test(s_sh_baker& sh_baker, int vertex_index, const float3& direction)
{
	bool visible = true;
	const float3& orig = sh_baker.vertices[vertex_index];
	for (unsigned int face_index = 0; face_index < sh_baker.num_triangles; face_index++)
	{
		const s_triangle_indices& triangle = sh_baker.triangles[face_index];
		if ((vertex_index != triangle.a) && (vertex_index != triangle.b) && (vertex_index != triangle.c))
		{
			visible = !ray_intersects_triangle(sh_baker, face_index, orig, direction);
			if (!visible) 
				break;
		}
	}
	return(visible);
}

void sh_project_unshadowed(s_sh_baker& sh_baker, float3** coefficients)
{
	for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
	{
		for (unsigned int vertex_index = 0; vertex_index < sh_baker.num_vertices; vertex_index++)
		{
			coefficients[band_index][vertex_index].x = 0.0f;
			coefficients[band_index][vertex_index].y = 0.0f;
			coefficients[band_index][vertex_index].z = 0.0f;
		}
	}

	for (unsigned int vertex_index = 0; vertex_index < sh_baker.num_vertices; vertex_index++)
	{
		for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
		{
			coefficients[band_index][vertex_index].x = 0.0f;
			coefficients[band_index][vertex_index].y = 0.0f;
			coefficients[band_index][vertex_index].z = 0.0f;
		}

		for (unsigned int sample_index = 0; sample_index < sh_baker.num_samples; sample_index++)
		{
			s_sh_baker_sample& sample = sh_baker.samples[sample_index];
			const float3& normal = sh_baker.normals[vertex_index];
			float cosine_term = dot(normal, sample.cartesian_coord);

			if (cosine_term > 0.0f)
			{
				for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
				{
					float sh_function = sample.sh_functions[band_index];
					coefficients[band_index][vertex_index].x += sh_function * cosine_term;
					coefficients[band_index][vertex_index].y += sh_function * cosine_term;
					coefficients[band_index][vertex_index].z += sh_function * cosine_term;
				}
			}
		}

		constexpr float weight = 4.0f * PI;
		float scale = weight / sh_baker.num_samples;
		for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
		{
			coefficients[band_index][vertex_index].x *= scale;
			coefficients[band_index][vertex_index].y *= scale;
			coefficients[band_index][vertex_index].z *= scale;
			coefficients[band_index][vertex_index].x /= PI;
			coefficients[band_index][vertex_index].y /= PI;
			coefficients[band_index][vertex_index].z /= PI;
		}
	}
}

void sh_project_shadowed_mt(void* _sh_baker, uint32_t vertex_index)
{
	s_sh_baker& sh_baker = *(s_sh_baker*)_sh_baker;

	for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
	{
		sh_baker.coefficients[band_index][vertex_index].x = 0.0f;
		sh_baker.coefficients[band_index][vertex_index].y = 0.0f;
		sh_baker.coefficients[band_index][vertex_index].z = 0.0f;
	}

	for (unsigned int sample_index = 0; sample_index < sh_baker.num_samples; sample_index++)
	{
		s_sh_baker_sample& sample = sh_baker.samples[sample_index];
		const float3& normal = sh_baker.normals[vertex_index];
		float cosine_term = dot(normal, sample.cartesian_coord);

		if (cosine_term > 0.0f)
		{
			if (ray_intersection_test(sh_baker, vertex_index, sample.cartesian_coord))
			{
				for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
				{
					float sh_function = sample.sh_functions[band_index];
					sh_baker.coefficients[band_index][vertex_index].x += sh_function * cosine_term;
					sh_baker.coefficients[band_index][vertex_index].y += sh_function * cosine_term;
					sh_baker.coefficients[band_index][vertex_index].z += sh_function * cosine_term;
				}
			}
			else
			{
				debug_point;
			}
		}
	}

	constexpr float weight = 4.0f * PI;
	float scale = weight / sh_baker.num_samples;
	for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
	{
		sh_baker.coefficients[band_index][vertex_index].x *= scale;
		sh_baker.coefficients[band_index][vertex_index].y *= scale;
		sh_baker.coefficients[band_index][vertex_index].z *= scale;
		sh_baker.coefficients[band_index][vertex_index].x /= PI;
		sh_baker.coefficients[band_index][vertex_index].y /= PI;
		sh_baker.coefficients[band_index][vertex_index].z /= PI;
	}
}

void sh_project_shadowed(s_sh_baker& sh_baker)
{
	for (unsigned int vertex_index = 0; vertex_index < sh_baker.num_vertices; vertex_index++)
	{
		for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
		{
			sh_baker.coefficients[band_index][vertex_index].x = 0.0f;
			sh_baker.coefficients[band_index][vertex_index].y = 0.0f;
			sh_baker.coefficients[band_index][vertex_index].z = 0.0f;
		}

		for (unsigned int sample_index = 0; sample_index < sh_baker.num_samples; sample_index++)
		{
			s_sh_baker_sample& sample = sh_baker.samples[sample_index];
			const float3& normal = sh_baker.normals[vertex_index];
			float cosine_term = dot(normal, sample.cartesian_coord);

			if (cosine_term > 0.0f)
			{
				if (ray_intersection_test(sh_baker, vertex_index, sample.cartesian_coord))
				{
					for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
					{
						float sh_function = sample.sh_functions[band_index];
						sh_baker.coefficients[band_index][vertex_index].x += sh_function * cosine_term;
						sh_baker.coefficients[band_index][vertex_index].y += sh_function * cosine_term;
						sh_baker.coefficients[band_index][vertex_index].z += sh_function * cosine_term;
					}
				}
				else
				{
					debug_point;
				}
			}
		}

		constexpr float weight = 4.0f * PI;
		float scale = weight / sh_baker.num_samples;
		for (unsigned int band_index = 0; band_index < sh_baker.bands2; band_index++)
		{
			sh_baker.coefficients[band_index][vertex_index].x *= scale;
			sh_baker.coefficients[band_index][vertex_index].y *= scale;
			sh_baker.coefficients[band_index][vertex_index].z *= scale;
			sh_baker.coefficients[band_index][vertex_index].x /= PI;
			sh_baker.coefficients[band_index][vertex_index].y /= PI;
			sh_baker.coefficients[band_index][vertex_index].z /= PI;
		}
	}
}

BCS_RESULT sh_baker_bake(h_sh_baker& sh_baker_handle, c_geometry_mesh* geometry_mesh)
{
	BCS_VALIDATE_ARGUMENT(geometry_mesh != nullptr);
	s_sh_baker& sh_baker = *static_cast<s_sh_baker*>(sh_baker_handle);

	sh_baker.num_triangles = geometry_mesh->get_face_count();
	sh_baker.triangles = reinterpret_cast<const s_triangle_indices*>(geometry_mesh->get_mesh_indices_uint());
	sh_baker.num_vertices = geometry_mesh->get_vertex_count();
	sh_baker.vertices = geometry_mesh->get_positions();
	sh_baker.normals = geometry_mesh->get_normals();

	sh_baker.triangle_precompute = new() s_triangle_precompute[sh_baker.num_triangles];
	for (unsigned int i = 0; i < sh_baker.num_triangles; i++)
	{
		const s_triangle_indices& triangle = sh_baker.triangles[i];
		const float3& v0 = sh_baker.vertices[triangle.a];
		const float3& v1 = sh_baker.vertices[triangle.b];
		const float3& v2 = sh_baker.vertices[triangle.c];

		s_triangle_precompute& triangle_precompute = sh_baker.triangle_precompute[i];
		triangle_precompute.v0v1 = v1 - v0;
		triangle_precompute.v0v2 = v2 - v0;
	}

	sh_project_generate_samples(sh_baker, 16);

	sh_baker.coefficients = new float3 * [sh_baker.bands2];
	for (unsigned int i = 0; i < sh_baker.bands2; i++)
	{
		sh_baker.coefficients[i] = new float3[sh_baker.num_vertices];
	}

	//sh_project_shadowed(sh_baker);
	parallel_invoke(0, sh_baker.num_vertices, sh_project_shadowed_mt, &sh_baker);

	return BCS_S_OK;
}

BCS_RESULT sh_baker_get(h_sh_baker& sh_baker_handlebaker, const float3* const*& coefficients, unsigned int& num_coefficients)
{
	s_sh_baker& sh_baker = *static_cast<s_sh_baker*>(sh_baker_handlebaker);

	coefficients = (const float3* const*)sh_baker.coefficients;
	num_coefficients = sh_baker.num_vertices;

	return BCS_S_OK;
}

BCS_RESULT destroy_sh_baker(h_sh_baker& sh_baker_handle)
{
	s_sh_baker& sh_baker = *static_cast<s_sh_baker*>(sh_baker_handle);
	delete& sh_baker;

	return BCS_S_OK;
}
