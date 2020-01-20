#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

static llvm::cl::OptionCategory MyToolCategory("my-tool options");

static std::stringstream stringstream;

class FindNamedClassVisitor
	: public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
	explicit FindNamedClassVisitor(ASTContext* Context)
		: Context(Context) {}

	bool VisitCXXRecordDecl(CXXRecordDecl* Declaration) {

		std::string declarationName = Declaration->getQualifiedNameAsString();

		stringstream << "template<>" << std::endl;
		stringstream << "inline const ReflectionData& GetReflectionData<" << declarationName << ">()" << std::endl;
		stringstream << "{" << std::endl;
		stringstream << "\t" << "static ReflectionData reflectionData = {" << std::endl;

		RecordDecl::field_range fields = Declaration->fields();

		int count = 0;
		for (FieldDecl* field : fields) count++;
		stringstream << "\t\t\"" << declarationName.c_str() << "\"," << std::endl;
		stringstream << "\t\t" << count << "," << std::endl;
		stringstream << "\t\t" << "{" << std::endl;
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

			stringstream << "\t\t\t{ \""<< typeName <<"\", \""<< fieldName <<"\" }," << std::endl;
		}
		stringstream << "\t\t\t{ }" << std::endl;

		stringstream << "\t\t" << "}" << std::endl;
		stringstream << "\t" << "};" << std::endl;
		stringstream << "\treturn reflectionData;" << std::endl;
		
		stringstream << "}" << std::endl;

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

	stringstream << "#pragma once" << std::endl << std::endl;

	CommonOptionsParser OptionsParser(numArgs, argumentsArray, MyToolCategory);
	ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

	FindNamedClassAction findNamedClassAction;

	//// #TODO: Add custom LLVM code here and pass to newFrontendActionFactory
	//// see https://clang.llvm.org/docs/LibASTMatchersTutorial.html

	int llvmResult = Tool.run(newFrontendActionFactory<FindNamedClassAction>().get());

	std::string str = stringstream.str();
	printf("%s\n", str.c_str());

	{
		FILE* pReflectionHeader = fopen(szOutputHeader, "w");
		assert(pReflectionHeader != nullptr);
		fwrite(str.c_str(), 1, str.length(), pReflectionHeader);
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


