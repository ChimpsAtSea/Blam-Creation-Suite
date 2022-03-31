add_library(lzxlib STATIC
	lxz_decoder.h
	lzxlib.h
	lxz_decoder.cpp)

bcs_set_common_properties(lzxlib)

set_target_properties(lzxlib PROPERTIES
	FOLDER "ThirdParty")
