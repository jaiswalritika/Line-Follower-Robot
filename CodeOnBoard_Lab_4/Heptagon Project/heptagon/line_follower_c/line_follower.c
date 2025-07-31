/* --- Generated the 30/3/2025 at 16:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__findpid_reset(Line_follower__findpid_mem* self) {
  self->v = true;
}

void Line_follower__findpid_step(int sen3, int sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self) {
  
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int z;
  int p;
  int d;
  int error;
  if (self->v) {
    v_1 = 0;
  } else {
    v_1 = self->error_1;
  };
  error = (sen3-sen1);
  d = (error-v_1);
  v_3 = (Line_follower__kd*d);
  p = error;
  v_2 = (Line_follower__kp*p);
  z = (v_2+v_3);
  v_4 = (z>0);
  if (v_4) {
    _out->pid = 15;
  } else {
    _out->pid = -15;
  };
  self->error_1 = error;
  self->v = false;;
}

void Line_follower__counter_reset(Line_follower__counter_mem* self) {
  self->beaconcount_1 = 0;
  self->flg_1 = false;
  self->cnt_2 = 0;
  self->pnr = false;
  self->ck = Line_follower__St_Ready;
}

void Line_follower__counter_step(int sen0, int sen1, int sen2, int sen3,
                                 int sen4, int beacon, int flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self) {
  
  int v_5;
  int v;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int r_St_Wait;
  Line_follower__st s_St_Wait;
  int r_St_Increment;
  Line_follower__st s_St_Increment;
  int r_St_Ready;
  Line_follower__st s_St_Ready;
  int nr_St_Wait;
  Line_follower__st ns_St_Wait;
  int beaconcount_St_Wait;
  int cnt_St_Wait;
  int nr_St_Increment;
  Line_follower__st ns_St_Increment;
  int beaconcount_St_Increment;
  int cnt_St_Increment;
  int nr_St_Ready;
  Line_follower__st ns_St_Ready;
  int beaconcount_St_Ready;
  int cnt_St_Ready;
  Line_follower__st ck_1;
  Line_follower__st s;
  Line_follower__st ns;
  int r;
  int nr;
  int cnt;
  int flg;
  int beaconcount;
  flg = flag;
  switch (self->ck) {
    case Line_follower__St_Ready:
      v_6 = (sen1+sen2);
      v_7 = (v_6+sen3);
      v_8 = (v_7<2250);
      v_9 = (flag&&v_8);
      if (v_9) {
        r_St_Ready = false;
        s_St_Ready = Line_follower__St_Increment;
      } else {
        r_St_Ready = self->pnr;
        s_St_Ready = Line_follower__St_Ready;
      };
      s = s_St_Ready;
      r = r_St_Ready;
      break;
    case Line_follower__St_Increment:
      r_St_Increment = self->pnr;
      s_St_Increment = Line_follower__St_Increment;
      s = s_St_Increment;
      r = r_St_Increment;
      break;
    case Line_follower__St_Wait:
      v = (self->beaconcount_1>1);
      v_5 = (flag&&v);
      if (v_5) {
        r_St_Wait = false;
        s_St_Wait = Line_follower__St_Ready;
      } else {
        r_St_Wait = self->pnr;
        s_St_Wait = Line_follower__St_Wait;
      };
      s = s_St_Wait;
      r = r_St_Wait;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Line_follower__St_Ready:
      beaconcount_St_Ready = 0;
      cnt_St_Ready = self->cnt_2;
      nr_St_Ready = false;
      ns_St_Ready = Line_follower__St_Ready;
      cnt = cnt_St_Ready;
      beaconcount = beaconcount_St_Ready;
      ns = ns_St_Ready;
      nr = nr_St_Ready;
      break;
    case Line_follower__St_Increment:
      beaconcount_St_Increment = 0;
      cnt_St_Increment = (self->cnt_2+1);
      if (true) {
        nr_St_Increment = true;
      } else {
        nr_St_Increment = false;
      };
      if (true) {
        ns_St_Increment = Line_follower__St_Wait;
      } else {
        ns_St_Increment = Line_follower__St_Increment;
      };
      cnt = cnt_St_Increment;
      beaconcount = beaconcount_St_Increment;
      ns = ns_St_Increment;
      nr = nr_St_Increment;
      break;
    case Line_follower__St_Wait:
      cnt_St_Wait = self->cnt_2;
      beaconcount_St_Wait = (self->beaconcount_1+beacon);
      nr_St_Wait = false;
      ns_St_Wait = Line_follower__St_Wait;
      cnt = cnt_St_Wait;
      beaconcount = beaconcount_St_Wait;
      ns = ns_St_Wait;
      nr = nr_St_Wait;
      break;
    default:
      break;
  };
  _out->count = cnt;
  self->beaconcount_1 = beaconcount;
  self->flg_1 = flg;
  self->cnt_2 = cnt;
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__findpid_reset(&self->findpid);
  Line_follower__counter_reset(&self->counter);
  self->v_79 = true;
  self->v_74 = true;
  self->v_69 = true;
  self->v_64 = true;
  self->v_59 = true;
  self->v_54 = true;
  self->v_49 = true;
  self->v_43 = true;
  self->v_38 = true;
  self->v_33 = true;
  self->pnr = false;
  self->ck = Line_follower__St_1_Forward;
}

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_d_front, int ir_d_left,
                              int beacon, int second,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__findpid_out Line_follower__findpid_out_st;
  Line_follower__counter_out Line_follower__counter_out_st;
  
  int v_36;
  int v_34;
  int v_32;
  int v_41;
  int v_39;
  int v_37;
  int v_46;
  int v_44;
  int v_42;
  int v_47;
  int v_52;
  int v_50;
  int v_48;
  int v_57;
  int v_55;
  int v_53;
  int v_62;
  int v_60;
  int v_58;
  int v_67;
  int v_65;
  int v_63;
  int v_72;
  int v_70;
  int v_68;
  int v_77;
  int v_75;
  int v_73;
  int v_82;
  int v_80;
  int v_78;
  int v_90;
  Line_follower__st_1 v_89;
  int v_88;
  Line_follower__st_1 v_87;
  int v_86;
  Line_follower__st_1 v_85;
  int v_84;
  Line_follower__st_1 v_83;
  int v_98;
  Line_follower__st_1 v_97;
  int v_96;
  Line_follower__st_1 v_95;
  int v_94;
  Line_follower__st_1 v_93;
  int v_92;
  Line_follower__st_1 v_91;
  int v_100;
  Line_follower__st_1 v_99;
  int v_102;
  Line_follower__st_1 v_101;
  int v_123;
  Line_follower__st_1 v_122;
  int v_121;
  Line_follower__st_1 v_120;
  int v_119;
  Line_follower__st_1 v_118;
  int v_117;
  Line_follower__st_1 v_116;
  int v_115;
  Line_follower__st_1 v_114;
  int v_113;
  Line_follower__st_1 v_112;
  int v_111;
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_135;
  Line_follower__st_1 v_134;
  int v_133;
  Line_follower__st_1 v_132;
  int v_131;
  Line_follower__st_1 v_130;
  int v_129;
  Line_follower__st_1 v_128;
  int v_127;
  Line_follower__st_1 v_126;
  int v_125;
  Line_follower__st_1 v_124;
  int v_147;
  Line_follower__st_1 v_146;
  int v_145;
  Line_follower__st_1 v_144;
  int v_143;
  Line_follower__st_1 v_142;
  int v_141;
  Line_follower__st_1 v_140;
  int v_139;
  Line_follower__st_1 v_138;
  int v_137;
  Line_follower__st_1 v_136;
  int v_159;
  Line_follower__st_1 v_158;
  int v_157;
  Line_follower__st_1 v_156;
  int v_155;
  Line_follower__st_1 v_154;
  int v_153;
  Line_follower__st_1 v_152;
  int v_151;
  Line_follower__st_1 v_150;
  int v_149;
  Line_follower__st_1 v_148;
  int v_169;
  Line_follower__st_1 v_168;
  int v_167;
  Line_follower__st_1 v_166;
  int v_165;
  Line_follower__st_1 v_164;
  int v_163;
  Line_follower__st_1 v_162;
  int v_161;
  Line_follower__st_1 v_160;
  int v_181;
  Line_follower__st_1 v_180;
  int v_179;
  Line_follower__st_1 v_178;
  int v_177;
  Line_follower__st_1 v_176;
  int v_175;
  Line_follower__st_1 v_174;
  int v_173;
  Line_follower__st_1 v_172;
  int v_171;
  int v_170;
  int v_189;
  Line_follower__st_1 v_188;
  int v_187;
  Line_follower__st_1 v_186;
  int v_185;
  Line_follower__st_1 v_184;
  int v_183;
  Line_follower__st_1 v_182;
  int nr_St_1_RightTurn3;
  Line_follower__st_1 ns_St_1_RightTurn3;
  int rightturn_count_St_1_RightTurn3;
  int timer_St_1_RightTurn3;
  int flag_St_1_RightTurn3;
  int dir_St_1_RightTurn3;
  int v_r_St_1_RightTurn3;
  int v_l_St_1_RightTurn3;
  int nr_St_1_Move5;
  Line_follower__st_1 ns_St_1_Move5;
  int rightturn_count_St_1_Move5;
  int timer_St_1_Move5;
  int flag_St_1_Move5;
  int dir_St_1_Move5;
  int v_r_St_1_Move5;
  int v_l_St_1_Move5;
  int nr_St_1_LeftTurn2;
  Line_follower__st_1 ns_St_1_LeftTurn2;
  int rightturn_count_St_1_LeftTurn2;
  int timer_St_1_LeftTurn2;
  int flag_St_1_LeftTurn2;
  int dir_St_1_LeftTurn2;
  int v_r_St_1_LeftTurn2;
  int v_l_St_1_LeftTurn2;
  int nr_St_1_Move4;
  Line_follower__st_1 ns_St_1_Move4;
  int rightturn_count_St_1_Move4;
  int timer_St_1_Move4;
  int flag_St_1_Move4;
  int dir_St_1_Move4;
  int v_r_St_1_Move4;
  int v_l_St_1_Move4;
  int nr_St_1_Forward2;
  Line_follower__st_1 ns_St_1_Forward2;
  int rightturn_count_St_1_Forward2;
  int timer_St_1_Forward2;
  int flag_St_1_Forward2;
  int dir_St_1_Forward2;
  int v_r_St_1_Forward2;
  int v_l_St_1_Forward2;
  int nr_St_1_Move3;
  Line_follower__st_1 ns_St_1_Move3;
  int rightturn_count_St_1_Move3;
  int timer_St_1_Move3;
  int flag_St_1_Move3;
  int dir_St_1_Move3;
  int v_r_St_1_Move3;
  int v_l_St_1_Move3;
  int nr_St_1_LeftTurn1;
  Line_follower__st_1 ns_St_1_LeftTurn1;
  int rightturn_count_St_1_LeftTurn1;
  int timer_St_1_LeftTurn1;
  int flag_St_1_LeftTurn1;
  int dir_St_1_LeftTurn1;
  int v_r_St_1_LeftTurn1;
  int v_l_St_1_LeftTurn1;
  int nr_St_1_Move2;
  Line_follower__st_1 ns_St_1_Move2;
  int rightturn_count_St_1_Move2;
  int timer_St_1_Move2;
  int flag_St_1_Move2;
  int dir_St_1_Move2;
  int v_r_St_1_Move2;
  int v_l_St_1_Move2;
  int nr_St_1_Forward1;
  Line_follower__st_1 ns_St_1_Forward1;
  int rightturn_count_St_1_Forward1;
  int timer_St_1_Forward1;
  int flag_St_1_Forward1;
  int dir_St_1_Forward1;
  int v_r_St_1_Forward1;
  int v_l_St_1_Forward1;
  int nr_St_1_Move1;
  Line_follower__st_1 ns_St_1_Move1;
  int rightturn_count_St_1_Move1;
  int timer_St_1_Move1;
  int flag_St_1_Move1;
  int dir_St_1_Move1;
  int v_r_St_1_Move1;
  int v_l_St_1_Move1;
  int nr_St_1_RightTurn1;
  Line_follower__st_1 ns_St_1_RightTurn1;
  int rightturn_count_St_1_RightTurn1;
  int timer_St_1_RightTurn1;
  int flag_St_1_RightTurn1;
  int dir_St_1_RightTurn1;
  int v_r_St_1_RightTurn1;
  int v_l_St_1_RightTurn1;
  int nr_St_1_ObstacleAvoidance;
  Line_follower__st_1 ns_St_1_ObstacleAvoidance;
  int rightturn_count_St_1_ObstacleAvoidance;
  int timer_St_1_ObstacleAvoidance;
  int flag_St_1_ObstacleAvoidance;
  int dir_St_1_ObstacleAvoidance;
  int v_r_St_1_ObstacleAvoidance;
  int v_l_St_1_ObstacleAvoidance;
  int nr_St_1_BlackDriftRight;
  Line_follower__st_1 ns_St_1_BlackDriftRight;
  int rightturn_count_St_1_BlackDriftRight;
  int timer_St_1_BlackDriftRight;
  int flag_St_1_BlackDriftRight;
  int dir_St_1_BlackDriftRight;
  int v_r_St_1_BlackDriftRight;
  int v_l_St_1_BlackDriftRight;
  int nr_St_1_BlackDriftLeft;
  Line_follower__st_1 ns_St_1_BlackDriftLeft;
  int rightturn_count_St_1_BlackDriftLeft;
  int timer_St_1_BlackDriftLeft;
  int flag_St_1_BlackDriftLeft;
  int dir_St_1_BlackDriftLeft;
  int v_r_St_1_BlackDriftLeft;
  int v_l_St_1_BlackDriftLeft;
  int nr_St_1_BlackRight;
  Line_follower__st_1 ns_St_1_BlackRight;
  int rightturn_count_St_1_BlackRight;
  int timer_St_1_BlackRight;
  int flag_St_1_BlackRight;
  int dir_St_1_BlackRight;
  int v_r_St_1_BlackRight;
  int v_l_St_1_BlackRight;
  int nr_St_1_BlackLeft;
  Line_follower__st_1 ns_St_1_BlackLeft;
  int rightturn_count_St_1_BlackLeft;
  int timer_St_1_BlackLeft;
  int flag_St_1_BlackLeft;
  int dir_St_1_BlackLeft;
  int v_r_St_1_BlackLeft;
  int v_l_St_1_BlackLeft;
  int nr_St_1_BlackStop;
  Line_follower__st_1 ns_St_1_BlackStop;
  int rightturn_count_St_1_BlackStop;
  int timer_St_1_BlackStop;
  int flag_St_1_BlackStop;
  int dir_St_1_BlackStop;
  int v_r_St_1_BlackStop;
  int v_l_St_1_BlackStop;
  int nr_St_1_BlackForward;
  Line_follower__st_1 ns_St_1_BlackForward;
  int rightturn_count_St_1_BlackForward;
  int timer_St_1_BlackForward;
  int flag_St_1_BlackForward;
  int dir_St_1_BlackForward;
  int v_r_St_1_BlackForward;
  int v_l_St_1_BlackForward;
  int nr_St_1_DriftRight;
  Line_follower__st_1 ns_St_1_DriftRight;
  int rightturn_count_St_1_DriftRight;
  int timer_St_1_DriftRight;
  int flag_St_1_DriftRight;
  int dir_St_1_DriftRight;
  int v_r_St_1_DriftRight;
  int v_l_St_1_DriftRight;
  int nr_St_1_DriftLeft;
  Line_follower__st_1 ns_St_1_DriftLeft;
  int rightturn_count_St_1_DriftLeft;
  int timer_St_1_DriftLeft;
  int flag_St_1_DriftLeft;
  int dir_St_1_DriftLeft;
  int v_r_St_1_DriftLeft;
  int v_l_St_1_DriftLeft;
  int nr_St_1_Right;
  Line_follower__st_1 ns_St_1_Right;
  int rightturn_count_St_1_Right;
  int timer_St_1_Right;
  int flag_St_1_Right;
  int dir_St_1_Right;
  int v_r_St_1_Right;
  int v_l_St_1_Right;
  int nr_St_1_Left;
  Line_follower__st_1 ns_St_1_Left;
  int rightturn_count_St_1_Left;
  int timer_St_1_Left;
  int flag_St_1_Left;
  int dir_St_1_Left;
  int v_r_St_1_Left;
  int v_l_St_1_Left;
  int nr_St_1_Stop;
  Line_follower__st_1 ns_St_1_Stop;
  int rightturn_count_St_1_Stop;
  int timer_St_1_Stop;
  int flag_St_1_Stop;
  int dir_St_1_Stop;
  int v_r_St_1_Stop;
  int v_l_St_1_Stop;
  int nr_St_1_Forward;
  Line_follower__st_1 ns_St_1_Forward;
  int rightturn_count_St_1_Forward;
  int timer_St_1_Forward;
  int flag_St_1_Forward;
  int dir_St_1_Forward;
  int v_r_St_1_Forward;
  int v_l_St_1_Forward;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v;
  Line_follower__st_1 ns;
  int r;
  int nr;
  int pid;
  int wspeed;
  int bspeed;
  int oasspeed;
  int count;
  int flag;
  int c1;
  int c2;
  int c3;
  int c4;
  int c5;
  int blacknodedetected;
  int b3;
  int b4;
  int b5;
  int switch_condition;
  int timer;
  int rightturn_count;
  r = self->pnr;
  v_31 = (sen2>700);
  v_30 = (sen3<700);
  b5 = (v_30&&v_31);
  v_29 = (sen2>700);
  v_28 = (sen1<700);
  b4 = (v_28&&v_29);
  b3 = (sen4<700);
  v_24 = (sen0+sen1);
  v_25 = (v_24+sen2);
  v_26 = (v_25+sen3);
  v_27 = (v_26+sen4);
  blacknodedetected = (v_27<3000);
  oasspeed = 40;
  bspeed = 40;
  wspeed = 40;
  v_22 = (sen0+sen1);
  v_23 = (v_22>1400);
  v_20 = (sen4>800);
  v_19 = (sen2<700);
  v_21 = (v_19&&v_20);
  switch_condition = (v_21&&v_23);
  v_18 = (sen2<800);
  v_17 = (sen3>900);
  c5 = (v_17&&v_18);
  v_16 = (sen2<800);
  v_15 = (sen1>900);
  c4 = (v_15&&v_16);
  c3 = (sen4>900);
  v_13 = (sen0*18);
  v_14 = (v_13/10);
  c2 = (v_14>900);
  v = (sen0+sen1);
  v_10 = (v+sen2);
  v_11 = (v_10+sen3);
  v_12 = (v_11+sen4);
  c1 = (v_12>4500);
  Line_follower__findpid_step(sen3, sen1, &Line_follower__findpid_out_st,
                              &self->findpid);
  pid = Line_follower__findpid_out_st.pid;
  switch (self->ck) {
    case Line_follower__St_1_Forward:
      rightturn_count_St_1_Forward = self->rightturn_count_1;
      timer_St_1_Forward = self->timer_1;
      dir_St_1_Forward = 1;
      flag_St_1_Forward = false;
      v_r_St_1_Forward = wspeed;
      v_l_St_1_Forward = wspeed;
      if (c5) {
        v_183 = true;
      } else {
        v_183 = false;
      };
      if (c4) {
        v_185 = true;
      } else {
        v_185 = v_183;
      };
      if (c3) {
        v_187 = true;
      } else {
        v_187 = v_185;
      };
      if (c2) {
        v_189 = true;
      } else {
        v_189 = v_187;
      };
      if (switch_condition) {
        nr_St_1_Forward = true;
      } else {
        nr_St_1_Forward = v_189;
      };
      if (c5) {
        v_182 = Line_follower__St_1_DriftLeft;
      } else {
        v_182 = Line_follower__St_1_Forward;
      };
      if (c4) {
        v_184 = Line_follower__St_1_DriftRight;
      } else {
        v_184 = v_182;
      };
      if (c3) {
        v_186 = Line_follower__St_1_Right;
      } else {
        v_186 = v_184;
      };
      if (c2) {
        v_188 = Line_follower__St_1_Left;
      } else {
        v_188 = v_186;
      };
      if (switch_condition) {
        ns_St_1_Forward = Line_follower__St_1_BlackForward;
      } else {
        ns_St_1_Forward = v_188;
      };
      _out->v_l = v_l_St_1_Forward;
      _out->v_r = v_r_St_1_Forward;
      _out->dir = dir_St_1_Forward;
      flag = flag_St_1_Forward;
      timer = timer_St_1_Forward;
      rightturn_count = rightturn_count_St_1_Forward;
      break;
    case Line_follower__St_1_Stop:
      rightturn_count_St_1_Stop = self->rightturn_count_1;
      timer_St_1_Stop = self->timer_1;
      dir_St_1_Stop = 0;
      flag_St_1_Stop = false;
      v_r_St_1_Stop = 0;
      v_l_St_1_Stop = 0;
      if (true) {
        v_173 = true;
      } else {
        v_173 = false;
      };
      if (c5) {
        v_175 = true;
      } else {
        v_175 = v_173;
      };
      if (c4) {
        v_177 = true;
      } else {
        v_177 = v_175;
      };
      if (c3) {
        v_179 = true;
      } else {
        v_179 = v_177;
      };
      if (true) {
        v_172 = Line_follower__St_1_Forward;
      } else {
        v_172 = Line_follower__St_1_Stop;
      };
      if (c5) {
        v_174 = Line_follower__St_1_DriftLeft;
      } else {
        v_174 = v_172;
      };
      if (c4) {
        v_176 = Line_follower__St_1_DriftRight;
      } else {
        v_176 = v_174;
      };
      if (c3) {
        v_178 = Line_follower__St_1_Right;
      } else {
        v_178 = v_176;
      };
      v_170 = !(c1);
      v_171 = (v_170&&c2);
      if (v_171) {
        v_181 = true;
      } else {
        v_181 = v_179;
      };
      if (switch_condition) {
        nr_St_1_Stop = true;
      } else {
        nr_St_1_Stop = v_181;
      };
      if (v_171) {
        v_180 = Line_follower__St_1_Left;
      } else {
        v_180 = v_178;
      };
      if (switch_condition) {
        ns_St_1_Stop = Line_follower__St_1_BlackForward;
      } else {
        ns_St_1_Stop = v_180;
      };
      _out->v_l = v_l_St_1_Stop;
      _out->v_r = v_r_St_1_Stop;
      _out->dir = dir_St_1_Stop;
      flag = flag_St_1_Stop;
      timer = timer_St_1_Stop;
      rightturn_count = rightturn_count_St_1_Stop;
      break;
    case Line_follower__St_1_Left:
      rightturn_count_St_1_Left = self->rightturn_count_1;
      timer_St_1_Left = self->timer_1;
      dir_St_1_Left = 4;
      flag_St_1_Left = false;
      v_r_St_1_Left = wspeed;
      v_l_St_1_Left = wspeed;
      if (true) {
        v_161 = true;
      } else {
        v_161 = false;
      };
      if (c5) {
        v_163 = true;
      } else {
        v_163 = v_161;
      };
      if (c4) {
        v_165 = true;
      } else {
        v_165 = v_163;
      };
      if (c3) {
        v_167 = true;
      } else {
        v_167 = v_165;
      };
      if (switch_condition) {
        v_169 = true;
      } else {
        v_169 = v_167;
      };
      if (c1) {
        nr_St_1_Left = true;
      } else {
        nr_St_1_Left = v_169;
      };
      if (true) {
        v_160 = Line_follower__St_1_Forward;
      } else {
        v_160 = Line_follower__St_1_Left;
      };
      if (c5) {
        v_162 = Line_follower__St_1_DriftLeft;
      } else {
        v_162 = v_160;
      };
      if (c4) {
        v_164 = Line_follower__St_1_DriftRight;
      } else {
        v_164 = v_162;
      };
      if (c3) {
        v_166 = Line_follower__St_1_Right;
      } else {
        v_166 = v_164;
      };
      if (switch_condition) {
        v_168 = Line_follower__St_1_BlackForward;
      } else {
        v_168 = v_166;
      };
      if (c1) {
        ns_St_1_Left = Line_follower__St_1_Stop;
      } else {
        ns_St_1_Left = v_168;
      };
      _out->v_l = v_l_St_1_Left;
      _out->v_r = v_r_St_1_Left;
      _out->dir = dir_St_1_Left;
      flag = flag_St_1_Left;
      timer = timer_St_1_Left;
      rightturn_count = rightturn_count_St_1_Left;
      break;
    case Line_follower__St_1_Right:
      rightturn_count_St_1_Right = self->rightturn_count_1;
      timer_St_1_Right = self->timer_1;
      dir_St_1_Right = 5;
      flag_St_1_Right = false;
      v_r_St_1_Right = wspeed;
      v_l_St_1_Right = wspeed;
      if (true) {
        v_149 = true;
      } else {
        v_149 = false;
      };
      if (c5) {
        v_151 = true;
      } else {
        v_151 = v_149;
      };
      if (c4) {
        v_153 = true;
      } else {
        v_153 = v_151;
      };
      if (c3) {
        v_155 = true;
      } else {
        v_155 = v_153;
      };
      if (c2) {
        v_157 = true;
      } else {
        v_157 = v_155;
      };
      if (switch_condition) {
        v_159 = true;
      } else {
        v_159 = v_157;
      };
      if (c1) {
        nr_St_1_Right = true;
      } else {
        nr_St_1_Right = v_159;
      };
      if (true) {
        v_148 = Line_follower__St_1_Forward;
      } else {
        v_148 = Line_follower__St_1_Right;
      };
      if (c5) {
        v_150 = Line_follower__St_1_DriftLeft;
      } else {
        v_150 = v_148;
      };
      if (c4) {
        v_152 = Line_follower__St_1_DriftRight;
      } else {
        v_152 = v_150;
      };
      if (c3) {
        v_154 = Line_follower__St_1_Right;
      } else {
        v_154 = v_152;
      };
      if (c2) {
        v_156 = Line_follower__St_1_Left;
      } else {
        v_156 = v_154;
      };
      if (switch_condition) {
        v_158 = Line_follower__St_1_BlackForward;
      } else {
        v_158 = v_156;
      };
      if (c1) {
        ns_St_1_Right = Line_follower__St_1_Stop;
      } else {
        ns_St_1_Right = v_158;
      };
      _out->v_l = v_l_St_1_Right;
      _out->v_r = v_r_St_1_Right;
      _out->dir = dir_St_1_Right;
      flag = flag_St_1_Right;
      timer = timer_St_1_Right;
      rightturn_count = rightturn_count_St_1_Right;
      break;
    case Line_follower__St_1_DriftLeft:
      rightturn_count_St_1_DriftLeft = self->rightturn_count_1;
      timer_St_1_DriftLeft = self->timer_1;
      flag_St_1_DriftLeft = false;
      dir_St_1_DriftLeft = 3;
      v_r_St_1_DriftLeft = (wspeed+pid);
      v_l_St_1_DriftLeft = 0;
      if (true) {
        v_137 = true;
      } else {
        v_137 = false;
      };
      if (c5) {
        v_139 = true;
      } else {
        v_139 = v_137;
      };
      if (c4) {
        v_141 = true;
      } else {
        v_141 = v_139;
      };
      if (c3) {
        v_143 = true;
      } else {
        v_143 = v_141;
      };
      if (c2) {
        v_145 = true;
      } else {
        v_145 = v_143;
      };
      if (switch_condition) {
        v_147 = true;
      } else {
        v_147 = v_145;
      };
      if (c1) {
        nr_St_1_DriftLeft = true;
      } else {
        nr_St_1_DriftLeft = v_147;
      };
      if (true) {
        v_136 = Line_follower__St_1_Forward;
      } else {
        v_136 = Line_follower__St_1_DriftLeft;
      };
      if (c5) {
        v_138 = Line_follower__St_1_DriftLeft;
      } else {
        v_138 = v_136;
      };
      if (c4) {
        v_140 = Line_follower__St_1_DriftRight;
      } else {
        v_140 = v_138;
      };
      if (c3) {
        v_142 = Line_follower__St_1_Right;
      } else {
        v_142 = v_140;
      };
      if (c2) {
        v_144 = Line_follower__St_1_Left;
      } else {
        v_144 = v_142;
      };
      if (switch_condition) {
        v_146 = Line_follower__St_1_BlackForward;
      } else {
        v_146 = v_144;
      };
      if (c1) {
        ns_St_1_DriftLeft = Line_follower__St_1_Stop;
      } else {
        ns_St_1_DriftLeft = v_146;
      };
      _out->v_l = v_l_St_1_DriftLeft;
      _out->v_r = v_r_St_1_DriftLeft;
      _out->dir = dir_St_1_DriftLeft;
      flag = flag_St_1_DriftLeft;
      timer = timer_St_1_DriftLeft;
      rightturn_count = rightturn_count_St_1_DriftLeft;
      break;
    case Line_follower__St_1_DriftRight:
      rightturn_count_St_1_DriftRight = self->rightturn_count_1;
      timer_St_1_DriftRight = self->timer_1;
      flag_St_1_DriftRight = false;
      dir_St_1_DriftRight = 2;
      v_r_St_1_DriftRight = 0;
      v_l_St_1_DriftRight = (wspeed+pid);
      if (true) {
        v_125 = true;
      } else {
        v_125 = false;
      };
      if (c5) {
        v_127 = true;
      } else {
        v_127 = v_125;
      };
      if (c4) {
        v_129 = true;
      } else {
        v_129 = v_127;
      };
      if (c3) {
        v_131 = true;
      } else {
        v_131 = v_129;
      };
      if (c2) {
        v_133 = true;
      } else {
        v_133 = v_131;
      };
      if (switch_condition) {
        v_135 = true;
      } else {
        v_135 = v_133;
      };
      if (c1) {
        nr_St_1_DriftRight = true;
      } else {
        nr_St_1_DriftRight = v_135;
      };
      if (true) {
        v_124 = Line_follower__St_1_Forward;
      } else {
        v_124 = Line_follower__St_1_DriftRight;
      };
      if (c5) {
        v_126 = Line_follower__St_1_DriftLeft;
      } else {
        v_126 = v_124;
      };
      if (c4) {
        v_128 = Line_follower__St_1_DriftRight;
      } else {
        v_128 = v_126;
      };
      if (c3) {
        v_130 = Line_follower__St_1_Right;
      } else {
        v_130 = v_128;
      };
      if (c2) {
        v_132 = Line_follower__St_1_Left;
      } else {
        v_132 = v_130;
      };
      if (switch_condition) {
        v_134 = Line_follower__St_1_BlackForward;
      } else {
        v_134 = v_132;
      };
      if (c1) {
        ns_St_1_DriftRight = Line_follower__St_1_Stop;
      } else {
        ns_St_1_DriftRight = v_134;
      };
      _out->v_l = v_l_St_1_DriftRight;
      _out->v_r = v_r_St_1_DriftRight;
      _out->dir = dir_St_1_DriftRight;
      flag = flag_St_1_DriftRight;
      timer = timer_St_1_DriftRight;
      rightturn_count = rightturn_count_St_1_DriftRight;
      break;
    case Line_follower__St_1_BlackForward:
      rightturn_count_St_1_BlackForward = self->rightturn_count_1;
      timer_St_1_BlackForward = self->timer_1;
      dir_St_1_BlackForward = 1;
      flag_St_1_BlackForward = true;
      v_r_St_1_BlackForward = bspeed;
      v_l_St_1_BlackForward = bspeed;
      if (true) {
        v_113 = true;
      } else {
        v_113 = false;
      };
      if (b5) {
        v_115 = true;
      } else {
        v_115 = v_113;
      };
      if (b4) {
        v_117 = true;
      } else {
        v_117 = v_115;
      };
      if (true) {
        v_112 = Line_follower__St_1_BlackForward;
      } else {
        v_112 = Line_follower__St_1_BlackForward;
      };
      if (b5) {
        v_114 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_114 = v_112;
      };
      if (b4) {
        v_116 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_116 = v_114;
      };
      v_103 = (ir_d_front>-1);
      _out->v_l = v_l_St_1_BlackForward;
      _out->v_r = v_r_St_1_BlackForward;
      _out->dir = dir_St_1_BlackForward;
      flag = flag_St_1_BlackForward;
      timer = timer_St_1_BlackForward;
      rightturn_count = rightturn_count_St_1_BlackForward;
      break;
    case Line_follower__St_1_BlackStop:
      rightturn_count_St_1_BlackStop = self->rightturn_count_1;
      timer_St_1_BlackStop = self->timer_1;
      flag_St_1_BlackStop = true;
      dir_St_1_BlackStop = 0;
      v_r_St_1_BlackStop = 0;
      v_l_St_1_BlackStop = 0;
      if (true) {
        nr_St_1_BlackStop = true;
      } else {
        nr_St_1_BlackStop = false;
      };
      if (true) {
        ns_St_1_BlackStop = Line_follower__St_1_BlackStop;
      } else {
        ns_St_1_BlackStop = Line_follower__St_1_BlackStop;
      };
      _out->v_l = v_l_St_1_BlackStop;
      _out->v_r = v_r_St_1_BlackStop;
      _out->dir = dir_St_1_BlackStop;
      flag = flag_St_1_BlackStop;
      timer = timer_St_1_BlackStop;
      rightturn_count = rightturn_count_St_1_BlackStop;
      break;
    case Line_follower__St_1_BlackLeft:
      rightturn_count_St_1_BlackLeft = self->rightturn_count_1;
      timer_St_1_BlackLeft = self->timer_1;
      dir_St_1_BlackLeft = 4;
      flag_St_1_BlackLeft = true;
      v_r_St_1_BlackLeft = bspeed;
      v_l_St_1_BlackLeft = bspeed;
      if (true) {
        v_102 = true;
      } else {
        v_102 = false;
      };
      if (blacknodedetected) {
        nr_St_1_BlackLeft = true;
      } else {
        nr_St_1_BlackLeft = v_102;
      };
      if (true) {
        v_101 = Line_follower__St_1_BlackForward;
      } else {
        v_101 = Line_follower__St_1_BlackLeft;
      };
      if (blacknodedetected) {
        ns_St_1_BlackLeft = Line_follower__St_1_BlackLeft;
      } else {
        ns_St_1_BlackLeft = v_101;
      };
      _out->v_l = v_l_St_1_BlackLeft;
      _out->v_r = v_r_St_1_BlackLeft;
      _out->dir = dir_St_1_BlackLeft;
      flag = flag_St_1_BlackLeft;
      timer = timer_St_1_BlackLeft;
      rightturn_count = rightturn_count_St_1_BlackLeft;
      break;
    case Line_follower__St_1_BlackRight:
      rightturn_count_St_1_BlackRight = self->rightturn_count_1;
      timer_St_1_BlackRight = self->timer_1;
      dir_St_1_BlackRight = 5;
      flag_St_1_BlackRight = true;
      v_r_St_1_BlackRight = bspeed;
      v_l_St_1_BlackRight = bspeed;
      if (true) {
        v_100 = true;
      } else {
        v_100 = false;
      };
      if (blacknodedetected) {
        nr_St_1_BlackRight = true;
      } else {
        nr_St_1_BlackRight = v_100;
      };
      if (true) {
        v_99 = Line_follower__St_1_BlackForward;
      } else {
        v_99 = Line_follower__St_1_BlackRight;
      };
      if (blacknodedetected) {
        ns_St_1_BlackRight = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackRight = v_99;
      };
      _out->v_l = v_l_St_1_BlackRight;
      _out->v_r = v_r_St_1_BlackRight;
      _out->dir = dir_St_1_BlackRight;
      flag = flag_St_1_BlackRight;
      timer = timer_St_1_BlackRight;
      rightturn_count = rightturn_count_St_1_BlackRight;
      break;
    case Line_follower__St_1_BlackDriftLeft:
      rightturn_count_St_1_BlackDriftLeft = self->rightturn_count_1;
      timer_St_1_BlackDriftLeft = self->timer_1;
      flag_St_1_BlackDriftLeft = true;
      dir_St_1_BlackDriftLeft = 3;
      v_r_St_1_BlackDriftLeft = (bspeed+pid);
      v_l_St_1_BlackDriftLeft = 0;
      if (true) {
        v_92 = true;
      } else {
        v_92 = false;
      };
      if (b5) {
        v_94 = true;
      } else {
        v_94 = v_92;
      };
      if (b4) {
        v_96 = true;
      } else {
        v_96 = v_94;
      };
      if (switch_condition) {
        v_98 = true;
      } else {
        v_98 = v_96;
      };
      if (blacknodedetected) {
        nr_St_1_BlackDriftLeft = true;
      } else {
        nr_St_1_BlackDriftLeft = v_98;
      };
      if (true) {
        v_91 = Line_follower__St_1_BlackForward;
      } else {
        v_91 = Line_follower__St_1_BlackDriftLeft;
      };
      if (b5) {
        v_93 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_93 = v_91;
      };
      if (b4) {
        v_95 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_95 = v_93;
      };
      if (switch_condition) {
        v_97 = Line_follower__St_1_BlackForward;
      } else {
        v_97 = v_95;
      };
      if (blacknodedetected) {
        ns_St_1_BlackDriftLeft = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackDriftLeft = v_97;
      };
      _out->v_l = v_l_St_1_BlackDriftLeft;
      _out->v_r = v_r_St_1_BlackDriftLeft;
      _out->dir = dir_St_1_BlackDriftLeft;
      flag = flag_St_1_BlackDriftLeft;
      timer = timer_St_1_BlackDriftLeft;
      rightturn_count = rightturn_count_St_1_BlackDriftLeft;
      break;
    case Line_follower__St_1_BlackDriftRight:
      rightturn_count_St_1_BlackDriftRight = self->rightturn_count_1;
      timer_St_1_BlackDriftRight = self->timer_1;
      flag_St_1_BlackDriftRight = true;
      dir_St_1_BlackDriftRight = 2;
      v_r_St_1_BlackDriftRight = 0;
      v_l_St_1_BlackDriftRight = (bspeed+pid);
      if (true) {
        v_84 = true;
      } else {
        v_84 = false;
      };
      if (b5) {
        v_86 = true;
      } else {
        v_86 = v_84;
      };
      if (b4) {
        v_88 = true;
      } else {
        v_88 = v_86;
      };
      if (switch_condition) {
        v_90 = true;
      } else {
        v_90 = v_88;
      };
      if (blacknodedetected) {
        nr_St_1_BlackDriftRight = true;
      } else {
        nr_St_1_BlackDriftRight = v_90;
      };
      if (true) {
        v_83 = Line_follower__St_1_BlackForward;
      } else {
        v_83 = Line_follower__St_1_BlackDriftRight;
      };
      if (b5) {
        v_85 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_85 = v_83;
      };
      if (b4) {
        v_87 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_87 = v_85;
      };
      if (switch_condition) {
        v_89 = Line_follower__St_1_BlackForward;
      } else {
        v_89 = v_87;
      };
      if (blacknodedetected) {
        ns_St_1_BlackDriftRight = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackDriftRight = v_89;
      };
      _out->v_l = v_l_St_1_BlackDriftRight;
      _out->v_r = v_r_St_1_BlackDriftRight;
      _out->dir = dir_St_1_BlackDriftRight;
      flag = flag_St_1_BlackDriftRight;
      timer = timer_St_1_BlackDriftRight;
      rightturn_count = rightturn_count_St_1_BlackDriftRight;
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      rightturn_count_St_1_ObstacleAvoidance = self->rightturn_count_1;
      v_82 = (self->v_81-1);
      if (self->v_79) {
        v_80 = true;
      } else {
        v_80 = r;
      };
      if (v_80) {
        timer_St_1_ObstacleAvoidance = 100;
      } else {
        timer_St_1_ObstacleAvoidance = v_82;
      };
      flag_St_1_ObstacleAvoidance = true;
      v_r_St_1_ObstacleAvoidance = 0;
      v_l_St_1_ObstacleAvoidance = 0;
      dir_St_1_ObstacleAvoidance = 0;
      _out->v_l = v_l_St_1_ObstacleAvoidance;
      _out->v_r = v_r_St_1_ObstacleAvoidance;
      _out->dir = dir_St_1_ObstacleAvoidance;
      flag = flag_St_1_ObstacleAvoidance;
      timer = timer_St_1_ObstacleAvoidance;
      v_78 = (timer<=0);
      if (v_78) {
        nr_St_1_ObstacleAvoidance = true;
        ns_St_1_ObstacleAvoidance = Line_follower__St_1_RightTurn1;
      } else {
        nr_St_1_ObstacleAvoidance = false;
        ns_St_1_ObstacleAvoidance = Line_follower__St_1_ObstacleAvoidance;
      };
      rightturn_count = rightturn_count_St_1_ObstacleAvoidance;
      break;
    case Line_follower__St_1_RightTurn1:
      rightturn_count_St_1_RightTurn1 = self->rightturn_count_1;
      v_77 = (self->v_76-1);
      if (self->v_74) {
        v_75 = true;
      } else {
        v_75 = r;
      };
      if (v_75) {
        timer_St_1_RightTurn1 = 90;
      } else {
        timer_St_1_RightTurn1 = v_77;
      };
      flag_St_1_RightTurn1 = true;
      v_r_St_1_RightTurn1 = oasspeed;
      v_l_St_1_RightTurn1 = oasspeed;
      dir_St_1_RightTurn1 = 5;
      _out->v_l = v_l_St_1_RightTurn1;
      _out->v_r = v_r_St_1_RightTurn1;
      _out->dir = dir_St_1_RightTurn1;
      flag = flag_St_1_RightTurn1;
      timer = timer_St_1_RightTurn1;
      v_73 = (timer<=0);
      if (v_73) {
        nr_St_1_RightTurn1 = true;
        ns_St_1_RightTurn1 = Line_follower__St_1_Move1;
      } else {
        nr_St_1_RightTurn1 = false;
        ns_St_1_RightTurn1 = Line_follower__St_1_RightTurn1;
      };
      rightturn_count = rightturn_count_St_1_RightTurn1;
      break;
    case Line_follower__St_1_Move1:
      rightturn_count_St_1_Move1 = self->rightturn_count_1;
      v_72 = (self->v_71-1);
      if (self->v_69) {
        v_70 = true;
      } else {
        v_70 = r;
      };
      if (v_70) {
        timer_St_1_Move1 = 100;
      } else {
        timer_St_1_Move1 = v_72;
      };
      flag_St_1_Move1 = true;
      v_r_St_1_Move1 = oasspeed;
      v_l_St_1_Move1 = oasspeed;
      dir_St_1_Move1 = 1;
      _out->v_l = v_l_St_1_Move1;
      _out->v_r = v_r_St_1_Move1;
      _out->dir = dir_St_1_Move1;
      flag = flag_St_1_Move1;
      timer = timer_St_1_Move1;
      v_68 = (timer<=0);
      if (v_68) {
        nr_St_1_Move1 = true;
        ns_St_1_Move1 = Line_follower__St_1_Forward1;
      } else {
        nr_St_1_Move1 = false;
        ns_St_1_Move1 = Line_follower__St_1_Move1;
      };
      rightturn_count = rightturn_count_St_1_Move1;
      break;
    case Line_follower__St_1_Forward1:
      timer_St_1_Forward1 = self->timer_1;
      flag_St_1_Forward1 = true;
      v_r_St_1_Forward1 = oasspeed;
      v_l_St_1_Forward1 = oasspeed;
      dir_St_1_Forward1 = 1;
      v_67 = (self->v_66+1);
      if (self->v_64) {
        v_65 = true;
      } else {
        v_65 = r;
      };
      if (v_65) {
        rightturn_count_St_1_Forward1 = 0;
      } else {
        rightturn_count_St_1_Forward1 = v_67;
      };
      v_63 = (ir_d_left==1);
      if (v_63) {
        nr_St_1_Forward1 = true;
        ns_St_1_Forward1 = Line_follower__St_1_Move2;
      } else {
        nr_St_1_Forward1 = false;
        ns_St_1_Forward1 = Line_follower__St_1_Forward1;
      };
      _out->v_l = v_l_St_1_Forward1;
      _out->v_r = v_r_St_1_Forward1;
      _out->dir = dir_St_1_Forward1;
      flag = flag_St_1_Forward1;
      timer = timer_St_1_Forward1;
      rightturn_count = rightturn_count_St_1_Forward1;
      break;
    case Line_follower__St_1_Move2:
      rightturn_count_St_1_Move2 = self->rightturn_count_1;
      v_62 = (self->v_61-1);
      if (self->v_59) {
        v_60 = true;
      } else {
        v_60 = r;
      };
      if (v_60) {
        timer_St_1_Move2 = 75;
      } else {
        timer_St_1_Move2 = v_62;
      };
      flag_St_1_Move2 = true;
      v_r_St_1_Move2 = oasspeed;
      v_l_St_1_Move2 = oasspeed;
      dir_St_1_Move2 = 1;
      _out->v_l = v_l_St_1_Move2;
      _out->v_r = v_r_St_1_Move2;
      _out->dir = dir_St_1_Move2;
      flag = flag_St_1_Move2;
      timer = timer_St_1_Move2;
      v_58 = (timer<=0);
      if (v_58) {
        nr_St_1_Move2 = true;
        ns_St_1_Move2 = Line_follower__St_1_LeftTurn1;
      } else {
        nr_St_1_Move2 = false;
        ns_St_1_Move2 = Line_follower__St_1_Move2;
      };
      rightturn_count = rightturn_count_St_1_Move2;
      break;
    case Line_follower__St_1_LeftTurn1:
      rightturn_count_St_1_LeftTurn1 = self->rightturn_count_1;
      v_57 = (self->v_56-1);
      if (self->v_54) {
        v_55 = true;
      } else {
        v_55 = r;
      };
      if (v_55) {
        timer_St_1_LeftTurn1 = 37;
      } else {
        timer_St_1_LeftTurn1 = v_57;
      };
      flag_St_1_LeftTurn1 = true;
      v_r_St_1_LeftTurn1 = oasspeed;
      v_l_St_1_LeftTurn1 = oasspeed;
      dir_St_1_LeftTurn1 = 4;
      _out->v_l = v_l_St_1_LeftTurn1;
      _out->v_r = v_r_St_1_LeftTurn1;
      _out->dir = dir_St_1_LeftTurn1;
      flag = flag_St_1_LeftTurn1;
      timer = timer_St_1_LeftTurn1;
      v_53 = (timer<=0);
      if (v_53) {
        nr_St_1_LeftTurn1 = true;
        ns_St_1_LeftTurn1 = Line_follower__St_1_Move3;
      } else {
        nr_St_1_LeftTurn1 = false;
        ns_St_1_LeftTurn1 = Line_follower__St_1_LeftTurn1;
      };
      rightturn_count = rightturn_count_St_1_LeftTurn1;
      break;
    case Line_follower__St_1_Move3:
      rightturn_count_St_1_Move3 = self->rightturn_count_1;
      v_52 = (self->v_51-1);
      if (self->v_49) {
        v_50 = true;
      } else {
        v_50 = r;
      };
      if (v_50) {
        timer_St_1_Move3 = 200;
      } else {
        timer_St_1_Move3 = v_52;
      };
      flag_St_1_Move3 = true;
      v_r_St_1_Move3 = oasspeed;
      v_l_St_1_Move3 = oasspeed;
      dir_St_1_Move3 = 1;
      _out->v_l = v_l_St_1_Move3;
      _out->v_r = v_r_St_1_Move3;
      _out->dir = dir_St_1_Move3;
      flag = flag_St_1_Move3;
      timer = timer_St_1_Move3;
      v_48 = (timer<=0);
      if (v_48) {
        nr_St_1_Move3 = true;
        ns_St_1_Move3 = Line_follower__St_1_Forward2;
      } else {
        nr_St_1_Move3 = false;
        ns_St_1_Move3 = Line_follower__St_1_Move3;
      };
      rightturn_count = rightturn_count_St_1_Move3;
      break;
    case Line_follower__St_1_Forward2:
      rightturn_count_St_1_Forward2 = self->rightturn_count_1;
      timer_St_1_Forward2 = self->timer_1;
      flag_St_1_Forward2 = true;
      v_r_St_1_Forward2 = oasspeed;
      v_l_St_1_Forward2 = oasspeed;
      dir_St_1_Forward2 = 1;
      v_47 = (ir_d_left==1);
      if (v_47) {
        nr_St_1_Forward2 = true;
        ns_St_1_Forward2 = Line_follower__St_1_Move4;
      } else {
        nr_St_1_Forward2 = false;
        ns_St_1_Forward2 = Line_follower__St_1_Forward2;
      };
      _out->v_l = v_l_St_1_Forward2;
      _out->v_r = v_r_St_1_Forward2;
      _out->dir = dir_St_1_Forward2;
      flag = flag_St_1_Forward2;
      timer = timer_St_1_Forward2;
      rightturn_count = rightturn_count_St_1_Forward2;
      break;
    case Line_follower__St_1_Move4:
      rightturn_count_St_1_Move4 = self->rightturn_count_1;
      v_46 = (self->v_45-1);
      if (self->v_43) {
        v_44 = true;
      } else {
        v_44 = r;
      };
      if (v_44) {
        timer_St_1_Move4 = 75;
      } else {
        timer_St_1_Move4 = v_46;
      };
      flag_St_1_Move4 = true;
      v_r_St_1_Move4 = oasspeed;
      v_l_St_1_Move4 = oasspeed;
      dir_St_1_Move4 = 1;
      _out->v_l = v_l_St_1_Move4;
      _out->v_r = v_r_St_1_Move4;
      _out->dir = dir_St_1_Move4;
      flag = flag_St_1_Move4;
      timer = timer_St_1_Move4;
      v_42 = (timer<=0);
      if (v_42) {
        nr_St_1_Move4 = true;
        ns_St_1_Move4 = Line_follower__St_1_LeftTurn2;
      } else {
        nr_St_1_Move4 = false;
        ns_St_1_Move4 = Line_follower__St_1_Move4;
      };
      rightturn_count = rightturn_count_St_1_Move4;
      break;
    case Line_follower__St_1_LeftTurn2:
      rightturn_count_St_1_LeftTurn2 = self->rightturn_count_1;
      v_41 = (self->v_40-1);
      if (self->v_38) {
        v_39 = true;
      } else {
        v_39 = r;
      };
      if (v_39) {
        timer_St_1_LeftTurn2 = 35;
      } else {
        timer_St_1_LeftTurn2 = v_41;
      };
      flag_St_1_LeftTurn2 = true;
      v_r_St_1_LeftTurn2 = oasspeed;
      v_l_St_1_LeftTurn2 = oasspeed;
      dir_St_1_LeftTurn2 = 4;
      _out->v_l = v_l_St_1_LeftTurn2;
      _out->v_r = v_r_St_1_LeftTurn2;
      _out->dir = dir_St_1_LeftTurn2;
      flag = flag_St_1_LeftTurn2;
      timer = timer_St_1_LeftTurn2;
      v_37 = (timer<=0);
      if (v_37) {
        nr_St_1_LeftTurn2 = true;
        ns_St_1_LeftTurn2 = Line_follower__St_1_Move5;
      } else {
        nr_St_1_LeftTurn2 = false;
        ns_St_1_LeftTurn2 = Line_follower__St_1_LeftTurn2;
      };
      rightturn_count = rightturn_count_St_1_LeftTurn2;
      break;
    case Line_follower__St_1_Move5:
      rightturn_count_St_1_Move5 = self->rightturn_count_1;
      timer_St_1_Move5 = self->timer_1;
      flag_St_1_Move5 = true;
      v_r_St_1_Move5 = oasspeed;
      v_l_St_1_Move5 = oasspeed;
      dir_St_1_Move5 = 1;
      if (blacknodedetected) {
        nr_St_1_Move5 = true;
        ns_St_1_Move5 = Line_follower__St_1_RightTurn3;
      } else {
        nr_St_1_Move5 = false;
        ns_St_1_Move5 = Line_follower__St_1_Move5;
      };
      _out->v_l = v_l_St_1_Move5;
      _out->v_r = v_r_St_1_Move5;
      _out->dir = dir_St_1_Move5;
      flag = flag_St_1_Move5;
      timer = timer_St_1_Move5;
      rightturn_count = rightturn_count_St_1_Move5;
      break;
    case Line_follower__St_1_RightTurn3:
      rightturn_count_St_1_RightTurn3 = self->rightturn_count_1;
      v_36 = (self->v_35-1);
      if (self->v_33) {
        v_34 = true;
      } else {
        v_34 = r;
      };
      if (v_34) {
        timer_St_1_RightTurn3 = 80;
      } else {
        timer_St_1_RightTurn3 = v_36;
      };
      flag_St_1_RightTurn3 = true;
      v_r_St_1_RightTurn3 = oasspeed;
      v_l_St_1_RightTurn3 = oasspeed;
      dir_St_1_RightTurn3 = 5;
      _out->v_l = v_l_St_1_RightTurn3;
      _out->v_r = v_r_St_1_RightTurn3;
      _out->dir = dir_St_1_RightTurn3;
      flag = flag_St_1_RightTurn3;
      timer = timer_St_1_RightTurn3;
      v_32 = (timer<=0);
      if (v_32) {
        nr_St_1_RightTurn3 = true;
        ns_St_1_RightTurn3 = Line_follower__St_1_BlackRight;
      } else {
        nr_St_1_RightTurn3 = false;
        ns_St_1_RightTurn3 = Line_follower__St_1_RightTurn3;
      };
      rightturn_count = rightturn_count_St_1_RightTurn3;
      break;
    default:
      break;
  };
  Line_follower__counter_step(sen0, sen1, sen2, sen3, sen4, beacon, flag,
                              &Line_follower__counter_out_st, &self->counter);
  count = Line_follower__counter_out_st.count;
  _out->cnt = count;
  switch (self->ck) {
    case Line_follower__St_1_BlackForward:
      v_110 = (count>6);
      v_111 = (blacknodedetected&&v_110);
      if (v_111) {
        v_119 = true;
        v_118 = Line_follower__St_1_BlackStop;
      } else {
        v_119 = v_117;
        v_118 = v_116;
      };
      v_107 = (count<=6);
      v_106 = (count>3);
      v_108 = (v_106&&v_107);
      v_109 = (blacknodedetected&&v_108);
      if (v_109) {
        v_121 = true;
        v_120 = Line_follower__St_1_BlackLeft;
      } else {
        v_121 = v_119;
        v_120 = v_118;
      };
      v_104 = (count<=3);
      v_105 = (blacknodedetected&&v_104);
      if (v_105) {
        v_123 = true;
      } else {
        v_123 = v_121;
      };
      if (v_103) {
        nr_St_1_BlackForward = true;
      } else {
        nr_St_1_BlackForward = v_123;
      };
      if (v_105) {
        v_122 = Line_follower__St_1_BlackRight;
      } else {
        v_122 = v_120;
      };
      if (v_103) {
        ns_St_1_BlackForward = Line_follower__St_1_ObstacleAvoidance;
      } else {
        ns_St_1_BlackForward = v_122;
      };
      ns = ns_St_1_BlackForward;
      nr = nr_St_1_BlackForward;
      break;
    case Line_follower__St_1_RightTurn3:
      ns = ns_St_1_RightTurn3;
      nr = nr_St_1_RightTurn3;
      self->v_35 = timer;
      self->v_33 = false;
      break;
    case Line_follower__St_1_Move5:
      ns = ns_St_1_Move5;
      nr = nr_St_1_Move5;
      break;
    case Line_follower__St_1_LeftTurn2:
      ns = ns_St_1_LeftTurn2;
      nr = nr_St_1_LeftTurn2;
      self->v_40 = timer;
      self->v_38 = false;
      break;
    case Line_follower__St_1_Move4:
      ns = ns_St_1_Move4;
      nr = nr_St_1_Move4;
      self->v_45 = timer;
      self->v_43 = false;
      break;
    case Line_follower__St_1_Forward2:
      ns = ns_St_1_Forward2;
      nr = nr_St_1_Forward2;
      break;
    case Line_follower__St_1_Move3:
      ns = ns_St_1_Move3;
      nr = nr_St_1_Move3;
      self->v_51 = timer;
      self->v_49 = false;
      break;
    case Line_follower__St_1_LeftTurn1:
      ns = ns_St_1_LeftTurn1;
      nr = nr_St_1_LeftTurn1;
      self->v_56 = timer;
      self->v_54 = false;
      break;
    case Line_follower__St_1_Move2:
      ns = ns_St_1_Move2;
      nr = nr_St_1_Move2;
      self->v_61 = timer;
      self->v_59 = false;
      break;
    case Line_follower__St_1_Forward1:
      ns = ns_St_1_Forward1;
      nr = nr_St_1_Forward1;
      self->v_66 = rightturn_count;
      self->v_64 = false;
      break;
    case Line_follower__St_1_Move1:
      ns = ns_St_1_Move1;
      nr = nr_St_1_Move1;
      self->v_71 = timer;
      self->v_69 = false;
      break;
    case Line_follower__St_1_RightTurn1:
      ns = ns_St_1_RightTurn1;
      nr = nr_St_1_RightTurn1;
      self->v_76 = timer;
      self->v_74 = false;
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      ns = ns_St_1_ObstacleAvoidance;
      nr = nr_St_1_ObstacleAvoidance;
      self->v_81 = timer;
      self->v_79 = false;
      break;
    case Line_follower__St_1_BlackDriftRight:
      ns = ns_St_1_BlackDriftRight;
      nr = nr_St_1_BlackDriftRight;
      break;
    case Line_follower__St_1_BlackDriftLeft:
      ns = ns_St_1_BlackDriftLeft;
      nr = nr_St_1_BlackDriftLeft;
      break;
    case Line_follower__St_1_BlackRight:
      ns = ns_St_1_BlackRight;
      nr = nr_St_1_BlackRight;
      break;
    case Line_follower__St_1_BlackLeft:
      ns = ns_St_1_BlackLeft;
      nr = nr_St_1_BlackLeft;
      break;
    case Line_follower__St_1_BlackStop:
      ns = ns_St_1_BlackStop;
      nr = nr_St_1_BlackStop;
      break;
    case Line_follower__St_1_DriftRight:
      ns = ns_St_1_DriftRight;
      nr = nr_St_1_DriftRight;
      break;
    case Line_follower__St_1_DriftLeft:
      ns = ns_St_1_DriftLeft;
      nr = nr_St_1_DriftLeft;
      break;
    case Line_follower__St_1_Right:
      ns = ns_St_1_Right;
      nr = nr_St_1_Right;
      break;
    case Line_follower__St_1_Left:
      ns = ns_St_1_Left;
      nr = nr_St_1_Left;
      break;
    case Line_follower__St_1_Stop:
      ns = ns_St_1_Stop;
      nr = nr_St_1_Stop;
      break;
    case Line_follower__St_1_Forward:
      ns = ns_St_1_Forward;
      nr = nr_St_1_Forward;
      break;
    default:
      break;
  };
  self->rightturn_count_1 = rightturn_count;
  self->timer_1 = timer;
  self->cnt_3 = _out->cnt;
  self->pnr = nr;
  self->ck = ns;;
}

