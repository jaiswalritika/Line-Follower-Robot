/* --- Generated the 29/3/2025 at 13:33 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower_without_obstacle.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_without_obstacle.h"

void Line_follower_without_obstacle__findpid_reset(Line_follower_without_obstacle__findpid_mem* self) {
  self->v = true;
}

void Line_follower_without_obstacle__findpid_step(long sen3, long sen1,
                                                  Line_follower_without_obstacle__findpid_out* _out,
                                                  Line_follower_without_obstacle__findpid_mem* self) {
  
  long v_4;
  long v_3;
  long v_2;
  long v_1;
  long z;
  long p;
  long d;
  long error;
  if (self->v) {
    v_1 = 0;
  } else {
    v_1 = self->error_1;
  };
  error = (sen3-sen1);
  d = (error-v_1);
  v_3 = (Line_follower_without_obstacle__kd*d);
  p = error;
  v_2 = (Line_follower_without_obstacle__kp*p);
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

void Line_follower_without_obstacle__main_reset(Line_follower_without_obstacle__main_mem* self) {
  Line_follower_without_obstacle__findpid_reset(&self->findpid);
  self->v_139 = true;
  self->v_69 = true;
  self->v_45 = true;
  self->v_35 = true;
  self->pnr = false;
  self->ck = Line_follower_without_obstacle__St_Forward;
}

void Line_follower_without_obstacle__main_step(long sen0, long sen1, long sen2,
                                               long sen3, long sen4,
                                               Line_follower_without_obstacle__main_out* _out,
                                               Line_follower_without_obstacle__main_mem* self) {
  Line_follower_without_obstacle__findpid_out Line_follower_without_obstacle__findpid_out_st;
  
  long v_36;
  long v_34;
  Line_follower_without_obstacle__st v_33;
  long v_32;
  Line_follower_without_obstacle__st v_31;
  long v_30;
  Line_follower_without_obstacle__st v_29;
  long v_28;
  Line_follower_without_obstacle__st v_27;
  long v_46;
  long v_44;
  Line_follower_without_obstacle__st v_43;
  long v_42;
  Line_follower_without_obstacle__st v_41;
  long v_40;
  Line_follower_without_obstacle__st v_39;
  long v_38;
  Line_follower_without_obstacle__st v_37;
  long v_48;
  Line_follower_without_obstacle__st v_47;
  long v_56;
  Line_follower_without_obstacle__st v_55;
  long v_54;
  Line_follower_without_obstacle__st v_53;
  long v_52;
  Line_follower_without_obstacle__st v_51;
  long v_50;
  Line_follower_without_obstacle__st v_49;
  long v_70;
  long v_68;
  Line_follower_without_obstacle__st v_67;
  long v_66;
  Line_follower_without_obstacle__st v_65;
  long v_64;
  Line_follower_without_obstacle__st v_63;
  long v_62;
  Line_follower_without_obstacle__st v_61;
  long v_60;
  long v_59;
  long v_58;
  long v_57;
  long v_82;
  Line_follower_without_obstacle__st v_81;
  long v_80;
  Line_follower_without_obstacle__st v_79;
  long v_78;
  Line_follower_without_obstacle__st v_77;
  long v_76;
  Line_follower_without_obstacle__st v_75;
  long v_74;
  Line_follower_without_obstacle__st v_73;
  long v_72;
  Line_follower_without_obstacle__st v_71;
  long v_94;
  Line_follower_without_obstacle__st v_93;
  long v_92;
  Line_follower_without_obstacle__st v_91;
  long v_90;
  Line_follower_without_obstacle__st v_89;
  long v_88;
  Line_follower_without_obstacle__st v_87;
  long v_86;
  Line_follower_without_obstacle__st v_85;
  long v_84;
  Line_follower_without_obstacle__st v_83;
  long v_106;
  Line_follower_without_obstacle__st v_105;
  long v_104;
  Line_follower_without_obstacle__st v_103;
  long v_102;
  Line_follower_without_obstacle__st v_101;
  long v_100;
  Line_follower_without_obstacle__st v_99;
  long v_98;
  Line_follower_without_obstacle__st v_97;
  long v_96;
  Line_follower_without_obstacle__st v_95;
  long v_116;
  Line_follower_without_obstacle__st v_115;
  long v_114;
  Line_follower_without_obstacle__st v_113;
  long v_112;
  Line_follower_without_obstacle__st v_111;
  long v_110;
  Line_follower_without_obstacle__st v_109;
  long v_108;
  Line_follower_without_obstacle__st v_107;
  long v_128;
  Line_follower_without_obstacle__st v_127;
  long v_126;
  Line_follower_without_obstacle__st v_125;
  long v_124;
  Line_follower_without_obstacle__st v_123;
  long v_122;
  Line_follower_without_obstacle__st v_121;
  long v_120;
  Line_follower_without_obstacle__st v_119;
  long v_118;
  long v_117;
  long v_140;
  long v_138;
  Line_follower_without_obstacle__st v_137;
  long v_136;
  Line_follower_without_obstacle__st v_135;
  long v_134;
  Line_follower_without_obstacle__st v_133;
  long v_132;
  Line_follower_without_obstacle__st v_131;
  long v_130;
  Line_follower_without_obstacle__st v_129;
  long nr_St_BlackDriftRight;
  Line_follower_without_obstacle__st ns_St_BlackDriftRight;
  long cnt_St_BlackDriftRight;
  long dir_St_BlackDriftRight;
  long v_r_St_BlackDriftRight;
  long v_l_St_BlackDriftRight;
  long nr_St_BlackDriftLeft;
  Line_follower_without_obstacle__st ns_St_BlackDriftLeft;
  long cnt_St_BlackDriftLeft;
  long dir_St_BlackDriftLeft;
  long v_r_St_BlackDriftLeft;
  long v_l_St_BlackDriftLeft;
  long nr_St_BlackRight;
  Line_follower_without_obstacle__st ns_St_BlackRight;
  long cnt_St_BlackRight;
  long dir_St_BlackRight;
  long v_r_St_BlackRight;
  long v_l_St_BlackRight;
  long nr_St_BlackLeft;
  Line_follower_without_obstacle__st ns_St_BlackLeft;
  long cnt_St_BlackLeft;
  long dir_St_BlackLeft;
  long v_r_St_BlackLeft;
  long v_l_St_BlackLeft;
  long nr_St_BlackForward;
  Line_follower_without_obstacle__st ns_St_BlackForward;
  long cnt_St_BlackForward;
  long dir_St_BlackForward;
  long v_r_St_BlackForward;
  long v_l_St_BlackForward;
  long nr_St_DriftRight;
  Line_follower_without_obstacle__st ns_St_DriftRight;
  long cnt_St_DriftRight;
  long dir_St_DriftRight;
  long v_r_St_DriftRight;
  long v_l_St_DriftRight;
  long nr_St_DriftLeft;
  Line_follower_without_obstacle__st ns_St_DriftLeft;
  long cnt_St_DriftLeft;
  long dir_St_DriftLeft;
  long v_r_St_DriftLeft;
  long v_l_St_DriftLeft;
  long nr_St_Right;
  Line_follower_without_obstacle__st ns_St_Right;
  long cnt_St_Right;
  long dir_St_Right;
  long v_r_St_Right;
  long v_l_St_Right;
  long nr_St_Left;
  Line_follower_without_obstacle__st ns_St_Left;
  long cnt_St_Left;
  long dir_St_Left;
  long v_r_St_Left;
  long v_l_St_Left;
  long nr_St_Stop;
  Line_follower_without_obstacle__st ns_St_Stop;
  long cnt_St_Stop;
  long dir_St_Stop;
  long v_r_St_Stop;
  long v_l_St_Stop;
  long nr_St_Forward;
  Line_follower_without_obstacle__st ns_St_Forward;
  long cnt_St_Forward;
  long dir_St_Forward;
  long v_r_St_Forward;
  long v_l_St_Forward;
  long v_26;
  long v_25;
  long v_24;
  long v_23;
  long v_22;
  long v_21;
  long v_20;
  long v_19;
  long v_18;
  long v_17;
  long v_16;
  long v_15;
  long v_14;
  long v_13;
  long v_12;
  long v_11;
  long v_10;
  long v_9;
  long v_8;
  long v_7;
  long v_6;
  long v_5;
  long v;
  Line_follower_without_obstacle__st ns;
  long r;
  long nr;
  long pid;
  long wspeed;
  long bspeed;
  long c1;
  long c2;
  long c3;
  long c4;
  long c5;
  long b2;
  long b3;
  long b4;
  long b5;
  long switch_condition;
  r = self->pnr;
  v_26 = (sen2>700);
  v_25 = (sen3<700);
  b5 = (v_25&&v_26);
  v_24 = (sen2>700);
  v_23 = (sen1<700);
  b4 = (v_23&&v_24);
  b3 = (sen4<700);
  v_19 = (sen0+sen1);
  v_20 = (v_19+sen2);
  v_21 = (v_20+sen3);
  v_22 = (v_21+sen4);
  b2 = (v_22<3000);
  bspeed = 40;
  wspeed = 40;
  v_17 = (sen0+sen1);
  v_18 = (v_17>1400);
  v_15 = (sen4>800);
  v_14 = (sen2<700);
  v_16 = (v_14&&v_15);
  switch_condition = (v_16&&v_18);
  v_13 = (sen2<800);
  v_12 = (sen3>900);
  c5 = (v_12&&v_13);
  v_11 = (sen2<800);
  v_10 = (sen1>900);
  c4 = (v_10&&v_11);
  c3 = (sen4>900);
  v_8 = (sen0*18);
  v_9 = (v_8/10);
  c2 = (v_9>900);
  v = (sen0+sen1);
  v_5 = (v+sen2);
  v_6 = (v_5+sen3);
  v_7 = (v_6+sen4);
  c1 = (v_7>4500);
  Line_follower_without_obstacle__findpid_step(sen3, sen1,
                                               &Line_follower_without_obstacle__findpid_out_st,
                                               &self->findpid);
  pid = Line_follower_without_obstacle__findpid_out_st.pid;
  switch (self->ck) {
    case Line_follower_without_obstacle__St_Forward:
      if (self->v_139) {
        v_140 = true;
      } else {
        v_140 = r;
      };
      if (v_140) {
        cnt_St_Forward = 0;
      } else {
        cnt_St_Forward = self->cnt_1;
      };
      dir_St_Forward = 1;
      v_r_St_Forward = wspeed;
      v_l_St_Forward = wspeed;
      if (c5) {
        v_130 = true;
      } else {
        v_130 = false;
      };
      if (c4) {
        v_132 = true;
      } else {
        v_132 = v_130;
      };
      if (c3) {
        v_134 = true;
      } else {
        v_134 = v_132;
      };
      if (c2) {
        v_136 = true;
      } else {
        v_136 = v_134;
      };
      if (switch_condition) {
        v_138 = true;
      } else {
        v_138 = v_136;
      };
      if (c1) {
        nr_St_Forward = true;
      } else {
        nr_St_Forward = v_138;
      };
      if (c5) {
        v_129 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_129 = Line_follower_without_obstacle__St_Forward;
      };
      if (c4) {
        v_131 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_131 = v_129;
      };
      if (c3) {
        v_133 = Line_follower_without_obstacle__St_Right;
      } else {
        v_133 = v_131;
      };
      if (c2) {
        v_135 = Line_follower_without_obstacle__St_Left;
      } else {
        v_135 = v_133;
      };
      if (switch_condition) {
        v_137 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_137 = v_135;
      };
      if (c1) {
        ns_St_Forward = Line_follower_without_obstacle__St_Stop;
      } else {
        ns_St_Forward = v_137;
      };
      _out->v_l = v_l_St_Forward;
      _out->v_r = v_r_St_Forward;
      _out->dir = dir_St_Forward;
      _out->cnt = cnt_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      self->v_139 = false;
      break;
    case Line_follower_without_obstacle__St_Stop:
      cnt_St_Stop = self->cnt_1;
      dir_St_Stop = 0;
      v_r_St_Stop = 0;
      v_l_St_Stop = 0;
      if (true) {
        v_120 = true;
      } else {
        v_120 = false;
      };
      if (c5) {
        v_122 = true;
      } else {
        v_122 = v_120;
      };
      if (c4) {
        v_124 = true;
      } else {
        v_124 = v_122;
      };
      if (c3) {
        v_126 = true;
      } else {
        v_126 = v_124;
      };
      if (true) {
        v_119 = Line_follower_without_obstacle__St_Forward;
      } else {
        v_119 = Line_follower_without_obstacle__St_Stop;
      };
      if (c5) {
        v_121 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_121 = v_119;
      };
      if (c4) {
        v_123 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_123 = v_121;
      };
      if (c3) {
        v_125 = Line_follower_without_obstacle__St_Right;
      } else {
        v_125 = v_123;
      };
      v_117 = !(c1);
      v_118 = (v_117&&c2);
      if (v_118) {
        v_128 = true;
      } else {
        v_128 = v_126;
      };
      if (switch_condition) {
        nr_St_Stop = true;
      } else {
        nr_St_Stop = v_128;
      };
      if (v_118) {
        v_127 = Line_follower_without_obstacle__St_Left;
      } else {
        v_127 = v_125;
      };
      if (switch_condition) {
        ns_St_Stop = Line_follower_without_obstacle__St_BlackForward;
      } else {
        ns_St_Stop = v_127;
      };
      _out->v_l = v_l_St_Stop;
      _out->v_r = v_r_St_Stop;
      _out->dir = dir_St_Stop;
      _out->cnt = cnt_St_Stop;
      ns = ns_St_Stop;
      nr = nr_St_Stop;
      break;
    case Line_follower_without_obstacle__St_Left:
      cnt_St_Left = self->cnt_1;
      dir_St_Left = 4;
      v_r_St_Left = wspeed;
      v_l_St_Left = wspeed;
      if (true) {
        v_108 = true;
      } else {
        v_108 = false;
      };
      if (c5) {
        v_110 = true;
      } else {
        v_110 = v_108;
      };
      if (c4) {
        v_112 = true;
      } else {
        v_112 = v_110;
      };
      if (c3) {
        v_114 = true;
      } else {
        v_114 = v_112;
      };
      if (switch_condition) {
        v_116 = true;
      } else {
        v_116 = v_114;
      };
      if (c1) {
        nr_St_Left = true;
      } else {
        nr_St_Left = v_116;
      };
      if (true) {
        v_107 = Line_follower_without_obstacle__St_Forward;
      } else {
        v_107 = Line_follower_without_obstacle__St_Left;
      };
      if (c5) {
        v_109 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_109 = v_107;
      };
      if (c4) {
        v_111 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_111 = v_109;
      };
      if (c3) {
        v_113 = Line_follower_without_obstacle__St_Right;
      } else {
        v_113 = v_111;
      };
      if (switch_condition) {
        v_115 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_115 = v_113;
      };
      if (c1) {
        ns_St_Left = Line_follower_without_obstacle__St_Stop;
      } else {
        ns_St_Left = v_115;
      };
      _out->v_l = v_l_St_Left;
      _out->v_r = v_r_St_Left;
      _out->dir = dir_St_Left;
      _out->cnt = cnt_St_Left;
      ns = ns_St_Left;
      nr = nr_St_Left;
      break;
    case Line_follower_without_obstacle__St_Right:
      cnt_St_Right = self->cnt_1;
      dir_St_Right = 5;
      v_r_St_Right = wspeed;
      v_l_St_Right = wspeed;
      if (true) {
        v_96 = true;
      } else {
        v_96 = false;
      };
      if (c5) {
        v_98 = true;
      } else {
        v_98 = v_96;
      };
      if (c4) {
        v_100 = true;
      } else {
        v_100 = v_98;
      };
      if (c3) {
        v_102 = true;
      } else {
        v_102 = v_100;
      };
      if (c2) {
        v_104 = true;
      } else {
        v_104 = v_102;
      };
      if (switch_condition) {
        v_106 = true;
      } else {
        v_106 = v_104;
      };
      if (c1) {
        nr_St_Right = true;
      } else {
        nr_St_Right = v_106;
      };
      if (true) {
        v_95 = Line_follower_without_obstacle__St_Forward;
      } else {
        v_95 = Line_follower_without_obstacle__St_Right;
      };
      if (c5) {
        v_97 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_97 = v_95;
      };
      if (c4) {
        v_99 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_99 = v_97;
      };
      if (c3) {
        v_101 = Line_follower_without_obstacle__St_Right;
      } else {
        v_101 = v_99;
      };
      if (c2) {
        v_103 = Line_follower_without_obstacle__St_Left;
      } else {
        v_103 = v_101;
      };
      if (switch_condition) {
        v_105 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_105 = v_103;
      };
      if (c1) {
        ns_St_Right = Line_follower_without_obstacle__St_Stop;
      } else {
        ns_St_Right = v_105;
      };
      _out->v_l = v_l_St_Right;
      _out->v_r = v_r_St_Right;
      _out->dir = dir_St_Right;
      _out->cnt = cnt_St_Right;
      ns = ns_St_Right;
      nr = nr_St_Right;
      break;
    case Line_follower_without_obstacle__St_DriftLeft:
      cnt_St_DriftLeft = self->cnt_1;
      dir_St_DriftLeft = 3;
      v_r_St_DriftLeft = (wspeed+pid);
      v_l_St_DriftLeft = 0;
      if (true) {
        v_84 = true;
      } else {
        v_84 = false;
      };
      if (c5) {
        v_86 = true;
      } else {
        v_86 = v_84;
      };
      if (c4) {
        v_88 = true;
      } else {
        v_88 = v_86;
      };
      if (c3) {
        v_90 = true;
      } else {
        v_90 = v_88;
      };
      if (c2) {
        v_92 = true;
      } else {
        v_92 = v_90;
      };
      if (switch_condition) {
        v_94 = true;
      } else {
        v_94 = v_92;
      };
      if (c1) {
        nr_St_DriftLeft = true;
      } else {
        nr_St_DriftLeft = v_94;
      };
      if (true) {
        v_83 = Line_follower_without_obstacle__St_Forward;
      } else {
        v_83 = Line_follower_without_obstacle__St_DriftLeft;
      };
      if (c5) {
        v_85 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_85 = v_83;
      };
      if (c4) {
        v_87 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_87 = v_85;
      };
      if (c3) {
        v_89 = Line_follower_without_obstacle__St_Right;
      } else {
        v_89 = v_87;
      };
      if (c2) {
        v_91 = Line_follower_without_obstacle__St_Left;
      } else {
        v_91 = v_89;
      };
      if (switch_condition) {
        v_93 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_93 = v_91;
      };
      if (c1) {
        ns_St_DriftLeft = Line_follower_without_obstacle__St_Stop;
      } else {
        ns_St_DriftLeft = v_93;
      };
      _out->v_l = v_l_St_DriftLeft;
      _out->v_r = v_r_St_DriftLeft;
      _out->dir = dir_St_DriftLeft;
      _out->cnt = cnt_St_DriftLeft;
      ns = ns_St_DriftLeft;
      nr = nr_St_DriftLeft;
      break;
    case Line_follower_without_obstacle__St_DriftRight:
      cnt_St_DriftRight = self->cnt_1;
      dir_St_DriftRight = 2;
      v_r_St_DriftRight = 0;
      v_l_St_DriftRight = (wspeed+pid);
      if (true) {
        v_72 = true;
      } else {
        v_72 = false;
      };
      if (c5) {
        v_74 = true;
      } else {
        v_74 = v_72;
      };
      if (c4) {
        v_76 = true;
      } else {
        v_76 = v_74;
      };
      if (c3) {
        v_78 = true;
      } else {
        v_78 = v_76;
      };
      if (c2) {
        v_80 = true;
      } else {
        v_80 = v_78;
      };
      if (switch_condition) {
        v_82 = true;
      } else {
        v_82 = v_80;
      };
      if (c1) {
        nr_St_DriftRight = true;
      } else {
        nr_St_DriftRight = v_82;
      };
      if (true) {
        v_71 = Line_follower_without_obstacle__St_Forward;
      } else {
        v_71 = Line_follower_without_obstacle__St_DriftRight;
      };
      if (c5) {
        v_73 = Line_follower_without_obstacle__St_DriftLeft;
      } else {
        v_73 = v_71;
      };
      if (c4) {
        v_75 = Line_follower_without_obstacle__St_DriftRight;
      } else {
        v_75 = v_73;
      };
      if (c3) {
        v_77 = Line_follower_without_obstacle__St_Right;
      } else {
        v_77 = v_75;
      };
      if (c2) {
        v_79 = Line_follower_without_obstacle__St_Left;
      } else {
        v_79 = v_77;
      };
      if (switch_condition) {
        v_81 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_81 = v_79;
      };
      if (c1) {
        ns_St_DriftRight = Line_follower_without_obstacle__St_Stop;
      } else {
        ns_St_DriftRight = v_81;
      };
      _out->v_l = v_l_St_DriftRight;
      _out->v_r = v_r_St_DriftRight;
      _out->dir = dir_St_DriftRight;
      _out->cnt = cnt_St_DriftRight;
      ns = ns_St_DriftRight;
      nr = nr_St_DriftRight;
      break;
    case Line_follower_without_obstacle__St_BlackForward:
      if (self->v_69) {
        v_70 = true;
      } else {
        v_70 = r;
      };
      if (v_70) {
        cnt_St_BlackForward = 0;
      } else {
        cnt_St_BlackForward = self->cnt_1;
      };
      dir_St_BlackForward = 1;
      v_r_St_BlackForward = bspeed;
      v_l_St_BlackForward = bspeed;
      if (true) {
        v_62 = true;
      } else {
        v_62 = false;
      };
      if (b5) {
        v_64 = true;
      } else {
        v_64 = v_62;
      };
      if (b4) {
        v_66 = true;
      } else {
        v_66 = v_64;
      };
      if (true) {
        v_61 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_61 = Line_follower_without_obstacle__St_BlackForward;
      };
      if (b5) {
        v_63 = Line_follower_without_obstacle__St_BlackDriftLeft;
      } else {
        v_63 = v_61;
      };
      if (b4) {
        v_65 = Line_follower_without_obstacle__St_BlackDriftRight;
      } else {
        v_65 = v_63;
      };
      _out->v_l = v_l_St_BlackForward;
      _out->v_r = v_r_St_BlackForward;
      _out->dir = dir_St_BlackForward;
      _out->cnt = cnt_St_BlackForward;
      v_59 = (_out->cnt>=2);
      v_60 = (b2&&v_59);
      if (v_60) {
        v_68 = true;
        v_67 = Line_follower_without_obstacle__St_BlackLeft;
      } else {
        v_68 = v_66;
        v_67 = v_65;
      };
      v_57 = (_out->cnt<2);
      v_58 = (b2&&v_57);
      if (v_58) {
        nr_St_BlackForward = true;
        ns_St_BlackForward = Line_follower_without_obstacle__St_BlackRight;
      } else {
        nr_St_BlackForward = v_68;
        ns_St_BlackForward = v_67;
      };
      ns = ns_St_BlackForward;
      nr = nr_St_BlackForward;
      self->v_69 = false;
      break;
    case Line_follower_without_obstacle__St_BlackLeft:
      cnt_St_BlackLeft = (self->cnt_1+1);
      dir_St_BlackLeft = 4;
      v_r_St_BlackLeft = bspeed;
      v_l_St_BlackLeft = bspeed;
      if (true) {
        v_50 = true;
      } else {
        v_50 = false;
      };
      if (b5) {
        v_52 = true;
      } else {
        v_52 = v_50;
      };
      if (b4) {
        v_54 = true;
      } else {
        v_54 = v_52;
      };
      if (switch_condition) {
        v_56 = true;
      } else {
        v_56 = v_54;
      };
      if (b2) {
        nr_St_BlackLeft = true;
      } else {
        nr_St_BlackLeft = v_56;
      };
      if (true) {
        v_49 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_49 = Line_follower_without_obstacle__St_BlackLeft;
      };
      if (b5) {
        v_51 = Line_follower_without_obstacle__St_BlackDriftLeft;
      } else {
        v_51 = v_49;
      };
      if (b4) {
        v_53 = Line_follower_without_obstacle__St_BlackDriftRight;
      } else {
        v_53 = v_51;
      };
      if (switch_condition) {
        v_55 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_55 = v_53;
      };
      if (b2) {
        ns_St_BlackLeft = Line_follower_without_obstacle__St_BlackRight;
      } else {
        ns_St_BlackLeft = v_55;
      };
      _out->v_l = v_l_St_BlackLeft;
      _out->v_r = v_r_St_BlackLeft;
      _out->dir = dir_St_BlackLeft;
      _out->cnt = cnt_St_BlackLeft;
      ns = ns_St_BlackLeft;
      nr = nr_St_BlackLeft;
      break;
    case Line_follower_without_obstacle__St_BlackRight:
      cnt_St_BlackRight = (self->cnt_1+1);
      dir_St_BlackRight = 5;
      v_r_St_BlackRight = bspeed;
      v_l_St_BlackRight = bspeed;
      if (true) {
        v_48 = true;
      } else {
        v_48 = false;
      };
      if (b2) {
        nr_St_BlackRight = true;
      } else {
        nr_St_BlackRight = v_48;
      };
      if (true) {
        v_47 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_47 = Line_follower_without_obstacle__St_BlackRight;
      };
      if (b2) {
        ns_St_BlackRight = Line_follower_without_obstacle__St_BlackRight;
      } else {
        ns_St_BlackRight = v_47;
      };
      _out->v_l = v_l_St_BlackRight;
      _out->v_r = v_r_St_BlackRight;
      _out->dir = dir_St_BlackRight;
      _out->cnt = cnt_St_BlackRight;
      ns = ns_St_BlackRight;
      nr = nr_St_BlackRight;
      break;
    case Line_follower_without_obstacle__St_BlackDriftLeft:
      if (self->v_45) {
        v_46 = true;
      } else {
        v_46 = r;
      };
      if (v_46) {
        cnt_St_BlackDriftLeft = 0;
      } else {
        cnt_St_BlackDriftLeft = self->cnt_1;
      };
      dir_St_BlackDriftLeft = 3;
      v_r_St_BlackDriftLeft = (bspeed+pid);
      v_l_St_BlackDriftLeft = 0;
      if (true) {
        v_38 = true;
      } else {
        v_38 = false;
      };
      if (b5) {
        v_40 = true;
      } else {
        v_40 = v_38;
      };
      if (b4) {
        v_42 = true;
      } else {
        v_42 = v_40;
      };
      if (switch_condition) {
        v_44 = true;
      } else {
        v_44 = v_42;
      };
      if (b2) {
        nr_St_BlackDriftLeft = true;
      } else {
        nr_St_BlackDriftLeft = v_44;
      };
      if (true) {
        v_37 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_37 = Line_follower_without_obstacle__St_BlackDriftLeft;
      };
      if (b5) {
        v_39 = Line_follower_without_obstacle__St_BlackDriftLeft;
      } else {
        v_39 = v_37;
      };
      if (b4) {
        v_41 = Line_follower_without_obstacle__St_BlackDriftRight;
      } else {
        v_41 = v_39;
      };
      if (switch_condition) {
        v_43 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_43 = v_41;
      };
      if (b2) {
        ns_St_BlackDriftLeft = Line_follower_without_obstacle__St_BlackRight;
      } else {
        ns_St_BlackDriftLeft = v_43;
      };
      _out->v_l = v_l_St_BlackDriftLeft;
      _out->v_r = v_r_St_BlackDriftLeft;
      _out->dir = dir_St_BlackDriftLeft;
      _out->cnt = cnt_St_BlackDriftLeft;
      ns = ns_St_BlackDriftLeft;
      nr = nr_St_BlackDriftLeft;
      self->v_45 = false;
      break;
    case Line_follower_without_obstacle__St_BlackDriftRight:
      if (self->v_35) {
        v_36 = true;
      } else {
        v_36 = r;
      };
      if (v_36) {
        cnt_St_BlackDriftRight = 0;
      } else {
        cnt_St_BlackDriftRight = self->cnt_1;
      };
      dir_St_BlackDriftRight = 2;
      v_r_St_BlackDriftRight = 0;
      v_l_St_BlackDriftRight = (bspeed+pid);
      if (true) {
        v_28 = true;
      } else {
        v_28 = false;
      };
      if (b5) {
        v_30 = true;
      } else {
        v_30 = v_28;
      };
      if (b4) {
        v_32 = true;
      } else {
        v_32 = v_30;
      };
      if (switch_condition) {
        v_34 = true;
      } else {
        v_34 = v_32;
      };
      if (b2) {
        nr_St_BlackDriftRight = true;
      } else {
        nr_St_BlackDriftRight = v_34;
      };
      if (true) {
        v_27 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_27 = Line_follower_without_obstacle__St_BlackDriftRight;
      };
      if (b5) {
        v_29 = Line_follower_without_obstacle__St_BlackDriftLeft;
      } else {
        v_29 = v_27;
      };
      if (b4) {
        v_31 = Line_follower_without_obstacle__St_BlackDriftRight;
      } else {
        v_31 = v_29;
      };
      if (switch_condition) {
        v_33 = Line_follower_without_obstacle__St_BlackForward;
      } else {
        v_33 = v_31;
      };
      if (b2) {
        ns_St_BlackDriftRight = Line_follower_without_obstacle__St_BlackRight;
      } else {
        ns_St_BlackDriftRight = v_33;
      };
      _out->v_l = v_l_St_BlackDriftRight;
      _out->v_r = v_r_St_BlackDriftRight;
      _out->dir = dir_St_BlackDriftRight;
      _out->cnt = cnt_St_BlackDriftRight;
      ns = ns_St_BlackDriftRight;
      nr = nr_St_BlackDriftRight;
      self->v_35 = false;
      break;
    default:
      break;
  };
  self->cnt_1 = _out->cnt;
  self->pnr = nr;
  self->ck = ns;;
}

