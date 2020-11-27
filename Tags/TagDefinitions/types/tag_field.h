#pragma once

#pragma warning( push )
#pragma warning( disable : 4312 ) // warning C4312: 'type cast': conversion from 'A' to 'void *' of greater size

namespace blofeld
{
	using t_tag_field_custom_version_callback = int32_t(*)(e_engine_type, e_platform_type, e_build);

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
			const s_tag_interop_definition* const tag_interop_definition;
			const char* const explanation;
			uint32_t padding;
			uint32_t length;
		};
		const void* const value2;
		//enum e_build const min_version;
		//enum e_build const max_version;

		e_engine_type _engine_type;
		e_platform_type _platform_type;
		e_build _build;
		uint32_t _version_field_skip_count;
		t_tag_field_custom_version_callback _custom_version_callback;

		template<typename A, typename B>
		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name,
			A&& value1,
			B&& value2) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1((void*)(value1)),
			value2((void*)(value2)),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		template<typename A>
		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name,
			A&& value1) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1((void*)(value1)),
			value2(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			const char* name) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			s_engine_type_and_platform_and_build engine_type_and_build,
			uint32_t version_field_skip_count = 1) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr),
			_engine_type(engine_type_and_build.engine_type),
			_platform_type(engine_type_and_build.platform_type),
			_build(engine_type_and_build.build),
			_version_field_skip_count(version_field_skip_count),
			_custom_version_callback(nullptr)
		{
			ASSERT(field_type > _field_type_non_standard);
		}

		s_tag_field(
			e_field field_type,
			const char* filename,
			int32_t line,
			t_tag_field_custom_version_callback custom_version_callback) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			value1(nullptr),
			value2(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(custom_version_callback)
		{
			ASSERT(field_type == _field_version_custom);
		}
	};

	inline bool skip_tag_field_version(s_tag_field const& tag_field, e_engine_type engine_type, e_platform_type platform_type, e_build build, uint32_t& skip_count)
	{
		if (tag_field.field_type > _field_type_non_standard)
		{
			bool skip_versioning_field = false;
			skip_count = tag_field._version_field_skip_count;

			switch (tag_field.field_type)
			{
			case _field_version_platform_include:
				if (tag_field._platform_type != _platform_type_not_set && platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field._platform_type & platform_type) != 0;
				}
				break;
			case _field_version_platform_exclude:
				if (tag_field._platform_type != _platform_type_not_set && platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field._platform_type & platform_type) == 0;
				}
				break;
			case _field_version_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type == tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build == tag_field._build;
				break;
			case _field_version_not_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type != tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build != tag_field._build;
				break;
			case _field_version_less:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type < tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build < tag_field._build;
				break;
			case _field_version_greater:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type > tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build > tag_field._build;
				break;
			case _field_version_less_or_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type <= tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build <= tag_field._build;
				break;
			case _field_version_greater_or_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type >= tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build >= tag_field._build;
				break;
			case _field_version_custom:
				ASSERT(tag_field._custom_version_callback);
				skip_count = tag_field._custom_version_callback(engine_type, platform_type, build);
				skip_versioning_field = false;
				break;
			}

			if (skip_versioning_field)
			{
				skip_count = 0;
			}

			return true;
		}
		skip_count = 0;
		return false;
	}
}

#pragma warning( pop )
