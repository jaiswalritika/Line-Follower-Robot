/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_1_Stop,
  Line_follower__St_1_RightTurn_Park,
  Line_follower__St_1_RightTurn3,
  Line_follower__St_1_RightTurn1,
  Line_follower__St_1_Right,
  Line_follower__St_1_PreParkingDriftRight,
  Line_follower__St_1_PreParkingDriftLeft,
  Line_follower__St_1_ParkrightBackward,
  Line_follower__St_1_ParkleftBackward,
  Line_follower__St_1_ParkingStartTS,
  Line_follower__St_1_ParkingStartSS,
  Line_follower__St_1_ParkingStartFS,
  Line_follower__St_1_ParkingDriftRightTS,
  Line_follower__St_1_ParkingDriftRightSS,
  Line_follower__St_1_ParkingDriftRight,
  Line_follower__St_1_ParkingDriftLeftTS,
  Line_follower__St_1_ParkingDriftLeftSS,
  Line_follower__St_1_ParkingDriftLeft,
  Line_follower__St_1_ParkingDelay,
  Line_follower__St_1_Parking,
  Line_follower__St_1_ObstacleAvoidance,
  Line_follower__St_1_Move5,
  Line_follower__St_1_Move3,
  Line_follower__St_1_Move1,
  Line_follower__St_1_LeftTurn_Park,
  Line_follower__St_1_LeftTurn2,
  Line_follower__St_1_LeftTurn1,
  Line_follower__St_1_Left,
  Line_follower__St_1_Forwardoneparking,
  Line_follower__St_1_Forward_1,
  Line_follower__St_1_Forward2,
  Line_follower__St_1_Forward1,
  Line_follower__St_1_Forward,
  Line_follower__St_1_FirstleftParking,
  Line_follower__St_1_ExitState,
  Line_follower__St_1_DriftRight,
  Line_follower__St_1_DriftLeft,
  Line_follower__St_1_DelayP2,
  Line_follower__St_1_DelayP1,
  Line_follower__St_1_BlackRight,
  Line_follower__St_1_BlackLeft,
  Line_follower__St_1_BlackForward,
  Line_follower__St_1_BlackDriftRight,
  Line_follower__St_1_BlackDriftLeft
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_WaitForNextIncrement,
  Line_follower__St_Initial,
  Line_follower__St_CountIncrement
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const int Line_follower__kp = 3;

static const int Line_follower__kd = 1;

#endif // LINE_FOLLOWER_TYPES_H
