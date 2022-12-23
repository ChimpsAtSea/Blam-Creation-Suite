add_library(xxhash STATIC
	xxhash.h
	xxhash_cx.h
	
	xxhash.c)

bcs_set_common_properties(xxhash)

set_target_properties(xxhash PROPERTIES
	FOLDER "ThirdParty")
