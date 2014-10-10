/*
 * settings_synthia_test.h
 * This file is part of the TinyG project
 *
 * Copyright (c) 2010 - 2014 Alden S. Hart, Jr.
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/* Note: The values in this file are the default settings that are loaded
 * 		 into a virgin EEPROM, and can be changed using the config commands.
 *		 After initial load the EEPROM values (or changed values) are used.
 *
 *		 System and hardware settings that you shouldn't need to change
 *		 are in system.h  Application settings that also shouldn't need
 *		 to be changed are in tinyg.h
 */

/***********************************************************************/
/***********************************************************************/

// ***> NOTE: The init message must be a single line with no CRs or LFs
#define INIT_MESSAGE "Initializing configs to Synthia Test profile"

#define JUNCTION_DEVIATION		0.010						// default value, in mm - larger is faster
#define JUNCTION_ACCELERATION	2000000						// centripetal acceleration around corners

// *** settings.h overrides ***

#undef MOTOR_IDLE_TIMEOUT
#define MOTOR_IDLE_TIMEOUT		1.00						// seconds to maintain motor at full power before idling

#undef SOFT_LIMIT_ENABLE
#define SOFT_LIMIT_ENABLE		1							// 0 = off, 1 = on

#undef SWITCH_TYPE
#define SWITCH_TYPE 			SW_TYPE_NORMALLY_CLOSED		// one of: SW_TYPE_NORMALLY_OPEN, SW_TYPE_NORMALLY_CLOSED

#undef COMM_MODE
#define COMM_MODE				TEXT_MODE

#undef TEXT_VERBOSITY
#define TEXT_VERBOSITY			TV_SILENT					// one of: TV_SILENT, TV_VERBOSE

#undef QUEUE_REPORT_VERBOSITY
#define QUEUE_REPORT_VERBOSITY	QR_TRIPLE					// one of: QR_OFF, QR_SINGLE, QR_TRIPLE

#undef STATUS_REPORT_VERBOSITY
#define STATUS_REPORT_VERBOSITY		SR_FILTERED				// one of: SR_OFF, SR_FILTERED, SR_VERBOSE=

#undef STATUS_REPORT_INTERVAL_MS
#define STATUS_REPORT_INTERVAL_MS	100						// milliseconds - set $SV=0 to disable

#undef COM_ENABLE_FLOW_CONTROL
#define COM_ENABLE_FLOW_CONTROL		FLOW_CONTROL_RTS		// FLOW_CONTROL_OFF, FLOW_CONTROL_XON, FLOW_CONTROL_RTS


// *** motor settings ***

#define M1_MOTOR_MAP 			AXIS_X				// 1ma
#define M1_STEP_ANGLE			1.8					// 1sa
#define M1_TRAVEL_PER_REV		40.00				// 1tr
#define M1_MICROSTEPS			8					// 1mi		1,2,4,8
#define M1_POLARITY				0					// 1po		0=normal, 1=reversed
#define M1_POWER_MODE			MOTOR_POWERED_IN_CYCLE	// 1pm		TRUE=low power idle enabled
#define M1_POWER_LEVEL			MOTOR_POWER_LEVEL

#define M2_MOTOR_MAP			AXIS_Y
#define M2_STEP_ANGLE			1.8
#define M2_TRAVEL_PER_REV		40.00
#define M2_MICROSTEPS			8
#define M2_POLARITY				0
#define M2_POWER_MODE			MOTOR_POWERED_IN_CYCLE
#define M2_POWER_LEVEL			MOTOR_POWER_LEVEL

#define M3_MOTOR_MAP			AXIS_Y
#define M3_STEP_ANGLE			1.8
#define M3_TRAVEL_PER_REV		40.00
#define M3_MICROSTEPS			8
#define M3_POLARITY				1
#define M3_POWER_MODE			MOTOR_POWERED_IN_CYCLE
#define M3_POWER_LEVEL			MOTOR_POWER_LEVEL

