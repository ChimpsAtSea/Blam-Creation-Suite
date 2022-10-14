#pragma once

class c_radiance_transfer_engine_cpu;

struct c_radiance_transfer_geometry_cpu
{
	c_geometry_mesh* geometry_mesh;
	const c_radiance_transfer_engine_cpu* radiance_transfer_engine;

	const float3* vertices;
	const float3* normals;
	unsigned int num_vertices;

	const unsigned int* indices;
	unsigned int num_triangles;

	float** surface_coefficient_planes;
	float** subsurface_coefficient_planes;
	float* coefficients;
};

class c_radiance_transfer_engine_cpu :
	public c_radiance_transfer_engine
{
public:
	c_radiance_transfer_engine_cpu(
		unsigned int order, 
		unsigned short resolution, 
		bool use_shadows, 
		bool calculate_subsurface);
	c_radiance_transfer_engine_cpu(c_radiance_transfer_engine_cpu const&) = delete;
	virtual ~c_radiance_transfer_engine_cpu();

	virtual BCS_RESULT add_mesh(
		c_geometry_mesh& geometry_mesh) override;
	virtual BCS_RESULT bake() override;
	virtual BCS_RESULT read(
		c_geometry_mesh& geometry_mesh,
		const float* const*& surface_coefficient_planes,
		const float* const*& subsurface_coefficient_planes,
		unsigned int& num_coefficient_planes) override;

protected:
	void init_samples();
	void deinit_samples();

	static bool ray_intersection_test(
		c_radiance_transfer_geometry_cpu const& geometry,
		int vertex_index,
		const float3& ray_direction);
	static bool ray_intersects_triangle(
		c_radiance_transfer_geometry_cpu const& geometry,
		int face_index, 
		const float3& ray_origin,
		const float3& ray_direction);

	static void calculate_spherical_harmonic_coefficient_callback(void* geometry, uint32_t vertex_index);
	void calculate_spherical_harmonic_coefficient(c_radiance_transfer_geometry_cpu const& geometry, uint32_t vertex_index) const;

	c_geometry_mesh** geometry_meshes;
	unsigned int num_geometry_meshes;
	c_radiance_transfer_geometry_cpu* geometries;
	unsigned int num_geometries;
	unsigned int order;
	unsigned int resolution;
	unsigned int num_coefficient_planes;
	bool use_shadows;
	bool calculate_subsurface;
	float3* samples;
	unsigned int num_samples;
	float* sample_sh_coefficients;
	unsigned int num_sample_sh_coefficients;
	void (*spherical_harmonic_evaluation)(float x, float y, float z, float* coefficients);
};
