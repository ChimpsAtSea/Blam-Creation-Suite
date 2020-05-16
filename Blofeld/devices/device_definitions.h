#pragma once

namespace blofeld
{

constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';

extern s_tag_group device_control_group;
constexpr unsigned long DEVICE_TAG = 'devi';

extern s_tag_group device_group;
constexpr unsigned long DEVICE_DISPENSER_TAG = 'dspn';

extern s_tag_group device_dispenser_group;
constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';

extern s_tag_group device_machine_group;
constexpr unsigned long DEVICE_TERMINAL_TAG = 'term';

extern s_tag_group device_terminal_group;

extern s_tag_block_definition device_control_block_block;
extern s_tag_block_definition device_block_block;
extern s_tag_block_definition device_dispenser_block_block;
extern s_tag_block_definition device_machine_block_block;
extern s_tag_block_definition device_terminal_block_block;
extern s_tag_struct terminal_page_block_definition_block_struct;
extern s_tag_block_definition terminal_page_block_definition_block;

extern s_tag_struct device_control_struct_definition_struct_definition; // tag group
extern s_tag_struct device_struct_definition_struct_definition; // tag group
extern s_tag_struct device_dispenser_struct_definition_struct_definition; // tag group
extern s_tag_struct device_machine_struct_definition_struct_definition; // tag group
extern s_tag_struct device_terminal_struct_definition_struct_definition; // tag group

} // namespace blofeld

