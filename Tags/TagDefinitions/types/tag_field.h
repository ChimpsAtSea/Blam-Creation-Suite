#pragma once

#pragma warning( push )
#pragma warning( disable : 4312 ) // warning C4312: 'type cast': conversion from 'A' to 'void *' of greater size

namespace blofeld
{
	using t_tag_field_custom_version_callback = long(*)(s_engine_platform_build engine_platform_build);

	struct s_tag_field
	{
		e_field const field_type;
		const char* const name;
		const char* const description;
		const char* const units;
		const char* const limits;
		const char** const old_names;
		unsigned long const flags;
		const char* const filename;
		long const line;
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
			unsigned long padding; // #todo remove from union
			unsigned long length; // #todo remove from union
		};
		union
		{
			const void* const extra_value; // #todo remove
			unsigned long custom_type; // #todo remove
			e_field_id id;
		};
		//enum e_build const min_version;
		//enum e_build const max_version;

		s_engine_platform_build engine_platform_build;
		unsigned long _version_field_skip_count;
		t_tag_field_custom_version_callback _custom_version_callback;
		//c_blamlib_string_parser string_parser;

	public:
		template<typename A, typename B>
		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			long line,
#endif
			const char* name,
			A&& pointer,
			B&& extra_value) :
			field_type(field_type),
			name(name),
			description(),
			units(),
			limits(),
			old_names(),
			flags(),
			filename(filename),
			line(line),
			pointer((void*)(pointer)),
			extra_value((void*)(extra_value)),
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
			//string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		template<typename A>
		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			long line,
#endif
			const char* name,
			A&& pointer) :
			field_type(field_type),
			name(name),
			description(),
			units(),
			limits(),
			old_names(),
			flags(),
			filename(filename),
			line(line),
			pointer((void*)(pointer)),
			extra_value(nullptr),
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
			//string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			long line,
#endif
			const char* name) :
			field_type(field_type),
			name(name),
			description(),
			units(),
			limits(),
			old_names(),
			flags(),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
			//string_parser(name)
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type
#ifndef __INTELLISENSE__
			, const char* filename
			, int line
