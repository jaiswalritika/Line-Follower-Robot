/* --- Generated the 29/3/2025 at 13:33 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 15:45:36 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower_without_obstacle.ept --- */

#ifndef LINE_FOLLOWER_WITHOUT_OBSTACLE_H
#define LINE_FOLLOWER_WITHOUT_OBSTACLE_H

#include "line_follower_without_obstacle_types.h"
typedef struct Line_follower_without_obstacle__findpid_mem {
  long v;
  long error_1;
} Line_follower_without_obstacle__findpid_mem;

typedef struct Line_follower_without_obstacle__findpid_out {
  long pid;
} Line_follower_without_obstacle__findpid_out;

void Line_follower_without_obstacle__findpid_reset(Line_follower_without_obstacle__findpid_mem* self);

void Line_follower_without_obstacle__findpid_step(long sen3, long sen1,
                                                  Line_follower_without_obstacle__findpid_out* _out,
                                                  Line_follower_without_obstacle__findpid_mem* self);

typedef struct Line_follower_without_obstacle__main_mem {
  long v_35;
  long v_45;
  long v_69;
  long v_139;
  Line_follower_without_obstacle__st ck;
  long pnr;
  long cnt_1;
  Line_follower_without_obstacle__findpid_mem findpid;
} Line_follower_without_obstacle__main_mem;

typedef struct Line_follower_without_obstacle__main_out {
  long v_l;
  long v_r;
  long dir;
  long cnt;
} Line_follower_without_obstacle__main_out;

void Line_follower_without_obstacle__main_reset(Line_follower_without_obstacle__main_mem* self);

void Line_follower_without_obstacle__main_step(long sen0, long sen1, long sen2,
                                               long sen3, long sen4,
                                               Line_follower_without_obstacle__main_out* _out,
                                               Line_follower_without_obstacle__main_mem* self);

#endif // LINE_FOLLOWER_WITHOUT_OBSTACLE_H
