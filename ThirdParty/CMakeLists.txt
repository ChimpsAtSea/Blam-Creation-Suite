set(VCPKG_TRIPLET "x64-windows-$<$<CONFIG:DEBUG>:debug>$<$<NOT:$<CONFIG:DEBUG>>:release>$<$<STREQUAL:${BCS_BUILD_SHARED_LIBRARIES},TRUE>:-shared>-bcs" CACHE INTERNAL "")
set(VCPKG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg" CACHE INTERNAL "")
set(VCPKG "${VCPKG_DIR}/vcpkg.exe" CACHE INTERNAL "")
set(VCPKG_INSTALLED_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}" CACHE INTERNAL "")
set(VCPKG_INCLUDE_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/include" CACHE INTERNAL "")
set(VCPKG_DEBUG_LIB_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/debug/lib" CACHE INTERNAL "")
set(VCPKG_DEBUG_BIN_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/debug/bin" CACHE INTERNAL "")
set(VCPKG_RELEASE_LIB_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/lib" CACHE INTERNAL "")
set(VCPKG_RELEASE_BIN_DIR "${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin" CACHE INTERNAL "")

if(NOT CONFIG MATCHES DEBUG)
	message("Using vcpkg debug")
	set(VCPKG_LIB_DIR "${VCPKG_DEBUG_LIB_DIR}" CACHE INTERNAL "")
	set(VCPKG_BIN_DIR "${VCPKG_DEBUG_BIN_DIR}" CACHE INTERNAL "")
else()
	message("Using vcpkg release")
	set(VCPKG_LIB_DIR "${VCPKG_LIB_DIR}" CACHE INTERNAL "")
	set(VCPKG_BIN_DIR "${VCPKG_BIN_DIR}" CACHE INTERNAL "")
endif()

add_custom_command(OUTPUT ${VCPKG}
    COMMAND cmd /c "${VCPKG_DIR}/bootstrap-vcpkg.bat -disableMetrics")

add_custom_target(VcPkgBootstrap ALL
    DEPENDS ${VCPKG}
)

set(VCPKG_TRIPLETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg-custom-triplets/")
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/VcPkg.stamp
    COMMAND ${VCPKG} install 
	"curl:${VCPKG_TRIPLET}" 
	"rapidjson:${VCPKG_TRIPLET}" 
	"ffmpeg[core,avcodec,swresample]:${VCPKG_TRIPLET}" 
	"mimalloc:${VCPKG_TRIPLET}" 
	"directxtex[dx12]:${VCPKG_TRIPLET}" 
	"directxmesh:${VCPKG_TRIPLET}" 
	"uvatlas:${VCPKG_TRIPLET}" 
	"assimp:${VCPKG_TRIPLET}" 
	"freeimage:${VCPKG_TRIPLET}"
	"--overlay-triplets=${VCPKG_TRIPLETS_DIR}" 
	--disable-metrics
	--no-binarycaching
	--recurse
    COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_BINARY_DIR}/VcPkg.stamp")

add_custom_target(VcPkg ALL
    DEPENDS "${CMAKE_BINARY_DIR}/VcPkg.stamp"
)

add_dependencies(VcPkg VcPkgBootstrap)

set_target_properties(VcPkg VcPkgBootstrap PROPERTIES
	FOLDER "ThirdParty")

function(bcs_use_vcpkg_directories TARGET_NAME)
	target_include_directories(${TARGET_NAME} PUBLIC
		${VCPKG_INCLUDE_DIR})
	
	target_link_directories(${TARGET_NAME} PUBLIC
		${VCPKG_LIB_DIR})
	
	add_dependencies(${TARGET_NAME} VcPkg)
endfunction()

set(TBB_BUILD_TBBMALLOC ON)
set(TBB_BUILD_TBBMALLOC_PROXY OFF)
set(TBB_BUILD_TESTS OFF)
set(TBB_BUILD_SHARED ON)
set(TBB_BUILD_STATIC OFF)
set(TBB_CI_BUILD OFF)
set(TBB_NO_DATE ON)
add_subdirectory(tbb)

#set_target_properties(tbb_static tbbmalloc_static tbb_def_files PROPERTIES
set_target_properties(tbb tbbmalloc tbb_def_files PROPERTIES
	FOLDER "ThirdParty")

set(DXHEADERS_BUILD_TEST OFF)
set(DXHEADERS_INSTALL OFF)
add_subdirectory(DirectX-Headers)

set_target_properties(DirectX-Guids PROPERTIES
	FOLDER "ThirdParty")

set(BUILD_TESTING OFF)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(pugixml EXCLUDE_FROM_ALL)

set_target_properties(pugixml PROPERTIES
	FOLDER "ThirdParty")

add_subdirectory(zlib)
add_subdirectory(oozle_build)
add_subdirectory(murmur3_build)
add_subdirectory(lzxlib)
add_subdirectory(xxhash)
add_subdirectory(imgui)
add_subdirectory(xatlas_build)
add_subdirectory(d3d12raytracingfallback_build)
add_subdirectory(winpixeventruntime)
add_subdirectory(directxshadercompiler)
