/* --- Generated the 20/3/2025 at 1:17 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 16:17:35 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__findpid_mem {
  int v_3;
  int v_1;
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

typedef struct Line_follower__main_mem {
  Line_follower__st ck;
  int pnr;
  Line_follower__findpid_mem findpid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
