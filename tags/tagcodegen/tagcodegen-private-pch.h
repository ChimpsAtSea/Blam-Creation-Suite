#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#include <unordered_set>
#include <sstream>
#include <algorithm>

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\blam\blamlib-public-pch.h>
#include <symbolsruntime\symbolsruntime-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagdefinitions\tagdefinitions-public-pch.h>
#include <blamtoozle\blamtoozle-public-pch.h>
#include <runtimedefinitions\runtimedefinitions-public-pch.h>

#include "blamlib_string_parser.h"
#include "custom_codegen.h"
#include "tagcodegen-public-pch.h"

#include "source_generator_base.h"
#include "low_level_tag_source_generator.h"
#include "high_level_tag_source_generator.h"
#include "structure_relationship_node.h"
#include "filesystem_helper.h"
