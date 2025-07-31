/* --- Generated the 30/3/2025 at 16:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

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
  int beaconcount_1;
  int flg_1;
  int cnt_2;
} Line_follower__counter_mem;

typedef struct Line_follower__counter_out {
  int count;
} Line_follower__counter_out;

void Line_follower__counter_reset(Line_follower__counter_mem* self);

void Line_follower__counter_step(int sen0, int sen1, int sen2, int sen3,
                                 int sen4, int beacon, int flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self);

typedef struct Line_follower__main_mem {
  int v_35;
  int v_33;
  int v_40;
  int v_38;
  int v_45;
  int v_43;
  int v_51;
  int v_49;
  int v_56;
  int v_54;
  int v_61;
  int v_59;
  int v_66;
  int v_64;
  int v_71;
  int v_69;
  int v_76;
  int v_74;
  int v_81;
  int v_79;
  Line_follower__st_1 ck;
  int pnr;
  int rightturn_count_1;
  int timer_1;
  int cnt_3;
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
                              int sen4, int ir_d_front, int ir_d_left,
                              int beacon, int second,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
