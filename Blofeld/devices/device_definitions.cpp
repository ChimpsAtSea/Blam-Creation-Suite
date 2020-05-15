#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(terminal_page, _terminal_definition::k_max_page_count)
{
	{ _field_short_integer, "bitmap sequence index" },
	{ _field_short_integer, "bitmap sprite index" },
	{ _field_string_id, "text" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(device_control, DEVICE_CONTROL_TAG, device, DEVICE_TAG)
{
	{ _field_struct, "device" },
	{ _field_custom, "$$$ CONTROL $$$" },
	{ _field_enum, "type" },
	{ _field_enum, "triggers when" },
	{ _field_real, "call value:[0,1]" },
	{ _field_string_id, "action string" },
	{ _field_string_id, "secondary action string" },
	{ _field_string_id, "action denied string#A string to display when someone else is already using \"interaction held\"-type controls" },
	{ _field_string_id, "action denied secondary string#A string displayed when someone else is using \"interaction held\"-type controls and it\'s in secondary mode" },
	{ _field_string_id, "MP team use denied string#A string to display if the reason for denial is because of the MP team use restriction" },
	{ _field_string_id, "MP team use denied secondary string#A string displayed if denied because of MP team use restriction and in secondary mode" },
	{ _field_string_id, "action and MP team use denied string#Displayed when someone else already using \"interaction held\"-type controls and that player\'s team also triggers the mp use restriction" },
	{ _field_string_id, "action and MP team use denied secondary string#Displayed when \"interaction held\"-type controls in use, the MP use restriction applies, and in secondary mode" },
	{ _field_real, "interaction hold time#How many seconds the user must hold the interaction button before the control triggers:seconds" },
	{ _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type controls" },
	{ _field_tag_reference, "hold start#An effect to play when a user starts holding the interaction button on this control" },
	{ _field_tag_reference, "action denied sound#A sound to play when someone attempts to use this control while it is in use" },
	{ _field_useless_pad },
	{ _field_enum, "MP team use restriction" },
	{ _field_pad, "turd", 2 },
	{ _field_tag_reference, "on" },
	{ _field_tag_reference, "off" },
	{ _field_tag_reference, "deny" },
	{ _field_string_id, "script name" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(device, DEVICE_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ DEVICE $$$" },
	{ _field_long_flags, "flags" },
	{ _field_real, "power transition time:seconds" },
	{ _field_real, "power acceleration time:seconds" },
	{ _field_real, "position transition time:seconds" },
	{ _field_real, "position acceleration time:seconds" },
	{ _field_real, "depowered position transition time:seconds" },
	{ _field_real, "depowered position acceleration time:seconds" },
	{ _field_word_flags, "lightmap flags" },
	{ _field_pad, "ZHBMT", 2 },
	{ _field_useless_pad },
	{ _field_tag_reference, "open (up)" },
	{ _field_tag_reference, "close (down)" },
	{ _field_tag_reference, "opened" },
	{ _field_tag_reference, "closed" },
	{ _field_tag_reference, "depowered" },
	{ _field_tag_reference, "repowered" },
	{ _field_real, "delay time:seconds" },
	{ _field_useless_pad },
	{ _field_tag_reference, "delay effect" },
	{ _field_real, "automatic activation radius:world units" },
	{ _field_custom },
	{ _field_string_id, "marker name" },
	{ _field_real, "marker radius#max distance between the unit and the marker" },
	{ _field_angle, "marker cone angle#angle from marker forward the unit must be" },
	{ _field_angle, "marker facing angle#angle from unit facing the marker must be" },
	{ _field_real, "min targetable position threshold#above this value and below the max, object becomes targetable" },
	{ _field_real, "max targetable position threshold#below this value and above the min, object becomes targetable" },
	{ _field_useless_pad },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(device_dispenser, DEVICE_DISPENSER_TAG, device, DEVICE_TAG)
{
	{ _field_struct, "device" },
	{ _field_custom, "DISPENSER" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "triggers when" },
	{ _field_byte_integer, "use cooldown:seconds#The number of seconds that must elapse before this dispenser is usable" },
	{ _field_byte_integer, "abandonment time:seconds#When abandoned for this many seconds the object will be deleted" },
	{ _field_byte_integer, "max quota:(between 0 and 8)#The maximum number of objects that can come from this dispenser" },
	{ _field_pad, "unrealized potential", 3 },
	{ _field_real, "interaction hold time:seconds#How many seconds the user must hold the interaction button before the dispenser triggers" },
	{ _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type dispensers" },
	{ _field_tag_reference, "dispensed object#This object will be spawned by the dispenser" },
	{ _field_string_id, "desired variant name#The model variant to use of the dispensed object" },
	{ _field_string_id, "action string#This interaction text will display when usable" },
	{ _field_string_id, "same team denial string#Displayed when a player is in range but not on the right team" },
	{ _field_string_id, "disabled denial string#Displayed when the dispenser is disabled" },
	{ _field_string_id, "use cooldown denial string#Displayed when the use cooldown time hasn\'t elapsed yet" },
	{ _field_string_id, "max quota denial string#Displayed when this dispenser is out of charges" },
	{ _field_string_id, "interaction in progress denial string#Displayed when someone is already interacting with this device" },
	{ _field_custom },
	{ _field_string_id, "spawn marker name#The dispensed object will appear with this marker\'s position and orientation" },
	{ _field_custom },
	{ _field_string_id, "effect marker name#Creates the dispense effect at this marker name" },
	{ _field_tag_reference, "dispense effect#An effect created when the the dispenser dispenses something" },
	{ _field_string_id, "dispenser attach marker#The marker on the dispenser to use for attachment if we attach our dispensed object, origin if undefined" },
	{ _field_string_id, "dispensed object attach marker#The marker on the dispensed object to use for attachment if we attach our dispensed object, origin if undefined" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(device_machine, DEVICE_MACHINE_TAG, device, DEVICE_TAG)
{
	{ _field_struct, "device" },
	{ _field_explanation, "$$$ MACHINE $$$" },
	{ _field_enum, "type" },
	{ _field_word_flags, "flags" },
	{ _field_real, "door open time:seconds" },
	{ _field_real_fraction_bounds, "door occlusion bounds#maps position [0,1] to occlusion" },
	{ _field_useless_pad },
	{ _field_enum, "collision response" },
	{ _field_short_integer, "elevator node" },
	{ _field_useless_pad },
	{ _field_enum, "pathfinding policy" },
	{ _field_pad, "R", 2 },
	{ _field_string_id, "shield name#shield (or any damage section) to control" },
	{ _field_string_id, "shield function#shield is on when this function is greater then 0.5f, off otherwise." },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(device_terminal, DEVICE_TERMINAL_TAG, device, DEVICE_TAG)
{
	{ _field_struct, "device" },
	{ _field_explanation, "$$$ TERMINAL $$$" },
	{ _field_long_integer, "bah bah" },
	{ _field_string_id, "action string" },
	{ _field_string_id, "name#text pulled from strings tag above" },
	{ _field_tag_reference, "activation sound" },
	{ _field_tag_reference, "bitmap" },
	{ _field_tag_reference, "strings" },
	{ _field_block, "pages", &terminal_page_block },
	{ _field_terminator },
};

} // namespace blofeld

