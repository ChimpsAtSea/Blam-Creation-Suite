#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(camera, 1)
{
	FIELD( _field_tag_reference, "default unit camera track" ),
	FIELD( _field_explanation, "SANDBOX" ),
	FIELD( _field_struct, "pitch to vertical offset" ),
	FIELD( _field_explanation, "CAMERA UNIVERSALS" ),
	FIELD( _field_real, "field of view:degrees" ),
	FIELD( _field_real, "yaw scale" ),
	FIELD( _field_real, "pitch scale" ),
	FIELD( _field_real, "forward scale" ),
	FIELD( _field_real, "side scale" ),
	FIELD( _field_real, "up scale" ),
	FIELD( _field_explanation, "DEAD CAMERA" ),
	FIELD( _field_real, "transition time:seconds#time it takes for the camera to move from the initial distance to the final distance" ),
	FIELD( _field_real, "falling death transition time:seconds#time it takes for the camera to move to its final position during a falling death" ),
	FIELD( _field_real, "initial distance:wu#on the first frame after death, this is how far out of the body the camera will be" ),
	FIELD( _field_real, "final distance:wu#how far from the body the camera will settle" ),
	FIELD( _field_real, "dead cam z offset:wu#how far above the body the camera focuses on" ),
	FIELD( _field_real, "dead cam maximum elevation:radians#the highest angle the camera can raise to (prevents it from flipping over the vertical axis)" ),
	FIELD( _field_real, "dead cam movement delay:seconds#delay in tracking the killer" ),
	FIELD( _field_real, "time_to_auto_switch_to_orbiting:seconds#how long the death camera lasts before auto-switching to orbiting camera" ),
	FIELD( _field_real, "ignore_stick_time:seconds#how long the death camera ignores stick inputs and keeps turning towards the killer (should be non-zero because user could have died while running or looking around)" ),
	FIELD( _field_real, "ignore_button_time:seconds#how long the death camera ignores shoulder button inputs and keeps turning towards the killer" ),
	FIELD( _field_real, "dead camera minimum falling velocity#minimum velocity to switch to fell to death behavior (when biped is not actually falling to death)" ),
	FIELD( _field_explanation, "FLYING CAMERA" ),
	FIELD( _field_real, "maximum boost speed#the scaling factor for the left stick when the left trigger is fully depressed" ),
	FIELD( _field_real, "time to maximum_boost#seconds. while pegging boost, time to reach maximum speed" ),
	FIELD( _field_enum, "boost function" ),
	FIELD( _field_pad, "hoist", 2 ),
	FIELD( _field_real, "zoomed field of view:degrees#field of view when zoomed" ),
	FIELD( _field_real, "zoomed look speed#scaling factor for look speed when zoomed" ),
	FIELD( _field_real, "bounding sphere radius:wu#radius of sphere for collision" ),
	FIELD( _field_real, "flying cam movement delay:seconds#how quickly the camera responds to the user\'s input" ),
	FIELD( _field_real, "zoom transition time:seconds#how long it takes to zoom in or out" ),
	FIELD( _field_real, "vertical movement time to max speed" ),
	FIELD( _field_enum, "vertical movement function" ),
	FIELD( _field_pad, "moist", 2 ),
	FIELD( _field_real, "survival switch time:seconds#how long it takes in survival mode before switching to flying camera" ),
	FIELD( _field_explanation, "ORBITING CAMERA" ),
	FIELD( _field_real, "minimum distance:wu" ),
	FIELD( _field_real, "maximum distance:wu" ),
	FIELD( _field_real, "orbit cam movement delay:seconds#how quickly the camera responds to the user\'s input" ),
	FIELD( _field_real, "orbit cam z offset:wu#how far above the object\'s root node to position the camera\'s focus point" ),
	FIELD( _field_real, "orbit cam minimum elevation:radians#lowest angle the camera can be moved to" ),
	FIELD( _field_real, "orbit cam maximum elevation:radians#highest angle the camera can be moved to" ),
	FIELD( _field_explanation, "SAVED FILMS" ),
	FIELD( _field_real, "max playback speed#how fast the film plays when the trigger is fully depressed" ),
	FIELD( _field_real, "fade out time:seconds#how long it takes for the screen to fade out when rewinding" ),
	FIELD( _field_real, "fade in time:seconds#see above" ),
	FIELD( _field_explanation, "IN GAME" ),
	FIELD( _field_real, "enter vehicle transition time:seconds#how long it takes the camera to move from first to third person when entering a vehicle" ),
	FIELD( _field_real, "exit vehicle transition time:seconds#see above" ),
	FIELD( _field_explanation, "CAMERA OBSTRUCTION" ),
	FIELD( _field_struct, "obstruction" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

