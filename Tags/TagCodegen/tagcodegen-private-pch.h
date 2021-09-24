#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#include <unordered_set>
#include <sstream>
#include <algorithm>

#include <Platform\platform-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>

#include "blamlib_string_parser.h"
#include "custom_codegen.h"
#include "tagcodegen-public-pch.h"

#include "low_level_tag_source_generator.h"
#include "virtual_tag_source_generator.h"
#include "high_level_tag_source_generator.h"
#include "structure_relationship_node.h"
#include "filesystem_helper.h"
