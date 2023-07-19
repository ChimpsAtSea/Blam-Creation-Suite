#include "highlevelcachefileserialization-private-pch.h"

BCS_RESULT iterate_prototype_references(h_prototype& prototype, void(*callback)(void* userdata, h_tag_reference&), void* userdata)
{
	using namespace blofeld;

	BCS_RESULT rs = BCS_S_OK;

	h_prototype_serialization_info const& prototype_serialization_info = prototype.get_serialization_information();
	for (unsigned int field_serialization_index = 0; field_serialization_index < prototype_serialization_info.num_field_serialization_infos; field_serialization_index++)
	{
		h_field_serialization_info const& field_serialization_info = prototype_serialization_info.field_serialization_infos[field_serialization_index];
		s_tag_field const& tag_field = prototype_serialization_info.tag_struct_definition.fields[field_serialization_info.blofeld_field_index];

		if (field_serialization_info.pointer_to_member == nullptr)
		{
			continue;
		}

		h_type& field_data = prototype.*field_serialization_info.pointer_to_member;

		switch (tag_field.field_type)
		{
		case _field_tag_reference:
		{
			h_tag_reference* tag_reference = high_level_cast<h_tag_reference*>(&field_data);
			ASSERT(tag_reference != nullptr);

			callback(userdata, *tag_reference);
		}
		break;
		case _field_struct:
		{
			h_prototype* struct_prototype = high_level_cast<h_prototype*>(&field_data);
			ASSERT(struct_prototype != nullptr);

			if (BCS_FAILED(rs = iterate_prototype_references(*struct_prototype, callback, userdata)))
			{
				return rs;
			}
		}
		break;
		case _field_array:
		{
			h_array* _array = high_level_cast<h_array*>(&field_data);
			ASSERT(_array != nullptr);

			for (h_prototype* array_prototype : *_array)
			{
				if (BCS_FAILED(rs = iterate_prototype_references(*array_prototype, callback, userdata)))
				{
					return rs;
				}
			}
		}
		break;
		case _field_block:
		{
			h_block* block = high_level_cast<h_block*>(&field_data);
			ASSERT(block != nullptr);

			for (h_prototype* block_prototype : *block)
			{
				if (BCS_FAILED(rs = iterate_prototype_references(*block_prototype, callback, userdata)))
				{
					return rs;
				}
			}
		}
		break;
		}
	}

	return rs;
}

BCS_RESULT iterate_prototype_references(h_prototype& prototype, void(*callback)(h_tag_reference&))
{
	return iterate_prototype_references(
		prototype,
		[](void* userdata, h_tag_reference& target)
		{
			void(*callback)(h_tag_reference&) = reinterpret_cast<decltype(callback)>(userdata);
			return callback(target);
		},
		&callback);
}

