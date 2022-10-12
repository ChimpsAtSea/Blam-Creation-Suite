#pragma once

#include <Platform/platform-public-pch.h>
#include <TemplateLibrary/templatelibrary-public-pch.h>
#include <GraphicsLib/graphicslib-public-pch.h>

#pragma push_macro("new")
#undef new
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags
#pragma pop_macro("new")

#include <UVAtlas.h>
#include <DirectXMesh.h>
#include <xatlas_c.h>

#include <Platform/platform-exports-pch.h>

#include "geometrylib-public-pch.h"
#include "radiance_transfer_cpu.h"
#include "radiance_transfer_gpu.h"

#include "assimp_geometry_scene.h"
#include "assimp_geometry_mesh.h"
