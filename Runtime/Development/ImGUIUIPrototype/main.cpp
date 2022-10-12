#include "imguiuiprototype-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif

static c_window* window;
static c_render_context* window_render_context;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

void mandrill(c_window& window);


#define MANDRILL_THEME_HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MANDRILL_THEME_MED(v) { 0.455f, 0.198f, 0.301f, v }
#define MANDRILL_THEME_LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define MANDRILL_THEME_DISABLED_HIGH(v) { 0.224f, 0.224f, 0.224f, v }
#define MANDRILL_THEME_DISABLED_MED(v) { 0.286f, 0.286f, 0.286f, v }
#define MANDRILL_THEME_DISABLED_LOW(v) { 0.215f, 0.215f, 0.215f, v }
#define MANDRILL_THEME_BG(v) { 0.200f, 0.220f, 0.270f, v }
#define MANDRILL_THEME_TEXT(v) { 0.930f, 0.965f, 0.945f, v }
#define MANDRILL_THEME_COMMENT_TEXT(v) { 0.752f, 0.965f, 0.766f, v }
#define MANDRILL_THEME_ERROR_TEXT(v) { 0.950f, 0.475f, 0.475f, v }
#define MANDRILL_THEME_INFO_TEXT(v) { 0.796f, 0.808f, 0.965f, v }
#define MANDRILL_THEME_MENU(v) { 0.377f, 0.377f, 0.377f, v }

constexpr float MANDRILL_THEME_DEFAULT_TEXT_ALPHA = 0.78f;


struct s_parent_entry
{
	uint32_t index;
	const char* name;
};

void draw_parents(s_parent_entry* entry_start, s_parent_entry* entry_end)
{
	ImGuiWindowFlags flags = 0;
	flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
	ImVec2 x = ImGui::GetContentRegionAvail();
	if (ImGui::BeginChild("", x, flags))
	{

		static ImGuiTableFlags flags =
			ImGuiTableFlags_Borders |
			ImGuiTableFlags_NoBordersInBodyUntilResize;



		uint32_t previous_index = 0;
		bool display_table = false;
		for (s_parent_entry* entry = entry_start; entry < entry_end; entry++)
		{
			if (previous_index != entry->index)
			{
				previous_index = entry->index;
				if (display_table)
				{
					ImGui::EndTable();
				}

				int total = 0;
				for (s_parent_entry* _entry = entry_start; _entry < entry_end; _entry++) if (entry->index == _entry->index) { total++; }
				ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
				if (entry->index <= 1)
				{
					ImGui::Text("Immediate Relatives (%i total)", total);
				}
				else
				{
					ImGui::Text("Relatives %i Steps Away (%i total)", entry->index, total);
				}
				ImGui::PopStyleColor();

				if (display_table = ImGui::BeginTable("parents", 3, flags))
				{
					ImGui::TableSetupColumn(nullptr, ImGuiTableColumnFlags_NoHeaderLabel | ImGuiTableColumnFlags_WidthFixed);
					ImGui::TableSetupColumn(nullptr, ImGuiTableColumnFlags_NoHeaderLabel);
					ImGui::TableSetupColumn(nullptr, ImGuiTableColumnFlags_NoHeaderLabel | ImGuiTableColumnFlags_WidthFixed);
				}
			}

			ImGui::TableNextRow();
			{
				ImGui::TableSetColumnIndex(0);
				{
					ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
					char buffer[21];
					itoa(entry->index, buffer, 10);
					if (ImGui::Button(buffer))
					{

					}
					ImGui::PopItemFlag();
				}
				ImGui::TableSetColumnIndex(1);
				{
					ImGui::TextUnformatted(entry->name);
				}
				ImGui::TableSetColumnIndex(2);
				{
					if (ImGui::Button(".."))
					{

					}
				}
			}

		}
		if (display_table)
		{
			ImGui::EndTable();
		}

		ImGui::EndChild();
	}
	debug_point;
}

