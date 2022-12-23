add_executable(RadianceTransferTest
	radiancetransfertest-private-pch.h
	main.cpp)

bcs_set_common_properties(RadianceTransferTest)

target_link_libraries(RadianceTransferTest PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	GeometryLib)

target_precompile_headers(RadianceTransferTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:radiancetransfertest-private-pch.h>")

set_target_properties(RadianceTransferTest PROPERTIES
	FOLDER "Runtime/Tests")
