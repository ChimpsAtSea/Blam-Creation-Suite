add_executable(BlamtoozleCmd
	main.cpp
	
	blamtoozlecmd-private-pch.h
	blamtoozlecmd-public-pch.h)

bcs_set_common_properties(BlamtoozleCmd)
bcs_set_post_build_shared_lib_dep_copy(BlamtoozleCmd)

target_link_libraries(BlamtoozleCmd PRIVATE
	Platform TemplateLibrary BlamtoozleLib)
	
target_precompile_headers(BlamtoozleCmd PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:blamtoozlecmd-private-pch.h>")
	
set_target_properties(BlamtoozleCmd PROPERTIES
	FOLDER "Runtime/Development")
