#include "definitiontweaker-private-pch.h"

c_group_serialization_context::c_group_serialization_context(c_runtime_tag_group_definition& _tag_group) :
	max_serialization_error_type(_tag_serialization_state_error),
	tag_group(_tag_group)
{

}

void c_group_serialization_context::post()
{
	for (c_tag_serialization_context* serialization_context : serialization_contexts)
	{
		max_serialization_error_type = __max(max_serialization_error_type, serialization_context->max_serialization_error_type);
	}
}
