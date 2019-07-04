#include "opus-private-pch.h"

enum Realm;
struct NetworkID;

//0000000142A038B0		InitializeSimpleNetworkLibrary	SimpleNetworkLibrary-x64-Release
//InitializeSimpleNetworkLibrary  ord:7 rva2iat: 02A038B0
typedef __int64(__fastcall InitializeSimpleNetworkLibrary_Func)(__int64 a1);
InitializeSimpleNetworkLibrary_Func* InitializeSimpleNetworkLibrary_FuncPtr = nullptr;
extern "C" __declspec(dllexport) __int64 __fastcall InitializeSimpleNetworkLibrary(__int64 a1)
{
	return InitializeSimpleNetworkLibrary_FuncPtr(a1);
}

//0000000142A038B8		CreateSimpleNetworkInterface	SimpleNetworkLibrary-x64-Release
//CreateSimpleNetworkInterface  ord:4 rva2iat: 02A038B8
typedef __int64(__fastcall CreateSimpleNetworkInterface_Func)(__int64 a1, __int64 a2, __int64 a3);
CreateSimpleNetworkInterface_Func* CreateSimpleNetworkInterface_FuncPtr = nullptr;
extern "C" __declspec(dllexport) __int64 __fastcall CreateSimpleNetworkInterface(__int64 a1, __int64 a2, __int64 a3)
{
	return CreateSimpleNetworkInterface_FuncPtr(a1, a2, a3);
}

//0000000142A038C0		DestroySimpleNetworkInterface	SimpleNetworkLibrary-x64-Release
//DestroySimpleNetworkInterface  ord:5 rva2iat: 02A038C0
typedef void(__fastcall DestroySimpleNetworkInterface_Func)(__int64 a1);
DestroySimpleNetworkInterface_Func* DestroySimpleNetworkInterface_FuncPtr = nullptr;
extern "C" __declspec(dllexport) void __fastcall DestroySimpleNetworkInterface(__int64 a1)
{
	return DestroySimpleNetworkInterface_FuncPtr(a1);
}

//0000000142A03898		SetSimpleNetworkLibraryLogging	SimpleNetworkLibrary-x64-Release
//SetSimpleNetworkLibraryLogging  ord:9 rva2iat: 02A03898
typedef void(__fastcall SetSimpleNetworkLibraryLogging_Func)(__int64 a1, int a2);
SetSimpleNetworkLibraryLogging_Func* SetSimpleNetworkLibraryLogging_FuncPtr = nullptr;
extern "C" __declspec(dllexport) void __fastcall SetSimpleNetworkLibraryLogging(__int64 a1, int a2)
{
	return SetSimpleNetworkLibraryLogging_FuncPtr(a1, a2);
}

//0000000142A038A0		SimpleNetwork::NetworkID::FromHostname(SimpleNetwork::Realm,char const *)	SimpleNetworkLibrary-x64-Release
//?FromHostname@NetworkID@SimpleNetwork@@SA?AU12@W4Realm@2@PEBD@Z  ord:0 rva2iat: 02A038A0
typedef NetworkID* (__fastcall SimpleNetwork__NetworkID__FromHostname_Func)(NetworkID* a1, Realm a2, char const* a3);
SimpleNetwork__NetworkID__FromHostname_Func* SimpleNetwork__NetworkID__FromHostname_FuncPtr = nullptr;
extern "C" NetworkID* __fastcall SimpleNetwork__NetworkID__FromHostname(NetworkID* a1, Realm a2, char const* a3)
{
	return SimpleNetwork__NetworkID__FromHostname_FuncPtr(a1, a2, a3);
}

//0000000142A038A8		SimpleNetwork::NetworkID::FromXUID(unsigned __int64)	SimpleNetworkLibrary-x64-Release
//?FromXUID@NetworkID@SimpleNetwork@@SA?AU12@_K@Z  ord:2 rva2iat: 02A038A8
typedef NetworkID* (__fastcall SimpleNetwork__NetworkID__FromXUID_Func)(NetworkID* a1, unsigned __int64 a2);
SimpleNetwork__NetworkID__FromXUID_Func* SimpleNetwork__NetworkID__FromXUID_FuncPtr = nullptr;
extern "C" NetworkID* __fastcall SimpleNetwork__NetworkID__FromXUID(NetworkID* a1, unsigned __int64 a2)
{
	return SimpleNetwork__NetworkID__FromXUID_FuncPtr(a1, a2);
}

