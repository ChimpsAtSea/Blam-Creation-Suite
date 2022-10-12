include(ExternalProject)

set(WINPIXEVENTRUNTIME_NUPKG_FILENAME "winpixeventruntime.1.0.220810001.nupkg" CACHE INTERNAL "")
set(WINPIXEVENTRUNTIME_NUPKG_URL "https://globalcdn.nuget.org/packages/${WINPIXEVENTRUNTIME_NUPKG_FILENAME}" CACHE INTERNAL "")

ExternalProject_Add(
    winpixeventruntime_external
	PREFIX "winpix"
    URL ${WINPIXEVENTRUNTIME_NUPKG_URL}
	DOWNLOAD_EXTRACT_TIMESTAMP true
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND "")
	
ExternalProject_Get_property(winpixeventruntime_external SOURCE_DIR)
set(WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY "${SOURCE_DIR}/Include" CACHE INTERNAL "")
set(WINPIXEVENTRUNTIME_BINARY_DIRECTORY "${SOURCE_DIR}/bin/x64" CACHE INTERNAL "")

add_custom_command(
	TARGET winpixeventruntime_external
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  								
        "${WINPIXEVENTRUNTIME_BINARY_DIRECTORY}/WinPixEventRuntime.dll"
		$<$<CONFIG:DEBUG>:"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/">
		$<$<CONFIG:RELEASE>:"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/">
    DEPENDS
		winpixeventruntime_external)

# message("SOURCE_DIR: ${SOURCE_DIR}")
# message("WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY: ${WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY}")
# message("WINPIXEVENTRUNTIME_BINARY_DIRECTORY: ${WINPIXEVENTRUNTIME_BINARY_DIRECTORY}")

add_library(winpixeventruntime INTERFACE)
add_dependencies(winpixeventruntime winpixeventruntime_external)
add_dependencies(winpixeventruntime "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/WinPixEventRuntime.dll")
target_link_directories(winpixeventruntime INTERFACE "${WINPIXEVENTRUNTIME_BINARY_DIRECTORY}")
target_link_libraries(winpixeventruntime INTERFACE WinPixEventRuntime.lib)
target_include_directories(winpixeventruntime INTERFACE 
	"${WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY}"
	"${WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY}/WinPixEventRuntime")

add_library(winpixeventruntime_binaryonly INTERFACE)
add_dependencies(winpixeventruntime_binaryonly winpixeventruntime_external)
add_dependencies(winpixeventruntime_binaryonly "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/WinPixEventRuntime.dll")
target_link_directories(winpixeventruntime_binaryonly INTERFACE "${WINPIXEVENTRUNTIME_BINARY_DIRECTORY}")
target_include_directories(winpixeventruntime_binaryonly INTERFACE 
	"${WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY}"
	"${WINPIXEVENTRUNTIME_INCLUDE_DIRECTORY}/WinPixEventRuntime")

set_target_properties(winpixeventruntime_external PROPERTIES
	FOLDER "ThirdParty")
