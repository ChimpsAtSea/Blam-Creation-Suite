cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# shut my battered wife CMake up
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0011 NEW)

# DON'T use Test for now, it's completely unconfigured
set(CMAKE_CONFIGURATION_TYPES Debug Test Release)

# #TODO: disable C# on unsupported platforms by cmake.
#project(BlamCreationSuite LANGUAGES C CXX CSHARP)
project(BlamCreationSuite LANGUAGES C CXX)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/!Install)

# this has to exist. we cannot swap DLL/LIB linkage based on VS debug/release target
set(BCS_LIBRARY_TYPE "SHARED" CACHE STRING "")
set_property(CACHE BCS_LIBRARY_TYPE PROPERTY STRINGS "SHARED" "STATIC")

set(BCS_BUILD_HIGH_LEVEL_HALO_1 ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_2 ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_3 ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_3_ODST ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_ELDORADO ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_REACH ON CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_4 OFF CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_GROUNDHOG OFF CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_5 OFF CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_HALO_INFINITE OFF CACHE BOOL "")
set(BCS_BUILD_HIGH_LEVEL_STUBBS OFF CACHE BOOL "")

set(BCS_NUM_GENERATED_CTORS "64" CACHE STRING "")

if(BCS_LIBRARY_TYPE)
	if (BCS_LIBRARY_TYPE STREQUAL "SHARED")
		set(BCS_BUILD_SHARED_LIBRARIES TRUE)
	else()
		set(BCS_BUILD_SHARED_LIBRARIES FALSE)
	endif()
else()
	set(BCS_BUILD_SHARED_LIBRARIES ${BUILD_SHARED_LIBS})
endif()

# enable VS project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/!Bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/!Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/!Bin)

function(bcs_set_compile_properties TARGET_NAME)
	set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
	
	target_compile_definitions(${TARGET_NAME} PRIVATE
		$<$<CONFIG:DEBUG>:_DEBUG>
		$<$<NOT:$<CONFIG:DEBUG>>:NDEBUG>
		$<$<BOOL:BCS_BUILD_SHARED_LIBRARIES>:BCS_USE_SHARED_LIBRARIES>
		UNICODE
		_UNICODE
		_HAS_ITERATOR_DEBUGGING=0
		_SECURE_SCL=0
		IMGUI_USER_CONFIG="imgui_user_config.h")
		
	target_compile_features(${TARGET_NAME} PRIVATE
		cxx_std_23)
		
	target_link_directories(${TARGET_NAME} PRIVATE
		${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
	
	target_include_directories(${TARGET_NAME} PRIVATE
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Framework
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Framework/blamlib
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ContentFramework
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/DebugFileTools
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Tooling
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ThirdParty
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ThirdParty/imgui
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ThirdParty/IconFontCppHeaders
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/ThirdParty/xatlas/source/xatlas
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Tags
		${CMAKE_BINARY_DIR}/Tags)
	
	target_include_directories(${TARGET_NAME} PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR})
		
	if (MSVC)
		add_definitions("/MP")
		add_definitions("/wd4273")
  
		target_link_options(${TARGET_NAME} PRIVATE
			"/MAP:$<TARGET_FILE_DIR:${TARGET_NAME}>/$<TARGET_FILE_BASE_NAME:${TARGET_NAME}>.map")
		
		target_compile_options(${TARGET_NAME} PRIVATE
			"/bigobj")

		set_property(TARGET ${TARGET_NAME} PROPERTY
			MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:DebugDLL>")
	endif()
endfunction()

function(bcs_set_source_tree_properties TARGET_NAME)
	get_target_property(${TARGET_NAME}_SOURCES ${TARGET_NAME} SOURCES)
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${${TARGET_NAME}_SOURCES})
endfunction()

function(bcs_set_common_properties TARGET_NAME)
	bcs_set_compile_properties(${TARGET_NAME})
	bcs_set_source_tree_properties(${TARGET_NAME})
	
	if(${BCS_BUILD_HIGH_LEVEL_HALO_1})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_1)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_STUBBS)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_2})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_2)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_3})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_3)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_3_ODST})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_3_ODST)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_ELDORADO})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_ELDORADO)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_REACH})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_REACH)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_4})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_4)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_GROUNDHOG})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_5})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_5)
	endif()
	if(${BCS_BUILD_HIGH_LEVEL_HALO_INFINITE})
		add_compile_definitions(BCS_BUILD_HIGH_LEVEL_HALO_INFINITE)
	endif()

	install(FILES "$<TARGET_FILE:${TARGET_NAME}>" DESTINATION bin)
