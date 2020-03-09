#pragma once

#pragma warning( push )
#pragma warning( disable : 4146 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4267 )
#pragma warning( disable : 4291 )
#pragma warning( disable : 4624 )
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
// Declares llvm::cl::extrahelp.
#include <llvm/Support/CommandLine.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#pragma warning( pop )

#include <windows.h>
#include <stdio.h>
#include <sstream>
#include <memory>

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>

#include "util.h"

#include "mantlereflect-public-pch.h"

#include "reflection_field_container.h"
#include "reflection_type_container.h"
#include "reflection_enum_container.h"
#include "SourceGenerators/ast_source_generator.h"
#include "SourceGenerators/mantle_tag_groups_generator.h"
#include "SourceGenerators/mantle_runtime_reflection_generator.h"
#include "SourceGenerators/mantle_compile_time_gui_generator.h"
#include "SourceGenerators/mantle_compile_time_conversion_generator.h"
#include "SourceGenerators/mantle_virtual_tag_interface_generator.h"
