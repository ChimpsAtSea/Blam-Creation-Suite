#pragma once

namespace eldorado
{
	struct s_cache_file_tag_instance
	{
		dword checksum;
		dword total_size;
		short dependency_count;
		short data_fixup_count;
		short resource_fixup_count;
		short padding;
		dword offset; // offset from `base`
		tag group_tags[3];
		dword group_name; // string id
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x24);
}
