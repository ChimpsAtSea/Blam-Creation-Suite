#pragma once

class c_geometry_mesh;

using h_uv_atlas_packer = void*;

BCS_SHARED BCS_RESULT create_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle, unsigned int resolution);
BCS_SHARED BCS_RESULT uv_atlas_packer_add_mesh(h_uv_atlas_packer& uv_atlas_packer_handle, c_geometry_mesh* mesh_data);
BCS_SHARED BCS_RESULT uv_atlas_packer_bake(h_uv_atlas_packer& uv_atlas_packer_handle);
BCS_SHARED BCS_RESULT destroy_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle);
