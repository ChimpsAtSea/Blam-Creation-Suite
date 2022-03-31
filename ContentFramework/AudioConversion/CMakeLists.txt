add_library(AudioConversion ${BCS_LIBRARY_TYPE}
	audioconversion-public-pch.h
	audioconversion-private-pch.h
	audioconversion-platform-pch.h
	xma2defs.h
	xma2_to_wave.h
	xma2_to_wave.cpp)

bcs_set_common_properties(AudioConversion)
	
target_include_directories(AudioConversion PRIVATE
	${FFMPEG_INCLUDE_DIRS})
target_link_directories(AudioConversion PRIVATE
	${FFMPEG_LIBRARY_DIRS})
target_link_libraries(AudioConversion PRIVATE
	Platform
	TemplateLibrary
	${FFMPEG_LIBRARIES})

target_precompile_headers(AudioConversion PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:audioconversion-private-pch.h>")

set_target_properties(AudioConversion PROPERTIES
	FOLDER "!Framework")
