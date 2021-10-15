#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

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
#include <Rhesus\rhesus-public-pch.h>

#include "crc32.h"

#include "tag_file_high_level_transplant.h"

#include "single_tag_file_header.h"
#include "single_tag_file_layout_reader.h"
#include "single_tag_file_reader.h"

#include "Chunks\chunk.h"
#include "Chunks\typed_chunk.h"
#include "Chunks\tag_header_chunk.h"

#include "Chunks\LayoutChunks\tag_group_layout_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_v3_chunk.h"
#include "Chunks\LayoutChunks\string_data_chunk.h"
#include "Chunks\LayoutChunks\string_offsets_chunk.h"
#include "Chunks\LayoutChunks\custom_block_index_search_names_chunk.h"
#include "Chunks\LayoutChunks\string_lists_chunk.h"
#include "Chunks\LayoutChunks\data_definition_name_chunk.h"
#include "Chunks\LayoutChunks\array_definitions_chunk.h"
#include "Chunks\LayoutChunks\tag_field_types_chunk.h"
#include "Chunks\LayoutChunks\fields_chunk.h"
#include "Chunks\LayoutChunks\block_definitions_chunk.h"
#include "Chunks\LayoutChunks\resource_definitions_chunk.h"
#include "Chunks\LayoutChunks\interop_definitions_chunk.h"
#include "Chunks\LayoutChunks\structure_definitions_chunk.h"

#include "Chunks\TagChunks\binary_data_chunk.h"
#include "Chunks\TagChunks\tag_string_id_chunk.h"
#include "Chunks\TagChunks\tag_data_chunk.h"
#include "Chunks\TagChunks\tag_reference_chunk.h"
#include "Chunks\TagChunks\tag_struct_chunk.h"
#include "Chunks\TagChunks\tag_block_chunk.h"
