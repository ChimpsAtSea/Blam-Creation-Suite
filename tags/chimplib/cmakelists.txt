add_library(ChimpLib SHARED
	CustomScript.cs
	Command.cs
	Commands/HelloWorld.cs
	Commands/Eval.cs)

bcs_set_common_properties(ChimpLib)

set_target_properties(ChimpLib PROPERTIES
	DOTNET_SDK "Microsoft.NET.Sdk"
	DOTNET_TARGET_FRAMEWORK "net6.0"
	VS_GLOBAL_ROOTNAMESPACE "ChimpsAtSea.BlamCreationSuite.Chimp"
	VS_PACKAGE_REFERENCES "Microsoft.CodeAnalysis.CSharp.Scripting_4.1.0")

set_property(TARGET ChimpLib PROPERTY VS_DOTNET_REFERENCES
	"System, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089")

set_target_properties(ChimpLib PROPERTIES
	FOLDER "Tags")
