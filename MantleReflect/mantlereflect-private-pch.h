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
#include <clang/AST/Comment.h>
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

#include "LLVM/llvm_compiler_interface.h"
#include "LLVM/llvm_class_visitor.h"
#include "LLVM/llvm_ast_consumer.h"
#include "LLVM/llvm_compile_action.h"

#include "LegacyGenerators/legacy_reflection_field_container.h"
#include "LegacyGenerators/legacy_reflection_type_container.h"
#include "LegacyGenerators/legacy_reflection_enum_container.h"

#include "BlamlibGenerators/blamlib_compiler_interface.h"

// --- LEGACY GENERATORS ---
#include "LegacyGenerators/legacy_compiler_interface.h"
#include "LegacyGenerators/legacy_ast_source_generator.h"
#include "LegacyGenerators/legacy_tag_groups_generator.h"
#include "LegacyGenerators/legacy_runtime_reflection_generator.h"
#include "LegacyGenerators/legacy_compile_time_gui_generator.h"
#include "LegacyGenerators/legacy_compile_time_conversion_generator.h"
#include "LegacyGenerators/legacy_virtual_tag_interface_generator.h"
/// --- END LEGACY GENERATORS ---
