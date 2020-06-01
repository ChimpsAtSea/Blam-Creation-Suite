#pragma once

#pragma warning( push )
#pragma warning( disable : 4312 ) // warning C4312: 'type cast': conversion from 'A' to 'void *' of greater size

namespace blofeld
{
	struct s_tag_field
	{
		e_field const field_type;
		const char* const name;
		const char* const filename;
		int32_t const line;
		union
		{
			void* const value1;
			const s_tag_block_definition* const block_definition;
			const s_tag_struct_definition* const struct_definition;
			const s_tag_array_definition* const array_definition;
			const s_string_list_definition* const string_list_definition;
			const s_tag_reference_definition* const tag_reference_definition;
			const char* const explanation;
			uint32_t padding;
			uint32_t length;
		};
		const void* const value2;
		//enum e_build const min_version;
		//enum e_build const max_version;

		template<typename A, typename B>
		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name,
			A&& value1,
			B&& value2/*,
			e_build min_version = 0,
			e_build max_version = 0*/) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1((void*)(value1)),
			value2((void*)(value1))/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		template<typename A>
		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name,
			A&& value1/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1((void*)(value1)),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line/*,
			e_build min_version = (e_build)0,
			e_build max_version = (e_build)0*/) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr)/*,
			min_version(min_version),
			max_version(max_version)*/
		{

		}
	};
}

#pragma warning( pop )
