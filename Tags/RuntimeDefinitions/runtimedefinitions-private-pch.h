#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <GraphicsLib\graphicslib-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <Blamtoozle\blamtoozle-public-pch.h>
#include <TagFileSerialization\tagfileserialization-public-pch.h>

#include <Platform\platform-exports-pch.h>
#include <runtimedefinitions-public-pch.h>

// #TODO: Find a home for this
#define safe_string(str) ((str) ? (str) : "") 
