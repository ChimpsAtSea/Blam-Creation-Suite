add_library(Oozle STATIC
	../Oozle/oozle.h
	../Oozle/stdafx.h
	../Oozle/targetver.h
	../Oozle/bitknit.cpp
	../Oozle/kraken.cpp
	../Oozle/lzna.cpp
	../Oozle/stdafx.cpp)

bcs_set_compile_properties(Oozle)

target_precompile_headers(Oozle PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:../Oozle/stdafx.h>")

set_target_properties(Oozle PROPERTIES
	FOLDER "ThirdParty")
