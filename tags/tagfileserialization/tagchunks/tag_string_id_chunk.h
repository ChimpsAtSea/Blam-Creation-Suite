#pragma once

class c_tag_string_id_chunk : public c_typed_chunk<'tgsi', false>
{
public:
	const char* string;

	BCS_SHARED c_tag_string_id_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_string_id_chunk();

	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	BCS_SHARED virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	BCS_SHARED virtual BCS_RESULT set_string(const char* string);
	void read_data();

protected:
	BCS_SHARED virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
};
