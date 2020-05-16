#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT_FROM_BLOCK(device_control, DEVICE_CONTROL_TAG, device, DEVICE_TAG, device_control_block_block );

TAG_GROUP_INHERIT_FROM_BLOCK(device, DEVICE_TAG, object, OBJECT_TAG, device_block_block );

TAG_GROUP_INHERIT_FROM_BLOCK(device_dispenser, DEVICE_DISPENSER_TAG, device, DEVICE_TAG, device_dispenser_block_block );

TAG_GROUP_INHERIT_FROM_BLOCK(device_machine, DEVICE_MACHINE_TAG, device, DEVICE_TAG, device_machine_block_block );

TAG_GROUP_INHERIT_FROM_BLOCK(device_terminal, DEVICE_TERMINAL_TAG, device, DEVICE_TAG, device_terminal_block_block );

TAG_BLOCK_FROM_STRUCT(device_control_block, 1, device_control_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(device_block, 1, device_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(device_dispenser_block, 1, device_dispenser_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(device_machine_block, 1, device_machine_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(device_terminal_block, 1, device_terminal_struct_definition_struct_definition );

TAG_BLOCK(terminal_page_block_definition, _terminal_definition::k_max_page_count)
{
	FIELD( _field_short_integer, "bitmap sequence index" ),
	FIELD( _field_short_integer, "bitmap sprite index" ),
	FIELD( _field_string_id, "text" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(device_control_struct_definition)
{
	FIELD( _field_struct, "device", &device_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ CONTROL $$$" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_enum, "triggers when" ),
	FIELD( _field_real, "call value:[0,1]" ),
	FIELD( _field_string_id, "action string" ),
	FIELD( _field_string_id, "secondary action string" ),
	FIELD( _field_string_id, "action denied string#A string to display when someone else is already using \"interaction held\"-type controls" ),
	FIELD( _field_string_id, "action denied secondary string#A string displayed when someone else is using \"interaction held\"-type controls and it\'s in secondary mode" ),
	FIELD( _field_string_id, "MP team use denied string#A string to display if the reason for denial is because of the MP team use restriction" ),
	FIELD( _field_string_id, "MP team use denied secondary string#A string displayed if denied because of MP team use restriction and in secondary mode" ),
	FIELD( _field_string_id, "action and MP team use denied string#Displayed when someone else already using \"interaction held\"-type controls and that player\'s team also triggers the mp use restriction" ),
	FIELD( _field_string_id, "action and MP team use denied secondary string#Displayed when \"interaction held\"-type controls in use, the MP use restriction applies, and in secondary mode" ),
	FIELD( _field_real, "interaction hold time#How many seconds the user must hold the interaction button before the control triggers:seconds" ),
	FIELD( _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type controls" ),
	FIELD( _field_tag_reference, "hold start#An effect to play when a user starts holding the interaction button on this control" ),
	FIELD( _field_tag_reference, "action denied sound#A sound to play when someone attempts to use this control while it is in use" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_enum, "MP team use restriction" ),
	FIELD( _field_pad, "turd", 2 ),
	FIELD( _field_tag_reference, "on" ),
	FIELD( _field_tag_reference, "off" ),
	FIELD( _field_tag_reference, "deny" ),
	FIELD( _field_string_id, "script name" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(device_struct_definition)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ DEVICE $$$" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "power transition time:seconds" ),
	FIELD( _field_real, "power acceleration time:seconds" ),
	FIELD( _field_real, "position transition time:seconds" ),
	FIELD( _field_real, "position acceleration time:seconds" ),
	FIELD( _field_real, "depowered position transition time:seconds" ),
	FIELD( _field_real, "depowered position acceleration time:seconds" ),
	FIELD( _field_word_flags, "lightmap flags" ),
	FIELD( _field_pad, "ZHBMT", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_tag_reference, "open (up)" ),
	FIELD( _field_tag_reference, "close (down)" ),
	FIELD( _field_tag_reference, "opened" ),
	FIELD( _field_tag_reference, "closed" ),
	FIELD( _field_tag_reference, "depowered" ),
	FIELD( _field_tag_reference, "repowered" ),
	FIELD( _field_real, "delay time:seconds" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_tag_reference, "delay effect" ),
	FIELD( _field_real, "automatic activation radius:world units" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name" ),
	FIELD( _field_real, "marker radius#max distance between the unit and the marker" ),
	FIELD( _field_angle, "marker cone angle#angle from marker forward the unit must be" ),
	FIELD( _field_angle, "marker facing angle#angle from unit facing the marker must be" ),
	FIELD( _field_real, "min targetable position threshold#above this value and below the max, object becomes targetable" ),
	FIELD( _field_real, "max targetable position threshold#below this value and above the min, object becomes targetable" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(device_dispenser_struct_definition)
{
	FIELD( _field_struct, "device", &device_struct_definition_struct_definition ),
	FIELD( _field_custom, "DISPENSER" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "triggers when" ),
	FIELD( _field_byte_integer, "use cooldown:seconds#The number of seconds that must elapse before this dispenser is usable" ),
	FIELD( _field_byte_integer, "abandonment time:seconds#When abandoned for this many seconds the object will be deleted" ),
	FIELD( _field_byte_integer, "max quota:(between 0 and 8)#The maximum number of objects that can come from this dispenser" ),
	FIELD( _field_pad, "unrealized potential", 3 ),
	FIELD( _field_real, "interaction hold time:seconds#How many seconds the user must hold the interaction button before the dispenser triggers" ),
	FIELD( _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type dispensers" ),
	FIELD( _field_tag_reference, "dispensed object#This object will be spawned by the dispenser" ),
	FIELD( _field_string_id, "desired variant name#The model variant to use of the dispensed object" ),
	FIELD( _field_string_id, "action string#This interaction text will display when usable" ),
	FIELD( _field_string_id, "same team denial string#Displayed when a player is in range but not on the right team" ),
	FIELD( _field_string_id, "disabled denial string#Displayed when the dispenser is disabled" ),
	FIELD( _field_string_id, "use cooldown denial string#Displayed when the use cooldown time hasn\'t elapsed yet" ),
	FIELD( _field_string_id, "max quota denial string#Displayed when this dispenser is out of charges" ),
	FIELD( _field_string_id, "interaction in progress denial string#Displayed when someone is already interacting with this device" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "spawn marker name#The dispensed object will appear with this marker\'s position and orientation" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "effect marker name#Creates the dispense effect at this marker name" ),
	FIELD( _field_tag_reference, "dispense effect#An effect created when the the dispenser dispenses something" ),
	FIELD( _field_string_id, "dispenser attach marker#The marker on the dispenser to use for attachment if we attach our dispensed object, origin if undefined" ),
	FIELD( _field_string_id, "dispensed object attach marker#The marker on the dispensed object to use for attachment if we attach our dispensed object, origin if undefined" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(device_machine_struct_definition)
{
	FIELD( _field_struct, "device", &device_struct_definition_struct_definition ),
	FIELD( _field_explanation, "$$$ MACHINE $$$" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_real, "door open time:seconds" ),
	FIELD( _field_real_fraction_bounds, "door occlusion bounds#maps position [0,1] to occlusion" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_enum, "collision response" ),
	FIELD( _field_short_integer, "elevator node" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_enum, "pathfinding policy" ),
	FIELD( _field_pad, "R", 2 ),
	FIELD( _field_string_id, "shield name#shield (or any damage section) to control" ),
	FIELD( _field_string_id, "shield function#shield is on when this function is greater then 0.5f, off otherwise." ),
	FIELD( _field_terminator )
};

TAG_STRUCT(device_terminal_struct_definition)
{
	FIELD( _field_struct, "device", &device_struct_definition_struct_definition ),
	FIELD( _field_explanation, "$$$ TERMINAL $$$" ),
	FIELD( _field_long_integer, "bah bah" ),
	FIELD( _field_string_id, "action string" ),
	FIELD( _field_string_id, "name#text pulled from strings tag above" ),
	FIELD( _field_tag_reference, "activation sound" ),
	FIELD( _field_tag_reference, "bitmap" ),
	FIELD( _field_tag_reference, "strings" ),
	FIELD( _field_block, "pages", &terminal_page_block_definition_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

