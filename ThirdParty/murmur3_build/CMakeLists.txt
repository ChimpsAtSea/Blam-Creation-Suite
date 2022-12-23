add_library(murmur3 STATIC
	../murmur3/murmur3.h
	../murmur3/murmur3.c)

bcs_set_compile_properties(murmur3)

set_target_properties(murmur3 PROPERTIES
	FOLDER "ThirdParty")
