#pragma once

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <graphicslib\graphicslib-public-pch.h>
#include <shared\blam\blamlib-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagdefinitions\tagdefinitions-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>
#include <blamtoozle\blamtoozle-public-pch.h>
#include <tagfileserialization\tagfileserialization-public-pch.h>

#include <platform\platform-exports-pch.h>
#include <runtimedefinitions-public-pch.h>

// #TODO: Find a home for this
#define safe_string(str) ((str) ? (str) : "") 
