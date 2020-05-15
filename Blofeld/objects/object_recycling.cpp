#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(garbage_collection, 1)
{
	FIELD( _field_explanation, "Garbage Times" ),
	FIELD( _field_real, "Dropped item:seconds" ),
	FIELD( _field_real, "Dropped item by player:seconds" ),
	FIELD( _field_real, "Dropped item in multiplayer:seconds" ),
	FIELD( _field_real, "Broken constraints:seconds" ),
	FIELD( _field_real, "Dead unit:seconds" ),
	FIELD( _field_real, "Dead player:seconds" ),
	FIELD( _field_real, "Dead MP Player:seconds" ),
	FIELD( _field_real, "Dead MP Player overloaded: seconds" ),
	FIELD( _field_long_integer, "Max dead body count #above this number, overloaded mp time is used to garbage collect dead bodies" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

