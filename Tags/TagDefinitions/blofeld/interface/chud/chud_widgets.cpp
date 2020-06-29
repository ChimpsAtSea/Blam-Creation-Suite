#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	
	TAG_REFERENCE(chud_widget_animation_data_reference, CHUD_WIDGET_ANIMATION_DATA_TAG);
	TAG_REFERENCE(chud_widget_placement_data_reference, CHUD_WIDGET_PLACEMENT_DATA_TAG);
	TAG_REFERENCE(chud_widget_render_data_reference, CHUD_WIDGET_RENDER_DATA_TAG);
	TAG_REFERENCE(chud_widget_state_data_reference, CHUD_WIDGET_STATE_DATA_TAG);

	TAG_GROUP(chud_widget_animation_data, CHUD_WIDGET_ANIMATION_DATA_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud_widget_placement_data, CHUD_WIDGET_PLACEMENT_DATA_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud_widget_render_data, CHUD_WIDGET_RENDER_DATA_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud_widget_state_data, CHUD_WIDGET_STATE_DATA_TAG)
	{
		{ _field_terminator }
	};
}
