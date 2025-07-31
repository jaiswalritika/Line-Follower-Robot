/* --- Generated the 30/3/2025 at 16:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Stop")==0)) {
    return Line_follower__St_1_Stop;
  };
  if ((strcmp(s, "St_1_RightTurn3")==0)) {
    return Line_follower__St_1_RightTurn3;
  };
  if ((strcmp(s, "St_1_RightTurn1")==0)) {
    return Line_follower__St_1_RightTurn1;
  };
  if ((strcmp(s, "St_1_Right")==0)) {
    return Line_follower__St_1_Right;
  };
  if ((strcmp(s, "St_1_ObstacleAvoidance")==0)) {
    return Line_follower__St_1_ObstacleAvoidance;
  };
  if ((strcmp(s, "St_1_Move5")==0)) {
    return Line_follower__St_1_Move5;
  };
  if ((strcmp(s, "St_1_Move4")==0)) {
    return Line_follower__St_1_Move4;
  };
  if ((strcmp(s, "St_1_Move3")==0)) {
    return Line_follower__St_1_Move3;
  };
  if ((strcmp(s, "St_1_Move2")==0)) {
    return Line_follower__St_1_Move2;
  };
  if ((strcmp(s, "St_1_Move1")==0)) {
    return Line_follower__St_1_Move1;
  };
  if ((strcmp(s, "St_1_LeftTurn2")==0)) {
    return Line_follower__St_1_LeftTurn2;
  };
  if ((strcmp(s, "St_1_LeftTurn1")==0)) {
    return Line_follower__St_1_LeftTurn1;
  };
  if ((strcmp(s, "St_1_Left")==0)) {
    return Line_follower__St_1_Left;
  };
  if ((strcmp(s, "St_1_Forward2")==0)) {
    return Line_follower__St_1_Forward2;
  };
  if ((strcmp(s, "St_1_Forward1")==0)) {
    return Line_follower__St_1_Forward1;
  };
  if ((strcmp(s, "St_1_Forward")==0)) {
    return Line_follower__St_1_Forward;
  };
  if ((strcmp(s, "St_1_DriftRight")==0)) {
    return Line_follower__St_1_DriftRight;
  };
  if ((strcmp(s, "St_1_DriftLeft")==0)) {
    return Line_follower__St_1_DriftLeft;
  };
  if ((strcmp(s, "St_1_BlackStop")==0)) {
    return Line_follower__St_1_BlackStop;
  };
  if ((strcmp(s, "St_1_BlackRight")==0)) {
    return Line_follower__St_1_BlackRight;
  };
  if ((strcmp(s, "St_1_BlackLeft")==0)) {
    return Line_follower__St_1_BlackLeft;
  };
  if ((strcmp(s, "St_1_BlackForward")==0)) {
    return Line_follower__St_1_BlackForward;
  };
  if ((strcmp(s, "St_1_BlackDriftRight")==0)) {
    return Line_follower__St_1_BlackDriftRight;
  };
  if ((strcmp(s, "St_1_BlackDriftLeft")==0)) {
    return Line_follower__St_1_BlackDriftLeft;
  };
}

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf) {
  switch (x) {
    case Line_follower__St_1_Stop:
      strcpy(buf, "St_1_Stop");
      break;
    case Line_follower__St_1_RightTurn3:
      strcpy(buf, "St_1_RightTurn3");
      break;
    case Line_follower__St_1_RightTurn1:
      strcpy(buf, "St_1_RightTurn1");
      break;
    case Line_follower__St_1_Right:
      strcpy(buf, "St_1_Right");
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      strcpy(buf, "St_1_ObstacleAvoidance");
      break;
    case Line_follower__St_1_Move5:
      strcpy(buf, "St_1_Move5");
      break;
    case Line_follower__St_1_Move4:
      strcpy(buf, "St_1_Move4");
      break;
    case Line_follower__St_1_Move3:
      strcpy(buf, "St_1_Move3");
      break;
    case Line_follower__St_1_Move2:
      strcpy(buf, "St_1_Move2");
      break;
    case Line_follower__St_1_Move1:
      strcpy(buf, "St_1_Move1");
      break;
    case Line_follower__St_1_LeftTurn2:
      strcpy(buf, "St_1_LeftTurn2");
      break;
    case Line_follower__St_1_LeftTurn1:
      strcpy(buf, "St_1_LeftTurn1");
      break;
    case Line_follower__St_1_Left:
      strcpy(buf, "St_1_Left");
      break;
    case Line_follower__St_1_Forward2:
      strcpy(buf, "St_1_Forward2");
      break;
    case Line_follower__St_1_Forward1:
      strcpy(buf, "St_1_Forward1");
      break;
    case Line_follower__St_1_Forward:
      strcpy(buf, "St_1_Forward");
      break;
    case Line_follower__St_1_DriftRight:
      strcpy(buf, "St_1_DriftRight");
      break;
    case Line_follower__St_1_DriftLeft:
      strcpy(buf, "St_1_DriftLeft");
      break;
    case Line_follower__St_1_BlackStop:
      strcpy(buf, "St_1_BlackStop");
      break;
    case Line_follower__St_1_BlackRight:
      strcpy(buf, "St_1_BlackRight");
      break;
    case Line_follower__St_1_BlackLeft:
      strcpy(buf, "St_1_BlackLeft");
      break;
    case Line_follower__St_1_BlackForward:
      strcpy(buf, "St_1_BlackForward");
      break;
    case Line_follower__St_1_BlackDriftRight:
      strcpy(buf, "St_1_BlackDriftRight");
      break;
    case Line_follower__St_1_BlackDriftLeft:
      strcpy(buf, "St_1_BlackDriftLeft");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_Wait")==0)) {
    return Line_follower__St_Wait;
  };
  if ((strcmp(s, "St_Ready")==0)) {
    return Line_follower__St_Ready;
  };
  if ((strcmp(s, "St_Increment")==0)) {
    return Line_follower__St_Increment;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_Wait:
      strcpy(buf, "St_Wait");
      break;
    case Line_follower__St_Ready:
      strcpy(buf, "St_Ready");
      break;
    case Line_follower__St_Increment:
      strcpy(buf, "St_Increment");
      break;
    default:
      break;
  };
  return buf;
}

