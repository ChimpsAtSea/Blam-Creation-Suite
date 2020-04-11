#pragma once

struct nicename("decorator_set") tag_group('dctr') s_decorator_set_definition
{
	enum nicename("Is Visible? (Can Crash Xbox!)") e_is_visible_can_crash_xbox : uint16_t
	{
		/*nicename("Yes")*/ _is_visible_can_crash_xbox_yes = 1ui16,
		/*nicename("No")*/ _is_visible_can_crash_xbox_no = 2ui16,
	};

	enum nicename("Lod Type") e_lod_type : uint16_t
	{
		/*nicename("1 Model")*/ _lod_type__1_model = 1ui16,
		/*nicename("2 Models")*/ _lod_type__2_models = 2ui16,
		/*nicename("3 Models")*/ _lod_type__3_models = 3ui16,
		/*nicename("4 Models")*/ _lod_type__4_models = 4ui16,
	};

	struct nicename("Parts") s_parts_definition
	{
		DEPRECATED_string_id nicename("Name") name;
	};

	TagReference nicename("Lod Model 1") lod_model_1_reference;
	TagReference nicename("Lod Model 2") lod_model_2_reference;
	TagReference nicename("Lod Model 3") lod_model_3_reference;
	TagReference nicename("Lod Model 4") lod_model_4_reference;
	s_tag_block_definition<s_parts_definition> nicename("Parts") parts_block;
	int32_t __unknown0;
	TagReference nicename("Texture") texture_reference;
	int16_t nicename("Affects Visibility") affects_visibility;
	int16_t __unknown1;
	colorf nicename("Color?") color;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	float nicename("Brightness (Base)") brightness_base;
	float nicename("Brightness (Shadow)") brightness_shadow;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	e_is_visible_can_crash_xbox nicename("Is Visible? (Can Crash Xbox!)") is_visible_can_crash_xbox;
	e_lod_type nicename("Lod Type") lod_type;
	float nicename("Lod 1 ...?") lod_1_;
	float nicename("Lod 1 ...?") lod_1_1;
	float nicename("Lod 1 Activation Distance (negative)") lod_1_activation_distance_negative;
	float nicename("Lod 1 Range") lod_1_range;
	float nicename("Lod 2 ...?") lod_2_;
	float nicename("Lod 2 ...?") lod_2_1;
	float nicename("Lod 2 Activation Distance (negative)") lod_2_activation_distance_negative;
	float nicename("Lod 2 Range") lod_2_range;
	float nicename("Lod 3 ...?") lod_3_;
	float nicename("Lod 3 ...?") lod_3_1;
	float nicename("Lod 3 Activation Distance (negative)") lod_3_activation_distance_negative;
	float nicename("Lod 3 Range") lod_3_range;
	float nicename("Lod 4 ...?") lod_4_;
	float nicename("Lod 4 ...?") lod_4_1;
	float nicename("Lod 4 Activation Distance (negative)") lod_4_activation_distance_negative;
	float nicename("Lod 4 Range") lod_4_range;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	Undefined32 __unknown18;
};