#define M4_MOTOR_MAP			AXIS_Z
#define M4_STEP_ANGLE			1.8
#define M4_TRAVEL_PER_REV		1.25
#define M4_MICROSTEPS			4
#define M4_POLARITY				0
#define M4_POWER_MODE			MOTOR_POWERED_IN_CYCLE
#define M4_POWER_LEVEL			MOTOR_POWER_LEVEL

#if (MOTORS >= 5)
#define M5_MOTOR_MAP			AXIS_B
#define M5_STEP_ANGLE			1.8
#define M5_TRAVEL_PER_REV		360
#define M5_MICROSTEPS			8
#define M5_POLARITY				0
#define M5_POWER_MODE			MOTOR_POWERED_IN_CYCLE
#define M5_POWER_LEVEL			MOTOR_POWER_LEVEL

#define M6_MOTOR_MAP			AXIS_C
#define M6_STEP_ANGLE			1.8
#define M6_TRAVEL_PER_REV		360
#define M6_MICROSTEPS			8
#define M6_POLARITY				0
#define M6_POWER_MODE			MOTOR_POWERED_IN_CYCLE
#define M6_POWER_LEVEL			MOTOR_POWER_LEVEL
#endif

// *** axis settings ***

#define X_AXIS_MODE				AXIS_STANDARD		// xam		see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX			16000 				// xvm		G0 max velocity in mm/min
#define X_FEEDRATE_MAX			X_VELOCITY_MAX		// xfr 		G1 max feed rate in mm/min
#define X_TRAVEL_MIN			0					// xtn		minimum travel for soft limits
#define X_TRAVEL_MAX			280					// xtm		travel between switches or crashes
#define X_JERK_MAX				5000				// xjm		yes, that's "5 billion" mm/(min^3)
#define X_JERK_HOMING			10000				// xjh
#define X_JUNCTION_DEVIATION	JUNCTION_DEVIATION	// xjd
#define X_SWITCH_MODE_MIN		SW_MODE_HOMING_LIMIT// xsn		SW_MODE_DISABLED, SW_MODE_HOMING, SW_MODE_LIMIT, SW_MODE_HOMING_LIMIT
#define X_SWITCH_MODE_MAX 		SW_MODE_LIMIT		// xsx		SW_MODE_DISABLED, SW_MODE_HOMING, SW_MODE_LIMIT, SW_MODE_HOMING_LIMIT
#define X_SEARCH_VELOCITY		3000				// xsv		minus means move to minimum switch
#define X_LATCH_VELOCITY		100					// xlv		mm/min
#define X_LATCH_BACKOFF			50					// xlb		mm
#define X_ZERO_BACKOFF			30					// xzb		mm

#define Y_AXIS_MODE				AXIS_STANDARD
#define Y_VELOCITY_MAX			16000
#define Y_FEEDRATE_MAX			Y_VELOCITY_MAX
#define Y_TRAVEL_MIN			0
#define Y_TRAVEL_MAX			280
#define Y_JERK_MAX				5000
#define Y_JERK_HOMING			10000
#define Y_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define Y_SWITCH_MODE_MIN		SW_MODE_HOMING_LIMIT
#define Y_SWITCH_MODE_MAX		SW_MODE_LIMIT
#define Y_SEARCH_VELOCITY		3000
#define Y_LATCH_VELOCITY		100
#define Y_LATCH_BACKOFF			50
#define Y_ZERO_BACKOFF			30

#define Z_AXIS_MODE				AXIS_STANDARD
#define Z_VELOCITY_MAX			900
#define Z_FEEDRATE_MAX			Z_VELOCITY_MAX
#define Z_TRAVEL_MAX			0
#define Z_TRAVEL_MIN			-95
#define Z_JERK_MAX				500
#define Z_JERK_HOMING			1000
#define Z_JUNCTION_DEVIATION	0.05
#define Z_SWITCH_MODE_MIN		SW_MODE_DISABLED
#define Z_SWITCH_MODE_MAX		SW_MODE_HOMING_LIMIT
#define Z_SEARCH_VELOCITY		Z_VELOCITY_MAX
#define Z_LATCH_VELOCITY		300
#define Z_LATCH_BACKOFF			20
#define Z_ZERO_BACKOFF			5

