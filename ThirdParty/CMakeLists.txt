set(VCPKG_TRIPLET "x64-windows-$<$<CONFIG:DEBUG>:debug>$<$<NOT:$<CONFIG:DEBUG>>:release>-bcs" CACHE INTERNAL "")
set(VCPKG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg" CACHE INTERNAL "")
set(VCPKG "${VCPKG_DIR}/vcpkg.exe" CACHE INTERNAL "")

add_custom_command(OUTPUT ${VCPKG}
    COMMAND cmd /c "${VCPKG_DIR}/bootstrap-vcpkg.bat -disableMetrics")

add_custom_target(VcPkgBootstrap ALL
    DEPENDS ${VCPKG}
)

set(VCPKG_TRIPLETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg-custom-triplets/")
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/VcPkg.stamp
    COMMAND ${VCPKG} install "curl:${VCPKG_TRIPLET}" "rapidjson:${VCPKG_TRIPLET}" "ffmpeg[core,avcodec,swresample]:${VCPKG_TRIPLET}" "mimalloc:${VCPKG_TRIPLET}" "--overlay-triplets=${VCPKG_TRIPLETS_DIR}" --recurse
    COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_BINARY_DIR}/VcPkg.stamp")

add_custom_target(VcPkg ALL
    DEPENDS "${CMAKE_BINARY_DIR}/VcPkg.stamp"
)

add_dependencies(VcPkg VcPkgBootstrap)

set_target_properties(VcPkg VcPkgBootstrap PROPERTIES
	FOLDER "ThirdParty")

function(bcs_use_vcpkg_directories TARGET_NAME)
	target_include_directories(${TARGET_NAME} PUBLIC
		${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/include)
	
	target_link_directories(${TARGET_NAME} PUBLIC
		${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/lib)

	add_dependencies(${TARGET_NAME} VcPkg)
endfunction()

set(TBB_BUILD_TBBMALLOC ON)
set(TBB_BUILD_TBBMALLOC_PROXY OFF)
set(TBB_BUILD_TESTS OFF)
set(TBB_BUILD_SHARED OFF)
set(TBB_BUILD_STATIC ON)
add_subdirectory(tbb)

set_target_properties(tbb_static tbbmalloc_static tbb_def_files PROPERTIES
	FOLDER "ThirdParty")

add_subdirectory(DirectX-Headers)

set_target_properties(DirectX-Guids PROPERTIES
	FOLDER "ThirdParty")

set(BUILD_TESTING OFF)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(pugixml)

set_target_properties(pugixml-shared pugixml-static pugixml PROPERTIES
	FOLDER "ThirdParty")

add_subdirectory(zlib)
add_subdirectory(Oozle)
add_subdirectory(murmur3)
add_subdirectory(lzxlib)
add_subdirectory(xxhash)
add_subdirectory(imgui)
