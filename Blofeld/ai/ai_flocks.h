#pragma once

namespace blofeld
{

constexpr unsigned long FLOCK_TAG = 'flck';

extern s_tag_group flock_group;

extern s_tag_block_definition flock_block_block;
extern s_tag_struct flock_palette_block_block_struct;
extern s_tag_block_definition flock_palette_block_block;
extern s_tag_struct flock_instance_block_block_struct;
extern s_tag_block_definition flock_instance_block_block;
extern s_tag_struct flock_source_block_block_struct;
extern s_tag_block_definition flock_source_block_block;
extern s_tag_struct flock_destination_block_block_struct;
extern s_tag_block_definition flock_destination_block_block;

extern s_tag_struct flock_struct_definition_struct_definition; // tag group

} // namespace blofeld