void draw_self()
{
	static ImGuiTableFlags flags =
		ImGuiTableFlags_Borders |
		ImGuiTableFlags_NoBordersInBodyUntilResize;
	if (ImGui::BeginTable("self", 2, flags))
	{
		ImGui::TableSetupColumn(nullptr, ImGuiTableColumnFlags_NoHeaderLabel);
		ImGui::TableSetupColumn(nullptr, ImGuiTableColumnFlags_NoHeaderLabel | ImGuiTableColumnFlags_WidthStretch);

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Name");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextUnformatted("reflection_lighting_test");
		}

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Extension");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextUnformatted("biped");
		}

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Path");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextEx("objects\\reference\\reflection_lighting_test", nullptr, ImGuiTextFlags_NoWidthForLargeClippedText);
		}

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Type");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextUnformatted("Tag");
		}

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Age");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextUnformatted("420 minutes and 69 seconds");
		}

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			ImGui::TextUnformatted("Source");
			ImGui::TableSetColumnIndex(1);
			ImGui::TextUnformatted("(Read-Only) Built-in tag");
		}

		ImGui::EndTable();
	}
}


s_parent_entry parents[] =
{
	{ 1, "battle_rifle_rubber.shader" },
	{ 1, "scorch_detail.bitmap" },
	{ 1, "stencil_stipple.vertex_shader" },
	{ 1, "gun_l_snow.model" },
	{ 1, "pelican_black_glass.shader" },
	{ 1, "firing.light" },
	{ 1, "rudder_right.collision_model" },
	{ 1, "_2_10_1_1_0_3.vertex_shader" },
	{ 1, "fxaa.vertex_shader" },
	{ 1, "_3_10_0_2_1_1_1_0_0_0.vertex_shader" },
	{ 1, "olifaunt_hatch.physics_model" },
	{ 1, "gun_rack.bitmap" },
	{ 1, "projectile.effect" },
	{ 1, "_0_0_0_1_0_1_0_0_0_0.vertex_shader" },
	{ 1, "_0_0_0_0_7_0_0_3_0_0.render_method_template" },
	{ 1, "pelican_glass.shader" },
	{ 1, "_0_1_0_1_2_0_0_0_0_0.vertex_shader" },
	{ 2, "firing.light" },
	{ 2, "gun.model" },
	{ 2, "pathfinding_vehicle.model" },
	{ 2, "downsample_4x4_gaussian_hlsl.hlsl_include" },
	{ 2, "banshee_destroyed.model" },
	{ 2, "seat.physics_model" },
	{ 2, "tank_shell.projectile" },
	{ 2, "chud_texture_cam.hlsl_include" },
	{ 2, "_2_1_0_0_0_0_0.vertex_shader" },
	{ 2, "_0_8_1_0_0_3_1.pixel_shader" },
	{ 2, "cargo_shelf.model" },
	{ 2, "hull_garbage.model" },
	{ 3, "detonation.light" },
	{ 3, "tether_main.shader" },
	{ 3, "_0_0_0_1_2_2_0_0_0_0.render_method_template" },
	{ 3, "driver_hatch.crate" },
	{ 3, "anti_air_turret.projectile" },
	{ 3, "impact.effect" },
	{ 3, "_0_0_0_2_2_1_0_3_0_0.vertex_shader" },
	{ 3, "electric_bolts.particle" },
	{ 3, "spike_blur_vertical.pixel_shader" },
	{ 4, "_0_8_1_0_1_2_0.render_method_template" },
	{ 4, "contrail_spawn.pixel_shader" },
	{ 4, "backwash_fire.particle" },
	{ 4, "albedo_custom.hlsl_include" },
	{ 4, "beam_rifle.bitmap" },
	{ 4, "hornet_bullet.projectile" },
	{ 4, "_0_3_0_0_0_1_1_1_0_1.pixel_shader" },
	{ 4, "_1_10_0_0_0_1_1_1_0_0.vertex_shader" },
	{ 4, "bed_long.collision_model" },
	{ 4, "phantom_destroyed_detail01.bitmap" },
	{ 4, "pelican_rocket_pod02.model" },
	{ 4, "texture_xform_fx.hlsl_include" },
	{ 4, "fxaa_hlsl.hlsl_include" },
	{ 4, "_2_8_0_0.render_method_template" },
	{ 4, "olifaunt.collision_model" },
	{ 4, "specular_mask.hlsl_include" },
	{ 4, "_0_0_0_0_0_2_0_1_0_0.vertex_shader" },
	{ 4, "sailpanel.physics_model" },
	{ 4, "plasma_wire_lg.bitmap" },
	{ 4, "rf_fender_snow.render_model" },
	{ 4, "mc_car_civilian_a_illum.bitmap" },
	{ 4, "_3_3_0_0_0_0_0_1_0_1.render_method_template" },
	{ 4, "_2_10_1_1_1_3.render_method_template" },
	{ 4, "_0_1_0_0_0_0_1_0_1_0.render_method_template" },
	{ 4, "_0_1_0_1_1_2_0_3_0_0.render_method_template" },
	{ 4, "_0_3_1_0.render_method_template" },
	{ 4, "_3_8_0_0_1_0_1_0_0_0.pixel_shader" },
	{ 4, "entry_pod_inserter.render_model" },
	{ 4, "barrel_garbage.render_model" },
	{ 4, "material_models_fx.hlsl_include" },
	{ 4, "firing.effect" },
	{ 4, "rocket.render_model" },
	{ 4, "plasma_rifle_bolt.projectile" },
	{ 4, "flap.model" },
	{ 4, "screenshot_memexport.vertex_shader" },
	{ 4, "_0_1_0_0_2_0_5_0_0_0.render_method_template" },
	{ 4, "anti_infantry.weapon" },
	{ 4, "sign_horiz_scenery.scenery" },
	{ 4, "firing.light" },
	{ 4, "impact_liquid.effect" },
	{ 4, "alpha_white.bitmap" },
	{ 4, "_0_1_0_0_7_0_0_0_0_0.vertex_shader" },
};

