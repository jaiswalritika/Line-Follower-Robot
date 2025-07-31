/* --- Generated the 30/3/2025 at 16:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__findpid_mem {
  long v;
  long error_1;
} Line_follower__findpid_mem;

typedef struct Line_follower__findpid_out {
  long pid;
} Line_follower__findpid_out;

void Line_follower__findpid_reset(Line_follower__findpid_mem* self);

void Line_follower__findpid_step(long sen3, long sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self);

typedef struct Line_follower__counter_mem {
  Line_follower__st ck;
  long pnr;
  long beaconcount_1;
  long flg_1;
  long cnt_2;
} Line_follower__counter_mem;

typedef struct Line_follower__counter_out {
  long count;
} Line_follower__counter_out;

void Line_follower__counter_reset(Line_follower__counter_mem* self);

void Line_follower__counter_step(long sen0, long sen1, long sen2, long sen3,
                                 long sen4, long beacon, long flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self);

typedef struct Line_follower__main_mem {
  long v_35;
  long v_33;
  long v_40;
  long v_38;
  long v_45;
  long v_43;
  long v_51;
  long v_49;
  long v_56;
  long v_54;
  long v_61;
  long v_59;
  long v_66;
  long v_64;
  long v_71;
  long v_69;
  long v_76;
  long v_74;
  long v_81;
  long v_79;
  Line_follower__st_1 ck;
  long pnr;
  long rightturn_count_1;
  long timer_1;
  long cnt_3;
  Line_follower__counter_mem counter;
  Line_follower__findpid_mem findpid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
  long cnt;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long ir_d_front, long ir_d_left,
                              long beacon, long second,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
