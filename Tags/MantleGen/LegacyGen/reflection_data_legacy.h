#pragma once

template<typename T>
const s_reflection_structure_type_legacy& reflection_structure_legacy();

template<typename T>
const s_reflection_enum_type_legacy& reflection_enum_legacy();

#ifndef __visual_assist__
const s_reflection_structure_type_legacy* reflection_legacy(uint32_t tagGroup);
#endif
