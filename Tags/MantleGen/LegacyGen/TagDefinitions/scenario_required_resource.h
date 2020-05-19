#pragma once

struct nicename("scenario_required_resource") tag_group('sdzg') s_scenario_required_resource_definition_legacy
{
	struct nicename("Required Objects") s_required_objects_definition_legacy
	{
		s_tag_reference_legacy nicename("Object") object_reference;
	};

	s_tag_block_legacy<s_required_objects_definition_legacy> nicename("Required Objects") required_objects_block;
};