#define A_AXIS_MODE				AXIS_STANDARD
#define A_VELOCITY_MAX			10000
#define A_FEEDRATE_MAX			10000
#define A_TRAVEL_MIN			-1					// degrees
#define A_TRAVEL_MAX 			-1					// same value means infinite, no limit
#define A_JERK_MAX				500000
#define A_JERK_HOMING			1000
#define A_JUNCTION_DEVIATION	0.1
#define A_RADIUS				0.1989
#define A_SWITCH_MODE_MIN		0
#define A_SWITCH_MODE_MAX		0
#define A_SEARCH_VELOCITY		300
#define A_LATCH_VELOCITY		300
#define A_LATCH_BACKOFF			10
#define A_ZERO_BACKOFF			5

#define B_AXIS_MODE				AXIS_DISABLED
#define B_VELOCITY_MAX			3600
#define B_FEEDRATE_MAX			B_VELOCITY_MAX
#define B_TRAVEL_MAX			-1
#define B_TRAVEL_MIN			-1
#define B_JERK_MAX				20
#define B_JERK_HOMING			B_JERK_MAX
#define B_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define B_RADIUS				1
#define B_SWITCH_MODE_MIN		SW_MODE_HOMING
#define B_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define B_SEARCH_VELOCITY		6000
#define B_LATCH_VELOCITY		1000
#define B_LATCH_BACKOFF			5
#define B_ZERO_BACKOFF			2

#define C_AXIS_MODE				AXIS_DISABLED
#define C_VELOCITY_MAX			3600
#define C_FEEDRATE_MAX			C_VELOCITY_MAX
#define C_TRAVEL_MAX			-1
#define C_TRAVEL_MIN			-1
#define C_JERK_MAX				20
#define C_JERK_HOMING			C_JERK_MAX
#define C_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define C_RADIUS				1
#define C_SWITCH_MODE_MIN		SW_MODE_HOMING
#define C_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define C_SEARCH_VELOCITY		6000
#define C_LATCH_VELOCITY		1000
#define C_LATCH_BACKOFF			5
#define C_ZERO_BACKOFF			2

// *** DEFAULT COORDINATE SYSTEM OFFSETS ***
// Our convention is:
//	- leave G54 in machine coordinates to act as a persistent absolute coordinate system
//	- set G55 to be a zero in the middle of the table
//	- no action for the others

#define G54_X_OFFSET 0			// G54 is traditionally set to all zeros
#define G54_Y_OFFSET 0
#define G54_Z_OFFSET 0
#define G54_A_OFFSET 0
#define G54_B_OFFSET 0
#define G54_C_OFFSET 0

#define G55_X_OFFSET (X_TRAVEL_MAX/2)	// set g55 to middle of table
#define G55_Y_OFFSET (Y_TRAVEL_MAX/2)
#define G55_Z_OFFSET 0
#define G55_A_OFFSET 0
#define G55_B_OFFSET 0
#define G55_C_OFFSET 0

#define G56_X_OFFSET 0
#define G56_Y_OFFSET 0
#define G56_Z_OFFSET 0
#define G56_A_OFFSET 0
#define G56_B_OFFSET 0
#define G56_C_OFFSET 0

#define G57_X_OFFSET 0
#define G57_Y_OFFSET 0
#define G57_Z_OFFSET 0
#define G57_A_OFFSET 0
#define G57_B_OFFSET 0
#define G57_C_OFFSET 0

#define G58_X_OFFSET 0
#define G58_Y_OFFSET 0
#define G58_Z_OFFSET 0
#define G58_A_OFFSET 0
#define G58_B_OFFSET 0
#define G58_C_OFFSET 0

#define G59_X_OFFSET 0
#define G59_Y_OFFSET 0
#define G59_Z_OFFSET 0
#define G59_A_OFFSET 0
#define G59_B_OFFSET 0
#define G59_C_OFFSET 0

