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
			const void* const pointer; // #todo rename to definition
			const s_tag_block_definition* const block_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const s_tag_struct_definition* const struct_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const s_tag_array_definition* const array_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const s_string_list_definition* const string_list_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const s_tag_reference_definition* const tag_reference_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const s_tag_interop_definition* const tag_interop_definition; // #todo make type safe and dynamic cast from definition using common type (debug only)
			const char* const explanation; // #todo remove from union
			uint32_t padding; // #todo remove from union
			uint32_t length; // #todo remove from union
		};
		union
		{
			const void* const extra_value; // #todo remove
			uint32_t custom_type; // #todo remove
			e_field_id id;
		};
		//enum e_build const min_version;
		//enum e_build const max_version;

		e_engine_type _engine_type;
		e_platform_type _platform_type;
		e_build _build;
		uint32_t _version_field_skip_count;
		t_tag_field_custom_version_callback _custom_version_callback;
		c_blamlib_string_parser string_parser;

	public:
		template<typename A, typename B>
		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			int32_t line,
#endif
			const char* name,
			A&& pointer,
			B&& extra_value) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			pointer((void*)(pointer)),
			extra_value((void*)(extra_value)),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr),
			string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		template<typename A>
		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			int32_t line,
#endif
			const char* name,
			A&& pointer) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			pointer((void*)(pointer)),
			extra_value(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr),
			string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			int32_t line,
#endif
			const char* name) :
			field_type(field_type),
			name(name),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr),
			string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type
#ifndef __INTELLISENSE__
			, const char* filename
			, int32_t line
#endif
		) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr),
			string_parser("")
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			int32_t line,
#endif
			s_engine_type_and_platform_and_build engine_type_and_build,
			uint32_t version_field_skip_count = 1) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			_engine_type(engine_type_and_build.engine_type),
			_platform_type(engine_type_and_build.platform_type),
			_build(engine_type_and_build.build),
			_version_field_skip_count(version_field_skip_count),
			_custom_version_callback(nullptr),
			string_parser(name)
		{
			ASSERT(field_type > _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			int32_t line,
#endif
			t_tag_field_custom_version_callback custom_version_callback) :
			field_type(field_type),
			name(nullptr),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(custom_version_callback),
			string_parser("")
		{
			ASSERT(field_type == _field_version_custom);
		}

		// type #WARN: Must only be used with _field_terminator
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line)) :
			s_tag_field(type HIDDEN(, filename, line), nullptr, nullptr, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default)
		{
			DEBUG_ONLY(if (type != _field_terminator) FATAL_ERROR(L"Invalid tag constructor usage (expected type == _field_terminator) %S:%i", filename, line));
		};
		
		// type, name
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, uint32_t flags) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, uint32_t flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, nullptr, id) {};

		// type, name, description
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, uint32_t flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, description, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, description, units
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description, units
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, uint32_t flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, description, units, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, uint32_t flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, nullptr, id) {};

		// type, name, description, units, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, description, units, limits
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, const char* limits) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description, units, limits, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, const char* limits, uint32_t flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, flags, nullptr, _field_id_default) {};

		// #TODO: replace all of these constructors with bespoke type checking
		// don't put incorrect pointers along with incorrect field types
		
#define __tag_field_pointer_type__ s_tag_struct_definition
#include "tag_field.ctor.inl"
#undef __tag_field_pointer_type__

#define __tag_field_pointer_type__ s_tag_block_definition
#include "tag_field.ctor.inl"
#undef __tag_field_pointer_type__

#define __tag_field_pointer_type__ s_tag_array_definition
#include "tag_field.ctor.inl"
#undef __tag_field_pointer_type__

#define __tag_field_pointer_type__ s_string_list_definition
#include "tag_field.ctor.inl"
#undef __tag_field_pointer_type__

#define __tag_field_pointer_type__ s_tag_reference_definition
#include "tag_field.ctor.inl"
#undef __tag_field_pointer_type__
		
		// type, name, description, units, limits, alt-names-array, FLAGS, pointer, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int32_t line), const char* name, const char* description, const char* units, const char* limits, const char** alt_names, uint32_t flags, const void* pointer, e_field_id id) :
			field_type(type),
			name(nullptr),
#ifndef HIDDEN_CODE
			filename(filename),
			line(line),
#else
			filename(""),
			line(0),
#endif
			pointer(pointer), // union
			extra_value((void*)id), // union
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr),
			string_parser(name)
		{

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
