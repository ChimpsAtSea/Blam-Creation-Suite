#pragma once

struct nicename("Cloth") group('clwd') s_cloth_definition
{
	struct nicename("Vertices") s_vertex_block_definition;
	struct nicename("Indices") s_index_block_definition;
	struct nicename("Links") s_link_block_definition;

	int32_t nicename("Flags") flags; 
	string_id nicename("Marker Attachment Name") marker_attachment_name; 
	string_id nicename("Second Marker Attachment Name") second_marker_attachment_name; 
	TagReference nicename("Shader") shader_reference; 
	int16_t nicename("Grid X Dimension") grid_x_dimension; 
	int16_t nicename("Grid Y Dimension") grid_y_dimension; 
	float nicename("Grid Spacing X") grid_spacing_x; 
	float nicename("Grid Spacing Y") grid_spacing_y; 
	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	int16_t nicename("Integration Type") integration_type; 
	int16_t nicename("Number Iterations") number_iterations; 
	float nicename("Weight") weight; 
	float nicename("Drag") drag; 
	float nicename("Wind Scale") wind_scale; 
	float nicename("Wind Flappiness Scale") wind_flappiness_scale; 
	float nicename("Longest Rod") longest_rod; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	Undefined32 __unknown9; 
	s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 
	s_tag_block_definition<s_index_block_definition> nicename("Indices") indices_block; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	s_tag_block_definition<s_link_block_definition> nicename("Links") links_block; 

	struct nicename("vertex") s_vertex_block_definition
	{
		float nicename("Initial Position X") initial_position_x; 
		float nicename("Initial Position Y") initial_position_y; 
		float nicename("Initial Position Z") initial_position_z; 
		float nicename("UV i") uv_i; 
		float nicename("UV j") uv_j; 
	};

	struct nicename("index") s_index_block_definition
	{
		int16_t nicename("Index") index; 
	};

	struct nicename("link") s_link_block_definition
	{
		float nicename("Default Distance") default_distance; 
		int32_t nicename("Index 1") index_1; 
		int32_t nicename("Index 2") index_2; 
		Undefined32 __unknown; 
	};
};
