#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_target_tracking_parameters_block, 1)
{
	FIELD( _field_block, "tracking types#specify the kinds of targets this tracking system can lock on", &tracking_type_block_block ),
	FIELD( _field_real, "acquire time:s" ),
	FIELD( _field_real, "grace time:s" ),
	FIELD( _field_real, "decay time:s" ),
	FIELD( _field_tag_reference, "tracking sound" ),
	FIELD( _field_tag_reference, "locked sound" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(tracking_type_block, 16)
{
	FIELD( _field_string_id, "tracking type^" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

