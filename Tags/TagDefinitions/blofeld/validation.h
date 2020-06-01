#pragma once

namespace blofeld
{
	uint32_t calculate_struct_size(const s_tag_struct_definition& struct_definition, bool* block_failed_validation = nullptr);
	bool validate_halo4();
}



