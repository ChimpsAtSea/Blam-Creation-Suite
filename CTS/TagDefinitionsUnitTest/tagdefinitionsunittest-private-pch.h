#pragma once

#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>

#include "CppUnitTest.h"

///////////////////////////////////////////////////////////////////////////////////////////
//Macro for creating test methods with custom names
#define TEST_METHOD_EX(functionName, methodName)\
	static const EXPORT_METHOD ::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo* CALLING_CONVENTION CATNAME(__GetTestMethodInfo_, functionName)()\
	{\
		__GetTestClassInfo();\
		__GetTestVersion();\
		ALLOCATE_TESTDATA_SECTION_METHOD\
		static const ::Microsoft::VisualStudio::CppUnitTestFramework::MethodMetadata s_Metadata = {L"TestMethodInfo", L##methodName, reinterpret_cast<const unsigned char*>(__FUNCTION__ " (" methodName ")"), reinterpret_cast<const unsigned char*>(__FUNCDNAME__), __WFILE__, __LINE__};\
\
		static ::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo s_Info = {::Microsoft::VisualStudio::CppUnitTestFramework::MemberMethodInfo::TestMethod, NULL, &s_Metadata};\
		s_Info.method.pVoidMethod = static_cast<::Microsoft::VisualStudio::CppUnitTestFramework::TestClassImpl::__voidFunc>(&ThisClass::functionName);\
		return &s_Info;\
	}\
	void functionName()
