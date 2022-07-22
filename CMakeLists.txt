cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# shut my battered wife CMake up
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0011 NEW)

# DON'T use Test for now, it's completely unconfigured
set(CMAKE_CONFIGURATION_TYPES Debug Test Release)

project(BlamCreationSuite LANGUAGES C CXX CSharp)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/!Install)

# this has to exist. we cannot swap DLL/LIB linkage based on VS debug/release target
set(BCS_LIBRARY_TYPE "SHARED" CACHE STRING "")
set_property(CACHE BCS_LIBRARY_TYPE PROPERTY STRINGS "SHARED" "STATIC")

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
#add_subdirectory(Framework/corelib)
add_subdirectory(Framework/Shared)
add_subdirectory(Framework/GraphicsLib)
add_subdirectory(Framework/DeviceCommunication)

add_subdirectory(DebugFileTools/SymbolsRuntime)
add_subdirectory(DebugFileTools/SymbolsLib)
add_subdirectory(DebugFileTools/SymbolsPreprocessor)

add_subdirectory(Tooling/ResourcesPackager)

add_subdirectory(Tags/TagDefinitions)
add_subdirectory(Tooling/TagFieldTypeLookupTable)
add_subdirectory(Tags/TagCodegen)
add_subdirectory(Tags/TagReflection)
add_subdirectory(Tags/Generated)
add_subdirectory(Tags/TagValidate)
add_subdirectory(Tags/MandrillLib)
add_subdirectory(Tags/MandrillUI)
add_subdirectory(Tags/Blamtoozle)
add_subdirectory(Tags/ChimpLib)

#add_subdirectory(Tooling/TagDefinitionsValidate)
#add_subdirectory(Tooling/UpgradeMacaque)

add_subdirectory(ContentFramework/AudioConversion)

add_subdirectory(Runtime/Mandrill)
add_subdirectory(Runtime/ImGUIUIPrototype)
add_subdirectory(Runtime/GraphicsTest)
add_subdirectory(Runtime/Halo1TagFileTest)
add_subdirectory(Runtime/Halo2TagFileTest)
add_subdirectory(Runtime/Halo2CacheFileBuilderTest)
add_subdirectory(Runtime/Halo3TagFileTest)
add_subdirectory(Runtime/Chimp)
