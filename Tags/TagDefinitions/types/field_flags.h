#pragma once

namespace blofeld
{
	enum e_tag_field_flags
	{
		_tag_field_flag_unknown0,
		_tag_field_flag_read_only,
		_tag_field_flag_index,
		_tag_field_flag_unknown3,
		_tag_field_flag_unknown4,
		_tag_field_flag_pointer,
		k_num_tag_field_flags
	};
	using f_tag_field_flags = c_flags<e_tag_field_flags, underlying(e_tag_field_flags), k_num_tag_field_flags>;
}
