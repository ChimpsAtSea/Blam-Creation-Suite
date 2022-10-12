#include "geometrylib-private-pch.h"

c_radiance_transfer_engine_gpu::c_radiance_transfer_engine_gpu(
	unsigned int _order,
	unsigned short _resolution,
	bool _use_shadows,
	bool _calculate_subsurface) :
	c_radiance_transfer_engine()
{

}

c_radiance_transfer_engine_gpu::~c_radiance_transfer_engine_gpu()
{

}

BCS_RESULT c_radiance_transfer_engine_gpu::add_mesh(c_geometry_mesh& geometry_mesh)
{
	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_gpu::bake()
{
	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_gpu::read(
	c_geometry_mesh& geometry_mesh,
	const float* const*& surface_coefficient_planes,
	const float* const*& subsurface_coefficient_planes, 
	unsigned int& num_coefficients)
{
	return BCS_S_OK;
}
