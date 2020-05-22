#pragma once

struct nicename("emblem_library") tag_group('mlib') s_emblem_library_definition_legacy
{
	struct nicename("Foregrounds") s_foregrounds_definition_legacy
	{
		// Secondary : 
		int16_t nicename("Sequence Index") sequence_index;
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		int16_t __unknown4;
		float nicename("Scale x") scale_x;
		float nicename("Skew x") skew_x;
		float nicename("Position x") position_x;
		s_undefined32_legacy __unknown5;
		float nicename("Skew y") skew_y;
		float nicename("Scale y") scale_y;
		float nicename("Position y") position_y;
		s_undefined32_legacy __unknown6;
		float nicename("Mask Scale x") mask_scale_x;
		float nicename("Mask Skew x") mask_skew_x;
		float nicename("Mask Position x") mask_position_x;
		s_undefined32_legacy __unknown7;
		float nicename("Mask Skew y") mask_skew_y;
		float nicename("Mask Scale y") mask_scale_y;
		float nicename("Mask Position y") mask_position_y;
		s_undefined32_legacy __unknown8;
		float nicename("Edge Hardness") edge_hardness;
		float __unknown9;
		float nicename("Edge Refinement") edge_refinement;
		float nicename("Alpha") alpha;
		float nicename("Mask Edge Hardness") mask_edge_hardness;
		float __unknown10;
		float nicename("Mask Edge Refinement") mask_edge_refinement;
		float nicename("Mask Alpha") mask_alpha;
		// Primary : 
		int16_t nicename("Sequence Index") sequence_index1;
		int16_t __unknown11;
		int16_t __unknown12;
		int16_t __unknown13;
		int16_t __unknown14;
		int16_t __unknown15;
		float nicename("Scale x") scale_x1;
		float nicename("Skew x") skew_x1;
		float nicename("Position x") position_x1;
		s_undefined32_legacy __unknown16;
		float nicename("Skew y") skew_y1;
		float nicename("Scale y") scale_y1;
		float nicename("Position y") position_y1;
		s_undefined32_legacy __unknown17;
		float nicename("Mask Scale x") mask_scale_x1;
		float nicename("Mask Skew x") mask_skew_x1;
		float nicename("Mask Position x") mask_position_x1;
		s_undefined32_legacy __unknown18;
		float nicename("Mask Skew y") mask_skew_y1;
		float nicename("Mask Scale y") mask_scale_y1;
		float nicename("Mask Position y") mask_position_y1;
		s_undefined32_legacy __unknown19;
		float nicename("Edge Hardness") edge_hardness1;
		float __unknown20;
		float nicename("Edge Refinement") edge_refinement1;
		float nicename("Front Alpha") front_alpha;
		float nicename("Mask Edge Hardness") mask_edge_hardness1;
		float __unknown21;
		float nicename("Mask Edge Refinement") mask_edge_refinement1;
		float nicename("Mask Alpha") mask_alpha1;
		int8_t __unknown22;
		int8_t __unknown23;
		int8_t __unknown24;
		int8_t __unknown25;
	};

	struct nicename("Backgrounds") s_backgrounds_definition_legacy
	{
		int16_t nicename("Sequence Index") sequence_index;
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		int16_t __unknown4;
		float nicename("Scale x") scale_x;
		float nicename("Skew x") skew_x;
		float nicename("Position x") position_x;
		s_undefined32_legacy __unknown5;
		float nicename("Skew y") skew_y;
		float nicename("Scale y") scale_y;
		float nicename("Position y") position_y;
		s_undefined32_legacy __unknown6;
		float nicename("Mask Scale x") mask_scale_x;
		float nicename("Mask Skew x") mask_skew_x;
		float nicename("Mask Position x") mask_position_x;
		s_undefined32_legacy __unknown7;
		float nicename("Mask Skew y") mask_skew_y;
		float nicename("Mask Scale y") mask_scale_y;
		float nicename("Mask Position y") mask_position_y;
		s_undefined32_legacy __unknown8;
		float nicename("Edge Hardness") edge_hardness;
		float __unknown9;
		float nicename("Edge Refinement") edge_refinement;
		float nicename("Alpha") alpha;
		float nicename("Mask Edge Hardness") mask_edge_hardness;
		float __unknown10;
		float nicename("Mask Edge Refinement") mask_edge_refinement;
		float nicename("Mask Alpha") mask_alpha;
	};

	int16_t __unknown0;
	int16_t __unknown1;
	float __unknown2;
	float __unknown3;
	s_tag_reference_legacy nicename("Emblem Bitmap") emblem_bitmap_reference;
	s_tag_reference_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_tag_block_legacy<s_foregrounds_definition_legacy> nicename("Foregrounds") foregrounds_block;
	s_tag_block_legacy<s_backgrounds_definition_legacy> nicename("Backgrounds") backgrounds_block;
};

