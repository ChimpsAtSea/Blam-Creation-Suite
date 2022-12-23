#pragma once

class c_build_identifier_chunk : public c_typed_chunk<'id#6', false>
{
public:
	uint64_t id;

	BCS_SHARED c_build_identifier_chunk(c_chunk& parent);

	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};
