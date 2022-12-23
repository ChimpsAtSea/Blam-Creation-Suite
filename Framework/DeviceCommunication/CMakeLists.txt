add_library(DeviceCommunication ${BCS_LIBRARY_TYPE}
	device_communication.cpp
	xbox360_device_manager.cpp
	devicecommunication-private-pch.h
	devicecommunication-public-pch.h
	device_communication.h
	xbox360_device_manager.h)

bcs_set_common_properties(DeviceCommunication)

target_link_libraries(DeviceCommunication PRIVATE
	Platform)

target_precompile_headers(DeviceCommunication PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:devicecommunication-private-pch.h>")
	
set_target_properties(DeviceCommunication PROPERTIES
	FOLDER "!Framework")
