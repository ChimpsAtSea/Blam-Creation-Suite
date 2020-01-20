#include "mantlereflect-private-pch.h"

using namespace clang::tooling;
using namespace llvm;

static llvm::cl::OptionCategory MyToolCategory("my-tool options");

int main(int argc, const char* argv[])
{
	if (argc != 4)
	{
		printf("Incorrect number of arguments. Expected 3");
		return 1;
	}

	const char* szReflectionSourceFile = argv[1];
	const char* szOutputHeader = argv[2];
	const char* szOutputSource = argv[3];

	printf("Reflection Source File:   '%s'\n", szReflectionSourceFile);
	printf("Reflection Output Header: '%s'\n", szOutputHeader);
	printf("Reflection Output Source: '%s'\n", szOutputSource);

	const char* argumentsArray[] = {
			argv[0],
			szReflectionSourceFile
	};
	int numArgs = _countof(argumentsArray);
	CommonOptionsParser OptionsParser(numArgs, argumentsArray, MyToolCategory);
	ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

	// #TODO: Add custom LLVM code here and pass to newFrontendActionFactory
	// see https://clang.llvm.org/docs/LibASTMatchersTutorial.html

	int llvmResult = Tool.run(newFrontendActionFactory<clang::SyntaxOnlyAction>().get());

	{
		FILE* pReflectionHeader = fopen(szOutputHeader, "w");
		assert(pReflectionHeader != nullptr);
		fflush(pReflectionHeader);
		fclose(pReflectionHeader);
	}

	{
		FILE* pReflectionSource = fopen(szOutputSource, "w");
		assert(pReflectionSource != nullptr);
		fflush(pReflectionSource);
		fclose(pReflectionSource);
	}

	return llvmResult;
}


