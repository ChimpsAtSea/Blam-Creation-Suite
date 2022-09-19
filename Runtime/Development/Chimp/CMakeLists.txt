add_executable(Chimp
	Program.cs)

bcs_set_common_properties(Chimp)

target_link_libraries(Chimp PRIVATE
	ChimpLib)

set_target_properties(Chimp PROPERTIES
	DOTNET_SDK "Microsoft.NET.Sdk"
	DOTNET_TARGET_FRAMEWORK "net6.0"
	VS_GLOBAL_ROOTNAMESPACE "ChimpsAtSea.BlamCreationSuite.Chimp.Launcher"
	VS_GLOBAL_ApplicationIcon "${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/bcs_icon.ico")

set_property(TARGET Chimp PROPERTY VS_DOTNET_REFERENCES
	"System")

set_target_properties(Chimp PROPERTIES
	FOLDER "Runtime/Development")
