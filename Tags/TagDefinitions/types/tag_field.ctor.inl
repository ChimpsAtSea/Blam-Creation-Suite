
// type, name, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, pointer, _field_id_default) {};

// type, name, FLAGS, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, pointer, _field_id_default) {};

// type, name, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, 0, pointer, id) {};

// type, name, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, nullptr, flags, pointer, id) {};

// type, name, description, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, pointer, _field_id_default) {};

// type, name, description, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, 0, pointer, id) {};

// type, name, description, FLAGS, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, flags, pointer, _field_id_default) {};

// type, name, description, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, nullptr, flags, pointer, id) {};

// type, name, description, units, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, 0, pointer, _field_id_default) {};

// type, name, description, units, limits, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, 0, pointer, _field_id_default) {};

// type, name, description, units, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, pointer, id) {};

// type, name, description, units, limits, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, nullptr, flags, pointer, id) {};


// type, name, old-names-array, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, 0, pointer, _field_id_default) {};

// type, name, old-names-array, FLAGS, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, flags, pointer, _field_id_default) {};

// type, name, old-names-array, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, 0, pointer, id) {};

// type, name, old-names-array, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char** old_names, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, nullptr, nullptr, nullptr, old_names, flags, pointer, id) {};

// type, name, description, old-names-array, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, 0, pointer, _field_id_default) {};

// type, name, description, old-names-array, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, 0, pointer, id) {};

// type, name, description, old-names-array, FLAGS, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, flags, pointer, _field_id_default) {};

// type, name, description, units, old-names-array, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, nullptr, flags, pointer, _field_id_default) {};

// type, name, description, units, FLAGS, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, 0, pointer, _field_id_default) {};

// type, name, description, units, limits, old-names-array, pointer
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char* limits, const char** old_names, const __tag_field_pointer_type__* pointer) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, limits, old_names, 0, pointer, _field_id_default) {};

// type, name, description, old-names-array, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char** old_names, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, nullptr, nullptr, old_names, flags, pointer, id) {};

// type, name, description, units, old-names-array, FLAGS, pointer, id
s_tag_field(e_field type HIDDEN(, const char* filename, int line), const char* name, const char* description, const char* units, const char** old_names, c_flags<e_tag_field_flag> flags, const __tag_field_pointer_type__* pointer, e_field_id id) :
	s_tag_field(type HIDDEN(, filename, line), name, description, units, nullptr, old_names, flags, pointer, id) {};
