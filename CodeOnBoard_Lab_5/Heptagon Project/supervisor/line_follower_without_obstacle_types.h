/* --- Generated the 29/3/2025 at 13:33 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower_without_obstacle.ept --- */

#ifndef LINE_FOLLOWER_WITHOUT_OBSTACLE_TYPES_H
#define LINE_FOLLOWER_WITHOUT_OBSTACLE_TYPES_H

#include "stdbool.h"
#include "assert.h"
// #include "pervasives.h"
typedef enum {
  Line_follower_without_obstacle__St_Stop,
  Line_follower_without_obstacle__St_Right,
  Line_follower_without_obstacle__St_Left,
  Line_follower_without_obstacle__St_Forward,
  Line_follower_without_obstacle__St_DriftRight,
  Line_follower_without_obstacle__St_DriftLeft,
  Line_follower_without_obstacle__St_BlackRight,
  Line_follower_without_obstacle__St_BlackLeft,
  Line_follower_without_obstacle__St_BlackForward,
  Line_follower_without_obstacle__St_BlackDriftRight,
  Line_follower_without_obstacle__St_BlackDriftLeft
} Line_follower_without_obstacle__st;

Line_follower_without_obstacle__st Line_follower_without_obstacle__st_of_string(
char* s);

char* string_of_Line_follower_without_obstacle__st(Line_follower_without_obstacle__st x,
                                                   char* buf);

static const long Line_follower_without_obstacle__kp = 3;

static const long Line_follower_without_obstacle__kd = 1;

#endif // LINE_FOLLOWER_WITHOUT_OBSTACLE_TYPES_H
