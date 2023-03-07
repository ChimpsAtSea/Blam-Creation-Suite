#pragma once

#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags
#include <DirectXMesh.h>
#include <xatlas_c.h>

#include <platform/platform-public-pch.h>
#include <templatelibrary/templatelibrary-public-pch.h>
#include <graphicslib/graphicslib-public-pch.h>

#include <platform/platform-exports-pch.h>

#include "geometrylib-public-pch.h"
#include "radiance_transfer_cpu.h"
#include "radiance_transfer_gpu.h"

#include "assimp_geometry_scene.h"
#include "assimp_geometry_mesh.h"
