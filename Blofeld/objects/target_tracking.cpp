#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_target_tracking_parameters, 1)
{
	{ _field_block, "tracking types#specify the kinds of targets this tracking system can lock on", &tracking_type_block },
	{ _field_real, "acquire time:s" },
	{ _field_real, "grace time:s" },
	{ _field_real, "decay time:s" },
	{ _field_tag_reference, "tracking sound" },
	{ _field_tag_reference, "locked sound" },
	{ _field_terminator },
};

TAG_BLOCK(tracking_type, 16)
{
	{ _field_string_id, "tracking type^" },
	{ _field_terminator },
};

} // namespace blofeld