s_parent_entry children[] =
{
	{ 1, "skid_r_snow.render_model" },
	{ 1, "_2_3_0_1_0_0.render_method_template" },
	{ 1, "particle_update.pixel_shader" },
	{ 1, "_0_0_1_0_2_2_0_0_0_0.vertex_shader" },
	{ 1, "_5_8_0_0_0_1_0_0_0_0.vertex_shader" },
	{ 1, "flood_meteor_diffuse.bitmap" },
	{ 1, "firing.light" },
	{ 1, "sword_clash.area_screen_effect" },
	{ 1, "cubemap_phi_blur_hlsl.hlsl_include" },
	{ 1, "plasma_rifle_red.projectile" },
	{ 1, "downsample_registers_fx.hlsl_include" },
	{ 1, "survival_door_plaza.collision_model" },
	{ 2, "turret.collision_model" },
	{ 2, "wraith_blown_open_height.bitmap" },
	{ 2, "l_wing_shell.model" },
	{ 2, "projectile.effect" },
	{ 2, "wall_sign_2x1_huge_left.model" },
	{ 2, "simple.vertex_shader" },
	{ 2, "trash_bag_d.collision_model" },
	{ 2, "rf_fender.render_model" },
	{ 2, "horizontal_gaussian_blur.hlsl_include" },
	{ 2, "mortar_destroyed.scenery" },
	{ 2, "_0_0_0_1_1_2_0_0_0_0.render_method_template" },
	{ 2, "hornet.vehicle" },
	{ 2, "warehouse_wire_spool_diffuse.bitmap" },
	{ 2, "_1_10_0_0_0_1_0_1_0_1.render_method_template" },
	{ 2, "wheel_peg_destroyed.crate" },
	{ 2, "perm_hull_major.effect" },
	{ 2, "turret_gauss_standalone_damaged.scenery" },
	{ 2, "_0_0_0_0_1_2_0_3_0_0.vertex_shader" },
	{ 2, "platform.collision_model" },
	{ 2, "insertion_pod_dif.bitmap" },
	{ 2, "rf_tread_snow.crate" },
	{ 2, "cart_tire_garbage.crate" },
	{ 2, "final_composite_zoom.pixel_shader" },
	{ 2, "_2_8_0_0_0_1_0_0_0_0.pixel_shader" },
	{ 2, "single_lobe_phong.hlsl_include" },
	{ 2, "_0_1_0_1_2_2_5_0_0_0.pixel_shader" },
	{ 2, "wall_tv_screen_right.device_machine" },
	{ 3, "_0_1_0_2_7_0_0_3_0_0.pixel_shader" },
	{ 3, "bullet.projectile" },
	{ 3, "trash_bag_e.scenery" },
	{ 3, "_1_10_0_0_1_0_1_0_0_0.render_method_template" },
	{ 3, "_8_10_0_1_0_0.pixel_shader" },
	{ 3, "cinematic_gravlift_up.lens_flare" },
	{ 3, "cov_cruiser.render_model" },
	{ 3, "_0_8_1_0_1_2_0.pixel_shader" },
	{ 3, "chud_cortana_screen_final.hlsl_include" },
	{ 3, "beam_rifle.collision_model" },
	{ 3, "_1_10_0_1_1_1_1_1_1_0.pixel_shader" },
	{ 3, "water_tessellation_fx.hlsl_include" },
	{ 3, "insertion_pod_detail_bump.bitmap" },
	{ 3, "global_particle_options.render_method_option" },
	{ 3, "headlights_bright.lens_flare" },
	{ 3, "_0_0_0_0_1_2_0_0_0_0.render_method_template" },
	{ 3, "brute_shot.physics_model" },
	{ 3, "_2_5_1_0_1_2_1.vertex_shader" },
	{ 3, "brute_shot.weapon" },
	{ 3, "_4_3_0_2_1_1_1_0_0_0.vertex_shader" },
	{ 3, "spacecamp_door_large.model_animation_graph" },
	{ 3, "automag_bullet.projectile" },
	{ 3, "flash_large.particle" },
	{ 3, "interior.shader" },
	{ 3, "trans_rf_fender_major.effect" },
	{ 3, "light_green.bitmap" },
	{ 3, "_5_3_0_0_1_1_1_1_0_1.pixel_shader" },
	{ 3, "tether_version_destroyed_plaza_convoy.render_model" },
	{ 3, "chud_meter_chapter.hlsl_include" },
	{ 3, "garbage_rudder.crate" },
	{ 3, "illum_3_channel.render_method_option" },
	{ 3, "_5_3_0_0_0_0_1_1_0_1.vertex_shader" },
	{ 3, "sc130_out_hb_alt.model_animation_graph" },
	{ 3, "ar.bitmap" },
	{ 3, "tread_side_panel.physics_model" },
	{ 3, "hdr_retrieve_hlsl.hlsl_include" },
	{ 3, "_0_2_0_1_0_0.pixel_shader" },
	{ 3, "cowl_left.collision_model" },
	{ 4, "chud_cortana_screen_hlsl.hlsl_include" },
	{ 4, "antigrav.effect" },
	{ 4, "panel_truck_destroyed.shader" },
	{ 4, "sc130_in_sc.model_animation_graph" },
	{ 4, "frag_grenade.projectile" },
	{ 4, "anti_grav.physics_model" },
	{ 4, "landing_gear.crate" },
	{ 4, "assault_bomb.collision_model" },
	{ 4, "_3_8_0_0_0_1_0_0_0_0.pixel_shader" },
	{ 4, "airborne_detonation.effect" },
	{ 4, "debug.vertex_shader" },
	{ 4, "warthog_disabled.crate" },
	{ 4, "screenshot_display.pixel_shader" },
	{ 4, "wave_new_slope_water.bitmap" },
	{ 4, "mortar_destroyed.model" },
	{ 4, "_1_3_0_1_1_1_1_1_1_0.pixel_shader" },
	{ 4, "_0_0_0_0_7_0_5_0_0_0.pixel_shader" },
	{ 4, "cov_light.lens_flare" },
	{ 4, "banshee.render_model" },
	{ 4, "_0_2_0_1_0_0.vertex_shader" },
	{ 4, "organism_material_fx.hlsl_include" },
	{ 4, "insertion_pod_door_upper.crate" },
	{ 4, "_0_0_0_0_2_2_0_0_0_0.render_method_template" },
	{ 4, "shotgun_shiny.shader" },
	{ 4, "ramp.render_model" },
	{ 4, "anti_infantry.vehicle" },
	{ 4, "security_camera_destroyed.bitmap" },
	{ 4, "_0_0_0_0_0_0_1_0_0_1.render_method_template" },
	{ 4, "tether_strand_c100.scenery" },
	{ 4, "projectile.contrail_system" },
	{ 4, "alpha_black.bitmap" },
	{ 4, "firebomb_grenade_bump.bitmap" },
	{ 5, "flag_beta_bump.bitmap" },
	{ 5, "particle_spawn_registers.hlsl_include" },
	{ 5, "voi_switch.render_model" },
	{ 5, "cargo_truck_damaged.model" },
	{ 5, "trans_hull_destroyed.light" },
	{ 5, "l_wing_shell.render_model" },
	{ 5, "excavator_bump.bitmap" },
	{ 5, "_0_0_1_0_0_0_5_0_0_0.vertex_shader" },
	{ 5, "floodlight.collision_model" },
	{ 5, "_0_1_0_1_1_0_0_0_0_0.pixel_shader" },
	{ 5, "assault_rifle.render_model" },
	{ 5, "tread_right_snow.shader" },
	{ 5, "_2_9_1_0_0_2_0.vertex_shader" },
	{ 5, "_4_3_0_2_1_1_1_0_0_0.pixel_shader" },
	{ 5, "_0_1_0_1_2_2_0_0_0_0.vertex_shader" },
	{ 5, "lb_tread_snow.render_model" },
	{ 5, "_5_10_0_0_0_1_1_1_0_0.render_method_template" },
	{ 5, "smg.weapon" },
	{ 5, "_0_1_0_2_2_2_0_0_0_0.pixel_shader" },
	{ 5, "bump_detail.render_method_option" },
	{ 5, "muzzle_flash_round.particle" },
	{ 5, "_3_8_0_0_0_0_1_0_1_0.pixel_shader" },
	{ 5, "sky_dome_simple.hlsl_include" },
	{ 5, "_0_3_0_2_0_0_0_1_0_1.render_method_template" },
	{ 5, "sc130_buildings_torn_up.bitmap" },
	{ 5, "mirror_destroyed.collision_model" },
	{ 5, "trans_hull_major.effect" },
	{ 5, "spike_rifle.weapon" },
	{ 5, "skid_r.collision_model" },
	{ 5, "beam_update.hlsl_include" },
	{ 5, "detonation.effect" },
	{ 5, "overheated.effect" },
	{ 5, "fp_flag.render_model" },
	{ 5, "police_lights_back.render_model" },
	{ 5, "_1_2_1_0_0_0.render_method_template" },
	{ 5, "hornet_snow.bitmap" },
	{ 5, "_2_3_0_1_1_0.render_method_template" },
};

