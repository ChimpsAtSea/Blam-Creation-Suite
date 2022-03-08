#pragma once

class c_string_data_chunk : public c_typed_chunk<'str*', false>
{
public:

	c_string_data_chunk(c_chunk& parent);
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;

};
