#include "stringdefinitions-private-pch.h"

BCS_RESULT get_constant_string_id_table_by_engine_platform_build(s_engine_platform_build engine_platform_build, s_constant_string_id_table*& constant_string_id_table)
{
	if (engine_platform_build.engine_type == _engine_type_eldorado)
	{
		switch (engine_platform_build.build)
		{
		case _build_eldorado_1_106708_cert_ms23:
			constant_string_id_table = &eldorado_1_106708_cert_ms23::constant_string_id_table;
			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}
