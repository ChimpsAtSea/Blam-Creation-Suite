#pragma once

class c_geometry_mesh;

using h_sh_baker = void*;

BCS_DEBUG_API BCS_RESULT create_sh_baker_cpu(h_sh_baker& sh_baker, unsigned int order);
BCS_DEBUG_API BCS_RESULT sh_baker_bake(h_sh_baker& sh_baker, c_geometry_mesh* geometry_mesh);
BCS_DEBUG_API BCS_RESULT sh_baker_get(h_sh_baker& sh_baker, const float3* const*& coefficients, unsigned int& num_coefficients);
BCS_DEBUG_API BCS_RESULT destroy_sh_baker(h_sh_baker& sh_baker);
