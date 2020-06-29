#pragma once

namespace blofeld
{
	constexpr unsigned long CHUD_WIDGET_ANIMATION_DATA_TAG = 'wadt';
	constexpr unsigned long CHUD_WIDGET_PLACEMENT_DATA_TAG = 'wpdt';
	constexpr unsigned long CHUD_WIDGET_RENDER_DATA_TAG = 'wrdt';
	constexpr unsigned long CHUD_WIDGET_STATE_DATA_TAG = 'wsdt';

	extern s_tag_group chud_widget_animation_data_group;
	extern s_tag_group chud_widget_placement_data_group;
	extern s_tag_group chud_widget_render_data_group;
	extern s_tag_group chud_widget_state_data_group;

	extern s_tag_reference_definition chud_widget_animation_data_reference;
	extern s_tag_reference_definition chud_widget_placement_data_reference;
	extern s_tag_reference_definition chud_widget_render_data_reference;
	extern s_tag_reference_definition chud_widget_state_data_reference;

}