endfunction()

function(bcs_set_post_build_shared_lib_dep_copy TARGET_NAME)
	if (BCS_BUILD_SHARED_LIBRARIES)
		add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>
			COMMAND_EXPAND_LISTS)
	endif()
endfunction()

add_subdirectory(ThirdParty)

add_subdirectory(Framework/blamlib)
add_subdirectory(Framework/Platform)
add_subdirectory(Framework/TemplateLibrary)
add_subdirectory(Framework/GeometryLib)
add_subdirectory(Framework/TextureLib)
add_subdirectory(Framework/Shared)
add_subdirectory(Framework/GraphicsLib)
add_subdirectory(Framework/DeviceCommunication)

add_subdirectory(DebugFileTools/SymbolsRuntime)
add_subdirectory(DebugFileTools/SymbolsLib)
add_subdirectory(DebugFileTools/SymbolsPreprocessor)

add_subdirectory(Tooling/ResourcesPackager)


add_subdirectory(Tags/TagFramework)
add_subdirectory(Tags/TagDefinitions)
if(${BCS_BUILD_HIGH_LEVEL_HALO_1})
	add_subdirectory(Tags/TagDefinitions/Halo1)
	add_subdirectory(Runtime/Development/Halo1TagFileTest)
endif()
if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
	add_subdirectory(Tags/TagDefinitions/Stubbs)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_2})
	add_subdirectory(Tags/TagDefinitions/Halo2)
	add_subdirectory(Runtime/Development/Halo2TagFileTest)
	add_subdirectory(Runtime/Development/Halo2CacheFileBuilderTest)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3})
	add_subdirectory(Tags/TagDefinitions/Halo3)
	add_subdirectory(Runtime/Development/TextureTest)
	add_subdirectory(Runtime/Development/GeometryTest)
	add_subdirectory(Runtime/Development/Halo3TagFileTest)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3_ODST})
	add_subdirectory(Tags/TagDefinitions/Halo3ODST)
endif()
if(${BCS_BUILD_HIGH_LEVEL_ELDORADO})
	add_subdirectory(Tags/TagDefinitions/Eldorado)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_REACH})
	add_subdirectory(Tags/TagDefinitions/HaloReach)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_4})
	add_subdirectory(Tags/TagDefinitions/Halo4)
endif()
if(${BCS_BUILD_HIGH_LEVEL_GROUNDHOG})
	add_subdirectory(Tags/TagDefinitions/Groundhog)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_5})
	add_subdirectory(Tags/TagDefinitions/Halo5)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_INFINITE})
	add_subdirectory(Tags/TagDefinitions/HaloInfinite)
endif()

add_subdirectory(Tooling/TagFieldTypeLookupTable)
add_subdirectory(Tags/TagCodegen)
add_subdirectory(Tags/TagReflection)
add_subdirectory(Tags/Generated)
add_subdirectory(Tags/TagValidate)
add_subdirectory(Tags/MandrillLib)
add_subdirectory(Tags/MandrillUI)
add_subdirectory(Tags/Blamtoozle)
#add_subdirectory(Tags/ChimpLib)
add_subdirectory(Tags/RuntimeDefinitions)
add_subdirectory(Tags/TagFileSerialization)
add_subdirectory(Tags/StringDefinitions)
add_subdirectory(Tags/CacheFileSerialization)

#add_subdirectory(Tooling/TagDefinitionsValidate)
#add_subdirectory(Tooling/UpgradeMacaque)

add_subdirectory(ContentFramework/AudioConversion)

add_subdirectory(Runtime/Mandrill)

add_subdirectory(Runtime/Development/ImGUIUIPrototype)
add_subdirectory(Runtime/Development/GraphicsTest)
add_subdirectory(Runtime/Development/BlamtoozleCmd)
add_subdirectory(Runtime/Development/DefinitionTweaker)
add_subdirectory(Runtime/Development/DefinitionDumper)
add_subdirectory(Runtime/Development/LightmapResearch)
#add_subdirectory(Runtime/Development/Chimp)

add_subdirectory(Runtime/Tests/ComputeTest)
add_subdirectory(Runtime/Tests/RaytraceTest)
add_subdirectory(Runtime/Tests/RadianceTransferTest)
