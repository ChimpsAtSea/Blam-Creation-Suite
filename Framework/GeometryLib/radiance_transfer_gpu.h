#pragma once

class c_radiance_transfer_engine_gpu :
	public c_radiance_transfer_engine
{
public:
	c_radiance_transfer_engine_gpu(
		unsigned int order,
		unsigned short resolution,
		bool use_shadows,
		bool calculate_subsurface);
	c_radiance_transfer_engine_gpu(c_radiance_transfer_engine_gpu const&) = delete;
	virtual ~c_radiance_transfer_engine_gpu();

	virtual BCS_RESULT add_mesh(
		c_geometry_mesh& geometry_mesh) override;
	virtual BCS_RESULT bake() override;
	virtual BCS_RESULT read(
		c_geometry_mesh& geometry_mesh,
		const float* const*& surface_coefficient_planes,
		const float* const*& subsurface_coefficient_planes,
		unsigned int& num_coefficients) override;

protected:
	c_geometry_mesh** geometry_meshes;
	unsigned int num_geometry_meshes;
	unsigned int order;
	unsigned int resolution;
	unsigned int num_coefficients;
};