#pragma comment(linker, "/EXPORT:?FromHostname@NetworkID@SimpleNetwork@@SA?AU12@W4Realm@2@PEBD@Z=SimpleNetwork__NetworkID__FromHostname")
#pragma comment(linker, "/EXPORT:?FromXUID@NetworkID@SimpleNetwork@@SA?AU12@_K@Z=SimpleNetwork__NetworkID__FromXUID")

HMODULE SimpleNetworkLibrary; //SimpleNetworkLibrary-x64-Release.dll

void init_simple_network()
{
	SimpleNetworkLibrary = LoadLibraryA("SimpleNetworkLibrary-x64-Release.dll");
	assert(SimpleNetworkLibrary);

	SimpleNetwork__NetworkID__FromXUID_FuncPtr = (SimpleNetwork__NetworkID__FromXUID_Func*)GetProcAddress(SimpleNetworkLibrary, "?FromXUID@NetworkID@SimpleNetwork@@SA?AU12@_K@Z");;
	SimpleNetwork__NetworkID__FromHostname_FuncPtr = (SimpleNetwork__NetworkID__FromHostname_Func*)GetProcAddress(SimpleNetworkLibrary, "?FromHostname@NetworkID@SimpleNetwork@@SA?AU12@W4Realm@2@PEBD@Z");;
	SetSimpleNetworkLibraryLogging_FuncPtr = (SetSimpleNetworkLibraryLogging_Func*)GetProcAddress(SimpleNetworkLibrary, "SetSimpleNetworkLibraryLogging");;
	DestroySimpleNetworkInterface_FuncPtr = (DestroySimpleNetworkInterface_Func*)GetProcAddress(SimpleNetworkLibrary, "DestroySimpleNetworkInterface");;
	InitializeSimpleNetworkLibrary_FuncPtr = (InitializeSimpleNetworkLibrary_Func*)GetProcAddress(SimpleNetworkLibrary, "InitializeSimpleNetworkLibrary");;
	CreateSimpleNetworkInterface_FuncPtr = (CreateSimpleNetworkInterface_Func*)GetProcAddress(SimpleNetworkLibrary, "CreateSimpleNetworkInterface");;

	assert(SimpleNetwork__NetworkID__FromXUID_FuncPtr);
	assert(SimpleNetwork__NetworkID__FromHostname_FuncPtr);
	assert(SetSimpleNetworkLibraryLogging_FuncPtr);
	assert(DestroySimpleNetworkInterface_FuncPtr);
	assert(InitializeSimpleNetworkLibrary_FuncPtr);
	assert(CreateSimpleNetworkInterface_FuncPtr);
}

void deinit_simple_network()
{
	assert(SimpleNetwork__NetworkID__FromXUID_FuncPtr);
	assert(SimpleNetwork__NetworkID__FromHostname_FuncPtr);
	assert(SetSimpleNetworkLibraryLogging_FuncPtr);
	assert(DestroySimpleNetworkInterface_FuncPtr);
	assert(InitializeSimpleNetworkLibrary_FuncPtr);
	assert(CreateSimpleNetworkInterface_FuncPtr);

	SimpleNetwork__NetworkID__FromXUID_FuncPtr = nullptr;
	SimpleNetwork__NetworkID__FromHostname_FuncPtr = nullptr;
	SetSimpleNetworkLibraryLogging_FuncPtr = nullptr;
	DestroySimpleNetworkInterface_FuncPtr = nullptr;
	InitializeSimpleNetworkLibrary_FuncPtr = nullptr;
	CreateSimpleNetworkInterface_FuncPtr = nullptr;

	BOOL freeLibraryResult = FreeLibrary(SimpleNetworkLibrary);
	assert(freeLibraryResult);
}

