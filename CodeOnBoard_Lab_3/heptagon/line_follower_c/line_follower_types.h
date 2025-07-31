/* --- Generated the 20/3/2025 at 1:17 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 16:17:35 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_Stop,
  Line_follower__St_Right,
  Line_follower__St_Left,
  Line_follower__St_Forward,
  Line_follower__St_DriftRight,
  Line_follower__St_DriftLeft
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const int Line_follower__kp = 3;

static const int Line_follower__kd = 1;

static const int Line_follower__ki = 0;

#endif // LINE_FOLLOWER_TYPES_H
