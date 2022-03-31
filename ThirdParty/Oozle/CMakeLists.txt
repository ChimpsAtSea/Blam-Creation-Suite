add_library(Oozle STATIC
	oozle.h
	stdafx.h
	targetver.h
	bitknit.cpp
	kraken.cpp
	lzna.cpp
	stdafx.cpp)

bcs_set_common_properties(Oozle)

target_precompile_headers(Oozle PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:stdafx.h>")

set_target_properties(Oozle PROPERTIES
	FOLDER "ThirdParty")