#endif
		) :
			field_type(field_type),
			name(nullptr),
				description(),
				units(),
				limits(),
				old_names(),
				flags(),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
			//string_parser("")
		{
			ASSERT(field_type < _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			long line,
#endif
			c_engine_platform_build engine_type_and_build,
			unsigned long version_field_skip_count = 1) :
			field_type(field_type),
			name(nullptr),
			description(),
			units(),
			limits(),
			old_names(),
			flags(),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			engine_platform_build(engine_type_and_build),
			_version_field_skip_count(version_field_skip_count),
			_custom_version_callback(nullptr)
			//string_parser(name)
		{
			ASSERT(field_type > _field_type_non_standard);
		}

		s_tag_field(
			e_field_legacy,
			e_field field_type,
#ifndef __INTELLISENSE__
			const char* filename,
			long line,
#endif
			t_tag_field_custom_version_callback custom_version_callback) :
			field_type(field_type),
			name(nullptr),
			description(),
			units(),
			limits(),
			old_names(),
			flags(),
			filename(filename),
			line(line),
			pointer(nullptr),
			extra_value(nullptr),
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(custom_version_callback)
			//string_parser("")
		{
			ASSERT(field_type == _field_version_custom);
		}

		// type #WARN: Must only be used with _field_terminator
		s_tag_field(e_field type HIDDEN(, const char* filename, int line)) :
			s_tag_field(type HIDDEN(, filename, line), nullptr, nullptr, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default)
		{
			DEBUG_ONLY(if (type != _field_terminator) FATAL_ERROR("Invalid tag constructor usage (expected type == _field_terminator) %S:%i", filename, line));
		};
		
		// type, name
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, FLAGS, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, unsigned long flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, nullptr, id) {};

		// type, name, description
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, description, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, description, units
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description, units, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, nullptr, _field_id_default) {};

		// type, name, description, units, FLAGS, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, unsigned long flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, nullptr, id) {};

		// type, name, description, units, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, 0, nullptr, id) {};

		// type, name, description, units, limits
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, 0, nullptr, _field_id_default) {};

		// type, name, description, units, limits, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, flags, nullptr, _field_id_default) {};



		// type, name, old-names-array
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, 0, nullptr, _field_id_default) {};

		// type, name, old-names-array, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, 0, nullptr, id) {};

		// type, name, old-names-array, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, flags, nullptr, _field_id_default) {};

		// type, name, old-names-array, FLAGS, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, unsigned long flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, flags, nullptr, id) {};

		// type, name, description, old-names-array
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, 0, nullptr, _field_id_default) {};

		// type, name, description, old-names-array, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, flags, nullptr, _field_id_default) {};

		// type, name, description, old-names-array, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, 0, nullptr, id) {};

		// type, name, description, units, old-names-array
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, 0, nullptr, _field_id_default) {};

		// type, name, description, units, old-names-array, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, flags, nullptr, _field_id_default) {};

		// type, name, description, units, old-names-array, FLAGS, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names, unsigned long flags, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, flags, nullptr, id) {};

		// type, name, description, units, old-names-array, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names, e_field_id id) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, 0, nullptr, id) {};

		// type, name, description, units, limits, old-names-array
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, const char** old_names) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, old_names, 0, nullptr, _field_id_default) {};

		// type, name, description, units, limits, old-names-array, FLAGS
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, const char** old_names, unsigned long flags) :
			s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, old_names, flags, nullptr, _field_id_default) {};

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
		
		// type, name, description, units, limits, old-names-array, FLAGS, pointer, id
		s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, const char** old_names, unsigned long flags, const void* pointer, e_field_id id) :
			field_type(type),
			name(name),
			description(description),
			units(units),
			limits(limits),
			old_names(old_names),
			flags(flags),
#ifndef HIDDEN_CODE
			filename(filename),
			line(line),
#else
			filename(""),
			line(0),
#endif
			pointer(pointer), // union
			extra_value((void*)id), // union
			engine_platform_build(),
			_version_field_skip_count(0),
			_custom_version_callback(nullptr)
			//string_parser(name)
		{

		}
	};

	inline bool skip_tag_field_version(s_tag_field const& tag_field, s_engine_platform_build engine_platform_build, unsigned long& skip_count)
	{
		if (tag_field.field_type > _field_type_non_standard)
		{
			bool skip_versioning_field = false;
			skip_count = tag_field._version_field_skip_count;

			if (tag_field.field_type == _field_version_custom)
			{
				ASSERT(tag_field._custom_version_callback);
				skip_count = tag_field._custom_version_callback(engine_platform_build);
				skip_versioning_field = false;
			}
			else if (tag_field.field_type == _field_version_platform_include)
			{
				if (tag_field.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
				}
			}
			else if (tag_field.field_type == _field_version_platform_exclude)
			{
				if (tag_field.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
				}
			}
			else
			{
				switch (tag_field.field_type)
				{
				case _field_version_equal:
					skip_versioning_field = engine_platform_build == tag_field.engine_platform_build;
					break;
				case _field_version_not_equal:
					skip_versioning_field = engine_platform_build != tag_field.engine_platform_build;
					break;
				case _field_version_less:
					skip_versioning_field = engine_platform_build < tag_field.engine_platform_build;
					break;
				case _field_version_greater:
					skip_versioning_field = engine_platform_build > tag_field.engine_platform_build;
					break;
				case _field_version_less_or_equal:
					skip_versioning_field = engine_platform_build <= tag_field.engine_platform_build;
					break;
				case _field_version_greater_or_equal:
					skip_versioning_field = engine_platform_build >= tag_field.engine_platform_build;
					break;
				}
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
