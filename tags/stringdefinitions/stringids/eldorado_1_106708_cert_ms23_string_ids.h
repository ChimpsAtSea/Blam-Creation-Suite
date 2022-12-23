#pragma once

namespace eldorado_1_106708_cert_ms23
{
	enum e_string_namespace
	{
		_string_namespace_global = 0,
		_string_namespace_gui,
		_string_namespace_gui_alert,
		_string_namespace_gui_dialog,
		_string_namespace_game_engine,
		_string_namespace_game_start,
		_string_namespace_online,
		_string_namespace_saved_game,
		_string_namespace_gpu,
		k_string_namespace_count
	};

	extern s_constant_string_id_table constant_string_id_table;
}
