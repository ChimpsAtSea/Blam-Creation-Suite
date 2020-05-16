#include <blamboozlelib-private-pch.h>

c_h4_tag_enum::c_h4_tag_enum(const char* h4_data, const s_h4_tag_enum_definition* enum_definition) :
	name(),
	filename(),
	enum_definition(enum_definition)
{
	const bpointer32<const char*>* options_address = h4_va_to_pointer<const bpointer32<const char*>>(h4_data, enum_definition->options_address);
	for (uint32_t option_index = 0; option_index < enum_definition->option_count; option_index++)
	{
		const bpointer32<const char*>& option_address = options_address[option_index];
		const char* option = h4_va_to_pointer(h4_data, option_address);

		options.push_back(option);
	}
}
