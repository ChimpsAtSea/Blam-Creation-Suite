add_library(Shared INTERFACE
	Blam/byteswap/blamlib_byteswap.inl
	Blam/byteswap/blamlib_byteswap.cpp
	Blam/byteswap/blamlib_byteswap.h
	Blam/blamlib-public-pch.h
	Blam/Blam.h
	shared-types-pch.h
	shared-private-pch.h
	shared-public-pch.h)

get_target_property(Shared_SOURCES Shared SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${Shared_SOURCES})

target_link_libraries(Shared INTERFACE
	blamlib)
	
set_target_properties(Shared PROPERTIES
	FOLDER "!Framework")
