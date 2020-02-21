#pragma once

enum e_network_session_peer_state : uint32_t
{
	_network_session_peer_state_connected = 4,
	_network_session_peer_state_waiting = 7,
	_network_session_peer_state_established = 8,
};
