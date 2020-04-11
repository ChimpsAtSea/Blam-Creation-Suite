#pragma once

struct nicename("cheap_particle_type_library") tag_group('cptl') s_cheap_particle_type_library_definition
{
	struct nicename("Particle Type Library") s_particle_type_library_definition
	{
		string_id_legacy nicename("Name") name;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		int32_t nicename("Sibling Index") sibling_index;
		int32_t __unknown6;
		float nicename("Alpha") alpha;
		s_colorf_legacy nicename("Color") color;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		int32_t nicename("Bitmap Index") bitmap_index;
		s_undefined32_legacy __unknown12;
	};

	struct nicename("Bitmaps") s_bitmaps_definition
	{
		s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	};

	s_tag_block_legacy<s_particle_type_library_definition> nicename("Particle Type Library") particle_type_library_block;
	s_tag_block_legacy<s_bitmaps_definition> nicename("Bitmaps") bitmaps_block;
	s_tag_reference_legacy nicename("Random Map") random_map_reference;
	s_tag_reference_legacy nicename("Turbulence Map") turbulence_map_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	s_tag_reference_legacy nicename("Global Type Texture") global_type_texture_reference;
	s_tag_reference_legacy nicename("Global Render Texture") global_render_texture_reference;
};

