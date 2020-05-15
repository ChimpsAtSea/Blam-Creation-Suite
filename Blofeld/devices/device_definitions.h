#pragma once

namespace blofeld
{

extern s_tag_block terminal_page_block;

constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';

extern s_tag_block device_control_block;
extern s_tag_group device_control_group;
constexpr unsigned long DEVICE_TAG = 'devi';

extern s_tag_block device_block;
extern s_tag_group device_group;
constexpr unsigned long DEVICE_DISPENSER_TAG = 'dspn';

extern s_tag_block device_dispenser_block;
extern s_tag_group device_dispenser_group;
constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';

extern s_tag_block device_machine_block;
extern s_tag_group device_machine_group;
constexpr unsigned long DEVICE_TERMINAL_TAG = 'term';

extern s_tag_block device_terminal_block;
extern s_tag_group device_terminal_group;
} // namespace blofeld

