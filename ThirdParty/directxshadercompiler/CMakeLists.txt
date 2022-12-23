include(ExternalProject)

set(DIRECTXSHADERCOMPILER_ZIP_FILENAME "dxc-artifacts.zip" CACHE INTERNAL "")
set(DIRECTXSHADERCOMPILER_ZIP_URL "https://github.com/ChimpsAtSea/DirectXShaderCompiler/releases/download/1.0.2139/dxc-artifacts.zip" CACHE INTERNAL "")

ExternalProject_Add(
    directxshadercompiler_external
	PREFIX "dxc"
    URL ${DIRECTXSHADERCOMPILER_ZIP_URL}
	DOWNLOAD_EXTRACT_TIMESTAMP true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND "")
	
ExternalProject_Get_property(directxshadercompiler_external SOURCE_DIR)
set(DIRECTXSHADERCOMPILER_INCLUDE_DIRECTORY "${SOURCE_DIR}/include" CACHE INTERNAL "")
set(DIRECTXSHADERCOMPILER_BINARY_DIRECTORY "${SOURCE_DIR}/bin" CACHE INTERNAL "")
set(DIRECTXSHADERCOMPILER_LIBRARY_DIRECTORY "${SOURCE_DIR}/lib" CACHE INTERNAL "")

add_custom_command(
	TARGET directxshadercompiler_external
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  								
        "${DIRECTXSHADERCOMPILER_BINARY_DIRECTORY}/dxrfallbackcompiler.dll"
		$<$<CONFIG:DEBUG>:"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/">
		$<$<CONFIG:RELEASE>:"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/">
    DEPENDS
		directxshadercompiler_external)

add_library(directxshadercompiler INTERFACE)
add_dependencies(directxshadercompiler directxshadercompiler_external)
add_dependencies(directxshadercompiler "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dxrfallbackcompiler.dll")

target_link_directories(directxshadercompiler INTERFACE
	"${DIRECTXSHADERCOMPILER_BINARY_DIRECTORY}")

#target_link_libraries(directxshadercompiler INTERFACE dxrfallbackcompiler.lib)

target_include_directories(directxshadercompiler INTERFACE 
	"${DIRECTXSHADERCOMPILER_INCLUDE_DIRECTORY}"
	"${DIRECTXSHADERCOMPILER_INCLUDE_DIRECTORY}/dxc")

set_target_properties(directxshadercompiler_external PROPERTIES
	FOLDER "ThirdParty")
