/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Stop")==0)) {
    return Line_follower__St_1_Stop;
  };
  if ((strcmp(s, "St_1_RightTurn_Park")==0)) {
    return Line_follower__St_1_RightTurn_Park;
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
  if ((strcmp(s, "St_1_PreParkingDriftRight")==0)) {
    return Line_follower__St_1_PreParkingDriftRight;
  };
  if ((strcmp(s, "St_1_PreParkingDriftLeft")==0)) {
    return Line_follower__St_1_PreParkingDriftLeft;
  };
  if ((strcmp(s, "St_1_ParkrightBackward")==0)) {
    return Line_follower__St_1_ParkrightBackward;
  };
  if ((strcmp(s, "St_1_ParkleftBackward")==0)) {
    return Line_follower__St_1_ParkleftBackward;
  };
  if ((strcmp(s, "St_1_ParkingStartTS")==0)) {
    return Line_follower__St_1_ParkingStartTS;
  };
  if ((strcmp(s, "St_1_ParkingStartSS")==0)) {
    return Line_follower__St_1_ParkingStartSS;
  };
  if ((strcmp(s, "St_1_ParkingStartFS")==0)) {
    return Line_follower__St_1_ParkingStartFS;
  };
  if ((strcmp(s, "St_1_ParkingDriftRightTS")==0)) {
    return Line_follower__St_1_ParkingDriftRightTS;
  };
  if ((strcmp(s, "St_1_ParkingDriftRightSS")==0)) {
    return Line_follower__St_1_ParkingDriftRightSS;
  };
  if ((strcmp(s, "St_1_ParkingDriftRight")==0)) {
    return Line_follower__St_1_ParkingDriftRight;
  };
  if ((strcmp(s, "St_1_ParkingDriftLeftTS")==0)) {
    return Line_follower__St_1_ParkingDriftLeftTS;
  };
  if ((strcmp(s, "St_1_ParkingDriftLeftSS")==0)) {
    return Line_follower__St_1_ParkingDriftLeftSS;
  };
  if ((strcmp(s, "St_1_ParkingDriftLeft")==0)) {
    return Line_follower__St_1_ParkingDriftLeft;
  };
  if ((strcmp(s, "St_1_ParkingDelay")==0)) {
    return Line_follower__St_1_ParkingDelay;
  };
  if ((strcmp(s, "St_1_Parking")==0)) {
    return Line_follower__St_1_Parking;
  };
  if ((strcmp(s, "St_1_ObstacleAvoidance")==0)) {
    return Line_follower__St_1_ObstacleAvoidance;
  };
  if ((strcmp(s, "St_1_Move5")==0)) {
    return Line_follower__St_1_Move5;
  };
  if ((strcmp(s, "St_1_Move3")==0)) {
    return Line_follower__St_1_Move3;
  };
  if ((strcmp(s, "St_1_Move1")==0)) {
    return Line_follower__St_1_Move1;
  };
  if ((strcmp(s, "St_1_LeftTurn_Park")==0)) {
    return Line_follower__St_1_LeftTurn_Park;
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
  if ((strcmp(s, "St_1_Forwardoneparking")==0)) {
    return Line_follower__St_1_Forwardoneparking;
  };
  if ((strcmp(s, "St_1_Forward_1")==0)) {
    return Line_follower__St_1_Forward_1;
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
  if ((strcmp(s, "St_1_FirstleftParking")==0)) {
    return Line_follower__St_1_FirstleftParking;
  };
  if ((strcmp(s, "St_1_ExitState")==0)) {
    return Line_follower__St_1_ExitState;
  };
  if ((strcmp(s, "St_1_DriftRight")==0)) {
    return Line_follower__St_1_DriftRight;
  };
  if ((strcmp(s, "St_1_DriftLeft")==0)) {
    return Line_follower__St_1_DriftLeft;
  };
  if ((strcmp(s, "St_1_DelayP2")==0)) {
    return Line_follower__St_1_DelayP2;
  };
  if ((strcmp(s, "St_1_DelayP1")==0)) {
    return Line_follower__St_1_DelayP1;
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
    case Line_follower__St_1_RightTurn_Park:
      strcpy(buf, "St_1_RightTurn_Park");
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
    case Line_follower__St_1_PreParkingDriftRight:
      strcpy(buf, "St_1_PreParkingDriftRight");
      break;
    case Line_follower__St_1_PreParkingDriftLeft:
      strcpy(buf, "St_1_PreParkingDriftLeft");
      break;
    case Line_follower__St_1_ParkrightBackward:
      strcpy(buf, "St_1_ParkrightBackward");
      break;
    case Line_follower__St_1_ParkleftBackward:
      strcpy(buf, "St_1_ParkleftBackward");
      break;
    case Line_follower__St_1_ParkingStartTS:
      strcpy(buf, "St_1_ParkingStartTS");
      break;
    case Line_follower__St_1_ParkingStartSS:
      strcpy(buf, "St_1_ParkingStartSS");
      break;
    case Line_follower__St_1_ParkingStartFS:
      strcpy(buf, "St_1_ParkingStartFS");
      break;
    case Line_follower__St_1_ParkingDriftRightTS:
      strcpy(buf, "St_1_ParkingDriftRightTS");
      break;
    case Line_follower__St_1_ParkingDriftRightSS:
      strcpy(buf, "St_1_ParkingDriftRightSS");
      break;
    case Line_follower__St_1_ParkingDriftRight:
      strcpy(buf, "St_1_ParkingDriftRight");
      break;
    case Line_follower__St_1_ParkingDriftLeftTS:
      strcpy(buf, "St_1_ParkingDriftLeftTS");
      break;
    case Line_follower__St_1_ParkingDriftLeftSS:
      strcpy(buf, "St_1_ParkingDriftLeftSS");
      break;
    case Line_follower__St_1_ParkingDriftLeft:
      strcpy(buf, "St_1_ParkingDriftLeft");
      break;
    case Line_follower__St_1_ParkingDelay:
      strcpy(buf, "St_1_ParkingDelay");
      break;
    case Line_follower__St_1_Parking:
      strcpy(buf, "St_1_Parking");
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      strcpy(buf, "St_1_ObstacleAvoidance");
      break;
    case Line_follower__St_1_Move5:
      strcpy(buf, "St_1_Move5");
      break;
    case Line_follower__St_1_Move3:
      strcpy(buf, "St_1_Move3");
      break;
    case Line_follower__St_1_Move1:
      strcpy(buf, "St_1_Move1");
      break;
    case Line_follower__St_1_LeftTurn_Park:
      strcpy(buf, "St_1_LeftTurn_Park");
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
    case Line_follower__St_1_Forwardoneparking:
      strcpy(buf, "St_1_Forwardoneparking");
      break;
    case Line_follower__St_1_Forward_1:
      strcpy(buf, "St_1_Forward_1");
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
    case Line_follower__St_1_FirstleftParking:
      strcpy(buf, "St_1_FirstleftParking");
      break;
    case Line_follower__St_1_ExitState:
      strcpy(buf, "St_1_ExitState");
      break;
    case Line_follower__St_1_DriftRight:
      strcpy(buf, "St_1_DriftRight");
      break;
    case Line_follower__St_1_DriftLeft:
      strcpy(buf, "St_1_DriftLeft");
      break;
    case Line_follower__St_1_DelayP2:
      strcpy(buf, "St_1_DelayP2");
      break;
    case Line_follower__St_1_DelayP1:
      strcpy(buf, "St_1_DelayP1");
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
  if ((strcmp(s, "St_WaitForNextIncrement")==0)) {
    return Line_follower__St_WaitForNextIncrement;
  };
  if ((strcmp(s, "St_Initial")==0)) {
    return Line_follower__St_Initial;
  };
  if ((strcmp(s, "St_CountIncrement")==0)) {
    return Line_follower__St_CountIncrement;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_WaitForNextIncrement:
      strcpy(buf, "St_WaitForNextIncrement");
      break;
    case Line_follower__St_Initial:
      strcpy(buf, "St_Initial");
      break;
    case Line_follower__St_CountIncrement:
      strcpy(buf, "St_CountIncrement");
      break;
    default:
      break;
  };
  return buf;
}

