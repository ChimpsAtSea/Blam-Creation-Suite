#pragma once

struct nicename("Cloth") group('clwd') s_cloth_definition
{
	struct nicename("Vertices") s_vertex_block_definition;
	struct nicename("Indices") s_index_block_definition;
	struct nicename("Links") s_link_block_definition;

	signed int nicename("Flags") flags; 
	string_id nicename("Marker Attachment Name") marker_attachment_name; 
	string_id nicename("Second Marker Attachment Name") second_marker_attachment_name; 
	TagReference nicename("Shader") shader_reference; 
	signed short nicename("Grid X Dimension") grid_x_dimension; 
	signed short nicename("Grid Y Dimension") grid_y_dimension; 
	float nicename("Grid Spacing X") grid_spacing_x; 
	float nicename("Grid Spacing Y") grid_spacing_y; 
	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	signed short nicename("Integration Type") integration_type; 
	signed short nicename("Number Iterations") number_iterations; 
	float nicename("Weight") weight; 
	float nicename("Drag") drag; 
	float nicename("Wind Scale") wind_scale; 
	float nicename("Wind Flappiness Scale") wind_flappiness_scale; 
	float nicename("Longest Rod") longest_rod; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 
	s_tag_block_definition<s_index_block_definition> nicename("Indices") indices_block; 
	Unknown32 __unknown10; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
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
		signed short nicename("Index") index; 
	};

	struct nicename("link") s_link_block_definition
	{
		float nicename("Default Distance") default_distance; 
		signed int nicename("Index 1") index_1; 
		signed int nicename("Index 2") index_2; 
		Unknown32 __unknown; 
	};
};
