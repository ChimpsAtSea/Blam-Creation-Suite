#include <blamboozlelib-private-pch.h>

c_h4_tag_enum::c_h4_tag_enum(const char* h4_data, const s_h4_tag_enum_definition* enum_definition) :
	enum_definition(enum_definition),
	name(h4_va_to_pointer(h4_data, enum_definition->name)),
	filepath(h4_va_to_pointer(h4_data, enum_definition->filepath)),
	line_number(enum_definition->line_number)
{
	const bptr32<const char*>* options_address = h4_va_to_pointer<const bptr32<const char*>>(h4_data, enum_definition->options);
	for (unsigned long option_index = 0; option_index < enum_definition->option_count; option_index++)
	{
		const bptr32<const char*>& option_address = options_address[option_index];
		const char* option = h4_va_to_pointer(h4_data, option_address);

		options.push_back(option);
	}
}
