/* --- Generated the 29/3/2025 at 13:33 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower_without_obstacle.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_without_obstacle_types.h"

Line_follower_without_obstacle__st Line_follower_without_obstacle__st_of_string(
  char* s) {
  if ((strcmp(s, "St_Stop")==0)) {
    return Line_follower_without_obstacle__St_Stop;
  };
  if ((strcmp(s, "St_Right")==0)) {
    return Line_follower_without_obstacle__St_Right;
  };
  if ((strcmp(s, "St_Left")==0)) {
    return Line_follower_without_obstacle__St_Left;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Line_follower_without_obstacle__St_Forward;
  };
  if ((strcmp(s, "St_DriftRight")==0)) {
    return Line_follower_without_obstacle__St_DriftRight;
  };
  if ((strcmp(s, "St_DriftLeft")==0)) {
    return Line_follower_without_obstacle__St_DriftLeft;
  };
  if ((strcmp(s, "St_BlackRight")==0)) {
    return Line_follower_without_obstacle__St_BlackRight;
  };
  if ((strcmp(s, "St_BlackLeft")==0)) {
    return Line_follower_without_obstacle__St_BlackLeft;
  };
  if ((strcmp(s, "St_BlackForward")==0)) {
    return Line_follower_without_obstacle__St_BlackForward;
  };
  if ((strcmp(s, "St_BlackDriftRight")==0)) {
    return Line_follower_without_obstacle__St_BlackDriftRight;
  };
  if ((strcmp(s, "St_BlackDriftLeft")==0)) {
    return Line_follower_without_obstacle__St_BlackDriftLeft;
  };
}

char* string_of_Line_follower_without_obstacle__st(Line_follower_without_obstacle__st x,
                                                   char* buf) {
  switch (x) {
    case Line_follower_without_obstacle__St_Stop:
      strcpy(buf, "St_Stop");
      break;
    case Line_follower_without_obstacle__St_Right:
      strcpy(buf, "St_Right");
      break;
    case Line_follower_without_obstacle__St_Left:
      strcpy(buf, "St_Left");
      break;
    case Line_follower_without_obstacle__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    case Line_follower_without_obstacle__St_DriftRight:
      strcpy(buf, "St_DriftRight");
      break;
    case Line_follower_without_obstacle__St_DriftLeft:
      strcpy(buf, "St_DriftLeft");
      break;
    case Line_follower_without_obstacle__St_BlackRight:
      strcpy(buf, "St_BlackRight");
      break;
    case Line_follower_without_obstacle__St_BlackLeft:
      strcpy(buf, "St_BlackLeft");
      break;
    case Line_follower_without_obstacle__St_BlackForward:
      strcpy(buf, "St_BlackForward");
      break;
    case Line_follower_without_obstacle__St_BlackDriftRight:
      strcpy(buf, "St_BlackDriftRight");
      break;
    case Line_follower_without_obstacle__St_BlackDriftLeft:
      strcpy(buf, "St_BlackDriftLeft");
      break;
    default:
      break;
  };
  return buf;
}

