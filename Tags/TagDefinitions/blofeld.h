#pragma once

namespace blofeld
{
	struct s_tag_group;
	struct s_tag_struct_definition;
	struct s_tag_block_definition;
	struct s_tag_array_definition;
	struct s_tag_reference_definition;
	struct s_string_list_definition;
	struct s_tag_field;

	constexpr unsigned long INVALID_TAG = 0xFFFFFFFF;
	constexpr unsigned long ANY_TAG = 0;
	extern const char* empty_string_list[];

	const s_tag_group* get_tag_group_by_group_tag(uint32_t group_tag);
	struct s_tag_struct_validation_data
	{
		const s_tag_struct_definition& struct_definition;
		uint32_t size;
	};
	namespace Tag
	{
		template<class T>
		class Reference
		{
		public:
			static s_tag_reference_definition s_defaultDefinition;
		};
	}
}
