add_library(AudioConversion ${BCS_LIBRARY_TYPE}
	audioconversion-public-pch.h
	audioconversion-private-pch.h
	audioconversion-platform-pch.h
	xma2defs.h
	xma2_to_wave.h
	xma2_to_wave.cpp)

bcs_set_common_properties(AudioConversion)
bcs_use_vcpkg_directories(AudioConversion)

target_link_libraries(AudioConversion PRIVATE
	Platform
	TemplateLibrary
	avcodec
	avutil
	swresample
	Mfplat
	Mfuuid
	Strmiids
	Bcrypt)

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET AudioConversion POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/avcodec-58.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/avutil-56.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/swresample-3.dll"
		"$<TARGET_FILE_DIR:AudioConversion>")
	
	install(FILES
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/avcodec-58.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/avutil-56.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/swresample-3.dll"
		DESTINATION bin)
endif()

target_precompile_headers(AudioConversion PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:audioconversion-private-pch.h>")

set_target_properties(AudioConversion PROPERTIES
	FOLDER "!ContentFramework")
