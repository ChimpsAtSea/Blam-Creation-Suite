#pragma once

namespace blofeld
{

extern s_tag_struct script_container_struct_definition_struct_definition;
extern s_tag_struct script_struct_definition_struct_definition;
extern s_tag_struct hs_script_data_struct_struct_definition;

extern s_tag_struct hs_source_reference_block_struct_definition;
extern s_tag_block_definition hs_source_reference_block;

constexpr unsigned long SCRIPT_CONTAINER_TAG = 'hscn';

extern s_tag_block_definition script_container_block;
extern s_tag_group script_container_group;
constexpr unsigned long SCRIPT_TAG = 'hsdt';

extern s_tag_block_definition script_block;
extern s_tag_group script_group;
} // namespace blofeld

