#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT_FROM_BLOCK(vehicle, VEHICLE_TAG, unit, UNIT_TAG, vehicle_block_block );

TAG_BLOCK_FROM_STRUCT(vehicle_block, 1, vehicle_group_struct_definition );

TAG_BLOCK_FROM_STRUCT(human_tank_block, 1, human_tank_struct_struct_definition );

TAG_BLOCK(human_jeep_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_struct, "engine", &global_vehicle_engine_struct_struct_definition ),
	FIELD( _field_block, "boat engine", &boat_engine_definition_block_block ),
	FIELD( _field_explanation, "wheel circumferance" ),
	FIELD( _field_real, "wheel circumferance" ),
	FIELD( _field_real, "gravity adjust#0-1 fraction by which we scale gravity that is not along the ground plane" ),
	FIELD( _field_real, "antiroll torque factor#how much torque should be applied to prevent a vehicle from rolling. Default should be 0.0, 1.0 is a good value for making it hard to roll." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(human_plane_block, 1)
{
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "speed accel against direction#acceleration when trying to throttle against current speed direction" ),
	FIELD( _field_real, "maximum forward speed during boost" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "slide accel against direction#acceleration when trying to throttle against current slide direction" ),
	FIELD( _field_real, "maximum slide speed during boost" ),
	FIELD( _field_real, "maximum up rise" ),
	FIELD( _field_real, "maximum down rise" ),
	FIELD( _field_real, "rise acceleration" ),
	FIELD( _field_real, "rise deceleration" ),
	FIELD( _field_real, "rise accel against direction#acceleration when trying to throttle against current rise direction" ),
	FIELD( _field_real, "maximum rise speed during boost" ),
	FIELD( _field_explanation, "human plane tuning variables" ),
	FIELD( _field_real, "flying torque scale#big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." ),
	FIELD( _field_real, "air friction deceleration#human plane physics only. 0 is nothing.  1 is like thowing the engine to full reverse" ),
	FIELD( _field_real, "thrust scale#human plane physics only. 0 is default (1)" ),
	FIELD( _field_real, "turn rate scale when boosting#this was originally added for the sentinel enforce, but I could see other uses. 0 defaults to 1" ),
	FIELD( _field_real, "maximum roll#0 defaults to 90 degrees" ),
	FIELD( _field_struct, "steering animation", &steering_animation_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(wolverine_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_struct, "engine", &global_vehicle_engine_struct_struct_definition ),
	FIELD( _field_explanation, "wheel circumferance" ),
	FIELD( _field_real, "wheel circumferance" ),
	FIELD( _field_real, "gravity adjust#0-1 fraction by which we scale gravity that is not along the ground plane" ),
	FIELD( _field_explanation, "deployed mode" ),
	FIELD( _field_real, "turret deployment time:seconds#time it takes for turret and support legs to deploy" ),
	FIELD( _field_real, "turret holster time:seconds#time it takes for turret and support legs to pack up" ),
	FIELD( _field_real, "runtime inverse turret deployment time!*" ),
	FIELD( _field_real, "runtime inverse turret holster time!*" ),
	FIELD( _field_real, "deployed camera yaw scale." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(alien_scout_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "slide accel against direction#acceleration when trying to throttle against current slide direction" ),
	FIELD( _field_real, "slide speed at top speed:wu/s#the slide speeds are interpolated down to this value, reaching it when the vehicle is moving at its top speed" ),
	FIELD( _field_explanation, "specific types" ),
	FIELD( _field_char_enum, "specific type" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "NPBE", 2 ),
	FIELD( _field_real, "drag coeficient" ),
	FIELD( _field_real, "constant deceleration" ),
	FIELD( _field_real, "torque scale#0 defaults to 1" ),
	FIELD( _field_explanation, "engine object function" ),
	FIELD( _field_struct, "engine gravity function", &engine_function_struct_struct_definition ),
	FIELD( _field_explanation, "contrail object function" ),
	FIELD( _field_struct, "contrail gravity function", &engine_function_struct_struct_definition ),
	FIELD( _field_explanation, "engine rotation function" ),
	FIELD( _field_real_bounds, "gear rotation speed#cycles per second idle to full throttle" ),
	FIELD( _field_struct, "steering animation", &steering_animation_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(alien_fighter_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "slide accel against direction#acceleration when trying to throttle against current slide direction" ),
	FIELD( _field_explanation, "torque scale" ),
	FIELD( _field_real, "flying torque scale#big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." ),
	FIELD( _field_explanation, "fixed gun offset" ),
	FIELD( _field_angle, "fixed gun yaw" ),
	FIELD( _field_angle, "fixed gun pitch" ),
	FIELD( _field_explanation, "alien fighter trick variables" ),
	FIELD( _field_real, "maximum trick frequency" ),
	FIELD( _field_real, "loop trick duration" ),
	FIELD( _field_real, "roll trick duration" ),
	FIELD( _field_explanation, "alien fighter fake flight control" ),
	FIELD( _field_real, "zero gravity speed" ),
	FIELD( _field_real, "full gravity speed" ),
	FIELD( _field_real, "strafe boost scale" ),
	FIELD( _field_real, "off stick deceleration scale" ),
	FIELD( _field_real, "cruising throttle" ),
	FIELD( _field_real, "dive speed scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(turret_block, 1)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_string_id, "physical yaw node" ),
	FIELD( _field_string_id, "physical pitch node" ),
	FIELD( _field_string_id, "physical elevate node#this is specificly for the wolverine which has a turret which pops up when you use it." ),
	FIELD( _field_angle, "operating elevation angle#angle which elevate node is set to in order to operate" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(mantis_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_struct, "walker physics", &walker_physics_struct_struct_definition ),
	FIELD( _field_real, "walk cycle pause#fraction of walkcycle at end for pause" ),
	FIELD( _field_short_integer, "stable planted legs#number of legs mantis needs planted to be considered stable." ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_real, "time without plant buffer#seconds" ),
	FIELD( _field_real, "not along up gravity scale#0-1" ),
	FIELD( _field_real, "speed acceleration limit" ),
	FIELD( _field_real, "speed acceleration match scale" ),
	FIELD( _field_real, "slide acceleration limit" ),
	FIELD( _field_real, "slide acceleration match scale" ),
	FIELD( _field_real, "turn acceleration limit" ),
	FIELD( _field_real, "turn acceleration match scale" ),
	FIELD( _field_explanation, "jumping" ),
	FIELD( _field_real, "jump set time#seconds" ),
	FIELD( _field_real, "jump set interpolation fraction#0-1, portion of set time spent interpolating into neutral stance" ),
	FIELD( _field_real, "jump leap time#seconds" ),
	FIELD( _field_real, "jump recovery time#seconds" ),
	FIELD( _field_real, "jump recovery fraction#0-1, portion of recovery time spent interpolating into neutral stance" ),
	FIELD( _field_real, "jump leg set distance#WU, amount foot moves up to get ready to jump" ),
	FIELD( _field_real, "jump leg distance#WU, amount foot moves down when jumping" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vtol_block, 1)
{
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "left lift marker" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "right lift marker" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "thrust marker" ),
	FIELD( _field_struct, "trigger to throttle", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_struct, "descent to boost", &vtol_descent_function_struct_struct_definition ),
	FIELD( _field_explanation, "minimum and maximum up acceleration" ),
	FIELD( _field_real, "maximum up acceleration" ),
	FIELD( _field_real, "maximum down acceleration" ),
	FIELD( _field_real, "vertical deceleration time:seconds#after accelerating vertically, take this long to bleed off the throttle" ),
	FIELD( _field_explanation, "lift arm pivot" ),
	FIELD( _field_real, "lift arm pivot length" ),
	FIELD( _field_explanation, "turn, left and forward accelerations" ),
	FIELD( _field_real, "maximum turn acceleration" ),
	FIELD( _field_real, "turn acceleration gain" ),
	FIELD( _field_explanation, "interpolation parameters" ),
	FIELD( _field_real, "interpolation speed domain" ),
	FIELD( _field_explanation, "funciton explanation" ),
	FIELD( _field_struct, "SPEED_TROTTLE_CEILING()", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_struct, "INTERPOLATION_ACC()", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_struct, "A_B_INTERPOLATION() interpolation mapping", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_block, "speed interpolated parameters", &vtol_speed_interpolated_block_block ),
	FIELD( _field_angle, "lift angles acc#how fast can the engine animations accelerate their turn in degress/SQR(sec)" ),
	FIELD( _field_angle, "render lift angles acc#how fast can the engine animations accelerate their turn in degress/SQR(sec)" ),
	FIELD( _field_real, "alt. lock offset coefficient#scalar for altitude lock based on distance to target - higher numbers reach the target more quickly but may cause bounciness" ),
	FIELD( _field_real, "alt. lock velocity coefficient#scalar for altitude lock based on velocity.  Acts like friction, trying to remove vertical velocity from the system" ),
	FIELD( _field_explanation, "prop rotation" ),
	FIELD( _field_real_bounds, "prop rotation speed#cycles per second idle to full throttle" ),
	FIELD( _field_explanation, "landing" ),
	FIELD( _field_real, "landing time:s#how long we must maintain the landing state in order to land" ),
	FIELD( _field_real, "takeoff time:s#how long it takes to leave the landed state" ),
	FIELD( _field_real, "landing linear velocity:wu/s#must be under this linear velocity to enter/maintain landing state" ),
	FIELD( _field_real, "landing angular velocity:rad/s#must be under this angular velocity to enter/maintain landing state" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vtol_speed_interpolated_block, 2)
{
	FIELD( _field_real, "rotor damping#maxes out around 30" ),
	FIELD( _field_real, "maximum left acceleration" ),
	FIELD( _field_real, "maximum forward acceleration" ),
	FIELD( _field_real, "drag coeficient" ),
	FIELD( _field_real, "constant deceleration" ),
	FIELD( _field_real, "magic angular acc exp#magic force that torques vehicle back towards up" ),
	FIELD( _field_real, "magic angular acc scale#magic force that torques vehicle back towards up" ),
	FIELD( _field_real, "magic angular acc k#magic force that torques vehicle back towards up" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(chopper_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_struct, "engine", &global_vehicle_engine_struct_struct_definition ),
	FIELD( _field_explanation, "wheel circumferance" ),
	FIELD( _field_real, "wheel circumferance" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "rotation marker" ),
	FIELD( _field_real, "magic turning scale#scale up the magic force" ),
	FIELD( _field_real, "magic turning acc#(degrees/pow(sec,2))rate at which the turning tries to accelerate" ),
	FIELD( _field_real, "magic turning max vel.#(degrees/sec)rate at which vehicl tries to turn" ),
	FIELD( _field_real, "magic turning exponent#turn_acc=delta^exp" ),
	FIELD( _field_real, "bank to slide ratio#(WU/sec)the slide velocity at which we achieve full bank" ),
	FIELD( _field_real, "bank slide exponent" ),
	FIELD( _field_real, "bank to turn ratio#(WU/sec)the slide velocity at which we achieve full bank" ),
	FIELD( _field_real, "bank turn exponent" ),
	FIELD( _field_real, "bank fraction#fraction of possible tire drop when we bank. 0 is full bank 1 is no bank." ),
	FIELD( _field_real, "bank rate#bank fraction velocity. (0-1 fraction / sec)" ),
	FIELD( _field_real, "wheel accel#acceleration of the wheel towards the engine speed" ),
	FIELD( _field_real, "gyroscopic damping#0==none, 30==damn near full damping" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(guardian_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "torque scale#0 defaults to 1" ),
	FIELD( _field_real, "anti-gravity force z-offset" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(jackal_glider_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "torque scale#0 defaults to 1" ),
	FIELD( _field_explanation, "engine object function" ),
	FIELD( _field_struct, "engine object function", &engine_function_struct_struct_definition ),
	FIELD( _field_explanation, "contrail object function" ),
	FIELD( _field_struct, "contrail object function", &engine_function_struct_struct_definition ),
	FIELD( _field_struct, "steering animation", &steering_animation_struct_struct_definition ),
	FIELD( _field_real, "flying velocity threshold" ),
	FIELD( _field_angle, "flying look threshold#degrees" ),
	FIELD( _field_real, "flying hover threshold" ),
	FIELD( _field_real, "grounded hover threshold" ),
	FIELD( _field_real, "landing grounded time" ),
	FIELD( _field_angle, "ground turn radius#degrees" ),
	FIELD( _field_real, "ground acceleration#wu/sec" ),
	FIELD( _field_explanation, "wing lift" ),
	FIELD( _field_real, "wing lift q" ),
	FIELD( _field_real, "wing lift k" ),
	FIELD( _field_real, "wing lift function ceiling" ),
	FIELD( _field_real, "aileron to angular acceleartion scale" ),
	FIELD( _field_angle, "aileron yaw tilt angle" ),
	FIELD( _field_explanation, "wing" ),
	FIELD( _field_struct, "wing surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "ailerons" ),
	FIELD( _field_struct, "aileron surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "elevator" ),
	FIELD( _field_struct, "elevator surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "tail" ),
	FIELD( _field_struct, "tail surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "rudder" ),
	FIELD( _field_struct, "rudder surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "taxi" ),
	FIELD( _field_struct, "taxi surface", &flight_surface_struct_struct_definition ),
	FIELD( _field_explanation, "ground drag" ),
	FIELD( _field_struct, "ground drag struct", &jackal_glider_drag_struct_struct_definition ),
	FIELD( _field_explanation, "air drag" ),
	FIELD( _field_struct, "air drag struct", &jackal_glider_drag_struct_struct_definition ),
	FIELD( _field_explanation, "takeoff drag" ),
	FIELD( _field_struct, "takeoff drag struct", &jackal_glider_drag_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(boat_block, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "blah", 3 ),
	FIELD( _field_angle, "tank control forward arc:degrees#only used when \'use tank controls\' is checked above" ),
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_real, "gravity scale#0 means 0.  How hard is it to type 1\?" ),
	FIELD( _field_struct, "engine", &global_vehicle_engine_struct_struct_definition ),
	FIELD( _field_block, "boat engine", &boat_engine_definition_block_block ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "hull marker name#the name of the hull surface used to spew effects along the hull of the vehicle." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(space_fighter_block, 1)
{
	FIELD( _field_struct, "steering control", &vehicle_steering_control_struct_struct_definition ),
	FIELD( _field_struct, "turning control", &vehicle_turning_control_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "full throttle speed:wu/s#maximum speed when throttle = 1.0" ),
	FIELD( _field_real, "neutral throttle speed:wu/s#speed when throttle = 0.0" ),
	FIELD( _field_real, "reverse throttle speed:wu/s#speed when throttle = -1.0" ),
	FIELD( _field_real, "speed acceleration:wu/s/s" ),
	FIELD( _field_real, "speed deceleration:wu/s/s" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_real, "slide accel against direction#acceleration when trying to throttle against current slide direction" ),
	FIELD( _field_explanation, "torque scale" ),
	FIELD( _field_real, "flying torque scale#big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." ),
	FIELD( _field_explanation, "fixed gun offset" ),
	FIELD( _field_angle, "fixed gun yaw" ),
	FIELD( _field_angle, "fixed gun pitch" ),
	FIELD( _field_explanation, "alien fighter trick variables" ),
	FIELD( _field_real, "maximum trick frequency" ),
	FIELD( _field_real, "loop trick duration" ),
	FIELD( _field_real, "roll trick duration" ),
	FIELD( _field_explanation, "alien fighter fake flight control" ),
	FIELD( _field_real, "strafe boost scale" ),
	FIELD( _field_real, "off stick deceleration scale" ),
	FIELD( _field_real, "dive speed scale" ),
	FIELD( _field_angle, "roll max velocity:deg/sec#max angular velocity for user-input roll" ),
	FIELD( _field_angle, "roll acceleration:deg/sec/sec#acceleration for user-input roll" ),
	FIELD( _field_angle, "roll deceleration:deg/sec/sec#deceleration for user-input roll (when the user releases the stick)" ),
	FIELD( _field_real_fraction, "roll smoothing fraction#if non-zero, when the desired velocity change is less than this fraction of the acceleration, starts interpolating the maximum acceleration towards zero.\nYou can think of this as a time in seconds where if the velocity would reach its target in this amount of time or less, it will start taking longer." ),
	FIELD( _field_explanation, "autolevel" ),
	FIELD( _field_real, "autolevel time:s#how long you must not rotate (roll, pitch, yaw) before autoleveling kicks in" ),
	FIELD( _field_angle, "autolevel pitch cutoff:degrees#if the ship is pitched outside of this range, autoleveling will not happen.  The effect is also scaled as the pitch approaches this angle" ),
	FIELD( _field_angle, "autolevel max velocity:degrees/sec#maximum angular velocity for autoleveling" ),
	FIELD( _field_angle, "autolevel max acceleration:deg/sec/sec#maximum acceleration for autoleveling" ),
	FIELD( _field_angle, "autolevel max user ang. vel.:deg/sec#autolevel can continue to happen if the user is desiring an angular velocity lower than this" ),
	FIELD( _field_real, "autolevel spring k#controls relationship between displacement and acceleration - higher values mean faster acceleration when the desired position is far from current position" ),
	FIELD( _field_real, "autolevel spring c#controls relationship between velocity and friction - higher values will slow the system down, lower values may let the system oscillate" ),
	FIELD( _field_explanation, "cosmetic roll" ),
	FIELD( _field_real, "cosmetic roll scale#desired roll = delta yaw X scale" ),
	FIELD( _field_angle, "cosmetic roll max bank:degrees#maximum cosmetic roll angle" ),
	FIELD( _field_angle, "cosmetic roll max velocity:deg/sec#maximum angular velocity that cosmetic roll can achieve" ),
	FIELD( _field_angle, "cosmetic roll acceleration:deg/sec/sec#maximum angular acceleration for cosmetic roll" ),
	FIELD( _field_real, "cosmetic roll spring k#controls relationship between displacement and acceleration - higher values mean faster acceleration when the desired position is far from current position" ),
	FIELD( _field_real, "cosmetic roll spring c#controls relationship between velocity and friction - higher values will slow the system down, lower values may let the system oscillate" ),
	FIELD( _field_explanation, "new roll" ),
	FIELD( _field_long_flags, "roll flags" ),
	FIELD( _field_angle, "maximum left stick roll angle" ),
	FIELD( _field_real, "left stick rate smoothing" ),
	FIELD( _field_real, "left stick trend smoothing" ),
	FIELD( _field_angle, "maximum right stick roll angle" ),
	FIELD( _field_real, "right stick rate smoothing" ),
	FIELD( _field_real, "right stick trend smoothing" ),
	FIELD( _field_explanation, "turn deceleration" ),
	FIELD( _field_angle, "turn deceleration threshold:deg/sec#turn deceleration kicks in when turning faster than this" ),
	FIELD( _field_real_fraction, "turn deceleration fraction#when turning at the maximum rate, throttle is limited to this value" ),
	FIELD( _field_explanation, "soft ceiling turn back" ),
	FIELD( _field_long_flags, "turn back flags" ),
	FIELD( _field_real, "turn back latched period" ),
	FIELD( _field_struct, "turn back distance to turn rate", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_explanation, "thrust params" ),
	FIELD( _field_real, "ideal thrust decay" ),
	FIELD( _field_real, "ideal thrust increase" ),
	FIELD( _field_real, "minimum thrust decay" ),
	FIELD( _field_real, "minimum thrust increase" ),
	FIELD( _field_real, "maximum thrust increase" ),
	FIELD( _field_explanation, "dive params" ),
	FIELD( _field_real, "minimum dive angle" ),
	FIELD( _field_real, "maximum dive angle" ),
	FIELD( _field_explanation, "strafe params" ),
	FIELD( _field_real, "strafe boost power" ),
	FIELD( _field_explanation, "wingtip params" ),
	FIELD( _field_real, "wingtip contrail turn" ),
	FIELD( _field_real, "wingtip min turn" ),
	FIELD( _field_explanation, "Safety" ),
	FIELD( _field_real, "dangerous trajectory prediction time:seconds#How much the position is predicted by the velocity to check against potential collisions" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(revenant_block, 1)
{
	FIELD( _field_struct, "tank block", &human_tank_struct_struct_definition ),
	FIELD( _field_explanation, "velocity control variables" ),
	FIELD( _field_real, "maximum forward speed" ),
	FIELD( _field_real, "maximum reverse speed" ),
	FIELD( _field_real, "speed acceleration" ),
	FIELD( _field_real, "speed deceleration" ),
	FIELD( _field_real, "maximum left slide" ),
	FIELD( _field_real, "maximum right slide" ),
	FIELD( _field_real, "slide acceleration" ),
	FIELD( _field_real, "slide deceleration" ),
	FIELD( _field_struct, "steering animation", &steering_animation_struct_struct_definition ),
	FIELD( _field_explanation, "specific types" ),
	FIELD( _field_char_enum, "specific type" ),
	FIELD( _field_real, "drag coeficient" ),
	FIELD( _field_real, "constant deceleration" ),
	FIELD( _field_real, "torque scale#0 defaults to 1" ),
	FIELD( _field_pad, "BLURBY", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SoundRTPCBlock, k_maxSoundRTPCBlocks)
{
	FIELD( _field_long_block_index, "Attachment Index#Sound attachment to affect" ),
	FIELD( _field_string_id, "Function#Function to drive the RTPC" ),
	FIELD( _field_string_id, "RTPC Name#WWise RTPC string name" ),
	FIELD( _field_long_integer, "RTPC name hash value*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SoundSweetenerBlock, k_maxSoundSweetenerBlocks)
{
	FIELD( _field_string_id, "Function#Function to trigger the sweetener" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" ),
	FIELD( _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(physics_transitions_block, k_max_vehicle_physics_transitions)
{
	FIELD( _field_real, "transition velocity:wu/s#speed at which flight model transition occurs" ),
	FIELD( _field_real, "velocity threshold side: 0 or 1#0 if velocity should be smaller than transition value, else 1" ),
	FIELD( _field_real, "transition throttle:-1 to 1#throttle input at which physics model transition occurs" ),
	FIELD( _field_real, "throttle threshold side: 0 or 1#0 if throttle should be smaller than transition value, else 1" ),
	FIELD( _field_char_enum, "transition target vehicle type#upon reaching transition velocity, act like this vehicle type" ),
	FIELD( _field_pad, "pad after transition target vehicle type", 3 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(vehicle_group)
{
	FIELD( _field_struct, "unit", &unit_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ VEHICLE $$$" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "physics type" ),
	FIELD( _field_struct, "physics types", &vehicle_physics_types_struct_struct_definition ),
	FIELD( _field_explanation, "friction and antigravity points" ),
	FIELD( _field_struct, "havok vehicle physics", &havok_vehicle_physics_struct_struct_definition ),
	FIELD( _field_block, "tricks", &unit_trick_definition_block_block ),
	FIELD( _field_char_enum, "player training vehicle type" ),
	FIELD( _field_char_enum, "vehicle size#The size determine what kind of seats in larger vehicles it may occupy (i.e. small or large cargo seats)" ),
	FIELD( _field_char_integer, "complex suspension sample count#How many additional raycasts to perform per side of a tire." ),
	FIELD( _field_pad, "VQWHV", 1 ),
	FIELD( _field_angle, "complex suspension distribution angle:degrees#0-90 degrees of the wedge portion of the wheel to test suspension" ),
	FIELD( _field_real, "complex suspension wheel diameter" ),
	FIELD( _field_real, "complex suspension wheel width" ),
	FIELD( _field_real, "minimum flipping angular velocity" ),
	FIELD( _field_real, "maximum flipping angular velocity" ),
	FIELD( _field_real, "crouch transition time:seconds" ),
	FIELD( _field_real, "HOOJYTSU!" ),
	FIELD( _field_real, "seat enterance acceleration scale#how much do we scale the force the vehicle the applies down on the seat when he enters. 0 == no acceleration" ),
	FIELD( _field_real, "seat exit accelersation scale#how much do we scale the force the vehicle the applies down on the seat when he exits. 0 == no acceleration" ),
	FIELD( _field_real, "blur speed" ),
	FIELD( _field_string_id, "flip message" ),
	FIELD( _field_explanation, "sounds and effects" ),
	FIELD( _field_tag_reference, "Player vehicle sound bank#High quality player sound bank to be prefetched. Can be empty." ),
	FIELD( _field_tag_reference, "suspension sound" ),
	FIELD( _field_real, "fake audio speed - speed increase amount#amount to increase per frame while speeding up(.002 is a good number)" ),
	FIELD( _field_real, "fake audio speed - boost speed increase amount#amount to increase per frame while boosting (.006 is a good number)" ),
	FIELD( _field_real, "fake audio speed - speed decrease amount#amount to decrease per frame while slowing down (.002 is a good number)" ),
	FIELD( _field_real, "fake audio speed - non-boost limit#max value while not boosting (maximum is 1)" ),
	FIELD( _field_real, "fake audio speed - max speed scale#scales speed value. Must be > 0 for this to work (ie for banshee, 5 is good)" ),
	FIELD( _field_block, "Sound RTPCs", &SoundRTPCBlock_block ),
	FIELD( _field_block, "Sound Sweeteners", &SoundSweetenerBlock_block ),
	FIELD( _field_tag_reference, "special effect" ),
	FIELD( _field_tag_reference, "driver boost damage effect or response" ),
	FIELD( _field_tag_reference, "rider boost damage effect or response" ),
	FIELD( _field_string_id, "vehicle name" ),
	FIELD( _field_block, "physics transitions", &physics_transitions_block_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(vehicle_physics_types_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_block, "type-human_tank", &human_tank_block_block ),
	FIELD( _field_block, "type-human_jeep", &human_jeep_block_block ),
	FIELD( _field_block, "type-human_plane", &human_plane_block_block ),
	FIELD( _field_block, "type-wolverine", &wolverine_block_block ),
	FIELD( _field_block, "type-alien_scout", &alien_scout_block_block ),
	FIELD( _field_block, "type-alien_fighter", &alien_fighter_block_block ),
	FIELD( _field_block, "type-turret", &turret_block_block ),
	FIELD( _field_block, "type-mantis", &mantis_block_block ),
	FIELD( _field_block, "type-vtol", &vtol_block_block ),
	FIELD( _field_block, "type-chopper", &chopper_block_block ),
	FIELD( _field_block, "type-guardian", &guardian_block_block ),
	FIELD( _field_block, "type-jackal-glider", &jackal_glider_block_block ),
	FIELD( _field_block, "type-boat", &boat_block_block ),
	FIELD( _field_block, "type-space-fighter", &space_fighter_block_block ),
	FIELD( _field_block, "type-revenant", &revenant_block_block ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(human_tank_struct)
{
	FIELD( _field_angle, "forward arc#outside of this arc the vehicle reverse direciton, around 110 degrees seems to be nice..." ),
	FIELD( _field_angle, "perpendicular forward arc#this is the value of forward arc when turned sideways.  We interpolate from forward arc to this value when camera becomes perpendicular to the vehicle" ),
	FIELD( _field_real, "flip window#seconds" ),
	FIELD( _field_real, "pegged fraction#0-1" ),
	FIELD( _field_real, "forward turn scale#think of this as oversteer" ),
	FIELD( _field_real, "reverse turn scale#think of this as oversteer" ),
	FIELD( _field_explanation, "forward differential" ),
	FIELD( _field_real, "maximum left differential" ),
	FIELD( _field_real, "maximum right differential" ),
	FIELD( _field_real, "differential acceleration" ),
	FIELD( _field_real, "differential deceleration" ),
	FIELD( _field_explanation, "reverse differential" ),
	FIELD( _field_real, "maximum left reverse differential" ),
	FIELD( _field_real, "maximum right reverse differential" ),
	FIELD( _field_real, "differential reverse acceleration" ),
	FIELD( _field_real, "differential reverse deceleration" ),
	FIELD( _field_struct, "engine", &global_vehicle_engine_struct_struct_definition ),
	FIELD( _field_explanation, "wheel circumferance" ),
	FIELD( _field_real, "wheel circumferance" ),
	FIELD( _field_real, "gravity adjust#0-1 fraction by which we scale gravity that is not along the ground plane" ),
	FIELD( _field_explanation, "New Tank Controls" ),
	FIELD( _field_byte_flags, "control flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_real, "at rest forward angle(purple)" ),
	FIELD( _field_real, "at rest reverse angle(violet)" ),
	FIELD( _field_real, "at rest side on reverse angle closest to front(green)#first angle starting arc in which the control will cause the tank to reverse while at rest and facing side on" ),
	FIELD( _field_real, "at rest side on reverse angle furthest from front(blue)#second angle ending arc in which the control will cause the tank to reverse while at rest and facing side on" ),
	FIELD( _field_real, "at rest facing forward reverse angle(yellow)#angle forming arc in which the control will cause the tank to reverse while at rest and facing forward" ),
	FIELD( _field_real, "at rest facing backward reverse angle(pink)##angle forming arc in which the control will cause the tank to reverse while at rest and facing backwards" ),
	FIELD( _field_real, "in motion opposing direction angle#when in motion the angle in which the control must be to start moving in the opposite direction" ),
	FIELD( _field_real, "in motion speed#the speed a tank must reach before we consider it in motion, changing the control mode" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(vehicle_steering_control_struct)
{
	FIELD( _field_explanation, "steering overdampening" ),
	FIELD( _field_real, "overdampen cusp angle:degrees" ),
	FIELD( _field_real, "overdampen exponent" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(vehicle_turning_control_struct)
{
	FIELD( _field_explanation, "turning" ),
	FIELD( _field_real, "maximum left turn" ),
	FIELD( _field_real, "maximum right turn (negative)" ),
	FIELD( _field_real, "turn rate" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(steering_animation_struct)
{
	FIELD( _field_explanation, "steering animation and interpolation\n" ),
	FIELD( _field_real, "interpolation scale#1= heavy interp. of steering animations" ),
	FIELD( _field_angle, "max angle#non-zero= max angle delta per frame" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(engine_function_struct)
{
	FIELD( _field_string_id, "object function damage region#this is the name of the region by which we gauge the overall damage of the vehicle" ),
	FIELD( _field_real, "min anti gravity engine speed#speed at which engine position funciton  moves.  value of 1 means goes from 0-1 in 1 second" ),
	FIELD( _field_real, "max anti gravity engine speed#speed at which engine position funciton  moves.  value of 1 means goes from 0-1 in 1 second" ),
	FIELD( _field_real, "engine speed acceleration#strictly used for object funtion. in 0-1 space" ),
	FIELD( _field_real, "maximum vehicle speed#function is capped by speed of the vehicle. So when we slow down for any reason we see the function go down" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(vtol_descent_function_struct)
{
	FIELD( _field_struct, "descent to boost", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "max downward speed:wu/s" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(flight_surface_struct)
{
	FIELD( _field_char_enum, "offset axis" ),
	FIELD( _field_char_enum, "pivot axis" ),
	FIELD( _field_char_enum, "rotation axis" ),
	FIELD( _field_char_enum, "normal axis" ),
	FIELD( _field_real, "offset distance" ),
	FIELD( _field_real, "pivot distance" ),
	FIELD( _field_explanation, "normal force" ),
	FIELD( _field_real, "q" ),
	FIELD( _field_real, "k" ),
	FIELD( _field_real, "function ceiling" ),
	FIELD( _field_angle, "maximum angle" ),
	FIELD( _field_real, "render debug radius" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(jackal_glider_drag_struct)
{
	FIELD( _field_explanation, "drag" ),
	FIELD( _field_real, "q" ),
	FIELD( _field_real, "k" ),
	FIELD( _field_real, "constant deceleration" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

