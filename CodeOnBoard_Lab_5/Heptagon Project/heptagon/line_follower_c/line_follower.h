/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__findpid_mem {
  int v;
  int error_1;
} Line_follower__findpid_mem;

typedef struct Line_follower__findpid_out {
  int pid;
} Line_follower__findpid_out;

void Line_follower__findpid_reset(Line_follower__findpid_mem* self);

void Line_follower__findpid_step(int sen3, int sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self);

typedef struct Line_follower__counter_mem {
  Line_follower__st ck;
  int pnr;
  int flg_1;
  int bcount_1;
  int c_1;
} Line_follower__counter_mem;

typedef struct Line_follower__counter_out {
  int finalcount;
} Line_follower__counter_out;

void Line_follower__counter_reset(Line_follower__counter_mem* self);

void Line_follower__counter_step(int sen0, int sen1, int sen2, int sen3,
                                 int sen4, int beacon, int flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self);

typedef struct Line_follower__main_mem {
  int v_34;
  int v_37;
  int v_40;
  int v_43;
  int v_46;
  int v_75;
  int v_78;
  int v_107;
  int v_110;
  int v_139;
  int v_157;
  int v_184;
  int v_188;
  int v_193;
  int v_198;
  int v_202;
  int v_205;
  Line_follower__st_1 ck;
  int pnr;
  int rightturn_count_1;
  int timer1_1;
  int timer_1;
  int rightflag3_1;
  int leftflag3_1;
  int rightflag2_1;
  int leftflag2_1;
  int rightflag1_1;
  int leftflag1_1;
  int cnt_1;
  Line_follower__counter_mem counter;
  Line_follower__findpid_mem findpid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
  int cnt;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_d_front,
                              int leftforwardDetection,
                              int leftbackwardDetection,
                              int rightforwardDetection,
                              int rightbackwardDetection, int beacon,
                              int second, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
