#pragma once

namespace blofeld
{

extern s_tag_struct device_control_struct_definition_struct_definition;
extern s_tag_struct device_struct_definition_struct_definition;
extern s_tag_struct device_dispenser_struct_definition_struct_definition;
extern s_tag_struct device_machine_struct_definition_struct_definition;
extern s_tag_struct device_terminal_struct_definition_struct_definition;

extern s_tag_struct terminal_page_block_definition_struct_definition;
extern s_tag_block_definition terminal_page_block_definition;

constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';

extern s_tag_block_definition device_control_block;
extern s_tag_group device_control_group;
constexpr unsigned long DEVICE_TAG = 'devi';

extern s_tag_block_definition device_block;
extern s_tag_group device_group;
constexpr unsigned long DEVICE_DISPENSER_TAG = 'dspn';

extern s_tag_block_definition device_dispenser_block;
extern s_tag_group device_dispenser_group;
constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';

extern s_tag_block_definition device_machine_block;
extern s_tag_group device_machine_group;
constexpr unsigned long DEVICE_TERMINAL_TAG = 'term';

extern s_tag_block_definition device_terminal_block;
extern s_tag_group device_terminal_group;
} // namespace blofeld

