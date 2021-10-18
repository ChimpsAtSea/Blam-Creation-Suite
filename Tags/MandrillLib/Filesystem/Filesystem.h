#pragma once

#include "crc32.h"

#include "tag_file_high_level_transplant.h"

#include "single_tag_file_header.h"
#include "single_tag_file_layout_reader.h"
#include "single_tag_file_reader.h"

#include "Chunks\chunk.h"
#include "Chunks\typed_chunk.h"
#include "Chunks\tag_header_chunk.h"

#include "Chunks\LayoutChunks\string_data_chunk.h"
#include "Chunks\LayoutChunks\string_offsets_chunk.h"
#include "Chunks\LayoutChunks\string_lists_chunk.h"

#include "Chunks\LayoutChunks\tag_group_layout_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_prechunk_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_preinterop_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_v3_chunk.h"
#include "Chunks\LayoutChunks\custom_block_index_search_names_chunk.h"
#include "Chunks\LayoutChunks\data_definition_name_chunk.h"
#include "Chunks\LayoutChunks\array_definitions_chunk.h"
#include "Chunks\LayoutChunks\field_types_chunk.h"
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
