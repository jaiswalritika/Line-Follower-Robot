/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

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
  long flg_1;
  long bcount_1;
  long c_1;
} Line_follower__counter_mem;

typedef struct Line_follower__counter_out {
  long finalcount;
} Line_follower__counter_out;

void Line_follower__counter_reset(Line_follower__counter_mem* self);

void Line_follower__counter_step(long sen0, long sen1, long sen2, long sen3,
                                 long sen4, long beacon, long flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self);

typedef struct Line_follower__main_mem {
  long v_34;
  long v_37;
  long v_40;
  long v_43;
  long v_46;
  long v_75;
  long v_78;
  long v_107;
  long v_110;
  long v_139;
  long v_157;
  long v_184;
  long v_188;
  long v_193;
  long v_198;
  long v_202;
  long v_205;
  Line_follower__st_1 ck;
  long pnr;
  long rightturn_count_1;
  long timer1_1;
  long timer_1;
  long rightflag3_1;
  long leftflag3_1;
  long rightflag2_1;
  long leftflag2_1;
  long rightflag1_1;
  long leftflag1_1;
  long cnt_1;
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
                              long sen4, long ir_d_front,
                              long leftforwardDetection,
                              long leftbackwardDetection,
                              long rightforwardDetection,
                              long rightbackwardDetection, long beacon,
                              long second, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
