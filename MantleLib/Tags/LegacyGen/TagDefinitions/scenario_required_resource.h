#pragma once

struct nicename("scenario_required_resource") tag_group('sdzg') s_scenario_required_resource_definition
{
	struct nicename("Required Objects") s_required_objects_definition
	{
		s_tag_reference_legacy nicename("Object") object_reference;
	};

	s_tag_block_legacy<s_required_objects_definition> nicename("Required Objects") required_objects_block;
};

