#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

static llvm::cl::OptionCategory MyToolCategory("my-tool options");


class FindNamedClassVisitor
	: public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
	explicit FindNamedClassVisitor(ASTContext* Context)
		: Context(Context) {}

	bool VisitCXXRecordDecl(CXXRecordDecl* Declaration) {

		std::string declarationName = Declaration->getQualifiedNameAsString();

		printf("%s\n{\n", declarationName.c_str());

		RecordDecl::field_range fields = Declaration->fields();
		for (FieldDecl* field : fields)
		{
			const clang::RecordDecl* rd = field->getParent();
			const clang::QualType qt = field->getType();
			const clang::Type* t = qt.getTypePtr();
			
			static LangOptions languageOptions;
			static PrintingPolicy printingPolicy = { languageOptions };
			std::string typeName = QualType::getAsString(qt.split(), printingPolicy);

			std::string qualifiedName = field->getQualifiedNameAsString();
			std::string fieldName = field->getNameAsString();

			printf("\t%s '%s'\n", typeName.c_str(), fieldName.c_str());
		}
		printf("}\n", declarationName.c_str());

		return true;
	}

private:
	ASTContext* Context;
};

class FindNamedClassConsumer : public clang::ASTConsumer {
public:
	explicit FindNamedClassConsumer(ASTContext* Context)
		: Visitor(Context) {}

	virtual void HandleTranslationUnit(clang::ASTContext& Context) {
		Visitor.TraverseDecl(Context.getTranslationUnitDecl());
	}
private:
	FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction {
public:
	virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
		clang::CompilerInstance& Compiler, llvm::StringRef InFile) {
		return std::unique_ptr<clang::ASTConsumer>(
			new FindNamedClassConsumer(&Compiler.getASTContext()));
	}
};

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

	FindNamedClassAction findNamedClassAction;

	//// #TODO: Add custom LLVM code here and pass to newFrontendActionFactory
	//// see https://clang.llvm.org/docs/LibASTMatchersTutorial.html

	int llvmResult = Tool.run(newFrontendActionFactory<FindNamedClassAction>().get());

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


