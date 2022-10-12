#pragma once

typedef enum : unsigned int
{
	_radiance_transfer_engine_cpu,
	_radiance_transfer_engine_gpu,
	k_num_radiance_transfer_engine_types
} e_radiance_transfer_engine_type;

class c_geometry_mesh;

class c_radiance_transfer_engine
{
protected:
	c_radiance_transfer_engine();
	c_radiance_transfer_engine(c_radiance_transfer_engine const&) = delete;
	virtual ~c_radiance_transfer_engine();

public:
	virtual BCS_RESULT add_mesh(c_geometry_mesh& geometry_mesh) = 0;
	virtual BCS_RESULT bake() = 0;
	virtual BCS_RESULT read(
		c_geometry_mesh& geometry_mesh,
		const float* const*& surface_coefficient_planes,
		const float* const*& subsurface_coefficient_planes,
		unsigned int& num_coefficient_planes) = 0;
};

BCS_DEBUG_API BCS_RESULT radiance_transfer_create(
	e_radiance_transfer_engine_type radiance_transfer_engine_type,
	unsigned int order,
	unsigned int resolution,
	bool use_shadows,
	bool calculate_subsurface,
	c_radiance_transfer_engine*& radiance_transfer_engine);

BCS_DEBUG_API BCS_RESULT radiance_transfer_add_mesh(
	c_radiance_transfer_engine* radiance_transfer_engine,
	c_geometry_mesh* geometry_mesh);

BCS_DEBUG_API BCS_RESULT radiance_transfer_bake(
	c_radiance_transfer_engine* radiance_transfer_engine);

BCS_DEBUG_API BCS_RESULT radiance_transfer_read(
	c_radiance_transfer_engine* radiance_transfer_engine,
	c_geometry_mesh* geometry_mesh,
	const float* const*& surface_coefficient_planes,
	const float* const*& subsurface_coefficient_planes,
	unsigned int& num_coefficient_planes);

BCS_DEBUG_API BCS_RESULT radiance_transfer_destroy(
	c_radiance_transfer_engine* radiance_transfer_engine);

BCS_DEBUG_API void spherical_harmonic_evaluation_order0(float x, float y, float z, float* coefficients);
BCS_DEBUG_API void spherical_harmonic_evaluation_order1(float x, float y, float z, float* coefficients);
BCS_DEBUG_API void spherical_harmonic_evaluation_order2(float x, float y, float z, float* coefficients);
