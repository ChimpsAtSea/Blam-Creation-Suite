#include "definitiontweaker-private-pch.h"

#define THEME_FATAL_ERROR_TEXT(v) { 1.000f, 0.375f, 0.375f, v }
#define THEME_DATA_VALIDATION_OK_TEXT(v) { 0.796f, 0.965f, 0.808f, v }
#define THEME_BLOCK_VALIDATION_ERROR_TEXT(v) { 0.475f, 0.950f, 0.950f, v }
#define THEME_DATA_VALIDATION_ERROR_TEXT(v) { 0.950f, 0.475f, 0.950f, v }

ImVec4 serialization_error_colors[k_num_serialization_error_types] =
{
	THEME_DATA_VALIDATION_OK_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	MANDRILL_THEME_WARNING_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	MANDRILL_THEME_ERROR_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	THEME_FATAL_ERROR_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	THEME_BLOCK_VALIDATION_ERROR_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	THEME_DATA_VALIDATION_ERROR_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
};

c_serialization_error::c_serialization_error(e_serialization_error_type _error_type) :
	error_type(_error_type)
{

}
c_serialization_error::~c_serialization_error()
{

}

c_generic_serialization_error::c_generic_serialization_error(e_serialization_error_type error_type, const char* _error_format, ...) :
	c_serialization_error(error_type),
	error(nullptr)
{
	va_list virtual_argument_list;
	va_start(virtual_argument_list, _error_format);
	int buffer_size = vsnprintf(nullptr, 0, _error_format, virtual_argument_list);
	char* buffer = trivial_alloca(char, buffer_size + 1);
	ASSERT(vsnprintf(buffer, buffer_size + 1, _error_format, virtual_argument_list) == buffer_size);
	buffer[buffer_size] = 0;
	va_end(virtual_argument_list);
	error = strdup(buffer);
}

c_generic_serialization_error::~c_generic_serialization_error()
{
	untracked_free(error);
}

void c_generic_serialization_error::render()
{
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[error_type]);
	ImGui::TextUnformatted(error);
	ImGui::PopStyleColor();
}
