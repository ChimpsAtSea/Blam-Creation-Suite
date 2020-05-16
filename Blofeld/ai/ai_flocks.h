#pragma once

namespace blofeld
{

extern s_tag_struct flock_struct_definition_struct_definition;

extern s_tag_struct flock_palette_block_struct_definition;
extern s_tag_block_definition flock_palette_block;
extern s_tag_struct flock_instance_block_struct_definition;
extern s_tag_block_definition flock_instance_block;
extern s_tag_struct flock_source_block_struct_definition;
extern s_tag_block_definition flock_source_block;
extern s_tag_struct flock_destination_block_struct_definition;
extern s_tag_block_definition flock_destination_block;

constexpr unsigned long FLOCK_TAG = 'flck';

extern s_tag_block_definition flock_block;
extern s_tag_group flock_group;
} // namespace blofeld

