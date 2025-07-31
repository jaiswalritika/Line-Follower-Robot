/* --- Generated the 20/3/2025 at 1:17 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 16:17:35 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_Stop")==0)) {
    return Line_follower__St_Stop;
  };
  if ((strcmp(s, "St_Right")==0)) {
    return Line_follower__St_Right;
  };
  if ((strcmp(s, "St_Left")==0)) {
    return Line_follower__St_Left;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Line_follower__St_Forward;
  };
  if ((strcmp(s, "St_DriftRight")==0)) {
    return Line_follower__St_DriftRight;
  };
  if ((strcmp(s, "St_DriftLeft")==0)) {
    return Line_follower__St_DriftLeft;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_Stop:
      strcpy(buf, "St_Stop");
      break;
    case Line_follower__St_Right:
      strcpy(buf, "St_Right");
      break;
    case Line_follower__St_Left:
      strcpy(buf, "St_Left");
      break;
    case Line_follower__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    case Line_follower__St_DriftRight:
      strcpy(buf, "St_DriftRight");
      break;
    case Line_follower__St_DriftLeft:
      strcpy(buf, "St_DriftLeft");
      break;
    default:
      break;
  };
  return buf;
}

