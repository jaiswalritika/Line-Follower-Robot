/* --- Generated the 20/3/2025 at 1:17 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 16:17:35 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__findpid_reset(Line_follower__findpid_mem* self) {
  self->v_3 = true;
  self->v = true;
}

void Line_follower__findpid_step(long sen3, long sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self) {
  
  long v_9;
  long v_8;
  long v_7;
  long v_6;
  long v_5;
  long v_4;
  long v_2;
  long z;
  long p;
  long d;
  long i;
  long error;
  if (self->v_3) {
    v_4 = 0;
  } else {
    v_4 = self->error_1;
  };
  error = (sen3-sen1);
  d = (error-v_4);
  v_8 = (Line_follower__kd*d);
  v_2 = (self->v_1+error);
  if (self->v) {
    i = 0;
  } else {
    i = v_2;
  };
  v_6 = (Line_follower__ki*i);
  p = error;
  v_5 = (Line_follower__kp*p);
  v_7 = (v_5+v_6);
  z = (v_7+v_8);
  v_9 = (z>0);
  if (v_9) {
    _out->pid = 15;
  } else {
    _out->pid = -15;
  };
  self->error_1 = error;
  self->v_3 = false;
  self->v_1 = i;
  self->v = false;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__findpid_reset(&self->findpid);
  self->pnr = false;
  self->ck = Line_follower__St_Forward;
}

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__findpid_out Line_follower__findpid_out_st;
  
  long v_24;
  Line_follower__st v_23;
  long v_22;
  Line_follower__st v_21;
  long v_20;
  Line_follower__st v_19;
  long v_18;
  Line_follower__st v_17;
  long v_16;
  Line_follower__st v_15;
  long v_34;
  Line_follower__st v_33;
  long v_32;
  Line_follower__st v_31;
  long v_30;
  Line_follower__st v_29;
  long v_28;
  Line_follower__st v_27;
  long v_26;
  Line_follower__st v_25;
  long v_44;
  Line_follower__st v_43;
  long v_42;
  Line_follower__st v_41;
  long v_40;
  Line_follower__st v_39;
  long v_38;
  Line_follower__st v_37;
  long v_36;
  Line_follower__st v_35;
  long v_52;
  Line_follower__st v_51;
  long v_50;
  Line_follower__st v_49;
  long v_48;
  Line_follower__st v_47;
  long v_46;
  Line_follower__st v_45;
  long v_62;
  Line_follower__st v_61;
  long v_60;
  Line_follower__st v_59;
  long v_58;
  Line_follower__st v_57;
  long v_56;
  Line_follower__st v_55;
  long v_54;
  long v_53;
  long v_70;
  Line_follower__st v_69;
  long v_68;
  Line_follower__st v_67;
  long v_66;
  Line_follower__st v_65;
  long v_64;
  Line_follower__st v_63;
  long nr_St_DriftRight;
  Line_follower__st ns_St_DriftRight;
  long dir_St_DriftRight;
  long v_r_St_DriftRight;
  long v_l_St_DriftRight;
  long nr_St_DriftLeft;
  Line_follower__st ns_St_DriftLeft;
  long dir_St_DriftLeft;
  long v_r_St_DriftLeft;
  long v_l_St_DriftLeft;
  long nr_St_Right;
  Line_follower__st ns_St_Right;
  long dir_St_Right;
  long v_r_St_Right;
  long v_l_St_Right;
  long nr_St_Left;
  Line_follower__st ns_St_Left;
  long dir_St_Left;
  long v_r_St_Left;
  long v_l_St_Left;
  long nr_St_Stop;
  Line_follower__st ns_St_Stop;
  long dir_St_Stop;
  long v_r_St_Stop;
  long v_l_St_Stop;
  long nr_St_Forward;
  Line_follower__st ns_St_Forward;
  long dir_St_Forward;
  long v_r_St_Forward;
  long v_l_St_Forward;
  long v_14;
  long v_13;
  long v_12;
  long v_11;
  long v_10;
  long v;
  Line_follower__st ns;
  long r;
  long nr;
  long pid;
  long c1;
  long c2;
  long c3;
  long c4;
  long c5;
  r = self->pnr;
  c5 = (sen3>900);
  c4 = (sen1>900);
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
    case Line_follower__St_Forward:
      dir_St_Forward = 1;
      v_r_St_Forward = 50;
      v_l_St_Forward = 50;
      if (c5) {
        v_64 = true;
      } else {
        v_64 = false;
      };
      if (c4) {
        v_66 = true;
      } else {
        v_66 = v_64;
      };
      if (c3) {
        v_68 = true;
      } else {
        v_68 = v_66;
      };
      if (c2) {
        v_70 = true;
      } else {
        v_70 = v_68;
      };
      if (c1) {
        nr_St_Forward = true;
      } else {
        nr_St_Forward = v_70;
      };
      if (c5) {
        v_63 = Line_follower__St_DriftLeft;
      } else {
        v_63 = Line_follower__St_Forward;
      };
      if (c4) {
        v_65 = Line_follower__St_DriftRight;
      } else {
        v_65 = v_63;
      };
      if (c3) {
        v_67 = Line_follower__St_Right;
      } else {
        v_67 = v_65;
      };
      if (c2) {
        v_69 = Line_follower__St_Left;
      } else {
        v_69 = v_67;
      };
      if (c1) {
        ns_St_Forward = Line_follower__St_Stop;
      } else {
        ns_St_Forward = v_69;
      };
      _out->v_l = v_l_St_Forward;
      _out->v_r = v_r_St_Forward;
      _out->dir = dir_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      break;
    case Line_follower__St_Stop:
      dir_St_Stop = 0;
      v_r_St_Stop = 0;
      v_l_St_Stop = 0;
      if (true) {
        v_56 = true;
      } else {
        v_56 = false;
      };
      if (c5) {
        v_58 = true;
      } else {
        v_58 = v_56;
      };
      if (c4) {
        v_60 = true;
      } else {
        v_60 = v_58;
      };
      if (c3) {
        v_62 = true;
      } else {
        v_62 = v_60;
      };
      if (true) {
        v_55 = Line_follower__St_Forward;
      } else {
        v_55 = Line_follower__St_Stop;
      };
      if (c5) {
        v_57 = Line_follower__St_DriftLeft;
      } else {
        v_57 = v_55;
      };
      if (c4) {
        v_59 = Line_follower__St_DriftRight;
      } else {
        v_59 = v_57;
      };
      if (c3) {
        v_61 = Line_follower__St_Right;
      } else {
        v_61 = v_59;
      };
      v_53 = !(c1);
      v_54 = (v_53&&c2);
      if (v_54) {
        nr_St_Stop = true;
        ns_St_Stop = Line_follower__St_Left;
      } else {
        nr_St_Stop = v_62;
        ns_St_Stop = v_61;
      };
      _out->v_l = v_l_St_Stop;
      _out->v_r = v_r_St_Stop;
      _out->dir = dir_St_Stop;
      ns = ns_St_Stop;
      nr = nr_St_Stop;
      break;
    case Line_follower__St_Left:
      dir_St_Left = 4;
      v_r_St_Left = 50;
      v_l_St_Left = 50;
      if (true) {
        v_46 = true;
      } else {
        v_46 = false;
      };
      if (c5) {
        v_48 = true;
      } else {
        v_48 = v_46;
      };
      if (c4) {
        v_50 = true;
      } else {
        v_50 = v_48;
      };
      if (c3) {
        v_52 = true;
      } else {
        v_52 = v_50;
      };
      if (c1) {
        nr_St_Left = true;
      } else {
        nr_St_Left = v_52;
      };
      if (true) {
        v_45 = Line_follower__St_Forward;
      } else {
        v_45 = Line_follower__St_Left;
      };
      if (c5) {
        v_47 = Line_follower__St_DriftLeft;
      } else {
        v_47 = v_45;
      };
      if (c4) {
        v_49 = Line_follower__St_DriftRight;
      } else {
        v_49 = v_47;
      };
      if (c3) {
        v_51 = Line_follower__St_Right;
      } else {
        v_51 = v_49;
      };
      if (c1) {
        ns_St_Left = Line_follower__St_Stop;
      } else {
        ns_St_Left = v_51;
      };
      _out->v_l = v_l_St_Left;
      _out->v_r = v_r_St_Left;
      _out->dir = dir_St_Left;
      ns = ns_St_Left;
      nr = nr_St_Left;
      break;
    case Line_follower__St_Right:
      dir_St_Right = 5;
      v_r_St_Right = 50;
      v_l_St_Right = 50;
      if (true) {
        v_36 = true;
      } else {
        v_36 = false;
      };
      if (c5) {
        v_38 = true;
      } else {
        v_38 = v_36;
      };
      if (c4) {
        v_40 = true;
      } else {
        v_40 = v_38;
      };
      if (c3) {
        v_42 = true;
      } else {
        v_42 = v_40;
      };
      if (c2) {
        v_44 = true;
      } else {
        v_44 = v_42;
      };
      if (c1) {
        nr_St_Right = true;
      } else {
        nr_St_Right = v_44;
      };
      if (true) {
        v_35 = Line_follower__St_Forward;
      } else {
        v_35 = Line_follower__St_Right;
      };
      if (c5) {
        v_37 = Line_follower__St_DriftLeft;
      } else {
        v_37 = v_35;
      };
      if (c4) {
        v_39 = Line_follower__St_DriftRight;
      } else {
        v_39 = v_37;
      };
      if (c3) {
        v_41 = Line_follower__St_Right;
      } else {
        v_41 = v_39;
      };
      if (c2) {
        v_43 = Line_follower__St_Left;
      } else {
        v_43 = v_41;
      };
      if (c1) {
        ns_St_Right = Line_follower__St_Stop;
      } else {
        ns_St_Right = v_43;
      };
      _out->v_l = v_l_St_Right;
      _out->v_r = v_r_St_Right;
      _out->dir = dir_St_Right;
      ns = ns_St_Right;
      nr = nr_St_Right;
      break;
    case Line_follower__St_DriftLeft:
      dir_St_DriftLeft = 3;
      v_r_St_DriftLeft = (40+pid);
      v_l_St_DriftLeft = 0;
      if (true) {
        v_26 = true;
      } else {
        v_26 = false;
      };
      if (c5) {
        v_28 = true;
      } else {
        v_28 = v_26;
      };
      if (c4) {
        v_30 = true;
      } else {
        v_30 = v_28;
      };
      if (c3) {
        v_32 = true;
      } else {
        v_32 = v_30;
      };
      if (c2) {
        v_34 = true;
      } else {
        v_34 = v_32;
      };
      if (c1) {
        nr_St_DriftLeft = true;
      } else {
        nr_St_DriftLeft = v_34;
      };
      if (true) {
        v_25 = Line_follower__St_Forward;
      } else {
        v_25 = Line_follower__St_DriftLeft;
      };
      if (c5) {
        v_27 = Line_follower__St_DriftLeft;
      } else {
        v_27 = v_25;
      };
      if (c4) {
        v_29 = Line_follower__St_DriftRight;
      } else {
        v_29 = v_27;
      };
      if (c3) {
        v_31 = Line_follower__St_Right;
      } else {
        v_31 = v_29;
      };
      if (c2) {
        v_33 = Line_follower__St_Left;
      } else {
        v_33 = v_31;
      };
      if (c1) {
        ns_St_DriftLeft = Line_follower__St_Stop;
      } else {
        ns_St_DriftLeft = v_33;
      };
      _out->v_l = v_l_St_DriftLeft;
      _out->v_r = v_r_St_DriftLeft;
      _out->dir = dir_St_DriftLeft;
      ns = ns_St_DriftLeft;
      nr = nr_St_DriftLeft;
      break;
    case Line_follower__St_DriftRight:
      dir_St_DriftRight = 2;
      v_r_St_DriftRight = 0;
      v_l_St_DriftRight = (40+pid);
      if (true) {
        v_16 = true;
      } else {
        v_16 = false;
      };
      if (c5) {
        v_18 = true;
      } else {
        v_18 = v_16;
      };
      if (c4) {
        v_20 = true;
      } else {
        v_20 = v_18;
      };
      if (c3) {
        v_22 = true;
      } else {
        v_22 = v_20;
      };
      if (c2) {
        v_24 = true;
      } else {
        v_24 = v_22;
      };
      if (c1) {
        nr_St_DriftRight = true;
      } else {
        nr_St_DriftRight = v_24;
      };
      if (true) {
        v_15 = Line_follower__St_Forward;
      } else {
        v_15 = Line_follower__St_DriftRight;
      };
      if (c5) {
        v_17 = Line_follower__St_DriftLeft;
      } else {
        v_17 = v_15;
      };
      if (c4) {
        v_19 = Line_follower__St_DriftRight;
      } else {
        v_19 = v_17;
      };
      if (c3) {
        v_21 = Line_follower__St_Right;
      } else {
        v_21 = v_19;
      };
      if (c2) {
        v_23 = Line_follower__St_Left;
      } else {
        v_23 = v_21;
      };
      if (c1) {
        ns_St_DriftRight = Line_follower__St_Stop;
      } else {
        ns_St_DriftRight = v_23;
      };
      _out->v_l = v_l_St_DriftRight;
      _out->v_r = v_r_St_DriftRight;
      _out->dir = dir_St_DriftRight;
      ns = ns_St_DriftRight;
      nr = nr_St_DriftRight;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

