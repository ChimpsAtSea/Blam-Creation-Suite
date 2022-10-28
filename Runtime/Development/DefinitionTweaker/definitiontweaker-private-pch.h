#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <GraphicsLib\graphicslib-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagValidate\tagvalidate-public-pch.h>
#include <MandrillLib\mandrilllib-public-pch.h>
#include <MandrillUI\mandrillui-public-pch.h>

#include <unordered_set>
#include <sstream>

#include <Blamtoozle\blamtoozle-public-pch.h>

#include "Eldorado\file_last_modification_date.h"
#include "Eldorado\cache_file_tags_header.h"
#include "Eldorado\cache_file_tag_instance.h"

#include "RuntimeTagDefinitions\runtime_tag_definitions.h"
#include "RuntimeTagDefinitions\runtime_tag_field.h"
#include "RuntimeTagDefinitions\runtime_tag_group_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_block_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_data_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_interop_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_reference_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_resource_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_string_list_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_struct_definition.h"
#include "RuntimeTagDefinitions\runtime_block_index_custom_search_definition.h"
#include "RuntimeTagDefinitions\runtime_tag_array_definition.h"

#include "definition_tweaker.h"

#include "SerializationContexts\serialization_errors.h"
#include "SerializationContexts\serialization_context.h"
#include "SerializationContexts\group_serialization_context.h"
#include "SerializationContexts\tag_serialization_context.h"
#include "SerializationContexts\tag_struct_serialization_context.h"
#include "SerializationContexts\tag_field_serialization_context.h"

// #TODO: Find a home for this
#define safe_string(str) ((str) ? (str) : "") 
