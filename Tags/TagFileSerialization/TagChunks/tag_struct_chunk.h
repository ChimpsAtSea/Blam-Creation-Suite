#pragma once

class c_tag_struct_chunk : public c_typed_chunk<'tgst', true>
{
public:
	BCS_SHARED c_tag_struct_chunk(c_chunk& parent);
	BCS_SHARED virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
};
