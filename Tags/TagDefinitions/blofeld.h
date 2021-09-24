#pragma once

namespace blofeld
{
	using t_max_count_func = unsigned long(s_engine_platform_build engine_platform_build);

	struct s_tag_group;
	struct s_tag_struct_definition;
	struct s_tag_block_definition;
	struct s_tag_array_definition;
	struct s_tag_reference_definition;
	struct s_tag_interop_definition;
	struct s_string_list_definition;
	class t_string_list;
	struct s_tag_field;

	constexpr unsigned long INVALID_TAG = 0xFFFFFFFF;
	constexpr unsigned long ANY_TAG = 0;

	const s_tag_group* get_group_tag_by_group_tag(e_engine_type engine_type, unsigned long group_tag);
	struct s_tag_struct_validation_data
	{
		const s_tag_struct_definition& struct_definition;
		unsigned long size;
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
