/* --- Generated the 30/3/2025 at 16:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_1_Stop,
  Line_follower__St_1_RightTurn3,
  Line_follower__St_1_RightTurn1,
  Line_follower__St_1_Right,
  Line_follower__St_1_ObstacleAvoidance,
  Line_follower__St_1_Move5,
  Line_follower__St_1_Move4,
  Line_follower__St_1_Move3,
  Line_follower__St_1_Move2,
  Line_follower__St_1_Move1,
  Line_follower__St_1_LeftTurn2,
  Line_follower__St_1_LeftTurn1,
  Line_follower__St_1_Left,
  Line_follower__St_1_Forward2,
  Line_follower__St_1_Forward1,
  Line_follower__St_1_Forward,
  Line_follower__St_1_DriftRight,
  Line_follower__St_1_DriftLeft,
  Line_follower__St_1_BlackStop,
  Line_follower__St_1_BlackRight,
  Line_follower__St_1_BlackLeft,
  Line_follower__St_1_BlackForward,
  Line_follower__St_1_BlackDriftRight,
  Line_follower__St_1_BlackDriftLeft
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_Wait,
  Line_follower__St_Ready,
  Line_follower__St_Increment
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const long Line_follower__kp = 3;

static const long Line_follower__kd = 1;

#endif // LINE_FOLLOWER_TYPES_H