void draw_explorer()
{
	static ImGuiTableFlags flags =
		ImGuiTableFlags_NoBordersInBodyUntilResize;

	if (ImGui::BeginTable("table1", 3, flags))
	{
		ImGui::TableSetupColumn("Parents");
		ImGui::TableSetupColumn("Self");
		ImGui::TableSetupColumn("Children");
		ImGui::TableHeadersRow();

		ImGui::TableNextRow();
		{
			ImGui::TableSetColumnIndex(0);
			{
				ImGui::PushID("Parents");
				draw_parents(parents, parents + _countof(parents));
				ImGui::PopID();
			}
			ImGui::TableSetColumnIndex(1);
			{
				ImGui::PushID("Self");
				draw_self();
				ImGui::PopID();
			}
			ImGui::TableSetColumnIndex(2);
			{
				ImGui::PushID("Children");
				draw_parents(children, children + _countof(children));
				ImGui::PopID();
			}
		}

		ImGui::EndTable();
	}
}








int mandrill_theme_color_count;
int mandrill_theme_var_count;
void mandrill_theme_push()
{
#define push_color4_float(color, r, g, b, a) mandrill_theme_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) mandrill_theme_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) mandrill_theme_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

	mandrill_theme_color_count = 0;
	mandrill_theme_var_count = 0;

	push_color(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, MANDRILL_THEME_TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, MANDRILL_THEME_BG(0.15f));
	push_color(ImGuiCol_PopupBg, MANDRILL_THEME_BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TitleBg, MANDRILL_THEME_LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, MANDRILL_THEME_HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, MANDRILL_THEME_BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_Header, MANDRILL_THEME_MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_HeaderActive, MANDRILL_THEME_HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MANDRILL_THEME_MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotLines, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MANDRILL_THEME_MED(0.43f));
	//push_color(ImGuiCol_ModalWindowDarkening, MANDRILL_THEME_BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_TabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, MANDRILL_THEME_LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_MENU(1.0f));

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

void mandrill_theme_pop()
{
	ImGui::PopStyleColor(mandrill_theme_color_count);
	ImGui::PopStyleVar(mandrill_theme_var_count);
}

static t_callback_handle imgui_memory_test_wip_callback_handle;
static bool g_window_open = true;
static void __cdecl imgui_memory_test_wip()
{
	mandrill_theme_push();
	//return;
	ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Always);
	ImGui::SetNextWindowSize({ window->width_float, window->height_float }, ImGuiCond_Always);

	ImGuiWindowFlags imgui_window_flags = 0;
	//imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	//imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	//imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
	imgui_window_flags |= ImGuiWindowFlags_NoMove;
	imgui_window_flags |= ImGuiWindowFlags_NoResize;
	imgui_window_flags |= ImGuiWindowFlags_NoScrollbar;
	imgui_window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
	if (ImGui::Begin("##mandrill", &g_window_open, imgui_window_flags))
	{
		draw_explorer();

		//ImGui::Columns(3, nullptr, false);
		//{
		//	ImGui::TextUnformatted("Column A");
		//}
		//ImGui::NextColumn();
		//{
		//	ImGui::TextUnformatted("Column B");
		//}
		//ImGui::NextColumn();
		//{
		//	ImGui::TextUnformatted("Column C");
		//}
		//ImGui::NextColumn();
		//ImGui::Columns(1, nullptr, false);
	}
	ImGui::End();

	ImGui::ShowDemoWindow();
	mandrill_theme_pop();
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	BCS_FAIL_RETURN(register_process_module_by_pointer(wWinMain));
	BCS_RESULT rs0 = init_command_line(lpCmdLine);
	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? init_console() : BCS_S_OK;
	BCS_RESULT rs2 = window_create(window_title, "mandrill", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, true, false, window);
	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	ASSERT(BCS_SUCCEEDED(window_render_context->on_render_foreground.add_callback(imgui_memory_test_wip, imgui_memory_test_wip_callback_handle)));
	window_render_context->render();
	ASSERT(BCS_SUCCEEDED(window_render_context->on_render_foreground.remove_callback(imgui_memory_test_wip_callback_handle)));

	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);
	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
