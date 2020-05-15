#pragma once

namespace blofeld
{

extern s_tag_block cheap_particle_type_block;
extern s_tag_block cheap_particle_bitmap_reference_block;
extern s_tag_block cheapParticleTurbulenceTypeBlock_block;

constexpr unsigned long CHEAP_PARTICLE_EMITTER_TAG = 'cpem';

extern s_tag_block cheap_particle_emitter_block;
extern s_tag_group cheap_particle_emitter_group;
constexpr unsigned long CHEAP_PARTICLE_TYPE_LIBRARY_TAG = 'cptl';

extern s_tag_block cheap_particle_type_library_block;
extern s_tag_group cheap_particle_type_library_group;
} // namespace blofeld

