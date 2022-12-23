#include "geometrylib-private-pch.h"

c_radiance_transfer_engine::c_radiance_transfer_engine()
{

}

c_radiance_transfer_engine::~c_radiance_transfer_engine()
{

}

BCS_RESULT radiance_transfer_create(
	e_radiance_transfer_engine_type radiance_transfer_engine_type,
	unsigned int order,
	unsigned int resolution, 
	bool use_shadows, 
	bool calculate_subsurface,
	c_radiance_transfer_engine*& radiance_transfer_engine)
{
	BCS_VALIDATE_ARGUMENT(radiance_transfer_engine_type < k_num_radiance_transfer_engine_types);

	switch (radiance_transfer_engine_type)
	{
	case _radiance_transfer_engine_cpu:
		radiance_transfer_engine = new c_radiance_transfer_engine_cpu(order, resolution, use_shadows, calculate_subsurface);
		return BCS_S_OK;
	case _radiance_transfer_engine_gpu:
		radiance_transfer_engine = new c_radiance_transfer_engine_gpu(order, resolution, use_shadows, calculate_subsurface);
		return BCS_S_OK;
	default:
		return BCS_E_UNSUPPORTED;
	}
}

BCS_RESULT radiance_transfer_add_mesh(
	c_radiance_transfer_engine* radiance_transfer_engine,
	c_geometry_mesh* geometry_mesh)
{
	BCS_VALIDATE_ARGUMENT(radiance_transfer_engine != nullptr);
	BCS_VALIDATE_ARGUMENT(geometry_mesh != nullptr);

	BCS_RESULT rs = radiance_transfer_engine->add_mesh(*geometry_mesh);
	return rs;

}

BCS_RESULT radiance_transfer_bake(
	c_radiance_transfer_engine* radiance_transfer_engine)
{
	BCS_VALIDATE_ARGUMENT(radiance_transfer_engine != nullptr);

	BCS_RESULT rs = radiance_transfer_engine->bake();
	return rs;
}

BCS_RESULT radiance_transfer_read(
	c_radiance_transfer_engine* radiance_transfer_engine,
	c_geometry_mesh* geometry_mesh,
	const float* const*& surface_coefficient_planes,
	const float* const*& subsurface_coefficient_planes,
	unsigned int& num_coefficient_planes)
{
	BCS_VALIDATE_ARGUMENT(geometry_mesh != nullptr);
	BCS_VALIDATE_ARGUMENT(radiance_transfer_engine != nullptr);

	BCS_RESULT rs = radiance_transfer_engine->read(
		*geometry_mesh, 
		surface_coefficient_planes, 
		subsurface_coefficient_planes, 
		num_coefficient_planes);
	return rs;
}

BCS_RESULT radiance_transfer_destroy(
	c_radiance_transfer_engine* radiance_transfer_engine)
{
	BCS_VALIDATE_ARGUMENT(radiance_transfer_engine != nullptr);

	if (c_radiance_transfer_engine_cpu* radiance_transfer_engine_cpu = dynamic_cast<c_radiance_transfer_engine_cpu*>(radiance_transfer_engine))
	{
		delete radiance_transfer_engine_cpu;
	}
	else if (c_radiance_transfer_engine_gpu* radiance_transfer_engine_gpu = dynamic_cast<c_radiance_transfer_engine_gpu*>(radiance_transfer_engine))
	{
		delete radiance_transfer_engine_gpu;
	}
	else
	{
		return BCS_E_UNSUPPORTED;
	}

	return BCS_S_OK;
}


// order 0
void spherical_harmonic_evaluation_order0(const float fX, const float fY, const float fZ, float* pSH)
{
	pSH[0] = 0.2820947917738781f;
}

// order 1
void spherical_harmonic_evaluation_order1(const float fX, const float fY, const float fZ, float* pSH)
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
void spherical_harmonic_evaluation_order2(const float fX, const float fY, const float fZ, float* pSH)
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

// order 0
void spherical_harmonic_evaluation_order02(float x, float y, float z, float* coefficients)
{
	coefficients[0] = 0.2820947917738781f;
}

// order 1
void spherical_harmonic_evaluation_order12(float x, float y, float z, float* coefficients)
{
	float fC0, fC1, fS0, fS1, fTmpA, fTmpB, fTmpC;

	coefficients[0] = 0.2820947917738781f;
	coefficients[2] = 0.4886025119029199f * z;
	fC0 = x;
	fS0 = y;

	fTmpB = -0.48860251190292f;
	coefficients[3] = fTmpB * fC0;
	coefficients[1] = fTmpB * fS0;
}

// order 2
void spherical_harmonic_evaluation_order22(float x, float y, float z, float* coefficients)
{
	float fC0, fC1, fS0, fS1, fTmpA, fTmpB, fTmpC;
	float z2 = z * z;

	coefficients[0] = 0.2820947917738781f;
	coefficients[2] = 0.4886025119029199f * z;
	coefficients[6] = 0.9461746957575601f * z2 + -0.31539156525252f;
	fC0 = x;
	fS0 = y;

	fTmpA = -0.48860251190292f;
	coefficients[3] = fTmpA * fC0;
	coefficients[1] = fTmpA * fS0;
	fTmpB = -1.092548430592079f * z;
	coefficients[7] = fTmpB * fC0;
	coefficients[5] = fTmpB * fS0;
	fC1 = x * fC0 - y * fS0;
	fS1 = x * fS0 + y * fC0;

	fTmpC = 0.5462742152960395f;
	coefficients[8] = fTmpC * fC1;
	coefficients[4] = fTmpC * fS1;
}
