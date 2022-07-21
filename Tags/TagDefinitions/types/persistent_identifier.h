#pragma once

namespace blofeld
{
	struct s_tag_persistent_identifier
	{
		uint32_t identifier_part_0;
		uint32_t identifier_part_1;
		uint32_t identifier_part_2;
		uint32_t identifier_part_3;

		// #TODO: relocate this
		//BCS_DEBUG_API bool operator==(const s_tag_persistent_identifier& value) const;
		//BCS_DEBUG_API bool operator!=(const s_tag_persistent_identifier& value) const;
		inline bool operator==(const s_tag_persistent_identifier& value) const
		{
			return
				identifier_part_0 == value.identifier_part_0 &&
				identifier_part_1 == value.identifier_part_1 &&
				identifier_part_2 == value.identifier_part_2 &&
				identifier_part_3 == value.identifier_part_3;
		}

		inline bool operator!=(const s_tag_persistent_identifier& value) const
		{
			return
				identifier_part_0 != value.identifier_part_0 ||
				identifier_part_1 != value.identifier_part_1 ||
				identifier_part_2 != value.identifier_part_2 ||
				identifier_part_3 != value.identifier_part_3;
		}
	};
}
