#pragma once

enum e_network_session_class : uint32_t
{
	_network_session_class_none = 0x0,
	_network_session_class_offline = 0x1,
	_network_session_class_system_link = 0x2,
	_network_session_class_xbox_live = 0x3,
	k_network_session_class_count = 0x4,
};
