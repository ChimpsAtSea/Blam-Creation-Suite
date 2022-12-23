add_executable(ResourcesPackager
	main.cpp)

bcs_set_common_properties(ResourcesPackager)
bcs_set_post_build_shared_lib_dep_copy(ResourcesPackager)

target_link_libraries(ResourcesPackager PRIVATE
	Platform SymbolsLib)
	
set_target_properties(ResourcesPackager PROPERTIES
	FOLDER "Tooling")

# -symbolfile:$<TARGET_FILE_DIR:${TARGET_NAME}>/$<TARGET_FILE_BASE_NAME:${TARGET_NAME}>.map
#function(bcs_set_post_build_resource_package TARGET_NAME ARGUMENTS)
#	add_dependencies(${TARGET_NAME} ResourcesPackager)
#	add_custom_command(
#		TARGET ${TARGET_NAME} POST_BUILD
#		COMMAND "$<TARGET_FILE:ResourcesPackager>"
#			"-packagesymbols -executable:$<TARGET_FILE:${TARGET_NAME}> -outputdir:$<TARGET_FILE_DIR:Platform> -resources:${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/ ${ARGUMENTS}"
#		COMMAND_EXPAND_LISTS)
#endfunction()
