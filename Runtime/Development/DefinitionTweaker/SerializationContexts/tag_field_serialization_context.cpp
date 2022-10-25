#include "definitiontweaker-private-pch.h"

c_tag_field_serialization_context::c_tag_field_serialization_context(c_tag_serialization_context& _serialization_context) :
	serialization_context(_serialization_context)
{

}

c_tag_field_serialization_context::~c_tag_field_serialization_context()
{
	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}
